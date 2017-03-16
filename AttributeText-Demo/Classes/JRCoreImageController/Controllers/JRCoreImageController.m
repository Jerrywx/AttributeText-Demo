//
//  JRCoreImageController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/23.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreImageController.h"
#import "UIView+YYAdd.h"
#import "JRMotionBlurController.h"

@interface JRCoreImageController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) YYLabel	*label;

/// UITableView
@property (nonatomic, strong) UITableView	*tableView;

@property (nonatomic, strong) NSArray<NSString *>	*imageList;

@end

@implementation JRCoreImageController

- (void)viewDidLoad {
    [super viewDidLoad];

	/// Setup UI
	[self setupView];
}

#pragma mark - Setup UI
- (void)setupView {

	/// 设置控制器
	self.title = @"Core Image";
	self.view.backgroundColor = [UIColor whiteColor];
	
	/// 添加 tableView
	[self.view addSubview:self.tableView];
	[self.tableView reloadData];
}

#pragma mark - UItableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return self.imageList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
	
	cell.textLabel.text = self.imageList[indexPath.row];
	
	return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	
	JRMotionBlurController *blurVC = [[JRMotionBlurController alloc] init];
	blurVC.title = self.imageList[indexPath.row];
	[self.navigationController pushViewController:blurVC animated:YES];
}

#pragma mark - Getter Methond
- (UITableView *)tableView {
	
	if (_tableView) {
		return _tableView;
	}
	
	_tableView = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds
											  style:UITableViewStyleGrouped];
	_tableView.dataSource	= self;
	_tableView.delegate		= self;
	_tableView.rowHeight	= 44;
	[_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
	return _tableView;
}

- (NSArray<NSString *> *)imageList {
	if (_imageList) {
		return _imageList;
	}
	
	_imageList = @[@"动态模糊"];
	
	return _imageList;
}

#pragma mark - Abandon
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

	NSAttributedString *aString = [self getAttributedString];
	self.label.height			= MAXFLOAT;
	self.label.numberOfLines	= 3;
	self.label.attributedText	= aString;

	CGSize size					= [self.label sizeThatFits:CGSizeMake(SCREEN_W - 40, 0)];
	self.label.size				= size;
	self.label.centerY			= 200;
//	NSLog(@"------- %f - %f = %zd", size.width, size.height, aString.string.length);
}
///
- (NSAttributedString *)getAttributedString {
	
	NSMutableAttributedString *aString = [NSMutableAttributedString new];
	UIFont *font = [UIFont systemFontOfSize:16];
	
	[aString appendAttributedString:[[NSAttributedString alloc] initWithString:@"Thasdax撒啊撒adfadfasdfasssasas fsdf d啊撒是fasdf sadString:" attributes:nil]];
	
	NSArray *names = @[@"冷笑", @"亲亲", @"吐舌头", @"委屈", @"笑哭", @"呵呵",@"冷笑", @"亲亲", @"吐舌头", @"委屈", @"笑哭", @"呵呵"];
	
//	for (NSString *name in names) {
//
//		UIImage *img   = [UIImage imageNamed:name];
//		NSData *data = UIImagePNGRepresentation(img);
//		YYImage *image	= [YYImage imageWithData:data scale:3];
//
//		NSMutableAttributedString *attachText
//			= [NSMutableAttributedString yy_attachmentStringWithContent:image
//															contentMode:UIViewContentModeCenter
//														 attachmentSize:CGSizeMake(21, 20)
//															alignToFont:font
//															  alignment:YYTextVerticalAlignmentCenter];
//		[aString appendAttributedString:attachText];
//	}
	
//	UIImage *image = [UIImage imageNamed:@"ggg"];
//	NSMutableAttributedString *attachText
//		= [NSMutableAttributedString yy_attachmentStringWithContent:image 
//														contentMode:UIViewContentModeScaleAspectFit
//													 attachmentSize:CGSizeMake(20, 20) 
//														alignToFont:font 
//														  alignment:YYTextVerticalAlignmentCenter];
//	[aString appendAttributedString:attachText];
	
	[aString appendAttributedString:[[NSAttributedString alloc] initWithString:@"\n" attributes:nil]];
	
	return aString;
}
////
- (void)demo1 {
	
	UIImage *image = [UIImage imageNamed:@"apple.jpg"];
	
	UIImage *img = [self compressOriginalImage:image toSize:CGSizeZero];
	
	NSString *path = [[NSBundle mainBundle] pathForResource:@"apple.jpg" ofType:nil];
	NSData *data = [NSData dataWithContentsOfFile:path];
	
	NSLog(@"=======asdas %zd", [data length]);
	UIImage * im = [[UIImage alloc] initWithData:data];
	
	NSLog(@"======= %zd", [UIImageJPEGRepresentation(image, 0.1) length]);
	NSLog(@"======= %zd", [UIImagePNGRepresentation(img) length]);
	
	NSLog(@"======= %zd", [UIImageJPEGRepresentation(image, 0.001) length]);
	image = [[UIImage alloc] initWithData:UIImageJPEGRepresentation(image, 0.001)];
	NSLog(@"======= %zd", [UIImageJPEGRepresentation(image, 0.001) length]);
	image = [[UIImage alloc] initWithData:UIImageJPEGRepresentation(image, 0.001)];
	NSLog(@"======= %zd", [UIImageJPEGRepresentation(image, 0.001) length]);
	
	
}
- (UIImage *)compressOriginalImage:(UIImage *)image toSize:(CGSize)size{
	
	CGSize ss = CGSizeMake(5, 5);
	
	UIImage * resultImage = image;
	UIGraphicsBeginImageContext(ss);
	[resultImage drawInRect:CGRectMake(0, 0, ss.width, ss.height)];
	resultImage = UIGraphicsGetImageFromCurrentImageContext();
	UIGraphicsEndImageContext();
	return resultImage;
}

@end
