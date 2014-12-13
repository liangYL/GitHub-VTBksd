//
//  XCAutoLayout.h
//  VTControlKit
//
//  Created by wxc on 14/11/5.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutCSSTransform.h"

@class XCAutoLayoutDIV;
@interface UIView (XCAutoLayout)

- (void)xcChangeAutoLayoutSize:(CGSize)size;
- (void)xcChangeAutoLayoutMargin:(XCMargin)margin;
- (XCAutoLayoutDIV *)xcGetAutoLayoutCss;
@end
