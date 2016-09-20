//
//  JRYYTextViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/19.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRYYTextViewController.h"
#import "TextViewController.h"

@interface JRYYTextViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UITableView	*tableView;
@end

@implementation JRYYTextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
	[self setupView];
}

- (void)setupView {
	
	// 0.
	self.title = @"YYText";

	// 1.
	self.view.backgroundColor = [UIColor whiteColor];
	
	// 2.
	self.tableView = ({
		UITableView *tableView  = [[UITableView alloc] initWithFrame:[UIScreen mainScreen].bounds
															  style:UITableViewStyleGrouped];
		tableView.delegate		= self;
		tableView.dataSource	= self;
		[tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
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
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
	
	cell.textLabel.text = @"This is YYText Cell";
	
	return cell;
}

#pragma mark - UItableVewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	TextViewController *textVC = [[TextViewController alloc] init];
	[self.navigationController pushViewController:textVC animated:YES];
}

@end
