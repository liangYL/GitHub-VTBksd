//
//  VTLog.h
//  VTLog
//
//  Created by wxc on 14-6-26.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
#import <Foundation/Foundation.h>

@protocol VTLogProtocol <NSObject>

+ (void)logInfo:(NSString *)formt,...;
+ (void)logVerbose:(NSString *)formt,...;
+ (void)logWarn:(NSString *)formt,...;
+ (void)logError:(NSString *)formt,...;

+ (void)setDefaultHandler;
@end


extern id<VTLogProtocol> VTLog;


#define VTLogInfo( s, ... ) [VTLog logInfo:@"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define VTLogVerbose( s, ... ) [VTLog logVerbose:@"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define VTLogWarn( s, ... ) [VTLog logWarn:@"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__]]

#define VTLogError( s, ... ) [VTLog logError:@"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__]]
