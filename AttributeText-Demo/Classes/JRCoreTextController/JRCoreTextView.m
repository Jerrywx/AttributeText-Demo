//
//  JRCoreTextView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/26.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreTextView.h"

@implementation JRCoreTextView


- (instancetype)initWithFrame:(CGRect)frame {
	self = [super initWithFrame:frame];
	return self;
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
//	[self SimpleTextLabel];
	
	CFStringRef string; CTFontRef font; CGContextRef context;
	
	string = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
	// 创建font
	font = CTFontCreateWithName((CFStringRef)[UIFont boldSystemFontOfSize:14].fontName, 24, NULL);
	context = UIGraphicsGetCurrentContext();
	
	// Initialize the string, font, and context
 
	CFStringRef keys[] = { kCTFontAttributeName };
	CFTypeRef values[] = { font };
 
	CFDictionaryRef attributes =
	CFDictionaryCreate(kCFAllocatorDefault, (const void**)&keys,
        (const void**)&values, sizeof(keys) / sizeof(keys[0]),
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks);
 
	CFAttributedStringRef attrString =
	CFAttributedStringCreate(kCFAllocatorDefault, string, attributes);
	
	
	
	// Initialize a graphics context in iOS.
//	CGContextRef context = UIGraphicsGetCurrentContext();
 
	// Flip the context coordinates in iOS only.
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
 
	// Initializing a graphic context in OS X is different:
	// CGContextRef context =
	//     (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
 
	// Set the text matrix.
	CGContextSetTextMatrix(context, CGAffineTransformIdentity);
 
	// Create the framesetter with the attributed string.
	CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(
																		   (CFAttributedStringRef)attrString);
 
	// Call createColumnsWithColumnCount function to create an array of
	// three paths (columns).
	CFArrayRef columnPaths = [self createColumnsWithColumnCount:3];
 
	CFIndex pathCount = CFArrayGetCount(columnPaths);
	CFIndex startIndex = 0;
	int column;
 
	// Create a frame for each column (path).
	for (column = 0; column < pathCount; column++) {
		// Get the path for this column.
		CGPathRef path = (CGPathRef)CFArrayGetValueAtIndex(columnPaths, column);
		
		// Create a frame for this column and draw it.
		CTFrameRef frame = CTFramesetterCreateFrame(
													framesetter, CFRangeMake(startIndex, 0), path, NULL);
		CTFrameDraw(frame, context);
		
		// Start the next frame at the first character not visible in this frame.
		CFRange frameRange = CTFrameGetVisibleStringRange(frame);
		startIndex += frameRange.length;
		CFRelease(frame);
		
	}
	CFRelease(columnPaths);
	CFRelease(framesetter);
	
}

// Laying Out a Paragraph
- (void)LayingOutaParagraph {
	
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

// Simple Text Label
- (void)SimpleTextLabel {
	CFStringRef string; CTFontRef font; CGContextRef context;
	
	string = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
	// 创建font
	font = CTFontCreateWithName((CFStringRef)[UIFont boldSystemFontOfSize:14].fontName, 24, NULL);
	context = UIGraphicsGetCurrentContext();
	
	// Initialize the string, font, and context
 
	CFStringRef keys[] = { kCTFontAttributeName };
	CFTypeRef values[] = { font };
 
	CFDictionaryRef attributes =
	CFDictionaryCreate(kCFAllocatorDefault, (const void**)&keys,
        (const void**)&values, sizeof(keys) / sizeof(keys[0]),
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks);
 
	CFAttributedStringRef attrString =
	CFAttributedStringCreate(kCFAllocatorDefault, string, attributes);
	CFRelease(string);
	CFRelease(attributes);
 
	CTLineRef line = CTLineCreateWithAttributedString(attrString);
 
	// Set text position and draw the line into the graphics context
	CGContextSetTextPosition(context, 10.0, 10.0);
	CTLineDraw(line, context);
	CFRelease(line);
}

- (CFArrayRef)createColumnsWithColumnCount:(int)columnCount {
	int column;
 
	CGRect* columnRects = (CGRect*)calloc(columnCount, sizeof(*columnRects));
	// Set the first column to cover the entire view.
	columnRects[0] = self.bounds;
 
	// Divide the columns equally across the frame's width.
	CGFloat columnWidth = CGRectGetWidth(self.bounds) / columnCount;
	for (column = 0; column < columnCount - 1; column++) {
		CGRectDivide(columnRects[column], &columnRects[column],
					 &columnRects[column + 1], columnWidth, CGRectMinXEdge);
	}
 
	// Inset all columns by a few pixels of margin.
	for (column = 0; column < columnCount; column++) {
		columnRects[column] = CGRectInset(columnRects[column], 8.0, 15.0);
	}
 
	// Create an array of layout paths, one for each column.
	CFMutableArrayRef array =
	CFArrayCreateMutable(kCFAllocatorDefault,
						 columnCount, &kCFTypeArrayCallBacks);
 
	for (column = 0; column < columnCount; column++) {
		CGMutablePathRef path = CGPathCreateMutable();
		CGPathAddRect(path, NULL, columnRects[column]);
		CFArrayInsertValueAtIndex(array, column, path);
		CFRelease(path);
	}
	free(columnRects);
	return array;
}

@end
