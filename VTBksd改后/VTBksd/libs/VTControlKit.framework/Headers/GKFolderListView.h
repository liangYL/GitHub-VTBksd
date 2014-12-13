//
//  GKFolderListView.h
//  GKListViewDemo
//
//  Created by GK on 14-8-1.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

typedef enum {
    GKListTypeFoldOne,      //始终展开一个
    GKListTypeFoldSelect,    //展开选择区域
    GKListTypeNomol       //始终展开 不做张开折叠操作
} GKListType;

@class GKFolderListView;
@protocol GKFolderListDelegate <NSObject>
- (void)cellClick:(NSInteger)indexPathSection cell:(NSInteger)indexPathCell;
- (UITableViewCell *)folderListView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIView *)folderListView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section;
- (NSArray *)sectionIndexTitlesForTableView:(UITableView *)tableView listView:(GKFolderListView *)listView;
@end

@interface GKFolderListView : UIView<UITableViewDelegate,UITableViewDataSource,XCAutoLayoutProtocol>
{
    UITableView *_tableView;
    NSMutableArray *_dataArray;
    NSInteger      _selectedIndex; //当前选择的行
    NSInteger lastBtnTag;   //上次选择的行
    BOOL *flag;
    
    id <GKFolderListDelegate> _delegate;
    
}
@property(nonatomic,retain) UITableView *tableView;
@property(nonatomic,assign) GKListType listType;
@property(nonatomic,retain) NSMutableArray *dataArray;
@property(nonatomic,assign) id<GKFolderListDelegate> delegate;
@property(nonatomic,assign) CGFloat sectionHeight;
@property(nonatomic,assign) CGFloat rowHeight;
@end


