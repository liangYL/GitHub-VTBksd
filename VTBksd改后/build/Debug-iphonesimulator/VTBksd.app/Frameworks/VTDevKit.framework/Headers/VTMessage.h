//
//  VTMessage.h
//  VTMessage
//
//  Created by wxc on 14-6-3.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//消息包格式声明

typedef enum{
    vtIsNul,    //无
    vtServer,   //服务器
    vtPlug,     //插件
    vtBuiltIn     //内置服务
}VTMessageRole;


@protocol VTMessage <NSObject>

@required
@property (nonatomic,copy) NSString *messageID;        //消息ID
@property (nonatomic,copy) NSString *channelID;        //所属通道
@property (nonatomic,assign) int timeOut;              //超时时间
@property (nonatomic,copy) NSString *messageType;      //业务类型
@property (nonatomic,assign) VTMessageRole toRole;     //强制路由策略
@property (nonatomic,assign) id fromObj;       //来自哪个插件入口对象指针
@property (nonatomic,retain) id messageData;   //消息内容
@property (nonatomic,retain) id messageControl;  //消息控制
@end