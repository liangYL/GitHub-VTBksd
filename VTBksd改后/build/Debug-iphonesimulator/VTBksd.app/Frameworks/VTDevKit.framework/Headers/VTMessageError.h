//
//  VTMessageError.h
//  VTMessage
//
//  Created by wxc on 14-6-3.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
//消息错误声明

@protocol VTMessageError <NSObject>

@required

@property (nonatomic,assign) int code;  //错误码
@property (nonatomic,copy) NSString *msg;  //错误描述
@property (nonatomic,assign) int fromServiceCode;  //错误来自哪个服务


+ (id<VTMessageError>)initWithError:(int)code msg:(NSString *)msg;
@end
