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

	self.label = [YYLabel new];
	self.label.textVerticalAlignment = YYTextVerticalAlignmentTop;
	self.label.size		= CGSizeMake(SCREEN_W - 40, MAXFLOAT);
	self.label.centerX	= SCREEN_W * 0.5;
	self.label.centerY	= 200;
	self.label.font		= [UIFont systemFontOfSize:18];

	NSString *string = @"http://m.zongheng.com/h5/book?bookid=635757《绝品邪帝》来访求各位朋友们眼熟！！";
	
	NSAttributedString *aString = [NSAttributedString attributedString:string 
															 textColor:[UIColor grayColor] 
															  textFont:[UIFont systemFontOfSize:16] 
														 textLineSpace:6];
//	self.label.attributedText	= aString;
	self.label.text				= string;
	self.label.numberOfLines	= 0;
	CGSize size					= [self.label sizeThatFits:CGSizeMake(SCREEN_W - 40, 0)];
	self.label.size				= size;
	self.label.centerY			= 200;
	self.label.backgroundColor	= [UIColor orangeColor];
	[self.view addSubview:self.label];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {

//	NSAttributedString *aString = [self getAttributedString];
//	self.label.height			= MAXFLOAT;
//	self.label.numberOfLines	= 3;
//	self.label.attributedText	= aString;
//
//	CGSize size					= [self.label sizeThatFits:CGSizeMake(SCREEN_W - 40, 0)];
//	self.label.size				= size;
//	self.label.centerY			= 200;
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
