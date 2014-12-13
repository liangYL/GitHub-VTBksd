//
//  Effects.h
//  VTDevKit
//
//  Created by wxc on 14/10/23.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Effects)
- (UIImage *)applyLightEffect;
- (UIImage *)applyExtraLightEffect;
- (UIImage *)applyDarkEffect;
- (UIImage *)applyTintEffectWithColor:(UIColor *)tintColor;
- (UIImage *)applyBlurWithRadius:(CGFloat)blurRadius tintColor:(UIColor *)tintColor saturationDeltaFactor:(CGFloat)saturationDeltaFactor maskImage:(UIImage *)maskImage;
@end
