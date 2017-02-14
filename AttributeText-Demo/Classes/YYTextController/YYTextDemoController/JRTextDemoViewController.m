//
//  JRTextDemoViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/14.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRTextDemoViewController.h"

@interface JRTextDemoViewController ()

@property (nonatomic, strong) YYLabel	*label;

@end

@implementation JRTextDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupUI];
	
}

/// 初始化界面
- (void)setupUI {
	
	self.view.backgroundColor = [UIColor whiteColor];

	self.label = [[YYLabel alloc] initWithFrame:CGRectMake(20, 80, 400, 200)];
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:@"TEST"];
	[aString yy_setFont:[UIFont systemFontOfSize:38] range:NSMakeRange(0, aString.length)];
	
	// 设置阴影
	YYTextShadow *shadow = [[YYTextShadow alloc] init];
	shadow.color = [UIColor redColor];
	shadow.offset = CGSizeMake(10, 10);
//	[aString yy_setTextShadow:shadow range:NSMakeRange(0, aString.length)];
	
	// 装饰
	YYTextDecoration *dec = [[YYTextDecoration alloc] init];
	dec.style = YYTextLineStyleThick;
	dec.width = [NSNumber numberWithInt:2];
	dec.color = [UIColor redColor];
//	[aString setYy_textUnderline:dec];
	
	// 边框
	YYTextBorder *border = [[YYTextBorder alloc] init];
	border.lineStyle = YYTextLineStylePatternCircleDot;
	border.strokeColor = [UIColor redColor];
	border.strokeWidth = 1;
	border.insets = UIEdgeInsetsMake(1, 1, 1, 1);
	[aString yy_setTextBorder:border range:NSMakeRange(0, aString.length)];
	
	self.label.attributedText = aString;
	[self.view addSubview:self.label];
	self.label.backgroundColor = [UIColor yellowColor];
	
}

@end
