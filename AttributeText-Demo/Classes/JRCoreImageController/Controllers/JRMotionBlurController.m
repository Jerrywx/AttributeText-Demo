//
//  JRMotionBlurController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRMotionBlurController.h"

@interface JRMotionBlurController ()

///
@property (nonatomic, strong) UIImageView *imageView;
///
@property (nonatomic, strong) UIImageView *imageViewBlur;
///
@property (nonatomic, strong) CIFilter	*filter;
///
@property (nonatomic, strong) CIContext *context;

@end

@implementation JRMotionBlurController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupUI];
}

///
- (void)setupUI {

	CGFloat w = (SCREEN_W - 60) / 2;
	
	/// imageView
	self.imageView					= [[UIImageView alloc] initWithFrame:CGRectMake(20, 80, w, w)];
	self.imageView.image			= [UIImage imageNamed:@"img1"];
	[self.view addSubview:self.imageView];
	
	/// imageViewBlur
	self.imageViewBlur					= [[UIImageView alloc] initWithFrame:CGRectMake(w + 40, 80, w, w)];
	self.imageViewBlur.image			= [self outputImageWithFilterName:@"CIMotionBlur"];
	[self.view addSubview:self.imageViewBlur];
}

///
- (UIImage *)outputImageWithFilterName:(NSString *)filterName {
	
	// 1. 将UIImage转换成CIImage
	CIImage *ciImage = [[CIImage alloc] initWithImage:self.imageView.image];
	
	// 2. 创建滤镜
	self.filter = [CIFilter filterWithName:filterName keysAndValues:kCIInputImageKey, ciImage, nil];
	// 设置相关参数
	[self.filter setValue:@(10.f) forKey:@"inputRadius"];
	
	// 3. 渲染并输出CIImage
	CIImage *outputImage = [self.filter outputImage];
	
	// 4. 获取绘制上下文
	self.context = [CIContext contextWithOptions:nil];
	
	// 5. 创建输出CGImage
	CGImageRef cgImage = [self.context createCGImage:outputImage fromRect:[outputImage extent]];
	UIImage *image = [UIImage imageWithCGImage:cgImage];
	// 6. 释放CGImage
	CGImageRelease(cgImage);
	
	return image;
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

	/// 创建 CIImage
//	[self createAnCIImage];
	/// 获取滤镜列表
	[self getAllFilters];
}

/// Creating an CIImage
- (void)createAnCIImage {
	
	/*
	 UIImage *image = [UIImage imageNamed:@"imageName"];
	 image.CIImage == nil;
	 如果:
		UIImage *newImage = [[UIImage alloc] initWithCIImage:ciImage];
		newImage.CIImage != nil;
	 */
	UIImage *image = [UIImage imageNamed:@"img1"];
	
	NSLog(@"image: %@", image);
	NSLog(@"ciimage: %@", image.CIImage);
	
	NSLog(@"===================");
	
	CIImage *ciImage = [[CIImage alloc] initWithImage:image];
	UIImage *newImage = [[UIImage alloc] initWithCIImage:ciImage];
	NSLog(@"ciImage: %@", ciImage);
	NSLog(@"newImage: %@", newImage);
	NSLog(@"cc %@", newImage.CIImage);
}
/// 获取系统支持的滤镜
- (void)getAllFilters {
	
	NSArray *filterNames=[CIFilter filterNamesInCategory:kCICategoryBuiltIn];
	
	NSLog(@"滤镜数量: %zd", filterNames.count);
	for (NSString *filterName in filterNames) {
		CIFilter *filter=[CIFilter filterWithName:filterName];
		NSLog(@"\r滤镜: %@\r属性: %@",filterName,[filter attributes]);
	}
	
}


@end



