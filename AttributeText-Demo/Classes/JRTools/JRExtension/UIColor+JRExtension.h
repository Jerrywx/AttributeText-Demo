//
//  UIColor+JRExtension.h
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (JRExtension)

+ (UIColor *)color16WithHexString:(NSString *)color alpha:(float)alpha;

+ (UIColor *)color16WithHexString:(NSString *)color;

+ (UIColor *)colorWithString:(NSString *)colorstr;

@end
