//
//  STScrollImageListView.h
//  CreatKongjian
//
//  Created by steve on 14-9-10.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutProtocol.h"

@interface STScrollImageListView : UIView<XCAutoLayoutProtocol>
{
    UIScrollView *_superScrollView;
    CGFloat _space;
    CGFloat _imageWidth;
    CGFloat _imageHeight;
    NSArray *_imageNameArray;
}
@property (nonatomic,assign) CGFloat space,imageWidth,imageHeight;
@property (nonatomic,retain) NSArray *imageNameArray;
@end
