//
//  TextViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/19.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "TextViewController.h"

@interface TextViewController ()

@property (nonatomic, strong) YYLabel	*label;

@property (nonatomic, strong) YYLabel	*label2;

@property (nonatomic, strong) NSMutableAttributedString *aString;

@end

@implementation TextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupView];
}

- (void)setupView {
	
	///
	self.label = ({
		YYLabel *label = [[YYLabel alloc] initWithFrame:CGRectMake(20, 80, SCREEN_W - 40, 100)];
		label.textVerticalAlignment = YYTextVerticalAlignmentTop;
		label.displaysAsynchronously = YES;
		label.backgroundColor = [UIColor lightGrayColor];
		[self.view addSubview:label];
		label;
	});
	
	
	YYTextLayout *layout = [YYTextLayout layoutWithContainerSize:CGSizeMake(300, 100) text:self.aString];
	self.label.textLayout = layout;
	
	NSLog(@"%@", NSStringFromCGRect(layout.textBoundingRect));
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:@"An NSAttributedString object manages character strings and associated sets of attributes (for example, font and kerning) that apply to individual characters..."];
	[aString setYy_font:kFontSize_18];
	[aString yy_setColor:[UIColor redColor] range:NSMakeRange(10, 40)];
	self.label.attributedText = aString;
	
	
//	[NSAttributedString attributedStringWithAttachment:<#(nonnull NSTextAttachment *)#>]
//	CFAttributedStringCreate
	
	CFStringRef str = CFSTR("An NSAttributedString object manages character strings and associated sets of attributes (for example, font and kerning) that apply to individual characters...");
	
	CFAttributedStringRef cfaString = CFAttributedStringCreate(kCFAllocatorDefault, str, NULL);
	CFIndex len = CFAttributedStringGetLength(cfaString);
	NSLog(@"==== %zd", len);
	
}

#pragma mark - 

- (NSMutableAttributedString *)aString {
	if (_aString) {
		return _aString;
	}
	
	_aString = [[NSMutableAttributedString alloc] initWithString:@"春来山岙水还凉，看田墒，话农桑。 千里晴川 ，一派菜花黄。 牵牛地头无意过，香欲醉，蕊沾裳。 霞云飞处是家乡，燕成双，柳成行。 风送蛙鸣，荷露小池塘。 遥想年年霜断日，花锦..."];
	
	return _aString;
}



@end
