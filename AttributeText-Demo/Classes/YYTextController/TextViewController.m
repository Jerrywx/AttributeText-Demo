//
//  TextViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/19.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "TextViewController.h"

@interface TextViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) YYLabel		*label;
@property (nonatomic, strong) UITableView	*tableView;
@end

@implementation TextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupView];
}

- (void)setupView {
	
	[self demo2];
	
	//
	self.view.backgroundColor = [UIColor whiteColor];
	
	//
	self.tableView = ({
		UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds
															  style:UITableViewStyleGrouped];
		tableView.delegate		= self;
		tableView.dataSource	= self;
		tableView.tableHeaderView = self.label;
		[tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"ccc"];
		[self.view addSubview:tableView];
		tableView;
	});
	
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
		[self downLoadImage];
	});
}

#pragma mark -
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ccc"];
	
	cell.textLabel.text = @"asdasdasdas";
	
	return cell;
}

#pragma mark -
- (void)demo2 {
	self.label = [YYLabel new];
	
	self.label.numberOfLines = 0;
	
	NSMutableAttributedString *text = [NSMutableAttributedString new];
	UIFont *font = [UIFont systemFontOfSize:16];
	
	[text appendAttributedString:[[NSAttributedString alloc] initWithString:@"This is a String:" attributes:nil]];
	
	NSArray *names = @[@"冷笑", @"亲亲", @"吐舌头", @"委屈", @"笑哭", @"呵呵"];
	
	for (NSString *name in names) {
		UIImage *image = [UIImage imageNamed:name];
		NSMutableAttributedString *attachText = [NSMutableAttributedString yy_attachmentStringWithContent:image contentMode:UIViewContentModeCenter attachmentSize:image.size alignToFont:font alignment:YYTextVerticalAlignmentCenter];
		[text appendAttributedString:attachText];
	}
	
	UIImage *image = [UIImage imageNamed:@"ggg"];
	NSMutableAttributedString *attachText = [NSMutableAttributedString yy_attachmentStringWithContent:image contentMode:UIViewContentModeScaleAspectFit attachmentSize:CGSizeMake(40, 40) alignToFont:font alignment:YYTextVerticalAlignmentCenter];
	[text appendAttributedString:attachText];
	
	[text appendAttributedString:[[NSAttributedString alloc] initWithString:@"\n" attributes:nil]];
	
	UIImage *imag = [UIImage imageNamed:@"ppp"];
	NSMutableAttributedString *attachText2 = [NSMutableAttributedString yy_attachmentStringWithContent:imag contentMode:UIViewContentModeScaleAspectFit attachmentSize:CGSizeMake(200, 200) alignToFont:font alignment:YYTextVerticalAlignmentCenter];
	[text appendAttributedString:attachText2];
	
	[text appendAttributedString:[[NSAttributedString alloc] initWithString:@"\n" attributes:nil]];
//	[text appendAttributedString:[[NSAttributedString alloc] initWithString:@"\n" attributes:nil]];
	
	UIImage *img = [UIImage imageNamed:@"ppp"];
	NSMutableAttributedString *attachText3 = [NSMutableAttributedString yy_attachmentStringWithContent:img contentMode:UIViewContentModeScaleAspectFit attachmentSize:CGSizeMake(200, 200) alignToFont:font alignment:YYTextVerticalAlignmentCenter];
	[text appendAttributedString:attachText3];
	
	
	self.label.attributedText = text;
	self.label.backgroundColor = [UIColor lightGrayColor];
	
	//	self.label.frame = CGRectMake(10, 100, 300, 100);
	[self.label sizeToFit];
	self.label.center = CGPointMake(200, 200);
//	[self.view addSubview:self.label];
	
	self.label.textTapAction = ^(UIView *containerView, NSAttributedString *text, NSRange range, CGRect rect) {
		NSLog(@"==== %@", NSStringFromRange(range));
		NSLog(@"---- %@", NSStringFromCGRect(rect));
	};
	
	self.label.numberOfLines = 0;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	[self downLoadImage];
}

- (void)downLoadImage {
	
//	http://static.zongheng.com/upload/bbs/30/68/3068ac54f34f2de01a2b9ef38ad3ae98.jpeg
	NSURL *url = [NSURL URLWithString:@"http://static.zongheng.com/upload/bbs/30/68/3068ac54f34f2de01a2b9ef38ad3ae98.jpeg"];
	[[SDWebImageManager sharedManager] downloadImageWithURL:url 
													options:SDWebImageRetryFailed
												   progress:nil 
												  completed:^(UIImage *image,
															  NSError *error, 
															  SDImageCacheType cacheType, 
															  BOOL finished, 
															  NSURL *imageURL) {
													  NSRange range = NSMakeRange(25, 1);
													  UIFont *font = [UIFont systemFontOfSize:16];
													  
//													  self.label.attributedText
													  
													  CGFloat w = 200;
													  CGFloat h = w/(image.size.width / image.size.height);
													  
													  
		NSLog(@"------------=== %@", NSStringFromCGSize(image.size));
	    NSMutableAttributedString *mAtt = [self.label.attributedText mutableCopy];
		NSMutableAttributedString *attachText = [NSMutableAttributedString yy_attachmentStringWithContent:image contentMode:UIViewContentModeScaleAspectFit attachmentSize:CGSizeMake(w, h + 20) alignToFont:font alignment:YYTextVerticalAlignmentCenter];
//		mAtt replaceCharactersInRange:range withString:<#(nonnull NSString *)#>
		[mAtt replaceCharactersInRange:range withAttributedString:attachText];
													  self.label.attributedText = mAtt;
		
													  
													  [self.label sizeToFit];
		self.tableView.tableHeaderView = self.label;
		NSLog(@"=================sssss %@", NSStringFromCGRect(self.label.frame));
	}];
	
}

#pragma mark -

/// YYLabel 设置普通文本
- (void)yylabelDemo1 {
	//	self.label = [[YYLabel alloc] initWithFrame:CGRectMake(40, 100, 350, 200)];
	self.label = [YYLabel new];
	self.label.backgroundColor = [UIColor lightGrayColor];
	self.label.text = @"This is a Label";
	[self.label sizeToFit];
	
	self.label.center = CGPointMake(200, 200);
	
	[self.view addSubview:self.label];
}

@end
