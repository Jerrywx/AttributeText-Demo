//
//  JRLayer.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/4/3.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRLayer.h"

@implementation JRLayer

- (void)drawInContext:(CGContextRef)ctx {
	
	//获得当前画板
//	CGContextRef ctx = UIGraphicsGetCurrentContext();
	//颜色
	CGContextSetRGBStrokeColor(ctx, 0.2, 0.2, 0.2, 1.0);
	//画线的宽度
	CGContextSetLineWidth(ctx, 0.25);
	//void CGContextAddArc(CGContextRef c,CGFloat x, CGFloat y,CGFloat radius,CGFloat startAngle,CGFloat endAngle, int clockwise)1弧度＝180°/π （≈57.3°） 度＝弧度×180°/π 360°＝360×π/180 ＝2π 弧度
	// x,y为圆点坐标，radius半径，startAngle为开始的弧度，endAngle为 结束的弧度，clockwise 0为顺时针，1为逆时针。
	CGContextAddArc(ctx, 100, 20, 20, 0, 2*M_PI, 0); //添加一个圆
	CGContextDrawPath(ctx, kCGPathStroke); //绘制路径
	[super drawInContext:ctx];
}

@end
