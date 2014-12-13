//
//  VTMessageRoute.h
//  VTMessage
//
//  Created by wxc on 14-6-3.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//消息路由声明
@protocol VTMessage;
@protocol VTMessageError;

@protocol VTMessageRoute <NSObject>

@required

/**
 *回执一个异步执行完成的消息
 */
+ (BOOL)receiptMessage:(NSString *)messageID data:(id)data responseType:(int)responseType;


@end

