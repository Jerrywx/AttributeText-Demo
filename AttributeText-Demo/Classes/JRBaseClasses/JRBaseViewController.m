//
//  JRBaseViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/9.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRBaseViewController.h"

@interface JRBaseViewController () 

@end

@implementation JRBaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	self.view.backgroundColor = [UIColor whiteColor];
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
	return 0.1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
	return 0.1;
}


@end
