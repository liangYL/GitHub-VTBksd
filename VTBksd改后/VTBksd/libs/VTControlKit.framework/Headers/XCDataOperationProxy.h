//
//  XCDataOperationProxy.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataOperationPartsProtocol.h"

@interface XCDataOperationProxy : NSObject<XCDataOperationPartsProtocol>
@property (nonatomic,retain) id data;


- (void)login:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)loginTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)getData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataReload:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataAppend:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)upData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)getDataTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)upDataTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)dataOperation:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
//已str开头
- (NSString *)startString:(NSString *)str;
//已str结尾
- (NSString *)endString:(NSString *)str;
//包含str
- (NSString *)containsString:(NSString *)str;

//分页装配
- (id)pageSetting:(XCForm *)form params:(id)params isNextPage:(BOOL)isNextPage;
@end
