//
//  STOrderDetailViewController.h
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STOrderDetailView.h"

@interface STOrderDetailViewController : XCSuperObjectViewController

@property (nonatomic,assign) STOrderDetailView *orderDetailView;
@property (nonatomic,retain) XCDataBlock *block;
@end
