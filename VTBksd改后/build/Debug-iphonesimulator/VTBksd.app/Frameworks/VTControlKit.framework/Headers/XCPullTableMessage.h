//
//  XCPullTableMessage.h
//  XCPullTable
//
//  Created by wxc on 14-4-28.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XCPullTableMessage : UIView
{
    UIImageView *_imgage;
    UILabel     *_label;
}
@property (nonatomic,retain) UIImageView *imgage;
@property (nonatomic,retain) UILabel     *label;
@end
