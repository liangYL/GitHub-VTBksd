//
//  XCDataLoadMsg.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCLoadMsgPartsProtocol.h"

@interface XCDataLoadMsg : NSObject<XCLoadMsgPartsProtocol>

- (void)dismiss:(UIView *)view ; //消失

/**
 *加载中
 */
- (void)showLoadingToView:(UIView *)view parms:(id)parms;

/**
 *加载失败 网络不通
 */
- (void)loadingNotNetWorkToView:(UIView *)view parms:(id)parms evn:(void (^)(id obj))evn;

/**
 *加载失败
 */
- (void)loadingErrorToView:(UIView *)view parms:(id)parms evn:(void (^)(id obj))evn;

#pragma mark -

+ (void)dismissS:(UIView *)view ; //消失

/**
 *加载中
 */
+ (void)showLoadingToViewS:(UIView *)view parms:(id)parms;

/**
 *加载失败 网络不通
 */
+ (void)loadingNotNetWorkToViewS:(UIView *)view parms:(id)parms evn:(void (^)(id obj))evn;

/**
 *加载失败
 */
+ (void)loadingErrorToViewS:(UIView *)view parms:(id)parms evn:(void (^)(id obj))evn;
@end


//加载中
@interface XCLoadingMsg : UIView
@property (nonatomic,retain) UIImage *bgImage;
@property (nonatomic,copy) NSString *title;

- (void)loadView;
@end

//加载失败
@interface XCLoadingError : UIView
@property (nonatomic,retain) UIImage *errorImg,*bgImage;
@property (nonatomic,copy) NSString *errorTitle,*errorSubtitle;
@property (nonatomic,copy) void (^evn)(id obj);

- (void)loadView;
@end
