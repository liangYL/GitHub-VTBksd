//
//  GKUserInfoView.m
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKUserInfoView.h"
#import "AppDelegate.h"
#import <VTDevKit/UIImage+VTDevKit.h>
#import <VTDevKit/VTGTMBase64.h>

@implementation GKUserInfoView

-(void)startLoad
{
    [super startLoad];
    
    UITapGestureRecognizer *codetap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(codeModify)];
    [_codeModifyView  addGestureRecognizer:codetap];
    [codetap release];
    
    UITapGestureRecognizer *versiontap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(versionUp)];
    [_versionView  addGestureRecognizer:versiontap];
    [versiontap release];
    [_exitButton.button addTarget:self action:@selector(exitAPP) forControlEvents:UIControlEventTouchUpInside];
    [_testButton.button addTarget:self action:@selector(test) forControlEvents:UIControlEventTouchUpInside];
    
    
    _userStar.isUIE=0;
    
    UITapGestureRecognizer*tap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(imgClick)];
    _headImg.userInteractionEnabled=YES;
    [_headImg addGestureRecognizer:tap];
    [tap release];
     AppDelegate *app=[UIApplication sharedApplication].delegate;

    if (app.userImg == nil )
    {
        [_userDataBlock.aClass dataImmit:_userDataBlock.data views:self.autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
            
            if ([layout.css.cid isEqualToString:@"userStar"])
            {
                if ((NSNull *)value == [NSNull null]) {
                    value = @"0.0";
                }
                float p = value.floatValue/5;
                return [NSString stringWithFormat:@"%f",p];
            }
            return value;
            
        }  imageFilter:^(XCAutoLayout *layout, NSString *key, NSString *value, id imageView) {
            if ((NSNull *)value == [NSNull null])
            {
                [(UIImageView *)imageView setImage:[UIImage imageNamed:@"userInfo_head.png"]];
                return ;
            }
            if ([VTDevUtil isNotNull:value] )
            {
                [(UIImageView *)imageView setImage:[UIImage imageNamed:@"userInfo_head.png"]];
                return ;
            }
            NSData *data=[VTGTMBase64 decodeString:value];
            
            [(UIImageView *)imageView setImage:[UIImage imageWithData:data]];
        }];
        
    }
    else
    {
        [_userDataBlock.aClass dataImmit:_userDataBlock.data views:self.autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
            
            if ([layout.css.cid isEqualToString:@"userStar"])
            {
                float p = value.floatValue/5;
                return [NSString stringWithFormat:@"%f",p];
            }
            return value;
            
        }  imageFilter:^(XCAutoLayout *layout, NSString *key, NSString *value, id imageView) {
            if ((NSNull *)value == [NSNull null])
            {
                return ;
            }
            if ([VTDevUtil isNotNull:value] )
            {
                return ;
            }
            NSData *data=[VTGTMBase64 decodeString:value];
            [(UIImageView *)imageView setImage:[UIImage imageWithData:data]];
        }];
        _headImg.image=app.userImg;
    
    }


    
}
-(void)changeUserImg:(UIImage *)img
{

    NSString *imgs= [img imageTransToBase64String];
    [_userDataBlock addCurd:(NSMutableDictionary *)@{@"hrimage":imgs} flag:8 indexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
    VTDevDataChannelDocUpdateData *uData = [[VTDataParamsFactory shardParamsFactory] getUpdataParams:[_userDataBlock getCurd]];
    
    __block typeof(self) this = self;
    [super upData:uData xform:@"changeImg" result:^(id obj){
        [this.hud showOKHud:@"修改成功!" delay:2];
        [_userDataBlock removeDefCurd];
    
    }error:^(id error){
        [this.hud showNOHud:@"修改失败!" delay:2];
    }];



}
-(void)codeModify
{
    XCSendEvent(userCodeModify, nil);
}
-(void)versionUp
{
    VTDevDataChannelDocData *dataChannelDocData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *conditionsData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:dataChannelDocData];
    XCForm *form = ((XCForm *)[self.autoLayout getFormById:@"versionUpdate"].view);
    conditionsData.name = form.viewDef.rootBlock.tableName;
    NSDictionary *dic = @{@"key":@"file_type",@"value":@"IOS"};
    conditionsData.simplecondition = [NSMutableArray arrayWithObject:dic];
    __block typeof(self) this = self;
    
    [this.hud showTextHud:@"请稍后..."];
    [super getData:dataChannelDocData xform:@"versionUpdate" result:^(id obj)
    {
        [this.hud hideHud];
        
        [this.autoLayout loadFormView:@"versionUpdate"];
        [this.autoLayout settingOutlet:this];
        XCDataBlock * userDataBlock=[XCControlKitUtil getBlock:this.versionView];
        [userDataBlock getData];
        NSLog(@"%@",userDataBlock.data);
        XCSendEvent(versionUpDate,userDataBlock);

    }
    error:nil];

 

}
-(void)exitAPP
{

    XCSendEvent(exitApp, nil);

}

-(void)test
{
    
    XCSendEvent(test, nil);
    
}

-(void)imgClick
{
  XCSendEvent(headImgClick, _userDataBlock);

}
@end
