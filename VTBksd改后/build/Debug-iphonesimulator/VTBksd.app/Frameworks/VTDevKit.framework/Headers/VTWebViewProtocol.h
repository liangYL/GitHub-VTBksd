//
//  VTWebView.h
//  VTPlug
//
//  Created by GK on 14-7-2.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol VTWebViewDelegate <NSObject>
- (BOOL)returnSyncMessage:(id)data;

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)webViewDidStartLoad:(UIWebView *)webView;
- (void)webViewDidFinishLoad:(UIWebView *)webView;
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end

@protocol VTWebViewProtocol <NSObject>
@property (nonatomic,assign) id<VTWebViewDelegate> delegate;
@property (nonatomic,readonly) UIWebView *webView;
@end

