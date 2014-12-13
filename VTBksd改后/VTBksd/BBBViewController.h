//
//  BBBViewController.h
//  VTBksd
//
//  Created by zcyx on 14-12-12.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "testView.h"
@interface BBBViewController : XCSuperObjectViewController
@property (nonatomic,assign) testView *testView;

@property (nonatomic,retain) UILabel *label;
@property (nonatomic,assign) UIImageView *img;
@property (nonatomic,assign) UIButton * btn;


@end
