//
//  JRCModel.h
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/20.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JRCModel : NSObject

@property (nonatomic, assign) NSInteger pageNumb;

@property (nonatomic, strong) NSString	*string;

@property (nonatomic, strong) NSAttributedString *content;

@property (nonatomic, assign) NSInteger	length;

@property (nonatomic, assign) NSRange	range;

/// 选择
@property (nonatomic, strong) NSArray	*array;


@end
