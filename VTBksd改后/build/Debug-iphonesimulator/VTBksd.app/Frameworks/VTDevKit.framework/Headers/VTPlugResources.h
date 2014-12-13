//
//  VTPlugResources.h
//  VTPlug
//
//  Created by wxc on 14-6-20.
//  Copyright (c) 2014年 GK. All rights reserved.
//

@protocol VTPlugResources <NSObject>
@property(nonatomic,copy)NSString *appName;                //插件名字
@property(nonatomic,retain)NSArray *messageTypes;          //插件服务列表
@property(nonatomic,copy)NSString *appID;                  //插件ID
@property(nonatomic,copy)NSString *appVersion;             //插件版本
@property(nonatomic,copy)NSString *channelID;              //所属通道ID
@property(nonatomic,copy)NSString *systemCompatibility;    //系统兼容版本
@property(nonatomic,copy)NSString *frameCompatibility;     //框架兼容版本
@property(nonatomic,copy) NSString *downLoadUrl; //下载地址
@end
