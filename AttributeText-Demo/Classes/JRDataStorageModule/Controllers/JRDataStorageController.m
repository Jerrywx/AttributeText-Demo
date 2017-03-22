//
//  JRDataStorageController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRDataStorageController.h"
#import "JRFMDBController.h"

@interface JRDataStorageController ()

///
@property (nonatomic, strong) JRFMDBController *fmdbVC;

@end

@implementation JRDataStorageController

- (void)viewDidLoad {
    [super viewDidLoad];
	self.view.backgroundColor = [UIColor lightGrayColor];
	
}

/// 点击
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	self.fmdbVC = [[JRFMDBController alloc] init];
	[self.navigationController pushViewController:self.fmdbVC animated:YES];
}


@end
