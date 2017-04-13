//
//  JRSimpleView.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/6.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpleView.h"

@implementation JRSimpleView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	CGContextRef context = UIGraphicsGetCurrentContext();
	[self drawRect:rect context:context];
}

///
- (void)drawRect:(CGRect)rect context:(CGContextRef)context {
	
	// 1. 获取图形上下文
//	CGContextRef context = UIGraphicsGetCurrentContext();
 
	// 2. 翻转坐标系
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
	// 3. 设置坐标系
	CGContextSetTextMatrix(context, CGAffineTransformIdentity);
	
	// 4. 创建路径
	CGMutablePathRef path = CGPathCreateMutable();
	// 5. 绘制一个矩形
	CGRect bounds = CGRectMake(0.0, 0.0, rect.size.width, rect.size.height);
	CGPathAddRect(path, NULL, bounds );
	
	
	// 6. 创建 CFStringRef 字符串
	CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.Sometimes I write one, and I look a是啊啊撒是按时按时啊是按时 as ");
 
	///
	CFMutableAttributedStringRef attrString =
	CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);
 
	// Copy the textString into the newly created attrString
	CFAttributedStringReplaceString (attrString, CFRangeMake(0, 0),
									 textString);
	
	// 创建颜色属性设置给字符串
	CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
	CGFloat components[] = { 1.0, 0.0, 0.0, 0.8 };
	CGColorRef red = CGColorCreate(rgbColorSpace, components);
	CGColorSpaceRelease(rgbColorSpace);
 
	// Set the color of the first 12 chars to red.
	// 设置前12 个字符的颜色属性
	CFAttributedStringSetAttribute(attrString, CFRangeMake(0, 12),
								   kCTForegroundColorAttributeName, red);
 
	
	
	// Create the framesetter with the attributed string.
	CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
	CFRelease(attrString);
 
	// Create a frame.
	CTFrameRef frame = CTFramesetterCreateFrame(framesetter,
												CFRangeMake(0, 0), path, NULL);
 
	/// 设置渲染字体
	CGFontRef cgFont = CGFontCreateWithFontName((CFStringRef)[UIFont boldSystemFontOfSize:20].fontName);
	CGContextSetFont(context, cgFont);
	
	/// 绘制 Frame
//	CTFrameDraw(frame, context);
 
	////////////////////////////////////////////////////////////////////////////
	// 获取 CFLineRef 数组
	CFArrayRef lines = CTFrameGetLines(frame);
	NSLog(@"---- %zd", CFArrayGetCount(lines));
	
	/// 获取属性
//	CFDictionaryRef dic = CTFrameGetFrameAttributes(frame);
	/// 获取可视范围
//	CFRange range = CTFrameGetVisibleStringRange(frame);
	
	// 获取最后一个 CFLineRef
	CTLineRef lastVisibleLine = CFArrayGetValueAtIndex(lines, CFArrayGetCount(lines) - 1);
	// 获取最后一个 CFLineRef 的 CFRange
	CFRange rangeToLayout = CTLineGetStringRange(lastVisibleLine);
//	NSLog(@"CFRange: %zd   %zd - %zd", CFArrayGetCount(lines),
//		  rangeToLayout.location, rangeToLayout.length);
	// 获取 CGSize
	CGSize constraints	 = CGSizeMake(SCREEN_W - 40, MAXFLOAT);
	CFRange rangeToSize  = CFRangeMake(0, rangeToLayout.location + rangeToLayout.length);
	CGSize suggestedSize = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, rangeToSize, NULL, constraints, NULL);
//	NSLog(@"CGSize: %f - %f", suggestedSize.width, suggestedSize.height);
	
	// 获取每个 CTLineRef 的 CGPoint
	CGPoint lineOrigins[CFArrayGetCount(lines)];
	CTFrameGetLineOrigins(frame, CFRangeMake(0, 0), lineOrigins);
	for (int i=0; i<CFArrayGetCount(lines); i++) {
		

		CTLineRef line = CFArrayGetValueAtIndex(lines, i);
		CGFloat lineAscent;
		CGFloat lineDescent;
		CGFloat lineLeading;
		CTLineGetTypographicBounds(line, &lineAscent, &lineDescent, &lineLeading);

		
		///
		double x = CTLineGetPenOffsetForFlush(line, 0.0, SCREEN_W - 40);
//		double w = CTLineGetTrailingWhitespaceWidth(line);
		
		/// 绘制 Line
		CGPoint p = lineOrigins[i];
		CGContextSetTextPosition(context, p.x + x, p.y);
//		CTLineDraw(line, context);

		/// 获取 line 中 run 数量
//		CFArrayRef runs = CTLineGetGlyphRuns(line);
		/// 获取 line 中 文本数量
//		CFIndex cc = CTLineGetGlyphCount(line);
		/// 获取 line 的文本显示范围
//		CFRange range = CTLineGetStringRange(line);

		
		CFArrayRef runs = CTLineGetGlyphRuns(line);
		for (int j = 0; j < CFArrayGetCount(runs); j++) {
			CTRunRef run = CFArrayGetValueAtIndex(runs, j);
			// run的属性字典
//			NSDictionary* attributes = (NSDictionary*)CTRunGetAttributes(run);
//			
//			CGFloat runAscent;
//			CGFloat runDescent;
//			CGFloat runWidth  = CTRunGetTypographicBounds(run, CFRangeMake(0,0), &runAscent, &runDescent, NULL);
//			NSLog(@"-------d %f - %f - %f", runAscent, runDescent, runWidth);
			
			/// ---
			CTRunDraw(run, context, CFRangeMake(0, 0));
			CFIndex count = CTRunGetGlyphCount(run);
			///
			CGPoint components[count];
			CTRunGetPositions(run, CFRangeMake(0, 0), components);
			///
			CGSize sizes[count];
			CTRunGetAdvances(run, CFRangeMake(0, 0), sizes);
			
			CFIndex indexs[count];
			CTRunGetStringIndices(run, CFRangeMake(0, 0), indexs);
			
			NSLog(@"============================ %zd", count);
			for (int i=0; i<count; i++) {
//				CGPoint p = components[i];
//				NSLog(@"--- %f - %f", p.x, p.y);
				
//				CGSize size = sizes[i];
//				NSLog(@"--- %f - %f", size.width, size.height);
				NSLog(@"---- %zd", indexs[i]);
			}
			
		}
	}
	
	// Release the objects we used.
	CFRelease(frame);
	CFRelease(path);
	CFRelease(framesetter);
	
}


@end
