//
//  STSelectPickerView.h
//  STSelectPickerView
//
//  Created by steve on 14-8-1.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#define kDeviceWidth ([UIScreen mainScreen].bounds.size.width)
#define KDeviceHeight ([UIScreen mainScreen].bounds.size.height)

#import <UIKit/UIKit.h>
@class STPickerView;

@protocol STPickerViewDelegate <NSObject>
@optional
- (void)pickerView:(STPickerView *)pickerView buttonIndex:(NSInteger)index selected:(NSInteger)selectIndex;
@end

@interface STSelectPickerView : UIView<STPickerViewDelegate>
{
    STPickerView *_pickerView;
    NSMutableArray *_dataArray;
    UILabel *_textLabel;
}
@property (nonatomic,retain) NSMutableArray *dataArray;
@property (nonatomic,copy) NSString *text;
@property (nonatomic,assign) NSInteger datelabelTextAlignment;//文本布局格式

- (void)showPickerView;
- (void)hiddentPickerView;
@end



@interface STPickerView : UIView<UIPickerViewDataSource,UIPickerViewDelegate>
{
    UIButton *_btn;
    UIPickerView *_picker;
    
    UIView *_toolBarView;
    UIButton *_cancelBtn;
    UIButton *_saveBtn;
    
    id<STPickerViewDelegate> _delegate;
    NSMutableArray *_dataArray;
    NSInteger _selectIndex;
}
@property (nonatomic,assign)id<STPickerViewDelegate> delegate;
@property (nonatomic,retain)NSMutableArray *dataArray;
@property (nonatomic,retain) UIPickerView *picker;

- (void)initView;
@end

