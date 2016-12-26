//
//  JRCoreImageController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/23.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreImageController.h"

@interface JRCoreImageController ()

@end

@implementation JRCoreImageController

- (void)viewDidLoad {
    [super viewDidLoad];

	[self setupView];
}

- (void)setupView {
	
	self.title = @"Core Image";
	self.view.backgroundColor = [UIColor whiteColor];
	
	[self demo1];
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
