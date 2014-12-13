//
//  XCXMLParse.h
//  testAutoLayout
//
//  Created by wxc on 14-8-11.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <Foundation/Foundation.h>
@class XCXMLElement;

@interface XCXMLParse : NSObject<NSXMLParserDelegate>

- (XCXMLElement *)parse:(NSString *)xml;
@end

@interface XCXMLElement : NSObject
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *text;
@property (nonatomic,retain) NSMutableDictionary *attributes;
@property (nonatomic,retain) NSMutableArray *subElements;
@property (nonatomic,assign) XCXMLElement *parent;
@end