//
//  ZHFProgressHUD.h
//  ZHCircle
//
//  Created by 王潇 on 16/11/11.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, JRProgressAlignment) {
	JRProgressAlignmentTop		=   0,	///< Top alignment.
	JRProgressAlignmentCenter	=	1,	///< Center alignment.
	JRProgressAlignmentBottom	=	2,	///< Bottom alignment.
};

@class MBProgressHUD;
@interface ZHFProgressHUD : NSObject

#pragma mark - 普通Loading
/// 菊花
+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view;

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view animated:(BOOL)animated;

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view animated:(BOOL)animated hideAll:(BOOL)hide;

/// 停止 Loading
+ (void)hideHUDForView:(UIView *)view;

+ (void)hideHUDForView:(UIView *)view animated:(BOOL)animated;

#pragma mark - Loading + Label
/// 菊花 + Label
+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string;

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string
						 animated:(BOOL)animated;

+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view
							title:(NSString *)string
						 animated:(BOOL)animated
						  hideAll:(BOOL)hide;

#pragma mark - Toast

/**
 在 keyWindow 上显示 Toast

 @param message 提示文本
 @return MBProgressHUD 对象
 */
+ (MBProgressHUD *)showToastToWindow:(NSString *)message;

/**
 在 keyWindow 上添加 Toast
 
 @param message 显示文本
 @return MBProgressHUD 对象
 */
+ (MBProgressHUD *)showToastAddToWindow:(NSString *)message;

/**
 在指定view 上显示 Toast

 @param view 显示提示信息的View
 @param message 提示文本
 @return MBProgressHUD 对象
 */
+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message;

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment;

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment
					afterDelay:(NSTimeInterval)delay;

+ (MBProgressHUD *)showToastTo:(UIView *)view
					   message:(NSString *)message
					 alignment:(JRProgressAlignment)alignment
					afterDelay:(NSTimeInterval)delay
					   hideAll:(BOOL)hide;

@end
