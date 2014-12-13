//
//  XCDataPathFactory.h
//  testAutoLayout
//
//  Created by wxc on 14-8-27.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataBlockProxyPro.h"
#import "XCAutoLayoutCSSPars.h"
#import "XCForm.h"

@class XCDataBlock;
@class XCAutoLayoutViewDef;

@interface XCDataBlockProxy : NSObject<XCDataBlockProxyPro>

//设置数据path
- (void)settingDataBlcok:(XCDataBlock *)dataBlcok view:(id)view;
/**
 *根据path获取数据源
 *
 */
- (id)getData:(id)data path:(id)path;
- (void)selectedDefDataOneRow:(XCDataBlock *)block;
- (void)refreshPath:(XCDataBlock *)block;
- (NSMutableDictionary *)createBlocks:(NSArray *)array dataView:(XCAutoLayoutViewDef *)dataView setting:(NSDictionary *)setting;

//生成数据引用s
- (id)getRefData:(id)data path:(id)path;
- (void)selectedDefRefDataOneRow:(XCDataSimpleRef *)ref;
- (void)refreshRefPath:(XCDataSimpleRef *)ref;
- (NSMutableDictionary *)createRefs:(NSArray *)array viewRef:(XCAutoLayoutViewRef *)viewRef setting:(NSDictionary *)setting;



/**
 *数据源注入 原数据 需要注入的view集合
 */
- (BOOL)dataImmit:(id)data views:(NSArray *)views map:(NSDictionary *)map filter:(id(^)(XCAutoLayout *layout,NSString *key,NSString *value))filter imageFilter:(void(^)(XCAutoLayout *layout,NSString *key,NSString *value,id imageView))imageFilter;
- (BOOL)dataImmit:(id)data form:(XCForm *)form views:(NSArray *)views map:(NSDictionary *)map filter:(id(^)(XCAutoLayout *layout,NSString *key,NSString *value))filter imageFilter:(void(^)(XCAutoLayout *layout,NSString *key,NSString *value,id imageView))imageFilter;

@end
