//
//  JRSimpCollectionController2.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/26.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpCollectionController2.h"

@interface JRSimpCollectionController2 () <UICollectionViewDataSource, UICollectionViewDelegate,
										UICollectionViewDelegateFlowLayout>
/// layout
@property (nonatomic, strong) UICollectionViewFlowLayout	*layout;
///
@property (nonatomic, strong) UICollectionView	*collectionView;

@property (nonatomic, assign) CGFloat hhhh;
@property (nonatomic, assign) CGFloat hhhh2;


@property (nonatomic, strong) NSMutableArray *hs;


@end

@implementation JRSimpCollectionController2

static NSString * const reuseIdentifier = @"Cell";

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.hs = [NSMutableArray array];
	
	for (int i=0; i<10; i++) {
		[self.hs addObject:@(SCREEN_H)];
	}
	
	
	[self setupUI];
}

///
- (void)setupUI {
	self.view.backgroundColor = [UIColor whiteColor];
	
	self.hhhh = 333;
	self.hhhh2 = SCREEN_H;
	
	self.collectionView = ({
		UICollectionView *colView = [[UICollectionView alloc] initWithFrame:self.view.bounds
													   collectionViewLayout:self.layout];
		colView.delegate	= self;
		colView.dataSource	= self;
		[colView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:reuseIdentifier];
		[self.view addSubview:colView];
		colView;
	});
	
	UIBarButtonItem *r = [[UIBarButtonItem alloc] initWithTitle:@"😁"
														  style:UIBarButtonItemStylePlain 
														 target:self 
														 action:@selector(test)];
	self.navigationItem.rightBarButtonItem = r;
}

- (void)test {
	self.hhhh = 2222;
	self.hhhh2 = 2;
	NSLog(@"=======");
	CGPoint point = self.collectionView.contentOffset;
	[self.collectionView reloadData];
	
//	[self.collectionView scrollRectToVisible:CGRectMake(point.x, point.y + 2222 - 333, SCREEN_W, SCREEN_H) animated:NO];
	
	[self.collectionView scrollRectToVisible:CGRectMake(point.x, point.y, SCREEN_W, SCREEN_H) animated:NO];
}

#pragma mark - UICollectionViewDataSource
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return 10;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier
																		   forIndexPath:indexPath];
	
	cell.backgroundColor = [UIColor cz_randomColor];
	
	return cell;
}

#pragma mark - UICollectionViewDelegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
	NSLog(@"== %@", indexPath);
}

#pragma mark - UICollectionViewDelegateFlowLayout
- (CGSize)collectionView:(UICollectionView *)collectionView
				  layout:(UICollectionViewLayout*)collectionViewLayout 
  sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
	
//	CGFloat w = (SCREEN_W - 20) / 2;
	
	NSLog(@"------ %@", indexPath);
	
//	if (indexPath.row == 3) {
//		CGFloat w = SCREEN_W;
//		return CGSizeMake(w, self.hhhh);
//	}
//	
//	if (indexPath.row == 1) {
//		CGFloat w = SCREEN_W;
//		return CGSizeMake(w, self.hhhh2);
//	}
	
	CGFloat w = SCREEN_W;
	return CGSizeMake(w, SCREEN_H - 64);
}


- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath {
	
	
	
}

//- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout insetForSectionAtIndex:(NSInteger)section;

- (CGFloat)collectionView:(UICollectionView *)collectionView
				   layout:(UICollectionViewLayout*)collectionViewLayout
	minimumLineSpacingForSectionAtIndex:(NSInteger)section {

	return 10;
}

- (CGFloat)collectionView:(UICollectionView *)collectionView 
				   layout:(UICollectionViewLayout*)collectionViewLayout
	minimumInteritemSpacingForSectionAtIndex:(NSInteger)section {
	return 10;
}

//- (CGSize)collectionView:(UICollectionView *)collectionView 
//				  layout:(UICollectionViewLayout*)collectionViewLayout
//referenceSizeForHeaderInSection:(NSInteger)section {
//	
//}

//- (CGSize)collectionView:(UICollectionView *)collectionView
//				  layout:(UICollectionViewLayout*)collectionViewLayout
//referenceSizeForFooterInSection:(NSInteger)section {
//	
//}

///////////
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath {
	return YES;
}

- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender {
	
	return YES;
}

- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender {
	NSLog(@"--- %@ %@", NSStringFromSelector(action), sender);
}


- (nonnull UICollectionViewTransitionLayout *)collectionView:(UICollectionView *)collectionView transitionLayoutForOldLayout:(UICollectionViewLayout *)fromLayout newLayout:(UICollectionViewLayout *)toLayout {
	NSLog(@"aaaaaaaaaaaaaaa");
	return [UICollectionViewTransitionLayout new];
}

#pragma mark - Getter Methond
- (UICollectionViewFlowLayout *)layout {
	
	if (_layout) {
		return _layout;
	}
	
	CGFloat w = (SCREEN_W - 20) / 2;
	_layout = [[UICollectionViewFlowLayout alloc] init];
	_layout.itemSize				= CGSizeMake(w, w);
	_layout.minimumLineSpacing		= 10;
	_layout.minimumInteritemSpacing = 20;
	
	return _layout;
}

@end
