//
//  STGuestLoginViewController.m
//  VTVMall
//
//  Created by steve on 14-10-15.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import "STGuestLoginViewController.h"
#import <VTX/XCEvent.h>
#import "AppDelegate.h"

@interface STGuestLoginViewController ()

@end

@implementation STGuestLoginViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _titleLabel.text=@"登录";

}

- (void)loadXML
{
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"login" tag:self];
    
    [_loginView startLoad];
    
    XCAddObserver(_loginView, loginBtnClick, @selector(LoginSucceed));
    
}

- (void)LoginSucceed
{

        AppDelegate * appdelegate = [UIApplication  sharedApplication].delegate;
        
        [appdelegate showMain];

        VTLogInfo(@"*****");
  
}


@end
