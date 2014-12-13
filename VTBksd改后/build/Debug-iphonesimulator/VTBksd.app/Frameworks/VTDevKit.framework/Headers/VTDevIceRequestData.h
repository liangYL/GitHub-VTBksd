//
//  VTDevIceRequestData.h
//  VTDevKit
//
//  Created by wxc on 14-6-17.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTIceRequestData.h"
#import "VTDataChannelData.h"

@interface VTDevIceDataParamsObj : NSObject<VTIceDataParamsObj>
@property (nonatomic,copy) NSString *spaceId,*systemid,*configsystemid,*domain,*client_server,*client_router;
@property (nonatomic,copy) NSString *serverIP,*serverPort,*routerIP,*routerPort;
@property (nonatomic,copy) NSString *messageType;
@property (nonatomic,retain) NSMutableDictionary *guest;
@property (nonatomic,assign) NSInteger reconnectionCount;
@property (nonatomic,assign) NSInteger client_lan,messageSizeMax,resendTimes,ice_encoding_version_major,ice_encoding_version_minor;
@end

@interface VTDevIceRequestData : NSObject<VTIceRequestData>
{
    id _params;
    id _messageContentData;
    void (^success)(id responseObject);
    void (^error)(id error);
}
@property (nonatomic,retain) id<VTIceDataParamsObj> dataParams;
@property (nonatomic,retain) id params;
@property (nonatomic,retain) id messageContentData;
@property (nonatomic,copy) void (^success)(id responseObject);
@property (nonatomic,copy) void (^error)(id error);
@end

@interface VTDevIceMessageContentData : NSObject<VTIceMessageContentData,VTIceDataOperationProtocol>
{
    NSString *_openType;
    NSString *_bzsystemid;
    NSString *_formid;
    NSString *_dataSetID;
    NSString *_reportID;
    NSString *_modelId;
    NSString *_fieldName;
    NSString *_runUser;
    NSString *_shareFlag;
    NSString *_treeStr;
    NSString *_saveType;
    NSString *_doccode;
    NSString *_clientId;
    NSString *_reportcasejson;
    NSString *_controlid;
    NSString *_deltaXml;
    NSMutableDictionary *_dataparam;
    NSMutableDictionary *_whereArr;
    NSMutableDictionary *_masterParam;
    BOOL _masterOnly;
    
}
@property (nonatomic,copy) NSString *openType,*bzsystemid,*formid,*dataSetID,*reportID,*modelId,*fieldName,*runUser,*shareFlag,*treeStr,*saveType,*doccode,*clientId,*reportcasejson,*controlid,*deltaXml;
@property (nonatomic,retain) NSMutableDictionary *dataparam,*whereArr,*masterParam;
@property (nonatomic,assign) BOOL masterOnly;
@property (nonatomic,assign) id<VTIceDataParamsObj> _dataParams;  //装配参数
@end