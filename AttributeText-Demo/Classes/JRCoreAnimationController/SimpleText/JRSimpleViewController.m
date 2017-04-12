//
//  JRSimpleViewController.m
//  AttributeText-Demo
//
//  Created by wxiao on 2017/4/6.
//  Copyright © 2017年 王潇. All rights reserved.
//

#import "JRSimpleViewController.h"
#import "JRSimpleView.h"


@interface JRSimpleViewController ()

///
@property (nonatomic, strong) JRSimpleView *textView;

@end

@implementation JRSimpleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
	
	[self setupUI];
}

- (void)setupUI {
	
	self.title = @"Simple";
	
	self.textView = [[JRSimpleView alloc] initWithFrame:CGRectMake(20, 100, SCREEN_W - 40, 100)];
	self.textView.backgroundColor = [UIColor yellowColor];
	[self.view addSubview:self.textView];
	
}


@end
