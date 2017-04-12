//
//  JRImageManager.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/17.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRImageManager.h"
#import <Photos/Photos.h>
#import "JRAssetCollection.h"
#import "JRAssetsManager.h"

@implementation JRImageManager

/// 获取所有相册
+ (void)getAllAlbum {
//	PHPhotoLibrary
	/// 根据类型获取相册
//	[self getAlbumWithType];
//	[self getAlbumWithLocation];
//	[self getAlbumWithMoments2];
	
	[self getSmartAlbumList];
	NSLog(@"=======================");
	[self getCustomAlbumList];
	
	NSLog(@"%@", [JRAssetsManager sharedAssetsManager].albums);
}

#pragma mark -

/**
 获取智能相册
 */
+ (void)getSmartAlbumList {
	/// 根据类型选择相册
//	PHFetchResult *albumResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeSmartAlbum
//																		  subtype:PHAssetCollectionSubtypeAlbumRegular
//																		  options:nil];

	
	PHFetchResult *albumResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeSmartAlbum
																		  subtype:PHAssetCollectionSubtypeAlbumRegular
																		  options:nil];
	
	CFTimeInterval start = CACurrentMediaTime();
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		
		if (res.count > 0) {
			JRAssetCollection *collection = [JRAssetCollection new];
			collection.assetCount	= res.count;
			collection.albumName	= asset.localizedTitle;
			[[JRAssetsManager sharedAssetsManager].albums addObject:collection];
		}

		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
	CFTimeInterval end = CACurrentMediaTime();
	NSLog(@"=-------2 %f", end - start);
}

/**
 获取用户创建相册
 */
+ (void)getCustomAlbumList {
	PHFetchResult *albumResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeAlbum
																		  subtype:PHAssetCollectionSubtypeAlbumRegular
																		  options:nil];
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		
		if (res.count > 0) {
			JRAssetCollection *collection = [JRAssetCollection new];
			collection.assetCount	= res.count;
			collection.albumName	= asset.localizedTitle;
			[[JRAssetsManager sharedAssetsManager].albums addObject:collection];
		}
		
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
			//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
}

/**
 获取时刻列表
 */
+ (void)getMomentAlbumList {
	
	PHFetchResult *albumResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeMoment
																		  subtype:PHAssetCollectionSubtypeAlbumRegular
																		  options:nil];
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
			//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
}


/// 根据类型获取相册
+ (void)getAlbumWithType {
	
	/// 根据类型选择相册
	PHFetchResult *albumResult = [PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeAlbum
																		  subtype:PHAssetCollectionSubtypeAlbumRegular
																		  options:nil];
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
}

/// 地点获取相册
+ (void)getAlbumWithLocation {
	
	PHFetchResult *albumResult = [PHAssetCollection fetchMomentsWithOptions:nil];
	
	__block NSInteger number = 0;
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		number += asset.estimatedAssetCount;
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
	NSLog(@"====== 图片数量: %zd", number);
}

/// 时间-地点选择
+ (void)getAlbumWithMoments {

	/// 获取 PHCollectionList 设置按时间选择
	PHFetchResult *fetchResult = [PHCollectionList fetchMomentListsWithSubtype:PHCollectionListSubtypeMomentListYear
																	   options:nil];
	
	/// 遍历 PHCollectionList
	[fetchResult enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %@", [obj class], [obj localizedLocationNames][0]);
		
		/// 默认选择模式是 地点
		PHFetchResult *albumResult = [PHAssetCollection fetchMomentsInMomentList:obj options:nil];
		
		[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
			NSLog(@"%@ - %zd == %@", asset.localizedTitle, asset.estimatedAssetCount, asset.startDate);
			PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
			[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
				//			NSLog(@"--- %@ - %zd", [obj class], idx);
			}];
		}];
	}];
}

/// 时间-地点选择
+ (void)getAlbumWithMoments2 {
	
	/// 获取 PHCollectionList 设置按时间选择
	PHFetchOptions *option = [[PHFetchOptions alloc] init];
	PHFetchResult *fetchResult = [PHCollectionList fetchMomentListsWithSubtype:PHCollectionListSubtypeMomentListCluster
																	   options:nil];
	
	/// 遍历 PHCollectionList
	[fetchResult enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %@", [obj class], [obj localizedLocationNames][0]);
		
		/// 默认选择模式是 地点
		PHFetchResult *albumResult = [PHAssetCollection fetchMomentsInMomentList:obj options:nil];
		
		[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
			NSLog(@"%@ - %zd == %@", asset.localizedTitle, asset.estimatedAssetCount, asset.startDate);
			PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
			[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
				//			NSLog(@"--- %@ - %zd", [obj class], idx);
			}];
		}];
	}];
}

///
+ (void)fetchWithLocalIdentifiers {
	
	/// 获取当前
//	[PHAssetCollection fetchAssetCollectionsWithLocalIdentifiers:<#(nonnull NSArray<NSString *> *)#> options:<#(nullable PHFetchOptions *)#>]
	
}

+ (void)fetchWithType {
	
	// PHAssetCollectionType
	//	1. PHAssetCollectionTypeAlbum
	//	An album in the Photos app.
	//	2. PHAssetCollectionTypeSmartAlbum
	//	A smart album whose contents update dynamically.
	//	3. PHAssetCollectionTypeMoment
	//	A moment in the Photos app.
	
	
//	[PHAssetCollection fetchAssetCollectionsWithType:PHAssetCollectionTypeAlbum subtype:<#(PHAssetCollectionSubtype)#> options:<#(nullable PHFetchOptions *)#>]
	
}

/// 根据时刻获取相册
+ (void)fetchMomentsWithOptions {
	
	PHFetchOptions *options = [[PHFetchOptions alloc] init];
	PHFetchResult *albumResult = [PHAssetCollection fetchMomentsWithOptions:options];
	
	NSLog(@"======= %zd", albumResult.count);
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
	
}

///
+ (void)fetchMomentsInMomentList {
	
	PHCollectionList *list = [[PHCollectionList alloc] init];
	PHFetchOptions *options = [[PHFetchOptions alloc] init];
	PHFetchResult *albumResult = [PHAssetCollection fetchMomentsInMomentList:list options:options];
	
	[albumResult enumerateObjectsUsingBlock:^(PHAssetCollection *asset, NSUInteger idx, BOOL * _Nonnull stop) {
		NSLog(@"%@ - %zd", asset.localizedTitle, asset.estimatedAssetCount);
		PHFetchResult *res = [PHAsset fetchAssetsInAssetCollection:asset options:nil];
		[res enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
			//			NSLog(@"--- %@ - %zd", [obj class], idx);
		}];
	}];
}

/*
 + fetchAssetCollectionsWithLocalIdentifiers:options:
	Retrieves asset collections with the specified unique identifiers.
 + fetchAssetCollectionsWithType:subtype:options:
	Retrieves asset collections of the specified type and subtype.
 + fetchAssetCollectionsContainingAsset:withType:options:
	Retrieves asset collections of the specified type containing the specified asset.
 + fetchAssetCollectionsWithALAssetGroupURLs:options:
	Retrieves asset collections using URLs provided by the Assets Library framework.
 + fetchMomentsInMomentList:options:
	Retrieves asset collections in the specified moment list collection.
 + fetchMomentsWithOptions:
	Retrieves asset collections corresponding to moments seen in the Photos app.

 */

@end

