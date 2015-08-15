//
//  XGridLayout.h
//  MyLayout
//
//  Created by go886 on 14-5-30.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBaseLayout.h"
@interface XGridLayout : XBaseLayout
@property(nonatomic,assign)NSUInteger numColumns;
@property(nonatomic,assign)BOOL fill;
@property(nonatomic,assign)BOOL horizontal;
@property(nonatomic,assign)CGFloat horizontalSpace;
@property(nonatomic,assign)CGFloat verticalSpace;
@property(nonatomic,assign)CGFloat minRowHeight;
@property(nonatomic,assign)CGFloat maxRowHeight;
@property(nonatomic,strong)UIColor* paddingColor;

-(void)setSpace:(CGFloat)space;
@end
