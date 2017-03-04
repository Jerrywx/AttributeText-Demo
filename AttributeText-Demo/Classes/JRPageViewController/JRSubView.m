//
//  JRSubView.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/21.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSubView.h"

@implementation JRSubView

- (instancetype)initWithFrame:(CGRect)frame {
	if (self = [super initWithFrame:frame]) {
		NSLog(@"%zd", self.isAccessibilityElement);
	}
	return self;
}

@end
