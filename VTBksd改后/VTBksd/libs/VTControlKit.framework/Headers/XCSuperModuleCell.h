//
//  XCSuperModuleCell.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutController.h"
#import "XCAutoLayoutProtocol.h"

typedef enum {
    xHeadTapEven,            //头像点击
    xOptBtnEven,                //按钮点击
    xMoreBtnEven                //按钮点击
} XCSuperModuleCellEven;

@interface XCSuperModuleCell : UITableViewCell<XCModuleProtocol>
{
    XCAutoLayoutController *_autoLayout;
}
@property (nonatomic,assign) XCAutoLayoutRoot *css;
@property (nonatomic,readonly) XCAutoLayoutController *autoLayout;
@property (nonatomic,assign) UIImageView *headView;
@property (nonatomic,assign) UIButton    *optBtn;
@property (nonatomic,assign) UIButton    *moreBtn;

- (void)startLoad;


//事件重写
- (void)headClick:(UITapGestureRecognizer *)tap;
- (void)optBtnClick:(UIButton *)btn;
- (void)moreBtnClick:(UIButton *)btn;
@end
