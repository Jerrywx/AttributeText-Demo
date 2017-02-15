//
//  jr_PHAsset.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHAsset_h
#define jr_PHAsset_h

// A representation of an image, video or Live Photo in the Photos library.
PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHAsset : PHObject

#pragma mark - Properties
/// 资源类型[照片、视频...]
@property (nonatomic, assign, readonly) PHAssetMediaType	mediaType;
/// 资源子类型
@property (nonatomic, assign, readonly) PHAssetMediaSubtype mediaSubtypes;
/// Size
@property (nonatomic, assign, readonly) NSUInteger pixelWidth;
@property (nonatomic, assign, readonly) NSUInteger pixelHeight;
/// 创建时间
@property (nonatomic, strong, readonly, nullable) NSDate *creationDate;
/// 最后修改时间
@property (nonatomic, strong, readonly, nullable) NSDate *modificationDate;
/// 地点
@property (nonatomic, strong, readonly, nullable) CLLocation *location;
/// 视频时间
@property (nonatomic, assign, readonly) NSTimeInterval duration;
/// 是否隐藏
@property (nonatomic, assign, readonly, getter=isHidden) BOOL hidden;
/// 是否喜欢
@property (nonatomic, assign, readonly, getter=isFavorite) BOOL favorite;
/// 唯一标识
@property (nonatomic, strong, readonly, nullable) NSString *burstIdentifier;
/// 连拍？？？
@property (nonatomic, assign, readonly) PHAssetBurstSelectionType burstSelectionTypes;

@property (nonatomic, assign, readonly) BOOL representsBurst;
/// 资源来源
@property (nonatomic, assign, readonly) PHAssetSourceType sourceType;

#pragma mark - Capabilities

- (BOOL)canPerformEditOperation:(PHAssetEditOperation)editOperation;

#pragma mark - Fetching assets

+ (PHFetchResult<PHAsset *> *)fetchAssetsInAssetCollection:(PHAssetCollection *)assetCollection
												   options:(nullable PHFetchOptions *)options;

+ (PHFetchResult<PHAsset *> *)fetchAssetsWithLocalIdentifiers:(NSArray<NSString *> *)identifiers 
													  options:(nullable PHFetchOptions *)options;

+ (nullable PHFetchResult<PHAsset *> *)fetchKeyAssetsInAssetCollection:(PHAssetCollection *)assetCollection 
															   options:(nullable PHFetchOptions *)options;

+ (PHFetchResult<PHAsset *> *)fetchAssetsWithBurstIdentifier:(NSString *)burstIdentifier 
													 options:(nullable PHFetchOptions *)options;

// Fetches PHAssetSourceTypeUserLibrary assets by default (use includeAssetSourceTypes option to override)
+ (PHFetchResult<PHAsset *> *)fetchAssetsWithOptions:(nullable PHFetchOptions *)options;

+ (PHFetchResult<PHAsset *> *)fetchAssetsWithMediaType:(PHAssetMediaType)mediaType 
											   options:(nullable PHFetchOptions *)options;

// assetURLs are URLs retrieved from ALAsset's ALAssetPropertyAssetURL
+ (PHFetchResult<PHAsset *> *)fetchAssetsWithALAssetURLs:(NSArray<NSURL *> *)assetURLs 
												 options:(nullable PHFetchOptions *)options;


#endif /* jr_PHAsset_h */
