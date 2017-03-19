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
		collectionView.delegate		= self;
		collectionView.dataSource	= self;
		collectionView.backgroundColor = [UIColor charcoalColor];
		[collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:@"item"];
		[self.view addSubview:collectionView];
		collectionView;
	});
}

#pragma mark - UICollectionViewDataSource
///
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return 20;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"item"
																		   forIndexPath:indexPath];
	
	cell.backgroundColor = [UIColor cz_randomColor];
	
	return cell;
}

#pragma mark - UICollectionViewDelegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
	
	NSLog(@"%@", indexPath);
	NSLog(@"%@", collectionView.collectionViewLayout);
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
