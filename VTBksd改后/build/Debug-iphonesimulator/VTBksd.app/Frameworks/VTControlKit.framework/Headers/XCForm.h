//
//  XCForm.h
//  testAutoLayout
//
//  Created by wxc on 14-9-10.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//表单

#import <UIKit/UIKit.h>
#import "XCDataBlock.h"

@class XCAutoLayoutViewDef;
@interface XCForm : UIView
@property (nonatomic,assign) XCAutoLayoutViewDef *viewDef;
@property (nonatomic,assign) NSInteger pageNo;
@property (nonatomic,assign) NSInteger pageSize;
@property (nonatomic,assign) BOOL ispage;

- (NSMutableDictionary *)getFormKey;
- (XCDataSimpleRef *)getRefForKey:(NSString *)key;
#pragma mark -
#pragma mark -
- (void)getData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataReload:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)getDataAppend:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)upData:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)login:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
- (void)loginTest:(id)dic result:(void(^)(id,...))result error:(void(^)(id))error;
@end
