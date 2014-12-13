//
//  XCChinessSortABCParse.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataParsePartsProtocol.h"

@interface XCChinessSortABCParse : NSObject<XCDataParsePartsProtocol>

/**
 *ABC分组数据转换配件
 *sourceData 传入原数据  parms参数 @{@"code":@"name"} 传入字典code为key分组name字段
 */
- (id)dataParse:(id)sourceData parms:(id)parms;

+ (id)dataParseS:(id)sourceData parms:(id)parms;
@end
