//
//  STTimeButtonView.h
//  CreatKongjian
//
//  Created by steve on 14-9-5.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//带计时器的btn按钮，点击之后开始计时，计时期间不能再次点击；计时结束之后，恢复点击事件

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STTimeButtonView : UIView<XCAutoLayoutProtocol>
{
    UIButton *_button;
    NSString *_title;
    
    NSTimer *_timer;
    NSInteger _timerNumber;
    
    int _timerNumberIng;
    UIImage *_backgroundImage;
    UIFont *_font;
    UIColor *_titleColor;
}
@property (nonatomic,retain) UIButton *button;
@property (nonatomic,copy) NSString *title;//btn title
@property (nonatomic,assign) NSInteger timerNumber;//计时时间

@property (nonatomic,retain) UIImage *backgroundImage;//btn背景图片
@property (nonatomic,retain) UIFont *font;//title font
@property (nonatomic,retain) UIColor *titleColor;//title color
@end
