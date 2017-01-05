//
//  JRSimpleTextView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpleTextView.h"

@implementation JRSimpleTextView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	CFStringRef string; CTFontRef font; CGContextRef context;
	
	string = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
	// 创建font
	font = CTFontCreateWithName((CFStringRef)[UIFont boldSystemFontOfSize:14].fontName, 24, NULL);
	context = UIGraphicsGetCurrentContext();
	
	// 翻转坐标系
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
	
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
	CGContextSetTextPosition(context, 0.0, 10.0);
	CTLineDraw(line, context);
	CFRelease(line);

}


@end
