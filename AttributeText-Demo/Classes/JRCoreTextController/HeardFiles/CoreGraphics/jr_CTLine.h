//
//  jr_CTLine.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/5.
//  Copyright © 2017年 王潇. All rights reserved.
//

#ifndef jr_CTLine_h
#define jr_CTLine_h

/* --------------------------------------------------------------------------- */
/* Line Types */
/* --------------------------------------------------------------------------- */

typedef const struct CF_BRIDGED_TYPE(id) __CTLine * CTLineRef;

/// Options for CTLineGetBoundsWithOptions.
typedef CF_OPTIONS(CFOptionFlags, CTLineBoundsOptions) {
	kCTLineBoundsExcludeTypographicLeading  = 1 << 0,
	kCTLineBoundsExcludeTypographicShifts   = 1 << 1,
	kCTLineBoundsUseHangingPunctuation      = 1 << 2,
	kCTLineBoundsUseGlyphPathBounds         = 1 << 3,
	kCTLineBoundsUseOpticalBounds           = 1 << 4,
	kCTLineBoundsIncludeLanguageExtents CT_ENUM_AVAILABLE(10_11, 8_0) = 1 << 5,
};


/// 内容截断类型
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
/// 使用属性字符串创建 CTLine
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef attrString );

/// Creates a truncated line from an existing line.
/// 创建一个删节内容
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
/// 获取显示文本数量
CFIndex CTLineGetGlyphCount(CTLineRef line );

/// Returns the array of glyph runs that make up the line object.
/// 获取 CTLineRef 中的 runs
CFArrayRef CTLineGetGlyphRuns(CTLineRef line );

/// Gets the range of characters that originally spawned the glyphs in the line.
/// 获取文本显示范围
CFRange CTLineGetStringRange(CTLineRef line );


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
								  CGFloat * __nullable leading );

/// 根据 CTLineBoundsOptions 获取 bounds
CGRect CTLineGetBoundsWithOptions(
								  CTLineRef line,
								  CTLineBoundsOptions options );

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
double CTLineGetTrailingWhitespaceWidth(CTLineRef line );

/// 获取 image bounds
CGRect CTLineGetImageBounds( CTLineRef line, CGContextRef __nullable context );


/* --------------------------------------------------------------------------- */
/* Line Caret Positioning and Highlighting */
/* --------------------------------------------------------------------------- */

/// 根据某个点获取索引
CFIndex CTLineGetStringIndexForPosition(CTLineRef line, CGPoint position );

/// 根据索引 获取 偏移量
CGFloat CTLineGetOffsetForStringIndex(
									  CTLineRef line,
									  CFIndex charIndex,
									  CGFloat * __nullable secondaryOffset );


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
								 void (^block)(double offset, CFIndex charIndex, bool leadingEdge, bool* stop));



#endif /* jr_CTLine_h */
