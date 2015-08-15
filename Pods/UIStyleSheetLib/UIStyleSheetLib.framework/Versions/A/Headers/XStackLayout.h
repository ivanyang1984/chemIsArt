//
//  XStackLayout.h
//  MyLayout
//
//  Created by go886 on 14-6-2.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBaseLayout.h"
@interface XStackLayout : XBaseLayout
@property(nonatomic,assign)NSUInteger curIndex;

-(void)next;
@end
