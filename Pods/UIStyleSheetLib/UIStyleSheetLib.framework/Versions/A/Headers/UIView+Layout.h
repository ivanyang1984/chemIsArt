//
//  UIView+Layout.h
//  MyLayout
//
//  Created by go886 on 14-5-28.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XSizePolicy.h"
@class XBaseLayout;
@class XSizePolicy;

@interface UIView (Layout)
@property(nonatomic,strong)XBaseLayout* frameLayout;
@property(nonatomic,strong)XSizePolicy* sizePolicy;


-(void)layout;
-(void)layout:(BOOL)animate;
-(void)layout:(BOOL)animate withDuration:(NSTimeInterval)duration;
-(void)layout:(BOOL)animate withDuration:(NSTimeInterval)duration completion:(void (^)(BOOL finished))completion;

-(CGRect)getClientFrame;
-(SizeInfo)hitSizeInfo:(CGFloat)wHint hHint:(CGFloat)hHint;
@end

@interface UIScrollView (Layout)
@property(nonatomic,assign)CGSize contentOffSize;
-(void)setContentSizeForLayout;
@end