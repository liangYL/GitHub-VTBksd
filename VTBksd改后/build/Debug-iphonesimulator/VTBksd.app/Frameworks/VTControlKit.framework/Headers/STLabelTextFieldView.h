//
//  STLabelTextFieldView.h
//  KeyValue
//
//  Created by steve on 14-8-14.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//*-------------Label--TextFiled------------*
#import "STKeyValueView.h"

@interface STLabelTextFieldView : STKeyValueView
{
    UILabel *_label;
    UITextField *_textField;
    NSString *_labeltext;
    NSString *_textFieldtext;
    NSString *_textFieldPlaceholder;
    UIImage *_textFieldBgImage;
}
@property (nonatomic,retain)UILabel *label;
@property (nonatomic,retain)UITextField *textField;
@property (nonatomic,copy)NSString *labeltext,*textFieldtext,*textFieldPlaceholder;
@property (nonatomic,retain)UIImage *textFieldBgImage;
@end
