//
//  JRThreadHeader.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/21.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRThreadHeader.h"

@interface JRThreadHeader ()

/// 帖子详情头部
@property (nonatomic, strong) UIView	*headerBar;
/// 帖子所在圈子标题
@property (nonatomic, strong) UILabel	*forumLabel;
/// 关注圈子按钮
@property (nonatomic, strong) UIButton	*forumFollowBtn;

/// 用户头像
@property (nonatomic, strong) JRUserHeader	*userHeader;
/// 用户昵称
@property (nonatomic, strong) YYLabel	*userName;
/// 发帖时间
@property (nonatomic, strong) UILabel	*timeLabel;
/// 帖子标题
@property (nonatomic, strong) YYLabel	*threadTitle;
/// 主题帖详细内容
@property (nonatomic, strong) YYLabel	*threadContent;

@end


@implementation JRThreadHeader

/// frame
static CGFloat margin		= 20;
static CGFloat margin2		= 10;
static CGFloat headerBarH	= 45;
static CGFloat followBtnW	= 55;
static CGFloat followBtnH	= 25;
static CGFloat userHeaderW	= 30;
static CGFloat userNameH	= 15;
static CGFloat timeLabelW	= 50;

- (instancetype)initWithFrame:(CGRect)frame {
	
	if (self = [super initWithFrame:frame]) {
		[self setupView];
	}
	return self;
}

- (void)setupView {
	
	// 0. 初始化
	self.backgroundColor = [UIColor whiteColor];

	// 1. headerBar
	self.headerBar = ({
		UIView *view		 = [[UIView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_W, 45)];
		view.backgroundColor = [UIColor colorWithRed:0.96f green:0.96f blue:0.96f alpha:1.00f];
		[self addSubview:view];
		view;
	});
	
	// 1.1 forumLabel
	self.forumLabel = ({
		CGFloat w		= SCREEN_W - margin * 3 - followBtnW;
		UILabel *label	= [[UILabel alloc] initWithFrame:CGRectMake(20, 0, w, headerBarH)];
		label.font		= kFontSize_14;
		label.textColor = [UIColor creamColor];
		[self.headerBar addSubview:label];
		label;
	});
	
	// 1.2 forumFollowBtn
	[self.headerBar addSubview:self.forumFollowBtn];
	
	// 2.1 userHeader
	self.userHeader = ({
		JRUserHeader *imgView = [[JRUserHeader alloc] initWithFrame:CGRectMake(margin,
													margin, userHeaderW, userHeaderW)];
		imgView.image = [UIImage imageNamed:@"userHeader"];
		[self addSubview:imgView];
		imgView;
	});
	
	// 2.2 userName
	self.userName = ({
		CGFloat userNmaeX = margin + userHeaderW + margin2;
		CGFloat userNameY = margin + (userHeaderW - userNameH) * 0.5;
		CGFloat userNameW = SCREEN_W - userNmaeX - margin - timeLabelW - margin2;
		YYLabel *label	  = [[YYLabel alloc] initWithFrame:CGRectMake(userNmaeX, userNameY, userNameW, userNameH)];
		label.font		  = kFontSize_12;
		[self addSubview:label];
		label;
	});
	
	// 2.3 timeLabel
	self.timeLabel = ({
		CGFloat timeLabelX = CGRectGetMaxX(self.userName.frame) + margin2;
		CGFloat timeLabelY = self.userName.frame.origin.y;
		UILabel *label	   = [[UILabel alloc] initWithFrame:CGRectMake(timeLabelX, timeLabelY, timeLabelX, userNameH)];
		label.font		   = kFontSize_10;
		label.textColor	   = [UIColor grayColor];
		[self addSubview:label];
		label;
	});
	
	// 2.4 threadTitle
	self.threadTitle = ({
		YYLabel *label = [[YYLabel alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
		
		[self addSubview:label];
		label;
	});
	
}

#pragma mark - Action Methond 
- (void)forumAct:(UIButton *)button {
	NSLog(@"======== forumAct");
}

#pragma mark - Lazy Loading
- (UIButton *)forumFollowBtn {
	
	if (_forumFollowBtn) {
		return _forumFollowBtn;
	}
	
	CGFloat followBtnX  = SCREEN_W - margin * 2 - followBtnW;
	_forumFollowBtn		= [[UIButton alloc] initWithFrame:CGRectMake(0, followBtnX, followBtnW, followBtnH)];
	[_forumFollowBtn addTarget:self action:@selector(forumAct:) forControlEvents:UIControlEventTouchUpInside];
	[_forumFollowBtn setTitle:@"加关注" forState:UIControlStateNormal];
	[_forumFollowBtn setTitle:@"已关注" forState:UIControlStateSelected];
	[_forumFollowBtn setBackgroundColor:[UIColor waveColor]];
	
	return _forumFollowBtn;
}

@end















