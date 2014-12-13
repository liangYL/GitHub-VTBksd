//
//  VTWebImageData.h
//  VTNetWork
//
//  Created by wxc on 14-6-11.
//  Copyright (c) 2014年 wxc. All rights reserved.
//
#import <UIKit/UIKit.h>

@protocol VTWebImageData <NSObject>
@property (nonatomic,assign) UIImageView *imageView;
@property (nonatomic,retain) UIImage *placeholderImage;
@property (nonatomic,copy) NSString *url;
@property (nonatomic,copy) void(^imageDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);
@property (nonatomic,copy) void(^imageCompletedBlock)(UIImage *image, NSError *error, int cacheType);
@end
