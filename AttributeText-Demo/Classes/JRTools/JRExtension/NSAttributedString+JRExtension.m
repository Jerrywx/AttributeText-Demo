//
//  NSAttributedString+JRExtension.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "NSAttributedString+JRExtension.h"

@implementation NSAttributedString (JRExtension)

+ (NSAttributedString *)attributedString:(NSString *)textString
							   textColor:(UIColor *)textColor
								textFont:(UIFont *)textFont
						   textLineSpace:(CGFloat)lineSpace {
	
	// 判断字符串合法性
	if (![textString isKindOfClass:[NSString class]] || textString.length == 0) {
		textString = @"";
	}
	
	// 段落
	NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc]init];
	// 行间距
	paragraphStyle.lineSpacing				= lineSpace;
	// 换行方式
	paragraphStyle.lineBreakMode			= NSLineBreakByCharWrapping;
	// 格式
	NSDictionary *textAttributes = @{
									 NSFontAttributeName			: textFont,
									 NSParagraphStyleAttributeName	: paragraphStyle,
									 NSForegroundColorAttributeName	: textColor
									 };
	// 格式化字符串
	NSMutableAttributedString *attribute = [[NSMutableAttributedString alloc] initWithString:textString
																				  attributes:textAttributes];
	// 返回属性字符串
	return attribute;
}

/// 字符串和图片拼接
+ (NSAttributedString *)getNickName:(NSString *)nickName
							  image:(UIImage *)image
							  color:(UIColor *)color
							   font:(UIFont *)font
							 margin:(CGFloat)margin
						  imageMode:(UIViewContentMode)imageMode
						   isHeader:(BOOL)isHeader {
	
	// 昵称转换为属性字符串
	NSAttributedString *aNickName = [NSAttributedString attributedString:nickName 
															   textColor:color 
																textFont:font 
														   textLineSpace:0];
	
	// 拼接图片
	NSAttributedString *aString = [NSAttributedString attributedString:aNickName
																append:image
															  isHeader:isHeader
																  font:font
																margin:margin
															 imageMode:imageMode];
	// 返回标题属性字符串
	return aString;
}

/// 字符串和图片拼接
+ (NSAttributedString *)attributedString:(NSAttributedString *)aString
								  append:(UIImage *)image
								isHeader:(BOOL)isHeader
									font:(UIFont *)font
								  margin:(CGFloat)margin
							   imageMode:(UIViewContentMode)imageMode {
	
	// 1.
	NSMutableAttributedString *mutableAttributedString = [NSMutableAttributedString new];
	NSMutableAttributedString *attachText = [NSMutableAttributedString new];
	// 2.
	if (image) {
		NSData *data = UIImagePNGRepresentation(image);
		YYImage *img = [YYImage imageWithData:data scale:2];
		img.preloadAllAnimatedImageFrames = YES;
		YYAnimatedImageView *imageView = [[YYAnimatedImageView alloc] initWithImage:img];
		
		CGSize imageSize = CGSizeMake(imageView.frame.size.width + margin, imageView.frame.size.height);
		attachText = [NSMutableAttributedString yy_attachmentStringWithContent:imageView
																contentMode:imageMode
																attachmentSize:imageSize
																alignToFont:font
																	 alignment:YYTextVerticalAlignmentCenter];
	}
	
	if (isHeader) {
		[mutableAttributedString appendAttributedString:attachText];
		[mutableAttributedString appendAttributedString:aString];
	} else {
		[mutableAttributedString appendAttributedString:aString];
		[mutableAttributedString appendAttributedString:attachText];
	}
	
	return mutableAttributedString;
}

@end
