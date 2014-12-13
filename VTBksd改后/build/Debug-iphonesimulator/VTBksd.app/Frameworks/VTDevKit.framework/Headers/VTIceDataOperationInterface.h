//
//  VTIceDataOperationInterface.h
//  VTDevKit
//
//  Created by wxc on 14/10/28.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface VTIceDataOperationInterface : NSObject
//登录
+ (void)login:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
//新登录
+ (void)loginNew:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
//获取数据
+ (void)dataOperation:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
@end
