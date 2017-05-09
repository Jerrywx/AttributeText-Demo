//
//  JRSimpCollectionController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/26.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpCollectionController.h"
#import "JRCollectionViewCell2.h"

@interface JRSimpCollectionController () <UICollectionViewDataSource, UICollectionViewDelegate>

/// layout
@property (nonatomic, strong) UICollectionViewFlowLayout	*layout;
///
@property (nonatomic, strong) UICollectionView	*collectionView;

@property (nonatomic, strong) NSMutableArray	*dataSource;

@property (nonatomic, assign) NSInteger	section;

@property (nonatomic, assign) CGFloat	lastOffset;

@property (nonatomic, assign) BOOL		dri;

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
	self.automaticallyAdjustsScrollViewInsets = NO;
	
	self.section = -1;
	
	self.collectionView = ({
		UICollectionView *colView = [[UICollectionView alloc] initWithFrame:CGRectMake(0, 64, SCREEN_W, SCREEN_H - 64)
													   collectionViewLayout:self.layout];
		colView.delegate	= self;
		colView.dataSource	= self;
		colView.backgroundColor = [UIColor whiteColor];
		colView.pagingEnabled = YES;
		[colView registerClass:[JRCollectionViewCell2 class] forCellWithReuseIdentifier:reuseIdentifier];
		[self.view addSubview:colView];
		colView;
	});
	
	UIBarButtonItem *r = [[UIBarButtonItem alloc] initWithTitle:@"YY" style:UIBarButtonItemStylePlain target:self action:@selector(test2)];
	self.navigationItem.rightBarButtonItem = r;
	
}

- (void)test2 {
	NSLog(@"=============TTT");
	[self.collectionView scrollToItemAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:8] 
								atScrollPosition:UICollectionViewScrollPositionCenteredHorizontally
										animated:NO];
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
	return self.dataSource.count;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
	return [self.dataSource[section] count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	JRCollectionViewCell2 *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier
																		   forIndexPath:indexPath];
	
	cell.backgroundColor = [UIColor cz_randomColor];
	
	NSArray *a = self.dataSource[indexPath.section];
	cell.con = a[indexPath.row];
	
	return cell;
}

#pragma mark - UICollectionViewDelegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
	NSLog(@"== %@", indexPath);
}

- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath {
	
//	if (self.section == indexPath.section) {
//		
//		NSInteger c = indexPath.section + 2;
//		c = c * c;
//		NSMutableArray *mm = [NSMutableArray arrayWithCapacity:c];
//		
//		for (int i=0; i<c; i++) {
//			NSString *s =[NSString stringWithFormat:@"%zd - %zd", indexPath.section, i];
//			[mm addObject:s];
//		}
//		
//		self.dataSource[indexPath.section] = mm;
//	}
//	self.section = indexPath.section;
//	[self.collectionView reloadData];
}

- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset {
	
//	NSLog(@"==== %@", scrollView);
	
}
- (void)setDri:(BOOL)dri {
	if (_dri != dri) {
		_dri = dri;
		
		if (dri) {
//			NSLog(@"-----右");
		} else {
//			NSLog(@"=====左");
		}
	}
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
	
	if (scrollView.contentOffset.x - self.lastOffset > 0) {
//		NSLog(@"-----右");
		self.dri = YES;
	} else {
//		NSLog(@"=====左");
		self.dri = NO;
	}
	
	
	
	
	self.lastOffset = scrollView.contentOffset.x;
	
	
	
	CGPoint point = CGPointMake(scrollView.contentOffset.x - SCREEN_W, scrollView.contentOffset.y);
	NSIndexPath *indexPath = [self.collectionView indexPathForItemAtPoint:point];
//	NSLog(@"--- %@", indexPath);
	
	
	if (self.section != indexPath.section) {
//		NSLog(@"asasas %zd - %zd", self.section, indexPath.section);
		NSInteger c = indexPath.section + 1;
		c = 5;
		NSMutableArray *mm = [NSMutableArray arrayWithCapacity:c];
		NSString *ss = self.dataSource[indexPath.section][0];
		for (int i=0; i<c; i++) {
			NSString *s =[NSString stringWithFormat:@"%@ - %zd", ss, i];
			[mm addObject:s];
		}
		
		self.dataSource[indexPath.section] = mm;
		
		self.section = indexPath.section;
		//	[self.collectionView reloadData];
		[self.collectionView reloadSections:[NSIndexSet indexSetWithIndex:indexPath.section]];
		[self.collectionView performSelector:@selector(reloadSections:) 
								  withObject:[NSIndexSet indexSetWithIndex:indexPath.section] 
								  afterDelay:0 
									 inModes:@[NSRunLoopCommonModes]];
		
		[self performSelector:@selector(test) withObject:nil afterDelay:0 inModes:@[NSRunLoopCommonModes]];
	}
	self.section = indexPath.section;
	//	[self.collectionView reloadData];
//	[self.collectionView reloadSections:[NSIndexSet indexSetWithIndex:indexPath.section]];
	
}

- (void)test {
	NSLog(@"asdasdasda");
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView {
	
	
//	NSIndexPath *indexPath = [self.collectionView indexPathForItemAtPoint:scrollView.contentOffset];
//	
//	NSLog(@"asasas %@", NSStringFromCGPoint(scrollView.contentOffset));
//	
//	if (self.section != indexPath.section) {
//		
//		NSInteger c = indexPath.section + 2;
//		c = c * c;
//		NSMutableArray *mm = [NSMutableArray arrayWithCapacity:c];
//		
//		for (int i=0; i<c; i++) {
//			NSString *s =[NSString stringWithFormat:@"%zd - %zd", indexPath.section, i];
//			[mm addObject:s];
//		}
//		
//		self.dataSource[indexPath.section] = mm;
//	}
//	self.section = indexPath.section;
////	[self.collectionView reloadData];
//	[self.collectionView reloadSections:[NSIndexSet indexSetWithIndex:indexPath.section]];

}


#pragma mark - Getter Methond
- (UICollectionViewFlowLayout *)layout {
	
	if (_layout) {
		return _layout;
	}
	
	CGFloat w = (SCREEN_W - 20) / 2;
	_layout = [[UICollectionViewFlowLayout alloc] init];
	_layout.itemSize				= CGSizeMake(SCREEN_W, SCREEN_H - 64);//self.view.bounds.size;//CGSizeMake(w, w);
	_layout.minimumLineSpacing		= 0;
	_layout.minimumInteritemSpacing = 0;
	_layout.scrollDirection			= UICollectionViewScrollDirectionHorizontal;
	
	return _layout;
}

- (NSMutableArray *)dataSource {
	
	if (_dataSource) {
		return _dataSource;
	}
	
//	_dataSource = @[@[@"A1", @"A2", @"A3", @"A4", @"A5", @"A6", @"A7", @"A8"],
//					@[@"B1", @"B2", @"B3"],
//					@[@"C1"],
//					@[@"E1", @"E2", @"E1", @"E2"],
//					@[@"F1", @"F2"],
//					@[@"G1", @"G2",@"G3"],
//					@[@"H1", @"H2"],
//					@[@"I1", @"I2"],
//					@[@"J1", @"J2", @"J1", @"J2"],
//					@[@"K1", @"K2"],].mutableCopy;
	_dataSource = @[@[@"A1"],
					@[@"B1"],
					@[@"C1"],
					@[@"E1"],
					@[@"F1"],
					@[@"G1"],
					@[@"H1"],
					@[@"I1"],
					@[@"J1"],
					@[@"K1"],].mutableCopy;
	
	
	return _dataSource;
}

@end
