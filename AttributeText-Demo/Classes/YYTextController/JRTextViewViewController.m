//
//  JRTextViewViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRTextViewViewController.h"

@interface JRTextViewViewController ()

///
@property (nonatomic, strong) UILabel	*label;

@end

@implementation JRTextViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [UIColor whiteColor];
	
	/// 普通字符串
	{
		NSString *string = @"这是一个测试字符串...... ！！！！！！用于文本排版 计算文本的高度";
		NSAttributedString *aString = [[NSAttributedString alloc] initWithString:string];
		
		self.label					= [[UILabel alloc] init];
		self.label.frame			= CGRectMake(20, 100, SCREEN_W - 40, 0);
		self.label.numberOfLines	= 0;
		self.label.attributedText	= aString;
//		self.label.text				= string;
		[self.label sizeToFit];
		self.label.backgroundColor	= [UIColor lightGrayColor];
		[self.view addSubview:self.label];
		
		CGSize size = [self.label sizeThatFits:CGSizeMake(SCREEN_W - 40, MAXFLOAT)];
		
		CGRect frame = self.label.frame;
		frame.size.height = size.height;
		self.label.frame = frame;
		
		
		/// YYTextLayout
//		YYTextLayout *laytout = [YYTextLayout layoutWithContainerSize:CGSizeMake(SCREEN_W - 40, MAXFLOAT)
//																 text:self.label.attributedText];
//		self.label.frame = CGRectMake(20, 100, SCREEN_W - 40, laytout.textBoundingSize.height);
//		
//		NSLog(@"---- %@", self.label.textLayout);
//		NSLog(@"==== %f", self.label.frame.size.height);
		
	}
	
	/// 属性字符串
	{
	
	}
}

@end
