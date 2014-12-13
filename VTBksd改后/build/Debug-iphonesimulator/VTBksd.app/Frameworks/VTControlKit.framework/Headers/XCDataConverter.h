//
//  XCDataConverter.h
//  testAutoLayout
//
//  Created by wxc on 14-8-21.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//
//数据转换器
#import <Foundation/Foundation.h>

@interface XCDataConverter : NSObject

//数据转换
+ (id)dataConverter:(id)data rules:(id)rules;
@end


