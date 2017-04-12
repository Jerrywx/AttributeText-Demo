//
//  JRAssetsManager.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/12.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRAssetsManager.h"

@implementation JRAssetsManager

+ (instancetype)sharedAssetsManager {
	static JRAssetsManager *instance;
	
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		instance = [JRAssetsManager new];
		instance.albums = [NSMutableArray array];
	});
	
	return instance;
}

@end
