//
//  XCAlertView.h
//  弹出框低2版
//
//  Created by wxc on 13-9-10.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCRealTimeBlurView.h"

#define AlertShowing @"AlertShowing"
#define AlertDidHide @"AlertDidHide"

typedef enum {
    xNotBlur,            //默认状态 没有模糊效果
    xBgBlur,             //整个背景模糊
    xContentBlur        //内容区模糊
} XCAlertViewBlurStyle;

typedef enum {
    xAlert,            //默认状态 没有模糊效果
    xBottomPush
} XCAlertViewBlurAnimationType;

@interface XCAlertView : UIView
{

    UIView      *_toView;
    
    UIView      *_alertView;     //alertView
    UIView      *_contentView;
    
    XCAlertViewBlurStyle _blurStyle;
    
    BOOL        _isAnimationing; //是否正在动画;
    
    BOOL        _isNotHide;
}
@property (nonatomic,readonly) UIView *alertView,*contentView;
@property (nonatomic,assign) BOOL isNotHide;

/**
 *alert初始化方法
 *@param contentView要显示的内容view blurStyle模糊类型 alertRect弹出内容的rect toView在那个view上显示 blurView模糊设置
 */
- (XCAlertView *)initWithAlertInView:(UIView *)contentView blurStyle:(XCAlertViewBlurStyle)blurStyle alertRect:(CGRect)alertRect toView:(UIView *)toView blurValue:(XCRealTimeBlurValue)blurValue;

/**
 *alert隐藏方法
 *@param de延迟隐藏
 */
- (void)hideAlertView:(NSTimeInterval)de;
- (void)hideAlertView;

/**
 *alert出现
 */
- (void)showAlert;
- (void)showAlert:(XCAlertViewBlurAnimationType)type;
@end
