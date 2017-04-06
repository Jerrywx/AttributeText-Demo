//
//  JRSimpCollectionController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/26.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpCollectionController.h"

@interface JRSimpCollectionController () <UICollectionViewDataSource, UICollectionViewDelegate>

/// layout
@property (nonatomic, strong) UICollectionViewFlowLayout	*layout;
///
@property (nonatomic, strong) UICollectionView	*collectionView;

@end

@implementation JRSimpCollectionController

static NSString * const reuseIdentifier = @"Cell";

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupUI];
}

///
- (void)setupUI {
	self.view.backgroundColor = [UIColor whiteColor];
	
	self.collectionView = ({
		UICollectionView *colView = [[UICollectionView alloc] initWithFrame:self.view.bounds
													   collectionViewLayout:self.layout];
		colView.delegate	= self;
		colView.dataSource	= self;
		[colView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:reuseIdentifier];
		[self.view addSubview:colView];
		colView;
	});
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
