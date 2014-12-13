//
//  XCSuperModuleFlowView.h
//  vwedd
//
//  Created by steve on 14/10/22.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "XCSuperModuleView.h"
#import "XCFlowShowView.h"
#import "XCSuperModuleFlowCell.h"

@interface XCSuperModuleFlowView : XCSuperModuleView<XCFlowShowViewDataSource,XCFlowShowViewDelegate,XCPullScrollViewDelegate>
{
    XCFlowShowView *_flowShowView;
}
@property (nonatomic,assign) XCFlowShowView *flowShowView;
@property (nonatomic,retain) XCAutoLayoutRoot *cellCss;
@property (nonatomic,copy) NSString *cellLayout;
@property (nonatomic,assign) NSInteger columnNumber;
@property (nonatomic,assign) CGFloat top;
@property (nonatomic,assign) CGFloat left;

- (void)pullScrollViewPullLoad:(UIScrollView *)scroll;
- (void)pullScrollViewMoreLoad:(UIScrollView *)scroll;

- (void)getDataReload:(VTDevDataChannelDocData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
- (void)getDataAppend:(VTDevDataChannelDocData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
@end
