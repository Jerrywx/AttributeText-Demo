//
//  jr_CTLine.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CTLine_h
#define jr_CTLine_h

#ifndef __CTLINE__
#define __CTLINE__

#include <CoreText/CTDefines.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFAttributedString.h>
#include <CoreGraphics/CGContext.h>

CF_IMPLICIT_BRIDGING_ENABLED
CF_EXTERN_C_BEGIN
CF_ASSUME_NONNULL_BEGIN

/* --------------------------------------------------------------------------- */
/* Line Types */
/* --------------------------------------------------------------------------- */

typedef const struct CF_BRIDGED_TYPE(id) __CTLine * CTLineRef;


/*!
 @enum       CTLineBoundsOptions
 @abstract   Options for CTLineGetBoundsWithOptions.
 
 @discussion Passing 0 (no options) returns the typographic bounds,
 including typographic leading and shifts.
 
 @constant   kCTLineBoundsExcludeTypographicLeading
 Pass this option to exclude typographic leading.
 
 @constant   kCTLineBoundsExcludeTypographicShifts
 Pass this option to ignore cross-stream shifts due to
 positioning (such as kerning or baseline alignment).
 
 @constant   kCTLineBoundsUseHangingPunctuation
 Normally line bounds include all glyphs; pass this option to
 treat standard punctuation hanging off either end of the line
 as fully hanging.
 
 @constant   kCTLineBoundsUseGlyphPathBounds
 Pass this option to use glyph path bounds rather than the
 default typographic bounds.
 
 @constant   kCTLineBoundsUseOpticalBounds
 Pass this option to use optical bounds. This option overrides
 kCTLineBoundsUseGlyphPathBounds.
 
 @constant   kCTLineBoundsIncludeLanguageExtents
 Pass this option to include additional space based on common
 glyph sequences for various languages. The result is intended
 to be used when drawing to avoid clipping that may be caused
 by the typographic bounds. This option does not have any effect
 when used with kCTLineBoundsUseGlyphPathBounds.
 */

typedef CF_OPTIONS(CFOptionFlags, CTLineBoundsOptions) {
	kCTLineBoundsExcludeTypographicLeading  = 1 << 0,
	kCTLineBoundsExcludeTypographicShifts   = 1 << 1,
	kCTLineBoundsUseHangingPunctuation      = 1 << 2,
	kCTLineBoundsUseGlyphPathBounds         = 1 << 3,
	kCTLineBoundsUseOpticalBounds           = 1 << 4,
	kCTLineBoundsIncludeLanguageExtents CT_ENUM_AVAILABLE(10_11, 8_0) = 1 << 5,
};


/*!
 @enum       CTLineTruncationType
 @abstract   Truncation types required by CTLineCreateTruncatedLine. These
 will tell truncation engine which type of truncation is being
 requested.
 
 @constant   kCTLineTruncationStart
 Truncate at the beginning of the line, leaving the end portion
 visible.
 
 @constant   kCTLineTruncationEnd
 Truncate at the end of the line, leaving the start portion
 visible.
 
 @constant   kCTLineTruncationMiddle
 Truncate in the middle of the line, leaving both the start
 and the end portions visible.
 */

typedef CF_ENUM(uint32_t, CTLineTruncationType) {
	kCTLineTruncationStart  = 0,
	kCTLineTruncationEnd    = 1,
	kCTLineTruncationMiddle = 2
};


/*!
 @function   CTLineGetTypeID
 @abstract   Returns the CFType of the line object
 */

CFTypeID CTLineGetTypeID( void ) CT_AVAILABLE(10_5, 3_2);


/* --------------------------------------------------------------------------- */
/* Line Creation */
/* --------------------------------------------------------------------------- */
/// Creates a single immutable line object directly from an attributed string.
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef attrString );

/// Creates a truncated line from an existing line.
CTLineRef __nullable CTLineCreateTruncatedLine(
											   CTLineRef line,
											   double width,
											   CTLineTruncationType truncationType,
											   CTLineRef __nullable truncationToken );

/// Creates a justified(对齐线) line from an existing line.
CTLineRef __nullable CTLineCreateJustifiedLine(
											   CTLineRef line,
											   CGFloat justificationFactor,
											   double justificationWidth );


/* --------------------------------------------------------------------------- */
/* Line Access */
/* --------------------------------------------------------------------------- */
/// Returns the total glyph count for the line object.
CFIndex CTLineGetGlyphCount(CTLineRef line );


/// Returns the array of glyph runs that make up the line object.
CFArrayRef CTLineGetGlyphRuns(CTLineRef line );

/// Gets the range of characters that originally spawned the glyphs in the line.
CFRange CTLineGetStringRange(
							 CTLineRef line ) CT_AVAILABLE(10_5, 3_2);


/*!
 @function   CTLineGetPenOffsetForFlush
 @abstract   Gets the pen offset required to draw flush text.
 
 @param      line
 The line that you want to obtain a flush position from.
 
 @param      flushFactor
 Specifies what kind of flushness you want. A flushFactor of 0 or
 less indicates left flush. A flushFactor of 1.0 or more indicates
 right flush. Flush factors between 0 and 1.0 indicate varying
 degrees of center flush, with a value of 0.5 being totally center
 flush.
 
 @param      flushWidth
 Specifies the width that the flushness operation should apply to.
 
 @result     A value which can be used to offset the current pen position for
 the flush operation.
 */

double CTLineGetPenOffsetForFlush(
								  CTLineRef line,
								  CGFloat flushFactor,
								  double flushWidth ) CT_AVAILABLE(10_5, 3_2);

/// Draws a line.
void CTLineDraw(CTLineRef line, CGContextRef context );


/* --------------------------------------------------------------------------- */
/* Line Measurement */
/* --------------------------------------------------------------------------- */

/// Calculates the typographic bounds for a line.
double CTLineGetTypographicBounds(
								  CTLineRef line,
								  CGFloat * __nullable ascent,
								  CGFloat * __nullable descent,
								  CGFloat * __nullable leading ) CT_AVAILABLE(10_5, 3_2);


/*!
 @function   CTLineGetBoundsWithOptions
 @abstract   Calculates the bounds for a line.
 
 @param      line
 The line that you want to calculate the bounds for.
 
 @param      options
 Desired options or 0 if none.
 
 @result     The bounds of the line as specified by the type and options,
 such that the coordinate origin is coincident with the line
 origin and the rect origin is at the bottom left. If the line
 is invalid this function will return CGRectNull.
 */

CGRect CTLineGetBoundsWithOptions(
								  CTLineRef line,
								  CTLineBoundsOptions options ) CT_AVAILABLE(10_8, 6_0);


/*!
 @function   CTLineGetTrailingWhitespaceWidth
 @abstract   Calculates the trailing whitespace width for a line.
 
 @param      line
 The line that you want to calculate the trailing whitespace width
 for. Creating a line for a width can result in a line that is
 actually longer than the desired width due to trailing
 whitespace. Normally this is not an issue due to whitespace being
 invisible, but this function may be used to determine what amount
 of a line's width is due to trailing whitespace.
 
 @result     The width of the line's trailing whitespace. If line is invalid,
 this function will always return zero.
 */

double CTLineGetTrailingWhitespaceWidth(
										CTLineRef line ) CT_AVAILABLE(10_5, 3_2);


/*!
 @function   CTLineGetImageBounds
 @abstract   Calculates the image bounds for a line.
 
 @discussion The image bounds for a line is the union of all non-empty glyph
 bounding rects, each positioned as it would be if drawn using
 CTLineDraw using the current context. Note that the result is
 ideal and does not account for raster coverage due to rendering.
 This function is purely a convenience for using glyphs as an
 image and should not be used for typographic purposes.
 
 @param      line
 The line that you want to calculate the image bounds for.
 
 @param      context
 The context which the image bounds will be calculated for or NULL,
 in which case the bounds are relative to CGPointZero.
 
 @result     A rectangle that tightly encloses the paths of the line's glyphs,
 which will be translated by the supplied context's text position.
 If the line is invalid, CGRectNull will be returned.
 
 @seealso    CTLineGetTypographicBounds
 @seealso    CTLineGetBoundsWithOptions
 @seealso    CTLineGetPenOffsetForFlush
 */

CGRect CTLineGetImageBounds(
							CTLineRef line,
							CGContextRef __nullable context ) CT_AVAILABLE(10_5, 3_2);


/* --------------------------------------------------------------------------- */
/* Line Caret Positioning and Highlighting */
/* --------------------------------------------------------------------------- */

/*!
 @function   CTLineGetStringIndexForPosition
 @abstract   Performs hit testing.
 
 @discussion This function can be used to determine the string index for a
 mouse click or other event. This string index corresponds to the
 character before which the next character should be inserted.
 This determination is made by analyzing the string from which a
 typesetter was created and the corresponding glyphs as embodied
 by a particular line.
 
 @param      line
 The line being examined.
 
 @param      position
 The location of the mouse click relative to the line's origin.
 
 @result     The string index for the position. Relative to the line's string
 range, this value will be no less than the first string index and
 no greater than one plus the last string index. In the event of
 failure, this function will return kCFNotFound.
 */

CFIndex CTLineGetStringIndexForPosition(
										CTLineRef line,
										CGPoint position ) CT_AVAILABLE(10_5, 3_2);


/*!
 @function   CTLineGetOffsetForStringIndex
 @abstract   Determines the graphical offset(s) for a string index.
 
 @discussion This function returns the graphical offset(s) corresponding to
 a string index, suitable for movement between adjacent lines or
 for drawing a custom caret. For the former, the primary offset
 may be adjusted for any relative indentation of the two lines;
 a CGPoint constructed with the adjusted offset for its x value
 and 0.0 for its y value is suitable for passing to
 CTLineGetStringIndexForPosition. In either case, the primary
 offset corresponds to the portion of the caret that represents
 the visual insertion location for a character whose direction
 matches the line's writing direction.
 
 @param      line
 The line from which the offset is requested.
 
 @param      charIndex
 The string index corresponding to the desired position.
 
 @param      secondaryOffset
 An output parameter that will be set to the secondary offset
 along the baseline for charIndex. When a single caret is
 sufficient for a string index, this value will be the same as
 the primary offset, which is the return value of this function.
 This parameter may be NULL.
 
 @result     The primary offset along the baseline for charIndex, or 0.0 in
 the event of failure.
 */

CGFloat CTLineGetOffsetForStringIndex(
									  CTLineRef line,
									  CFIndex charIndex,
									  CGFloat * __nullable secondaryOffset ) CT_AVAILABLE(10_5, 3_2);


#if defined(__BLOCKS__)

/*!
 @function   CTLineEnumerateCaretOffsets
 @abstract   Enumerates caret offsets for characters in a line.
 
 @discussion The provided block is invoked once for each logical caret edge in the line, in left-to-right visual order.
 
 @param      block
 The offset parameter is relative to the line origin. The leadingEdge parameter of this block refers to logical order.
 */

void CTLineEnumerateCaretOffsets(
								 CTLineRef line,
								 void (^block)(double offset, CFIndex charIndex, bool leadingEdge, bool* stop) ) CT_AVAILABLE(10_11, 9_0);

#endif // defined(__BLOCKS__)


CF_ASSUME_NONNULL_END
CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif



#endif /* jr_CTLine_h */
