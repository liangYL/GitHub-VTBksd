//
//  GKSwitchListView.h
//  VTControlKit
//
//  Created by wxc on 14-9-15.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCSuperModuleView.h"
#import "STSegmentedButtonView.h"
#import "XCPullTableView.h"
#import "XCForm.h"

#define PULL_TABLE_CHECK_TOP 55
@interface XCSegmentedListView : XCSuperModuleView<STSegmentedButtonViewDelegate,UITableViewDataSource,UITableViewDelegate,XCPullTableViewDelegate>
@property (nonatomic,retain) NSMutableArray *cellCSS;
@property (nonatomic,retain) NSArray *nomolImgArray;
@property (nonatomic,retain) NSArray *highImgArray;
@property (nonatomic,assign) STSegmentedButtonView *segmentView;
@property (nonatomic,retain) NSMutableArray *cellLayoutPaths;
@property (nonatomic,retain) NSMutableArray *tableCellHeights;

- (void)setTableDelegate:(XCPullTableView *)pullTableView;

- (void)pullTableViewPullLoad:(XCPullTableView *)tableView;
- (void)pullTableViewMoreLoad:(XCPullTableView *)tableView;

- (void)getData:(VTDevDataChannelDocData *)docData index:(NSInteger)index result:(void(^)(id))result error:(void(^)(id))error;
- (void)getDataReload:(VTDevDataChannelDocData *)docData index:(NSInteger)index result:(void(^)(id))result error:(void(^)(id))error;
- (void)getDataAppend:(VTDevDataChannelDocData *)docData index:(NSInteger)index result:(void(^)(id))result error:(void(^)(id))error;
@end
