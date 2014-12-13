//
//  VTXUtil.h
//  VTX
//
//  Created by wxc on 14-9-22.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VTDevKit/VTLogProtocol.h>
#import <VTDevKit/VTIceUserManage.h>

@interface VTXUtil : NSObject
/**
 *获取一个image资源
 *@param imageName资源名称
 *@return image对象
 */
+ (UIImage *)getResImage:(NSString *)imageName;

/**
 *获取资源路径
 *@return image对象
 */
+ (NSString *)getResPath;

/**
 *获取一个文件的资源路径
 *@param fileName文件名称
 *@return 路径
 */
+ (NSString *)getResPathByFile:(NSString *)fileName;

+ (NSString *)parsePath:(NSString *)path;
@end
