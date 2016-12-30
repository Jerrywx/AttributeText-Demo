//
//  JRCoreFoundationController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/30.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreFoundationController.h"

@interface JRCoreFoundationController ()

@end

@implementation JRCoreFoundationController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"Core Foundation😢!";
	self.view.backgroundColor = [UIColor whiteColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	[self creatCFString];
}

#pragma mark - CFString 
- (void)creatCFString {
	
	// 1. 创建 CFString
//	CFStringRef cfString = CFSTR("这是一个 CFString!");
//	NSLog(@"cfString: %@", cfString);

	
	// 2. CFArrayRef
//	NSString *values[] = {@"hello", @"world"};
//	CFArrayRef arrayRef = CFArrayCreate(kCFAllocatorDefault, (void *)values, (CFIndex)2, NULL);
//	NSArray *array = (__bridge NSArray *)arrayRef;
//	NSData *data = [NSKeyedArchiver archivedDataWithRootObject:array];
//	NSLog(@"%@", array);
//	NSLog(@"%@", data);
//	
//	// 3. CFStringCreateByCombiningStrings
//	CFStringRef m = CFSTR(":!");
//	CFStringRef a = CFStringCreateByCombiningStrings(kCFAllocatorMalloc, arrayRef, m);
//	NSLog(@"==: %@", a);
//
//	//
//	CFStringRef mString = CFSTR("abc_abc_abc_aaa");
//	CFArrayRef ar = CFStringCreateArrayBySeparatingStrings(kCFAllocatorMalloc, mString, CFSTR("_"));
//	array = (__bridge NSArray *)(ar);
//	NSLog(@"ARRAY: %@", array);
	
	char *string = "asdasda";
	NSLog(@"%s", string);
	
}


@end




















