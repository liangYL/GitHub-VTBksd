//
//  QuadCurveMenu.h
//  AwesomeMenu
//
//  Created by Levey on 11/30/11.
//  Copyright (c) 2011 lunaapp.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QuadCurveMenuItem.h"

@protocol QuadCurveMenuDelegate;

@interface QuadCurveMenu : UIView <QuadCurveMenuItemDelegate>
{
    NSArray *_menusArray;
    int _flag;
    NSTimer *_timer;
    QuadCurveMenuItem *_addButton;
    
    id<QuadCurveMenuDelegate> _delegate;
    
    CGPoint _startPoint;
}
@property (nonatomic, copy) NSArray *menusArray;
@property (nonatomic, getter = isExpanding)     BOOL expanding;
@property (nonatomic, assign) id<QuadCurveMenuDelegate> delegate;
@property (nonatomic, assign) CGPoint startPoint;
- (id)initWithFrame:(CGRect)frame menus:(NSArray *)aMenusArray;
- (id)initWithFrame:(CGRect)frame menus:(NSArray *)aMenusArray startPoint:(CGPoint)startPoint;
@end

@protocol QuadCurveMenuDelegate <NSObject>
@optional
- (void)quadCurveMenu:(QuadCurveMenu *)menu didSelectIndex:(NSInteger)idx;
@end