//
//  jr_PHChange.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/18.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHChange_h
#define jr_PHChange_h

PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHChange : NSObject

- (nullable PHObjectChangeDetails *)changeDetailsForObject:(PHObject *)object;
- (nullable PHFetchResultChangeDetails *)changeDetailsForFetchResult:(PHFetchResult *)object;

@end



PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHObjectChangeDetails<ObjectType: PHObject *> : NSObject

// the object in the state before this change (returns the object that was passed in to changeDetailsForObject:)
@property (atomic, strong, readonly) __kindof ObjectType objectBeforeChanges;

// the object in the state after this change
@property (atomic, strong, readonly, nullable) __kindof ObjectType objectAfterChanges;

// YES if the image or video content for this object has been changed
@property (atomic, readonly) BOOL assetContentChanged;

// YES if the object was deleted
@property (atomic, readonly) BOOL objectWasDeleted;

@end



PHOTOS_CLASS_AVAILABLE_IOS_TVOS(8_0, 10_0) @interface PHFetchResultChangeDetails<ObjectType: PHObject *> : NSObject

// fetch result with the state of the fetched objects before this change (returns the fetch result passed in to changeDetailsForFetchResult:)
@property (atomic, strong, readonly) PHFetchResult<ObjectType> *fetchResultBeforeChanges;

// fetch result with the state of the fetched objects after this change
@property (atomic, strong, readonly) PHFetchResult<ObjectType> *fetchResultAfterChanges;

// YES if the changes to this fetch result are described by the removed/inserted/changed details.
// NO indicates that the scope of changes were too large and UI clients should do a full reload, incremental changes could not be provided
@property (atomic, assign, readonly) BOOL hasIncrementalChanges;

// The indexes of the removed items, relative to the 'before' state of the fetch result
// returns nil if hasIncrementalChanges is NO
@property (atomic, strong, readonly, nullable) NSIndexSet *removedIndexes;
@property (atomic, strong, readonly) NSArray<ObjectType> *removedObjects;

// The indexes of the inserted items, relative to the 'before' state of the fetch result after applying the removedIndexes
// returns nil if hasIncrementalChanges is NO
@property (atomic, strong, readonly, nullable) NSIndexSet *insertedIndexes;
@property (atomic, strong, readonly) NSArray<ObjectType> *insertedObjects;

// The indexes of the updated items, relative to the 'after' state of the fetch result
// returns nil if hasIncrementalChanges is NO
@property (atomic, strong, readonly, nullable) NSIndexSet *changedIndexes;
@property (atomic, strong, readonly) NSArray<ObjectType> *changedObjects;

// Enumerates the indexes of the moved items, relative to the 'before' state of the fetch result after applying the removedIndexes and insertedIndexes
- (void)enumerateMovesWithBlock:(void(^)(NSUInteger fromIndex, NSUInteger toIndex))handler;

// YES if there are moved items
// returns NO if hasIncrementalChanges is NO
@property (atomic, assign, readonly) BOOL hasMoves;


// Provides a "diff" between 2 PHFetchResult objects.
+ (instancetype)changeDetailsFromFetchResult:(PHFetchResult<ObjectType> *)fromResult toFetchResult:(PHFetchResult<ObjectType> *)toResult changedObjects:(NSArray<ObjectType> *)changedObjects;

@end


#endif /* jr_PHChange_h */
