//
//  JRTranslateCTMView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/28.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRTranslateCTMView.h"

static inline double radians (double degrees) {return degrees * M_PI/180;}

@implementation JRTranslateCTMView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	CGContextRef myContext = UIGraphicsGetCurrentContext();
	UIImage *myImage = [UIImage imageNamed:@"qqq"];
	
	// 平移
//	CGContextTranslateCTM (myContext, rect.size.width * 0.5, rect.size.height * 0.5);
	// 旋转
//	CGContextRotateCTM (myContext, radians(-90));
	// 缩放
//	CGContextScaleCTM(myContext, 0.5, 0.5);
	// 仿射矩阵
//	CGContextConcatCTM(myContext, <#CGAffineTransform transform#>)

	// 缩放绘制
	CGContextDrawImage(myContext, rect, [myImage CGImage]);
	// 旋转绘制
//	CGContextDrawImage(myContext,
//					   CGRectMake(0, 0, rect.size.width * 0.25, rect.size.height * 0.25),
//					   [myImage CGImage]);
}


@end
