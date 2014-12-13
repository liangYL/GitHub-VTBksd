//
//  STSegmentedButtonView.h
//  www
//
//  Created by steve on 13-12-27.
//  Copyright (c) 2013年 刘国君. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol STSegmentedButtonViewDelegate <NSObject>

@optional
- (void)segmentedButtonSelectedIndex:(NSUInteger)segment button:(UIButton *)btn;

@end

@interface STSegmentedButtonView : UIView
{
    NSArray *_btnArray;
    NSMutableArray *_btnArr;
    NSArray *_nomalArray;
    NSArray *_hightArray;
    id<STSegmentedButtonViewDelegate> _delegate;
    
    NSInteger   _selectedIndex;
}
@property (nonatomic,assign) id<STSegmentedButtonViewDelegate> delegate;
@property (nonatomic,readonly) NSMutableArray *btnArr;
@property (nonatomic,assign) NSInteger selectedIndex;
@property (nonatomic,retain) NSArray *nomalArray;
@property (nonatomic,retain) NSArray *hightArray;

- (id)initWithbutton:(NSArray *)btnArray frame:(CGRect)frame;
- (id)initWithNomal:(NSArray *)nomalArray height:(NSArray *)hightArray frame:(CGRect)frame;
- (void)initViewNomal:(NSArray *)nomalArray height:(NSArray *)hightArray;
- (void)btnClick:(UIButton *)btn;
@end
