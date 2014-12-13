//
//  VTDBData.h
//  VTDB
//
//  Created by wxc on 14-6-9.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

@protocol VTDBData <NSObject>
@property (nonatomic,copy) NSString *dbFileUrl;   //库目录
@property (nonatomic,copy) NSString *table;       //表
@property (nonatomic,copy) NSString *sql;         //执行sql
@property (nonatomic,retain) id data;             //参数
@end