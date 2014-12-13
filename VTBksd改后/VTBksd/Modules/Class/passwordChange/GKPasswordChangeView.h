//
//  GKPasswordChangeView.h
//  VTBksd
//
//  Created by GK on 14-10-28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VTControlKit/STButtonView.h>
#import <VTControlKit/STLabelTextFieldView.h>
typedef enum
{
    saveCode
}GKPasswordChangeViewEvent;
@interface GKPasswordChangeView : STAutoKeyBoardSuperView
@property(nonatomic,assign)STButtonView*exitButton;
@property(nonatomic,assign)STLabelTextFieldView*orginUserCode;
@property(nonatomic,assign)STLabelTextFieldView*newUserCode;
@property(nonatomic,assign)STLabelTextFieldView*confirmCode;
@end


@interface XCChanngePwdData : NSObject<VTIceDataOperationProtocol>
@property (nonatomic,copy) NSString *controlid,*clientid,*systemid,*formid;
@property (nonatomic,retain) NSMutableDictionary *dataparam;
@property (nonatomic,assign) id<VTIceDataParamsObj> _dataParams;  //装配参数
@end