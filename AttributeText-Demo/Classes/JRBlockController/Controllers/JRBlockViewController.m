//
//  JRBlockViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRBlockViewController.h"

@interface JRBlockViewController () <UICollectionViewDataSource, UICollectionViewDelegate>

//// UICollectionView
@property (nonatomic, strong) UICollectionView	*collectionView;
/// layout
@property (nonatomic, strong) UICollectionViewFlowLayout	*layout;

@property (nonatomic, strong) NSArray	*list;

@end

@implementation JRBlockViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [UIColor whiteColor];
	
	[self setupUI];
}

#pragma mark - Setup UI
/// 设置 UI
- (void)setupUI {
	
	///
	self.collectionView = ({
		
		UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds
															  collectionViewLayout:self.layout];
		collectionView.delegate			 = self;
		collectionView.dataSource		 = self;
		collectionView.backgroundColor   = [UIColor charcoalColor];
		collectionView.collectionViewLayout		= self.layout;
		collectionView.allowsMultipleSelection	= YES;
		[collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:@"item"];
		[self.view addSubview:collectionView];
		collectionView;
	});
}

#pragma mark - UICollectionViewDataSource
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return 3;
}
/// cell
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return 6;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"item"
																		   forIndexPath:indexPath];
	
	cell.backgroundColor = [UIColor cz_randomColor];
	
	return cell;
}


#pragma mark - UICollectionViewDelegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
	NSLog(@"cell-被点击/选中 %@", indexPath);

	UICollectionViewCell *cell = [collectionView cellForItemAtIndexPath:indexPath];
	cell.backgroundColor = [UIColor blackColor];
}

#pragma mark <UICollectionViewDelegate>

// ----------------------------------------------------------- cell 点击操作
/// Cell是否可以高亮
- (BOOL)collectionView: (UICollectionView *)collectionView
shouldHighlightItemAtIndexPath: (NSIndexPath *)indexPath{
	return YES;
}

/// 如果Cell可以高亮，Cell变为高亮后调用该方法
- (void)collectionView: (UICollectionView *)collectionView
didHighlightItemAtIndexPath: (NSIndexPath *)indexPath {
	NSLog(@"cell-变为高亮 %@", indexPath);
}

/// 如果Cell可以高亮，Cell从高亮变为非高亮调用该方法
- (void)collectionView: (UICollectionView *)collectionView
didUnhighlightItemAtIndexPath: (NSIndexPath *)indexPath {
	NSLog(@"cell-变为非高亮 %@", indexPath);
}

// ----------------------------------------------------------- cell 选中操作
/// Cell是否可以选中
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath{
	return YES;
}

/// Cell多选时是否支持取消功能
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath{
	return YES;
}

/// Cell取消选中调用该方法
- (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath{
	NSLog(@"cell-被点击/取消选中 %@", indexPath);
	
	UICollectionViewCell *cell = [collectionView cellForItemAtIndexPath:indexPath];
	cell.backgroundColor = [UIColor whiteColor];
}


#pragma mark <UICollectionViewDelegateFlowLayout>
/// 改变Cell的尺寸
- (CGSize)collectionView: (UICollectionView *)collectionView
				  layout: (UICollectionViewLayout*)collectionViewLayout
  sizeForItemAtIndexPath: (NSIndexPath *)indexPath{
	
	CGFloat w = (SCREEN_W - 20) / 2;
	return CGSizeMake(w, 200);
	/// 测试代理
//	CGFloat heightOfCell = arc4random() % 100 + 30;
//	return CGSizeMake(heightOfCell, heightOfCell);
}

/// Section的上下左右边距--UIEdgeInsetsMake(上, 左, 下, 右);逆时针
- (UIEdgeInsets)collectionView: (UICollectionView *)collectionView
						layout: (UICollectionViewLayout*)collectionViewLayout
		insetForSectionAtIndex: (NSInteger)section{
	
	return UIEdgeInsetsMake(20, 0, 20, 0);
}

/// Section中每个Cell的上下边距
- (CGFloat)collectionView: (UICollectionView *)collectionView
				   layout: (UICollectionViewLayout*)collectionViewLayout
minimumLineSpacingForSectionAtIndex: (NSInteger)section{
	
	return 10.0f * (section + 1);
}

#pragma mark - Getter Methond
- (UICollectionViewFlowLayout *)layout {
	
	if (_layout) {
		return _layout;
	}
	
	CGFloat w = (SCREEN_W - 20) / 2;
	_layout = [[UICollectionViewFlowLayout alloc] init];
	_layout.itemSize				= CGSizeMake(w, 200);
	_layout.minimumLineSpacing		= 10;
	_layout.minimumInteritemSpacing = 20;

	return _layout;
}


#pragma mark -
///
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	[self.list bk_each:^(id obj) {
		NSLog(@"--- %@",obj);
	}];
}
///
- (NSArray *)list {
	
	if (_list) {
		return _list;
	}
	
	_list = @[@"aaa",
			  @"ddd",
			  @"fff",
			  @"eee",
			  @"xxx",
			  @"vvv",
			  @"qqq",
			  @"yyy",
			  @"uuu",
			  @"iii",
			  @"ooo",
			  @"ppp",
			  @"kkk",
			  @"lll",
			  @"jjj",
			  @"mmm",];
	
	return _list;
}

@end
