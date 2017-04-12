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
@property (nonatomic, strong) NSArray		*dataList;

@end

@implementation JRYYTextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	[self setupView];
}

- (void)setupView {

	self.title = @"YYText";
	self.view.backgroundColor	= [UIColor whiteColor];
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
	return self.dataList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];

	NSDictionary *dict = self.dataList[indexPath.row];
	cell.textLabel.text = dict[@"title"];
	
	return cell;
}

#pragma mark - UItableVewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {

	// 1. 设置 cell 点击动画
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
	
	// 2. 获取控制器类名
	NSDictionary *dict = self.dataList[indexPath.row];
	NSString *conName = dict[@"controller"];
	
	// 3. 创建控制器
	Class class = NSClassFromString(conName);
	UIViewController *controller = [class new];
	
	// 4. 跳转控制器
	[self.navigationController pushViewController:controller animated:YES];
}

#pragma mark - Lazy Loading
- (NSArray *)dataList {
	
	if (_dataList) {
		return _dataList;
	}
	
	_dataList = @[
				  @{@"title"		: @"YYText使用" ,
					@"controller"	: @"JRTextDemoViewController"},
				  @{@"title"		: @"YYLabel-Demo" ,
					@"controller"	: @"TextViewController"},
				  @{@"title"		: @"文字排版",
					@"controller"	: @"JRTextViewViewController"},
				  @{@"title"		: @"AAAA",
					@"controller"	: @"JRForumDetialController"},
				  @{@"title"		: @"BBBB",
					@"controller"	: @"JRThreadDetialController"},
				  @{@"title"		: @"Core_Image",
					@"controller"	: @"JRCoreImageController"},
				  ];
	
	return _dataList;
}

@end
