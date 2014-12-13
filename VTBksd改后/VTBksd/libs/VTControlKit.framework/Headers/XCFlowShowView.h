//
//  XCFlowShowView.h
//  HD-Ipad
//
//  Created by 王 晓超 on 12-12-8.
//  Copyright (c) 2012年 王 晓超. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCPullScrollView.h"

@class XCFlowShowView;
@class XCFlowCell;
#define vOPTIMIZE_VALUE  5.0   //优化值
#define vOPTIMIZE_TOP_BOTTOM_SPLIT_VALUE 30.0  //优化上下显示范围值+value个像素点 时期即使在屏幕范围外value个像素点依然算作在屏幕范围内

typedef struct
{
    float top;
    float left;
}Gap;   //间距
typedef struct
{
    float x;
    float y;
    float h;
}CellSiteDec;   //cell位置描述
typedef struct
{
    int row;
    int column;
}NSIndexCell;

#pragma mark -
#pragma mark XCFlowShowViewDataSource
@protocol XCFlowShowViewDataSource <NSObject>
@optional
- (NSInteger)numberColumnInView:(XCFlowShowView *)flowShowView;  //列数据源
- (Gap)cellGapInView:(XCFlowShowView *)flowShowView;      //间隙
@required
- (float)heightInIndexCell:(NSIndexCell)index;
- (NSInteger)numberCellInView:(XCFlowShowView *)flowShowView;  //传入数据个数
- (XCFlowCell *)cellForRowInColumn:(XCFlowShowView *)flowShowView index:(NSIndexCell)index frame:(CGRect)frame;
@end
#pragma mark -
#pragma mark XCFlowShowViewDelegate
@protocol XCFlowShowViewDelegate <NSObject>
@optional
- (void)didSelectedIndexCell:(XCFlowShowView *)flowShowView index:(NSIndexCell)index columnNum:(NSInteger)columnNum;  //点击
@end

@protocol XCFlowShowViewDataSource;
@class XCFlowCell;
@interface XCFlowShowView : XCPullScrollView <UIScrollViewDelegate>
{
    float _optimizeValue;
    float _optimizeTopBottomSpliteValue;
    
    float _offSetY;     //记录当前滚动位置
    
    //需初始化传入参数
    int   _columnNumber;    //多少列
    int   _dataCount;       //多少个数据
    
    Gap   _gap;     //间距
    
    id<XCFlowShowViewDataSource> _flowDataSource;
    id<XCFlowShowViewDelegate> _flowDelegate;
    
    NSMutableArray *_columnY;
    
    float   _columnWidth;     //列宽
    NSIndexCell   _currentLoadIndexCell;        //当前加载数据最后数据位置信息

    NSMutableDictionary *_dicReuseCells; //重用的cell
    NSMutableArray      *_nowWindowViewCellArray;  //现在在window上显示的cell
    NSMutableArray      *_cellRectArray;        //存入所有cell的frame
}
@property (nonatomic,assign) id<XCFlowShowViewDataSource> flowDataSource;
@property (nonatomic,assign) id<XCFlowShowViewDelegate> flowDelegate;

- (void)reloadFlow;
- (void)reloadAppendData;

+ (NSIndexCell)CGIndexCellMark:(int)row column:(int)column;
+ (Gap)CGGapMark:(float)top left:(float)left;


- (XCFlowCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
@end

#pragma mark -
#pragma mark cell

@interface XCFlowCell : UIView
{
    id _delegate;
    
    NSString *_strReuseIndentifier;
    NSIndexCell _indexCell;
    
    UIImageView *_imgView;
    
}
@property (nonatomic,assign) id delegate;
@property (nonatomic,assign) NSIndexCell indexCell;
@property (nonatomic,copy) NSString *strReuseIndentifier;
@property (nonatomic,retain) UIImageView *imgView;

- (id)initWithIndentifier:(NSString *)indentifier;
@end


