//
//  JRCoreImageController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/23.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreImageController.h"
#import "UIView+YYAdd.h"

@interface JRCoreImageController ()

@property (nonatomic, strong) YYLabel	*label;
@end

@implementation JRCoreImageController

- (void)viewDidLoad {
    [super viewDidLoad];

	[self setupView];
}

- (void)setupView {

	self.title = @"Core Image";
	self.view.backgroundColor = [UIColor whiteColor];
//
//	///
	self.label = [YYLabel new];
	self.label.textVerticalAlignment = YYTextVerticalAlignmentTop;
//	self.label.frame = CGRectMake(20, 100, SCREEN_W - 40, 4);
	self.label.size = CGSizeMake(SCREEN_W - 40, 110);
//	self.label.center = CGPointMake(SCREEN_W / 2, SCREEN_H / 2 - 0);
	self.label.centerX = SCREEN_W * 0.5;
	self.label.centerY = 200;
	self.label.text = @"我们在绘制图像前操作CTM来旋转、缩放或平移page,从而变换我们将要绘制的对象。以变换CTM之前，我们需要保存图形状态，以便绘制后能恢复。我们同样能用仿射矩阵来联结CTM。在本节中，我们将介绍与CTM函数相关的四种操作--平移、旋转、缩放和联结。";

	[self.view addSubview:self.label];
	self.label.numberOfLines = 2;
	CGSize size		= [self.label sizeThatFits:CGSizeMake(SCREEN_W - 40, 0)];
	self.label.size = size;
	self.label.backgroundColor = [UIColor orangeColor];
	
	
	
	NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"uartz 2D 绘制模型定义了两种独立的坐标空间：用户空间(用于表现文档页)和设备空间(用于表现设备的本地分辨率)。用户坐标空间用浮点数表示坐标，与设备空间的像素分辨率没有关系。当我们需要一个点或者显示文档时"];

	_label = [YYLabel new];
	_label.textVerticalAlignment = YYTextVerticalAlignmentTop;
	_label.size = CGSizeMake(260, 260);
	_label.center = CGPointMake(SCREEN_W / 2, SCREEN_H / 2 - 0);
	[self.view addSubview:_label];
	_label.attributedText	= text;
	_label.numberOfLines	= 2;
	size = [_label sizeThatFits:CGSizeMake(260, 0)];
	_label.size = size;
	_label.backgroundColor = [UIColor orangeColor];
	
//	[self demo1];
}

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
