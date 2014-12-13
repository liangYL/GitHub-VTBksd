//
//  XCLRKeyValueAutoLayoutView.h
//  XCLRKeyValueAutoLayoutView
//
//  Created by wxc on 14-8-6.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutCSSPars.h"
#import "XCAutoLayoutCSSTransform.h"
@protocol XCAutoLayoutControllerDelegate;

@interface XCAutoLayoutController : NSObject<NSXMLParserDelegate>
@property (nonatomic,assign) id<VTFrameWarehouseProtocol> frameWarehouse;
@property (nonatomic,assign) id<XCAutoLayoutControllerDelegate> delegate;
@property (nonatomic,copy) NSString *layoutFilePath;  //重设布局文件会导致页面重新加载绘制
@property (nonatomic,copy) NSString *layoutString;      //重设布局字符串同样会导致页面重新加载绘制
@property (nonatomic,readonly) NSMutableArray  *blocks;     //数据规则
@property (nonatomic,retain) XCAutoLayoutRoot *root;      //根节点
@property (nonatomic,readonly) NSMutableArray  *views;
@property (nonatomic,retain) NSMutableDictionary *forms;     //表单

+ (XCAutoLayoutRoot *)getLayoutFilePathDataXML:(NSString *)path settings:(NSDictionary *)settings frameWarehouse:(id<VTFrameWarehouseProtocol>)frameWarehouse;

- (id)initWithView:(UIView *)view layoutFilePath:(NSString *)layoutFilePath settings:(NSDictionary *)settings frameWarehouse:(id<VTFrameWarehouseProtocol>)frameWarehouse;
- (id)initWithView:(UIView *)view layoutRoot:(XCAutoLayoutRoot *)layoutRoot settings:(NSDictionary *)settings;
- (id)initWithView:(UIView *)view layoutString:(NSString *)layoutString settings:(NSDictionary *)settings frameWarehouse:(id<VTFrameWarehouseProtocol>)frameWarehouse;

- (void)loadFormView:(NSString *)cid;
- (void)loadFormViewAll;

- (XCAutoLayout *)getElementById:(NSString *)ID;    //根据ID获取
- (XCAutoLayout *)getFormById:(NSString *)ID;    //根据ID获取表单

- (void)settingOutlet:(id)tagger;                     //设置控件对象引用

- (void)setObjProperty:(id)obj key:(NSString *)key value:(id)value;     //设置obj的属性

//布局变动
- (void)reload;
- (void)reloadA;    //即将废弃
- (void)autoSizeReload;
@end

@protocol XCAutoLayoutControllerDelegate <NSObject>
- (void)addNodeView:(UIView *)contentView nodeView:(UIView *)nodeView index:(NSInteger)index css:(XCAutoLayoutDIV *)css;
@end



