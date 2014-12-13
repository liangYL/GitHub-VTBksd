//
//  GKLoginView.m
//  GKLogin
//
//  Created by GK on 14-9-16.
//  Copyright (c) 2014年 GK. All rights reserved.
//



#import "GKLoginView.h"
#import <VTX/XCEvent.h>

@implementation GKLoginView

-(void)startLoad
{
   [super startLoad];
    self.backgroundColor = [UIColor whiteColor];
    
    [_loginbutton.button addTarget:self action:@selector(loginbuttonClick) forControlEvents:UIControlEventTouchUpInside];
    _loginbutton.button.titleLabel.font=[UIFont systemFontOfSize:17];
    _userNameTextField.keyboardType=UIKeyboardTypeASCIICapable;  //只允许数字与字母
    _userNameTextField.borderStyle=UITextBorderStyleNone;
    _passWordTextField.keyboardType=UIKeyboardTypeDefault;
    _passWordTextField.secureTextEntry=YES;
    _passWordTextField.borderStyle=UITextBorderStyleNone;

//    UIImageView *userImg=[[UIImageView alloc]initWithImage:[UIImage imageNamed:@"username.png"]];
//     userImg.frame=CGRectMake(10, 0, 20, 20);
//    _userNameTextField.leftView=userImg;
//    _userNameTextField.leftViewMode=UITextFieldViewModeAlways;
//    [userImg release];sdfsdf
//
//    
//    UIImageView *userImg2=[[UIImageView alloc]initWithImage:[UIImage imageNamed:@"usercode11.png"]];
//    userImg2.frame=CGRectMake(10, 0, 20, 20);
//    _passWordTextField.leftView=userImg2;
//    _passWordTextField.leftViewMode=UITextFieldViewModeAlways;
//    [userImg2 release];
    
    
    
    
}
-(void)loginbuttonClick
{

//    _userNameTextField.text=@"37272";
//    _passWordTextField.text=@"111111";
    if ([VTDevUtil isNotNull:_userNameTextField.text]) {
//        [[XCHudTool sharedHud] showNOHud:@"用户名不能为空" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"用户名不能为空" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
    }
    if ([VTDevUtil isNotNull:_passWordTextField.text]) {
//        [[XCHudTool sharedHud] showNOHud:@"密码不能为空" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"密码不能为空" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
    }
    
    int aa=[self validationStrCont:_passWordTextField.text ];
    if (aa < 6) {
//        [[XCHudTool sharedHud] showNOHud:@"密码长度不能小于六位" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"密码长度不能小于六位" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
    }
    
    NSMutableDictionary *dic = [[VTDataParamsFactory shardParamsFactory] getLoginParams];
    [dic setObject:_userNameTextField.text forKey:@"userCode"];
    [dic setObject:_passWordTextField.text forKey:@"userpw"];
  
    [self login:dic xform:@"login" result:^(id result) {
        NSLog(@"%@",result);
        [self.hud hideHud];
        XCSendEvent(loginBtnClick,nil);
    } error:^(id error){
          NSLog(@"%@",error);
        [self.hud hideHud];
//       [self.hud showNOHud:@"密码错误或者用户名错误" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"密码错误或者用户名错误" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
    }];
 
  
   
}
-(int)validationStrCont:(NSString *)str
{
    int strlength = 0;
    char* p = (char*)[str cStringUsingEncoding:NSUnicodeStringEncoding];
    for (int i=0 ; i<[str lengthOfBytesUsingEncoding:NSUnicodeStringEncoding] ;i++) {
        if (*p) {
            p++;
            strlength++;
        }
        else {
            p++;
        }
    }
    return strlength;
    
}
@end
