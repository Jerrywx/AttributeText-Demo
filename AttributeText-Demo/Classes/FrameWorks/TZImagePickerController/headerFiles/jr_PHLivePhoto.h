//
//  jr_PHLivePhoto.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/18.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHLivePhoto_h
#define jr_PHLivePhoto_h

/// PHOTOS_CLASS_AVAILABLE_IOS_TVOS(9_1, 10_0)

/// 一个数字ID代表LivePhoto请求
typedef int32_t PHLivePhotoRequestID;
static const PHLivePhotoRequestID PHLivePhotoRequestIDInvalid = 0;

extern NSString * const PHLivePhotoInfoErrorKey;
// key : NSError decribing an error that has occurred while creating the live photo

extern NSString * const PHLivePhotoInfoIsDegradedKey;
// key : NSNumber containing a BOOL, YES whenever the deivered live photo object does not contain all content required for full playback.
extern NSString * const PHLivePhotoInfoCancelledKey;
// key : NSNumber containing a BOOL, YES when the result handler is being called after the request has been cancelled.


@interface PHLivePhoto : NSObject <NSCopying, NSSecureCoding>

#pragram mark - Inspecting a Live Photo
/// The dimensions of the live photo measured in pixels.
@property (readonly, nonatomic) CGSize size;

#pragram mark - Loading a Live Photo from Data Files
/// Asynchronously loads a Live Photo from the specified resource files.
+ (PHLivePhotoRequestID)requestLivePhotoWithResourceFileURLs:(NSArray<NSURL *> *)fileURLs
											placeholderImage:(UIImage *__nullable)image 
												  targetSize:(CGSize)targetSize 
												 contentMode:(PHImageContentMode)contentMode
											   resultHandler:(void(^)(PHLivePhoto *__nullable livePhoto, NSDictionary *info))resultHandler;

/// Cancels an asynchronous request
+ (void)cancelLivePhotoRequestWithRequestID:(PHLivePhotoRequestID)requestID;

#endif /* jr_PHLivePhoto_h */
