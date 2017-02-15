//
//  jr_PHImageManager.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHImageManager_h
#define jr_PHImageManager_h


//
//  PHImageManager.h
//  Photos
//
//  Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <Photos/PhotosTypes.h>
#import <Photos/PhotosDefines.h>

@class PHAsset;
@class PHLivePhoto;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - PHImageRequestOptions - Configuration

typedef NS_ENUM(NSInteger, PHImageRequestOptionsVersion) {
	PHImageRequestOptionsVersionCurrent = 0, // version with edits (aka adjustments) rendered or unadjusted version if there is no edits
	PHImageRequestOptionsVersionUnadjusted, // original version without any adjustments
	PHImageRequestOptionsVersionOriginal // original version, in the case of a combined format the highest fidelity format will be returned (e.g. RAW for a RAW+JPG source image)
} PHOTOS_ENUM_AVAILABLE_IOS_TVOS(8_0, 10_0);

typedef NS_ENUM(NSInteger, PHImageRequestOptionsDeliveryMode) {
	PHImageRequestOptionsDeliveryModeOpportunistic = 0, // client may get several image results when the call is asynchronous or will get one result when the call is synchronous
	PHImageRequestOptionsDeliveryModeHighQualityFormat = 1, // client will get one result only and it will be as asked or better than asked (sync requests are automatically processed this way regardless of the specified mode)
	PHImageRequestOptionsDeliveryModeFastFormat = 2 // client will get one result only and it may be degraded
} PHOTOS_ENUM_AVAILABLE_IOS_TVOS(8_0, 10_0);

typedef NS_ENUM(NSInteger, PHImageRequestOptionsResizeMode) {
	PHImageRequestOptionsResizeModeNone = 0, // no resize
	PHImageRequestOptionsResizeModeFast, // use targetSize as a hint for optimal decoding when the source image is a compressed format (i.e. subsampling), the delivered image may be larger than targetSize
	PHImageRequestOptionsResizeModeExact, // same as above but also guarantees the delivered image is exactly targetSize (must be set when a normalizedCropRect is specified)
} PHOTOS_ENUM_AVAILABLE_IOS_TVOS(8_0, 10_0);

// Progress handler, called in an arbitrary serial queue. Only called when the data is not available locally and is retrieved from iCloud.
typedef void (^ PHAssetImageProgressHandler)(double progress, NSError *__nullable error, BOOL *stop, NSDictionary *__nullable info) PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);




PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHImageRequestOptions : NSObject <NSCopying>

@property (nonatomic, assign) PHImageRequestOptionsVersion		version; // version
@property (nonatomic, assign) PHImageRequestOptionsDeliveryMode deliveryMode;
// delivery mode. Defaults to PHImageRequestOptionsDeliveryModeOpportunistic
@property (nonatomic, assign) PHImageRequestOptionsResizeMode resizeMode;
// resize mode. Does not apply when size is PHImageManagerMaximumSize. Defaults to PHImageRequestOptionsResizeModeNone (or no resize)
@property (nonatomic, assign) CGRect normalizedCropRect;
// specify crop rectangle in unit coordinates of the original image, such as a face. Defaults to CGRectZero (not applicable)
@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
// if necessary will download the image from iCloud (client can monitor or cancel using progressHandler). Defaults to NO (see start/stopCachingImagesForAssets)

@property (nonatomic, assign, getter=isSynchronous) BOOL synchronous;
// return only a single result, blocking until available (or failure). Defaults to NO
@property (nonatomic, copy, nullable) PHAssetImageProgressHandler progressHandler;
// provide caller a way to be told how much progress has been made prior to delivering the data when it comes from iCloud. Defaults to nil, shall be set by caller

@end


PHOTOS_CLASS_AVAILABLE_IOS_TVOS(9_1, 10_0) @interface PHLivePhotoRequestOptions : NSObject <NSCopying>

@property (nonatomic, assign) PHImageRequestOptionsVersion version; // version
@property (nonatomic, assign) PHImageRequestOptionsDeliveryMode deliveryMode;
@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
@property (nonatomic, copy, nullable) PHAssetImageProgressHandler progressHandler;

@end


#pragma mark - PHVideoRequestOptions - Configuration

typedef NS_ENUM(NSInteger, PHVideoRequestOptionsVersion) {
	PHVideoRequestOptionsVersionCurrent = 0, // version with edits (aka adjustments) rendered or unadjusted version if there is no edits
	PHVideoRequestOptionsVersionOriginal // original version
} PHOTOS_ENUM_AVAILABLE_IOS_TVOS(8_0, 10_0);

typedef NS_ENUM(NSInteger, PHVideoRequestOptionsDeliveryMode) { // only apply with PHVideoRequestOptionsVersionCurrent
	PHVideoRequestOptionsDeliveryModeAutomatic = 0, // let us pick the quality (typ. PHVideoRequestOptionsDeliveryModeMediumQualityFormat for streamed AVPlayerItem or AVAsset, or PHVideoRequestOptionsDeliveryModeHighQualityFormat for AVAssetExportSession)
	PHVideoRequestOptionsDeliveryModeHighQualityFormat = 1, // best quality
	PHVideoRequestOptionsDeliveryModeMediumQualityFormat = 2, // medium quality (typ. 720p MP4), currently only supported for AVPlayerItem or AVAsset when streaming from iCloud (will systematically default to PHVideoRequestOptionsDeliveryModeHighQualityFormat if locally available)
	PHVideoRequestOptionsDeliveryModeFastFormat = 3 // fastest available (typ. 360p MP4), currently only supported for AVPlayerItem or AVAsset when streaming from iCloud (will systematically default to PHVideoRequestOptionsDeliveryModeHighQualityFormat if locally available)
} PHOTOS_ENUM_AVAILABLE_IOS_TVOS(8_0, 10_0);

// Progress handler, called in an arbitrary serial queue: only called when the data is not available locally and is retrieved from iCloud
typedef void (^PHAssetVideoProgressHandler)(double progress, NSError *__nullable error, BOOL *stop, NSDictionary *__nullable info) PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);

PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHVideoRequestOptions : NSObject

@property (nonatomic, assign, getter=isNetworkAccessAllowed) BOOL networkAccessAllowed;
@property (nonatomic, assign) PHVideoRequestOptionsVersion version;
@property (nonatomic, assign) PHVideoRequestOptionsDeliveryMode deliveryMode;
@property (nonatomic, copy, nullable) PHAssetVideoProgressHandler progressHandler;

@end



#pragma mark - PHImageManager - Fetching

// Uniquely identify a cancellable async request
typedef int32_t PHImageRequestID PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);
static const PHImageRequestID PHInvalidImageRequestID = 0;

// Size to pass when requesting the original image or the largest rendered image available (resizeMode will be ignored)
extern CGSize const PHImageManagerMaximumSize PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0);

// Result's handler info dictionary keys
extern NSString *const PHImageResultIsInCloudKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0); // key (NSNumber): result is in iCloud, meaning a new request will need to get issued (with networkAccessAllowed set) to get the result
extern NSString *const PHImageResultIsDegradedKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0); // key (NSNumber): result  is a degraded image (only with async requests), meaning other images will be sent unless the request is cancelled in the meanwhile (note that the other request may fail if, for example, data is not available locally and networkAccessAllowed was not specified)
extern NSString *const PHImageResultRequestIDKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0); // key (NSNumber): Request ID of the request for this result
extern NSString *const PHImageCancelledKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0); // key (NSNumber): result is not available because the request was cancelled
extern NSString *const PHImageErrorKey PHOTOS_AVAILABLE_IOS_TVOS(8_0, 10_0); // key (NSError): NSFileManager or iCloud Photo Library errors


//////////
// Note that all sizes are in pixels
PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHImageManager : NSObject

/** Getting the Image Manager **/
+ (PHImageManager *)defaultManager;

/** Requesting Images **/
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

- (void)cancelImageRequest:(PHImageRequestID)requestID;

#pragma mark - Live Photo

- (PHImageRequestID)requestLivePhotoForAsset:(PHAsset *)asset 
								  targetSize:(CGSize)targetSize 
								 contentMode:(PHImageContentMode)contentMode 
									 options:(nullable PHLivePhotoRequestOptions *)options 
							   resultHandler:(void (^)(PHLivePhoto *__nullable livePhoto, NSDictionary *__nullable info))resultHandler PHOTOS_AVAILABLE_IOS_TVOS(9_1, 10_0);

#pragma mark - Video

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


#pragma mark - PHCachingImageManager - Preheating

@interface PHCachingImageManager : PHImageManager

/// A Boolean value that determines whether the image manager prepares high-quality images.
@property (nonatomic, assign) BOOL allowsCachingHighQualityImages;

// Asynchronous image preheating (aka caching), note that only image sources are cached (no crop or exact resize is ever done on them at the time of caching, only at the time of delivery when applicable).
// The options values shall exactly match the options values used in loading methods. If two or more caching requests are done on the same asset using different options or different targetSize the first
// caching request will have precedence (until it is stopped)

- (void)startCachingImagesForAssets:(NSArray<PHAsset *> *)assets 
						 targetSize:(CGSize)targetSize 
						contentMode:(PHImageContentMode)contentMode 
							options:(nullable PHImageRequestOptions *)options;

- (void)stopCachingImagesForAssets:(NSArray<PHAsset *> *)assets 
						targetSize:(CGSize)targetSize 
					   contentMode:(PHImageContentMode)contentMode 
						   options:(nullable PHImageRequestOptions *)options;

- (void)stopCachingImagesForAllAssets;

@end


#endif /* jr_PHImageManager_h */
