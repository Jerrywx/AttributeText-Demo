//
//  TZAssetModel.h
//  TZImagePickerController
//
//  Created by 谭真 on 15/12/24.
//  Copyright © 2015年 谭真. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    TZAssetModelMediaTypePhoto = 0,		// 照片
    TZAssetModelMediaTypeLivePhoto,		// LivePhoto
    TZAssetModelMediaTypePhotoGif,		// gif
    TZAssetModelMediaTypeVideo,			// 视频
    TZAssetModelMediaTypeAudio			// 音频
} TZAssetModelMediaType;

/// 资源
@class PHAsset;
@interface TZAssetModel : NSObject

@property (nonatomic, strong) id		asset;				///< PHAsset or ALAsset
@property (nonatomic, assign) BOOL		isSelected;			///< The select status of a photo, default is No
@property (nonatomic, copy) NSString	*timeLength;
@property (nonatomic, assign) TZAssetModelMediaType type;

/// Init a photo dataModel With a asset
/// 用一个PHAsset/ALAsset实例，初始化一个照片模型
+ (instancetype)modelWithAsset:(id)asset type:(TZAssetModelMediaType)type;

+ (instancetype)modelWithAsset:(id)asset type:(TZAssetModelMediaType)type timeLength:(NSString *)timeLength;

@end

/// 相册
@class PHFetchResult;
@interface TZAlbumModel : NSObject

@property (nonatomic, strong) NSString	*name;			///< The album name
@property (nonatomic, assign) NSInteger count;			///< Count of photos the album contain
@property (nonatomic, strong) id		result;			///< PHFetchResult<PHAsset> or ALAssetsGroup<ALAsset>

@property (nonatomic, strong) NSArray	*models;			/// 资源数组
@property (nonatomic, strong) NSArray	*selectedModels;	///	选中的资源
@property (nonatomic, assign) NSUInteger selectedCount;		///	选中的数量

@end
