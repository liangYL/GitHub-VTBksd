//
//  VTIceRequestData.h
//  VTNetWork
//
//  Created by wxc on 14-6-17.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
//参数装配
@protocol VTIceDataParamsObj <NSObject>
@property (nonatomic,copy) NSString *spaceId,*systemid,*configsystemid,*domain,*client_server,*client_router;
@property (nonatomic,copy) NSString *serverIP,*serverPort,*routerIP,*routerPort;
@property (nonatomic,copy) NSString *messageType;
@property (nonatomic,retain) NSMutableDictionary *guest;
@property (nonatomic,assign) NSInteger reconnectionCount;
@property (nonatomic,assign) NSInteger client_lan,messageSizeMax,resendTimes,ice_encoding_version_major,ice_encoding_version_minor;
@end

@protocol VTIceRequestData <NSObject>
@property (nonatomic,retain) id<VTIceDataParamsObj> dataParams;
@property (nonatomic,retain) id params;
@property (nonatomic,retain) id messageContentData;
@property (nonatomic,copy) void (^success)(id responseObject);
@property (nonatomic,copy) void (^error)(id error);
@end

@protocol VTIceMessageContentData <NSObject>
@property (nonatomic,copy) NSString *openType,*bzsystemid,*formid,*dataSetID,*reportID,*modelId,*fieldName,*runUser,*shareFlag,*treeStr,*saveType,*doccode,*clientId,*reportcasejson,*controlid,*deltaXml;
@property (nonatomic,retain) NSMutableDictionary *dataparam,*whereArr,*masterParam;
@property (nonatomic,assign) BOOL masterOnly;
@end





