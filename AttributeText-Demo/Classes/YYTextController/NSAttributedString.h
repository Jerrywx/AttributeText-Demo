//
//  NSAttributedString.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#ifndef NSAttributedString_h
#define NSAttributedString_h

/************************ Attributes ************************/

// Predefined character attributes for text.
// If the key is not in the dictionary, then use the default values as described below.
// UIFont, default Helvetica(Neue) 12											字体大小	NSFont 对象
UIKIT_EXTERN NSString * const NSFontAttributeName;
// NSParagraphStyle, default defaultParagraphStyle								段落样式 defaultParagraphStyle 对象
UIKIT_EXTERN NSString * const NSParagraphStyleAttributeName;
// UIColor, default blackColor													字体颜色 默认 黑色
UIKIT_EXTERN NSString * const NSForegroundColorAttributeName;
// UIColor, default nil: no background											字体背景色 默认无
UIKIT_EXTERN NSString * const NSBackgroundColorAttributeName;
// NSNumber containing integer, default 1: default ligatures, 0: no ligatures	连字符 默认无
UIKIT_EXTERN NSString * const NSLigatureAttributeName;
// NSNumber containing floating point value, in points;
// amount to modify default kerning. 0 means kerning is disabled.				字间距
UIKIT_EXTERN NSString * const NSKernAttributeName;
// NSNumber containing integer, default 0: no strikethrough						删除线
UIKIT_EXTERN NSString * const NSStrikethroughStyleAttributeName;
// NSNumber containing integer, default 0: no underline							下划线
UIKIT_EXTERN NSString * const NSUnderlineStyleAttributeName;
// UIColor, default nil: same as foreground color								文字边线颜色
UIKIT_EXTERN NSString * const NSStrokeColorAttributeName;
// NSNumber containing floating point value, in percent of font point size,
// default 0: no stroke; positive for stroke alone, negative for stroke and fill
// (a typical value for outlined text would be 3.0)								文字边线宽度
UIKIT_EXTERN NSString * const NSStrokeWidthAttributeName;
// NSShadow, default nil: no shadow												// 阴影属性
UIKIT_EXTERN NSString * const NSShadowAttributeName;
// NSString, default nil: no text effect
UIKIT_EXTERN NSString *const NSTextEffectAttributeName;
// NSTextAttachment, default nil						设置文本附件,取值为NSTextAttachment对象,常用于文字图片混排
UIKIT_EXTERN NSString * const NSAttachmentAttributeName;
// NSURL (preferred) or NSString												设置链接属性，点击后调用浏览器打开指定URL地址
UIKIT_EXTERN NSString * const NSLinkAttributeName;
// NSNumber containing floating point value, in points; offset from baseline, default 0
// 设置基线偏移值，取值为 NSNumber （float）,正值上偏，负值下偏
UIKIT_EXTERN NSString * const NSBaselineOffsetAttributeName;
// UIColor, default nil: same as foreground color								下划线颜色
UIKIT_EXTERN NSString * const NSUnderlineColorAttributeName;
// UIColor, default nil: same as foreground color
UIKIT_EXTERN NSString * const NSStrikethroughColorAttributeName;
// 设置字形倾斜度，取值为 NSNumber （float）,正值右倾，负值左倾
// NSNumber containing floating point value; skew to be applied to glyphs, default 0: no skew
UIKIT_EXTERN NSString * const NSObliquenessAttributeName;
// 设置文本横向拉伸属性，取值为 NSNumber （float）,正值横向拉伸文本，负值横向压缩文本
// NSNumber containing floating point value; log of expansion factor to be applied to glyphs, default 0: no expansion
UIKIT_EXTERN NSString * const NSExpansionAttributeName;

// 设置文字书写方向，从左向右书写或者从右向左书写
UIKIT_EXTERN NSString * const NSWritingDirectionAttributeName NS_AVAILABLE(10_6, 7_0);
//	NSArray of NSNumbers representing the nested levels of writing direction overrides as defined by Unicode LRE, RLE, LRO, and RLO characters.  The control characters can be obtained by masking NSWritingDirection and NSWritingDirectionFormatType values.  LRE: NSWritingDirectionLeftToRight|NSWritingDirectionEmbedding, RLE: NSWritingDirectionRightToLeft|NSWritingDirectionEmbedding, LRO: NSWritingDirectionLeftToRight|NSWritingDirectionOverride, RLO: NSWritingDirectionRightToLeft|NSWritingDirectionOverride,

// 设置文字排版方向，取值为 NSNumber 对象(整数)，0 表示横排文本，1 表示竖排文本
UIKIT_EXTERN NSString * const NSVerticalGlyphFormAttributeName NS_AVAILABLE(10_7, 6_0);
// An NSNumber containing an integer value.  0 means horizontal text.  1 indicates vertical text.  If not specified, it could follow higher-level vertical orientation settings.  Currently on iOS, it's always horizontal.  The behavior for any other value is undefined.



/************************ Attribute values ************************/
// This defines currently supported values for NSUnderlineStyleAttributeName and NSStrikethroughStyleAttributeName. NSUnderlineStyle*, NSUnderlinePattern*, and NSUnderlineByWord are or'ed together to produce an underline style.
/// 下划线样式
typedef NS_ENUM(NSInteger, NSUnderlineStyle) {
	NSUnderlineStyleNone                                    = 0x00,				// 无
	NSUnderlineStyleSingle                                  = 0x01,				// 单行
	NSUnderlineStyleThick NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x02,
	NSUnderlineStyleDouble NS_ENUM_AVAILABLE(10_0, 7_0)     = 0x09,				// 双
	
	NSUnderlinePatternSolid NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x0000,
	NSUnderlinePatternDot NS_ENUM_AVAILABLE(10_0, 7_0)        = 0x0100,
	NSUnderlinePatternDash NS_ENUM_AVAILABLE(10_0, 7_0)       = 0x0200,
	NSUnderlinePatternDashDot NS_ENUM_AVAILABLE(10_0, 7_0)    = 0x0300,
	NSUnderlinePatternDashDotDot NS_ENUM_AVAILABLE(10_0, 7_0) = 0x0400,
	
	NSUnderlineByWord NS_ENUM_AVAILABLE(10_0, 7_0)            = 0x8000
} NS_ENUM_AVAILABLE(10_0, 6_0);

// NSWritingDirectionFormatType values used by NSWritingDirectionAttributeName. It is or'ed with either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft. Can specify the formatting controls defined by Unicode Bidirectional Algorithm.
/// 绘制方向
typedef NS_ENUM(NSInteger, NSWritingDirectionFormatType) {
	NSWritingDirectionEmbedding     = (0 << 1),
	NSWritingDirectionOverride      = (1 << 1)
} NS_ENUM_AVAILABLE(10_11, 9_0);

// NSTextEffectAttributeName values
UIKIT_EXTERN NSString *const NSTextEffectLetterpressStyle NS_AVAILABLE(10_10, 7_0);


/************************ Attribute fixing ************************/

@interface NSMutableAttributedString (NSAttributedStringAttributeFixing)
// This method fixes attribute inconsistencies inside range.  It ensures NSFontAttributeName covers the characters, NSParagraphStyleAttributeName is only changing at paragraph boundaries, and NSTextAttachmentAttributeName is assigned to NSAttachmentCharacter.  NSTextStorage automatically invokes this method via -ensureAttributesAreFixedInRange:.
- (void)fixAttributesInRange:(NSRange)range NS_AVAILABLE(10_0, 7_0);

@end


/************************ Document formats ************************/

// Supported document types for the NSDocumentTypeDocumentAttribute key in the document attributes dictionary.
UIKIT_EXTERN NSString * const NSPlainTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSRTFTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSRTFDTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSHTMLTextDocumentType NS_AVAILABLE(10_0, 7_0);

// Keys for NSLayoutOrientationSectionsAttribute.
UIKIT_EXTERN NSString * const NSTextLayoutSectionOrientation NS_AVAILABLE(10_7, 7_0); // NSNumber containing NSTextLayoutOrientation value. default: NSTextLayoutOrientationHorizontal
UIKIT_EXTERN NSString * const NSTextLayoutSectionRange NS_AVAILABLE(10_7, 7_0); // NSValue containing NSRange representing a character range. default: a range covering the whole document


// Keys for options and document attributes dictionaries.  They are in and out document properties used by both read/write methods.

UIKIT_EXTERN NSString * const NSDocumentTypeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"DocumentType", one of the document types declared above.  For reader methods, this key in options can specify the document type for interpreting the contents.  Upon return, the document attributes can contain this key for indicating the actual format used to read the contents.  For write methods, this key specifies the format for generating the data.


// NSPlainTextDocumentType document attributes
UIKIT_EXTERN NSString * const NSCharacterEncodingDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"CharacterEncoding", NSNumber containing integer specifying NSStringEncoding for the file; default for plain text is the default encoding.  This key in options can specify the string encoding for reading the data.  Upon return, the document attributes can contain the actual encoding used.  For writing methods, this value is used for generating the plain text data.
UIKIT_EXTERN NSString * const NSDefaultAttributesDocumentAttribute NS_AVAILABLE(10_11, 7_0);  // @"DefaultAttributes", NSDictionary containing attributes to be applied to plain files.  Used by reader methods.  This key in options can specify the default attributes applied to the entire document contents.  The document attributes can contain this key indicating the actual attributes used.


// NSRTFTextDocumentType and NSRTFDTextDocumentType document attributes
// Document dimension
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString * const NSPaperSizeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"PaperSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString * const NSPaperMarginDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"PaperMargin", NSValue containing UIEdgeInsets

UIKIT_EXTERN NSString * const NSViewSizeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString * const NSViewZoomDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewZoom", NSNumber containing floating point value (100 == 100% zoom)
UIKIT_EXTERN NSString * const NSViewModeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewMode", NSNumber containing integer; 0 = normal; 1 = page layout

// Document settings
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString * const NSReadOnlyDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ReadOnly", NSNumber containing integer; if missing, or 0 or negative, not readonly; 1 or more, readonly. Note that this has nothing to do with the file system protection on the file, but instead, on how the file should be displayed to the user
UIKIT_EXTERN NSString * const NSBackgroundColorDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"BackgroundColor", UIColor, representing the document-wide page background color
UIKIT_EXTERN NSString * const NSHyphenationFactorDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"HyphenationFactor", NSNumber containing floating point value (0=off, 1=full hyphenation)
UIKIT_EXTERN NSString * const NSDefaultTabIntervalDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"DefaultTabInterval", NSNumber containing floating point value, representing the document-wide default tab stop interval, in points
UIKIT_EXTERN NSString * const NSTextLayoutSectionsAttribute NS_AVAILABLE(10_7, 7_0);  // NSArray of dictionaries.  Each dictionary describing a layout orientation section.  The dictionary can have two attributes: NSTextLayoutSectionOrientation and NSTextLayoutSectionRange.  When there is a gap between sections, it's assumed to have NSTextLayoutOrientationHorizontal.


@interface NSAttributedString (NSAttributedStringDocumentFormats)
// Methods initializing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (nullable instancetype)initWithURL:(NSURL *)url 
							 options:(NSDictionary<NSString *, id> *)options 
				  documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error;

- (nullable instancetype)initWithData:(NSData *)data 
							  options:(NSDictionary<NSString *, id> *)options 
				   documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error;

// Generates an NSData object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.
- (nullable NSData *)dataFromRange:(NSRange)range 
				documentAttributes:(NSDictionary<NSString *, id> *)dict 
							 error:(NSError **)error;

// Returns an NSFileWrapper object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.  The method returns a directory file wrapper for those document types represented by a file package such as NSRTFDTextDocumentType; otherwise, it returns a regular-file file wrapper.
- (nullable NSFileWrapper *)fileWrapperFromRange:(NSRange)range 
							  documentAttributes:(NSDictionary<NSString *, id> *)dict 
										   error:(NSError **)error;

@end

@interface NSMutableAttributedString (NSMutableAttributedStringDocumentFormats)
// Methods replacing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (BOOL)readFromURL:(NSURL *)url 
			options:(NSDictionary<NSString *, id> *)opts 
 documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict 
			  error:(NSError **)error;

- (BOOL)readFromData:(NSData *)data 
			 options:(NSDictionary<NSString *, id> *)opts 
  documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict 
			   error:(NSError **)error;

@end


/************************ Misc methods ************************/
@interface NSAttributedString (NSAttributedStringKitAdditions)
// Returns YES if the receiver contains a property configured (NSAttachmentAttributeName with NSAttachmentCharacter) in range
- (BOOL)containsAttachmentsInRange:(NSRange)range NS_AVAILABLE(10_11, 9_0);
@end










@interface NSAttributedString : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>
/// 获取字符串
@property (readonly, copy) NSString *string;
/// 根据索引获取字符串属性 并获取具有此属性的字符串范围
- (NSDictionary<NSString *, id> *)attributesAtIndex:(NSUInteger)location 
									 effectiveRange:(nullable NSRangePointer)range;

@end
/// 扩展
@interface NSAttributedString (NSExtendedAttributedString)
/// 长度
@property (readonly) NSUInteger length;
/// 根据索引、属性名 获取属性对应值 并获取范围
- (nullable id)attribute:(NSString *)attrName 
				 atIndex:(NSUInteger)location 
		  effectiveRange:(nullable NSRangePointer)range;
/// 根据范围获取子属性字符串
- (NSAttributedString *)attributedSubstringFromRange:(NSRange)range;
/// 现在范围
- (NSDictionary<NSString *, id> *)attributesAtIndex:(NSUInteger)location 
							  longestEffectiveRange:(nullable NSRangePointer)range 
											inRange:(NSRange)rangeLimit;

- (nullable id)attribute:(NSString *)attrName 
				 atIndex:(NSUInteger)location 
   longestEffectiveRange:(nullable NSRangePointer)range 
				 inRange:(NSRange)rangeLimit;
/// 属性比较
- (BOOL)isEqualToAttributedString:(NSAttributedString *)other;
/// 使用字符串初始化
- (instancetype)initWithString:(NSString *)str;
/// 使用字符串和属性初始化
- (instancetype)initWithString:(NSString *)str
					attributes:(nullable NSDictionary<NSString *, id> *)attrs;
/// 使用属性字符串初始化
- (instancetype)initWithAttributedString:(NSAttributedString *)attrStr;
///
typedef NS_OPTIONS(NSUInteger, NSAttributedStringEnumerationOptions) {
	NSAttributedStringEnumerationReverse = (1UL << 1),
	NSAttributedStringEnumerationLongestEffectiveRangeNotRequired = (1UL << 20)
};
/// 遍历
- (void)enumerateAttributesInRange:(NSRange)enumerationRange 
						   options:(NSAttributedStringEnumerationOptions)opts 
						usingBlock:(void (NS_NOESCAPE ^)(NSDictionary<NSString *, id> *attrs,
														 NSRange range, BOOL *stop))block;

- (void)enumerateAttribute:(NSString *)attrName 
				   inRange:(NSRange)enumerationRange 
				   options:(NSAttributedStringEnumerationOptions)opts 
				usingBlock:(void (NS_NOESCAPE ^)(id _Nullable value, NSRange range, BOOL *stop))block;

@end

@interface NSMutableAttributedString : NSAttributedString
/// 替换字符串
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)str;
/// 设置属性
- (void)setAttributes:(nullable NSDictionary<NSString *, id> *)attrs range:(NSRange)range;

@end

@interface NSMutableAttributedString (NSExtendedMutableAttributedString)
/// 可变字符串
@property (readonly, retain) NSMutableString *mutableString;
/// 添加属性
- (void)addAttribute:(NSString *)name value:(id)value range:(NSRange)range;
/// 添加属性
- (void)addAttributes:(NSDictionary<NSString *, id> *)attrs range:(NSRange)range;
/// 删除属性
- (void)removeAttribute:(NSString *)name range:(NSRange)range;
/// 替换属性字符串
- (void)replaceCharactersInRange:(NSRange)range withAttributedString:(NSAttributedString *)attrString;
/// 插入属性字符串
- (void)insertAttributedString:(NSAttributedString *)attrString atIndex:(NSUInteger)loc;
/// 追加属性字符串
- (void)appendAttributedString:(NSAttributedString *)attrString;
/// 删除属性字符串
- (void)deleteCharactersInRange:(NSRange)range;
/// 设置属性字符串
- (void)setAttributedString:(NSAttributedString *)attrString;
/// 开始编辑
- (void)beginEditing;
/// 停止编辑
- (void)endEditing;

@end


#endif /* NSAttributedString_h */
