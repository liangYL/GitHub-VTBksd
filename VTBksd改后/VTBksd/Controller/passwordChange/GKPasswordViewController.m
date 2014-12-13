//
//  GKPasswordViewController.m
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKPasswordViewController.h"

@interface GKPasswordViewController ()

@end

@implementation GKPasswordViewController
- (void)dealloc
{
    [super dealloc];
}
- (void)viewDidLoad {

    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    _titleLabel.text=@"密码修改";
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"password" tag:self];
    [_passwordView startLoad];
    
    XCAddObserver(_passwordView, saveCode, @selector(saveCode));
}
-(void)saveCode
{
    [self closeDelay:2.];

}

@end
