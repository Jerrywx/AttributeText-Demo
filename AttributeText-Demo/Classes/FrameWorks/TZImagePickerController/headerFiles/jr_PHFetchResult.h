//
//  jr_PHFetchResult.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/15.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_PHFetchResult_h
#define jr_PHFetchResult_h

@interface PHFetchResult<ObjectType> : NSObject <NSCopying, NSFastEnumeration>

@property (readonly) NSUInteger count;

- (ObjectType)objectAtIndex:(NSUInteger)index;

- (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx;

- (BOOL)containsObject:(ObjectType)anObject;

- (NSUInteger)indexOfObject:(ObjectType)anObject;

- (NSUInteger)indexOfObject:(ObjectType)anObject inRange:(NSRange)range;

@property (nonatomic, readonly, nullable) ObjectType firstObject;

@property (nonatomic, readonly, nullable) ObjectType lastObject;

- (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;

- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (NSUInteger)countOfAssetsWithMediaType:(PHAssetMediaType)mediaType;

@end


#endif /* jr_PHFetchResult_h */
