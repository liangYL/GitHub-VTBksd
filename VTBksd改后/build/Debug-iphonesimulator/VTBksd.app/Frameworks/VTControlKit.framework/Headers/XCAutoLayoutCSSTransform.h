//
//  XCAutoLayoutCSSTransform.h
//  testAutoLayout
//
//  Created by wxc on 14-8-19.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*间距 上 左 下 右*/
struct XCPadding {
    float top;
    float left;
    float bottom;
    float right;
};
typedef struct XCPadding XCPadding;

struct XCMargin {
    float top;
    float left;
    float bottom;
    float right;
};
typedef struct XCMargin XCMargin;


CG_INLINE XCPadding XCPaddingMake(float top, float left,float bottom,float right);
CG_INLINE XCPadding
XCPaddingMake(float top, float left,float bottom,float right)
{
    XCPadding p; p.top = top; p.left = left;p.bottom = bottom;p.right = right; return p;
}

CG_INLINE XCMargin XCMarginMake(float top, float left,float bottom,float right);
CG_INLINE XCMargin
XCMarginMake(float top, float left,float bottom,float right)
{
    XCMargin p; p.top = top; p.left = left;p.bottom = bottom;p.right = right; return p;
}


@interface XCAutoLayoutCSSTransform : NSObject

+ (XCPadding)getPadding:(NSString *)str;
+ (XCMargin)getMargin:(NSString *)str;
//frame  "0,0,100,100"
+ (CGRect)getFrameByStr:(NSString *)str;
//SIZE
+ (CGSize)getSizeByStr:(NSString *)str;
//UIColor   "0.1,0.3,0.4,1.0"
+ (UIColor *)getColorByStr:(NSString *)str;
//UIImage   "xxx.png"
+ (UIImage *)getImageByStr:(NSString *)str;
//UIFont    "System,17.0"
+ (UIFont *)getFontByStr:(NSString *)str;

//UITextAlignment    "UITextAlignmentLeft"
+ (NSString *)getTextAlignmentByStr:(NSString *)str;
#pragma mark -
#pragma mark 边框设置
//radius 圆角
+ (void)setBorder:(NSString*)style view:(UIView *)view;
//阴影
+ (void)setBorderShadow:(NSString *)style view:(UIView *)view;
@end
