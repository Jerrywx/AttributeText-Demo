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
	PHAuthorizationStatusNotDetermined = 0,		// 未知
	PHAuthorizationStatusRestricted,			// 
	PHAuthorizationStatusDenied,
	PHAuthorizationStatusAuthorized				// 有权限
};


/// 相册改动监听
@protocol PHPhotoLibraryChangeObserver <NSObject>
// This callback is invoked on an arbitrary serial queue. If you need this to be handled on a specific queue, you should redispatch appropriately
- (void)photoLibraryDidChange:(PHChange *)changeInstance;

@end

///
@interface PHPhotoLibrary : NSObject
/// 获取 PHPhotoLibrary 单粒
+ (PHPhotoLibrary *)sharedPhotoLibrary;
/// 获取Photos访问权限
+ (PHAuthorizationStatus)authorizationStatus;
/// 获取Photos访问权限
+ (void)requestAuthorization:(void(^)(PHAuthorizationStatus status))handler;

#pragma mark - Applying Changes to the Photo Library
/// 异步运行 Photo 修改
- (void)performChanges:(dispatch_block_t)changeBlock 
	 completionHandler:(nullable void(^)(BOOL success, NSError *__nullable error))completionHandler;
/// 同步运行修改
- (BOOL)performChangesAndWait:(dispatch_block_t)changeBlock error:(NSError *__autoreleasing *)error;

#pragma mark - Observing Changes in the Photo Library
/// 注册 Photos 改变监听
- (void)registerChangeObserver:(id<PHPhotoLibraryChangeObserver>)observer;
/// 取消注册 Photos 改变监听
- (void)unregisterChangeObserver:(id<PHPhotoLibraryChangeObserver>)observer;

@end


#endif /* jr_PHPhotoLibrary_h */
