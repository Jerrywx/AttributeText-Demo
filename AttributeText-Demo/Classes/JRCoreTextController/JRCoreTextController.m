//
//  JRCoreTextController.m
//  AttributeText-Demo
//
//  Created by 王潇 on 2016/12/26.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "JRCoreTextController.h"
#import "JRCoreTextView.h"
#import "JRParagraphView.h"



@interface JRCoreTextController ()

@property (nonatomic, strong) JRParagraphView	*paragraphView;

@end

@implementation JRCoreTextController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"Core Text!";
	self.view.backgroundColor = [UIColor whiteColor];

//	JRCoreTextView *view = [[JRCoreTextView alloc] initWithFrame:CGRectMake(100, 100, 200, 200)];
//	view.backgroundColor = [UIColor yellowColor];
//	[self.view addSubview:view];
	
	self.paragraphView = [[JRParagraphView alloc] initWithFrame:CGRectMake(20, 80, SCREEN_W - 40, 200)];
	self.paragraphView.backgroundColor = [UIColor lightGrayColor];
	[self.view addSubview:self.paragraphView];
	
}



@end
