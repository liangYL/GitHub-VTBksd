//
//  VTDataChannelIceData.h
//  VTDataChannel
//
//  Created by steve on 14-6-19.
//  Copyright (c) 2014年 lgj. All rights reserved.
//

@protocol VTDataChannelIceData <NSObject>

@property (nonatomic,copy) NSString *openType,*bzsystemid,*formid,*dataSetID,*reportID,*modelId,*fieldName,*runUser,*shareFlag,*treeStr,*saveType,*doccode,*clientId,*reportcasejson,*controlid,*deltaXml;
@property (nonatomic,retain) NSMutableDictionary *dataparam,*whereArr,*masterParam;
@property (nonatomic,assign) BOOL masterOnly;

@end

