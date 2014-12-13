//
//  VTDevUtil.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-25.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface VTDevUtil : NSObject

//创建返回retain
+ (id)newXIBClass:(NSString *)fileName aClass:(Class)aClass owner:(id)owner options:(NSDictionary *)options;

/**
 *
 */
+ (BOOL)checkError:(id)obj;


/**
 *计算某个UIViewController的工作区域高度自适应 4-4.5屏幕
 *@param viewController要计算的视图控制器
 *@return 返回一个工作区域Rect
 */
+ (CGRect)workspaceRect:(UIViewController *)viewController;

/**
 *创建UUID
 */
+ (NSString *)createGuid;
/**
 *创建一个CUID
 *@param
 */
+ (NSString *)createCUID:(NSString *)prefix;
/**
 *隐藏键盘
 *@param view
 */
+ (void)autohideKeyBoard:(UIView *)view;

#pragma mark -
#pragma mark 格式化时间
#define YYMMDDHHMM @"yy-MM-dd HH:mm"
#define HH_DEFAULT_TIME_FORM @"HH:mm"
#define DEFAULT_TIME_FORM @"MM/dd HH:mm"
#define DEFAULT_TIME_FORM1 @"MM-dd HH:mm"
#define YY_DEFAULT_TIME_FORM @"yyyy-MM-dd"
#define ALL_DEFAULT_TIME_FORM @"yyyy-MM-dd HH:mm:ss"
#define ALL_DEFAULT_TIME_FORM_FFF @"yyyy-MM-dd HH:mm:ss.SSS"
+ (NSString *)dateFormatter:(NSDate *)date format:(NSString *)format;
+ (NSDate *)stringToDate:(NSString *)str format:(NSString *)format;

+ (CGFloat)layoutNorm:(NSArray *)views margin:(CGPoint)margin addView:(UIView *)addView;
+ (CGFloat)layoutNorm:(NSArray *)views splite:(CGPoint)splite addView:(UIView *)addView;

//+ (CGFloat)linearAuto:(UIView *)view split:(CGFloat)split;

#pragma mark -
#pragma mark 验证
//验证不为空 YES是空
+ (BOOL)isNotNull:(NSString *)str;
//验证手机号
+ (BOOL)isMobileNumber:(NSString *)mobileNum;
/**
 *验证邮箱
 *@return YES是邮箱格式 NO不是邮箱格式
 */
#define xcCheckEmail @"\\b([a-zA-Z0-9%_.+\\-]+)@([a-zA-Z0-9.\\-]+?\\.[a-zA-Z]{2,6})\\b"
+ (BOOL)checkEmail:(NSString *)str;
/**
 *验证网站
 *@return YES是网站 NO不是网站
 */
#define xcCheckHttp  @"^((https?|ftp|news):\\/\\/)?([a-z]([a-z0-9\\-]*[\\.。])+([a-z]{2}|aero|arpa|biz|com|coop|edu|gov|info|int|jobs|mil|museum|name|nato|net|org|pro|travel)|(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]))(\\/[a-z0-9_\\-\\.~]+)*(\\/([a-z0-9_\\-\\.]*)(\\?[a-z0-9+_\\-\\.%=&]*)?)?(#[a-z][a-z0-9_]*)?$"
+ (BOOL)checkHttpPag:(NSString *)str;
/**
 *只能是数字
 *@return YES NO
 */
#define xcCheckN  @"^[0-9]*$"
+ (BOOL)checkN:(NSString *)str;

/**
 *只能是n位的数字 n-m之间位数 至少n位数
 *@return YES NO
 */
#define xcCheckNN(n) [NSString stringWithFormat:@"^d{%d}$",n]
+ (BOOL)checkNN:(NSString *)str n:(int)n;
#define xcCheckNToM(n,m) [NSString stringWithFormat:@"^d{%d,%d}$",n,m]
+ (BOOL)checkNToM:(NSString *)str n:(int)n m:(int)m;
#define xcCheckNAtLeastN(n)  [NSString stringWithFormat:@"^d{%d,}$",n]
+ (BOOL)checkNAtLeastN:(NSString *)str n:(int)n;

/**
 *只能是汉字
 *@return YES NO
 */
#define xcCheckChineseCharacter  @"^[u4e00-u9fa5],{0,}$"
+ (BOOL)checkChineseCharacter:(NSString *)str;
@end

