//
//  XCSuperModuleView.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//view类族 基类
#import <UIKit/UIKit.h>
#import "XCAutoLayoutController.h"
#import "XCAutoLayoutProtocol.h"
#import "XCLoadMsgPartsProtocol.h"
#import "XCDataOperationPartsProtocol.h"
#import "XCDataParsePartsProtocol.h"
#import "XCHudProtocol.h"

@interface XCSuperModuleView : UIView<XCModuleProtocol>
{
    XCAutoLayoutController *_autoLayout;
}
@property (nonatomic,retain) NSMutableDictionary *formParams;

@property (nonatomic,readonly) XCAutoLayoutController *autoLayout;
@property (nonatomic,assign) id<VTFrameWarehouseProtocol> __frameWarehouse;
@property (nonatomic,copy) NSString *businessID;
@property (nonatomic,copy) NSString *layoutPath;
@property (nonatomic,retain) NSDictionary *settings;
@property (nonatomic,readonly) id<XCLoadMsgPartsProtocol> loadMsg;
@property (nonatomic,readonly) id<XCHudProtocol> hud;


- (void)startLoad;

#pragma mark -
#pragma mark 数据操作
- (void)getData:(VTDevDataChannelDocData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
- (void)upData:(VTDevDataChannelDocUpdateData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
- (void)login:(id)dic xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
- (void)loginTest:(id)dic xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
@end
