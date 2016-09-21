//
//  UIColor+JRExtension.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "UIColor+JRExtension.h"

@implementation UIColor (JRExtension)

+ (UIColor *)colorWithString:(NSString *)colorstr{
	NSArray *colors = [colorstr componentsSeparatedByString:@","];
	UIColor *color =  [UIColor colorWithRed:[[colors objectAtIndex:0] floatValue] / 255
									  green:[[colors objectAtIndex:1] floatValue] / 255
									   blue:[[colors objectAtIndex:2] floatValue] / 255
									  alpha:[[colors objectAtIndex:3] floatValue]];
	return color;
}

+ (UIColor *)color16WithHexString:(NSString *)color alpha:(float)alpha {
	
	// 1. 过滤字符串两端的空格
	NSString *cString = [color stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
	// 2. 转小写
	[cString uppercaseString];
	
	// 3. 判断字节数
	if ([cString length] < 6) {
		return [UIColor clearColor];
	}
	
	// 4. 去除头部
	if ([cString hasPrefix:@"0X"])
		cString = [cString substringFromIndex:2];
	if ([cString hasPrefix:@"#"])
		cString = [cString substringFromIndex:1];
	if ([cString length] != 6)
		return [UIColor clearColor];
	
	// Separate into r, g, b substrings
	NSRange range;
	range.location = 0;
	range.length = 2;
	
	//r
	NSString *rString = [cString substringWithRange:range];
	
	//g
	range.location = 2;
	NSString *gString = [cString substringWithRange:range];
	
	//b
	range.location = 4;
	NSString *bString = [cString substringWithRange:range];
	
	// Scan values
	unsigned int r, g, b;
	[[NSScanner scannerWithString:rString] scanHexInt:&r];
	[[NSScanner scannerWithString:gString] scanHexInt:&g];
	[[NSScanner scannerWithString:bString] scanHexInt:&b];
	
	return [UIColor colorWithRed:((float) r / 255.0f) 
						   green:((float) g / 255.0f) 
							blue:((float) b / 255.0f) 
						   alpha:alpha];
}

+ (UIColor *)color16WithHexString:(NSString *)color {
	
	// 1. 过滤字符串两端的空格
	NSString *cString = [color stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
	// 2. 转小写
	[cString uppercaseString];
	
	// 3. 判断字节数
	if ([cString length] < 6) {
		return [UIColor clearColor];
	}
	
	// 4. 去除头部
	if ([cString hasPrefix:@"0X"])
		cString = [cString substringFromIndex:2];
	if ([cString hasPrefix:@"#"])
		cString = [cString substringFromIndex:1];
	if ([cString length] != 6)
		return [UIColor clearColor];
	
	// Separate into r, g, b substrings
	NSRange range;
	range.location = 0;
	range.length = 2;
	
	//r
	NSString *rString = [cString substringWithRange:range];
	
	//g
	range.location = 2;
	NSString *gString = [cString substringWithRange:range];
	
	//b
	range.location = 4;
	NSString *bString = [cString substringWithRange:range];
	
	// Scan values
	unsigned int r, g, b;
	[[NSScanner scannerWithString:rString] scanHexInt:&r];
	[[NSScanner scannerWithString:gString] scanHexInt:&g];
	[[NSScanner scannerWithString:bString] scanHexInt:&b];
	
	return [UIColor colorWithRed:((float) r / 255.0f)
						   green:((float) g / 255.0f)
							blue:((float) b / 255.0f)
						   alpha:1.0];
}

@end
