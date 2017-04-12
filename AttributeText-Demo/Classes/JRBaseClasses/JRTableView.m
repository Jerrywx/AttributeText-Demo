//
//  JRTableView.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/6.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRTableView.h"

@interface JRTableView () <UITableViewDataSource, UITableViewDelegate>

@end

@implementation JRTableView

- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style {
	
	if (self = [super initWithFrame:frame style:style]) {
		[self commonSetup];
	}
	
	return self;
}

/// 设置
- (void)commonSetup {
	self.dataSource = self;
	self.delegate = self;
	[self registerClass:[UITableViewCell class] forCellReuseIdentifier:@"normalCell"];
}

- (void)setDataList:(NSArray *)dataList {
	_dataList = dataList;
	[self reloadData];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return self.dataList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"normalCell"];
	
	cell.textLabel.text = self.dataList[indexPath.row];
	
	return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	
	if (self.didSelectedCell) {
		self.didSelectedCell(tableView, indexPath);
	}
}

#pragma mark - UItableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
	return 0.1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
	return 0.1;
}

@end
