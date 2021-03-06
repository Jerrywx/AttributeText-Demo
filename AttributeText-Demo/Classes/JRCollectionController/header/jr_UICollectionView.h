//
//  jr_UICollectionView.h
//  UICollectionDemo
//
//  Created by 王潇 on 2017/3/19.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_UICollectionView_h
#define jr_UICollectionView_h

typedef NS_OPTIONS(NSUInteger, UICollectionViewScrollPosition) {
	UICollectionViewScrollPositionNone                 = 0,
	UICollectionViewScrollPositionTop                  = 1 << 0,
	UICollectionViewScrollPositionCenteredVertically   = 1 << 1,
	UICollectionViewScrollPositionBottom               = 1 << 2,
	UICollectionViewScrollPositionLeft                 = 1 << 3,
	UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
	UICollectionViewScrollPositionRight                = 1 << 5
};

// layout transition block signature
typedef void (^UICollectionViewLayoutInteractiveTransitionCompletion)(BOOL completed, BOOL finished);

NS_CLASS_AVAILABLE_IOS(9_0)
@interface UICollectionViewFocusUpdateContext : UIFocusUpdateContext

@property (nonatomic, strong, readonly, nullable) NSIndexPath *previouslyFocusedIndexPath;
@property (nonatomic, strong, readonly, nullable) NSIndexPath *nextFocusedIndexPath;

@end


//// UICollectionViewDataSource
@protocol UICollectionViewDataSource <NSObject>
@required

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView
						   cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView;

// The view that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView
		   viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

////
- (BOOL)collectionView:(UICollectionView *)collectionView
canMoveItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);

- (void)collectionView:(UICollectionView *)collectionView
   moveItemAtIndexPath:(NSIndexPath *)sourceIndexPath
		   toIndexPath:(NSIndexPath*)destinationIndexPath NS_AVAILABLE_IOS(9_0);

@end


@protocol UICollectionViewDataSourcePrefetching <NSObject>
@required
// indexPaths are ordered ascending by geometric distance from the collection view
- (void)collectionView:(UICollectionView *)collectionView prefetchItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths NS_AVAILABLE_IOS(10_0);

@optional
// indexPaths that previously were considered as candidates for pre-fetching, but were not actually used; may be a subset of the previous call to -collectionView:prefetchItemsAtIndexPaths:
- (void)collectionView:(UICollectionView *)collectionView cancelPrefetchingForItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths  NS_AVAILABLE_IOS(10_0);

@end


//// UICollectionViewDelegate
@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional
/// 是否可以高亮
- (BOOL)collectionView:(UICollectionView *)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
/// 高亮回调
- (void)collectionView:(UICollectionView *)collectionView didHighlightItemAtIndexPath:(NSIndexPath *)indexPath;
/// 取消高亮回调
- (void)collectionView:(UICollectionView *)collectionView didUnhighlightItemAtIndexPath:(NSIndexPath *)indexPath;
/// 是否可点击
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;
/// 是否可取消点击
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath; // called when the user taps on an already-selected item in multi-select mode
/// 选择回调
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;
/// 取消玄色回调
- (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;
/// cell 将要显示
- (void)collectionView:(UICollectionView *)collectionView 
	   willDisplayCell:(UICollectionViewCell *)cell 
	forItemAtIndexPath:(NSIndexPath *)indexPath;
/// SupplementaryView 将要显示
- (void)collectionView:(UICollectionView *)collectionView willDisplaySupplementaryView:(UICollectionReusableView *)view forElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;
/// cell 显示完成回调
- (void)collectionView:(UICollectionView *)collectionView 
  didEndDisplayingCell:(UICollectionViewCell *)cell 
	forItemAtIndexPath:(NSIndexPath *)indexPath;

/// SupplementaryView 显示完成回调
- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingSupplementaryView:(UICollectionReusableView *)view forElementOfKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;

// These methods provide support for copy/paste actions on cells.
// All three should be implemented if any are.
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender;

- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender;

// support for custom transition layout
- (nonnull UICollectionViewTransitionLayout *)collectionView:(UICollectionView *)collectionView transitionLayoutForOldLayout:(UICollectionViewLayout *)fromLayout newLayout:(UICollectionViewLayout *)toLayout;

// Focus
- (BOOL)collectionView:(UICollectionView *)collectionView canFocusItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);
- (BOOL)collectionView:(UICollectionView *)collectionView shouldUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context NS_AVAILABLE_IOS(9_0);
- (void)collectionView:(UICollectionView *)collectionView didUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context withAnimationCoordinator:(UIFocusAnimationCoordinator *)coordinator NS_AVAILABLE_IOS(9_0);
- (nullable NSIndexPath *)indexPathForPreferredFocusedViewInCollectionView:(UICollectionView *)collectionView NS_AVAILABLE_IOS(9_0);

- (NSIndexPath *)collectionView:(UICollectionView *)collectionView targetIndexPathForMoveFromItemAtIndexPath:(NSIndexPath *)originalIndexPath toProposedIndexPath:(NSIndexPath *)proposedIndexPath NS_AVAILABLE_IOS(9_0);

- (CGPoint)collectionView:(UICollectionView *)collectionView targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset NS_AVAILABLE_IOS(9_0); // customize the content offset to be applied during transition or update animations

@end


///// UICollectionView
@interface UICollectionView : UIScrollView

/* --------------------------------------------------------------------------- */
/* 初始化方法 (Initializing a Collection View) */
/* --------------------------------------------------------------------------- */
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder;


/* --------------------------------------------------------------------------- */
/* 配置CollectionView (Configuring the Collection View) */
/* --------------------------------------------------------------------------- */
/// 代理对象
@property (nonatomic, weak, nullable) id <UICollectionViewDelegate> delegate;
/// 资源代理对象
@property (nonatomic, weak, nullable) id <UICollectionViewDataSource> dataSource;
/// 背景View (自动调整到与collectionView 相同的大小，并且置于cell 和 已添加的view底部)
@property (nonatomic, strong, nullable) UIView *backgroundView;


/* --------------------------------------------------------------------------- */
/* 预先获取数据 (Prefetching Collection View Cells and Data)  iOS 10   */
/* --------------------------------------------------------------------------- */
@property (nonatomic, weak, nullable) id<UICollectionViewDataSourcePrefetching> prefetchDataSource NS_AVAILABLE_IOS(10_0);

@property (nonatomic, getter=isPrefetchingEnabled) BOOL prefetchingEnabled NS_AVAILABLE_IOS(10_0);


/* --------------------------------------------------------------------------- */
/* 创建cell (Creating Collection View Cells) */
/* --------------------------------------------------------------------------- */
/// Cell
- (void)registerClass:(nullable Class)cellClass forCellWithReuseIdentifier:(NSString *)identifier;
- (void)registerNib:(nullable UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;
- (__kindof UICollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier
															 forIndexPath:(NSIndexPath *)indexPath;

/// Supplementary
- (void)registerClass:(nullable Class)viewClass forSupplementaryViewOfKind:(NSString *)elementKind
  withReuseIdentifier:(NSString *)identifier;
- (void)registerNib:(nullable UINib *)nib forSupplementaryViewOfKind:(NSString *)kind
withReuseIdentifier:(NSString *)identifier;
- (__kindof UICollectionReusableView *)dequeueReusableSupplementaryViewOfKind:(NSString *)elementKind
														  withReuseIdentifier:(NSString *)identifier
																 forIndexPath:(NSIndexPath *)indexPath;


/* --------------------------------------------------------------------------- */
/* 修改布局 (Changing the Layout) */
/* --------------------------------------------------------------------------- */

//// UICollectionViewLayout
@property (nonatomic, strong) UICollectionViewLayout *collectionViewLayout;

//// 设置 UICollectionViewLayout 动画
- (void)setCollectionViewLayout:(UICollectionViewLayout *)layout animated:(BOOL)animated;
//// 设置 UICollectionViewLayout 动画 回调
- (void)setCollectionViewLayout:(UICollectionViewLayout *)layout animated:(BOOL)animated
					 completion:(void (^ __nullable)(BOOL finished))completion;

//// Changes the collection view’s current layout using an interactive transition effect.
- (UICollectionViewTransitionLayout *)startInteractiveTransitionToCollectionViewLayout:(UICollectionViewLayout *)layout completion:(nullable UICollectionViewLayoutInteractiveTransitionCompletion)completion;

//// Tells the collection view to finish an interactive transition by installing the intended target layout.
- (void)finishInteractiveTransition;
//// Tells the collection view to abort an interactive transition and return to its original layout object.
- (void)cancelInteractiveTransition;


/* --------------------------------------------------------------------------- */
/* 重新加载内容 (Reloading Content) */
/* --------------------------------------------------------------------------- */
//// Reloads all of the data for the collection view.
- (void)reloadData;

- (void)reloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

- (void)reloadSections:(NSIndexSet *)sections;

/* --------------------------------------------------------------------------- */
/* 获取Collection View状态 (Getting the State of the Collection View) */
/* --------------------------------------------------------------------------- */
- (NSInteger)numberOfSections;

- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (NSArray<__kindof UICollectionViewCell *> *)visibleCells;

@property (nonatomic, readonly) NSArray<__kindof UICollectionViewCell *> *visibleCells;

/* --------------------------------------------------------------------------- */
/* 插入、移动或者删除 cell (Inserting, Moving, and Deleting Items) */
/* --------------------------------------------------------------------------- */
- (void)insertItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)deleteItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;


/* --------------------------------------------------------------------------- */
/* 插入、移动或者删除 sections (Inserting, Moving, and Deleting Sections) */
/* --------------------------------------------------------------------------- */
// These methods allow dynamic modification of the current set of items in the collection view
- (void)insertSections:(NSIndexSet *)sections;
- (void)deleteSections:(NSIndexSet *)sections;
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection;


/* --------------------------------------------------------------------------- */
/*  (Reordering Items Interactively) NS_AVAILABLE_IOS(9_0) */
/* --------------------------------------------------------------------------- */
// Support for reordering
// returns NO if reordering was prevented from beginning - otherwise YES
- (BOOL)beginInteractiveMovementForItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)updateInteractiveMovementTargetPosition:(CGPoint)targetPosition;
- (void)endInteractiveMovement;
- (void)cancelInteractiveMovement;

/* --------------------------------------------------------------------------- */
/*  (Managing the Selection) */
/* --------------------------------------------------------------------------- */
/// default is YES
@property (nonatomic) BOOL allowsSelection;
/// default is NO
@property (nonatomic) BOOL allowsMultipleSelection;
///
- (nullable NSArray<NSIndexPath *> *)indexPathsForSelectedItems;
///
- (void)selectItemAtIndexPath:(nullable NSIndexPath *)indexPath
					 animated:(BOOL)animated
			   scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
///
- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;


/* --------------------------------------------------------------------------- */
/*  (Managing Focus) */
/* --------------------------------------------------------------------------- */
// Support for Focus
@property (nonatomic) BOOL remembersLastFocusedIndexPath NS_AVAILABLE_IOS(9_0);
// defaults to NO. If YES, when focusing on a collection view the last focused index path is focused automatically. If the collection view has never been focused, then the preferred focused index path is used.

/* --------------------------------------------------------------------------- */
/* Locating Items and Views in the Collection View */
/* --------------------------------------------------------------------------- */
/// 根据点 获取 索引
- (nullable NSIndexPath *)indexPathForItemAtPoint:(CGPoint)point;
/// 获取显示的 Cell
@property (nonatomic, readonly) NSArray<NSIndexPath *> *indexPathsForVisibleItems;
/// 获取 cell 的索引
- (nullable NSIndexPath *)indexPathForCell:(UICollectionViewCell *)cell;
/// 根据索引 获取 cell
- (nullable UICollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

- (NSArray<NSIndexPath *> *)indexPathsForVisibleSupplementaryElementsOfKind:(NSString *)elementKind NS_AVAILABLE_IOS(9_0);

- (nullable UICollectionReusableView *)supplementaryViewForElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);

- (NSArray<UICollectionReusableView *> *)visibleSupplementaryViewsOfKind:(NSString *)elementKind NS_AVAILABLE_IOS(9_0);


/* --------------------------------------------------------------------------- */
/* Getting Layout Information */
/* --------------------------------------------------------------------------- */

- (nullable UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath;

- (nullable UICollectionViewLayoutAttributes *)layoutAttributesForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

/* --------------------------------------------------------------------------- */
/* Scrolling an Item Into View */
/* --------------------------------------------------------------------------- */
///
- (void)scrollToItemAtIndexPath:(NSIndexPath *)indexPath
			   atScrollPosition:(UICollectionViewScrollPosition)scrollPosition
					   animated:(BOOL)animated;


/* --------------------------------------------------------------------------- */
/* Animating Multiple Changes to the Collection View */
/* --------------------------------------------------------------------------- */
// allows multiple insert/delete/reload/move calls to be animated simultaneously. Nestable.
- (void)performBatchUpdates:(void (^ __nullable)(void))updates
				 completion:(void (^ __nullable)(BOOL finished))completion;


@end


///// NSIndexPath
@interface NSIndexPath (UICollectionViewAdditions)

+ (instancetype)indexPathForItem:(NSInteger)item inSection:(NSInteger)section;

@property (nonatomic, readonly) NSInteger item;

@end

#endif
