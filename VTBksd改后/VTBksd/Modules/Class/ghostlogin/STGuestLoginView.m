//
//  STGuestLoginView.m
//  VTVMall
//
//  Created by steve on 14-10-15.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import "STGuestLoginView.h"

@implementation STGuestLoginView

-(void)startLoad
{
    [super startLoad];
    self.backgroundColor = [UIColor whiteColor];
    NSLog(@"%@",_login);
    [self autoGuestLogin];
}
-(void)autoGuestLogin
{
    NSMutableDictionary *dic = [[VTDataParamsFactory shardParamsFactory] getGuestLoginParams];
    
    [self login:dic xform:@"login" result:^(id result) {
        [self.hud hideHud];
        XCSendEvent(guestLoginSucceed,@"1");
    } error:^(id error){
        [self.hud showNOHud:@"连接服务器失败!" delay:2];
        XCSendEvent(guestLoginSucceed,@"0");
    }];
}

@end
