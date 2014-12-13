//
//  VTDevDataChannelData.h
//  VTDevKit
//
//  Created by wxc on 14-6-21.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTDataChannelData.h"

//取数结构
@interface VTDevDataChannelDocData : NSObject<VTDataChannelDocData>
@property (nonatomic,copy) NSString *systemid;
@property (nonatomic,copy) NSString *configsystemid;
@property (nonatomic,copy) NSString *spaceId;
@property (nonatomic,copy) NSString *modelid;
@property (nonatomic,copy) NSString *aliasid;
@property (nonatomic,retain) NSMutableArray *conditions;
@property (nonatomic,assign) id<VTIceDataParamsObj> _dataParams;  //装配参数
@end

@interface VTDevDataChannelDocConditionsData : NSObject<VTDataChannelDocConditionsData>
@property (nonatomic,copy) NSString *name;
@property (nonatomic,retain) NSMutableArray *tablecondition;
@property (nonatomic,retain) NSMutableArray *simplecondition;
@property (nonatomic,retain) NSMutableDictionary *paging;
@property (nonatomic,retain) NSMutableDictionary *sort;
@end

//新文档型数据结构数据操作传参
@interface VTDevDataChannelDocUpdateData : NSObject<VTDataChannelDocUpdateData>
@property (nonatomic,copy) NSString *systemid;
@property (nonatomic,copy) NSString *configsystemid;
@property (nonatomic,copy) NSString *spaceId;
@property (nonatomic,copy) NSString *modelid;
@property (nonatomic,retain) NSMutableArray *crudlist;
@property (nonatomic,assign) id<VTIceDataParamsObj> _dataParams;  //装配参数
@end

@interface VTDevDataChannelDocUpdateCurdListData : NSObject<VTDataChannelDocUpdateCurdListData>
@property (nonatomic,assign) int flag;
@property (nonatomic,retain) NSMutableArray *path;
@property (nonatomic,retain) NSMutableDictionary *rowdata;
@end


