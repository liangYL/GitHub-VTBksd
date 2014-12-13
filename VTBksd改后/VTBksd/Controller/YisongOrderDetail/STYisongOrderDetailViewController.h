//
//  STYisongOrderDetailViewController.h
//  VTBksd
//
//  Created by steve on 14/11/8.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STOrderDetailView.h"

@interface STYisongOrderDetailViewController : XCSuperObjectViewController

@property (nonatomic,assign) STOrderDetailView *orderDetailView;
@property (nonatomic,retain) XCDataBlock *block;
@end
