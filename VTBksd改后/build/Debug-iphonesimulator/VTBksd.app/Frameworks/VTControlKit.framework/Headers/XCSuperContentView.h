//
//  XCSuperContentView.h
//  CreatZujian
//
//  Created by steve on 14-9-19.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutController.h"
#import "XCAutoLayoutProtocol.h"

@interface XCSuperContentView : UIView <XCModuleProtocol>
{
    XCAutoLayoutController *_autoLayout;
}
@property (nonatomic,assign) XCAutoLayoutRoot *css;
@property (nonatomic,readonly) XCAutoLayoutController *autoLayout;

- (void)startLoad;
@end
