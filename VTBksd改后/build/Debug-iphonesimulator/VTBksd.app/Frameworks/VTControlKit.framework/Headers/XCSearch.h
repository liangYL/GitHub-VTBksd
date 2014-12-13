//
//  XCSearchViewController.h
//  xmData
//
//  Created by wxc on 13-8-13.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol XCSearchDelegate;
@class XCSearchBar;
#import "GKFolderListView.h"



@interface XCSearch : NSObject <UISearchBarDelegate,UISearchDisplayDelegate,UITableViewDelegate,UITableViewDataSource>
{
    id <XCSearchDelegate> _delegate;
    
    CGRect      _initSearchRect;
    XCSearchBar *_searchBar;
    
    NSMutableArray *_searchDataArray;
    NSMutableArray *_searchResults;
    
    UISearchDisplayController *_searchDisplay;
    NSString *_searchField;
    NSArray  *_searchArray;
}
@property (nonatomic,retain) NSArray *searchDataArray;
@property (nonatomic,retain) NSMutableArray *searchResults;
@property (nonatomic,assign) id <XCSearchDelegate> delegate;


- (id)initWithViewController:(UIViewController *)viewController tableView:(UITableView *)tableView delegate:(id<XCSearchDelegate>)delegate searchArray:(NSArray *)searchArray;
- (id)initWithViewController:(UIViewController *)viewController scrollView:(UIScrollView *)scrollView delegate:(id<XCSearchDelegate>)delegate;

@end


@protocol XCSearchDelegate <NSObject>
@optional
- (BOOL)searchDisplayShouldForSearchString:(XCSearch *)search controller:(UISearchDisplayController *)controller string:(NSString *)string;
- (void)searchTableViewDidSelectRowIndexPath:(XCSearch *)search tableView:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath;
- (void)searchResultcancelBtnClick:(NSInteger)indexPath indexSection:(NSInteger)section;

- (UITableViewCell *)search:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath search:(XCSearch *)search;
- (CGFloat)search:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath search:(XCSearch *)search;
@end