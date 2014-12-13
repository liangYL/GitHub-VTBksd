//
//  XCHudTool.h
//  甲乙
//
//  Created by 王 晓超 on 13-3-25.
//  Copyright (c) 2013年 王 晓超. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define DEFAULT_HIDE_DELAY 2.0
#define LOAD_DEFAULT_TITLE @"请稍后..."
#define LOAD_NOTWEB @"请检查您的网络!"
#define LOAD_UNKNOWN @"未知错误!"
@interface XCHudTool : NSObject
{
    BOOL _keyBoardShow;
}

+ (XCHudTool *)sharedHud;

- (void)showTextHud:(NSString *)text;
- (void)showOKHud:(NSString *)text delay:(NSTimeInterval)dalay;
- (void)showNOHud:(NSString *)text delay:(NSTimeInterval)dalay;
- (void)showSmileHud:(NSString *)text delay:(NSTimeInterval)dalay;

- (void)showTextHud:(NSString *)text inView:(UIView *)inView;
- (void)showOKHud:(NSString *)text delay:(NSTimeInterval)dalay inView:(UIView *)inView;
- (void)showNOHud:(NSString *)text delay:(NSTimeInterval)dalay inView:(UIView *)inView;
- (void)showSmileHud:(NSString *)text delay:(NSTimeInterval)dalay inView:(UIView *)inView;

- (void)hideHud;
@end
