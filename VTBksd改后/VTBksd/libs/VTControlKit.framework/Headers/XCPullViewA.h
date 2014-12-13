//
//  XCCPullTopView.h
//  XCPullTable
//
//  Created by wxc on 14-1-10.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import "XCPullTableView.h"


#define ccPULL_BG_IMAGE @""
#define ccPULL_ARROW_IMAGE  @"arrow1@2x.png"
#define ccPULL_ARROW_W  18
#define ccPULL_ARROW_H  18
#define ccPULL_ACTIVITY_W   25
#define ccPULL_ACTIVITY_H   25

#define ccLABEL_TEXT1   @"下拉可以刷新"
#define ccLABEL_TEXT2   @"松开即可刷新"
#define ccLABEL_TEXT3   @"正在刷新..."

#define ccMORE_ACTIVITY_WIDTH 25          //加载更多菊花宽
#define ccMORE_ACTIVITY_HEIGHT 25         //加载更多菊花高
#define ccMORE_STATE_LABEL_HEIGHT 16      //加载更多状态文本高
#define ccMORE_STATE_LABEL_WIDTH 80       //加载更多状态文本宽
#define ccMORE_STATE_LABEL_FONT [UIFont fontWithName:@"STHeitiSC-Light" size:12] //加载更多状态文本字体
#define ccMORE_STATE_LABEL_TEXTCOLOR [UIColor blackColor]         //加载更多状态文本字体颜色
#define ccMORE_BG_IMAGE_NAME @""              //加载更多背景图片
#define ccMORE_STATE_TEXT_LOADMORE @"加载更多"
#define ccMORE_STATE_TEXT_DID_LOADING @"释放加载更多"
#define ccMORE_STATE_TEXT_LOADING  @"加载中..."
#define ccMORE_STATE_TEXT_NOTMORE  @"没有更多"

@interface XCPullTopView : XCPullView
{
    UIImageView     *_bgImageView;
    UIImageView     *_arrowImageView;
    UILabel         *_label;
    UIActivityIndicatorView *_activityView;
}

@end

@interface XCPullDownView : XCPullView
{
    UIImageView *_bgImageView;
    UILabel *_stateLable;
    UIActivityIndicatorView *_activityView;
}
@property (nonatomic,retain) UILabel *stateLable;
@property (nonatomic,retain) UIActivityIndicatorView *activityView;
@property (nonatomic,retain) UIImageView *bgImageView;
@end
