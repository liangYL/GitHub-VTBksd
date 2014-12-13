//
//  VTPlugData.h
//  VTPlug
//
//  Created by GK on 14-6-14.
//  Copyright (c) 2014年 GK. All rights reserved.
//

@protocol VTPlugData <NSObject>

@property (nonatomic,copy) NSString *appID;  //插件ID
@property (nonatomic,copy) NSString *channelID;  //通道
@property (nonatomic,retain) id     parms;  //传参
@property (nonatomic,copy) NSString *gID;   //实例ID

@end
