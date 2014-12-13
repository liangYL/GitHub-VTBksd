//
//  XCAttributeSearchListView.h
//  XCviewAttributeSearchListView
//
//  Created by wxc on 14-9-24.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XCAttributeSearchListView;
@class XCAttributeSearchListNodeView;

@protocol XCAttributeSearchListViewDataSource <NSObject>
- (NSInteger)attributeSearchListViewNumberOfRow:(XCAttributeSearchListView *)attView;
- (NSInteger)attributeSearchListViewNumberOfColumn:(XCAttributeSearchListView *)attView row:(NSInteger)row;
- (NSString *)attributeSearchListViewRowTitle:(XCAttributeSearchListView *)attView row:(NSInteger)row titleLabel:(UILabel *)titleLabel;
- (void)attributeSearchListViewRowTitle:(XCAttributeSearchListView *)attView row:(NSInteger)row column:(NSInteger)column nodeView:(XCAttributeSearchListNodeView *)nodeView;

@optional
- (CGFloat)attributeSearchListViewHeightOfRow:(XCAttributeSearchListView *)attView row:(NSInteger)row;
- (CGFloat)attributeSearchListViewTitleWidthOfRow:(XCAttributeSearchListView *)attView row:(NSInteger)row;
- (NSInteger)attributeSearchListViewDefSelectedColumn:(XCAttributeSearchListView *)attView row:(NSInteger)row;

@end
@protocol XCAttributeSearchListViewDelegate <NSObject>

@optional
- (void)attributeSearchListViewDidSelectedColumn:(XCAttributeSearchListView *)attView row:(NSInteger)row column:(NSInteger)column nodeView:(XCAttributeSearchListNodeView *)nodeView;
@end

@interface XCAttributeSearchListView : UIView
@property (nonatomic,assign) id<XCAttributeSearchListViewDataSource> dataSource;
@property (nonatomic,assign) id<XCAttributeSearchListViewDelegate> delegate;
@property (nonatomic,assign) BOOL isLine;  //是否换行
@property (nonatomic,assign) BOOL dividingLine;

- (void)load;
@end


@protocol XCAttributeSearchListNodeViewDelegate <NSObject>
@optional
- (void)attributeSearchListNodeViewClick:(XCAttributeSearchListNodeView *)nodeView;
@end
@interface XCAttributeSearchListNodeView : UIView
@property (nonatomic,readonly) UIButton *btn;
@property (nonatomic,assign) NSInteger row;
@property (nonatomic,assign) NSInteger column;
@property (nonatomic,assign) id<XCAttributeSearchListNodeViewDelegate> delegate;
@end
