//
//  XCPullView.h
//  XCPullTable
//
//  Created by wxc on 14-1-10.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "XCPull.h"

@interface XCPullView : UIView
{
    SystemSoundID _normalId;
    SystemSoundID _pullId;
    SystemSoundID _refreshingId;
    SystemSoundID _endRefreshId;
}
- (void)initView;

- (SystemSoundID)loadId:(NSString *)filename;

/**
 *当刷新控件将要出现时调用
 *@param scrollView对象
 */
- (void)pullWillDisplay:(UIScrollView *)scrollView;

/**
 *当刷新控件在滑动检查范围滑动时 向上滑动
 *@param scrollView对象 y滑动值
 */
- (void)pullDidScrollUp:(UIScrollView *)scrollView y:(NSInteger)y;

/**
 *当刷新控件在滑动检查范围滑动时 向下滑动
 *@param scrollView对象 y滑动值
 */
- (void)pullDidScrollDown:(UIScrollView *)scrollView y:(NSInteger)y;
/**
 *当刷新控件检查可以刷新时调用
 *@param scrollView对象
 */
- (void)pullDidLoad:(UIScrollView *)scrollView;

/**
 *当刷新控件检查不可以刷新时调用
 *@param scrollView对象
 */
- (void)pullNotLoad:(UIScrollView *)scrollView;

/**
 *当刷新控件检查确认刷新时调用
 *@param scrollView对象
 */
- (void)pullDidConfirmLoad:(UIScrollView *)scrollView;

/**
 *当刷新控件检查刷新完成后调用
 *@param scrollView对象
 */
- (void)pullDidFinished:(UIScrollView *)scrollView;

/**
 *当刷新控件将要消失时调用
 *@param scrollView对象
 */
- (void)pullWillDisappear:(UIScrollView *)scrollView;

/**
 *设置刷新控件无数据可刷新
 *@param scrollView对象
 */
- (void)pullNotData:(UIScrollView *)scrollView;


- (void)layoutSubviews;
@end