//
//  JRManualLineBreakingView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRManualLineBreakingView.h"

@implementation JRManualLineBreakingView

// Manual Line Breaking
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	double width; CGContextRef context; CGPoint textPosition; CFMutableAttributedStringRef attrString;
	// Initialize those variables.
	
	width = rect.size.width * 0.5;
	textPosition = CGPointMake(0, rect.size.height * 0.5);
	context = UIGraphicsGetCurrentContext();
	
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
	
	CFStringRef textString = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
 
	// Create a mutable attributed string with a max length of 0.
	// The max length is a hint as to how much internal storage to reserve.
	// 0 means no hint.
	///
	attrString = CFAttributedStringCreateMutable(kCFAllocatorDefault, 0);

	// Copy the textString into the newly created attrString
	CFAttributedStringReplaceString (attrString, CFRangeMake(0, 0),
									 textString);
 
	// Create a typesetter using the attributed string.
	CTTypesetterRef typesetter = CTTypesetterCreateWithAttributedString(attrString);
 
	// Find a break for line from the beginning of the string to the given width.
	CFIndex start = 0;
	CFIndex count = CTTypesetterSuggestLineBreak(typesetter, start, width);
 
	// Use the returned character count (to the break) to create the line.
	CTLineRef line = CTTypesetterCreateLine(typesetter, CFRangeMake(start, count));
 
	// Get the offset needed to center the line.
	float flush = 20.1; // centered
	double penOffset = CTLineGetPenOffsetForFlush(line, flush, width);
 
	// Move the given text drawing position by the calculated offset and draw the line.
	CGContextSetTextPosition(context, textPosition.x + penOffset, textPosition.y);
	CTLineDraw(line, context);
 
	// Move the index beyond the line break.
	start += count;	
}

@end
