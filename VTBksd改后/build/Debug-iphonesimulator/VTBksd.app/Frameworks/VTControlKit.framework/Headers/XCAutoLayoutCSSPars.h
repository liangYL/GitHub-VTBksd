//
//  XCAutoLayoutCSSPars.h
//  testAutoLayout
//
//  Created by wxc on 14-8-19.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCXMLParse.h"
#import "XCAutoLayoutCSSTransform.h"
#import "XCDataBlockProxyPro.h"
#import "XCDataOperationPartsProtocol.h"
#import "XCDataParsePartsProtocol.h"
#import "XCDataSimpleRef.h"

@class XCAutoLayoutRoot;
@class XCAutoLayoutModuleDef;

@interface XCAutoLayoutCSSPars : NSObject
@property (nonatomic,assign) id<VTFrameWarehouseProtocol> frameWarehouse;

- (id)initWithWarehouse:(id<VTFrameWarehouseProtocol>)warehouse;

- (XCAutoLayoutRoot *)transformDIVCSS:(XCXMLElement *)rootElement settings:(NSDictionary *)settings;
@end

//布局根节点
@interface  XCAutoLayoutDIV : NSObject
@property (nonatomic,assign) XCMargin  margin;
@property (nonatomic,assign) CGSize    size;
@property (nonatomic,copy) NSString *display;     //block inline inline-n
@property (nonatomic,copy) NSString *center;     //center center-x center-y
@property (nonatomic,copy) NSString *cid;
@property (nonatomic,copy) NSString *cname;       //控件模板对象名
@property (nonatomic,copy) NSString *xibname;     //是否加载布局文件
@property (nonatomic,copy) NSString *datafill;      //数据填充器
@property (nonatomic,retain) NSMutableDictionary *runTimeParms;  //动态赋值属性
@property (nonatomic,retain) NSMutableArray *nodes;
@property (nonatomic,retain) NSMutableDictionary   *style;    //布局模板样式
@property (nonatomic,copy) NSString       *classs;  //引用样式表
@property (nonatomic,copy)NSString *multiplier; //左右乘数比例
@property (nonatomic,assign) XCAutoLayoutDIV *parentDIV;
@end

@interface  XCAutoLayoutRoot : NSObject
@property (nonatomic,retain) NSMutableDictionary   *params;    //传参
@property (nonatomic,retain) NSDictionary   *style;    //布局模板样式
@property (nonatomic,retain) NSMutableArray *bodyDIVS;  //根布局集合
@property (nonatomic,retain) NSMutableDictionary *linkDIVS;  //link布局集合 11-04新增
@property (nonatomic,retain) NSMutableDictionary *map;      //数据填充配置
@property (nonatomic,retain) XCAutoLayoutModuleDef *moduleDef; //组件装配
@property (nonatomic,retain) NSMutableDictionary *blocks;
@property (nonatomic,assign) id<VTFrameWarehouseProtocol> frameWarehouse;
@end


@interface XCAutoLayout : NSObject
@property (nonatomic,assign) id view;
@property (nonatomic,assign) XCAutoLayoutDIV *css;
@property (nonatomic,assign) XCAutoLayout *superLayout;
@property (nonatomic,retain) NSMutableArray *nodes;
@property (nonatomic,assign) XCAutoLayout *form;
@end

//组件装配
@interface XCAutoLayoutModuleDef : NSObject
@property (nonatomic,copy) NSString *componentName;
@property (nonatomic,copy) NSString *compoType;
@property (nonatomic,copy) NSString *component_No;
@property (nonatomic,retain) NSMutableDictionary *views;        //数据块
@property (nonatomic,retain) NSMutableDictionary *sref;        //数据引用块
@end

@class XCAutoLayoutViewRef;
@interface XCAutoLayoutViewDef : NSObject
@property (nonatomic,copy) NSString *viewname;
@property (nonatomic,copy) NSString *modelid;
@property (nonatomic,copy) NSString *datafilename;
@property (nonatomic,retain) id<XCDataBlockProxyPro> aClass;
@property (nonatomic,assign) XCDataBlock *rootBlock;
@property (nonatomic,retain) NSMutableDictionary *blocks;
@property (nonatomic,assign) id form;
@property (nonatomic,retain) id<XCDataOperationPartsProtocol> dataOperation;
@property (nonatomic,retain) id<XCDataParsePartsProtocol> dataParse;
@property (nonatomic,assign) XCAutoLayoutViewRef *viewRef;
@end
//数据引用
@interface XCAutoLayoutViewRef : NSObject
@property (nonatomic,copy) NSString *refname;
@property (nonatomic,assign) XCAutoLayoutViewDef *viewDef;
@property (nonatomic,retain) NSMutableDictionary *ref;
@property (nonatomic,retain) NSMutableDictionary *rootRef;
@end
