//
//  STAutoKeyBoardSuperView.h
//  testKeyBord
//
//  Created by steve on 14-9-3.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCSuperModuleView.h"

@interface STAutoKeyBoardSuperView : XCSuperModuleView
{
    UIScrollView *_superScrollView;
    UIView *_stAutokeyView;
    CGRect _stAutokeyViewRect;
}
@end
