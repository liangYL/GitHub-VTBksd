//
//  NSData+VTDevKit.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-9.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "VTMessageError.h"

@interface NSData (VTDevKit)
- (void)loadUrl:(NSString *)url  placeholderImage:(UIImage *)placehold success:(void(^)(id,...))success error:(void(^)(id<VTMessageError>))error;     //下载并缓存一个网络文件提供下载完成和失败回调
- (void)loadUrl:(NSString *)url  placeholderImage:(UIImage *)placehold success:(void(^)(id,...))success error:(void(^)(id<VTMessageError>))error   progress:(void(^)(id data,id sum,id current))progress;  //下载并缓存一个网络文件提供下载完成和失败回调,进度回调
@end
