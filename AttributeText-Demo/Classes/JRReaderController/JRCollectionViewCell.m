//
//  JRCollectionViewCell.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCollectionViewCell.h"
#import "JRCModel.h"
#import "NSAttributedString+YYText.h"
#import "JRHModel.h"
#import "TYAttributedLabel.h"

@interface JRCollectionViewCell () <TYAttributedLabelDelegate>

@property (nonatomic, strong) UIView	*headerView;
@property (nonatomic, strong) UIView	*footerView;
@property (nonatomic, strong) TYAttributedLabel	*contentLabel;

@end

@implementation JRCollectionViewCell

- (instancetype)initWithFrame:(CGRect)frame {
	self = [super initWithFrame:frame];
	[self setupUI];
	return self;
}

- (void)setupUI {
	
	CGFloat width	= [UIScreen mainScreen].bounds.size.width;
	CGFloat h		= [UIScreen mainScreen].bounds.size.height;
	CGFloat height	= 40;//[UIScreen mainScreen].bounds.size.height;
	
	self.headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, width, height)];
	self.headerView.backgroundColor = [UIColor cz_randomColor];
	
	self.footerView = [[UIView alloc] initWithFrame:CGRectMake(0, h - height, width, height)];
	self.footerView.backgroundColor = [UIColor cz_randomColor];
	
	[self.contentView addSubview:self.headerView];
	[self.contentView addSubview:self.footerView];
	
	////
	self.contentLabel				= [[TYAttributedLabel alloc] initWithFrame:CGRectMake(0, height, 
																						  SCREEN_W, 
																						  SCREEN_H - height * 2)];
	self.contentLabel.numberOfLines = 0;
	self.contentLabel.delegate		= self;
	[self.contentView addSubview:self.contentLabel];
}

- (void)setModel:(JRCModel *)model {
	_model = model;
	
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:self.model.string];
	[aString yy_setFont:[UIFont systemFontOfSize:18] range:NSMakeRange(0, self.model.string.length)];
	[aString yy_setBackgroundColor:[UIColor yellowColor] range:NSMakeRange(20, 200)];
	
	self.contentLabel.attributedText = aString;//model.content;
}

#pragma mark - TYAttributedLabelDelegate
- (void)attributedLabel:(TYAttributedLabel *)attributedLabel 
 textStorageLongPressed:(id<TYTextStorageProtocol>)textStorage 
				onState:(UIGestureRecognizerState)state 
				atPoint:(CGPoint)point {
	
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:self.model.string];
	[aString yy_setFont:[UIFont systemFontOfSize:18] range:NSMakeRange(0, self.model.string.length)];
//	[aString yy_setBackgroundColor:[UIColor yellowColor] range:self.]
	NSLog(@"==== %zd - %zd", point.x, point.y);
	
	
}

- (void)attributedLabel:(TYAttributedLabel *)attributedLabel textStorageClicked:(id<TYTextStorageProtocol>)textStorage atPoint:(CGPoint)point {
	NSLog(@"asdasdasdasdas");
}

@end
