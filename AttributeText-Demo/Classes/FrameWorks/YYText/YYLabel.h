//
//  YYLabel.h
//  YYText <https://github.com/ibireme/YYText>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#import "YYTextParser.h"
#import "YYTextLayout.h"
#import "YYTextAttribute.h"

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_INTERFACE_BUILDER

/**
 The YYLabel class implements a read-only text view.
 
 @discussion The API and behavior is similar to UILabel, but provides more features:
 
 * It supports asynchronous layout and rendering (to avoid blocking UI thread).
 * It extends the CoreText attributes to support more text effects.
 * It allows to add UIImage, UIView and CALayer as text attachments.
 * It allows to add 'highlight' link to some range of text to allow user interact with.
 * It allows to add container path and exclusion paths to control text container's shape.
 * It supports vertical form layout to display CJK text.
 
 See NSAttributedString+YYText.h for more convenience methods to set the attributes.
 See YYTextAttribute.h and YYTextLayout.h for more information.
 */
@interface YYLabel : UIView <NSCoding>

#pragma mark - Accessing the Text Attributes
///=============================================================================
/// @name Accessing the Text Attributes
///=============================================================================

@property (nullable, nonatomic, copy) NSString *text;

@property (null_resettable, nonatomic, strong) UIFont *font;

@property (null_resettable, nonatomic, strong) UIColor *textColor;

@property (nullable, nonatomic, strong) UIColor *shadowColor;

@property (nonatomic) CGSize shadowOffset;

@property (nonatomic) CGFloat shadowBlurRadius;

@property (nonatomic) NSTextAlignment textAlignment;

@property (nonatomic) YYTextVerticalAlignment textVerticalAlignment;

@property (nullable, nonatomic, copy) NSAttributedString *attributedText;

@property (nonatomic) NSLineBreakMode lineBreakMode;

@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;

@property (nonatomic) NSUInteger numberOfLines;

/// YYTextParser protocol
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;

/// YYTextLayout
@property (nullable, nonatomic, strong) YYTextLayout *textLayout;


#pragma mark - Configuring the Text Container
///=============================================================================
/// @name Configuring the Text Container
///=============================================================================

/// A UIBezierPath object that specifies the shape of the text frame. Default value is nil.
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;

/**
 An array of UIBezierPath objects representing the exclusion paths inside the
 receiver's bounding rectangle. Default value is nil.
 */
@property (nullable, nonatomic, copy) NSArray<UIBezierPath *> *exclusionPaths;

/**
 The inset of the text container's layout area within the text view's content area.
 Default value is UIEdgeInsetsZero.
 */
@property (nonatomic) UIEdgeInsets textContainerInset;

/**
 Whether the receiver's layout orientation is vertical form. Default is NO.
 It may used to display CJK text.
 */
@property (nonatomic, getter=isVerticalForm) BOOL verticalForm;

/**
 The text line position modifier used to modify the lines' position in layout.
 Default value is nil.
 See `YYTextLinePositionModifier` protocol for more information.
 */
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;

/// The default value is [YYTextDebugOption sharedDebugOption].
@property (nullable, nonatomic, copy) YYTextDebugOption *debugOption;


#pragma mark - Getting the Layout Constraints
///=============================================================================
/// @name Getting the Layout Constraints
///=============================================================================

/**
 The preferred maximum width (in points) for a multiline label.
 
 @discussion This property affects the size of the label when layout constraints 
     are applied to it. During layout, if the text extends beyond the width 
     specified by this property, the additional text is flowed to one or more new 
     lines, thereby increasing the height of the label. If the text is vertical 
     form, this value will match to text height.
 */
@property (nonatomic) CGFloat preferredMaxLayoutWidth;


#pragma mark -   with Text Data
///=============================================================================
/// @name Interacting with Text Data
///=============================================================================

@property (nullable, nonatomic, copy) YYTextAction textTapAction;

@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;

@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;

@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;

#pragma mark - Configuring the Display Mode
///=============================================================================
/// @name Configuring the Display Mode
///=============================================================================

/// 异步渲染 默认NO
@property (nonatomic) BOOL displaysAsynchronously;

/// 异步渲染前是否清空内容
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;

/// 异步渲染动画
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;

/// 高亮动画
@property (nonatomic) BOOL fadeOnHighlight;

/// 忽略通用属性 例如:(such as text, font, textColor, attributedText...)
@property (nonatomic) BOOL ignoreCommonProperties;

/*
 Tips:
 
 1. If you only need a UILabel alternative to display rich text and receive link touch event, 
    you do not need to adjust the display mode properties.
 
 2. If you have performance issues, you may enable the asynchronous display mode
    by setting the `displaysAsynchronously` to YES.
 
 3. If you want to get the highest performance, you should do text layout with
    `YYTextLayout` class in background thread. Here's an example:
    
    YYLabel *label = [YYLabel new];
    label.displaysAsynchronously = YES;
    label.ignoreCommonProperties = YES;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
 
        // Create attributed string.
        NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:@"Some Text"];
        text.yy_font = [UIFont systemFontOfSize:16];
        text.yy_color = [UIColor grayColor];
        [text yy_setColor:[UIColor redColor] range:NSMakeRange(0, 4)];
 
        // Create text container
        YYTextContainer *container = [YYTextContainer new];
        container.size = CGSizeMake(100, CGFLOAT_MAX);
        container.maximumNumberOfRows = 0;
        
        // Generate a text layout.
        YYTextLayout *layout = [YYTextLayout layoutWithContainer:container text:text];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            label.size = layout.textBoundingSize;
            label.textLayout = layout;
        });
    });
 
 */

@end


#else // TARGET_INTERFACE_BUILDER
IB_DESIGNABLE
@interface YYLabel : UIView <NSCoding>
@property (nullable, nonatomic, copy) IBInspectable NSString *text;
@property (null_resettable, nonatomic, strong) IBInspectable UIColor *textColor;
@property (nullable, nonatomic, strong) IBInspectable NSString *fontName_;
@property (nonatomic) IBInspectable CGFloat fontSize_;
@property (nonatomic) IBInspectable BOOL fontIsBold_;
@property (nonatomic) IBInspectable NSUInteger numberOfLines;
@property (nonatomic) IBInspectable NSInteger lineBreakMode;
@property (nonatomic) IBInspectable CGFloat preferredMaxLayoutWidth;
@property (nonatomic, getter=isVerticalForm) IBInspectable BOOL verticalForm;
@property (nonatomic) IBInspectable NSInteger textAlignment;
@property (nonatomic) IBInspectable NSInteger textVerticalAlignment;
@property (nullable, nonatomic, strong) IBInspectable UIColor *shadowColor;
@property (nonatomic) IBInspectable CGPoint shadowOffset;
@property (nonatomic) IBInspectable CGFloat shadowBlurRadius;
@property (nullable, nonatomic, copy) IBInspectable NSAttributedString *attributedText;
@property (nonatomic) IBInspectable CGFloat insetTop_;
@property (nonatomic) IBInspectable CGFloat insetBottom_;
@property (nonatomic) IBInspectable CGFloat insetLeft_;
@property (nonatomic) IBInspectable CGFloat insetRight_;
@property (nonatomic) IBInspectable BOOL debugEnabled_;

@property (null_resettable, nonatomic, strong) UIFont *font;
@property (nullable, nonatomic, copy) NSAttributedString *truncationToken;
@property (nullable, nonatomic, strong) id<YYTextParser> textParser;
@property (nullable, nonatomic, strong) YYTextLayout *textLayout;
@property (nullable, nonatomic, copy) UIBezierPath *textContainerPath;
@property (nullable, nonatomic, copy) NSArray<UIBezierPath*> *exclusionPaths;
@property (nonatomic) UIEdgeInsets textContainerInset;
@property (nullable, nonatomic, copy) id<YYTextLinePositionModifier> linePositionModifier;
@property (nonnull, nonatomic, copy) YYTextDebugOption *debugOption;
@property (nullable, nonatomic, copy) YYTextAction textTapAction;
@property (nullable, nonatomic, copy) YYTextAction textLongPressAction;
@property (nullable, nonatomic, copy) YYTextAction highlightTapAction;
@property (nullable, nonatomic, copy) YYTextAction highlightLongPressAction;
@property (nonatomic) BOOL displaysAsynchronously;
@property (nonatomic) BOOL clearContentsBeforeAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnAsynchronouslyDisplay;
@property (nonatomic) BOOL fadeOnHighlight;
@property (nonatomic) BOOL ignoreCommonProperties;
@end
#endif // !TARGET_INTERFACE_BUILDER

NS_ASSUME_NONNULL_END
