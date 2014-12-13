//
//  GKVersionUpViewController.m
//  VTBksd
//
//  Created by GK on 14-11-15.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "GKVersionUpViewController.h"
@interface GKVersionUpViewController ()
{
    NSString *_url;
}
@end
@interface GKVersionUpViewController ()

@end

@implementation GKVersionUpViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor=[UIColor whiteColor];
    _titleLabel.text=@"版本升级";
    [self checkVersion];
    
    
    
   
}
-(void)checkVersion
{
    if (self.dataBlock.data !=nil && self.dataBlock.data !=[NSNull null]){
        
        NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"];
        
        NSString *newVersion=[[self.dataBlock.data objectAtIndex:0]objectForKey:@"version_code"];
        
        if ([newVersion compare:appVersion options:NSNumericSearch] == NSOrderedDescending)
        {
            _url = [[self.dataBlock.data objectAtIndex:0] objectForKey:@"update_file"];
            
            UILabel *label=[[UILabel alloc]initWithFrame:CGRectMake(60, 40, 200, 20)];
            label.text=@"发现新版本，请立即升级!";
            label.textAlignment=NSTextAlignmentCenter;
            label.backgroundColor=[UIColor clearColor];
            [self.view addSubview:label];
            [label release];
            
            UIButton *btn=[[UIButton alloc]initWithFrame:CGRectMake(15, label.frame.origin.y+label.frame.size.height+50, 290, 40)];
            btn.backgroundColor=[UIColor colorWithRed:0.18 green:0.70 blue:0.47 alpha:1.0];
            [btn setTitle:@"立即升级" forState:UIControlStateNormal];
            btn.titleLabel.font=[UIFont systemFontOfSize:17];
            [btn addTarget:self action:@selector(upVersion) forControlEvents:UIControlEventTouchUpInside];
            [self.view addSubview:btn];
            [btn release];
           
        }
        else
        {
            UILabel *label=[[UILabel alloc]initWithFrame:CGRectMake(60, 40, 200, 20)];
            label.text=@"您的版本已是最新!";
            label.textAlignment=NSTextAlignmentCenter;
            label.backgroundColor=[UIColor clearColor];
            [self.view addSubview:label];
            [label release];
            
            UIButton *btn=[[UIButton alloc]initWithFrame:CGRectMake(15, label.frame.origin.y+label.frame.size.height+50, 290, 40)];
            btn.backgroundColor=[UIColor colorWithRed:0.18 green:0.70 blue:0.47 alpha:1.0];
            [btn setTitle:@"检查新版本" forState:UIControlStateNormal];
            btn.titleLabel.font=[UIFont systemFontOfSize:17];
            [btn addTarget:self action:@selector(check) forControlEvents:UIControlEventTouchUpInside];
            [self.view addSubview:btn];
            [btn release];
       
        }
        
        
    }

}
-(void)upVersion
{
 
 [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[_url stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]]]];


}
-(void)check
{
    UIAlertView *alter=[[UIAlertView alloc]initWithTitle:@"版本更新" message:@"已是最新版本" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
    [alter show];
    [alter release];


}


@end
