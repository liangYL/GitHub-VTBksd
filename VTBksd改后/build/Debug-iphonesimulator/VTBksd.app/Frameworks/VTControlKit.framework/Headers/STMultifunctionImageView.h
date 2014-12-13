//
//  STMultifunctionImageView.h
//  CreatKongjian
//
//  Created by steve on 14-9-5.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STMultifunctionImageView : UIView<XCAutoLayoutProtocol>
{
    UIImageView *_imageView;
    UILabel *_cornerMark;
    UILabel *_textLabel;
    UILabel *_detailLabel;
    
    UIImage *_image;
    NSString *_cornerMarkTitle;
    NSString *_textLabelTitle;
    NSString *_detailLabelTitle;
    UIFont *_textLabelFont;
    UIFont *_detailLabelFont;
    float _imageCornerRadius;
    
    BOOL _cornerMarkHidden;
    BOOL _textLabelHidden;
    BOOL _detailLabelHidden;
}
@property (nonatomic,retain) UIImageView *imageView;
@property (nonatomic,retain) UILabel *cornerMark;
@property (nonatomic,retain) UILabel *textLabel;
@property (nonatomic,retain) UILabel *detailLabel;

@property (nonatomic,retain) UIImage *image;
@property (nonatomic,copy) NSString *cornerMarkTitle;
@property (nonatomic,copy) NSString *textLabelTitle;
@property (nonatomic,copy) NSString *detailLabelTitle;
@property (nonatomic,retain) UIFont *textLabelFont;
@property (nonatomic,retain) UIFont *detailLabelFont;

@property (nonatomic,assign) float imageCornerRadius;

@property (nonatomic,assign) BOOL cornerMarkHidden,textLabelHidden,detailLabelHidden;
@end
