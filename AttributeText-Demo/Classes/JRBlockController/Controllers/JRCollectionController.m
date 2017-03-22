//
//  JRCollectionController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/20.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCollectionController.h"
#import "JRBlockViewController.h"

@interface JRCollectionController () <UITableViewDataSource, UITableViewDelegate>

/// tableView
@property (nonatomic, strong) UITableView   *tableView;
/// dataSource
@property (nonatomic, strong) NSArray   *dataSource;

@end

@implementation JRCollectionController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupUI];
}

/// 设置UI
- (void)setupUI {
    
    self.tableView = ({
        UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds
                                                              style:UITableViewStyleGrouped];
        tableView.delegate = self;
        tableView.dataSource = self;
        [tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
        [self.view addSubview:tableView];
        tableView;
    });
}

#pragma mark -
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    
    cell.textLabel.text = self.dataSource[indexPath.row];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    switch (indexPath.row) {
        case 0: {
            JRBlockViewController *vc = [[JRBlockViewController alloc] init];
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        default:
            break;
    }
}


#pragma mark -
- (NSArray *)dataSource {
    if (_dataSource) {
        return _dataSource;
    }
    
    _dataSource = @[@"普通UICollection",
                    @"普通UICollection2"];
    
    return _dataSource;
}

@end
