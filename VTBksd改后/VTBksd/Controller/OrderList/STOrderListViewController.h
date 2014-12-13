//
//  STOrderListViewController.h
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STListView.h"

@interface STOrderListViewController : XCSuperObjectViewController


@property (nonatomic,assign) STListView *orderListView;
@property(nonatomic,copy)NSString *titile;
@property(nonatomic,retain)NSMutableArray *parmArray;
@end
