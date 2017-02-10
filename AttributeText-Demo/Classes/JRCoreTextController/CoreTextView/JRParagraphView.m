//
//  JRParagraphView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/26.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRParagraphView.h"

@implementation JRParagraphView


- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	// Initialize a graphics context in iOS.
	CGContextRef context = UIGraphicsGetCurrentContext();
 
	// Flip the context coordinates, in iOS only.
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
 
	// Initializing a graphic context in OS X is different:
	// CGContextRef context =
	//     (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
 
	// Set the text matrix.
	CGContextSetTextMatrix(context, CGAffineTransformIdentity);
 
	// Create a path which bounds the area where you will be drawing text.
	// The path need not be rectangular.
	CGMutablePathRef path = CGPathCreateMutable();
 
	// In this simple example, initialize a rectangular path.
	CGRect bounds = CGRectMake(0.0, 0.0, rect.size.width, rect.size.height);
	CGPathAddRect(path, NULL, bounds );
 
	// Initialize a string.
	CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
 
	// Create a mutable attributed string with a max length of 0.
	// The max length is a hint as to how much internal storage to reserve.
	// 0 means no hint.
	CFMutableAttributedStringRef attrString =
	CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);
 
	// Copy the textString into the newly created attrString
	CFAttributedStringReplaceString (attrString, CFRangeMake(0, 0),
									 textString);
 
	// Create a color that will be added as an attribute to the attrString.
	CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
	CGFloat components[] = { 1.0, 0.0, 0.0, 0.8 };
	CGColorRef red = CGColorCreate(rgbColorSpace, components);
	CGColorSpaceRelease(rgbColorSpace);
 
	// Set the color of the first 12 chars to red.
	CFAttributedStringSetAttribute(attrString, CFRangeMake(0, 12),
								   kCTForegroundColorAttributeName, red);
 
	// Create the framesetter with the attributed string.
	CTFramesetterRef framesetter =
	CTFramesetterCreateWithAttributedString(attrString);
	CFRelease(attrString);
 
	// Create a frame.
	CTFrameRef frame = CTFramesetterCreateFrame(framesetter,
												CFRangeMake(0, 0), path, NULL);
 
	// Draw the specified frame in the given context.
	CTFrameDraw(frame, context);
 
	// Release the objects we used.
	CFRelease(frame);
	CFRelease(path);
	CFRelease(framesetter);

}

- (void)drawDemoRect:(CGRect)rect {
	// 1. 获取图形上下文
	CGContextRef context = UIGraphicsGetCurrentContext();
 
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
	CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.Sometimes I write one, and I look a是啊啊撒是按时按时啊是按时");
 
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
	CTFramesetterRef framesetter =
	CTFramesetterCreateWithAttributedString(attrString);
	CFRelease(attrString);
 
	// Create a frame.
	CTFrameRef frame = CTFramesetterCreateFrame(framesetter,
												CFRangeMake(0, 0), path, NULL);
 
	/// 设置渲染字体
	CGFontRef cgFont = CGFontCreateWithFontName((CFStringRef)[UIFont boldSystemFontOfSize:20].fontName);
	CGContextSetFont(context, cgFont);
	
	// Draw the specified frame in the given context.
	CTFrameDraw(frame, context);
 
	////////////////////////////////////////////////////////////////////////////
	// 获取 CFLineRef 数组
	CFArrayRef lines = CTFrameGetLines(frame);
	// 获取最后一个 CFLineRef
	CTLineRef lastVisibleLine = CFArrayGetValueAtIndex(lines, CFArrayGetCount(lines) - 1);
	// 获取最后一个 CFLineRef 的 CFRange
	CFRange rangeToLayout = CTLineGetStringRange(lastVisibleLine);
	NSLog(@"CFRange: %zd   %zd - %zd", CFArrayGetCount(lines),
		  rangeToLayout.location, rangeToLayout.length);
	// 获取 CGSize
	CGSize constraints	 = CGSizeMake(SCREEN_W - 40, MAXFLOAT);
	CFRange rangeToSize  = CFRangeMake(0, rangeToLayout.location + rangeToLayout.length);
	CGSize suggestedSize = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, rangeToSize, NULL, constraints, NULL);
	NSLog(@"CGSize: %f - %f", suggestedSize.width, suggestedSize.height);
	
	// 获取每个 CTLineRef 的 CGPoint
	CGPoint lineOrigins[CFArrayGetCount(lines)];
	CTFrameGetLineOrigins(frame, CFRangeMake(0, 0), lineOrigins);
	for (int i=0; i<CFArrayGetCount(lines); i++) {
		CGPoint p = lineOrigins[i];
		
		CTLineRef line = CFArrayGetValueAtIndex(lines, i);
		CGFloat lineAscent;
		CGFloat lineDescent;
		CGFloat lineLeading;
		CTLineGetTypographicBounds(line, &lineAscent, &lineDescent, &lineLeading);
		CFArrayRef runs = CTLineGetGlyphRuns(line);
		NSLog(@"point: %f - %f  %f %f %f --- %ld", p.x, p.y, lineAscent,
			  lineDescent, lineLeading, CFArrayGetCount(runs));
		
		for (int j = 0; j < CFArrayGetCount(runs); j++) {
			CTRunRef run = CFArrayGetValueAtIndex(runs, j);
			// run的属性字典
			NSDictionary* attributes = (NSDictionary*)CTRunGetAttributes(run);
			//			NSLog(@"-------d %@", attributes);
			CGFloat runAscent;
			CGFloat runDescent;
			CGFloat runWidth  = CTRunGetTypographicBounds(run, CFRangeMake(0,0), &runAscent, &runDescent, NULL);
			NSLog(@"-------d %f - %f - %f", runAscent, runDescent, runWidth);
		}
		
	}
	
	// Release the objects we used.
	CFRelease(frame);
	CFRelease(path);
	CFRelease(framesetter);
}


@end
