/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "SDWebImageCompat.h"
#import "SDWebImageManager.h"

/**
 * Integrates SDWebImage async downloading and caching of remote images with UIImageView.
 *
 * Usage with a UITableViewCell sub-class:
 *
 * @code
 */
@interface UIImageView (WebCache)

/// Get the current image URL.
- (NSURL *)sd_imageURL;

/// Set the imageView `image` with an `url`.
- (void)sd_setImageWithURL:(NSURL *)url;

/// Set the imageView `image` with an `url` and a placeholder.
- (void)sd_setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder;

/// Set the imageView `image` with an `url`, placeholder and custom options.
- (void)sd_setImageWithURL:(NSURL *)url 
		  placeholderImage:(UIImage *)placeholder 
				   options:(SDWebImageOptions)options;

/// Set the imageView `image` with an `url` completedBlock.
- (void)sd_setImageWithURL:(NSURL *)url completed:(SDWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `url`, placeholder.
- (void)sd_setImageWithURL:(NSURL *)url 
		  placeholderImage:(UIImage *)placeholder 
				 completed:(SDWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `url`, placeholder and custom options.
- (void)sd_setImageWithURL:(NSURL *)url
		  placeholderImage:(UIImage *)placeholder 
				   options:(SDWebImageOptions)options 
				 completed:(SDWebImageCompletionBlock)completedBlock;

/// Set the imageView `image` with an `url`, placeholder and custom options.
- (void)sd_setImageWithURL:(NSURL *)url 
		  placeholderImage:(UIImage *)placeholder 
				   options:(SDWebImageOptions)options 
				  progress:(SDWebImageDownloaderProgressBlock)progressBlock 
				 completed:(SDWebImageCompletionBlock)completedBlock;

///  Set the imageView `image` with an `url` and optionally a placeholder image.
- (void)sd_setImageWithPreviousCachedImageWithURL:(NSURL *)url 
								 placeholderImage:(UIImage *)placeholder 
										  options:(SDWebImageOptions)options 
										 progress:(SDWebImageDownloaderProgressBlock)progressBlock 
										completed:(SDWebImageCompletionBlock)completedBlock;

/**
 * Download an array of images and starts them in an animation loop
 *
 * @param arrayOfURLs An array of NSURL
 */
- (void)sd_setAnimationImagesWithURLs:(NSArray *)arrayOfURLs;

/**
 * Cancel the current download
 */
- (void)sd_cancelCurrentImageLoad;

- (void)sd_cancelCurrentAnimationImagesLoad;

/**
 *  Show activity UIActivityIndicatorView
 */
- (void)setShowActivityIndicatorView:(BOOL)show;

/**
 *  set desired UIActivityIndicatorViewStyle
 *
 *  @param style The style of the UIActivityIndicatorView
 */
- (void)setIndicatorStyle:(UIActivityIndicatorViewStyle)style;

@end


@interface UIImageView (WebCacheDeprecated)

- (NSURL *)imageURL __deprecated_msg("Use `sd_imageURL`");

- (void)setImageWithURL:(NSURL *)url __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:`");
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:placeholderImage:`");
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:placeholderImage:options`");

- (void)setImageWithURL:(NSURL *)url completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:completed:`");
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:placeholderImage:completed:`");
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:placeholderImage:options:completed:`");
- (void)setImageWithURL:(NSURL *)url placeholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletedBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setImageWithURL:placeholderImage:options:progress:completed:`");

- (void)sd_setImageWithPreviousCachedImageWithURL:(NSURL *)url andPlaceholderImage:(UIImage *)placeholder options:(SDWebImageOptions)options progress:(SDWebImageDownloaderProgressBlock)progressBlock completed:(SDWebImageCompletionBlock)completedBlock __deprecated_msg("Method deprecated. Use `sd_setImageWithPreviousCachedImageWithURL:placeholderImage:options:progress:completed:`");

- (void)setAnimationImagesWithURLs:(NSArray *)arrayOfURLs __deprecated_msg("Use `sd_setAnimationImagesWithURLs:`");

- (void)cancelCurrentArrayLoad __deprecated_msg("Use `sd_cancelCurrentAnimationImagesLoad`");

- (void)cancelCurrentImageLoad __deprecated_msg("Use `sd_cancelCurrentImageLoad`");

@end
