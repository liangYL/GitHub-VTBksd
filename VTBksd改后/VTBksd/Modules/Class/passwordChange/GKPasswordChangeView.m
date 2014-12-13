//
//  GKPasswordChangeView.m
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKPasswordChangeView.h"
#import <VTControlKit/XCHudTool.h>

@implementation GKPasswordChangeView

-(void)startLoad
{

    [super startLoad];
    [_exitButton.button addTarget:self action:@selector(saveCode) forControlEvents:UIControlEventTouchUpInside];
    _orginUserCode.textField.secureTextEntry=YES;
    _newUserCode.textField.secureTextEntry=YES;
    _confirmCode.textField.secureTextEntry=YES;

}
-(void)saveCode

{
    if([VTDevUtil isNotNull:_orginUserCode.textField.text] )
    {
//        [[XCHudTool sharedHud] showNOHud:@"原密码不能为空" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"原密码不能为空" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
        
    }
    if([VTDevUtil isNotNull:_newUserCode.textField.text] )
    {
//        [[XCHudTool sharedHud] showNOHud:@"新密码不能为空" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"新密码不能为空" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
        
    }
    
    if([VTDevUtil isNotNull:_confirmCode.textField.text] )
    {
//        [[XCHudTool sharedHud] showNOHud:@"确认密码不能为空" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"确认密码不能为空" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;

    }
    int aa=[self validationStrCont:_newUserCode.textField.text ];
    int bb=[self validationStrCont:_confirmCode.textField.text ];
    if (aa < 6 || bb<6) {
//        [[XCHudTool sharedHud] showNOHud:@"密码长度不能小于六位" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"密码长度不能小于六位" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
    }
    
    if (![_confirmCode.textField.text isEqualToString:_newUserCode.textField.text]) {
//        [[XCHudTool sharedHud] showNOHud:@"新密码和确认密码不一致" delay:2];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"新密码和确认密码不一致" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        return;
    }
    [[XCHudTool sharedHud] showTextHud:@"请稍后..."];
    XCForm *form = [self.autoLayout getFormById:@"pwdChange"].view;
    
    XCChanngePwdData *data = [[[XCChanngePwdData alloc] init] autorelease];
    VTDevIceDataParamsObj *obj = [[VTDataParamsFactory shardParamsFactory] getDefParams];
    obj.messageType = @"BizDataService.executeAsyn";
    [data set_dataParams:obj];
    
    data.formid = @"101";
    data.systemid = @"2";
    data.clientid = obj.spaceId;
    data.controlid = @"10001";
    data.dataparam = (NSMutableDictionary *)@{@"buttonId":@"changePWD",@"param1":[[__userManage getUserByDomain:@"jkl"] userCode],@"param2":_orginUserCode.textField.text,@"param3":_confirmCode.textField.text};
    
    [form.viewDef.dataOperation dataOperation:data result:^(id obj,...){
        NSLog(@"%@",[[obj objectForKey:@"result"]objectForKey:@"10" ]);
        NSString *str1=[[obj objectForKey:@"result"]objectForKey:@"10"];
       NSDictionary *dic=[NSJSONSerialization JSONObjectWithData:[[NSString stringWithFormat:@"%@",str1] dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingAllowFragments error:nil];
        NSString *str2=[dic objectForKey:@"message"];
        NSDictionary *dic2=[NSJSONSerialization JSONObjectWithData:[[NSString stringWithFormat:@"%@",str2] dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingAllowFragments error:nil];
        
        NSString * message=[dic2 objectForKey:@"message"];
//        [[XCHudTool sharedHud] showOKHud:message delay:2.];
        [[XCHudTool sharedHud] hideHud];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:message delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alter show];
        [alter release];
        XCSendEvent(saveCode, nil);
    }error:^(id aError) {
//        [[XCHudTool sharedHud] showOKHud:@"修改失败!" delay:2.];
         [[XCHudTool sharedHud] hideHud];
        UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"提示" message:@"修改失败" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
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



@implementation XCChanngePwdData
- (void)dealloc
{
    [_formid release];
    [_systemid release];
    [_dataparam release];
    [_controlid release];
    [_clientid release];
    [super dealloc];
}
@end
