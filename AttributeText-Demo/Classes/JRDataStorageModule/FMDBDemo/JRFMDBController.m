//
//  JRFMDBController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/3/13.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRFMDBController.h"

@interface JRFMDBController ()

/// 创建表按钮
@property (nonatomic, strong) UIButton *createBtn;

/// 插入数据
@property (nonatomic, strong) UIButton	*insertData;
/// 更新数据
@property (nonatomic, strong) UIButton	*updateBtn;
/// 更新数据
@property (nonatomic, strong) UIButton	*updateBtn2;
/// 查询数据
@property (nonatomic, strong) UIButton	*searchData;
/// 清理数据
@property (nonatomic, strong) UIButton	*deleteBtn;

//// 数据库
@property (nonatomic, strong) FMDatabase *db;

@end

@implementation JRFMDBController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.view.backgroundColor = [UIColor wheatColor];
	
	CGFloat w = SCREEN_W / 4;
	
	////
	self.createBtn = [self createButton:@"创建表"];
	self.createBtn.center = CGPointMake(w, 100);
	[self.createBtn addTarget:self action:@selector(createAct) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.insertData = [self createButton:@"插入数据"];
	self.insertData.center = CGPointMake(SCREEN_W - w, 100);
	[self.insertData addTarget:self action:@selector(insertAct) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.updateBtn = [self createButton:@"更新数据"];
	self.updateBtn.center = CGPointMake(w, 150);
	[self.updateBtn addTarget:self action:@selector(updateAct) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.updateBtn2 = [self createButton:@"更新数据2"];
	self.updateBtn2.center = CGPointMake(SCREEN_W - w, 150);
	[self.updateBtn2 addTarget:self action:@selector(updateAct2) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.searchData = [self createButton:@"查询数据"];
	self.searchData.center = CGPointMake(w, 200);
	[self.searchData addTarget:self action:@selector(searchAct) forControlEvents:UIControlEventTouchUpInside];
	
	///
	self.deleteBtn = [self createButton:@"清理数据"];
	self.deleteBtn.center = CGPointMake(SCREEN_W - w, 200);
	[self.deleteBtn addTarget:self action:@selector(deleteForumLog) forControlEvents:UIControlEventTouchUpInside];
}

#pragma mark - SqLite Methond
/// 创建表
- (void)createAct {
	
	long long int interval = [[NSDate date] timeIntervalSince1970] * 1000;
	NSLog(@"---- ：：： %lld", interval);
	if ([self createForumTable]) {
		NSLog(@"创建表成功");
	} else {
		NSLog(@"创建表失败");
	}
}
/// 插入数据
- (void)insertAct {
	
	long long int interval = [[NSDate date] timeIntervalSince1970] * 1000;
	
	NSLog(@"---插入数据: %lld", interval);
	if ([self insertForumLog:@"qwe" lastTime:interval]) {
		NSLog(@"插入成功");
	} else {
		NSLog(@"插入数据失败");
	}
}
/// 更新表数据
- (void)updateAct {
	if ([self updateForumLog:@"圈子" lastTime:@"123213123"]) {
		NSLog(@"跟新成功");
	} else {
		NSLog(@"跟新失败");
	}
}
/// 更新表数据
- (void)updateAct2 {
	if ([self updateForumLog:@"圈子sss" lastTime:@"123213123"]) {
		NSLog(@"跟新成功");
	} else {
		NSLog(@"跟新失败");
	}
}
/// 查询数据
- (void)searchAct {
	[self getLastTimeWith:@"qwe"];
}

#pragma mark - FMDB Methond
/// 创建数据库和表
- (BOOL)createForumTable {
	
	NSString *path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).lastObject;
	NSString *sqlFilePath = [path stringByAppendingPathComponent:@"formLog.db"];
	
	// 1.通过路径创建数据库
	self.db = [FMDatabase databaseWithPath:sqlFilePath];
	
	// 2.打开数据库
	if ([self.db open]) {
	
		BOOL success = [self.db executeUpdate:@"CREATE TABLE IF NOT EXISTS t_forumLog (id INTEGER PRIMARY KEY AUTOINCREMENT, booId TEXT NOT NULL, lastTime INTEGER NOT NULL)"];
		
		return success;
	} else {
		return NO;
	}
}
/// 插入数据
- (BOOL)insertForumLog:(NSString *)bookId lastTime:(NSTimeInterval)time {
	
	if (![self createForumTable]) {
		return NO;
	}
	
	NSString *sqlString = [NSString stringWithFormat:@"INSERT INTO t_forumLog (booId, lastTime) VALUES ('%@', %f);", bookId, time];
	BOOL success = [self.db executeUpdate:sqlString];

	return success;
}
/// 更新数据
- (BOOL)updateForumLog:(NSString *)bookId lastTime:(NSString *)time {
	
	// 修改数据
	NSString *sqlString = [NSString stringWithFormat:@"UPDATE t_forumLog SET lastTime = '%@' WHERE booId == '%@';", time, bookId];

	BOOL success = [self.db executeUpdate:sqlString];
	
	return success;
}

/// 查询数据
- (NSTimeInterval)getLastTimeWith:(NSString *)bookId {
	
	// 查询数据
	NSString *sqlString = [NSString stringWithFormat:@"SELECT booId, lastTime FROM t_forumLog WHERE booId == '%@';", bookId];

	FMResultSet *result = [self.db executeQuery:sqlString];
	
	while ([result next]) {
		int ID = [result intForColumnIndex:0];
		NSString *book = [result stringForColumnIndex:1];
		long long int time = [result  longLongIntForColumn:@"lastTime"];
		NSLog(@"ID: %zd, name: %@, age: %lld", ID, book, time);
		if ([book isEqualToString:bookId]) {
			return time;
		}
	}
	
	return 0;
}

///
- (void)deleteForumLog {
	
	long long int now = [[NSDate date] timeIntervalSince1970] * 1000;
	/// 15天: 15 * 24 * 60 * 60 * 100
	/// 测试 20秒: 30 * 1000
//	long long int limit = now - 15 * 24 * 60 * 60 * 1000;
	long long int limit = now - 60 * 1000;
	
	// 删除数据
	NSString *sqlString = [NSString stringWithFormat:@"DELETE FROM t_forumLog WHERE lastTime <= %lld;", limit];
	NSLog(@"----删除: %@", sqlString);
	BOOL success = [self.db executeUpdate:sqlString];
	
	if (success) {
		NSLog(@"清理数据成功");
	} else {
		NSLog(@"清理数据失败");
	}
}

#pragma mark - Private Methond
/// 创建按钮
- (UIButton *)createButton:(NSString *)title {
	UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 80, 30)];
	[button setTitle:title forState:UIControlStateNormal];
	[button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
	button.titleLabel.font		= kFontSize_14;
	button.layer.borderColor	= [UIColor charcoalColor].CGColor;
	button.layer.borderWidth	= 1;
	button.layer.cornerRadius	= 2;
	[self.view addSubview:button];
	return button;
}

@end
