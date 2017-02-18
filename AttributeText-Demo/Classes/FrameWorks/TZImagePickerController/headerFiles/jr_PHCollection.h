//
//  jr_PHCollection.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHCollection_h
#define jr_PHCollection_h

/// The abstract superclass for Photos asset collections and collection lists.
@interface PHCollection : PHObject

/// A Boolean value indicating whether the collection can contain assets.
@property (nonatomic, assign, readonly) BOOL canContainAssets;
/// A Boolean value indicating whether the collection can contain other collections.
@property (nonatomic, assign, readonly) BOOL canContainCollections;
/// The localized name of the collection.
@property (nonatomic, strong, readonly, nullable) NSString *localizedTitle;

#pragma mark - Capabilities
/// Returns whether the collection supports the specified editing operation.
- (BOOL)canPerformEditOperation:(PHCollectionEditOperation)anOperation;

#pragma mark - Fetching collections

+ (PHFetchResult<PHCollection *> *)fetchCollectionsInCollectionList:(PHCollectionList *)collectionList 
															options:(nullable PHFetchOptions *)options;

+ (PHFetchResult<PHCollection *> *)fetchTopLevelUserCollectionsWithOptions:(nullable PHFetchOptions *)options;

@end


/// A representation of a Photos asset grouping, such as a moment, user-created album, or smart album.
@interface PHAssetCollection : PHCollection
/// 相册类型
@property (nonatomic, assign, readonly) PHAssetCollectionType assetCollectionType;
/// 相册子类型
@property (nonatomic, assign, readonly) PHAssetCollectionSubtype assetCollectionSubtype;
/// 相册中资源数量
@property (nonatomic, assign, readonly) NSUInteger estimatedAssetCount;

@property (nonatomic, strong, readonly, nullable) NSDate *startDate;

@property (nonatomic, strong, readonly, nullable) NSDate *endDate;

@property (nonatomic, strong, readonly, nullable) CLLocation *approximateLocation;

@property (nonatomic, strong, readonly) NSArray<NSString *> *localizedLocationNames;


#pragma mark - Fetching asset collections (获取资源集合)

// Fetch asset collections of a single type matching the provided local identifiers (type is inferred from the local identifiers)
+ (PHFetchResult<PHAssetCollection *> *)fetchAssetCollectionsWithLocalIdentifiers:(NSArray<NSString *> *)identifiers
																		  options:(nullable PHFetchOptions *)options;

/// Retrieves asset collections of the specified type and subtype.
+ (PHFetchResult<PHAssetCollection *> *)fetchAssetCollectionsWithType:(PHAssetCollectionType)type 
															  subtype:(PHAssetCollectionSubtype)subtype 
															  options:(nullable PHFetchOptions *)options;

// Smart Albums are not supported, only Albums and Moments
+ (PHFetchResult<PHAssetCollection *> *)fetchAssetCollectionsContainingAsset:(PHAsset *)asset 
																	withType:(PHAssetCollectionType)type 
																	 options:(nullable PHFetchOptions *)options;

// assetGroupURLs are URLs retrieved from ALAssetGroup's ALAssetsGroupPropertyURL
+ (PHFetchResult<PHAssetCollection *> *)fetchAssetCollectionsWithALAssetGroupURLs:(NSArray<NSURL *> *)assetGroupURLs 
																		  options:(nullable PHFetchOptions *)options;

#pragma mark - Fetching moment asset collections

+ (PHFetchResult<PHAssetCollection *> *)fetchMomentsInMomentList:(PHCollectionList *)momentList
														 options:(nullable PHFetchOptions *)options;

+ (PHFetchResult<PHAssetCollection *> *)fetchMomentsWithOptions:(nullable PHFetchOptions *)options;


#pragma mark - Creating Temporary Asset Collections (创建临时的资源结合)
/// 使用 PHAsset 数组 创建一个临时的资源集合
+ (PHAssetCollection *)transientAssetCollectionWithAssets:(NSArray<PHAsset *> *)assets 
													title:(nullable NSString *)title;
/// 使用 PHFetchResult 创建一个临时的资源集合
+ (PHAssetCollection *)transientAssetCollectionWithAssetFetchResult:(PHFetchResult<PHAsset *> *)fetchResult 
															  title:(nullable NSString *)title;

@end


/// A representation of a group containing Photos asset collections, such as a moments year or a folder of user-created albums.
@interface PHCollectionList : PHCollection
/// 筛选类型
@property (nonatomic, assign, readonly) PHCollectionListType collectionListType;
/// 筛选子类型
@property (nonatomic, assign, readonly) PHCollectionListSubtype collectionListSubtype;

@property (nonatomic, strong, readonly, nullable) NSDate *startDate;

@property (nonatomic, strong, readonly, nullable) NSDate *endDate;
/// 地区
@property (nonatomic, strong, readonly) NSArray<NSString *> *localizedLocationNames;

#pragma mark - Fetching collection lists

// A PHAssetCollectionTypeMoment will be contained by a PHCollectionListSubtypeMomentListCluster and a PHCollectionListSubtypeMomentListYear
// Non-moment PHAssetCollections will only be contained by a single collection list
+ (PHFetchResult<PHCollectionList *> *)fetchCollectionListsContainingCollection:(PHCollection *)collection 
																		options:(nullable PHFetchOptions *)options;

// Fetch collection lists of a single type matching the provided local identifiers (type is inferred from the local identifiers)
+ (PHFetchResult<PHCollectionList *> *)fetchCollectionListsWithLocalIdentifiers:(NSArray<NSString *> *)identifiers 
																		options:(nullable PHFetchOptions *)options;

// Fetch asset collections of a single type and subtype provided (use PHCollectionListSubtypeAny to match all subtypes)
+ (PHFetchResult<PHCollectionList *> *)fetchCollectionListsWithType:(PHCollectionListType)collectionListType 
															subtype:(PHCollectionListSubtype)subtype 
															options:(nullable PHFetchOptions *)options;

#pragma mark - Fetching moment collection lists
/// 根据 PHCollectionListSubtype 筛选时间/位置资源
+ (PHFetchResult<PHCollectionList *> *)fetchMomentListsWithSubtype:(PHCollectionListSubtype)momentListSubtype 
												  containingMoment:(PHAssetCollection *)moment 
														   options:(nullable PHFetchOptions *)options;
/// 根据 PHCollectionListSubtype 筛选时间/位置资源
+ (PHFetchResult<PHCollectionList *> *)fetchMomentListsWithSubtype:(PHCollectionListSubtype)momentListSubtype 
														   options:(nullable PHFetchOptions *)options;

#pragma mark - Creating Temporary Collection Lists (创建临时资源集合)
/// 根据 PHCollection 创建资源集合
+ (PHCollectionList *)transientCollectionListWithCollections:(NSArray<PHCollection *> *)collections 
													   title:(nullable NSString *)title;
/// 根据 PHFetchResult 创建资源集合
+ (PHCollectionList *)transientCollectionListWithCollectionsFetchResult:(PHFetchResult<PHCollection *> *)fetchResult
																  title:(nullable NSString *)title;

@end

#endif /* jr_PHCollection_h */


//PHAssetCollectionChangeRequest

