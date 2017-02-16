//
//  JRCollectionViewCell.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCollectionViewCell.h"

@interface JRCollectionViewCell ()

@property (nonatomic, strong) UIView	*headerView;
@property (nonatomic, strong) UIView	*footerView;
@property (nonatomic, strong) YYLabel	*contentLabel;

@end

@implementation JRCollectionViewCell

- (instancetype)initWithFrame:(CGRect)frame {
	self = [super initWithFrame:frame];
	NSLog(@"%@", NSStringFromCGRect(frame));
	[self setupUI];
	return self;
}

- (void)setupUI {
	
	CGFloat width	= [UIScreen mainScreen].bounds.size.width;
	CGFloat h		= [UIScreen mainScreen].bounds.size.height;
	CGFloat height	= 40;//[UIScreen mainScreen].bounds.size.height;
	
	self.headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, width, height)];
	self.headerView.backgroundColor = [UIColor cz_randomColor];
	
	self.footerView = [[UIView alloc] initWithFrame:CGRectMake(0, h - height, width, height)];
	self.footerView.backgroundColor = [UIColor cz_randomColor];
	
	[self.contentView addSubview:self.headerView];
	[self.contentView addSubview:self.footerView];
}


@end
