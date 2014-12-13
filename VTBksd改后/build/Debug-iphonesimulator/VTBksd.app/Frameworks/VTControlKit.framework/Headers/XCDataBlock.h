//
//  XCDataBlcok.h
//  testAutoLayout
//
//  Created by wxc on 14-9-3.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataBlockProxyPro.h"
#import "XCAutoLayoutCSSPars.h"

typedef enum{
    isTable,
    isRow
}XCDataBlcokType;

#define xBlockDefCurdBusiness   @"___defCurd"

@interface XCDataBlock : NSObject
@property (nonatomic,retain) id path;
@property (nonatomic,copy) NSString *blockName;
@property (nonatomic,assign) XCDataBlcokType dataSetType;
@property (nonatomic,copy) NSString *tableName;
@property (nonatomic,retain) NSMutableArray *nodes;
@property (nonatomic,assign) XCDataBlock *superBlock;
@property (nonatomic,retain) id data;
@property (nonatomic,retain) NSMutableArray *views;
@property (nonatomic,assign) id<XCDataBlockProxyPro> aClass;
@property (nonatomic,retain) id rowPath;
@property (nonatomic,assign) XCAutoLayoutViewDef *dataView;

- (void)getData;
- (void)setCurrentRow:(id)rowPath;

- (VTDevDataChannelDocUpdateCurdListData *)addCurd:(NSMutableDictionary *)dic flag:(int)flag indexPath:(NSIndexPath *)indexPath;
- (VTDevDataChannelDocUpdateCurdListData *)addCurd:(NSMutableDictionary *)dic flag:(int)flag indexPath:(NSIndexPath *)indexPath curdBusiness:(NSString *)curdBusiness;

- (NSMutableArray *)getCurd;
- (NSMutableArray *)getCurd:(NSString *)curdBusiness;

- (void)removeCurdAll;
- (void)removeDefCurd;
- (void)removeCurdByBusiness:(NSString *)curdBusiness;
- (void)removeDefCurdIndexPath:(NSIndexPath *)indexPath;
- (void)removeCurdByBusiness:(NSString *)curdBusiness indexPath:(NSIndexPath *)indexPath;
@end
