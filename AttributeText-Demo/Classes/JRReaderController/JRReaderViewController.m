//
//  JRReaderViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRReaderViewController.h"
#import "JRCollectionViewCell.h"
#import "JRCModel.h"

@interface JRReaderViewController () <UICollectionViewDataSource, UICollectionViewDelegate>

/// 内容 UICollectionView
@property (nonatomic, strong) UICollectionView	*collectionView;
/// UICollectionView 布局
@property (nonatomic, strong) UICollectionViewFlowLayout *layout;

@property (nonatomic, strong) NSArray	*models;

@end

@implementation JRReaderViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
//	self.extendedLayoutIncludesOpaqueBars = YES;
	self.automaticallyAdjustsScrollViewInsets = NO;
	
	
	/// 数据
	self.models = [self makeWithContent:[self loadData]];
	
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
	return self.models.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
	
	JRCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"item"
																		   forIndexPath:indexPath];
	
	cell.backgroundColor = [UIColor cz_randomColor];
	
	cell.model = self.models[indexPath.row];
	
	return cell;
}

#pragma mark - 加载数据
- (NSString *)loadData {
	NSURL *url			= [[NSBundle mainBundle] URLForResource:@"wkz" withExtension:@"txt"];
	NSString *content	= [NSString stringWithContentsOfURL:url encoding:0x80000632 error:nil];
	return content;
}

///
- (NSArray *)makeWithContent:(NSString *)content {

	/// 页字典
	NSMutableArray *mArrays = [NSMutableArray array];
	
	/// 创建属性字符串
	NSDictionary *a = @{NSFontAttributeName : [UIFont systemFontOfSize:18]};
	NSMutableAttributedString *maString = [[NSMutableAttributedString alloc] initWithString:content attributes:a];
	
	///
	CTFramesetterRef	frameSetter;
	frameSetter = CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef) maString);
	CGRect bounds = CGRectMake(0, 0, SCREEN_W, SCREEN_H - 80);
	CGPathRef path = CGPathCreateWithRect(bounds, NULL);

	///
	int currentOffset		= 0;
	int currentInnerOffset	= 0;
	BOOL hasMorePages		= YES;
	NSInteger pageNumb		= 1;
	while (hasMorePages) {
		CTFrameRef frame = CTFramesetterCreateFrame(frameSetter,
													CFRangeMake(currentInnerOffset, 0),
													path, NULL);
		CFRange range = CTFrameGetVisibleStringRange(frame);
//		NSLog(@"----- %ld - %ld", range.location, range.length);
		
		if (range.location + range.length < content.length) {
			
			currentOffset += range.length;
			currentInnerOffset += range.length;
			
			JRCModel *model = [[JRCModel alloc] init];
			model.length	= range.length;
			NSRange rag		= NSMakeRange(range.location, range.length);
			model.string	= [content substringWithRange:rag];
			model.content	= [maString attributedSubstringFromRange:rag];
			model.range		= rag;
			model.pageNumb	= pageNumb++;
			[mArrays addObject:model];
		} else {
			hasMorePages = NO;
		}
	}
	
	CGPathRelease(path);
	CFRelease(frameSetter);
	
//	NSLog(@"%@", mArrays);
	return mArrays;
	
	
	
	///////////////////////////////
//	NSMutableArray *mArray = [NSMutableArray array];
//	NSArray *cc = [content componentsSeparatedByString:@"\n"];
//	for (NSString *c in cc) {
//		if ([c stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]].length > 0) {
//			[mArray addObject:c];
//			NSLog(@"%zd - %@",c.length ,c);
//		}
//	}
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
//	_layout.scrollDirection			= UICollectionViewScrollDirectionHorizontal;
	_layout.scrollDirection			= UICollectionViewScrollDirectionHorizontal;
	
	return _layout;
}

@end












