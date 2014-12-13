//
//  XCManyStylesLabel.h
//  SmallBook
//
//  Created by apple on 13-5-15.
//  Copyright (c) 2013年 王 晓超. All rights reserved.
//

#import <UIKit/UIKit.h>
/*标示左右间距 */
struct XCGap {
    float left;
    float right;
};
typedef struct XCGap XCGap;
@interface XCManyStylesLabel : UILabel
{
    NSMutableAttributedString *resultAttributedString;
    
    BOOL _isBLine;
    XCGap _lineGap;
    UIColor *_lineColor;
}
- (void)setLineToGap:(XCGap)gap color:(UIColor *)color;
-(void)setKeyWordTextArray:(NSArray *)keyWordArray WithFont:(UIFont *)font AndColor:(UIColor *)keyWordColor;
-(void)setText:(NSString *)text WithFont:(UIFont *)font AndColor:(UIColor *)color;

@end
