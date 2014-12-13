//
//  XCLimitTextView.h
//  xmData
//
//  Created by apple on 13-7-22.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCManyStylesLabel.h"

@interface XCLimitTextView : UIView<UITextViewDelegate>
{
    UIView      *_view;
    UIImageView *_backgroundImgView;
    NSString    *_placeholder;
    UITextView  *_textView;
    UILabel     *_wordsNumberLabel; //限制字数显示
    
    XCManyStylesLabel *_placeholderLabel;
    
    int _limitWordNumber; //限制的字数
    BOOL _isError;
    
    id _isDelegate;
}
@property (nonatomic,assign) id isDelegate;
@property (nonatomic,readonly) UILabel *wordsNumberLabel,*bottomTitle;
@property (nonatomic,readonly) UITextView *textView;
@property (nonatomic,copy) NSString *text;
@property (nonatomic,assign) int limitWordNumber;
@property (nonatomic,assign) BOOL isError;
@property (nonatomic,copy) NSString *placeholder;
@property (nonatomic,assign)UIImage *backgroundImg;

- (void)setPlaceholderChangeTextColorForKey:(NSString *)key color:(UIColor *)color;

@end

@protocol XCLimitTextViewDelegate <NSObject>
@optional
- (void)textViewDidChange:(UITextView *)textView;
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString*)text;
- (void)textViewDidBeginEditing:(UITextView *)textView;
- (void)textViewDidEndEditing:(UITextView *)textView;
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;
@end