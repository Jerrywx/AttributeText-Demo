//
//  JRCModel.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2017/2/20.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRCModel.h"
#import "JRHModel.h"

@implementation JRCModel

- (NSString *)description {
	return [NSString stringWithFormat:@"%zd - %zd = %zd", self.pageNumb, self.range.location, self.length];
}

- (void)setContent:(NSAttributedString *)content {
	_content = content;
}

- (void)setString:(NSString *)string {
	_string = string;
	
	NSMutableArray *mArray = [NSMutableArray array];
	NSArray *cc = [string componentsSeparatedByString:@"\n"];
	NSInteger lastLocation = 0;
	for (NSString *c in cc) {
		if ([c stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]].length > 0) {
//			[mArray addObject:c];
			NSRange range = [string rangeOfString:c 
										  options:NSCaseInsensitiveSearch 
											range:NSMakeRange(lastLocation, string.length - lastLocation)];
			lastLocation = range.location + range.length;
			JRHModel *hm = [[JRHModel alloc] init];
			hm.range	= range;
			hm.string	= c;
			[mArray addObject:hm];
//			NSLog(@"%zd - %zd", range.location, range.length);
		}
	}
	self.array = mArray.copy;
//	NSLog(@"---- %@", mArray);
}

@end
