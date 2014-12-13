//
//  VTDevDataChannelIceData.h
//  VTDevKit
//
//  Created by wxc on 14-6-21.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTDataChannelIceData.h"

@interface VTDevDataChannelIceData : NSObject<VTDataChannelIceData>
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
@end
