//
//  XCAutoLayoutManage.h
//  VTControlKit
//
//  Created by wxc on 14/11/7.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCControlKitUtil.h"

@interface XCAutoLayoutManage : NSObject
{
    BOOL _isOldLayout;
}
@property (nonatomic,assign) BOOL isOldLayout;

DEFINE_SINGLETON_FOR_HEADER(XCAutoLayoutManage);
@end
