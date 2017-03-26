//
//  JRSimpCollectionController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/26.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpCollectionController.h"

@interface JRSimpCollectionController ()

/// layout
@property (nonatomic, strong) UICollectionViewFlowLayout	*layout;

@end

@implementation JRSimpCollectionController

static NSString * const reuseIdentifier = @"Cell";

- (instancetype)init {
	return [super initWithCollectionViewLayout:self.layout];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations
    // self.clearsSelectionOnViewWillAppear = NO;
	
	self.collectionView.collectionViewLayout = self.layout;
    // Register cell classes
    [self.collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:reuseIdentifier];
	
	self.collectionView.remembersLastFocusedIndexPath = YES;
	self.view.backgroundColor = [UIColor whiteColor];
}

#pragma mark <UICollectionViewDataSource>
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return 20;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    
	cell.backgroundColor = [UIColor cz_randomColor];
	
    return cell;
}

#pragma mark <UICollectionViewDelegate>

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
	NSLog(@"======= c: %@", indexPath);
	
}

/*
// Uncomment this method to specify if the specified item should be highlighted during tracking
- (BOOL)collectionView:(UICollectionView *)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath {
	return YES;
}
*/

/*
// Uncomment this method to specify if the specified item should be selected
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    return YES;
}
*/

/*
// Uncomment these methods to specify if an action menu should be displayed for the specified item, and react to actions performed on the item
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath {
	return NO;
}

- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender {
	return NO;
}

- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(id)sender {
	
}
*/

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
