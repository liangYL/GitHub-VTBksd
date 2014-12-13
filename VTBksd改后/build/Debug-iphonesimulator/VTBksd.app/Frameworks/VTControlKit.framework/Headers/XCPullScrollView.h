//
//  XCPullScrollView.h
//  XCPullTable
//
//  Created by wxc on 13-12-26.
//  Copyright (c) 2013年 wxc. All rights reserved.
//

#import "XCPull.h"
#import "XCPullView.h"
#import "XCAutoLayoutProtocol.h"

@protocol XCPullScrollViewDelegate;
@interface XCPullScrollView : UIScrollView
{
    __block XCPullView  *_topView;
    __block XCPullView  *_downView;
    
    CGFloat     _checkTopH;
    CGFloat     _checkDownH;
    
    BOOL        _topHide;
    BOOL        _downHide;
    
    void (^pullLoad)(UIScrollView *);
    void (^moreLoad)(UIScrollView *);
    
    id<XCPullScrollViewDelegate> _isDelegate;
}
@property (nonatomic,assign) CGFloat checkTopH,checkDownH;
@property (nonatomic,assign,setter = isTopHide:) BOOL topHide;
@property (nonatomic,assign,setter = isDownHide:) BOOL downHide;
@property (nonatomic,copy) void (^pullLoad)(UIScrollView *);
@property (nonatomic,copy) void (^moreLoad)(UIScrollView *);
@property (nonatomic,assign) id<XCPullScrollViewDelegate> isDelegate;
@property (nonatomic,retain) XCPullView *topView,*downView;
@property (nonatomic,copy) NSString *pullTopClass,*pullDownClass;

- (void)layoutDidFinished:(UIView *)view;
- (id)initWithFrame:(CGRect)frame pullTopView:(XCPullView *)pullTopView pullDownView:(XCPullView *)pullDownView;

- (void)finishLoad;
- (void)launchRefreshing;
- (void)launchLoadMore;
- (void)notMoreData:(BOOL)v;
- (void)notLoadData:(BOOL)v;


- (void)tableViewDidFinishedLoadingWithMessage:(NSString *)msg toView:(UIView *)aView dure:(CGFloat)dure image:(UIImage *)image;
- (void)tableViewDidFinishedLoadingWithMessage:(NSString *)msg dure:(CGFloat)dure image:(UIImage *)image;
- (void)tableViewDidFinishedLoadingWithMessage:(NSString *)msg image:(UIImage *)image;
@end

@protocol XCPullScrollViewDelegate <NSObject>
- (void)pullScrollViewPullLoad:(UIScrollView *)scroll;
- (void)pullScrollViewMoreLoad:(UIScrollView *)scroll;
@end

