//
//  STOrderDetailViewController.m
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STOrderDetailViewController.h"

@interface STOrderDetailViewController ()

@end

@implementation STOrderDetailViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _titleLabel.text=@"订单详情";
    
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"STOrderDetail" tag:self];
    _orderDetailView.block = _block;
    [_orderDetailView startLoad];
}

@end
