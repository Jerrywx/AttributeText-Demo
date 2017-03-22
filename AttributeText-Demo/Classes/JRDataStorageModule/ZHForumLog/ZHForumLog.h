//
//  ZHForumLog.h
//  AttributeText-Demo
//
//  Created by wxiao on 2017/3/22.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZHForumLog : NSObject

/**
 保存访问时间戳

 @param bookId 书籍ID
 @return 是否保存成功
 */
+ (BOOL)insertForumLog:(NSString *)bookId;


/**
 读取访问圈子时间戳

 @param bookId 书籍ID
 @return 访问时间戳
 */
+ (NSTimeInterval)getLastTimeWith:(NSString *)bookId;

@end
