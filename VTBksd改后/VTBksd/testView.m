//
//  testView.m
//  VTBksd
//
//  Created by zcyx on 14-12-12.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "testView.h"

@implementation testView

-(void)startLoad
{
    [super startLoad];
    
    
    UITapGestureRecognizer *codetap=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(codeModify)];
    [_img addGestureRecognizer:codetap];
    
    
    
}
- (void)codeModify{
    [self.hud showOKHud:@"显示" delay:2];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
