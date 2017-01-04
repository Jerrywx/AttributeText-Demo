//
//  JRCoreFoundationController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/30.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreFoundationController.h"

@interface JRCoreFoundationController ()

@end

@implementation JRCoreFoundationController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"Core Foundation😢!";
	self.view.backgroundColor = [UIColor whiteColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//	[self creatCFString];
//	[self cfDictionary];
	NSLog(@"%@", [self createCFDictionary]);
}

#pragma mark - CFString 
- (void)creatCFString {
	
	// 1. 创建 CFString
//	CFStringRef cfString = CFSTR("这是一个 CFString!");
//	NSLog(@"cfString: %@", cfString);

	
	// 2. CFArrayRef
//	NSString *values[] = {@"hello", @"world"};
//	CFArrayRef arrayRef = CFArrayCreate(kCFAllocatorDefault, (void *)values, (CFIndex)2, NULL);
//	NSArray *array = (__bridge NSArray *)arrayRef;
//	NSData *data = [NSKeyedArchiver archivedDataWithRootObject:array];
//	NSLog(@"%@", array);
//	NSLog(@"%@", data);
//	
//	// 3. CFStringCreateByCombiningStrings
//	CFStringRef m = CFSTR(":!");
//	CFStringRef a = CFStringCreateByCombiningStrings(kCFAllocatorMalloc, arrayRef, m);
//	NSLog(@"==: %@", a);
//
//	//
//	CFStringRef mString = CFSTR("abc_abc_abc_aaa");
//	CFArrayRef ar = CFStringCreateArrayBySeparatingStrings(kCFAllocatorMalloc, mString, CFSTR("_"));
//	array = (__bridge NSArray *)(ar);
//	NSLog(@"ARRAY: %@", array);
	
	char *string = "asdasda";
	NSLog(@"%s", string);
	
}

#pragma mark - CFDictionaryRef

typedef struct {
	void *modelMeta;  ///< _YYModelMeta
	void *model;      ///< id (self)
	void *dictionary; ///< NSDictionary (json)
} ModelSetContext;

- (void)cfDictionary {
	
//	NSDictionary *dict = @{@"title" : @"标题",
//						   @"content": @"内容",
//						   @"other" : @"其他"};
	
	NSDictionary *dict = [self createDict];
	NSLog(@"========== %zd", dict.count);
	
	CFDictionaryRef cfDict = (__bridge CFDictionaryRef)dict;
	NSLog(@"%zd", CFDictionaryGetCount(cfDict));
	
	ModelSetContext context = {0};
	context.modelMeta = (__bridge void *)(@"AAAAA");
	context.model = (__bridge void *)(@"BBBBB");
	context.dictionary = (__bridge void *)(@"CCCCC");
	
	CFTimeInterval end , begin;
	begin = CACurrentMediaTime();
	CFDictionaryApplyFunction(cfDict, ModelSetWithDictionaryFunction, &context);
	end = CACurrentMediaTime();
	printf("%8.4f\n", (end - begin) * 1000);
	
	
	begin = CACurrentMediaTime();
	[dict enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
//		NSLog(@"===%@ %@", key, obj);
	}];
	end = CACurrentMediaTime();
	printf("%8.4f\n", (end - begin) * 1000);
	
	
	begin = CACurrentMediaTime();
	NSArray *keys = [dict allKeys];
	dispatch_apply(keys.count, dispatch_get_global_queue(0, 0), ^(size_t size) {
		NSString *key = keys[size];
		NSString *value = dict[keys];
	});
	end = CACurrentMediaTime();
	printf("%8.4f\n", (end - begin) * 1000);
	
	begin = CACurrentMediaTime();
	NSArray *keys2 = [dict allKeys];
	for (NSString *key in keys2) {
		NSString *value = dict[key];
	}
	end = CACurrentMediaTime();
	printf("%8.4f\n", (end - begin) * 1000);
	
	
	begin = CACurrentMediaTime();
	for (NSString *k in dict) {
		NSString *v = dict[k];
	}
	end = CACurrentMediaTime();
	printf("%8.4f\n", (end - begin) * 1000);
	
}

- (NSDictionary *)createDict {
	
	NSInteger numb = 1000000;
	
	NSMutableDictionary *mDict = [NSMutableDictionary dictionaryWithCapacity:numb];
	
	for (int i = 0; i<numb; ++i) {
		NSString *key	= [NSString stringWithFormat:@"这是 key %zd", i];
		NSString *value = [NSString stringWithFormat:@"这是 value %zd", i];
		[mDict setObject:value forKey:key];
	}
	return mDict;
}

static void ModelSetWithDictionaryFunction(const void *_key, const void *_value, void *_context) {
	
//	ModelSetContext *context = _context;
//	NSLog(@"---%@ %@ %@", _key, _value, context->model);
}

#pragma mark - create
- (CFDictionaryRef)createCFDictionary {
	
	NSString *key[]		= {@"key1", @"key2", @"key3", @"key4", @"key5", @"key7", @"key6"};
	NSString *value[]	= {@"value1",@"value2",@"value3",@"value4",@"value5",@"value6",@"value7"};
	
	CFDictionaryRef cfDict = CFDictionaryCreate(kCFAllocatorDefault,
												(void *)&key,
												(void *)&value,
												7,
												&kCFTypeDictionaryKeyCallBacks,
												&kCFTypeDictionaryValueCallBacks);
	
	/// 获取 key 的出现次数
//	CFIndex len = CFDictionaryGetCountOfKey(cfDict, (void *)@"key5");
	/// 获取 value 的出现次数
//	CFIndex len = CFDictionaryGetCountOfValue(cfDict, (void *)@"value3");
//	NSLog(@"--- %ld",len);
	
	/// 获取是否包含 key
//	Boolean bol = CFDictionaryContainsKey(cfDict, (void *)@"key3");
//	NSLog(@"== %zd", bol);
	
	/// 根据给定 key 获取 value
//	NSString *ss = (NSString *)CFDictionaryGetValue(cfDict, (void *)@"key3");
//	NSLog(@"== %@", ss);

	/// 追加 CFMutableDicyionary
//	CFDictionaryAddValue(cfDict, @"key00", @"value00");
	
	///
	NSString *keys[7];
	NSString *values[7];
	// Implicit conversion of an indirect pointer to an Objective-C pointer to 'const void **' is disallowed with ARC
	CFDictionaryGetKeysAndValues(cfDict, (void *)keys, (void *)values);
	
	for (int i=0; i<7; i++) {
		NSLog(@"keys: %@ - %@", keys[i], values[i]);
	}
	return cfDict;
}



@end




















