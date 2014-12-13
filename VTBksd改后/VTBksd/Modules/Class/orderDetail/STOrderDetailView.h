//
//  STOrderDetailView.h
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <VTControlKit/STLabelLabelView.h>
@interface STOrderDetailView : XCSuperModuleView

@property (nonatomic,retain) XCDataBlock *block;
@property (nonatomic,assign) UIScrollView *scrollView;
@property(nonatomic,assign)STLabelLabelView *de_addr;

@end
