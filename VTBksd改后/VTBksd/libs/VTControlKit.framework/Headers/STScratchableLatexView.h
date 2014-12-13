//
//  STScratchableLatexView.h
//  CreatKongjian
//
//  Created by steve on 14-9-5.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol STScratchableLatexViewDataSource;
@protocol STScratchableLatexViewDelegate;

@interface STScratchableLatexIndex : NSObject
{
    NSInteger _section;//页
    NSInteger _row;//行
    NSInteger _line;//列
}
@property (nonatomic,assign) NSInteger section,row,line;
@end

@interface STScratchableLatexView : UIView<UIScrollViewDelegate>
{
    UIScrollView *_superScrollView;
    UIPageControl *_pageControl;
    id<STScratchableLatexViewDataSource> _dataSource;//数据源代理
    id<STScratchableLatexViewDelegate> _delagate;//代理
    
    BOOL _showTable;//是否显示表格线
    NSMutableDictionary *_dic;
}
@property (nonatomic,assign)id<STScratchableLatexViewDataSource> dataSource;
@property (nonatomic,assign)id<STScratchableLatexViewDelegate> delagate;
@property (nonatomic,assign)BOOL showTable;
- (void)layoutView;
@end

@protocol STScratchableLatexViewDataSource <NSObject>

- (NSInteger)numberOfSection;//返回有多少页
- (NSInteger)numberOfRowInSection:(STScratchableLatexIndex *)index;//某页有多少行
- (NSInteger)numberOfLineInSection:(STScratchableLatexIndex *)index;//某页某行有多少列
@end

@protocol STScratchableLatexViewDelegate <NSObject>

- (UIView *)scratchableLatexView:(STScratchableLatexView *)view contentView:(UIView *)content cellForRowAtIndex:(STScratchableLatexIndex *)index;//某块view
@optional
- (CGFloat)scratchableLatexView:(STScratchableLatexView *)view heightForRowAtIndex:(STScratchableLatexIndex *)index;//某块高度
- (CGFloat)scratchableLatexView:(STScratchableLatexView *)view widthForlineAtIndex:(STScratchableLatexIndex *)index;//某块宽度

- (void)scratchableLatexView:(STScratchableLatexView *)view contentView:(UIView *)content didSelectRowAtIndexPath:(STScratchableLatexIndex *)index;//某块点击事件

@end


@interface STScratchableLatexContentView : UIView

@property (nonatomic,retain)STScratchableLatexIndex *index;
@end