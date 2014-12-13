//
//  XCHudProtocol.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//hud配件协议

#import <UIKit/UIKit.h>

@protocol XCHudProtocol <NSObject>

@required
- (void)hideHud;
- (void)showTextHud:(NSString *)text;
- (void)showOKHud:(NSString *)text delay:(NSTimeInterval)dalay;
- (void)showNOHud:(NSString *)text delay:(NSTimeInterval)dalay;

@optional
+ (void)hideHudS;
+ (void)showTextHudS:(NSString *)text;
+ (void)showOKHudS:(NSString *)text delay:(NSTimeInterval)dalay;
+ (void)showNOHudS:(NSString *)text delay:(NSTimeInterval)dalay;
@end
