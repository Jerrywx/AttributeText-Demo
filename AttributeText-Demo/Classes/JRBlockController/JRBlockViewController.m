//
//  JRBlockViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRBlockViewController.h"

@interface JRBlockViewController ()

@property (nonatomic, strong) NSArray	*list;

@end

@implementation JRBlockViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	self.view.backgroundColor = [UIColor whiteColor];
}

///
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	[self.list bk_each:^(id obj) {
		NSLog(@"--- %@",obj);
	}];
	
	NSArray *array = @[@"one", @"two", @"three"];
	NSInteger length = array.count;			/// 3
	
	NSString *item = [array objectAtIndex:1];	/// two
	NSString *item2 = array[0];		/// one
	
}

///
- (NSArray *)list {
	
	if (_list) {
		return _list;
	}
	
	_list = @[@"aaa",
			  @"ddd",
			  @"fff",
			  @"eee",
			  @"xxx",
			  @"vvv",
			  @"qqq",
			  @"yyy",
			  @"uuu",
			  @"iii",
			  @"ooo",
			  @"ppp",
			  @"kkk",
			  @"lll",
			  @"jjj",
			  @"mmm",];
	
	return _list;
}


@end
