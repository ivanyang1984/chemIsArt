//
//  XSizePolicy.h
//  XLayout
//
//  Created by go886 on 15/5/9.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import "IXLayout.h"

extern const CGFloat kMaxLayoutLen;
extern const CGFloat kMinLayoutLen;

typedef struct {
    CGFloat minWidth;
    CGFloat minHeight;
    CGFloat maxWidth;
    CGFloat maxHeight;
}SizeInfo;

typedef enum {
    XSizePolicyStyleDefault = 0,
    XSizePolicyStyleAbsolute,
}XSizePolicyStyle;

@interface XSizePolicy : NSObject<IXLayout>
@property(nonatomic,assign)XSizePolicyStyle style;
@property(nonatomic,assign)BOOL isLazy;
@property(nonatomic,assign)CGFloat minWidth;
@property(nonatomic,assign)CGFloat maxWidth;
@property(nonatomic,assign)CGFloat minHeight;
@property(nonatomic,assign)CGFloat maxHeight;
@property(nonatomic,assign)CGFloat filledScalex;
@property(nonatomic,assign)CGFloat filledScaley;
@property(nonatomic,assign)CGFloat paddingLeft;
@property(nonatomic,assign)CGFloat paddingTop;
@property(nonatomic,assign)CGFloat paddingRight;
@property(nonatomic,assign)CGFloat paddingBottom;
@property(nonatomic,assign)CGFloat marginLeft;
@property(nonatomic,assign)CGFloat marginTop;
@property(nonatomic,assign)CGFloat marginRight;
@property(nonatomic,assign)CGFloat marginBottom;
@property(nonatomic,assign,readonly) BOOL hasMinWidth;
@property(nonatomic,assign,readonly) BOOL hasMaxWidth;
@property(nonatomic,assign,readonly) BOOL hasMinHeight;
@property(nonatomic,assign,readonly) BOOL hasMaxHeight;
@property(nonatomic,assign,readonly) BOOL hasMarginLeft;
@property(nonatomic,assign,readonly) BOOL hasMarginTop;
@property(nonatomic,assign,readonly) BOOL hasMarginRight;
@property(nonatomic,assign,readonly) BOOL hasMarginBottom;
@property(nonatomic,assign,readonly) BOOL isActive;

-(void)setPadding:(CGFloat)padding;
-(void)setMargin:(CGFloat)margin;
-(void)setExpand:(BOOL)expand collapsible:(BOOL)collapsible;
-(void)setExpand:(BOOL)expand;
-(void)setWidthExpand:(BOOL)expand;
-(void)setHeightExpand:(BOOL)expand;
-(void)setFixed:(CGFloat)len;
-(void)setFixedWidth:(CGFloat)width;
-(void)setFixedHeight:(CGFloat)height;
-(void)setFilledScale:(CGFloat)scale;

-(void)addConstraints:(void (^)(UIView* v))block;
-(void)removeConstraints:(id)block;
-(void)clearConstraints;

-(SizeInfo)hitSizeInfo:(UIView*)v wHint:(CGFloat)wHint hHint:(CGFloat)hHint;
@end