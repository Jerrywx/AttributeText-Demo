//
//  JRFMDBController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRFMDBController.h"

@interface JRFMDBController ()

/// 创建表按钮
@property (nonatomic, strong) UIButton *createBtn;

/// 插入数据
@property (nonatomic, strong) UIButton	*insertData;

/// 查询数据
@property (nonatomic, strong) UIButton	*searchData;

@end

@implementation JRFMDBController


- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [UIColor wheatColor];
	
	CGFloat w = SCREEN_W / 4;
	
	////
	self.createBtn = [self createButton:@"创建表"];
	self.createBtn.center = CGPointMake(w, 100);
	[self.createBtn addTarget:self action:@selector(createAct) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.insertData = [self createButton:@"插入数据"];
	self.insertData.center = CGPointMake(SCREEN_W - w, 100);
	[self.insertData addTarget:self action:@selector(insertAct) forControlEvents:UIControlEventTouchUpInside];
}

#pragma mark - SqLite Methond
/// 创建表
- (void)createAct {
	NSLog(@"---createAct");
}
/// 插入数据
- (void)insertAct {
	NSLog(@"--- insertAct");
}

#pragma mark - Private Methond
/// 创建按钮
- (UIButton *)createButton:(NSString *)title {
	UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 80, 30)];
	[button setTitle:title forState:UIControlStateNormal];
	[button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
	button.titleLabel.font		= kFontSize_14;
	button.layer.borderColor	= [UIColor charcoalColor].CGColor;
	button.layer.borderWidth	= 1;
	button.layer.cornerRadius	= 2;
	[self.view addSubview:button];
	return button;
}

@end
