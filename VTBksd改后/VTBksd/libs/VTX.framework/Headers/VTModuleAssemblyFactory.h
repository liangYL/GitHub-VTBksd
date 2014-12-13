//
//  XCModuleAssemblyFactory.h
//  testAutoLayout
//
//  Created by wxc on 14-8-27.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VTModuleAssemblyFactory : NSObject

+ (VTModuleAssemblyFactory *)initFactory:(NSString *)filePath;
+ (VTModuleAssemblyFactory *)sharedModuleAssemblyFactory;
- (void)setPageFile:(NSString *)filePath;
- (void)setPageFileArray:(NSArray *)filePaths;
- (void)setPageFileBundle:(NSString *)path;

- (void)assemblyPage:(NSString *)pageCode tag:(id)tag;
- (void)assemblyPageA:(NSString *)pageCode tag:(id)tag;
@end
