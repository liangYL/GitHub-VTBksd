//
//  ViewController.m
//  VTBksd
//
//  Created by GK on 14-10-27.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "ViewController.h"
#import "GKUserInfoCViewController.h"
#import "STOrderListViewController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _titleLabel.text=@"博客速递";
    self.view.backgroundColor = [UIColor whiteColor];
    
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"homePage" tag:self];
    
    [_homePageView startLoad];
    XCAddObserver(_homePageView, userInfoEvent, @selector(userInfoEvent:));
    XCAddObserver(_homePageView, waitingOrderEvent, @selector(waitOrderEvent:userode:));
    XCAddObserver(_homePageView, alreadyOrderEvent, @selector(alreadOrderEvent:userode:));
    XCAddObserver(_homePageView, dealersEvent, @selector(dealervent));
  
}
//用户信息
-(void)userInfoEvent:(XCDataBlock *)dataBlock
{
    GKUserInfoCViewController *userInfo = [[GKUserInfoCViewController alloc] init];
    userInfo.userDataBlock=dataBlock;
    [self.navigationController pushViewController:userInfo animated:YES];
    [userInfo release];
}
//待送订单
-(void)waitOrderEvent:(NSInteger)cout userode:(NSString *)userCode
{
    NSArray *conditionArray=@[@"3",@"4"];
    NSDictionary *dicValue=@{@"$in":conditionArray};
    NSDictionary *dic1=@{@"key":@"statusid",@"value":dicValue};
    
    
    NSDictionary *dic2=@{@"key":@"delistaff_id",@"value":userCode};
    STOrderListViewController *orderListVC = [[STOrderListViewController alloc] init];
    orderListVC.pushType=isPush;
    orderListVC.parmArray =[NSMutableArray arrayWithObjects:dic1,dic2,nil];
    [self.navigationController pushViewController:orderListVC animated:YES];
    orderListVC.titile = [NSString stringWithFormat:@"待送订单(%i)",cout];
    [orderListVC release];
}
//已送
-(void)alreadOrderEvent:(NSInteger)cout userode:(NSString *)userCode
{
    NSDictionary *dic1=@{@"key":@"statusid",@"value":[NSNumber numberWithInt:5]};
    NSDictionary *dic2=@{@"key":@"delistaff_id",@"value":userCode};
    STOrderListViewController *orderListVC = [[STOrderListViewController alloc] init];
    orderListVC.pushType=isPush;
   orderListVC.parmArray =[NSMutableArray arrayWithObjects:dic1,dic2,nil];
    [self.navigationController pushViewController:orderListVC animated:YES];
    orderListVC.titile = [NSString stringWithFormat:@"已送订单(%i)",cout];
    [orderListVC release];
}

//经销商
-(void)dealervent
{

}

@end
