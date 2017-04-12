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
/* Glyph Run Types */
/* --------------------------------------------------------------------------- */

typedef const struct CF_BRIDGED_TYPE(id) __CTRun * CTRunRef;


/*!
 @enum       CTRunStatus
 @abstract   A bitfield passed back by CTRunGetStatus that is used to
 indicate the disposition of the run.
 
 @constant   kCTRunStatusNoStatus
 The run has no special attributes.
 
 @constant   kCTRunStatusRightToLeft
 When set, the run is right to left.
 
 @constant   kCTRunStatusNonMonotonic
 When set, the run has been reordered in some way such that
 the string indices associated with the glyphs are no longer
 strictly increasing (for left to right runs) or decreasing
 (for right to left runs).
 
 @constant   kCTRunStatusHasNonIdentityMatrix
 When set, the run requires a specific text matrix to be set
 in the current CG context for proper drawing.
 */
typedef CF_OPTIONS(uint32_t, CTRunStatus) {
	kCTRunStatusNoStatus				= 0,
	kCTRunStatusRightToLeft				= (1 << 0),
	kCTRunStatusNonMonotonic			= (1 << 1),
	kCTRunStatusHasNonIdentityMatrix	= (1 << 2)
};

/*!
 @function   CTRunGetTypeID
 @abstract   Returns the CFType of the run object
 */
CFTypeID CTRunGetTypeID( void );


/* --------------------------------------------------------------------------- */
/* Glyph Run Access */
/* --------------------------------------------------------------------------- */

/// 获取 CTRun 索引
CFIndex CTRunGetGlyphCount(CTRunRef run);

/// 获取属性
CFDictionaryRef CTRunGetAttributes(CTRunRef run );

/// 获取状态
CTRunStatus CTRunGetStatus(CTRunRef run );

const CGGlyph * __nullable CTRunGetGlyphsPtr(CTRunRef run );

/// 获取 CGGlyph
void CTRunGetGlyphs(CTRunRef run,
					CFRange range,
					CGGlyph buffer[] );

const CGPoint * __nullable CTRunGetPositionsPtr(CTRunRef run );

/// 获取 glyph 位置
void CTRunGetPositions(CTRunRef run,
					   CFRange range,
					   CGPoint buffer[]);

const CGSize * __nullable CTRunGetAdvancesPtr(CTRunRef run);

/// 获取 宽度
void CTRunGetAdvances(CTRunRef run,
					  CFRange range,
					  CGSize buffer[]);

const CFIndex * __nullable CTRunGetStringIndicesPtr(CTRunRef run );

/// 获取索引
void CTRunGetStringIndices(CTRunRef run,
						   CFRange range,
						   CFIndex buffer[] );

/*!
 @function   CTRunGetStringRange
 @abstract   Gets the range of characters that originally spawned the glyphs
 in the run.
 
 @param      run
 The run whose string range you wish to access.
 
 @result     Returns the range of characters that originally spawned the
 glyphs. If run is invalid, this will return an empty range.
 */
CFRange CTRunGetStringRange(CTRunRef run);

/*!
 @function   CTRunGetTypographicBounds
 @abstract   Gets the typographic bounds of the run.
 
 @param      run
 The run that you want to calculate the typographic bounds for.
 
 @param      range
 The range of glyphs to be measured, with the entire range having
 a location of 0 and a length of CTRunGetGlyphCount. If the length
 of the range is set to 0, then the operation will continue from
 the range's start index to the end of the run.
 
 @param      ascent
 Upon return, this parameter will contain the ascent of the run.
 This may be set to NULL if not needed.
 
 @param      descent
 Upon return, this parameter will contain the descent of the run.
 This may be set to NULL if not needed.
 
 @param      leading
 Upon return, this parameter will contain the leading of the run.
 This may be set to NULL if not needed.
 
 @result     The typographic width of the run. If run or range is
 invalid, then this function will always return zero.
 */
double CTRunGetTypographicBounds(CTRunRef run,
								 CFRange range,
								 CGFloat * __nullable ascent,
								 CGFloat * __nullable descent,
								 CGFloat * __nullable leading );

/*!
 @function   CTRunGetImageBounds
 @abstract   Calculates the image bounds for a glyph range.
 
 @discussion The image bounds for a run is the union of all non-empty glyph
 bounding rects, each positioned as it would be if drawn using
 CTRunDraw using the current context. Note that the result is
 ideal and does not account for raster coverage due to rendering.
 This function is purely a convenience for using glyphs as an
 image and should not be used for typographic purposes.
 
 @param      run
 The run that you want to calculate the image bounds for.
 
 @param      context
 The context which the image bounds will be calculated for or NULL,
 in which case the bounds are relative to CGPointZero.
 
 @param      range
 The range of glyphs to be measured, with the entire range having
 a location of 0 and a length of CTRunGetGlyphCount. If the length
 of the range is set to 0, then the operation will continue from
 the range's start index to the end of the run.
 
 @result     A rect that tightly encloses the paths of the run's glyphs. The
 rect origin will match the drawn position of the requested range;
 that is, it will be translated by the supplied context's text
 position and the positions of the individual glyphs. If the run
 or range is invalid, CGRectNull will be returned.
 
 @seealso    CTRunGetTypographicBounds
 */
CGRect CTRunGetImageBounds(CTRunRef run,
						   CGContextRef __nullable context,
						   CFRange range );

/*!
 @function   CTRunGetTextMatrix
 @abstract   Returns the text matrix needed to draw this run.
 
 @discussion To properly draw the glyphs in a run, the fields 'tx' and 'ty' of
 the CGAffineTransform returned by this function should be set to
 the current text position.
 
 @param      run
 The run object from which to get the text matrix.
 
 @result     A CGAffineTransform.
 */
CGAffineTransform CTRunGetTextMatrix(CTRunRef run);

/*!
 @function   CTRunDraw
 @abstract   Draws a complete run or part of one.
 
 @discussion This is a convenience call, since the run could also be drawn by
 accessing its glyphs, positions, and text matrix. Unlike when
 drawing the entire line containing the run with CTLineDraw, the
 run's underline (if any) will not be drawn, since the underline's
 appearance may depend on other runs in the line. Note that this
 call may leave the graphics context in any state and does not
 flush the context after the draw operation.
 
 @param      run
 The run that you want to draw.
 
 @param      context
 The context to draw the run to.
 
 @param      range
 The range of glyphs to be drawn, with the entire range having a
 location of 0 and a length of CTRunGetGlyphCount. If the length
 of the range is set to 0, then the operation will continue from
 the range's start index to the end of the run.
 */
/// 绘制 CTRunRef
void CTRunDraw(CTRunRef run,
			   CGContextRef context,
			   CFRange range );


#endif /* jr_CTFrame_h */
