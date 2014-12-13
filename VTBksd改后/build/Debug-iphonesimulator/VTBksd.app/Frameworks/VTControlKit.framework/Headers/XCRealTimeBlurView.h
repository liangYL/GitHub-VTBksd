//
//  XCRealTimeBlurView.h
//  弹出框低2版
//
//  Created by wxc on 13-9-11.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>

struct XCRealTimeBlurValue {
    float blur;         //模糊率
    float radius;          //圆角
    float fps;              //刷新频率
    float transparency;   //透明度
};
typedef struct XCRealTimeBlurValue XCRealTimeBlurValue;

static XCRealTimeBlurValue XCRealTimeBlurValueMark(float blur, float radius,float fps,float transparency)
{
    XCRealTimeBlurValue value; value.blur = blur; value.radius = radius ;value.fps = fps; value.transparency = transparency; return value;
}


@interface XCRealTimeBlurView : UIView
{
    UIView    *_screenView;
    CALayer   *_tintLayer;
    UIColor   *_tint;
    
    BOOL      _renderStatic;
    
    XCRealTimeBlurValue _value;
    CGRect    _sFrame;
}
@property (nonatomic, assign) BOOL renderStatic;
@property (nonatomic,retain,readonly) UIView *screenView;
@property (nonatomic,readonly) CALayer *tintLayer;
@property (nonatomic,readonly) UIColor *tint;

- (id)initWithFrame:(CGRect)frame screenView:(UIView *)screenView blurValue:(XCRealTimeBlurValue)blurValue sFrme:(CGRect)sFrme;

@end


@interface XCRealTimeBlurViewManager : NSObject
{
    CGFloat _fps;
    NSMutableArray *_views;
}
@property (nonatomic,readonly) NSMutableArray *views;
@property (nonatomic,assign) CGFloat fps;

+ (id)sharedManager;

- (void)registerView:(XCRealTimeBlurView *)view fps:(CGFloat)fps;
- (void)deregisterView:(XCRealTimeBlurView *)view;

@end