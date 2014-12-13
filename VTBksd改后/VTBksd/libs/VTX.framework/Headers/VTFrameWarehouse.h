//
//  XCFrameWarehouse.h
//  testAutoLayout
//
//  Created by wxc on 14-8-11.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//模板仓库

#import <Foundation/Foundation.h>
#import "VTFrameWarehouseProtocol.h"

@interface VTFrameWarehouse : NSObject<VTFrameWarehouseProtocol>
{
    NSMutableDictionary *_warehouse;
}
+ (VTFrameWarehouse *)sharedWarehouse;

- (void)addFrame:(Class)aClass nikName:(NSString *)nikName;
- (Class)getFrame:(NSString *)nikName;
@end
