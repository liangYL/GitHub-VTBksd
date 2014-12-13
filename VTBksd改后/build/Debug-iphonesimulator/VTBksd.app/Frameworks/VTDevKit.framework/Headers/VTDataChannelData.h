//
//  VTDataChannelData.h
//  VTDataChannel
//
//  Created by steve on 14-6-19.
//  Copyright (c) 2014年 lgj. All rights reserved.
//
#import "VTIceRequestData.h"
@protocol VTIceDataOperationProtocol <NSObject>
@property (nonatomic,assign) id<VTIceDataParamsObj> _dataParams;  //装配参数
@end

//取数结构
@protocol VTDataChannelDocData <VTIceDataOperationProtocol>
@property (nonatomic,copy) NSString *systemid;
@property (nonatomic,copy) NSString *configsystemid;
@property (nonatomic,copy) NSString *spaceId;
@property (nonatomic,copy) NSString *modelid;
@property (nonatomic,copy) NSString *aliasid;
@property (nonatomic,retain) NSMutableArray *conditions;
@end
//
@protocol VTDataChannelDocConditionsData <NSObject>
@property (nonatomic,copy) NSString *name;
@property (nonatomic,retain) NSMutableArray *tablecondition;
@property (nonatomic,retain) NSMutableArray *simplecondition;
@property (nonatomic,retain) NSMutableDictionary *paging;
@property (nonatomic,retain) NSMutableDictionary *sort;
@end
//新文档型数据结构数据操作传参
@protocol VTDataChannelDocUpdateData <VTIceDataOperationProtocol>
@property (nonatomic,copy) NSString *systemid;
@property (nonatomic,copy) NSString *configsystemid;
@property (nonatomic,copy) NSString *spaceId;
@property (nonatomic,copy) NSString *modelid;
@property (nonatomic,retain) NSMutableArray *crudlist;
@end
@protocol VTDataChannelDocUpdateCurdListData <NSObject>
@property (nonatomic,assign) int flag;
@property (nonatomic,retain) NSMutableArray *path;
@property (nonatomic,retain) NSMutableDictionary *rowdata;
@end

