//
//  VTUserDef.h
//  VTDevKit
//
//  Created by wxc on 14/10/25.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VTUserDefaults : NSObject
+ (VTUserDefaults *)sharedUserDefaults;

- (void)setObject:(id)obj forKey:(id <NSCopying>)aKey;
- (id)getObjectForkey:(id)key;
- (void)removeObjectForkey:(id)key;
@end
