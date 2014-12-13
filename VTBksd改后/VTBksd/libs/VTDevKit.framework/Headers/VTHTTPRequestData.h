//
//  VTHTTPRequestData.h
//  VTNetWork
//
//  Created by wxc on 14-6-11.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

@protocol VTHTTPRequestData <NSObject>
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
