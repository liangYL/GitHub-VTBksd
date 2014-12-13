//
//  XCMultiLayoutModelCell.h
//  CreatZujian
//
//  Created by steve on 14-9-24.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XCAutoLayoutController.h"
#import "XCAutoLayoutProtocol.h"

@protocol XCMultiLayoutModelCellDelegate;

@interface XCMultiLayoutModelCell : UITableViewCell<XCModuleProtocol>
{
    NSMutableArray *_autoLayoutControllerArray;
    NSMutableArray *_views;
    id<XCMultiLayoutModelCellDelegate> _delegate;
}
@property (nonatomic,assign) id<XCMultiLayoutModelCellDelegate> delegate;

@property (nonatomic,assign) NSArray *autoLayoutCss;
@property (nonatomic,readonly) NSMutableArray *autoLayoutControllerArray;
@property (nonatomic,retain) NSIndexPath *indexPath;

- (void)startLoad;
- (void)setCssHiddent:(BOOL)b lie:(NSInteger)lie;
@end


@protocol  XCMultiLayoutModelCellDelegate<NSObject>

@optional
- (void)cell:(XCMultiLayoutModelCell *)cell didSelectRowAtIndexPath:(NSIndexPath *)indexPath lie:(NSInteger)lie;

@end
