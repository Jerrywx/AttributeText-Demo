//
//  JRReaderViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRReaderViewController.h"
#import "JRCollectionViewCell.h"

@interface JRReaderViewController () <UICollectionViewDataSource, UICollectionViewDelegate>

/// 内容 UICollectionView
@property (nonatomic, strong) UICollectionView	*collectionView;
/// UICollectionView 布局
@property (nonatomic, strong) UICollectionViewFlowLayout *layout;

@end

@implementation JRReaderViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
//	self.extendedLayoutIncludesOpaqueBars = YES;
	self.automaticallyAdjustsScrollViewInsets = NO;
	
	[self setupUI];
}

- (void)setupUI {
	
	/// 设置背景色
	self.view.backgroundColor = [UIColor whiteColor];
	
	/// 添加点击手势
	UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self
																		  action:@selector(tapAct)];
	[self.view addGestureRecognizer:tap];
	
	/// 创建 UICollectionView
	self.collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds
											 collectionViewLayout:self.layout];
	[self.collectionView registerClass:[JRCollectionViewCell class]
			forCellWithReuseIdentifier:@"item"];
	self.collectionView.dataSource = self;
	self.collectionView.delegate   = self;
	self.collectionView.pagingEnabled = YES;
	[self.view addSubview:self.collectionView];

	self.collectionView.backgroundColor = [UIColor orangeColor];
}

- (void)tapAct {

	[self.navigationController setNavigationBarHidden:!self.navigationController.navigationBarHidden 
											 animated:YES];
	
	[[UIApplication sharedApplication] setStatusBarHidden:self.navigationController.navigationBarHidden
											withAnimation:UIStatusBarAnimationSlide];
}

#pragma mark - UICollectionViewDataSource, UICollectionViewDelegate

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return 20;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	JRCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"item"
																		   forIndexPath:indexPath];
	
	if (indexPath.row % 2 == 1) {
		cell.backgroundColor = [UIColor redColor];
	} else {
		cell.backgroundColor = [UIColor yellowColor];
	}
	return cell;
}

#pragma mark - 懒加载

- (UICollectionViewFlowLayout *)layout {
	
	if (_layout) {
		return _layout;
	}
	
	_layout = [[UICollectionViewFlowLayout alloc] init];
	_layout.itemSize				= self.view.bounds.size;
	_layout.minimumLineSpacing		= 0;
	_layout.minimumInteritemSpacing = 0;
	_layout.scrollDirection			= UICollectionViewScrollDirectionHorizontal;
	
	return _layout;
}

@end
