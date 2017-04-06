//
//  JRTableView.h
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/6.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JRTableView : UITableView

/// 数据源
@property (nonatomic, strong) NSArray	*dataList;

@property (nonatomic, copy) void(^didSelectedCell)(UITableView *tableView, NSIndexPath *indexPath);

@end
