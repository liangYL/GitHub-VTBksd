//
//  VTDevMessage.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-9.
//  Copyright (c) 2014年 BENYU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTMessage.h"

@interface VTDevMessage : NSObject<VTMessage>
{
    NSString *_messageID;
    NSString *_channelID;
    int _timeOut;
    NSString *_messageType;
    VTMessageRole _toRole;
    id _fromObj;
    id _messageData;
    id _messageControl;
}
@property (nonatomic,copy) NSString *messageID;        //消息ID
@property (nonatomic,copy) NSString *channelID;        //所属通道
@property (nonatomic,assign) int timeOut;              //超时时间
@property (nonatomic,copy) NSString *messageType;      //业务类型
@property (nonatomic,assign) VTMessageRole toRole;     //强制路由策略
@property (nonatomic,assign) id fromObj;       //来自哪个插件入口对象指针
@property (nonatomic,retain) id messageData;   //消息内容
@property (nonatomic,retain) id messageControl;  //消息控制
@end
