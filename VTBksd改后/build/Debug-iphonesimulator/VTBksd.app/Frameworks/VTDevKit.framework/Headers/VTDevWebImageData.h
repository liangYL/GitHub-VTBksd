//
//  VTDevWebImageData.h
//  VTDevKit
//
//  Created by TIGERTOTO on 14-6-13.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTWebImageData.h"
@interface VTDevWebImageData : NSObject<VTWebImageData>
{
    UIImageView *_imageView;
    UIImage *_placeholderImage;
    NSString *_url;
    void(^imageDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);
    void(^imageCompletedBlock)(UIImage *image, NSError *error, int cacheType);
}

@property (nonatomic,assign) UIImageView *imageView;
@property (nonatomic,retain) UIImage *placeholderImage;
@property (nonatomic,copy) NSString *url;
@property (nonatomic,copy) void(^imageDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);
@property (nonatomic,copy) void(^imageCompletedBlock)(UIImage *image, NSError *error, int cacheType);
@end
