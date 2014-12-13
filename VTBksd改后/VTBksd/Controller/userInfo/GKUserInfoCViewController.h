//
//  GKUserInfoCViewController.h
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GKUserInfoView.h"
@interface GKUserInfoCViewController : XCSuperObjectViewController
@property(nonatomic,assign)GKUserInfoView *userInfoView;
@property(nonatomic,assign)XCDataBlock *userDataBlock;
@end
