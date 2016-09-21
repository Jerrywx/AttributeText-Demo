//
//  JRForumDetialControllerViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/20.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRForumDetialController.h"

@interface JRForumDetialController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView	*tableView;
@end

@implementation JRForumDetialController

- (void)viewDidLoad {
    [super viewDidLoad];

	[self setupView];
}

- (void)setupView {
	
	// 1. 背景色
	self.view.backgroundColor = [UIColor whiteColor];
	
	// 2. tableView
	self.tableView = ({
		CGFloat y = STATUS_H + NAVIGA_H;
		CGFloat h = SCREEN_H - y;
		UITableView *tableView	= [[UITableView alloc] initWithFrame:CGRectMake(0, y, SCREEN_W, h)];
		tableView.delegate		= self;
		tableView.dataSource	= self;
		[tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"ccl"];
		[self.view addSubview:tableView];
		tableView;
	});
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 22;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ccl"];
	cell.textLabel.text = @"ccccc";
	return cell;
}


@end
