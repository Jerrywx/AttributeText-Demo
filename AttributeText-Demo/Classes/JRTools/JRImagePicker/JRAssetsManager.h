//
//  JRAssetsManager.h
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/12.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JRAssetsManager : NSObject

@property (nonatomic, strong) NSMutableArray	*albums;

+ (instancetype)sharedAssetsManager;

@end
