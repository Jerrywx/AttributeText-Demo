//
//  JRParagraphStyleView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRParagraphStyleView.h"

@implementation JRParagraphStyleView


- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	// Initialize a graphics context in iOS.
	CGContextRef context = UIGraphicsGetCurrentContext();
 
	// Flip the context coordinates in iOS only.
	CGContextTranslateCTM(context, 0, self.bounds.size.height);
	CGContextScaleCTM(context, 1.0, -1.0);
 
	// Set the text matrix.
	CGContextSetTextMatrix(context, CGAffineTransformIdentity);
 
	CFStringRef fontName = CFSTR("Didot Italic");
	CGFloat pointSize = 24.0;
 
	CFStringRef string = CFSTR("Hello, World! I know nothing in the world that has as much power as a word. Sometimes I write one, and I look at it, until it begins to shine.");
							   
	// Apply the paragraph style.
	NSAttributedString* attrString = applyParaStyle(fontName, pointSize, (__bridge NSString *)(string), 50.0);

	// Put the attributed string with applied paragraph style into a framesetter.
	CTFramesetterRef framesetter =
	CTFramesetterCreateWithAttributedString((CFAttributedStringRef)attrString);

	// Create a path to fill the View.
	CGPathRef path = CGPathCreateWithRect(rect, NULL);

	// Create a frame in which to draw.
	CTFrameRef frame = CTFramesetterCreateFrame(
											   framesetter, CFRangeMake(0, 0), path, NULL);

	// Draw the frame.
	CTFrameDraw(frame, context);
	CFRelease(frame);
	CGPathRelease(path);
	CFRelease(framesetter);
}





NSAttributedString* applyParaStyle(
								   CFStringRef fontName , CGFloat pointSize,
								   NSString *plainText, CGFloat lineSpaceInc){
 
	// Create the font so we can determine its height.
	CTFontRef font = CTFontCreateWithName(fontName, pointSize, NULL);
 
	// Set the lineSpacing.
	CGFloat lineSpacing = (CTFontGetLeading(font) + lineSpaceInc) * 2;
 
	// Create the paragraph style settings.
	CTParagraphStyleSetting setting;
 
	setting.spec = kCTParagraphStyleSpecifierLineSpacing;
	setting.valueSize = sizeof(CGFloat);
	setting.value = &lineSpacing;
 
	CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(&setting, 1);
 
	// Add the paragraph style to the dictionary.
	NSDictionary *attributes = [NSDictionary dictionaryWithObjectsAndKeys:
								(__bridge id)font, (id)kCTFontNameAttribute,
								(__bridge id)paragraphStyle,
								(id)kCTParagraphStyleAttributeName, nil];
	CFRelease(font);
	CFRelease(paragraphStyle);
 
	// Apply the paragraph style to the string to created the attributed string.
	NSAttributedString* attrString = [[NSAttributedString alloc]
									  initWithString:(NSString*)plainText
									  attributes:attributes];
 
	return attrString;
}

@end
