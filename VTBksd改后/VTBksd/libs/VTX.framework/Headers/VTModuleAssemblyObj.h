//
//  XCModuleAssemblyObj.h
//  testAutoLayout
//
//  Created by wxc on 14-9-5.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VTModuleAssemblyObj : NSObject
@property (nonatomic,copy) NSString *layoutPath;   //布局文件
@property (nonatomic,copy) NSString *moduleNO;      //组件编号
@property (nonatomic,copy) NSString *nikName;       //别名
@property (nonatomic,copy) NSString *moduleClass;   //组件对象
@property (nonatomic,copy) NSString *area;          //所属区域
@property (nonatomic,copy) NSString *hud;    //hud配件
@property (nonatomic,copy) NSString *loadMsg;  //load配件
@property (nonatomic,retain) NSMutableDictionary *settings;      //settings
@end
