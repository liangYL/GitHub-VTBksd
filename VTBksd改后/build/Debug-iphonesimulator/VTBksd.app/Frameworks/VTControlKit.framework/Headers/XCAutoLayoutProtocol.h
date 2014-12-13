//
//  XCAutoLayoutP.h
//  testAutoLayout
//
//  Created by wxc on 14-8-11.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//
#import <UIKit/UIKit.h>
//协议
@protocol XCAutoLayoutProtocol <NSObject>
- (void)layoutDidFinished:(UIView *)view;
@end

//协议
@protocol XCModuleProtocol <NSObject>
@required
- (void)startLoad;      //开始布局
@end