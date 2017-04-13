//
//  TextViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/19.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "TextViewController.h"
#import "M80AttributedLabel.h"
#import "JRTextView.h"

@interface TextViewController ()

@property (nonatomic, strong) YYLabel	*label;

//@property (nonatomic, strong) YYLabel	*label2;

@property (nonatomic, strong) M80AttributedLabel *label2;

@property (nonatomic, strong) NSMutableAttributedString *aString;

@property (nonatomic, strong) JRTextView *textView;

@end

@implementation TextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupView];
}

- (void)setupView {
	
	/// YYKit
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
	
	/// M80
	self.label2 = ({
		M80AttributedLabel *label = [[M80AttributedLabel alloc] initWithFrame:CGRectMake(20, 200, SCREEN_W - 40, 50)];
		label.backgroundColor = [UIColor yellowColor];
		[self.view addSubview:label];
		label;
	});
	self.label2.text = @"这是一个测试";
	[self.label2 appendText:@"margin"];
	[self.label2 appendImage:[UIImage imageNamed:@"受惊"] maxSize:CGSizeMake(15, 15) margin:UIEdgeInsetsMake(0, 4, 2, 4)];
	[self.label2 appendText:@"测试结束"];
	
	/// 测试
	self.textView = ({
		JRTextView *view = [[JRTextView alloc] initWithFrame:CGRectMake(20, 320, SCREEN_W - 40, 100)];
		view.backgroundColor = [UIColor yellowColor];
		[self.view addSubview:view];
		view;
	});
	
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	NSMutableDictionary *appendAttributes = [NSMutableDictionary dictionary];
	[appendAttributes setObject:@"111" forKey:@"one"];
	[appendAttributes setObject:@"222" forKey:@"two"];
	[appendAttributes setObject:@[@"one", @"two", @"three"] forKey:@"three"];
	
	
	NSMutableDictionary *a2 = [NSMutableDictionary dictionary];
	[a2 setObject:@"111zzz" forKey:@"one!"];
	[a2 setObject:@"222aaa" forKey:@"two!"];
	[a2 setObject:@[@"one", @"two", @"three"] forKey:@"three!"];
	
	
	NSMutableAttributedString *aString = [[NSMutableAttributedString alloc] initWithString:@"这是一个"
																				attributes:appendAttributes];
	
	NSAttributedString *aString2 = [[NSAttributedString alloc] initWithString:@"测试字符串" attributes:a2];
	
	[aString appendAttributedString:aString2];
	
	NSRange textBlocksArrayRange;
	NSArray *textBlocks = [aString attribute:@"threeqq"
									 atIndex:1
					   longestEffectiveRange:&textBlocksArrayRange
									 inRange:NSMakeRange(0, aString.string.length)];
//	NSLog(@"=== %@ --- %zd %zd", textBlocks, textBlocksArrayRange.location, textBlocksArrayRange.length);
	
	NSDictionary *dic = [aString attributesAtIndex:1 effectiveRange:&textBlocksArrayRange];
	NSLog(@"=== %@ --- %zd %zd", dic, textBlocksArrayRange.location, textBlocksArrayRange.length);
//	NSDictionary *dic2 = [aString attributesAtIndex:6 effectiveRange:&textBlocksArrayRange];
	NSDictionary *dic2 = [aString attributesAtIndex:5 
							  longestEffectiveRange:&textBlocksArrayRange 
											inRange:NSMakeRange(3, 3)];
	NSLog(@"=== %@ --- %zd %zd", dic2, textBlocksArrayRange.location, textBlocksArrayRange.length);
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
