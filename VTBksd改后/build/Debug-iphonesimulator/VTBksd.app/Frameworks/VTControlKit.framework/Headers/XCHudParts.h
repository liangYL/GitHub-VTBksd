//
//  XCHudParts.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCHudProtocol.h"

@interface XCHudParts : NSObject<XCHudProtocol>

- (void)hideHud;
- (void)showTextHud:(NSString *)text;
- (void)showOKHud:(NSString *)text delay:(NSTimeInterval)dalay;
- (void)showNOHud:(NSString *)text delay:(NSTimeInterval)dalay;

#pragma mark -
+ (void)hideHudS;
+ (void)showTextHudS:(NSString *)text;
+ (void)showOKHudS:(NSString *)text delay:(NSTimeInterval)dalay;
+ (void)showNOHudS:(NSString *)text delay:(NSTimeInterval)dalay;
@end
