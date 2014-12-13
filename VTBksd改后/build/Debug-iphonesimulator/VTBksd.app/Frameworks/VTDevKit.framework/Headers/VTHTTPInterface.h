//
//  VTHTTPInterface.h
//  VTDevKit
//
//  Created by wxc on 14/10/25.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTHTTPRequestData.h"
#import "VTMessageError.h"

@interface VTHTTPInterface : NSObject
+ (void)getHTTPData:(id<VTHTTPRequestData>)requestData error:(NSObject<VTMessageError> **)error;
+ (void)updateHTTPData:(id<VTHTTPRequestData>)requestData error:(NSObject<VTMessageError> **)error;
+ (void)httpDownload:(id<VTHTTPRequestData>)requestData error:(NSObject<VTMessageError> **)error;
+ (void)downLoadPause:(NSString *)url;
+ (void)downLoadResume:(NSString *)url;
@end
