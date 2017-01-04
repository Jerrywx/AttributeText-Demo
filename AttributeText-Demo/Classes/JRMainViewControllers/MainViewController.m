//
//  MainViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/9.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "MainViewController.h"
#import "JRCoreFoundationController.h"

@interface MainViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UITableView	*tableView;
@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupView];
}

///
- (void)setupView {

	self.title = @"Example";
	self.view.backgroundColor	= [UIColor whiteColor];
	self.tableView = ({
		UITableView *tableView	= [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds
															  style:UITableViewStyleGrouped];
		tableView.delegate		= self;
		tableView.dataSource	= self;
		[tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
		[self.view addSubview:tableView];
		tableView;
	});
}

#pragma mark - UItableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return 22;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
	
	cell.textLabel.text = @"This is a Cell";
	cell.detailTextLabel.text = @"This is Cell Detail";
	
	return cell;
}

#pragma mark - UItableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	
	if (indexPath.row == 0) {
		JRYYTextViewController *textVC = [[JRYYTextViewController alloc] init];
		[self.navigationController pushViewController:textVC animated:YES];
	} else if (indexPath.row == 1) {
		JRCoreFoundationController *testVC = [JRCoreFoundationController new];
		[self.navigationController pushViewController:testVC animated:YES];
	} else {
		JRCoreTextController *testVC = [JRCoreTextController new];
		[self.navigationController pushViewController:testVC animated:YES];
	}
	
	
}

@end
