//
//  STImageLabelView.h
//  KeyValue
//
//  Created by steve on 14-8-14.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

//*-------------Label--ImageView------------*
#import "STKeyValueView.h"

@interface STImageLabelView : STKeyValueView
{
    UIImageView *_imageView;
    UILabel *_label;
}
@property (nonatomic,retain)UIImageView *imageView;
@property (nonatomic,retain)UILabel *label;

@property (nonatomic,copy)NSString *text;
@property (nonatomic,retain)UIImage *image;
@end
