//
//  AppDelegate.m
//  VTBksd
//
//  Created by GK on 14-10-27.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "UINavigationBar+Custom.h"
#import "STGuestLoginViewController.h"
#import <VTControlKit/XCAutoLayoutManage.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [XCAutoLayoutManage sharedXCAutoLayoutManage].isOldLayout = YES;
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] setPageFileBundle:[[[NSBundle mainBundle] bundlePath] stringByAppendingString:@"/Pages.bundle"]];
    [VTDataParamsFactory initParamsFactory:@"@data-params.plist"];
    
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]]autorelease];
    [self guestLogin];
    return YES;
}

- (void)guestLogin
{
    STGuestLoginViewController *guestloginController = [[[STGuestLoginViewController alloc] init] autorelease];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:guestloginController];
    [nav.navigationBar customNavigationBackGround];
    guestloginController.pushType=isPushMain;
    
    [VTAnimationTools cATransitionAnimation:self.window typeIndex:6 subTypeIndex:1 duration:0.5 animation:^{
        self.window.rootViewController = nav;
        [self.window makeKeyAndVisible];
        
        [guestloginController loadXML];
    }];
  
}

- (void)showMain
{
    ViewController *viewController = [[[ViewController alloc] init] autorelease];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:viewController];
    [nav.navigationBar customNavigationBackGround];
    viewController.pushType=isPushMain;
    
    [VTAnimationTools cATransitionAnimation:self.window typeIndex:6 subTypeIndex:1 duration:0.5 animation:^{
        self.window.rootViewController = nav;
        [self.window makeKeyAndVisible];
    }];
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
