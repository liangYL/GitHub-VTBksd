//
//  VTIceUserManage.h
//  VTNetWork
//
//  Created by wxc on 14-10-9.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol VTIceUser <NSObject>
@property (nonatomic,copy) NSString *linkInfo,*routerAddress;
@property (nonatomic,copy) NSString *clientId;
// 用户code
@property (nonatomic,copy) NSString *usercode;
// 用户code
@property (nonatomic,copy) NSString *userCode;
// 用户名
@property (nonatomic,copy)NSString *userName;
// 标识客户端是否连接到连接器
@property (nonatomic,assign)BOOL connected;
// 返回消息code(枚举:0表示失败,1表示成功)
@property (nonatomic,copy)NSString *msg;
// 返回的消息
@property (nonatomic,copy)NSString *code;
// 服务器唯一标识
@property (nonatomic,copy)NSString *userID;
// 客户端端点
@property (nonatomic,copy)NSString *endPoint;

@property (nonatomic,copy)NSString *value;

@property (nonatomic,copy)NSString *groupid;

@property (nonatomic,copy)NSString *state;

@property (nonatomic,copy)NSString *loginType;

@property (nonatomic,copy)NSString *thirdAccount;

@property (nonatomic,copy)NSString *email;

@property (nonatomic,copy)NSString *mobilephone;
// 是否为系统普通用户
@property (nonatomic,assign)BOOL systemUser;
// 是否为系统操作用户
@property (nonatomic,assign)BOOL manageUser;
@end


@protocol VTIceUserManage <NSObject>
- (id<VTIceUser>)getUserByDomain:(NSString *)domain;
@end


extern id<VTIceUserManage> __userManage;


