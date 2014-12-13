//
//  UINavigationBar+Custom.m
//  漫游无限
//
//  Created by meway on 13-2-1.
//
//

#import "UINavigationBar+Custom.h"

@implementation UINavigationBar (Custom)

- (void)drawRect:(CGRect)rect
{
    UIImage *bg = [UIImage imageNamed:NAV_BG_IMG6];
    [bg drawInRect:rect];
}

- (void)customNavigationBackGround
{
    self.translucent = NO;
    if (IOS5)
    {
        [self setBackgroundImage:[UIImage imageNamed:NAV_BG_IMG6] forBarMetrics:UIBarMetricsDefault];
    }
    if (IOS7)
    {
        [self setBackgroundImage:[UIImage imageNamed:NAV_BG_IMG7] forBarMetrics:UIBarMetricsDefault];
    }

    
}

@end
