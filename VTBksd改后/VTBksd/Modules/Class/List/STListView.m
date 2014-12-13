//
//  STListView.m
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STListView.h"
#import <VTDevKit/VTHTTPInterface.h>
@implementation STListView

-(void)startLoad
{
    [super startLoad];
    
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    cData.simplecondition = _paramArray;
    
    [super getData:docData xform:@"list" result:^(id obj){
        [this.autoLayout loadFormView:@"list"];
        [this.autoLayout settingOutlet:this];
        [[XCControlKitUtil getBlock:this.tableView] getData];
    }error:nil];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [[XCControlKitUtil getBlock:tableView].data count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 100;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 60;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    id obj = [[XCControlKitUtil getBlock:tableView].data objectAtIndex:section];
    
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor whiteColor];
    view.frame = CGRectMake(0, 0, self.frame.size.width, 100);
    view.tag = section;
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(headerClick:)];
    [view addGestureRecognizer:tap];
    [tap release];
    
    UILabel *codelabel = [[UILabel alloc] init];
    codelabel.frame = CGRectMake(25, 5, 170, 20);
    codelabel.font = [UIFont systemFontOfSize:12];
    codelabel.text = [obj objectForKey:@"ordercode"];
    [view addSubview:codelabel];
    [codelabel release];
    
    UILabel *timeLabel = [[UILabel alloc] init];
    timeLabel.frame = CGRectMake(self.frame.size.width-120, 5, 100, 20);
    timeLabel.textAlignment = NSTextAlignmentRight;
    timeLabel.font = [UIFont systemFontOfSize:12];
    timeLabel.textColor=[UIColor colorWithRed:0.57 green:0.57 blue:0.57 alpha:1.0];
    timeLabel.text = [VTDevUtil dateFormatter:[VTDevUtil stringToDate:[obj objectForKey:@"docdate"] format:ALL_DEFAULT_TIME_FORM] format:YY_DEFAULT_TIME_FORM];
    
    [view addSubview:timeLabel];
    [timeLabel release];
    
    UILabel *sendName = [[UILabel alloc] init];
    sendName.frame = CGRectMake(25, timeLabel.frame.origin.y+timeLabel.frame.size.height +10, self.frame.size.width, 20);
    sendName.font = [UIFont systemFontOfSize:13];
    sendName.text = [obj objectForKey:@"custname"];
    [view addSubview:sendName];
    [sendName release];
    
    UILabel *address = [[UILabel alloc] init];
    address.frame = CGRectMake(25, sendName.frame.origin.y+sendName.frame.size.height + 10, sendName.frame.size.width, 20);
    address.font = [UIFont systemFontOfSize:12];
    address.text = [obj objectForKey:@"de_addr"];
    [view addSubview:address];
    [address release];
    
    UIView *line = [[UIView alloc] initWithFrame:CGRectMake(15, view.frame.size.height-1, view.frame.size.width-30, 0.5)];
    line.backgroundColor = [UIColor grayColor];
    [view addSubview:line];
    [line release];
    
    return view;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    id obj = [[XCControlKitUtil getBlock:_tableView].data objectAtIndex:section];
    
    _footView = [[[UIView alloc] init] autorelease];
    _footView.backgroundColor = [UIColor whiteColor];
    _footView.frame = CGRectMake(0, 0, self.frame.size.width, 50);
    _footView.tag=section;
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(headerClick:)];
    [_footView addGestureRecognizer:tap];
    [tap release];
    
    UIView *line = [[UIView alloc] initWithFrame:CGRectMake(15, 1, _footView.frame.size.width-30, 0.5)];
    line.backgroundColor = [UIColor grayColor];
    [_footView addSubview:line];
    [line release];
    
    UIButton *btn1 = [UIButton buttonWithType:UIButtonTypeCustom];
    btn1.frame = CGRectMake(25, 10, 30, 30);
    if (((NSNull *)[obj objectForKey:@"de_tel"]!= [NSNull null])&&![(NSString *)[obj objectForKey:@"de_tel"]isEqualToString:@""])
    {
         [btn1 setBackgroundImage:[UIImage imageNamed:@"tell1.png"] forState:UIControlStateNormal];
        [btn1 addTarget:self action:@selector(callPhone:) forControlEvents:UIControlEventTouchUpInside];

    }
    else
    {
    
        [btn1 setBackgroundImage:[UIImage imageNamed:@"tell2.png"] forState:UIControlStateNormal];
    }
    [btn1 setBackgroundImage:[UIImage imageNamed:@"tell1.png"] forState:UIControlStateNormal];
    btn1.tag = section*3+0+100;
    [_footView addSubview:btn1];
    
    UIButton *btn2 = [UIButton buttonWithType:UIButtonTypeCustom];
    btn2.frame = CGRectMake(65, 10, 30, 30);
    if (((NSNull *)[obj objectForKey:@"de_tel1"]!= [NSNull null])&&![(NSString *)[obj objectForKey:@"de_tel1"]isEqualToString:@""])
    {
        [btn2 setBackgroundImage:[UIImage imageNamed:@"tell1.png"] forState:UIControlStateNormal];
        [btn2 addTarget:self action:@selector(callPhone:) forControlEvents:UIControlEventTouchUpInside];

    }
    else
    {
        
        [btn2 setBackgroundImage:[UIImage imageNamed:@"tell2.png"] forState:UIControlStateNormal];
    }
    btn2.tag = section*3+1+100;
    [_footView addSubview:btn2];
    
    UIButton *btn3 = [UIButton buttonWithType:UIButtonTypeCustom];
    btn3.frame = CGRectMake(105, 10, 30, 30);
    if (!((NSNull *)[obj objectForKey:@"de_tel2"] == [NSNull null]) && ![(NSString *)[obj objectForKey:@"de_tel2"]isEqualToString:@""])
    {

        [btn3 setBackgroundImage:[UIImage imageNamed:@"tell1.png"] forState:UIControlStateNormal];
        [btn3 addTarget:self action:@selector(callPhone:) forControlEvents:UIControlEventTouchUpInside];

    }
    else
    {
        
        [btn3 setBackgroundImage:[UIImage imageNamed:@"tell2.png"] forState:UIControlStateNormal];
    }
    btn3.tag = section*3+2+100;
    [_footView addSubview:btn3];
    
    UIImageView *imgView=[[UIImageView alloc]init];
    imgView.frame=CGRectMake(290, 15, 8, 15);
    imgView.image=[UIImage imageNamed:@"arrow22.png"];
    [_footView addSubview:imgView];
    [imgView release];
    
    
    UIView *line1 = [[UIView alloc] initWithFrame:CGRectMake(0, _footView.frame.size.height, _footView.frame.size.width, 2)];
    line1.backgroundColor = [UIColor colorWithRed:0.85 green:0.85 blue:0.85 alpha:1.0];
    [_footView addSubview:line1];
    [line1 release];


    
    return _footView;
}





- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    XCDataBlock *block = [XCControlKitUtil getBlock:tableView];
    return [[[[block.data objectAtIndex:section] objectForKey:@"morder_app_item"] objectForKey:@"dataArray"] count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static  NSString *str =@"cell";
    
    XCSuperModuleCell *cell =[tableView dequeueReusableCellWithIdentifier:str];
    if (cell ==nil)
    {
        cell =[[[XCSuperModuleCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:str] autorelease];
        cell.css = self.cellCss;
        [cell startLoad];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    XCDataBlock *block = [XCControlKitUtil getBlock:tableView];
    id obj = [[[[block.data objectAtIndex:indexPath.section] objectForKey:@"morder_app_item"] objectForKey:@"dataArray"] objectAtIndex:indexPath.row];
    [block.aClass dataImmit:obj views:cell.autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
        
        if ([layout.css.cid isEqualToString:@"productPrice"])
        {
            NSString *aa=[NSString stringWithFormat:@"%.2f",value.doubleValue];
            return [NSString stringWithFormat:@"￥:%@", aa];
        }
        if ([layout.css.cid isEqualToString:@"productCount"])
        {
            return [NSString stringWithFormat:@"x %@",value];
        }
        return value;
        
    } imageFilter:nil];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    XCDataBlock *block = [XCControlKitUtil getBlock:tableView];
    id obj = [block.data objectAtIndex:indexPath.section];
    [block setCurrentRow:@{@"key":@"_id",@"value":[obj objectForKey:@"_id"]}];
    
    XCDataBlock *cellBlock = [self.autoLayout.root.blocks objectForKey:@"tableViewCell"];
    [cellBlock getData];
    XCSendEvent(STListViewCellClick,cellBlock);
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return self.cellHeight;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

//- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
//    
//    if (editingStyle == UITableViewCellEditingStyleDelete)
//    {
//        [self deleteAddress:indexPath];
//    }
//}

- (void)pullTableViewPullLoad:(XCPullTableView *)tableView
{
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    cData.simplecondition = _paramArray;
    
    [super getDataReload:docData xform:@"list" result:^(id obj){
        [[XCControlKitUtil getBlock:this.tableView] getData];
        [this.tableView reloadData];
    }error:^(id aError) {
        
    }];
}

- (void)pullTableViewMoreLoad:(XCPullTableView *)tableView
{
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    cData.simplecondition = _paramArray;
    
    [super getDataAppend:docData xform:@"list" result:^(id obj){
        [[XCControlKitUtil getBlock:this.tableView] getData];
        [this.tableView reloadData];
    }error:^(id aError) {
        
    }];
}

////滑动删除
//- (void)deleteAddress:(NSIndexPath *)indexPath
//{
//    id obj = [[XCControlKitUtil getBlock:self.tableView].data objectAtIndex:indexPath.row];
//    NSMutableDictionary *dic = [NSMutableDictionary dictionaryWithObject:[obj objectForKey:@"_id"] forKey:@"_id"];
//    
//    [[XCControlKitUtil getBlock:self.tableView] addCurd:dic flag:2 indexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
//    VTDevDataChannelDocUpdateData *cData = [[VTDataParamsFactory shardParamsFactory] getUpdataParams:[XCControlKitUtil getBlock:self.tableView].getCurd];
//    
//    [super upData:cData xform:[XCControlKitUtil getBlock:self.tableView].dataView.form result:^(id obj){
//        
//        [self.hud showOKHud:@"删除成功" delay:2];
//        
//        [[XCControlKitUtil getBlock:self.tableView].data removeObjectAtIndex:indexPath.row];
//        [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
//        
//        XCSendEvent(STListViewCellDeleteSucceed, @"1");
//        
//    } error:^(id  error){
//        
//        [self.hud showNOHud:@"删除失败!" delay:2];
//        
//        XCSendEvent(STListViewCellDeleteSucceed, @"0");
//        
//    }];
//}

- (void)headerClick:(UITapGestureRecognizer *)tap
{
    int section = tap.view.tag;
    
    XCDataBlock *block = [XCControlKitUtil getBlock:_tableView];
    id obj = [block.data objectAtIndex:section];
    [block setCurrentRow:@{@"key":@"_id",@"value":[obj objectForKey:@"_id"]}];
    
    XCDataBlock *cellBlock = [self.autoLayout.root.blocks objectForKey:@"tableViewCell"];
    [cellBlock getData];
    XCSendEvent(STListViewCellClick,cellBlock);
}

- (void)callPhone:(UIButton *)btn
{
    
    int section = (btn.tag-100)/3;
    int row = (btn.tag-100)%3;
    id obj = [[XCControlKitUtil getBlock:_tableView].data objectAtIndex:section];
    NSString *tel1=[obj objectForKey:@"de_tel"];
    NSString *tel2=[obj objectForKey:@"de_tel1"];
    NSString *tel3=[obj objectForKey:@"de_tel2"];
 
    
    if (row ==0)
    {
        _phoneNumber =[tel1 copy];
    }
    else if (row==1)
    {
        _phoneNumber=[tel2 copy];
    }
    else if (row ==2)
    {
        _phoneNumber =[tel3 copy];
    }
    
    UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"是否拨打此电话" message:nil delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"拨打",nil];
    [alter show];
    [alter release];

   
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
 
    
    if(buttonIndex ==1)
    {
        [self zhuanjie:_phoneNumber];
        
    }
    
   
}

-(void)zhuanjie:(NSString *)phoneNum
{
    id data = [[VTUserDefaults sharedUserDefaults] getObjectForkey:@"userInfo"];
    NSLog(@"%@",[data objectForKey:@"mobile"]);
    if (data == nil)
    {
        [self.hud showNOHud:@"错误!请稍后!" delay:2.];
        return;
    }
    [self.hud showTextHud:@"正在转接请稍后!"];
    
    VTDevHTTPRequestData *requestData = [[[VTDevHTTPRequestData alloc] init] autorelease];
    requestData.url = @"http://106.120.210.124:3000/callback_task/add";
    requestData.method = @"GET";
    requestData.path = @"";
    requestData.params = @{@"mobile_no":[data objectForKey:@"mobile"],@"dest_no":phoneNum};
    requestData.success = ^(id obj){
        NSLog(@"%@ %@",obj,requestData);
        id jsonData = [NSJSONSerialization JSONObjectWithData:obj options:NSJSONReadingMutableLeaves error:nil];
        
        if (![[jsonData objectForKey:@"result"] isEqualToString:@"success"])
        {
            [self.hud showNOHud:@"转接失败!" delay:2.];
            
        }
        else
        {
            /*
            [self.hud showOKHud:@"电话已经成功拨出,请稍后" delay:2.];
            //拨打成功延迟15秒之内不能再次拨打
            _secondsCountDown = 15;//秒倒计时
            _countDownTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(timeFireMethod) userInfo:nil repeats:YES];
             */
            UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"电话已经成功拨出,请尽量不要在15秒之内重复拨打其他客服电话,以免冲突,谢谢"  message:nil delegate:self cancelButtonTitle:@"确认" otherButtonTitles:nil];
            [alter show];
            [alter release];
        }
    };
    requestData.error = ^(id error){
        [self.hud showNOHud:@"转接失败!" delay:2.];
    };
    
    [VTHTTPInterface getHTTPData:requestData error:nil];


}
/*
-(void)timeFireMethod{
    
    _secondsCountDown--;
    if(_secondsCountDown==0){
        
        NSLog(@"倒计时结束");
        for (int i = 0; i < [[XCControlKitUtil getBlock:self.tableView].data count]*3; i++) {
            ((UIButton *)[self.tableView viewWithTag:i+100]).userInteractionEnabled = YES;
        }
        [_countDownTimer invalidate];
        
    }
    for (int i = 0; i < [[XCControlKitUtil getBlock:self.tableView].data count]*3; i++) {
        ((UIButton *)[self.tableView viewWithTag:i+100]).userInteractionEnabled = NO;
        
    }
    
}

-(void)warning{
    UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"15秒后可再次拨打" message:nil delegate:self cancelButtonTitle:@"确认" otherButtonTitles:nil];
    [alter show];
}
*/


@end
