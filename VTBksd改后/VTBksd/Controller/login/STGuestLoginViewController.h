//
//  STGuestLoginViewController.h
//  VTVMall
//
//  Created by steve on 14-10-15.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GKLoginView.h"

@interface STGuestLoginViewController : XCSuperObjectViewController

@property (nonatomic,assign) GKLoginView *loginView;
- (void)loadXML;
@end
