//
//  XCSuperModuleFlowCell.h
//  vwedd
//
//  Created by steve on 14/10/22.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "XCFlowShowView.h"
#import "XCAutoLayoutController.h"
#import "XCAutoLayoutProtocol.h"

@interface XCSuperModuleFlowCell : XCFlowCell<XCModuleProtocol>
{
    XCAutoLayoutController *_autoLayout;
}
@property (nonatomic,assign) XCAutoLayoutRoot *css;
@property (nonatomic,readonly) XCAutoLayoutController *autoLayout;

- (void)startLoad;
@end
