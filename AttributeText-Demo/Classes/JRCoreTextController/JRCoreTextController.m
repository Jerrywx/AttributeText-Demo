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
#import "JRTranslateCTMView.h"


@interface JRCoreTextController ()

@property (nonatomic, strong) JRParagraphView	*paragraphView;

@end

@implementation JRCoreTextController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"Core Text!";
	self.view.backgroundColor = [UIColor whiteColor];
	
//	self.paragraphView = [[JRParagraphView alloc] initWithFrame:CGRectMake(20, 80, SCREEN_W - 40, 100)];
//	self.paragraphView.backgroundColor = [UIColor lightGrayColor];
//	[self.view addSubview:self.paragraphView];
	
	JRTranslateCTMView *imgView = [[JRTranslateCTMView alloc] initWithFrame:CGRectMake(150, 150, 150, 150)];
	imgView.backgroundColor = [UIColor yellowColor];
	[self.view addSubview:imgView];
	
}



@end
