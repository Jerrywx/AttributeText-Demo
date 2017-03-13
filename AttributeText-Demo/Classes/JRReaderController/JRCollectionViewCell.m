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
@property (nonatomic, strong) YYLabel	*contentLabel;

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
	self.contentLabel = [[YYLabel alloc] initWithFrame:CGRectMake(0, height,
																  SCREEN_W,
																  SCREEN_H - height * 2)];
	self.contentLabel.numberOfLines = 0;
	__weak JRCollectionViewCell *weakSelf = self;
	self.contentLabel.textLongPressAction = ^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
		
		for (JRHModel *hm in weakSelf.model.array) {
			if (NSLocationInRange(range.location, hm.range)) {
				
				NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithAttributedString:text];
				
				NSDictionary *attri = [text yy_attributesAtIndex:range.location];
				
				UIColor *color = [attri objectForKey:NSForegroundColorAttributeName];
				if ([color isEqual:[UIColor yellowColor]]) {
					/// 被选中
					[aString yy_setColor:[UIColor blackColor] range:hm.range];
				} else {
					/// 未被选中
					[aString yy_setColor:[UIColor yellowColor] range:hm.range];
				}
				
//				NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:weakSelf.model.string];
//				[aString yy_setFont:[UIFont systemFontOfSize:18] range:NSMakeRange(0, weakSelf.model.string.length)];
//				[aString yy_setColor:[UIColor yellowColor] range:hm.range];
				weakSelf.contentLabel.attributedText = aString;
			}
		}
	};
	
	[self.contentView addSubview:self.contentLabel];
}

- (void)setModel:(JRCModel *)model {
	_model = model;
	
	self.contentLabel.attributedText = model.content;
}

/// inferred

@end
