//
//  XCDataParsePartsProtocol.h
//  XCAddressBook
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

//数据转换配件协议

#import <UIKit/UIKit.h>

@protocol XCDataParsePartsProtocol <NSObject>
@required
- (id)dataParse:(id)sourceData parms:(id)parms;

@optional
+ (id)dataParseS:(id)sourceData parms:(id)parms;
@end
