//
//  STStarRatingView.h
//  CreatKongjian
//
//  Created by steve on 14-9-10.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STStarRatingView : UIView<XCAutoLayoutProtocol>
{
    UIView *_starBackgroundView;
    UIView *_starForegroundView;
    float _percent;
    int _starNumber;
}
@property (nonatomic,assign)float percent;
@property (nonatomic,assign)int starNumber;
@property (nonatomic,copy) NSString *backgroundStar;
@property (nonatomic,copy) NSString *foregroundStar;

@property (nonatomic,assign) NSInteger isUIE;//0,不可编辑;  1,可编辑;
@end
