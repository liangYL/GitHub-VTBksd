//
//  VTDevHTTPRequestData.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-13.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTHTTPRequestData.h"

@interface VTDevHTTPRequestData : NSObject<VTHTTPRequestData>
{
    NSString *_url;
    NSString *_path;
    NSString *_method;
    id  _params;
    id  _header;
    id  _formData;
    int _parameterEncoding;
    
    void (^success)(id responseObject);
    void (^error)(id error);
    void (^progress)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite);
}

@property (nonatomic,copy) NSString *url;
@property (nonatomic,copy) NSString *path;
@property (nonatomic,copy) NSString *method;
@property (nonatomic,retain) id params;
@property (nonatomic,retain) id header;
@property (nonatomic,retain) id formData;
@property (nonatomic,assign) int parameterEncoding;

@property (nonatomic,copy) void (^success)(id responseObject);
@property (nonatomic,copy) void (^error)(id error);
@property (nonatomic,copy) void (^progress)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite);
@end
