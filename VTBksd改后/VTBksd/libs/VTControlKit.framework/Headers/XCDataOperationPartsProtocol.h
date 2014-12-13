//
//  XCDataOperationPartsProtocol.h
//  XCAddressBook
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//


//数据操作配件

#import <UIKit/UIKit.h>

@class XCForm;
@protocol XCDataOperationPartsProtocol <NSObject>
@property (nonatomic,retain) id data;

@required
- (void)login:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)loginTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)getData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataReload:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataAppend:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)upData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)getDataTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)upDataTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;

- (void)dataOperation:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
@optional

//已str开头
- (NSString *)startString:(NSString *)str;
//已str结尾
- (NSString *)endString:(NSString *)str;
//包含str
- (NSString *)containsString:(NSString *)str;

- (id)pageSetting:(XCForm *)form params:(id)params isNextPage:(BOOL)isNextPage;
@end