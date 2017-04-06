//
//  JRCoreViewController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/1/20.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCoreViewController.h"
#import "JRSimpleViewController.h"

@interface JRCoreViewController ()

@property (nonatomic, strong) JRTableView	*tableView;

@end

@implementation JRCoreViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	[self setupUI];
}

#pragma mark -
- (void)setupUI {
	self.title = @"😀Core😎";
	
	__weak JRCoreViewController *weakSelf = self;
	self.tableView = [[JRTableView alloc] initWithFrame:self.view.bounds
												  style:UITableViewStyleGrouped];
	
	[self.view addSubview:self.tableView];
	self.tableView.dataList = @[@"qwe", @"asd", @"zxc"];
	self.tableView.didSelectedCell = ^(UITableView *tableView, NSIndexPath *indexPath) {
		[weakSelf tableDidSelected:tableView indexPath:indexPath];
	};
}

///
- (void)tableDidSelected:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath {

	switch (indexPath.row) {
		case 0: {
			JRSimpleViewController *vc = [JRSimpleViewController new];
			[self.navigationController pushViewController:vc animated:YES];
		}
			break;
			
		default:
			break;
	}
	
}

@end
