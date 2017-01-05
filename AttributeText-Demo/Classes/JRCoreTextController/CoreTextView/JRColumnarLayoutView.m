//
//  JRColumnarLayoutView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRColumnarLayoutView.h"

@implementation JRColumnarLayoutView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
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
