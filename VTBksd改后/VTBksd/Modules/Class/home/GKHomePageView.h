//
//  GKHomePageView.h
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VTControlKit/STMultifunctionImageView.h>
#import <VTControlKit/STStarRatingView.h>
#import <VTControlKit/XCPullScrollView.h>
typedef enum {
        userInfoEvent,        //用户信息
        waitingOrderEvent,     //待送
        alreadyOrderEvent,    //已送
        dealersEvent,         //经销商

}GKHomePageViewEvent;

@interface GKHomePageView : XCSuperModuleView<XCPullScrollViewDelegate>
{

    XCDataBlock *_userRowDataBlock;
    NSInteger   _waitNum;
    NSInteger   _alreadNum;
    
}
@property(nonatomic,assign)STStarRatingView*userStar;
@property(nonatomic,assign)UIView *userInfoView;
@property(nonatomic,assign)UIView *contView;
@property(nonatomic,assign)UIView *WaitingOrderView;
@property(nonatomic,assign)UIView *alreadyOrderView;
@property(nonatomic,assign)UIView *dealersView;
@property(nonatomic,assign)UIView *personInfoView;
@property(nonatomic,assign)STMultifunctionImageView*WaitingOrderImg;
@property(nonatomic,assign)STMultifunctionImageView*alreadyOrderImg;
@property(nonatomic,assign)UIImageView *headImg;
@property(nonatomic,assign)XCPullScrollView *scrollView;
@end
