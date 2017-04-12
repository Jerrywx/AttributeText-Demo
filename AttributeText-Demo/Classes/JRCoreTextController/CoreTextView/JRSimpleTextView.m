//
//  JRSimpleTextView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpleTextView.h"

@implementation JRSimpleTextView

- (void)drawRect:(CGRect)rect {
	
	///
	CFStringRef string; CTFontRef font; CGContextRef context;
	
	/// 创建 CFStringRef
	string = CFSTR("Where are you：这个设。CA");
	
	/// 创建 CTFontRef
	font = CTFontCreateWithName((CFStringRef)[UIFont boldSystemFontOfSize:14].fontName, 24, NULL);
	/// 获取上下文
	context = UIGraphicsGetCurrentContext();
	
	/// 翻转坐标系
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
	
	/// 创建属性字典
	
	CFStringRef keys[] = { kCTFontAttributeName, kCTForegroundColorAttributeName, kCTBackgroundColorAttributeName };
	CFTypeRef values[] = { font , [UIColor redColor].CGColor, [UIColor orangeColor].CGColor};
	CFDictionaryRef attributes = CFDictionaryCreate(kCFAllocatorDefault,
													(const void**)&keys,
													(const void**)&values,
													sizeof(keys) / sizeof(keys[0]),
													&kCFTypeDictionaryKeyCallBacks,
													&kCFTypeDictionaryValueCallBacks);
 
	/// 创建属性字符串
	CFAttributedStringRef attrString =
	CFAttributedStringCreate(kCFAllocatorDefault, string, attributes);

	/// 释放xxx
	CFRelease(string);
	CFRelease(attributes);
 
	/// 创建 CTLineRef
	CTLineRef line = CTLineCreateWithAttributedString(attrString);
//	line = CTLineCreateTruncatedLine(line, 15, kCTLineTruncationEnd, line);
	
	/// \u2026 是 Unicode编码 ...
//	NSAttributedString *truncatedString = [[NSAttributedString alloc] initWithString:@"\u2026\u2026"];
//	CTLineRef token = CTLineCreateWithAttributedString((__bridge CFAttributedStringRef)truncatedString);
//	
////	CTLineTruncationType ltt = kCTLineTruncationStart;
////	CTLineTruncationType ltt = kCTLineTruncationMiddle;
//	CTLineTruncationType ltt = kCTLineTruncationEnd;
//	line = CTLineCreateTruncatedLine(line, self.bounds.size.width, ltt, token);
 
	/// 设置绘制点
	CGContextSetTextPosition(context, 0.0, 10.0);
	/// 设置绘制模式
//	CGContextSetTextDrawingMode(context, kCGTextStrokeClip);		// 空心 英文
//	CGContextSetTextDrawingMode(context, kCGTextStroke);			// 空心 英文 & 汉字
//	CGContextSetTextDrawingMode(context, kCGTextFillStroke);		// 粗体 英文 & 汉字
//	CGContextSetTextDrawingMode(context, kCGTextInvisible);			// 隐藏 英文 & 汉字
//	CGContextSetTextDrawingMode(context, kCGTextFillClip);			// 正常 英文
//	CGContextSetTextDrawingMode(context, kCGTextFillStrokeClip);	//
//	CGContextSetTextDrawingMode(context, kCGTextClip);				//
	/// 设置字体 不起作用
//	CGFontRef cgFont = CGFontCreateWithFontName((CFStringRef)[UIFont boldSystemFontOfSize:20].fontName);
//	CGContextSetFont(context, cgFont);

	////
//	CFIndex index = CTLineGetGlyphCount(line);
//	NSLog(@"===== %zd", index);
	
	////
//	CGRect re = CTLineGetBoundsWithOptions(line, kCTLineBoundsIncludeLanguageExtents);
//	NSLog(@"=== %@", NSStringFromCGRect(re));
	
	////
	CFRange range = CTLineGetStringRange(line);
//	NSLog(@"------ %ld - %ld", range.location, range.length);
	
	////
	double width =  CTLineGetTrailingWhitespaceWidth(line);
//	NSLog(@"===== %f", width);
	
	////
	CGFloat leading, ascent, descent, offset, offset2;
	
	offset	= CTLineGetOffsetForStringIndex(line, range.location, NULL);
	offset2 = CTLineGetOffsetForStringIndex(line, range.length, NULL);
//	NSLog(@"===== %f - %f", offset, offset2);
	CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
//	NSLog(@"------ %f - %f - %f", ascent, descent, leading);
	
	////
	
	CFMutableAttributedStringRef attriString = CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);
 
	// Copy the textString into the newly created attrString
	CFAttributedStringReplaceString (attriString, CFRangeMake(0, 0),
									 string);
	
	CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(
									(CFAttributedStringRef)attriString);
	CFRange rangeToSize = CFRangeMake(0, [@"Where are you：这个设。CA" length]);
	CGSize constraints = CGSizeMake(SCREEN_W - 40, MAXFLOAT);
	CGSize suggestedSize = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, rangeToSize, NULL, constraints, NULL);
	NSLog(@"========= %f - %f", suggestedSize.width, suggestedSize.height);
	
	/// 绘制
	CTLineDraw(line, context);
	/// 释放
	CFRelease(line);
}


@end
