//
//  STOrderListViewController.m
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STOrderListViewController.h"
#import "STOrderDetailViewController.h"
#import "STYisongOrderDetailViewController.h"

@interface STOrderListViewController ()

@end

@implementation STOrderListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    _titleLabel.text = _titile;
    [[VTModuleAssemblyFactory sharedModuleAssemblyFactory] assemblyPage:@"STOrderList" tag:self];
    _orderListView.paramArray = _parmArray;
    [_orderListView startLoad];
    
    
    XCAddObserver(_orderListView, STListViewCellClick, @selector(listClick:));
}


- (void)listClick:(XCDataBlock *)block
{
    [block getData];
    NSNumber *i = [block.data objectForKey:@"statusid"];
    int state = i.intValue;

    if (state == 4 || state ==3)
    {
        STOrderDetailViewController *orderDetailVC = [[STOrderDetailViewController alloc] init];
        orderDetailVC.block = block;
        orderDetailVC.pushType=isPush;
        [self.navigationController pushViewController:orderDetailVC animated:YES];
        [orderDetailVC release];
    }
    else if (state == 5)
    {
        STYisongOrderDetailViewController *yisongOrderDetailVC = [[STYisongOrderDetailViewController alloc] init];
        yisongOrderDetailVC.block = block;
        yisongOrderDetailVC.pushType=isPush;
        [self.navigationController pushViewController:yisongOrderDetailVC animated:YES];
        [yisongOrderDetailVC release];
    }
    
}

@end
