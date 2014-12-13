//
//  STOrderDetailView.m
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STOrderDetailView.h"
@interface STOrderDetailView ()
{
    BOOL _load;
}
@end
@implementation STOrderDetailView

- (void)startLoad
{
    [super startLoad];
    NSLog(@"%@",_block.data);
    self.de_addr.rightLabel.numberOfLines=0;
    [_block.aClass dataImmit:_block.data views:self.autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
        
        
        if ([layout.css.cid isEqualToString:@"docdate"] || [layout.css.cid isEqualToString:@"back_date"])
        {
            if ((NSNull *)value == [NSNull null])
            {
                return nil;
            }
            
            return [VTDevUtil dateFormatter:[VTDevUtil stringToDate:value format:ALL_DEFAULT_TIME_FORM] format:ALL_DEFAULT_TIME_FORM];
        }
        return value;
        
    } imageFilter:nil];
    
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    if (_load == NO)
    {
        _load = YES;
        
        [self layoutProductView];
    }
    
}
- (void)layoutProductView
{
    UIView *product = [[UIView alloc] init];
    [_scrollView addSubview:product];
    
    id obj = [[_block.data objectForKey:@"morder_app_item"] objectForKey:@"dataArray"];
    product.frame = CGRectMake(0, 320, self.frame.size.width, 50*[obj count]);
    
    for (int i = 0; i<[obj count]; i++)
    {
        UIView *productView = [[UIView alloc] init];
        productView.frame = CGRectMake(0, 50*i, self.frame.size.width, 50);
        [product addSubview:productView];
        
        XCAutoLayoutRoot *css = [XCAutoLayoutController getLayoutFilePathDataXML:@"@STProductDetail.xml" settings:nil frameWarehouse:[VTFrameWarehouse sharedWarehouse]];
        XCAutoLayoutController *autoLayout = [[XCAutoLayoutController alloc] initWithView:productView layoutRoot:css settings:nil];
        
        [_block.aClass dataImmit:[obj objectAtIndex:i] views:autoLayout.views map:nil filter:^id(XCAutoLayout *layout, NSString *key, NSString *value) {
            
            if ([layout.css.cid isEqualToString:@"productPrice"])
            {
                NSString *aa=[NSString stringWithFormat:@"%.2f",value.doubleValue];
                return [NSString stringWithFormat:@"￥:%@",aa];
            }
            if ([layout.css.cid isEqualToString:@"productCount"])
            {
                return [NSString stringWithFormat:@"x %@",value];
            }
            return value;
            
        } imageFilter:nil];
        
        
    }
    
    int qty = 0;//个数
    float amount = 0;//应收
    float samount = 0;//优惠
    float sumamount = 0;//实收
    for (int i = 0; i<[obj count]; i++)
    {

        NSLog(@">>>>>>>>>>>>>>>>>>>>>>%@",obj);
        
        
        int a = [[[obj objectAtIndex:i] objectForKey:@"qty"] intValue];
        float b = [[[obj objectAtIndex:i] objectForKey:@"amount"] floatValue];
        float c = [[[obj objectAtIndex:i] objectForKey:@"samount"] floatValue];
        float d = [[[obj objectAtIndex:i] objectForKey:@"sumamount"] floatValue];
        
        qty += a;
        amount += b;
        samount += c;
        sumamount += d;
    }
    
    UIView *statisticsView = [[UIView alloc] init];
    statisticsView.frame = CGRectMake(0, product.frame.origin.y + product.frame.size.height +10, self.frame.size.width, 60);
    [_scrollView addSubview:statisticsView];
    [statisticsView release];
    
    UILabel *countLabel = [[UILabel alloc] init];
    countLabel.frame = CGRectMake(10, 0, self.frame.size.width-30, 30);
    countLabel.textAlignment = NSTextAlignmentRight;
    countLabel.font = [UIFont systemFontOfSize:12];
    countLabel.text = [NSString stringWithFormat:@"共计 %i 件商品",qty];
    [statisticsView addSubview:countLabel];
    [countLabel release];
    
    UILabel *yingfu = [[UILabel alloc] init];
    yingfu.frame = CGRectMake(10, 30, 90, 30);
    yingfu.font = [UIFont systemFontOfSize:12];
    yingfu.textAlignment = NSTextAlignmentCenter;
    yingfu.text = [NSString stringWithFormat:@"应付:￥%.2f",amount];
    [statisticsView addSubview:yingfu];
    [yingfu release];
    
    UILabel *youhui = [[UILabel alloc] init];
    youhui.frame = CGRectMake(110, 30, 90, 30);
    youhui.font = [UIFont systemFontOfSize:12];
    youhui.textAlignment = NSTextAlignmentCenter;
    youhui.text = [NSString stringWithFormat:@"优惠:￥%.2f",samount];
    [statisticsView addSubview:youhui];
    [youhui release];
    
    UILabel *shishou = [[UILabel alloc] init];
    shishou.frame = CGRectMake(210, 30, 90, 30);
    shishou.font = [UIFont systemFontOfSize:12];
    shishou.textAlignment = NSTextAlignmentCenter;
    shishou.text = [NSString stringWithFormat:@"实收:￥%.2f",sumamount];
    [statisticsView addSubview:shishou];
    [shishou release];
    
    _scrollView.contentSize = CGSizeMake(_scrollView.frame.size.width, statisticsView.frame.origin.y+statisticsView.frame.size.height + 50);
}

@end
