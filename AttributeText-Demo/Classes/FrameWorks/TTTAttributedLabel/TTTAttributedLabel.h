// TTTAttributedLabel.h
//
// Copyright (c) 2011 Mattt Thompson (http://mattt.me)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

//! Project version number for TTTAttributedLabel.
FOUNDATION_EXPORT double TTTAttributedLabelVersionNumber;

//! Project version string for TTTAttributedLabel.
FOUNDATION_EXPORT const unsigned char TTTAttributedLabelVersionString[];

@class TTTAttributedLabelLink;

/// 垂直对齐方式
typedef NS_ENUM(NSInteger, TTTAttributedLabelVerticalAlignment) {
    TTTAttributedLabelVerticalAlignmentCenter   = 0,
    TTTAttributedLabelVerticalAlignmentTop      = 1,
    TTTAttributedLabelVerticalAlignmentBottom   = 2,
};

/**
 Determines whether the text to which this attribute applies has a strikeout drawn through itself.
 */
extern NSString * const kTTTStrikeOutAttributeName;

/**
 The background fill color. Value must be a `CGColorRef`. Default value is `nil` (no fill).
 */
extern NSString * const kTTTBackgroundFillColorAttributeName;

/**
 The padding for the background fill. Value must be a `UIEdgeInsets`. Default value is `UIEdgeInsetsZero` (no padding).
 */
extern NSString * const kTTTBackgroundFillPaddingAttributeName;

/**
 The background stroke color. Value must be a `CGColorRef`. Default value is `nil` (no stroke).
 */
extern NSString * const kTTTBackgroundStrokeColorAttributeName;

/**
 The background stroke line width. Value must be an `NSNumber`. Default value is `1.0f`.
 */
extern NSString * const kTTTBackgroundLineWidthAttributeName;

/**
 The background corner radius. Value must be an `NSNumber`. Default value is `5.0f`.
 */
extern NSString * const kTTTBackgroundCornerRadiusAttributeName;

@protocol TTTAttributedLabelDelegate;

// Override UILabel @property to accept both NSString and NSAttributedString
@protocol TTTAttributedLabel <NSObject>
@property (nonatomic, copy) IBInspectable id text;
@end

IB_DESIGNABLE

/**
 `TTTAttributedLabel` is a drop-in replacement for `UILabel` that supports `NSAttributedString`, as well as automatically-detected and manually-added links to URLs, addresses, phone numbers, and dates.
 
 ## Differences Between `TTTAttributedLabel` and `UILabel`
 
 For the most part, `TTTAttributedLabel` behaves just like `UILabel`. The following are notable exceptions, in which `TTTAttributedLabel` may act differently:
 
 - `text` - This property now takes an `id` type argument, which can either be a kind of `NSString` or `NSAttributedString` (mutable or immutable in both cases)
 - `attributedText` - Do not set this property directly. Instead, pass an `NSAttributedString` to `text`.
 - `lineBreakMode` - This property displays only the first line when the value is `UILineBreakModeHeadTruncation`, `UILineBreakModeTailTruncation`, or `UILineBreakModeMiddleTruncation`
 - `adjustsFontsizeToFitWidth` - Supported in iOS 5 and greater, this property is effective for any value of `numberOfLines` greater than zero. In iOS 4, setting `numberOfLines` to a value greater than 1 with `adjustsFontSizeToFitWidth` set to `YES` may cause `sizeToFit` to execute indefinitely.
 - `baselineAdjustment` - This property has no affect.
 - `textAlignment` - This property does not support justified alignment.
 - `NSTextAttachment` - This string attribute is not supported.
 
 Any properties affecting text or paragraph styling, such as `firstLineIndent` will only apply when text is set with an `NSString`. If the text is set with an `NSAttributedString`, these properties will not apply.
 
 ### NSCoding
 
 `TTTAttributedLabel`, like `UILabel`, conforms to `NSCoding`. However, if the build target is set to less than iOS 6.0, `linkAttributes` and `activeLinkAttributes` will not be encoded or decoded. This is due to an runtime exception thrown when attempting to copy non-object CoreText values in dictionaries.
 
 @warning Any properties changed on the label after setting the text will not be reflected until a subsequent call to `setText:` or `setText:afterInheritingLabelAttributesAndConfiguringWithBlock:`. This is to say, order of operations matters in this case. For example, if the label text color is originally black when the text is set, changing the text color to red will have no effect on the display of the label until the text is set once again.
 
 @bug Setting `attributedText` directly is not recommended, as it may cause a crash when attempting to access any links previously set. Instead, call `setText:`, passing an `NSAttributedString`.
 */
@interface TTTAttributedLabel : UILabel <TTTAttributedLabel, UIGestureRecognizerDelegate>

- (instancetype) init NS_UNAVAILABLE;

///-----------------------------
/// @name Accessing the Delegate
///-----------------------------

/// The receiver's delegate.
@property (nonatomic, unsafe_unretained) IBOutlet id <TTTAttributedLabelDelegate> delegate;

///--------------------------------------------
/// @name Detecting, Accessing, & Styling Links
///--------------------------------------------

/// 类型
@property (nonatomic, assign) NSTextCheckingTypes enabledTextCheckingTypes;
/// NSTextCheckingResult 链接数组
@property (readonly, nonatomic, strong) NSArray *links;
/// 链接属性
@property (nonatomic, strong) NSDictionary *linkAttributes;

@property (nonatomic, strong) NSDictionary *activeLinkAttributes;

@property (nonatomic, strong) NSDictionary *inactiveLinkAttributes;

@property (nonatomic, assign) UIEdgeInsets linkBackgroundEdgeInset;

/**
 Indicates if links will be detected within an extended area around the touch
 to emulate the link detection behaviour of UIWebView. 
 Default value is NO. Enabling this may adversely impact performance.
 */
@property (nonatomic, assign) BOOL extendsLinkTouchArea;

///---------------------------------------
/// @name Acccessing Text Style Attributes
///---------------------------------------

/// 影子
@property (nonatomic, assign) IBInspectable CGFloat shadowRadius;
@property (nonatomic, assign) IBInspectable CGFloat highlightedShadowRadius;
@property (nonatomic, assign) IBInspectable CGSize highlightedShadowOffset;
@property (nonatomic, strong) IBInspectable UIColor *highlightedShadowColor;

/// 字间距
@property (nonatomic, assign) IBInspectable CGFloat kern;

///--------------------------------------------
/// @name Acccessing Paragraph Style Attributes
///--------------------------------------------

/// 首行缩进
@property (nonatomic, assign) IBInspectable CGFloat firstLineIndent;

/// 行间距
@property (nonatomic, assign) IBInspectable CGFloat lineSpacing;

/// 最小行高度
@property (nonatomic, assign) IBInspectable CGFloat minimumLineHeight;

/// 最大行高度
@property (nonatomic, assign) IBInspectable CGFloat maximumLineHeight;

/**
 The line height multiple. This value is 1.0 by default.
 */
@property (nonatomic, assign) IBInspectable CGFloat lineHeightMultiple;

/**
 The distance, in points, from the margin to the text container. This value is `UIEdgeInsetsZero` by default.
 sizeThatFits: will have its returned size increased by these margins.
 drawTextInRect: will inset all drawn text by these margins.
 */
@property (nonatomic, assign) IBInspectable UIEdgeInsets textInsets;

/// 垂直对齐方式
@property (nonatomic, assign) TTTAttributedLabelVerticalAlignment verticalAlignment;

///--------------------------------------------
/// @name Accessing Truncation Token Appearance
///--------------------------------------------

/**
 The attributed string to apply to the truncation token at the end of a truncated line. Overrides `truncationTokenStringAttributes` and `truncationTokenString`. If unspecified, attributes will fallback to `truncationTokenStringAttributes` and `truncationTokenString`.
 */
@property (nonatomic, strong) IBInspectable NSAttributedString *attributedTruncationToken;

///--------------------------
/// @name Long press gestures
///--------------------------

/**
 *  The long-press gesture recognizer used internally by the label.
 */
@property (nonatomic, strong, readonly) UILongPressGestureRecognizer *longPressGestureRecognizer;

///--------------------------------------------
/// @name Calculating Size of Attributed String
///--------------------------------------------

/**
 Calculate and return the size that best fits an attributed string, given the specified constraints on size and number of lines.

 @param attributedString The attributed string.
 @param size The maximum dimensions used to calculate size.
 @param numberOfLines The maximum number of lines in the text to draw, if the constraining size cannot accomodate the full attributed string.
 
 @return The size that fits the attributed string within the specified constraints.
 */
+ (CGSize)sizeThatFitsAttributedString:(NSAttributedString *)attributedString
                       withConstraints:(CGSize)size
                limitedToNumberOfLines:(NSUInteger)numberOfLines;

///----------------------------------
/// @name Setting the Text Attributes
///----------------------------------
/// 设置文本
- (void)setText:(id)text;
/// 设置文本
- (void)setText:(id)text
afterInheritingLabelAttributesAndConfiguringWithBlock:(NSMutableAttributedString *(^)(NSMutableAttributedString *mutableAttributedString))block;

///------------------------------------
/// @name Accessing the Text Attributes
///------------------------------------
/// 属性字符串
@property (readwrite, nonatomic, copy) NSAttributedString *attributedText;

///-------------------
/// @name Adding Links
///-------------------

/// 添加链接
- (void)addLink:(TTTAttributedLabelLink *)link;

/// Adds a link to an @c NSTextCheckingResult.
- (TTTAttributedLabelLink *)addLinkWithTextCheckingResult:(NSTextCheckingResult *)result;

/// Adds a link to an @c NSTextCheckingResult.
- (TTTAttributedLabelLink *)addLinkWithTextCheckingResult:(NSTextCheckingResult *)result
                                               attributes:(NSDictionary *)attributes;
/// 添加url
- (TTTAttributedLabelLink *)addLinkToURL:(NSURL *)url
                               withRange:(NSRange)range;
/// 添加地址
- (TTTAttributedLabelLink *)addLinkToAddress:(NSDictionary *)addressComponents
                                   withRange:(NSRange)range;

/// 添加号码
- (TTTAttributedLabelLink *)addLinkToPhoneNumber:(NSString *)phoneNumber
                                       withRange:(NSRange)range;

/// 添加时间
- (TTTAttributedLabelLink *)addLinkToDate:(NSDate *)date
                                withRange:(NSRange)range;
/// 添加时间
- (TTTAttributedLabelLink *)addLinkToDate:(NSDate *)date
                                 timeZone:(NSTimeZone *)timeZone
                                 duration:(NSTimeInterval)duration
                                withRange:(NSRange)range;
///
- (TTTAttributedLabelLink *)addLinkToTransitInformation:(NSDictionary *)components
                                              withRange:(NSRange)range;

/// 检测是否有链接
- (BOOL)containslinkAtPoint:(CGPoint)point;

/// 根据点获取链接
- (TTTAttributedLabelLink *)linkAtPoint:(CGPoint)point;

@end

/// 点击链接代理
@protocol TTTAttributedLabelDelegate <NSObject>

///-----------------------------------
/// @name Responding to Link Selection
///-----------------------------------
@optional

/// 点击链接代理
- (void)attributedLabel:(TTTAttributedLabel *)label didSelectLinkWithURL:(NSURL *)url;

/// 点击地址代理
- (void)attributedLabel:(TTTAttributedLabel *)label didSelectLinkWithAddress:(NSDictionary *)addressComponents;

/// 点击电话代理
- (void)attributedLabel:(TTTAttributedLabel *)label didSelectLinkWithPhoneNumber:(NSString *)phoneNumber;

/// 点击时间代理
- (void)attributedLabel:(TTTAttributedLabel *)label didSelectLinkWithDate:(NSDate *)date;

/**
 Tells the delegate that the user did select a link to a date with a time zone and duration.
 
 @param label The label whose link was selected.
 @param date The date for the selected link.
 @param timeZone The time zone of the date for the selected link.
 @param duration The duration, in seconds from the date for the selected link.
 */
- (void)attributedLabel:(TTTAttributedLabel *)label
  didSelectLinkWithDate:(NSDate *)date
               timeZone:(NSTimeZone *)timeZone
               duration:(NSTimeInterval)duration;

/**
 Tells the delegate that the user did select a link to transit information

 @param label The label whose link was selected.
 @param components A dictionary containing the transit components. The currently supported keys are `NSTextCheckingAirlineKey` and `NSTextCheckingFlightKey`.
 */
- (void)attributedLabel:(TTTAttributedLabel *)label
didSelectLinkWithTransitInformation:(NSDictionary *)components;

/**
 Tells the delegate that the user did select a link to a text checking result.
 
 @discussion This method is called if no other delegate method was called, which can occur by either now implementing the method in `TTTAttributedLabelDelegate` corresponding to a particular link, or the link was added by passing an instance of a custom `NSTextCheckingResult` subclass into `-addLinkWithTextCheckingResult:`.
 
 @param label The label whose link was selected.
 @param result The custom text checking result.
 */
- (void)attributedLabel:(TTTAttributedLabel *)label
didSelectLinkWithTextCheckingResult:(NSTextCheckingResult *)result;

///---------------------------------
/// @name Responding to Long Presses
///---------------------------------

/// 长按链接
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithURL:(NSURL *)url
                atPoint:(CGPoint)point;

/// 长按地址
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithAddress:(NSDictionary *)addressComponents
                atPoint:(CGPoint)point;

/// 长按号码
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithPhoneNumber:(NSString *)phoneNumber
                atPoint:(CGPoint)point;

//// 长按时间
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithDate:(NSDate *)date
                atPoint:(CGPoint)point;
///
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithDate:(NSDate *)date
               timeZone:(NSTimeZone *)timeZone
               duration:(NSTimeInterval)duration
                atPoint:(CGPoint)point;

/**
 Tells the delegate that the user long-pressed a link to transit information.
 
 @param label The label whose link was long pressed.
 @param components A dictionary containing the transit components. The currently supported keys are `NSTextCheckingAirlineKey` and `NSTextCheckingFlightKey`.
 @param point the point pressed, in the label's coordinate space
 */
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithTransitInformation:(NSDictionary *)components
                atPoint:(CGPoint)point;

/**
 Tells the delegate that the user long-pressed a link to a text checking result.
 
 @discussion Similar to `-attributedLabel:didSelectLinkWithTextCheckingResult:`, this method is called if a link is long pressed and the delegate does not implement the method corresponding to this type of link.
 
 @param label The label whose link was long pressed.
 @param result The custom text checking result.
 @param point the point pressed, in the label's coordinate space
 */
- (void)attributedLabel:(TTTAttributedLabel *)label
didLongPressLinkWithTextCheckingResult:(NSTextCheckingResult *)result
                atPoint:(CGPoint)point;

@end

/// 链接类
@interface TTTAttributedLabelLink : NSObject <NSCoding>

typedef void (^TTTAttributedLabelLinkBlock) (TTTAttributedLabel *, TTTAttributedLabelLink *);
/// 类型 链接、电话....
@property (readonly, nonatomic, strong) NSTextCheckingResult *result;
/// 链接属性
@property (readonly, nonatomic, copy) NSDictionary *attributes;
/// 点击属性
@property (readonly, nonatomic, copy) NSDictionary *activeAttributes;
/// 不活跃属性
@property (readonly, nonatomic, copy) NSDictionary *inactiveAttributes;
/// 显示文字
@property (nonatomic, copy) NSString *accessibilityValue;
/// 点击事件
@property (nonatomic, copy) TTTAttributedLabelLinkBlock linkTapBlock;
/// 长按事件
@property (nonatomic, copy) TTTAttributedLabelLinkBlock linkLongPressBlock;

/// 初始化
- (instancetype)initWithAttributes:(NSDictionary *)attributes
                  activeAttributes:(NSDictionary *)activeAttributes
                inactiveAttributes:(NSDictionary *)inactiveAttributes
                textCheckingResult:(NSTextCheckingResult *)result;

/// 初始化
- (instancetype)initWithAttributesFromLabel:(TTTAttributedLabel*)label
                         textCheckingResult:(NSTextCheckingResult *)result;

@end
