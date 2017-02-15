
//
//  jr_PHFetchOptions.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHFetchOptions_h
#define jr_PHFetchOptions_h

@interface PHFetchOptions : NSObject <NSCopying>

// Some predicates / sorts may be suboptimal and we will log
#program mark - Sorting and Filtering Fetch Results
/// 筛选断言
@property (nonatomic, strong, nullable) NSPredicate *predicate;
/// 排序方式
@property (nonatomic, strong, nullable) NSArray<NSSortDescriptor *> *sortDescriptors;

// Whether hidden assets are included in fetch results. Defaults to NO
@property (nonatomic, assign) BOOL includeHiddenAssets;

// Whether hidden burst assets are included in fetch results. Defaults to NO
@property (nonatomic, assign) BOOL includeAllBurstAssets;

// The asset source types included in the fetch results.  Defaults to PHAssetSourceTypeNone.
// If set to PHAssetSourceTypeNone the asset source types included in the fetch results are inferred from the type of query performed (see PHAsset fetchAssetsWithOptions:)
@property (nonatomic, assign) PHAssetSourceType includeAssetSourceTypes PHOTOS_AVAILABLE_IOS_TVOS(9_0, 10_0);

// Limits the maximum number of objects returned in the fetch result, a value of 0 means no limit.  Defaults to 0.
@property (nonatomic, assign, readwrite) NSUInteger fetchLimit PHOTOS_AVAILABLE_IOS_TVOS(9_0, 10_0);

// Whether the owner of this object is interested in incremental change details for the results of this fetch (see PHChange)
// Defaults to YES
@property (nonatomic, assign) BOOL wantsIncrementalChangeDetails;

#endif /* jr_PHFetchOptions_h */
