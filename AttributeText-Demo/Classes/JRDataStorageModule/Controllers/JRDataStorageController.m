//
//  JRDataStorageController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRDataStorageController.h"
#import "JRFMDBController.h"
#import "JRImageManager.h"

@interface JRDataStorageController ()

///
@property (nonatomic, strong) JRFMDBController *fmdbVC;

@property (nonatomic, strong) JRTableView *tableView;

@end

@implementation JRDataStorageController

- (void)viewDidLoad {
    [super viewDidLoad];
	self.view.backgroundColor = [UIColor lightGrayColor];
	
	[self setupUI];
}

- (void)setupUI {
	__weak JRDataStorageController *weakSelf = self;
	self.tableView = [[JRTableView alloc] initWithFrame:self.view.bounds
												  style:UITableViewStyleGrouped];
	
	[self.view addSubview:self.tableView];
	self.tableView.dataList = @[@"数据库", @"ImagePicker", @"zxc"];
	self.tableView.didSelectedCell = ^(UITableView *tableView, NSIndexPath *indexPath) {
		[weakSelf tableDidSelected:tableView indexPath:indexPath];
	};
}

///
- (void)tableDidSelected:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath {
	switch (indexPath.row) {
		case 0: {
			self.fmdbVC = [[JRFMDBController alloc] init];
			[self.navigationController pushViewController:self.fmdbVC animated:YES];
		}
		case 1: {
			[JRImageManager getAllAlbum];
		}
			break;
			
		default:
			break;
	}
}

/// 点击
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
	
	
}


@end
