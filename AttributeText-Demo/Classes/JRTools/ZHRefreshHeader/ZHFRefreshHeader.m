//
//  ZHFRefreshHeader.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/3/23.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "ZHFRefreshHeader.h"

@implementation ZHFRefreshHeader

- (void)prepare {
	[super prepare];
	
	// 设置普通状态的动画图片
	NSArray *idleImages = @[[UIImage imageNamed:@"ZHShop_refresh_1"]];
	[self setImages:idleImages forState:MJRefreshStateIdle];
	
	// 设置即将刷新状态的动画图片（一松开就会刷新的状态）
	NSMutableArray *refreshingImages = [NSMutableArray array];
	for (NSUInteger i = 1; i<=3; i++) {
		UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"dropdown_loading_0%zd", i]];
		[refreshingImages addObject:image];
	}
	//    [self setImages:refreshingImages forState:MJRefreshStatePulling];
	
	// 设置正在刷新状态的动画图片
	[self setImages:refreshingImages forState:MJRefreshStateRefreshing];
}

@end
