//
//  JRViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRViewController.h"

@interface JRViewController ()
/// 状态栏背景色
@property (nonatomic, strong) UIView	*statusView;
/// 导航栏背景色
@property (nonatomic, strong) UIView	*navgationView;
/// 返回按钮
@property (nonatomic, strong) JRButton	*leftButton;
/// 标题
@property (nonatomic, strong) JRButton	*titleButton;
/// 右侧按钮
@property (nonatomic, strong) JRButton	*rightButton;

@end

@implementation JRViewController

- (void)viewDidLoad {
    [super viewDidLoad];

	[self initlizeNavigation];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	self.navigationController.navigationBar.alpha = 0;
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	self.navigationController.navigationBar.alpha = 1;
}

#pragma mark - Initlize UI
- (void)initlizeNavigation {
	
	// 1. 状态栏
	self.statusView = ({
		UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_W, STATUS_H)];
		view.backgroundColor = [UIColor waveColor];
		[self.view insertSubview:view atIndex:self.view.subviews.count];
		view;
	});
	
	// 2. 导航栏
	self.navgationView = ({
		UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, STATUS_H, SCREEN_W, NAVIGA_H)];
		view.backgroundColor = [UIColor waveColor];
		[self.view addSubview:view];
		view;
	});
	
	// 3. leftButton
	self.leftButton = ({
		JRButton *button		= [[JRButton alloc] initWithFrame:CGRectMake(12, 0, 60, NAVIGA_H)];
		button.backgroundColor	= [UIColor infoBlueColor];
		[button addTarget:self
				   action:@selector(leftButtonAct:) 
		 forControlEvents:UIControlEventTouchUpInside];
		[self.navgationView addSubview:button];
		button;
	});
	
	// 4. titleButton
	self.titleButton = ({
		CGFloat w = SCREEN_W - 200;
		JRButton *button		= [[JRButton alloc] initWithFrame:CGRectMake(100, 0, w, NAVIGA_H)];
		button.backgroundColor	= [UIColor infoBlueColor];
		[button addTarget:self
				   action:@selector(titleButtonAct:)
		 forControlEvents:UIControlEventTouchUpInside];
		[self.navgationView addSubview:button];
		button;
	});
	
	// 5. rightButton
	self.rightButton = ({
		CGFloat x = SCREEN_W - 72;
		JRButton *button		= [[JRButton alloc] initWithFrame:CGRectMake(x, 0, 60, NAVIGA_H)];
		button.backgroundColor	= [UIColor infoBlueColor];
		[button addTarget:self
				   action:@selector(rightButtonAct:)
		 forControlEvents:UIControlEventTouchUpInside];
		[self.navgationView addSubview:button];
		button;
	});
}

#pragma mark - Action Methond
- (void)leftButtonAct:(UIButton *)button {
	[self.navigationController popViewControllerAnimated:YES];
}

- (void)titleButtonAct:(UIButton *)button {
	
}

- (void)rightButtonAct:(UIButton *)button {
	
}

@end















