//
//  STKeyValueView.h
//  KeyValue
//
//  Created by steve on 14-8-14.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STKeyValueView : UIView<XCAutoLayoutProtocol>
{
    float _keyWidth;
    float _valueWidth;
    float _space;
    UIView *_keyView;
    UIView *_valueView;
}
@property (nonatomic,assign)float space,keyWidth;

@property (nonatomic,retain) UIFont *leftFont,*rightFont;
@property (nonatomic,retain) UIColor *leftColor,*rightColor;
@property (nonatomic,assign) NSInteger leftTextAlignment,rightTextAlignment;

- (id)init;
- (void)layout;
- (void)layoutDidFinished:(UIView *)view;
@end
