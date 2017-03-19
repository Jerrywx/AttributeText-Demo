//
//  AppDelegate.m
//  AttributeText-Demo
//
//  Created by 王潇 on 16/9/7.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "AppDelegate.h"
#import "MainViewController.h"
#import "JRBlockViewController.h"
#import "JRDataStorageController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

/// 添加测试注释
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	
	/// 提交代码测试
//	[self setWindow];
	self.window					= [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
	UITabBarController	*tabVC	= [[UITabBarController alloc] init];
	
	/// 1.
	MainViewController *oneVC		= [[MainViewController alloc] init];
	UINavigationController *oneNav = [[UINavigationController alloc] initWithRootViewController:oneVC];
	oneNav.tabBarItem.title			= @"One";
	
	/// 2.
	JRBlockViewController *twoVC	= [[JRBlockViewController alloc] init];
	UINavigationController *twoNav	= [[UINavigationController alloc] initWithRootViewController:twoVC];
	twoVC.title						= @"Two";
	
	/// 3.
	JRDataStorageController *threeVC	= [[JRDataStorageController alloc] init];
	UINavigationController *threeNav	= [[UINavigationController alloc] initWithRootViewController:threeVC];
	threeVC.title			= @"Three";
	
//	JRCoreImageController
	/// 4.
	JRCoreImageController *fourVC	= [[JRCoreImageController alloc] init];
	UINavigationController *fourNav	= [[UINavigationController alloc] initWithRootViewController:fourVC];
	fourVC.title			= @"Four";
	
	/// 添加控制器
	tabVC.viewControllers = @[oneNav, twoNav, threeNav, fourNav];
	
	/// 显示
	self.window.rootViewController = tabVC;
	[self.window makeKeyAndVisible];
	
	
	return YES;
}

#pragma mark -
/// 初始化主控制器
- (void)setWindow {
	self.window					= [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
	MainViewController *viewVC		= [[MainViewController alloc] init];
	UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:viewVC];
	self.window.rootViewController = nav;
	[self.window makeKeyAndVisible];
}

- (void)applicationWillResignActive:(UIApplication *)application {
	// Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
	// Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
	// Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
	// If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
	// Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
	// Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
	// Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
