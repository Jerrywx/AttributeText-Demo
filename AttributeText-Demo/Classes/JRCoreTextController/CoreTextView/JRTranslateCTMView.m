//
//  JRTranslateCTMView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/28.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRTranslateCTMView.h"

@implementation JRTranslateCTMView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
	
	CGContextRef myContext = UIGraphicsGetCurrentContext();
	UIImage *myImage = [UIImage imageNamed:@"ggg"];
	
	// x,y 位置
	CGContextTranslateCTM (myContext, 40, 40);
	//
//	CGContextTranslateCTM (myContext, rect.size.width, rect.size.height);
//	CGContextRotateCTM (myContext, -20);
	//
//	CGContextTranslateCTM(myContext, 0, self.bounds.size.height * 0.5);
//	CGContextScaleCTM(myContext, 1.0, -1.0);
	
	CGContextDrawImage(myContext, rect, [myImage CGImage]);
}


@end
