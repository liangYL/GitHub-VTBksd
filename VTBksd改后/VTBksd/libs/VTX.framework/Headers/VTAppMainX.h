//
//  VTAppMainX.h
//  VTPlugTest1
//
//  Created by GK on 14-6-16.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTAppMain.h"

@interface VTAppMainX : NSObject<VTAppMain>
{
    NSString *_appID;
    NSString *_channelID;
    NSString *_resourcePath;
    NSString *_languagePath;
    NSString *_documentPath;
    id        _rootWindow;
}

@property (nonatomic,copy) NSString *appID; //插件ID
@property (nonatomic,copy) NSString *channelID;  //所属通道
@property (nonatomic,copy) NSString *resourcePath;  //资源地址
@property (nonatomic,copy) NSString *languagePath;  //语言文件地址
@property (nonatomic,copy) NSString *documentPath;  //插件所在地址
@property (nonatomic,retain) id     rootWindow;          //根窗口


+ (id)shardAppMain;

- (id)wakeUp:(id)data;                 //启动

//子类重写
- (id)initRootWindow:(id)data;                 //初始化
- (void)logout:(id)data;              //注销
- (void)unload:(id)data;              //卸载
/**
 *接收到消息
 */
- (id)receiveMessage:(id<VTMessage>)message success:(void(^)(id,...))success error:(void(^)(id))error progress:(void(^)(id data,id sum,id current))progress;


@end
