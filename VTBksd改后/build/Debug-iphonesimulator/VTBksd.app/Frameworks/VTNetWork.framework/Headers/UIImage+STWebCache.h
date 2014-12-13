//
//  UIImage+STWebCache.h
//  IBS-DEV
//
//  Created by steve on 14-6-4.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDWebImageCompat.h"
#import "SDWebImageManager.h"

@interface UIImage (STWebCache)
- (void)setImageWithURL:(NSURL *)url;
@end
