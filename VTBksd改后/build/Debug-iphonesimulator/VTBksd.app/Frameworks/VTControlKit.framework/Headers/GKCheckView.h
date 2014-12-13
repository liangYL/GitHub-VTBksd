//
//  GKCheckView.h
//  IBS-DEV
//
//  Created by GK on 14-4-28.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol GKCheckViewDelegate;


@interface GKCheckView : UIView
{
    BOOL       _isCheck;
    UIButton  *_checkButton;
    
    id<GKCheckViewDelegate> _delegate;


}
@property (nonatomic,assign) id<GKCheckViewDelegate> delegate;
@property (nonatomic,assign) BOOL isCheck;
- (id)initWithFrame:(CGRect)frame norImage:(UIImage *)norImage checkImage:(UIImage *)checkImage;

- (void)setCheck:(BOOL)val;
- (void)checkButtonClick;
@end
@protocol GKCheckViewDelegate <NSObject>
@optional
- (void)checkChange:(GKCheckView *)object val:(BOOL)val;
@end
