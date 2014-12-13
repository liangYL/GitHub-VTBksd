//
//  GKUserInfoCViewController.m
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKUserInfoCViewController.h"
#import "GKPasswordViewController.h"
#import "STCameraSheet.h"
#import "AppDelegate.h"
#import "GKVersionUpViewController.h"
#import "BBBViewController.h"
@interface GKUserInfoCViewController ()
{
    NSString *_url;
}
@end

@implementation GKUserInfoCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _titleLabel.text=@"个人中心";
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"userInfo" tag:self];
    _userInfoView.userDataBlock=_userDataBlock;
    [_userInfoView startLoad];
    
    XCAddObserver(_userInfoView,userCodeModify, @selector(userCodeModify));
    XCAddObserver(_userInfoView,versionUpDate, @selector(versionUpdate:));
    XCAddObserver(_userInfoView,exitApp, @selector(exitApp));
    XCAddObserver(_userInfoView,headImgClick, @selector(headImgChange:));
    
    XCAddObserver(_userInfoView,test, @selector(testAA));


}
- (void)testAA{
    
      BBBViewController * AAA = [[BBBViewController alloc] init];
    [self.navigationController pushViewController:AAA animated:YES];
//    [self closeDelay:2.];
//    [UIView animateWithDuration:3 animations:^{
//        UIAlertView * aa = [[UIAlertView alloc] initWithTitle:@"test" message:@"1111" delegate:self cancelButtonTitle:@"1111" otherButtonTitles:@"ok", nil];
//        [aa show];
//    }];
    
}



//用户密码修改
-(void)userCodeModify
{
    GKPasswordViewController *passWordControllrt=[[GKPasswordViewController alloc]init];
    passWordControllrt.pushType=isPush;
    [self.navigationController pushViewController:passWordControllrt animated:YES];
    [passWordControllrt release];
}
//版本更新
-(void)versionUpdate:(XCDataBlock*)dataBlock
{

    GKVersionUpViewController *version=[[GKVersionUpViewController alloc]init];
    version.pushType=isPush;
    version.dataBlock=dataBlock;
    [self.navigationController pushViewController:version animated:YES];
    [version release];
    
    
}

//退出
-(void)exitApp
{
   
    AppDelegate * appdelegate = [UIApplication  sharedApplication].delegate;
    appdelegate.userImg=nil;
    [appdelegate guestLogin];
 
    
}
-(void)headImgChange:(XCDataBlock *)userDateblock
{
    NSLog(@"%@",userDateblock.data);
   
    [[STCameraSheet CameraSheet] CameraWithController:self editing:Editing onDismiss:^(UIImage *cameraImage) {
        _userInfoView.headImg.image = cameraImage;
       AppDelegate * appdelegate = [UIApplication  sharedApplication].delegate;
        appdelegate.userImg=cameraImage;
        [_userInfoView changeUserImg:cameraImage];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"mytest"object:cameraImage];
    

    } onError:^(NSString *str) {
        
    }];


}

@end
