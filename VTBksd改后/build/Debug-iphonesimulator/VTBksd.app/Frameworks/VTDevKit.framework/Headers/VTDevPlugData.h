//
//  VTDevPlugData.h
//  VTDevKit
//
//  Created by wxc on 14-6-20.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTPlugData.h"

@interface VTDevPlugData : NSObject<VTPlugData>
{
    NSString *_appID;
    NSString *_channelID;
    NSString *_gID;
    id       _parms;
}

@property (nonatomic,copy) NSString *appID;  //插件ID
@property (nonatomic,copy) NSString *channelID;  //通道
@property (nonatomic,retain) id     parms;  //传参
@property (nonatomic,copy) NSString *gID;   //实例ID
@end
