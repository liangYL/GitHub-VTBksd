//
//  VTPlugResourcesMenu.h
//  VTPlug
//
//  Created by wxc on 14-6-20.
//  Copyright (c) 2014年 GK. All rights reserved.
//

@protocol VTPlugResourcesMenu <NSObject>
@property(nonatomic,copy)NSString *appName; //插件名字
@property(nonatomic,copy)NSString *appID;    //插件ID
@property(nonatomic,copy)NSString *iconUrl;  //图标地址
@property(nonatomic,copy)NSString *channelID;
@property(nonatomic,copy)NSString *downLoadUrl;
@end
