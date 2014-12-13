//
//  STButtonView.h
//  BYServe
//
//  Created by steve on 14-8-20.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STButtonView : UIView<XCAutoLayoutProtocol>
{
    UIButton *_button;
    NSString *_title;
    UIImage *_backgroundImage;
    UIFont *_titleFont;
    UIColor *_titleColor;
}
@property (nonatomic,retain)UIButton *button;
@property (nonatomic,copy)NSString *title;
@property (nonatomic,retain)UIImage *backgroundImage;
@property (nonatomic,retain)UIFont *titleFont;
@property (nonatomic,retain)UIColor *titleColor;
@property (nonatomic,assign)NSInteger titleAlignment;
@end
