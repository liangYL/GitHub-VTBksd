//
//  DES3Util.h
//  SmallBook
//
//  Created by apple on 13-5-24.
//  Copyright (c) 2013年 王 晓超. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VTDES3Util : NSObject
// 加密方法
+ (NSString*)encrypt:(NSString*)plainText;

// 解密方法
+ (NSString*)decrypt:(NSString*)encryptText;
@end
