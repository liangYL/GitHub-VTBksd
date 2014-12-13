//
//  STSelectDataPickerView.h
//  aaaa
//
//  Created by steve on 14/11/7.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#define kDeviceWidth ([UIScreen mainScreen].bounds.size.width)
#define KDeviceHeight ([UIScreen mainScreen].bounds.size.height)

#import <UIKit/UIKit.h>
@class STDataPickerView;

@protocol STDataPickerViewDelegate <NSObject>
@optional
- (void)dataPickerView:(STDataPickerView *)pickerView buttonIndex:(NSInteger)index date:(NSDate *)date;
@end


@interface STSelectDataPickerView : UIView<STDataPickerViewDelegate>
{
    STDataPickerView *_dataPickerView;
    NSString *_dataStr;
    UILabel *_dataLabel;
    NSString *_dataFormat;
}
@property (nonatomic,copy) NSString *dataStr;
@property (nonatomic,copy) NSString *dataFormat;//格式化时间格式
@property (nonatomic,assign) NSInteger datePickerMode;//dataPicker显示时间格式
@property (nonatomic,assign) NSInteger datelabelTextAlignment;//文本布局格式
@property (nonatomic,retain) NSDate *date;
@end

@interface STDataPickerView : UIView
{
    UIDatePicker *_dataPicker;
    
    UIView *_toolBarView;
    UIButton *_cancelBtn;
    UIButton *_saveBtn;
    id<STDataPickerViewDelegate> _delegate;
}
@property (nonatomic,assign) id<STDataPickerViewDelegate> delegate;
@property (nonatomic,assign) NSInteger datePickerMode;

- (void)initView;
@end

