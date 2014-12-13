//
//  BBBViewController.m
//  VTBksd
//
//  Created by zcyx on 14-12-12.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "BBBViewController.h"

@interface BBBViewController ()

@end

@implementation BBBViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor blueColor];
    _titleLabel.text = @"测试";
//    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"test" tag:self];
//    
//    [_testView startLoad];
    
    XCAutoLayoutRoot *css = [XCAutoLayoutController getLayoutFilePathDataXML:@"@aa.xml" settings:nil frameWarehouse:[VTFrameWarehouse sharedWarehouse]];
    XCAutoLayoutController * autolayout = [[XCAutoLayoutController alloc] initWithView:self.view layoutRoot:css settings:nil];
    [autolayout settingOutlet:self];
    
   
    UITapGestureRecognizer *codetap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(codeModify)];
    _img.userInteractionEnabled = YES;
    [_img addGestureRecognizer:codetap];
   
    [_btn addTarget:self action:@selector(codeModify) forControlEvents:UIControlEventTouchUpInside];
    NSLog(@"%@",_btn);
    NSLog(@"%@",_img);
    
}
 - (void)codeModify
{
     NSLog(@"OOOOO");
    
}











- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
