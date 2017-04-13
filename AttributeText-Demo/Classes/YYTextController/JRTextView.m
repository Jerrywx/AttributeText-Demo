//
//  JRTextView.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRTextView.h"

@implementation JRTextView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	CGContextRef context = UIGraphicsGetCurrentContext();
	
	CGRect rect1 = CGContextGetClipBoundingBox(context);
	NSLog(@"==== %@", NSStringFromCGRect(rect));
	NSLog(@"==== %@", NSStringFromCGRect(rect1));
	
	CGContextSaveGState(context);
	// stroke the frame because the layout frame might be open ended
	CGContextSaveGState(context);
	CGFloat dashes[] = {20.0, 5.0};
	CGContextSetLineDash(context, 0, dashes, 2);
	CGContextStrokeRect(context, CGRectMake(10, 10, 80, 80));
	
	// draw center line
	CGContextMoveToPoint(context, CGRectGetMidX(rect1), rect1.origin.y);
	CGContextAddLineToPoint(context, CGRectGetMidX(rect1), CGRectGetMaxY(rect1));
	CGContextStrokePath(context);
	
	CGContextRestoreGState(context);
	
	CGContextSetRGBStrokeColor(context, 1, 0, 0, 1.0);
	CGContextStrokeRect(context, rect);
	
	CGContextRestoreGState(context);
	
}

@end
