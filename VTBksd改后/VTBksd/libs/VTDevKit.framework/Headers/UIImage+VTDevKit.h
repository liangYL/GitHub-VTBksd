//
//  XCImage.h
//  XCTools
//
//  Created by wxc on 13-11-26.
//  Copyright (c) 2013年 apple. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface  UIImage (VTDevKit)
/**
 *将一个图片转换成Base64编码的字符串
 *@return Base64编码字符串
 */
- (NSString *)imageTransToBase64String; //默认压缩度0.1
- (NSString *)imageTransToBase64String:(CGFloat)r; //r压缩度

/**
 *将一个相机拍摄到的照片图片进行方向的矫正
 *@return 一个矫正好的图片
 */
- (UIImage *)fixOrientation;

/**
 *创建一个纯色的图片
 *param color要创建图片的颜色 andSize图片大小
 *@return 创建好的纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color andSize:(CGSize)size;

#pragma mark -
#pragma mark 切割图片
/**
 *图片剪切 自适应剪切-- 会自动根据传入size范围切割图片 图片自动缩略切割
 *param size剪切范围
 *@return 剪切好的新图片
 */
- (UIImage *)autoOriginImage:(CGSize)size;

/**
 *图片剪切 拉伸剪切-- 会自动根据传入的size拉伸图片 上下铺满
 *param size剪切范围
 *@return 剪切好的新图片
 */
- (UIImage *)originImage:(CGSize)size;

/**
 *图片剪切 居中剪切
 *param size居中剪切范围
 *@return 剪切好的新图片
 */
- (UIImage *)cutImage:(CGSize)size;

/**
 *图片剪切 自适应高的剪切
 *param height高
 *@return 剪切好的新图片
 */
- (UIImage *)autoHeightOriginImg:(float)height;

/**
 *图片剪切 自适应宽的剪切
 *param width宽
 *@return 剪切好的新图片
 */
- (UIImage *)autoWidthOriginImg:(float)width;

/**
 *剪切圆角图片
 *param size大小 radius圆角度xy
 *@return 剪切好的新图片
 */
- (UIImage *)createRoundedRectImage:(CGSize)size radius:(CGPoint)radius;
@end
