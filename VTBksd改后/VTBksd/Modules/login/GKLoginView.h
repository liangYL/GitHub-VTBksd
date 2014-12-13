//
//  GKLoginView.h
//  GKLogin
//
//  Created by GK on 14-9-16.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VTControlKit/STButtonView.h>
#import <VTControlKit/XCHudTool.h>
typedef enum
{
    loginBtnClick         //登陆  传参:用户名，密码

    
}GKLoginType;
@interface GKLoginView :STAutoKeyBoardSuperView

@property(nonatomic,assign)STButtonView *loginbutton;
@property(nonatomic,assign)UITextField *userNameTextField;
@property(nonatomic,assign)UITextField *passWordTextField;
@property(nonatomic,assign)NSString * loginType; //0表示正式登陆 1表示测试登陆
@property(nonatomic,assign)NSString *ICE_spaceId;
@end
