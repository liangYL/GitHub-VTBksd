//
//  XCSuperObjectViewController.h
//  xmData
//
//  Created by wxc on 13-10-20.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum{
    isPush,
    isModel,
    isPushMain
}XCPushType;

//导航字体
#define NAV_TITLE_FONT      [UIFont systemFontOfSize:16]
#define NAV_navClose        @"navClose.png"
#define NAV_navBack         @"navBack.png"

@interface XCSuperObjectViewController : UIViewController
{
    XCPushType _pushType;
    UILabel    *_titleLabel;
}
@property (nonatomic,assign) XCPushType pushType;
@property (nonatomic,retain) NSMutableDictionary *formParams;

- (void)close;
- (void)closeDelay:(NSTimeInterval)delay;
@end
