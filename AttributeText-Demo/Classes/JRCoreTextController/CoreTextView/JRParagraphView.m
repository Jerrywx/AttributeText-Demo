//
//  JRParagraphView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/26.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRParagraphView.h"

@implementation JRParagraphView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	// 1. 获取图形上下文
	CGContextRef context = UIGraphicsGetCurrentContext();
 
	// 2. 饭庄坐标系
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
 
	// Initializing a graphic context in OS X is different:
	// CGContextRef context =
	//     (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
	
	// 3. 设置坐标系
	CGContextSetTextMatrix(context, CGAffineTransformIdentity);
	// 4. 创建路径
	CGMutablePathRef path = CGPathCreateMutable();
	// 5. 绘制一个矩形
	CGRect bounds = CGRectMake(0.0, 0.0, 200.0, 200.0);
	CGPathAddRect(path, NULL, bounds );
	// 6. 创建 CFStringRef 字符串
	CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
 
	// Create a mutable attributed string with a max length of 0.
	// The max length is a hint as to how much internal storage to reserve.
	// 0 means no hint.
	CFMutableAttributedStringRef attrString =
	CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);
 
	// Copy the textString into the newly created attrString
	CFAttributedStringReplaceString (attrString, CFRangeMake(0, 0),
									 textString);
	
	// 创建颜色属性设置给字符串
	CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
	CGFloat components[] = { 0.0, 0.0, 1.0, 0.8 };
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
 
	// Draw the specified frame in the given context.
	CTFrameDraw(frame, context);
 
	// Release the objects we used.
	CFRelease(frame);
	CFRelease(path);
	CFRelease(framesetter);

	
}


@end
