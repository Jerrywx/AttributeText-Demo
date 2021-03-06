//
//  YYImage.h
//  YYImage <https://github.com/ibireme/YYImage>
//
//  Created by ibireme on 14/10/20.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<YYImage/YYImage.h>)
FOUNDATION_EXPORT double YYImageVersionNumber;
FOUNDATION_EXPORT const unsigned char YYImageVersionString[];
#import <YYImage/YYFrameImage.h>
#import <YYImage/YYSpriteSheetImage.h>
#import <YYImage/YYImageCoder.h>
#import <YYImage/YYAnimatedImageView.h>
#elif __has_include(<YYWebImage/YYImage.h>)
#import <YYWebImage/YYFrameImage.h>
#import <YYWebImage/YYSpriteSheetImage.h>
#import <YYWebImage/YYImageCoder.h>
#import <YYWebImage/YYAnimatedImageView.h>
#else
#import "YYFrameImage.h"
#import "YYSpriteSheetImage.h"
#import "YYImageCoder.h"
#import "YYAnimatedImageView.h"
#endif

NS_ASSUME_NONNULL_BEGIN


/**
 A YYImage object is a high-level way to display animated image data.
 
 @discussion It is a fully compatible `UIImage` subclass. It extends the UIImage
 to support animated WebP, APNG and GIF format image data decoding. It also 
 support NSCoding protocol to archive and unarchive multi-frame image data.
 
 If the image is created from multi-frame image data, and you want to play the 
 animation, try replace UIImageView with `YYAnimatedImageView`.
 
 Sample Code:
 
     // animation@3x.webp
     YYImage *image = [YYImage imageNamed:@"animation.webp"];
     YYAnimatedImageView *imageView = [YYAnimatedImageView alloc] initWithImage:image];
     [view addSubView:imageView];
    
 */
@interface YYImage : UIImage <YYAnimatedImage>

+ (nullable YYImage *)imageNamed:(NSString *)name; // no cache!

+ (nullable YYImage *)imageWithContentsOfFile:(NSString *)path;

+ (nullable YYImage *)imageWithData:(NSData *)data;

+ (nullable YYImage *)imageWithData:(NSData *)data scale:(CGFloat)scale;

/// 图片类型
@property (nonatomic, readonly) YYImageType animatedImageType;

/// 图片数据
@property (nullable, nonatomic, readonly) NSData *animatedImageData;

/// 图片占内存大小
@property (nonatomic, readonly) NSUInteger animatedImageMemorySize;

/// 预加载
@property (nonatomic) BOOL preloadAllAnimatedImageFrames;

@end

NS_ASSUME_NONNULL_END
