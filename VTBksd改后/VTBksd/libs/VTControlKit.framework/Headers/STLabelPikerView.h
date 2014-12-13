//
//  STLabelPikerView.h
//  KeyValue
//
//  Created by steve on 14-8-16.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//*-------------Label--PickView------------*

#import "STKeyValueView.h"
#import "STSelectPickerView.h"

@interface STLabelPikerView : STKeyValueView
{
    UILabel *_label;
    STSelectPickerView *_pickView;
}
@property (nonatomic,retain)UILabel *label;
@property (nonatomic,retain)STSelectPickerView *pickView;

@property (nonatomic,copy)NSString *labeltext,*pickViewTitle;
@end