//
//  jr_UICollectionViewFlowLayout.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/19.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_UICollectionViewFlowLayout_h
#define jr_UICollectionViewFlowLayout_h

UIKIT_EXTERN NSString *const UICollectionElementKindSectionHeader NS_AVAILABLE_IOS(6_0);
UIKIT_EXTERN NSString *const UICollectionElementKindSectionFooter NS_AVAILABLE_IOS(6_0);
UIKIT_EXTERN const CGSize UICollectionViewFlowLayoutAutomaticSize  NS_AVAILABLE_IOS(10_0);

typedef NS_ENUM(NSInteger, UICollectionViewScrollDirection) {
	UICollectionViewScrollDirectionVertical,
	UICollectionViewScrollDirectionHorizontal
};

@interface UICollectionViewFlowLayoutInvalidationContext : UICollectionViewLayoutInvalidationContext

@property (nonatomic) BOOL invalidateFlowLayoutDelegateMetrics; // if set to NO, flow layout will not requery the collection view delegate for size information etc.
@property (nonatomic) BOOL invalidateFlowLayoutAttributes; // if set to NO, flow layout will keep all layout information, effectively not invalidating - useful for a subclass which invalidates only a piece of itself

@end


/// UICollection 流式布局代理方法
@protocol UICollectionViewDelegateFlowLayout <UICollectionViewDelegate>
@optional

- (CGSize)collectionView:(UICollectionView *)collectionView 
				  layout:(UICollectionViewLayout*)collectionViewLayout
  sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView
						layout:(UICollectionViewLayout*)collectionViewLayout
		insetForSectionAtIndex:(NSInteger)section;

- (CGFloat)collectionView:(UICollectionView *)collectionView 
				   layout:(UICollectionViewLayout*)collectionViewLayout
minimumLineSpacingForSectionAtIndex:(NSInteger)section;

- (CGFloat)collectionView:(UICollectionView *)collectionView 
				   layout:(UICollectionViewLayout*)collectionViewLayout
minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;

- (CGSize)collectionView:(UICollectionView *)collectionView 
				  layout:(UICollectionViewLayout*)collectionViewLayout
referenceSizeForHeaderInSection:(NSInteger)section;

- (CGSize)collectionView:(UICollectionView *)collectionView 
				  layout:(UICollectionViewLayout*)collectionViewLayout
referenceSizeForFooterInSection:(NSInteger)section;


@end


/// UICollectionViewFlowLayout
@interface UICollectionViewFlowLayout : UICollectionViewLayout
// 最小的行距
@property (nonatomic) CGFloat minimumLineSpacing;
// 最小的列距
@property (nonatomic) CGFloat minimumInteritemSpacing;
// cell的大小
@property (nonatomic) CGSize itemSize;
@property (nonatomic) CGSize estimatedItemSize;
// defaults to CGSizeZero - setting a non-zero size enables cells that self-size via -preferredLayoutAttributesFittingAttributes:

// collectionView的滚动方向   UICollectionViewScrollDirectionVertical
@property (nonatomic) UICollectionViewScrollDirection scrollDirection;
// headersize
@property (nonatomic) CGSize headerReferenceSize;
@property (nonatomic) CGSize footerReferenceSize;
@property (nonatomic) UIEdgeInsets sectionInset;

// Set these properties to YES to get headers that pin to the top of the screen and footers that pin to the bottom while scrolling (similar to UITableView).
@property (nonatomic) BOOL sectionHeadersPinToVisibleBounds NS_AVAILABLE_IOS(9_0);
@property (nonatomic) BOOL sectionFootersPinToVisibleBounds NS_AVAILABLE_IOS(9_0);

@end


#endif /* jr_UICollectionViewFlowLayout_h */
