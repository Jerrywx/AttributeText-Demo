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
#import "JRSimpleTextView.h"
#import "JRColumnarLayoutView.h"
#import "JRManualLineBreakingView.h"
#import "JRParagraphStyleView.h"
#import "JRNonrectangularRegionView.h"

@interface JRCoreTextController ()

@property (nonatomic, strong) JRParagraphView	*paragraphView;

@end

@implementation JRCoreTextController

- (void)viewDidLoad {
    [super viewDidLoad];
	
	self.title = @"Core Text!";
	self.view.backgroundColor = [UIColor whiteColor];
	
	
	/// 0. JRTranslateCTMView
	//	JRTranslateCTMView *imgView = [[JRTranslateCTMView alloc] initWithFrame:CGRectMake(20,
	//															80, SCREEN_W - 40, SCREEN_W - 40)];
	//	imgView.backgroundColor = [UIColor yellowColor];
	//	[self.view addSubview:imgView];
	
	
	/// 1. JRParagraphView
	self.paragraphView = [[JRParagraphView alloc] initWithFrame:CGRectMake(20, 80, SCREEN_W - 40, 100)];
	self.paragraphView.backgroundColor = [UIColor lightGrayColor];
	[self.view addSubview:self.paragraphView];
	
	/// 2. JRSimpleTextView
	JRSimpleTextView *simpleText = [[JRSimpleTextView alloc] initWithFrame:CGRectMake(20,
														200, SCREEN_W - 40, 100)];
	simpleText.backgroundColor = [UIColor yellowColor];
	[self.view addSubview:simpleText];
	
	/// 3. JRColumnarLayoutView
	JRColumnarLayoutView *layoutView = [[JRColumnarLayoutView alloc] initWithFrame:CGRectMake(20,
																			320, SCREEN_W - 40, 100)];
	layoutView.backgroundColor = [UIColor yellowColor];
	[self.view addSubview:layoutView];
	
	/// 4. JRManualLineBreakingView
	JRManualLineBreakingView *breakView = [[JRManualLineBreakingView alloc] initWithFrame:CGRectMake(20, 440, SCREEN_W - 40, 100)];
	breakView.backgroundColor = [UIColor orangeColor];
	[self.view addSubview:breakView];
	
	/// 5. JRParagraphStyleView
//	JRParagraphStyleView *styleView = [[JRParagraphStyleView alloc] initWithFrame:CGRectMake(20, 560, SCREEN_W - 40, 100)];
//	styleView.backgroundColor = [UIColor yellowColor];
//	[self.view addSubview:styleView];
	
	/// 7. JRNonrectangularRegionView
	JRNonrectangularRegionView *styleView = [[JRNonrectangularRegionView alloc] initWithFrame:CGRectMake(20, 560, SCREEN_W - 40, 100)];
	styleView.backgroundColor = [UIColor yellowColor];
	[self.view addSubview:styleView];
	
	// CFStringRef
	CFStringRef string = CFSTR("按时阿萨德阿萨德是");
	NSString *s = (__bridge NSString *)(string);
	NSLog(@"%@", s);
}



@end
