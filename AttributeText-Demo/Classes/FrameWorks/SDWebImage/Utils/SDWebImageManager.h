/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageOperation.h"
#import "SDWebImageDownloader.h"
#import "SDImageCache.h"

typedef NS_OPTIONS(NSUInteger, SDWebImageOptions) {
	
	/*
	 *	默认情况下,如果一个url在下载的时候失败了,那么这个url会被加入黑名单并且library不会尝试再次下载,这个flag会阻止library把失败的url加入黑名单(简单来说如果选择了这个flag,那么即使某个url下载失败了,sdwebimage还是会尝试再次下载他.)
	 */
    SDWebImageRetryFailed = 1 << 0,
	/**
	 *默认情况下,图片会在交互发生的时候下载(例如你滑动tableview的时候),这个flag会禁止这个特性,导致的结果就是在scrollview减速的时候
	 *才会开始下载(也就是你滑动的时候scrollview不下载,你手从屏幕上移走,scrollview开始减速的时候才会开始下载图片)
	 */
    SDWebImageLowPriority = 1 << 1,
    // 这个flag禁止磁盘缓存,只有内存缓存
    SDWebImageCacheMemoryOnly = 1 << 2,
	// 这个flag会在图片下载的时候就显示(就像你用浏览器浏览网页的时候那种图片下载,一截一截的显示(待确认))
    SDWebImageProgressiveDownload = 1 << 3,
	// 这个选项的意思看的不是很懂,大意是即使一个图片缓存了,还是会重新请求.并且缓存侧略依据NSURLCache而不是SDWebImage.
    SDWebImageRefreshCached = 1 << 4,
	// 启动后台下载,加入你进入一个页面,有一张图片正在下载这时候你让app进入后台,图片还是会继续下载(这个估计要开backgroundfetch才有用)
    SDWebImageContinueInBackground = 1 << 5,

	/*
	 *可以控制存在NSHTTPCookieStore的cookies.(我没用过,等用过的人过来解释一下)
	 */
    SDWebImageHandleCookies = 1 << 6,

	/*
	 *允许不安全的SSL证书,在正式环境中慎用
	 */
    SDWebImageAllowInvalidSSLCertificates = 1 << 7,

	/*
	 *默认情况下,image在装载的时候是按照他们在队列中的顺序装载的(就是先进先出).这个flag会把他们移动到队列的前端,并且立刻装载
	 *而不是等到当前队列装载的时候再装载.
	 */
    SDWebImageHighPriority = 1 << 8,

	/*
	 *默认情况下,占位图会在图片下载的时候显示.这个flag开启会延迟占位图显示的时间,等到图片下载完成之后才会显示占位图.(等图片显示完了我干嘛还显示占位图?或许是我理解错了?)
	 */
    SDWebImageDelayPlaceholder = 1 << 9,

	/*
	 *是否transform图片(没用过,还要再看,但是据我估计,是否是图片有可能方向不对需要调整方向,例如采用iPhone拍摄的照片如果不纠正方向,那么图片是向左旋转90度的.可能很多人不知道iPhone的摄像头并不是竖直的,而是向左偏了90度.具体请google.)
	 */
    SDWebImageTransformAnimatedImage = 1 << 10,
    
    /**
     * By default, image is added to the imageView after download. But in some cases, we want to
     * have the hand before setting the image (apply a filter or add it with cross-fade animation for instance)
     * Use this flag if you want to manually set the image in the completion when success
     */
    SDWebImageAvoidAutoSetImage = 1 << 11
};

// 操作完成的回调，被上层的扩展调用。
typedef void(^SDWebImageCompletionBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL);
// 被SDWebImageManager调用。如果使用了SDWebImageProgressiveDownload标记，这个block可能会被重复调用，直到图片完全下载结束，finished=true,再最后调用一次这个block。
typedef void(^SDWebImageCompletionWithFinishedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL);
// SDWebImageManager每次把URL转换为cache key的时候调用，可以删除一些image URL中的动态部分。
typedef NSString *(^SDWebImageCacheKeyFilterBlock)(NSURL *url);


@class SDWebImageManager;

@protocol SDWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 * 控制在cache中没有找到image时 是否应该去下载。
 * @param imageManager The current `SDWebImageManager`
 * @param imageURL     The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(SDWebImageManager *)imageManager shouldDownloadImageForURL:(NSURL *)imageURL;

/**
 * Allows to transform the image immediately after it has been downloaded and just before to cache it on disk and memory.
 * NOTE: This method is called from a global queue in order to not to block the main thread.
 * 在下载之后，缓存之前转换图片。在全局队列中操作，不阻塞主线程
 * @param imageManager The current `SDWebImageManager`
 * @param image        The image to transform
 * @param imageURL     The url of the image to transform
 *
 * @return The transformed image object.
 */
- (UIImage *)imageManager:(SDWebImageManager *)imageManager transformDownloadedImage:(UIImage *)image withURL:(NSURL *)imageURL;

@end

/**
 * The SDWebImageManager is the class behind the UIImageView+WebCache category and likes.
 * It ties the asynchronous downloader (SDWebImageDownloader) with the image cache store (SDImageCache).
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 *
 * Here is a simple example of how to use SDWebImageManager:
 *
 * @code

SDWebImageManager *manager = [SDWebImageManager sharedManager];
[manager downloadImageWithURL:imageURL
                      options:0
                     progress:nil
                    completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
                        if (image) {
                            // do something with image
                        }
                    }];

 * @endcode
 */
@interface SDWebImageManager : NSObject
/// 代理对象
@property (weak, nonatomic) id <SDWebImageManagerDelegate> delegate;
/// 图片缓存
@property (strong, nonatomic, readonly) SDImageCache *imageCache;
/// 图片下载
@property (strong, nonatomic, readonly) SDWebImageDownloader *imageDownloader;

/**
 * The cache filter is a block used each time SDWebImageManager need to convert an URL into a cache key. This can
 * be used to remove dynamic part of an image URL.
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 *
 * @code

[[SDWebImageManager sharedManager] setCacheKeyFilter:^(NSURL *url) {
    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
    return [url absoluteString];
}];

 * @endcode
 */
@property (nonatomic, copy) SDWebImageCacheKeyFilterBlock cacheKeyFilter;

/// Returns global SDWebImageManager instance.
+ (SDWebImageManager *)sharedManager;

/**
 * Allows to specify instance of cache and image downloader used with image manager.
 * @return new instance of `SDWebImageManager` with specified cache and downloader.
 */
- (instancetype)initWithCache:(SDImageCache *)cache downloader:(SDWebImageDownloader *)downloader;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed.
 *
 *   This parameter is required.
 * 
 *   This block has no return value and takes the requested UIImage as first parameter.
 *   In case of error the image parameter is nil and the second parameter may contain an NSError.
 *
 *   The third parameter is an `SDImageCacheType` enum indicating if the image was retrieved from the local cache
 *   or from the memory cache or from the network.
 *
 *   The last parameter is set to NO when the SDWebImageProgressiveDownload option is used and the image is 
 *   downloading. This block is thus called repeatedly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 * @return Returns an NSObject conforming to SDWebImageOperation. Should be an instance of SDWebImageDownloaderOperation
 */
- (id <SDWebImageOperation>)downloadImageWithURL:(NSURL *)url
                                         options:(SDWebImageOptions)options
                                        progress:(SDWebImageDownloaderProgressBlock)progressBlock
                                       completed:(SDWebImageCompletionWithFinishedBlock)completedBlock;

/**
 * Saves image to cache for given URL
 *
 * @param image The image to cache
 * @param url   The URL to the image
 *
 */
- (void)saveImageToCache:(UIImage *)image forURL:(NSURL *)url;

/**
 * Cancel all current operations
 */
- (void)cancelAll;

/**
 * Check one or more operations running
 */
- (BOOL)isRunning;

/**
 *  Check if image has already been cached
 *
 *  @param url image url
 *
 *  @return if the image was already cached
 */
- (BOOL)cachedImageExistsForURL:(NSURL *)url;

/**
 *  Check if image has already been cached on disk only
 *
 *  @param url image url
 *
 *  @return if the image was already cached (disk only)
 */
- (BOOL)diskImageExistsForURL:(NSURL *)url;

/**
 *  Async check if image has already been cached
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *  
 *  @note the completion block is always executed on the main queue
 */
- (void)cachedImageExistsForURL:(NSURL *)url
                     completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Async check if image has already been cached on disk only
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *
 *  @note the completion block is always executed on the main queue
 */
- (void)diskImageExistsForURL:(NSURL *)url
                   completion:(SDWebImageCheckCacheCompletionBlock)completionBlock;


/**
 *Return the cache key for a given URL
 */
- (NSString *)cacheKeyForURL:(NSURL *)url;

@end


#pragma mark - Deprecated

typedef void(^SDWebImageCompletedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionBlock`");
typedef void(^SDWebImageCompletedWithFinishedBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionWithFinishedBlock`");


@interface SDWebImageManager (Deprecated)

/**
 *  Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 *  @deprecated This method has been deprecated. Use `downloadImageWithURL:options:progress:completed:`
 */
- (id <SDWebImageOperation>)downloadWithURL:(NSURL *)url
                                    options:(SDWebImageOptions)options
                                   progress:(SDWebImageDownloaderProgressBlock)progressBlock
                                  completed:(SDWebImageCompletedWithFinishedBlock)completedBlock __deprecated_msg("Method deprecated. Use `downloadImageWithURL:options:progress:completed:`");

@end
