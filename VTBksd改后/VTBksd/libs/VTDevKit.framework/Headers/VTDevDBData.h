//
//  VTDevDBData.h
//  VTDevKit
//
//  Created by wxc on 14-6-13.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTDBData.h"
@interface VTDevDBData : NSObject<VTDBData>
{
    NSString *_dbFileUrl;
    NSString *_table;
    NSString *_sql;
    id       _data;
}
@property (nonatomic,copy) NSString *dbFileUrl;   //库目录
@property (nonatomic,copy) NSString *table;       //表
@property (nonatomic,copy) NSString *sql;         //执行sql
@property (nonatomic,retain) id data;             //参数
@end
