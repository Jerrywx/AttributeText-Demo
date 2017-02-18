//
//  JRImageManager.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/17.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRImageManager.h"
#import <Photos/Photos.h>

@implementation JRImageManager

/// 获取所有相册
+ (void)getAllAlbum {
//	PHPhotoLibrary
	/// 根据类型获取相册
//	[self getAlbumWithType];
//	[self getAlbumWithLocation];
	[self getAlbumWithMoments2];
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
			NSLog(@"--- %@ - %zd", [obj class], idx);
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

@end

