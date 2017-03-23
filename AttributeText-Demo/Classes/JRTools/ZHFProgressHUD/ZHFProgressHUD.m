//
//  ZHFProgressHUD.m
//  ZHCircle
//
//  Created by 王潇 on 16/11/11.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "ZHFProgressHUD.h"
#import <MBProgressHUD.h>

@implementation ZHFProgressHUD

#pragma mark - 普通Loading
/// 开始Loading
+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view {
	return [ZHFProgressHUD showHUDAddedTo:view
								animated:YES
								 hideAll:YES];
}

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view animated:(BOOL)animated {
	return [ZHFProgressHUD showHUDAddedTo:view
								animated:animated
								 hideAll:YES];
}

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view animated:(BOOL)animated hideAll:(BOOL)hide {
	if (hide) [self hideHUDForView:view];
	MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view
											  animated:animated];
	
	hud.mode = MBProgressHUDModeCustomView;
	hud.customView = [ZHFProgressHUD customLoading];
	hud.bezelView.color = [UIColor clearColor];
	hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;

	hud.userInteractionEnabled = NO;
	return hud;
}

#pragma mark - 停止 Loading
/// 停止 Loading
+ (void)hideHUDForView:(UIView *)view {
	[self hideHUDForView:view animated:YES];
}

+ (void)hideHUDForView:(UIView *)view animated:(BOOL)animated {
	[MBProgressHUD hideHUDForView:view
						 animated:animated];
}

#pragma mark - Loading + Label
/// 开始显示
+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string {
	
	return [self showHUDAddedTo:view
						  title:string
					   animated:YES
						hideAll:YES];
}

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string
						 animated:(BOOL)animated {
	
	return [self showHUDAddedTo:view
						  title:string
					   animated:animated
						hideAll:YES];
}


+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string
						 animated:(BOOL)animated
						  hideAll:(BOOL)hide {
	
	if (hide) [self hideHUDForView:view];
	MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view
											  animated:animated];
	hud.userInteractionEnabled = NO;
	hud.label.text = string;
	return hud;
}

#pragma mark - Toast
/// 在 keyWindow 上显示 Toast
+ (MBProgressHUD *)showToastToWindow:(NSString *)message {
	
	return [ZHFProgressHUD showToastTo:[UIApplication sharedApplication].keyWindow
							   message:message
							 alignment:JRProgressAlignmentCenter
							afterDelay:1.5f
							   hideAll:YES];
}

/// 在 keyWindow 上显示 Toast
+ (MBProgressHUD *)showToastAddToWindow:(NSString *)message {
	
	return [ZHFProgressHUD showToastTo:[UIApplication sharedApplication].keyWindow
							   message:message
							 alignment:JRProgressAlignmentCenter
							afterDelay:1.5f
							   hideAll:NO];
}

/// 在置顶View 上显示 Toast
+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message {
	
	return [ZHFProgressHUD showToastTo:view
							  message:message
							alignment:JRProgressAlignmentCenter
						   afterDelay:1.5f
							  hideAll:YES];
}

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment {
	
	return [ZHFProgressHUD showToastTo:view
							  message:message
							alignment:alignment
						   afterDelay:1.5f
							  hideAll:YES];
}

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment
					afterDelay:(NSTimeInterval)delay {
	
	return [ZHFProgressHUD showToastTo:view
							   message:message
							 alignment:alignment
							afterDelay:delay
							   hideAll:YES];
}

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment
					   hideAll:(BOOL)hide {
	
	return [ZHFProgressHUD showToastTo:view
							  message:message
							alignment:alignment
						   afterDelay:1.5f
							  hideAll:hide];
}

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment
					afterDelay:(NSTimeInterval)delay
					   hideAll:(BOOL)hide {
	
	if (message.length == 0) {
		return nil;
	}
	
	if (hide) [self hideHUDForView:view];
	MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:view
											  animated:YES];
	
	hud.userInteractionEnabled = NO;
	hud.mode = MBProgressHUDModeText;
	hud.label.text = message;
	
	switch (alignment) {
		case JRProgressAlignmentTop:
			hud.offset = CGPointMake(0.f, -[UIScreen mainScreen].bounds.size.width * 0.5);
			break;
			
		case JRProgressAlignmentCenter:
			break;
			
		case JRProgressAlignmentBottom:
			hud.offset = CGPointMake(0.f, MBProgressMaxOffset);
			break;
			
		default:
			break;
	}
	[hud hideAnimated:YES afterDelay:delay];
	return hud;
}

#pragma mark - 获取自定义 Loading
+ (UIView *)customLoading {
	
	CGRect frame = CGRectMake(0, 0, 55, 55);
	
	UIImageView *loading = [[UIImageView alloc] initWithFrame:frame];
	loading.image = [UIImage imageNamed:@"ZHShop_loading_bac"];

	YYAnimatedImageView *img  = [[YYAnimatedImageView alloc] initWithFrame:frame];
	img.image = [YYImage imageNamed:@"ZHShop_loading.gif"];
	[loading addSubview:img];
	
	return loading;
}


@end
