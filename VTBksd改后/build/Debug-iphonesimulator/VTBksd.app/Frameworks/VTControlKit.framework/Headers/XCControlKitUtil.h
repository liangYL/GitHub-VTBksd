//
//  XCControlKitUtil.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataBlock.h"
#import "XCDataSimpleRef.h"
#import "XCAutoLayoutProtocol.h"
#import "XCAutoLayoutCSSPars.h"

#define DEFINE_SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;

#define DEFINE_SINGLETON_FOR_CLASS(className) \
\
+ (className *)shared##className { \
static className *shared##className = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
shared##className = [[self alloc] init]; \
}); \
return shared##className; \
}

@interface XCControlKitUtil : NSObject

+ (BOOL)isIOS7;
+ (BOOL)isIOS5;

+ (NSString *)getRuntimeValue:(NSString *)value;
+ (NSString *)getResourcePath:(NSString *)fileName;

+ (NSString *)parsePath:(NSString *)path;
+ (void)setObjProperty:(id)obj key:(NSString *)key value:(id)value;

+ (XCDataBlock *)getBlock:(id)tag;
+ (XCAutoLayout *)getLayout:(id)tag;
+ (XCDataSimpleRef *)getSimpleRef:(id)tag;

+ (id<VTFrameWarehouseProtocol>)getFrameWarehouse:(id)tag;

+ (BOOL)registersFont:(NSString *)path;


+ (void)additionalDataSimpleRef:(id)object target:(id)target;
+ (void)additionalAutoLayout:(id)object target:(id)target;
+ (void)additionalFrameWarehouse:(id)object target:(id)target;
+ (void)additionalDataBlock:(id)object target:(id)target;
@end
