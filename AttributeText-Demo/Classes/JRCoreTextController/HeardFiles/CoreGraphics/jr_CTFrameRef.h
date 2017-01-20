//
//  jr_CTFrameRef.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CTFrameRef_h
#define jr_CTFrameRef_h

#ifndef __CTFRAME__
#define __CTFRAME__


/* --------------------------------------------------------------------------- */
/* Frame Types */
/* --------------------------------------------------------------------------- */

typedef const struct CF_BRIDGED_TYPE(id) __CTFrame * CTFrameRef;

/// Returns the CFType of the frame object
CFTypeID CTFrameGetTypeID( void ) CT_AVAILABLE(10_5, 3_2);


/* --------------------------------------------------------------------------- */
/* Frame Values																   */
/* --------------------------------------------------------------------------- */

/*!
 @enum		CTFrameProgression
 @abstract	These constants specify frame progression types.
 
 @discussion The lines of text within a frame may be stacked for either
 horizontal or vertical text. Values are enumerated for each
 stacking type supported by CTFrame. Frames created with a
 progression type specifying vertical text will rotate lines
 90 degrees counterclockwise when drawing.
 
 @constant	kCTFrameProgressionTopToBottom
 Lines are stacked top to bottom for horizontal text.
 
 @constant	kCTFrameProgressionRightToLeft
 Lines are stacked right to left for vertical text.
 
 @constant	kCTFrameProgressionLeftToRight
 Lines are stacked left to right for vertical text.
 */

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

CT_EXPORT const CFStringRef kCTFrameProgressionAttributeName CT_AVAILABLE(10_5, 3_2);

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

CT_EXPORT const CFStringRef kCTFramePathWidthAttributeName CT_AVAILABLE(10_7, 4_2);


/*!
	@const		kCTFrameClippingPathsAttributeName
	@abstract	Specifies array of paths to clip frame.
	
	@discussion Value must be a CFArrayRef containing CFDictionaryRefs or CGPathRef.  (CGPathRef is allowed on 10.8 or later.)
 Each dictionary should have a kCTFramePathClippingPathAttributeName key-value pair, and can have a kCTFramePathFillRuleAttributeName key-value pair
 and kCTFramePathFillRuleAttributeName key-value pair as optional parameters.  In case of CGPathRef, default fill rule (kCTFramePathFillEvenOdd) and width (0.0) are used.
 
	@seealso	CTFramesetterCreateFrame
 */

CT_EXPORT const CFStringRef kCTFrameClippingPathsAttributeName CT_AVAILABLE(10_7, 4_3);

/*!
	@const		kCTFramePathClippingPathAttributeName
	@abstract	Specifies clipping path.  This attribute is valid in a dictionary contained in an array specified by kCTFrameClippingPathsAttributeName.
 On 10.8 or later, This attribute is also valid in frameAttributes dictionary passed to CTFramesetterCreateFrame.
 
	@discussion Value must be a CGPathRef specifying a clipping path.
 
	@seealso	kCTFrameClippingPathsAttributeName
 */

CT_EXPORT const CFStringRef kCTFramePathClippingPathAttributeName CT_AVAILABLE(10_7, 4_3);


/* --------------------------------------------------------------------------- */
/* Frame Accessors															   */
/* --------------------------------------------------------------------------- */

/*!
	@function	CTFrameGetStringRange
	@abstract	Returns the range of characters that were originally requested
 to fill the frame.
 
	@param		frame
 The frame that you want to get the character range from.
 
	@result		This function will return a CFRange containing the backing
 store range of characters that were originally requested
 to fill the frame. If the function call is not successful,
 then an empty range will be returned.
 */

CFRange CTFrameGetStringRange(CTFrameRef frame );


/*!
	@function	CTFrameGetVisibleStringRange
	@abstract	Returns the range of characters that actually fit in the
 frame.
 
	@discussion This can be used to chain frames, as it returns the range of
 characters that can be seen in the frame. The next frame would
 start where this frame ends.
 
	@param		frame
 The frame that you want to get the visible character range
 from.
 
	@result		This function will return a CFRange containing the backing
 store range of characters that fit into the frame. If the
 function call is not successful, or if no characters fit
 in the frame, then an empty range will be returned.
 */

CFRange CTFrameGetVisibleStringRange(
									 CTFrameRef frame ) CT_AVAILABLE(10_5, 3_2);


/*!
	@function	CTFrameGetPath
	@abstract	Returns the path used to create the frame.
 
	@param		frame
 The frame that you want to obtain the path from.
 */

CGPathRef CTFrameGetPath(
						 CTFrameRef frame ) CT_AVAILABLE(10_5, 3_2);


/*!
	@function	CTFrameGetFrameAttributes
	@abstract	Returns the frame attributes used to create the frame.
 
	@discussion It is possible to create a frame with an attributes dictionary
 in order to control various aspects of the framing process.
 These attributes are different from the ones that are used to
 create an attributed string.
 
	@param		frame
 The frame that you want to obtain the frame attributes from.
 
	@result		This function will return a CFDictionary containing the
 frame attributes that were used to create the frame. If the
 frame was created without any frame attributes, this function
 will return NULL.
 */

CFDictionaryRef __nullable CTFrameGetFrameAttributes(
													 CTFrameRef frame ) CT_AVAILABLE(10_5, 3_2);


/*!
	@function	CTFrameGetLines
	@abstract	Returns an array of lines that make up the frame.
 
	@discussion This function will return an array of CTLine objects that are
 stored in the frame. These line objects can be accessed and
 manipulated in any way that normal line objects can be. It is
 possible that an empty frame exists. That is, a frame in which
 no lines exist. In this case, the returned array will have 0
 entries.
 
	@param		frame
 The frame that you want to obtain the line array from.
 
	@result		This function will return a CFArray object containing the
 CTLine objects that make up the frame.
 */

CFArrayRef CTFrameGetLines(
						   CTFrameRef frame ) CT_AVAILABLE(10_5, 3_2);


/// 获取所有 CTLine 的显示点 CTFrameGetLineOrigins
void CTFrameGetLineOrigins(
						   CTFrameRef frame,
						   CFRange range,
						   CGPoint origins[] ) CT_AVAILABLE(10_5, 3_2);


/*!
	@function	CTFrameDraw
	@abstract	Draws an entire frame to a context.
 
	@discussion This function will draw an entire frame to the context. Note
 that this call may leave the context in any state and does not
 flush it after the draw operation.
 
	@param		frame
 The frame that you want to draw.
 
	@param		context
 The context to draw the frame to.
 
	@discussion	If both the frame and the context are valid, the frame will be
 drawn in the context.
 */

void CTFrameDraw(
				 CTFrameRef frame,
				 CGContextRef context ) CT_AVAILABLE(10_5, 3_2);


CF_ASSUME_NONNULL_END
CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif



#endif /* jr_CTFrameRef_h */
