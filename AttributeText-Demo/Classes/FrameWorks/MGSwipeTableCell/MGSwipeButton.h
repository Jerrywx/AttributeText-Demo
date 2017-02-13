/*
 * MGSwipeTableCell is licensed under MIT license. See LICENSE.md file for more information.
 * Copyright (c) 2016 Imanol Fernandez @MortimerGoro
 */

#import <UIKit/UIKit.h>


@class MGSwipeTableCell;

/// 操作按钮
@interface MGSwipeButton : UIButton

/// 按钮回调
typedef BOOL(^ MGSwipeButtonCallback)(MGSwipeTableCell * _Nonnull cell);
@property (nonatomic, strong, nullable) MGSwipeButtonCallback callback;

/// 按钮宽度
@property (nonatomic, assign) CGFloat buttonWidth;

/** 
 * Convenience static constructors
 */

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color 
								padding:(NSInteger) padding;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color 
								 insets:(UIEdgeInsets) insets;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color 
							   callback:(nullable MGSwipeButtonCallback) callback;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color 
								padding:(NSInteger) padding 
							   callback:(nullable MGSwipeButtonCallback) callback;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
						backgroundColor:(nullable UIColor *) color 
								 insets:(UIEdgeInsets) insets 
							   callback:(nullable MGSwipeButtonCallback) callback;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color 
								padding:(NSInteger) padding;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color 
								 insets:(UIEdgeInsets) insets;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color 
							   callback:(nullable MGSwipeButtonCallback) callback;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color 
								padding:(NSInteger) padding
							   callback:(nullable MGSwipeButtonCallback) callback;

+(nonnull instancetype) buttonWithTitle:(nonnull NSString *) title 
								   icon:(nullable UIImage*) icon 
						backgroundColor:(nullable UIColor *) color 
								 insets:(UIEdgeInsets) insets 
							   callback:(nullable MGSwipeButtonCallback) callback;

-(void) setPadding:(CGFloat) padding;
-(void) setEdgeInsets:(UIEdgeInsets)insets;
-(void) centerIconOverText;
-(void) centerIconOverTextWithSpacing: (CGFloat) spacing;
-(void) iconTintColor:(nullable UIColor *)tintColor;

@end
