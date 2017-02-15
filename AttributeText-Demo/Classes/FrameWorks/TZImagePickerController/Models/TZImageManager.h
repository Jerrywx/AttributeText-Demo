//
//  TZImageManager.h
//  TZImagePickerController
//
//  Created by 谭真 on 16/1/4.
//  Copyright © 2016年 谭真. All rights reserved.
//  图片资源获取管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Photos/Photos.h>

@class TZAlbumModel,TZAssetModel;
@interface TZImageManager : NSObject

@property (nonatomic, strong) PHCachingImageManager *cachingImageManager;

+ (instancetype)manager;
/// 修正方向
@property (nonatomic, assign) BOOL shouldFixOrientation;
/// Default is 600px / 默认600像素宽
@property (nonatomic, assign) CGFloat photoPreviewMaxWidth;
/// 默认4列, TZPhotoPickerController中的照片collectionView
@property (nonatomic, assign) NSInteger columnNumber;
/// 对照片排序，按修改时间升序，默认是YES。如果设置为NO,最新的照片会显示在最前面，内部的拍照按钮会排在第一个
@property (nonatomic, assign) BOOL sortAscendingByModificationDate;
/// 最小可选中的图片宽度，默认是0，小于这个宽度的图片不可选中
@property (nonatomic, assign) NSInteger minPhotoWidthSelectable;
@property (nonatomic, assign) NSInteger minPhotoHeightSelectable;
@property (nonatomic, assign) BOOL hideWhenCanNotSelect;

#pragma mark - 权限
/// Return YES if Authorized 返回YES如果得到了授权
- (BOOL)authorizationStatusAuthorized;
/// 获取用户权限
- (NSInteger)authorizationStatus;

#pragma mark - 获取资源
/// 获取相机胶卷相册
- (void)getCameraRollAlbum:(BOOL)allowPickingVideo 
		 allowPickingImage:(BOOL)allowPickingImage 
				completion:(void (^)(TZAlbumModel *model))completion;
/// 获取所有相册
- (void)getAllAlbums:(BOOL)allowPickingVideo 
   allowPickingImage:(BOOL)allowPickingImage 
		  completion:(void (^)(NSArray<TZAlbumModel *> *models))completion;

#pragma mark - 获取相册
/// 获得Asset数组
- (void)getAssetsFromFetchResult:(id)result
			   allowPickingVideo:(BOOL)allowPickingVideo 
			   allowPickingImage:(BOOL)allowPickingImage 
					  completion:(void (^)(NSArray<TZAssetModel *> *models))completion;

/// 
- (void)getAssetFromFetchResult:(id)result 
						atIndex:(NSInteger)index 
			  allowPickingVideo:(BOOL)allowPickingVideo 
			  allowPickingImage:(BOOL)allowPickingImage 
					 completion:(void (^)(TZAssetModel *model))completion;

/// Get photo 获得照片
- (void)getPostImageWithAlbumModel:(TZAlbumModel *)model 
						completion:(void (^)(UIImage *postImage))completion;

- (PHImageRequestID)getPhotoWithAsset:(id)asset 
						   completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion;

- (PHImageRequestID)getPhotoWithAsset:(id)asset 
						   photoWidth:(CGFloat)photoWidth 
						   completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion;

- (PHImageRequestID)getPhotoWithAsset:(id)asset 
						   completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion 
					  progressHandler:(void (^)(double progress, NSError *error, BOOL *stop, NSDictionary *info))progressHandler
				 networkAccessAllowed:(BOOL)networkAccessAllowed;

- (PHImageRequestID)getPhotoWithAsset:(id)asset 
						   photoWidth:(CGFloat)photoWidth 
						   completion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion 
					  progressHandler:(void (^)(double progress, NSError *error, BOOL *stop, NSDictionary *info))progressHandler
				 networkAccessAllowed:(BOOL)networkAccessAllowed;

#pragma mark - Get full Image 获取原图
/// 该方法会先返回缩略图，再返回原图，如果info[PHImageResultIsDegradedKey] 为 YES，则表明当前返回的是缩略图，否则是原图。
- (void)getOriginalPhotoWithAsset:(id)asset 
					   completion:(void (^)(UIImage *photo,NSDictionary *info))completion;
/// 获取 Image
- (void)getOriginalPhotoWithAsset:(id)asset
					newCompletion:(void (^)(UIImage *photo,NSDictionary *info,BOOL isDegraded))completion;
/// 获取 ImageData
- (void)getOriginalPhotoDataWithAsset:(id)asset 
						   completion:(void (^)(NSData *data,NSDictionary *info,BOOL isDegraded))completion;

#pragma mark - Save photo 保存照片
- (void)savePhotoWithImage:(UIImage *)image 
				completion:(void (^)(NSError *error))completion;

#pragma mark - 视频相关
/// Get video 获得视频
- (void)getVideoWithAsset:(id)asset 
			   completion:(void (^)(AVPlayerItem * playerItem, NSDictionary * info))completion;

/// Export video 导出视频
- (void)getVideoOutputPathWithAsset:(id)asset completion:(void (^)(NSString *outputPath))completion;

#pragma mark - 其他方法
/// Get photo bytes 获得一组照片的大小
- (void)getPhotosBytesWithArray:(NSArray *)photos
					 completion:(void (^)(NSString *totalBytes))completion;

/// Judge is a assets array contain the asset 判断一个assets数组是否包含这个asset
- (BOOL)isAssetsArray:(NSArray *)assets containAsset:(id)asset;

- (NSString *)getAssetIdentifier:(id)asset;

- (BOOL)isCameraRollAlbum:(NSString *)albumName;
/// 检查照片大小是否满足最小要求
- (BOOL)isPhotoSelectableWithAsset:(id)asset;
/// 获取图片尺寸
- (CGSize)photoSizeWithAsset:(id)asset;

/// 修正图片转向
- (UIImage *)fixOrientation:(UIImage *)aImage;

@end





