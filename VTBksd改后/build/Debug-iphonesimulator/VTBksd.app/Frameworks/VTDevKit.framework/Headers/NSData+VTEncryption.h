//
//  NSData+Encryption.h
//  SmallBook
//
//  Created by apple on 13-5-24.
//  Copyright (c) 2013年 王 晓超. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (VTEncryption)
- (NSData *)AES256EncryptWithKey:(NSData *)key;   //加密
- (NSData *)AES256DecryptWithKey:(NSData *)key;   //解密
- (NSString *)newStringInBase64FromData;            //追加64编码
+ (NSString*)base64encode:(NSString*)str;           //同上64编码
@end
