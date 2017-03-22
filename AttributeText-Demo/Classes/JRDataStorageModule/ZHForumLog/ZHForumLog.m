//
//  ZHForumLog.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/3/22.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "ZHForumLog.h"
#define FORUMLOG	@"formLog.db"

@interface ZHForumLog ()

/// 数据库
@property (nonatomic, strong) FMDatabase	*db;
/// 数据库名字
@property (nonatomic, strong) NSString	*forumLog;

@end

@implementation ZHForumLog

/// 创建数据库
+ (FMDatabase *)openForumTable {
	
	NSString *path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).lastObject;
	NSString *sqlFilePath = [path stringByAppendingPathComponent:FORUMLOG];
	
	// 1.通过路径创建数据库
	FMDatabase *db = [FMDatabase databaseWithPath:sqlFilePath];
	
	// 2.打开数据库
	if ([db open]) {
		BOOL success = [db executeUpdate:@"CREATE TABLE IF NOT EXISTS t_forumLog (id INTEGER PRIMARY KEY AUTOINCREMENT, bookId TEXT NOT NULL, lastTime INTEGER NOT NULL)"];
		if (success) {
			return db;
		} else {
			return nil;
		}
	} else {
		return nil;
	}
}

/// 插入数据
+ (BOOL)insertForumLog:(NSString *)bookId {
	
	FMDatabase *db = [ZHForumLog openForumTable];
	
	if (!db) {
		return NO;
	}
	
	long long int time = [[NSDate date] timeIntervalSince1970] * 1000;
	
	// 删除数据
	NSString *delSql = [NSString stringWithFormat:@"DELETE FROM t_forumLog WHERE bookId == '%@';", bookId];
	[db executeUpdate:delSql];
	
	NSString *sqlString = [NSString stringWithFormat:@"INSERT INTO t_forumLog (booId, lastTime) VALUES ('%@', %lld);", bookId, time];
	BOOL success = [db executeUpdate:sqlString];
	
	[self deleteForumLog:db];
	
	[db close];
	return success;
}

/// 查询数据
+ (NSTimeInterval)getLastTimeWith:(NSString *)bookId {
	
	FMDatabase *db = [ZHForumLog openForumTable];
	
	if (!db) {
		return 0;
	}
	
	// 查询数据
	NSString *sqlString = [NSString stringWithFormat:@"SELECT booId, lastTime FROM t_forumLog WHERE booId == '%@';", bookId];
	
	FMResultSet *result = [db executeQuery:sqlString];
	
	while ([result next]) {
		int ID = [result intForColumnIndex:0];
		NSString *book = [result stringForColumnIndex:1];
		long long int time = [result  longLongIntForColumn:@"lastTime"];
		NSLog(@"ID: %zd, name: %@, age: %lld", ID, book, time);
		if ([book isEqualToString:bookId]) {
			[db close];
			return time;
		}
	}
	
	[db close];
	return 0;
}

/// 清理数据库
+ (void)deleteForumLog:(FMDatabase *)db {
	
	long long int now = [[NSDate date] timeIntervalSince1970] * 1000;
	/// 15天: 15 * 24 * 60 * 60 * 100
	/// 测试 20秒: 30 * 1000
	//	long long int limit = now - 15 * 24 * 60 * 60 * 1000;
	long long int limit = now - 60 * 1000;
	
	// 删除数据
	NSString *sqlString = [NSString stringWithFormat:@"DELETE FROM t_forumLog WHERE lastTime <= %lld;", limit];
	NSLog(@"----删除: %@", sqlString);
	BOOL success = [db executeUpdate:sqlString];
	
	if (success) {
		NSLog(@"清理数据成功");
	} else {
		NSLog(@"清理数据失败");
	}
}

@end
