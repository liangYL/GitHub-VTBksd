//
//  XCPartsLoadMsgProtocol.h
//  XCAddressBook
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//数据获取提示配件协议

#import <UIKit/UIKit.h>

@protocol XCLoadMsgPartsProtocol <NSObject>
@required
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

@optional
- (void)dismissS:(UIView *)view ; //消失

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