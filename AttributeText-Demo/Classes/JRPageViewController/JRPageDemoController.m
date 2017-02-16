//
//  JRPageDemoController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/16.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRPageDemoController.h"
#import "JRPageViewController.h"

@interface JRPageDemoController ()

@end

@implementation JRPageDemoController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [UIColor yellowColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	JRPageViewController *pageVC = [JRPageViewController new];
	[self.navigationController pushViewController:pageVC animated:YES];
}

@end
