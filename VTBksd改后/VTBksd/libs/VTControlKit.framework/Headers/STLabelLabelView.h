//
//  STLabelLabelView.h
//  KeyValue
//
//  Created by steve on 14-8-14.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//*-------------Label--Label------------*
#import "STKeyValueView.h"

@interface STLabelLabelView : STKeyValueView
{
    UILabel *_leftLabel;
    UILabel *_rightLabel;
}
@property (nonatomic,retain)UILabel *leftLabel;
@property (nonatomic,retain)UILabel *rightLabel;

@property (nonatomic,copy)NSString *lefttext,*righttext;

@end
