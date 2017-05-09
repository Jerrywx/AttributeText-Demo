//
//  JRCollectionViewCell.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/26.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCollectionViewCell2.h"

@interface JRCollectionViewCell2 ()

@property (nonatomic, strong) UILabel *label;

@end

@implementation JRCollectionViewCell2

- (instancetype)initWithFrame:(CGRect)frame {
	
	if (self = [super initWithFrame:frame]) {
		
		self.label = [[UILabel alloc] initWithFrame:[UIScreen mainScreen].bounds];
		[self.contentView addSubview:self.label];
		self.label.font = [UIFont systemFontOfSize:40];
		self.label.textColor = [UIColor redColor];
		self.label.textAlignment = NSTextAlignmentCenter;
		
	}
	return self;
}

- (void)setCon:(NSString *)con {
	self.label.text = con;
}


@end
