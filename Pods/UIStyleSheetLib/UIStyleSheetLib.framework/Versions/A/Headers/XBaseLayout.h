//
//  XBaseLayout.h
//  MyLayout
//
//  Created by go886 on 14-5-28.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import "IXLayout.h"

typedef enum {
    AdapterStyleIOS6 = 0,
    AdapterStyleIOS7Nav,
    AdapterStyleIOS7Status,
}AdapterStyle;

typedef enum{
    LayoutAlignmentLeft = 1<<0,     //左对齐
    LayoutAlignmentTop = 1<<1,      //上对齐
    LayoutAlignmentRight = 1<<2,    //左对齐
    LayoutAlignmentBottom = 1<<3,   //下对齐
    LayoutAlignmentCenterx = 1<<4,  //水平中间对齐
    LayoutAlignmentCentery = 1<<5,  //垂直中间对其
    LayoutAlignmentBorder = 1<<6,   //左右边框对齐，space 可拉审
    LayoutAlignmentOverflow = 1<<7  //view 可以溢出
} LayoutAlignment;

@interface XBaseLayout : NSObject<IXLayout>
@property (nonatomic,assign) CGFloat marginLeft;
@property (nonatomic,assign) CGFloat marginTop;
@property (nonatomic,assign) CGFloat marginRight;
@property (nonatomic,assign) CGFloat marginBottom;
@property (nonatomic,assign) int itemAlignment;
@property (nonatomic,assign) AdapterStyle adapterStyle;
@property (nonatomic,assign) BOOL showBackgroundColor;  //仅用于debug
@property (nonatomic,assign) BOOL animate;

-(void)setMargin:(CGFloat)margin;
-(void)setMarginWidth:(CGFloat)margin;
-(void)setMarginHeight:(CGFloat)margin;
@end