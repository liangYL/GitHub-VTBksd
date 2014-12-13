//
//  XCSuperModuleListView.h
//  VTControlKit
//
//  Created by wxc on 14-9-2.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import "XCSuperModuleView.h"
#import "XCPullTable.h"

#define PULL_TABLE_CHECK_TOP 55
@interface XCSuperModuleListView : XCSuperModuleView<UITableViewDataSource,UITableViewDelegate,XCPullTableViewDelegate>
{
    XCPullTableView *_tableView;
}
@property (nonatomic,assign) XCPullTableView *tableView;
@property (nonatomic,retain) XCAutoLayoutRoot *cellCss;
@property (nonatomic,retain) XCAutoLayoutRoot *headCss;
//
@property (nonatomic,copy) NSString *cellLayout;
@property (nonatomic,copy) NSString *headLayout;
@property (nonatomic,assign) NSInteger cellHeight;
@property (nonatomic,assign) NSInteger headHeight;

- (void)pullTableViewPullLoad:(XCPullTableView *)tableView;
- (void)pullTableViewMoreLoad:(XCPullTableView *)tableView;

- (void)getDataReload:(VTDevDataChannelDocData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
- (void)getDataAppend:(VTDevDataChannelDocData *)docData xform:(id)xform result:(void(^)(id))result error:(void(^)(id))error;
@end
