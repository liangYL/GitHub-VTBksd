//
//  XCSingleSelectView.h
//  小小本
//
//  Created by apple on 13-4-25.
//  Copyright (c) 2013年 王 晓超. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface XCSingleView : UIView
{
    UIButton  *_selectBtn;
    UILabel   *_title;
}
@property (nonatomic,retain) UILabel *title;
@property (nonatomic,retain) UIButton *selectBtn;


@end

@protocol XCSingleSelectViewDelegate <NSObject>

@optional
- (void)selectedIndex:(NSInteger)index;

@end

@interface XCSingleSelectView : UIView<XCModuleProtocol>
{
    NSArray *_array;
    
    NSMutableArray *_viewArray;
    
    NSInteger  _selectedIndex;
    id<XCSingleSelectViewDelegate> _delegate;
}
@property (nonatomic,assign) NSInteger selectedIndex;
@property (nonatomic,retain) NSArray *array;
@property (nonatomic,assign) id<XCSingleSelectViewDelegate> delegate;
- (id)initWithFrame:(CGRect)frame array:(NSArray *)array;

- (void)selectedIndexBtn:(NSInteger)index;
@end




