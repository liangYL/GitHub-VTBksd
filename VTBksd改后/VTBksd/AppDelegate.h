//
//  AppDelegate.h
//  VTBksd
//
//  Created by GK on 14-10-27.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property(nonatomic,retain)UIImage *userImg;

- (void)showMain;
- (void)guestLogin;
@end

