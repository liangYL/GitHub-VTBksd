//
//  VTFrameWarehouseProtocol.h
//  VTControlKit
//
//  Created by wxc on 14-9-22.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol VTFrameWarehouseProtocol <NSObject>
- (void)addFrame:(Class)aClass nikName:(NSString *)nikName;
- (Class)getFrame:(NSString *)nikName;
@end
