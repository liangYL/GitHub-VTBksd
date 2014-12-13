//
//  STListView.h
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

typedef enum
{
    STListViewCellClick = 0,        //列表cell点击
    STListViewCellDeleteSucceed = 1 //列表cell左滑是否成功   0失败;1成功
}STListViewFunctionType;

@interface STListView : XCSuperModuleListView<UITableViewDataSource,UITableViewDelegate>

@property (nonatomic,retain) NSDictionary *parametersDic;
@end
