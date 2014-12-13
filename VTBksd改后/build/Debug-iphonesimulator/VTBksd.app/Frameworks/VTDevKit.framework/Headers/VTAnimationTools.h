//
//  XCAnimationTools.h
//  XCTools
//
//  Created by wxc on 13-11-26.
//  Copyright (c) 2013年 apple. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface VTAnimationTools : NSObject
//UIView 动画
+ (void)uiViewAnimationTransition:(UIView *)toView typeIndex:(NSInteger)typeIndex duration:(NSTimeInterval)duration animation:(void(^)(void))animation;

//CATransition 动画
+ (void)cATransitionAnimation:(UIView *)toView typeIndex:(NSInteger)typeIndex subTypeIndex:(NSInteger)subTypeIndex duration:(NSTimeInterval)duration animation:(void(^)(void))animation;
@end
