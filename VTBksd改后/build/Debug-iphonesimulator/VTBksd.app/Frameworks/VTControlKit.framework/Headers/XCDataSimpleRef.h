//
//  XCDataSimpleRef.h
//  VTControlKit
//
//  Created by wxc on 14/10/21.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XCDataBlockProxyPro.h"
#import "XCAutoLayoutCSSPars.h"

@interface XCDataSimpleRef : NSObject
@property (nonatomic,copy) NSString *refname;
@property (nonatomic,copy) NSString *tablename;
@property (nonatomic,retain) NSMutableArray *nodes;
@property (nonatomic,assign) XCDataSimpleRef *superRef;
@property (nonatomic,retain) id data;
@property (nonatomic,retain) id path;
@property (nonatomic,retain) id rowPath;
@property (nonatomic,assign) XCAutoLayoutViewRef *refView;
@property (nonatomic,assign) id<XCDataBlockProxyPro> aClass;


- (void)getData;
- (void)setCurrentRow:(id)rowPath;
@end
