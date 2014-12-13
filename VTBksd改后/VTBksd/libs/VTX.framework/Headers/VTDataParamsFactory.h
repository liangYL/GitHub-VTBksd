//
//  VTDataParamsFactory.h
//  VTX
//
//  Created by wxc on 14-9-25.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VTDevKit/VTDevDataChannelData.h>
#import <VTDevKit/VTDevIceRequestData.h>

@interface VTDataParamsFactory : NSObject

+ (VTDataParamsFactory *)initParamsFactory:(NSString *)filePath;
+ (VTDataParamsFactory *)shardParamsFactory;

//装配登录参数
- (NSMutableDictionary *)getLoginParams;
- (NSMutableDictionary *)getLoginParams:(NSString *)key;
- (NSMutableDictionary *)getGuestLoginParams;
- (NSMutableDictionary *)getGuestLoginParams:(NSString *)key;
//装配取数参数
- (VTDevDataChannelDocData *)getDataParams;
- (VTDevDataChannelDocData *)getDataParams:(NSString *)key;
- (VTDevDataChannelDocConditionsData *)getDataConditions:(VTDevDataChannelDocData *)dataParams;

//装配数据变更
- (VTDevDataChannelDocUpdateData *)getUpdataParams:(NSMutableArray *)curdList;
- (VTDevDataChannelDocUpdateData *)getUpdataParams:(NSMutableArray *)curdList key:(NSString *)key;

- (VTDevIceDataParamsObj *)getDefParams;
- (VTDevIceDataParamsObj *)getParamsByDomain:(NSString *)domain;

- (BOOL)isGuest:(NSString *)userCode;
- (BOOL)isGuest:(NSString *)userCode domain:(NSString *)domain;
@end
