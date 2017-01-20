//
//  jr_CTFrame.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/6.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CTFrame_h
#define jr_CTFrame_h

/* --------------------------------------------------------------------------- */
/* Frame Types */
/* --------------------------------------------------------------------------- */

typedef const struct CF_BRIDGED_TYPE(id) __CTFrame * CTFrameRef;


/*!
	@function	CTFrameGetTypeID
	@abstract	Returns the CFType of the frame object
 */
CFTypeID CTFrameGetTypeID( void ) CT_AVAILABLE(10_5, 3_2);


/* --------------------------------------------------------------------------- */
/* Frame Values */
/* --------------------------------------------------------------------------- */
/// These constants specify frame progression types.
typedef CF_ENUM(uint32_t, CTFrameProgression) {
	kCTFrameProgressionTopToBottom  = 0,
	kCTFrameProgressionRightToLeft  = 1,
	kCTFrameProgressionLeftToRight  = 2
};


/*!
	@const		kCTFrameProgressionAttributeName
	@abstract	Specifies progression for a frame.
	
	@discussion Value must be a CFNumberRef containing a CTFrameProgression.
 Default is kCTFrameProgressionTopToBottom. This value determines
 the line stacking behavior for a frame and does not affect the
 appearance of the glyphs within that frame.
 
	@seealso	CTFramesetterCreateFrame
 */
const CFStringRef kCTFrameProgressionAttributeName CT_AVAILABLE(10_5, 3_2);

/*!
	@enum		CTFramePathFillRule
	@abstract	These constants specify fill rule used by the frame.
 
	@discussion When a path intersects with itself, the client should specify which rule to use for deciding the
 area of the path.
 
	@constant	kCTFramePathFillEvenOdd
 Text is filled in the area that would be painted if the path were given to CGContextEOFillPath.
 
	@constant	kCTFramePathFillWindingNumber
 Text is fill in the area that would be painted if the path were given to CGContextFillPath.
 
 
 */
typedef CF_ENUM(uint32_t, CTFramePathFillRule) {
	kCTFramePathFillEvenOdd         = 0,
	kCTFramePathFillWindingNumber   = 1
};


/*!
	@const		kCTFramePathFillRuleAttributeName
	@abstract	Specifies fill rule for a frame if this attribute is used at top level of frameAttributes dictionary, or specify
 fill rule for a clipping path if used in a dictionary contained in an array specified by kCTFrameClippingPathsAttributeName.
 
	@discussion Value must be a CFNumberRef containing kCTFramePathFillEvenOdd or kCTFramePathFillWindingNumber.
 Default is kCTFramePathFillEvenOdd.
 
	@seealso	CTFramesetterCreateFrame
 */

CT_EXPORT const CFStringRef kCTFramePathFillRuleAttributeName CT_AVAILABLE(10_7, 4_2);

/*!
	@const		kCTFramePathWidthAttributeName
	@abstract	Specifies frame width if this attribute is used at top level of frameAttributes dictionary, or specify
 clipping path width if used in a dictionary contained in an array specified by kCTFrameClippingPathsAttributeName.
 
	@discussion Value must be a CFNumberRef specifying frame width.
 Default is zero.
 
	@seealso	CTFramesetterCreateFrame
 */

const CFStringRef kCTFramePathWidthAttributeName CT_AVAILABLE(10_7, 4_2);


/*!
	@const		kCTFrameClippingPathsAttributeName
	@abstract	Specifies array of paths to clip frame.
	
	@discussion Value must be a CFArrayRef containing CFDictionaryRefs or CGPathRef.  (CGPathRef is allowed on 10.8 or later.)
 Each dictionary should have a kCTFramePathClippingPathAttributeName key-value pair, and can have a kCTFramePathFillRuleAttributeName key-value pair
 and kCTFramePathFillRuleAttributeName key-value pair as optional parameters.  In case of CGPathRef, default fill rule (kCTFramePathFillEvenOdd) and width (0.0) are used.
 
	@seealso	CTFramesetterCreateFrame
 */
const CFStringRef kCTFrameClippingPathsAttributeName CT_AVAILABLE(10_7, 4_3);

/*!
	@const		kCTFramePathClippingPathAttributeName
	@abstract	Specifies clipping path.  This attribute is valid in a dictionary contained in an array specified by kCTFrameClippingPathsAttributeName.
 On 10.8 or later, This attribute is also valid in frameAttributes dictionary passed to CTFramesetterCreateFrame.
 
	@discussion Value must be a CGPathRef specifying a clipping path.
 
	@seealso	kCTFrameClippingPathsAttributeName
 */
const CFStringRef kCTFramePathClippingPathAttributeName CT_AVAILABLE(10_7, 4_3);

/* --------------------------------------------------------------------------- */
/* Frame Accessors */
/* --------------------------------------------------------------------------- */
/// Returns the range of characters that were originally requested to fill the frame.
CFRange CTFrameGetStringRange(CTFrameRef frame );

/// Returns the range of characters that actually fit in the frame.
CFRange CTFrameGetVisibleStringRange(CTFrameRef frame );

/// Returns the path used to create the frame.
CGPathRef CTFrameGetPath(CTFrameRef frame );

/// Returns the frame attributes used to create the frame.
CFDictionaryRef __nullable CTFrameGetFrameAttributes(CTFrameRef frame );

/// Returns an array of lines that make up the frame.
CFArrayRef CTFrameGetLines(CTFrameRef frame );

/// 获得每一行的origin坐标
void CTFrameGetLineOrigins(CTFrameRef frame,
						   CFRange range,
						   CGPoint origins[] );

/// Draws an entire frame to a context.
void CTFrameDraw(CTFrameRef frame,
				 CGContextRef context );

#endif /* jr_CTFrame_h */
