//
//  VTDevSendMessage.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-9.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTMessage.h"
#import "VTMessageError.h"

@interface VTDevSendMessage : NSObject

+ (id)sendMessage:(id<VTMessage>)message  success:(void(^)(id,...))success error:(void(^)(id<VTMessageError>))error;
+ (id)sendMessage:(id<VTMessage>)message  success:(void(^)(id,...))success error:(void(^)(id<VTMessageError>))error progress:(void(^)(id data,id sum,id current))progress;
+ (id)sendMessage:(id<VTMessage>)message  error:(NSObject<VTMessageError> **)error;

@end
