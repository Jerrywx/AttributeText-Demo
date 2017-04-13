//
//  JRCoreAnimationController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/4/3.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCoreAnimationController.h"
#import "JRLayer.h"

@interface JRCoreAnimationController ()

@end

@implementation JRCoreAnimationController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"😀CoreAnimation😎";
	self.view.backgroundColor = [UIColor whiteColor];
	
	
	JRLayer *layer = [JRLayer layer];
	layer.frame = CGRectMake(80, 80, 200, 200);
	layer.backgroundColor = [UIColor yellowColor].CGColor;
	[self.view.layer addSublayer:layer];
	[layer setNeedsDisplay];
	
}

@end
