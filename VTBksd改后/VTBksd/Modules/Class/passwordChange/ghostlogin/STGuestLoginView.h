//
//  STGuestLoginView.h
//  VTVMall
//
//  Created by steve on 14-10-15.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VTControlKit/XCHudTool.h>

typedef enum
{
    guestLoginSucceed = 0        //游客登陆 0失败，1成功
}guestLoginType;

@interface STGuestLoginView : XCSuperModuleView

@property (nonatomic,assign)XCForm *login;
@end
