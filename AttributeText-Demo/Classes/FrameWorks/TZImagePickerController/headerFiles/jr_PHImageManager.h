//
//  jr_PHImageManager.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHImageManager_h
#define jr_PHImageManager_h

typedef NS_ENUM(NSInteger, PHImageRequestOptionsVersion) {
	PHImageRequestOptionsVersionCurrent = 0,
	PHImageRequestOptionsVersionUnadjusted,
	PHImageRequestOptionsVersionOriginal
};

typedef NS_ENUM(NSInteger, PHImageRequestOptionsDeliveryMode) {
	PHImageRequestOptionsDeliveryModeOpportunistic		= 0,
	PHImageRequestOptionsDeliveryModeHighQualityFormat	= 1,
	PHImageRequestOptionsDeliveryModeFastFormat			= 2
};

typedef NS_ENUM(NSInteger, PHImageRequestOptionsResizeMode) {
	PHImageRequestOptionsResizeModeNone = 0, // no resize
	PHImageRequestOptionsResizeModeFast,
	PHImageRequestOptionsResizeModeExact,
};

typedef void (^ PHAssetImageProgressHandler)(double progress, NSError *__nullable error, BOOL *stop, NSDictionary *__nullable info);


/// 获取图片请求选项
@interface PHImageRequestOptions : NSObject <NSCopying>
/// The version of the image to be requested.
@property (nonatomic, assign) PHImageRequestOptionsVersion		version;
/// The requested image quality and delivery priority.
@property (nonatomic, assign) PHImageRequestOptionsDeliveryMode deliveryMode;
/// A mode that specifies how to resize the requested image.
@property (nonatomic, assign) PHImageRequestOptionsResizeMode resizeMode;
/// A rectangle for requesting a cropped version of the original image.
@property (nonatomic, assign) CGRect normalizedCropRect;
/// A Boolean value that specifies whether Photos can download the requested image from iCloud.
@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
/// 请求是否同步. Defaults to NO
@property (nonatomic, assign, getter=isSynchronous) BOOL synchronous;
// return only a single result, blocking until available (or failure)
@property (nonatomic, copy, nullable) PHAssetImageProgressHandler progressHandler;
// provide caller a way to be told how much progress has been made prior to delivering the data when it comes from iCloud. Defaults to nil, shall be set by caller

@end
/// LivePhoto 请求选项
@interface PHLivePhotoRequestOptions : NSObject <NSCopying>

@property (nonatomic, assign) PHImageRequestOptionsVersion version; // version
@property (nonatomic, assign) PHImageRequestOptionsDeliveryMode deliveryMode;
@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
@property (nonatomic, copy, nullable) PHAssetImageProgressHandler progressHandler;

@end

#pragma mark - PHVideoRequestOptions - Configuration

typedef NS_ENUM(NSInteger, PHVideoRequestOptionsVersion) {
	PHVideoRequestOptionsVersionCurrent = 0,
	PHVideoRequestOptionsVersionOriginal
};

typedef NS_ENUM(NSInteger, PHVideoRequestOptionsDeliveryMode) {
	PHVideoRequestOptionsDeliveryModeAutomatic				= 0,
	PHVideoRequestOptionsDeliveryModeHighQualityFormat		= 1, // best quality
	PHVideoRequestOptionsDeliveryModeMediumQualityFormat	= 2,
	PHVideoRequestOptionsDeliveryModeFastFormat				= 3
};

typedef void (^PHAssetVideoProgressHandler)(double progress, NSError *__nullable error, BOOL *stop, NSDictionary *__nullable info);

/// 视频请求选项
@interface PHVideoRequestOptions : NSObject
/// 是否允许网络请求
@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
///
@property (nonatomic, assign) PHVideoRequestOptionsVersion version;
/// 
@property (nonatomic, assign) PHVideoRequestOptionsDeliveryMode deliveryMode;

@property (nonatomic, copy, nullable) PHAssetVideoProgressHandler progressHandler;

@end


#pragma mark - PHImageManager - Fetching

{
/// A numeric identifier for an asynchronous image request.
typedef int32_t PHImageRequestID;
static const PHImageRequestID PHInvalidImageRequestID = 0;

// Size to pass when requesting the original image or the largest rendered image available (resizeMode will be ignored)
extern CGSize const PHImageManagerMaximumSize PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);

// Result's handler info dictionary keys
extern NSString *const PHImageResultIsInCloudKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
// key (NSNumber): result is in iCloud, meaning a new request will need to get issued (with networkAccessAllowed set) to get the result
extern NSString *const PHImageResultIsDegradedKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
// key (NSNumber): result  is a degraded image (only with async requests), meaning other images will be sent unless the request is cancelled in the meanwhile (note that the other request may fail if, for example, data is not available locally and networkAccessAllowed was not specified)
extern NSString *const PHImageResultRequestIDKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
// key (NSNumber): Request ID of the request for this result
extern NSString *const PHImageCancelledKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
// key (NSNumber): result is not available because the request was cancelled
extern NSString *const PHImageErrorKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
// key (NSError): NSFileManager or iCloud Photo Library errors
}
//////////
/// 获取资源内容
@interface PHImageManager : NSObject

/********************************************************************************/
/** Getting the Image Manager **/
/********************************************************************************/
+ (PHImageManager *)defaultManager;

#pragma mark - Requesting Images
/********************************************************************************/
/** Requesting Images **/
/********************************************************************************/
/// Requests an image representation for the specified asset.
- (PHImageRequestID)requestImageForAsset:(PHAsset *)asset 
							  targetSize:(CGSize)targetSize 
							 contentMode:(PHImageContentMode)contentMode 
								 options:(nullable PHImageRequestOptions *)options 
						   resultHandler:(void (^)(UIImage *__nullable result, NSDictionary *__nullable info))resultHandler;

/// Requests full-sized image data for the specified asset.
- (PHImageRequestID)requestImageDataForAsset:(PHAsset *)asset 
									 options:(nullable PHImageRequestOptions *)options 
							   resultHandler:(void(^)(NSData *__nullable imageData, NSString *__nullable dataUTI, UIImageOrientation orientation, NSDictionary *__nullable info))resultHandler;

#pragma mark - Canceling a Request
/// 取消
- (void)cancelImageRequest:(PHImageRequestID)requestID;

#pragma mark - Requesting Live Photos
//// 请求 Live Photo
- (PHImageRequestID)requestLivePhotoForAsset:(PHAsset *)asset 
								  targetSize:(CGSize)targetSize 
								 contentMode:(PHImageContentMode)contentMode 
									 options:(nullable PHLivePhotoRequestOptions *)options 
							   resultHandler:(void (^)(PHLivePhoto *__nullable livePhoto, NSDictionary *__nullable info))resultHandler PHOTOS_AVAILABLE_IOS_TVOS(9_1, 10_0);

#pragma mark - Requesting Video Objects
/********************************************************************************/
/** Requesting Video Objects **/
/********************************************************************************/
// Playback only. The result handler is called on an arbitrary queue.
- (PHImageRequestID)requestPlayerItemForVideo:(PHAsset *)asset 
									  options:(nullable PHVideoRequestOptions *)options 
								resultHandler:(void (^)(AVPlayerItem *__nullable playerItem, NSDictionary *__nullable info))resultHandler;

// Export. The result handler is called on an arbitrary queue.
- (PHImageRequestID)requestExportSessionForVideo:(PHAsset *)asset 
										 options:(nullable PHVideoRequestOptions *)options 
									exportPreset:(NSString *)exportPreset 
								   resultHandler:(void (^)(AVAssetExportSession *__nullable exportSession, NSDictionary *__nullable info))resultHandler;

// Everything else. The result handler is called on an arbitrary queue.
- (PHImageRequestID)requestAVAssetForVideo:(PHAsset *)asset 
								   options:(nullable PHVideoRequestOptions *)options 
							 resultHandler:(void (^)(AVAsset *__nullable asset, AVAudioMix *__nullable audioMix, NSDictionary *__nullable info))resultHandler;

@end


/// 获取资源 针对批量获取进行优化
@interface PHCachingImageManager : PHImageManager

#pragma mark - Setting Cache Policy
/// 是否获取高质量图片
@property (nonatomic, assign) BOOL allowsCachingHighQualityImages;

#pragma mark - Preparing Images
/// 开始缓存资源
- (void)startCachingImagesForAssets:(NSArray<PHAsset *> *)assets 
						 targetSize:(CGSize)targetSize 
						contentMode:(PHImageContentMode)contentMode 
							options:(nullable PHImageRequestOptions *)options;
/// 停止缓存资源
- (void)stopCachingImagesForAssets:(NSArray<PHAsset *> *)assets 
						targetSize:(CGSize)targetSize 
					   contentMode:(PHImageContentMode)contentMode 
						   options:(nullable PHImageRequestOptions *)options;

/// 停止缓存所有资源
- (void)stopCachingImagesForAllAssets;

@end

#endif /* jr_PHImageManager_h */
