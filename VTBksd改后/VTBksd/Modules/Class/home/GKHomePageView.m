//
//  GKHomePageView.m
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKHomePageView.h"
#import "AppDelegate.h"
#import <VTDevKit/VTGTMBase64.h>
#import <VTDevKit/VTDevUtil.h>

@implementation GKHomePageView
-(void)startLoad
{
    [super startLoad];
    self.scrollView.isDelegate=self;
    self.scrollView.downHide=YES;
    [self askUserData];
    [self sendEvent];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(mytest:) name:@"mytest"object:nil];
}

-(void)askUserData
{
    VTDevDataChannelDocData *dataChannelDocData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *conditionsData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:dataChannelDocData];
    XCForm *form = ((XCForm *)[self.autoLayout getFormById:@"userInfo"].view);
    conditionsData.name = form.viewDef.rootBlock.tableName;
    NSString *userCode = [[__userManage getUserByDomain:@"jkl"] userCode];
    NSDictionary *dic = @{@"key":@"hrcode",@"value":userCode};
    conditionsData.simplecondition = [NSMutableArray arrayWithObject:dic];
    __block typeof(self) this = self;
    [super getData:dataChannelDocData xform:@"userInfo" result:^(id obj){
        
        [this.autoLayout loadFormView:@"userInfo"];
        [this.autoLayout settingOutlet:this];
        UITapGestureRecognizer *tap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(userInfo)];
        [_userInfoView  addGestureRecognizer:tap];
        [tap release];
        
        
        _userStar.isUIE=0;
        
        
        XCDataBlock * userDataBlock=[XCControlKitUtil getBlock:this.userInfoView];
        [userDataBlock getData];
        NSLog(@"%@",userDataBlock.data);
        if (userDataBlock.data ==nil || [userDataBlock.data count] == 0)
        {
            return ;
        }
        [userDataBlock setCurrentRow:@{@"key":@"hrcode",@"value":[[userDataBlock.data objectAtIndex:0] objectForKey:@"hrcode"]}];
        _userRowDataBlock= [self.autoLayout.root.blocks objectForKey:@"user"];
        [_userRowDataBlock getData];
        [self Waitingdelivery];
        [self alreadelivery];
        
        [[VTUserDefaults sharedUserDefaults] setObject:_userRowDataBlock.data forKey:@"userInfo"];
        [_userRowDataBlock.aClass dataImmit:_userRowDataBlock.data views:this.autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
            NSLog(@"++++++++%@",value);
            if ([layout.css.cid isEqualToString:@"userStar"])
            {
                if ((NSNull *)value == [NSNull null]) {
                    value = @"0.0";
                }
                float p = value.floatValue/5;
                return [NSString stringWithFormat:@"%f",p];
            }
            return value;
            
        } imageFilter:^(XCAutoLayout *layout, NSString *key, NSString *value, id imageView) {
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
        [this.scrollView finishLoad];
    }error:nil];
}

-(void)mytest:(NSNotification *)notification
{

    _headImg.image=[notification object];
}
-(void)Waitingdelivery
{
    VTDevDataChannelDocData *dataChannelDocData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *conditionsData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:dataChannelDocData];
    XCForm *form = ((XCForm *)[self.autoLayout getFormById:@"orderCount"].view);
    conditionsData.name = form.viewDef.rootBlock.tableName;
    NSLog(@"userRowDataBlock.data = %@",_userRowDataBlock.data);
    
    NSArray *conditionArray=@[@"3",@"4"];
    NSDictionary *dicValue=@{@"$in":conditionArray};
    NSDictionary *dic1=@{@"key":@"statusid",@"value":dicValue};
    
    NSDictionary *dic2=@{@"key":@"delistaff_id",@"value":[_userRowDataBlock.data objectForKey:@"hrcode"]};
    conditionsData.simplecondition = [NSMutableArray arrayWithObjects:dic2,dic1, nil];
    __block typeof(self) this = self;
    [super getData:dataChannelDocData xform:@"orderCount" result:^(id obj){
        
        [this.autoLayout loadFormView:@"orderCount"];
        [this.autoLayout settingOutlet:this];
    
        XCDataBlock * userDataBlock=[XCControlKitUtil getBlock:this.contView];
        [userDataBlock getData];
        _waitNum=[userDataBlock.data count];
        _WaitingOrderImg.cornerMarkTitle=[NSString stringWithFormat:@"%i", [userDataBlock.data count]];
        _WaitingOrderImg.cornerMark.backgroundColor=[UIColor redColor];
   
        
    }error:nil];


}
-(void)alreadelivery
{
    VTDevDataChannelDocData *dataChannelDocData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *conditionsData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:dataChannelDocData];
    XCForm *form = ((XCForm *)[self.autoLayout getFormById:@"orderCount"].view);
    conditionsData.name = form.viewDef.rootBlock.tableName;
    
    NSDictionary *dic = @{@"key":@"statusid",@"value":[NSNumber numberWithInt:5]};
    NSDictionary *dic2=@{@"key":@"delistaff_id",@"value":[_userRowDataBlock.data objectForKey:@"hrcode"]};
    conditionsData.simplecondition = [NSMutableArray arrayWithObjects:dic2,dic, nil];
    __block typeof(self) this = self;
    [super getData:dataChannelDocData xform:@"orderCount" result:^(id obj){
        
        [this.autoLayout loadFormView:@"orderCount"];
        [this.autoLayout settingOutlet:this];
        
        XCDataBlock * alreadOrderBlock=[XCControlKitUtil getBlock:this.contView];
        [alreadOrderBlock getData];
        _alreadNum=[alreadOrderBlock.data count];
        _alreadyOrderImg.cornerMarkTitle=[NSString stringWithFormat:@"%i", [alreadOrderBlock.data count]];
        _alreadyOrderImg.cornerMark.backgroundColor=[UIColor redColor];
        
        
    }error:nil];



}
- (void)pullScrollViewPullLoad:(UIScrollView *)scroll
{
 __block typeof(self) this = self;
    [this askUserData];



}
-(void)sendEvent
{
    
    UITapGestureRecognizer *waittap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(WaitingOrder)];
    [_WaitingOrderView  addGestureRecognizer:waittap];
    [waittap release];
    
    UITapGestureRecognizer *alreadtap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(alreadOrder)];
    [_alreadyOrderView  addGestureRecognizer:alreadtap];
    [alreadtap release];
    
    UITapGestureRecognizer *dealertap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(dealer)];
    [_dealersView  addGestureRecognizer:dealertap];
    [dealertap release];
    

    UITapGestureRecognizer *personTap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(userInfo)];
    [_personInfoView  addGestureRecognizer:personTap];
    [personTap release];
    

}
-(void)userInfo
{
    XCSendEvent(userInfoEvent, _userRowDataBlock);
}
-(void)WaitingOrder
{
    NSLog(@"userCode = %@",[_userRowDataBlock.data objectForKey:@"userCode"]);
    
    if (_userRowDataBlock.data ==nil ||_userRowDataBlock.data ==[NSNull null])
    {
        return;

    }
    else
    {
     XCSendEvent(waitingOrderEvent, _waitNum,[_userRowDataBlock.data objectForKey:@"hrcode"]);

    }
    
   

}
-(void)alreadOrder
{
    if (_userRowDataBlock.data ==nil ||_userRowDataBlock.data ==[NSNull null])
    {
        return;
        
    }
    else
    {
        XCSendEvent(alreadyOrderEvent, _alreadNum,[_userRowDataBlock.data objectForKey:@"hrcode"]);
    }

}
-(void)dealer
{
    XCSendEvent(dealersEvent, nil);

}

@end
