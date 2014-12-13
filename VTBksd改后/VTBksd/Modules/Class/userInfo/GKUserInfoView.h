//
//  GKUserInfoView.h
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VTControlKit/STButtonView.h>
#import <VTControlKit/STStarRatingView.h>
typedef enum {
    userCodeModify,  //用户密码修改
    versionUpDate,   //版本升级
    exitApp,          //退出
    headImgClick,
    test
    
}GKUserInfoViewEvent;
@interface GKUserInfoView : XCSuperModuleView
@property(nonatomic,assign)XCDataBlock *userDataBlock;
@property(nonatomic,assign)UIView *codeModifyView;
@property(nonatomic,assign)UIView *versionView;
@property(nonatomic,assign)STButtonView*exitButton;
@property(nonatomic,assign)STStarRatingView*userStar;
@property(nonatomic,assign)STButtonView*testButton;


@property(nonatomic,assign)UIImageView*headImg;
-(void)changeUserImg:(UIImage *)img;
@end
