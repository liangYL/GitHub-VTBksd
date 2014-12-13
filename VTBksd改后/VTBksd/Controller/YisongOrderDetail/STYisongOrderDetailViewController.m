//
//  STYisongOrderDetailViewController.m
//  VTBksd
//
//  Created by steve on 14/11/8.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STYisongOrderDetailViewController.h"

@interface STYisongOrderDetailViewController ()

@end

@implementation STYisongOrderDetailViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _titleLabel.text=@"订单详情";
    
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"STYisongOrderDetail" tag:self];
    _orderDetailView.block = _block;
    [_orderDetailView startLoad];
}

@end
