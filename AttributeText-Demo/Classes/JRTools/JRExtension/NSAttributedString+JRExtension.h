//
//  NSAttributedString+JRExtension.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSAttributedString (JRExtension)

+ (NSAttributedString *)attributedString:(NSString *)textString
							   textColor:(UIColor *)textColor
								textFont:(UIFont *)textFont
						   textLineSpace:(CGFloat)lineSpace;


/// 字符串和图片拼接
+ (NSAttributedString *)getNickName:(NSString *)nickName
							  image:(UIImage *)image
							  color:(UIColor *)color
							   font:(UIFont *)font
							 margin:(CGFloat)margin
						  imageMode:(UIViewContentMode)imageMode
						   isHeader:(BOOL)isHeader;

/// 字符串和图片拼接
+ (NSAttributedString *)attributedString:(NSAttributedString *)aString
								  append:(UIImage *)image
								isHeader:(BOOL)isHeader
									font:(UIFont *)font
								  margin:(CGFloat)margin
							   imageMode:(UIViewContentMode)imageMode;

@end
