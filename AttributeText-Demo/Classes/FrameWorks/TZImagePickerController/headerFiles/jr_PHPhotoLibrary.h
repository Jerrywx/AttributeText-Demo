//
//  jr_PHPhotoLibrary.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHPhotoLibrary_h
#define jr_PHPhotoLibrary_h

/// 用户访问图片权限
typedef NS_ENUM(NSInteger, PHAuthorizationStatus) {
	PHAuthorizationStatusNotDetermined = 0,
	PHAuthorizationStatusRestricted,
	PHAuthorizationStatusDenied,
	PHAuthorizationStatusAuthorized
};


@protocol PHPhotoLibraryChangeObserver <NSObject>
// This callback is invoked on an arbitrary serial queue. If you need this to be handled on a specific queue, you should redispatch appropriately
- (void)photoLibraryDidChange:(PHChange *)changeInstance;

@end

/*!
 @class        PHPhotoLibrary
 @abstract     A PHPhotoLibrary provides access to the metadata and image data for the photos, videos and related content in the user's photo library, including content from the Camera Roll, iCloud Shared, Photo Stream, imported, and synced from iTunes.
 @discussion   ...
 */
@interface PHPhotoLibrary : NSObject

+ (PHPhotoLibrary *)sharedPhotoLibrary;

+ (PHAuthorizationStatus)authorizationStatus;

+ (void)requestAuthorization:(void(^)(PHAuthorizationStatus status))handler;

#pragma mark - Applying Changes

// handlers are invoked on an arbitrary serial queue
// Nesting change requests will throw an exception
- (void)performChanges:(dispatch_block_t)changeBlock 
	 completionHandler:(nullable void(^)(BOOL success, NSError *__nullable error))completionHandler;

- (BOOL)performChangesAndWait:(dispatch_block_t)changeBlock error:(NSError *__autoreleasing *)error;

#pragma mark - Change Handling

- (void)registerChangeObserver:(id<PHPhotoLibraryChangeObserver>)observer;
- (void)unregisterChangeObserver:(id<PHPhotoLibraryChangeObserver>)observer;

@end


#endif /* jr_PHPhotoLibrary_h */
