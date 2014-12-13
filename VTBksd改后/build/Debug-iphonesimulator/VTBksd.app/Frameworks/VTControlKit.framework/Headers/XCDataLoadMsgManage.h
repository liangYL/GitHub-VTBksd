//
//  XCDataLoadMsgManage.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCControlKitUtil.h"

@interface XCDataLoadMsgManage : NSObject
DEFINE_SINGLETON_FOR_HEADER(XCDataLoadMsgManage);

- (void)saveLoadMsg:(id)msg key:(NSString *)key;
- (id)getLoadMsg:(NSString *)key;
- (void)removeLoadMsg:(NSString *)key;
@end
