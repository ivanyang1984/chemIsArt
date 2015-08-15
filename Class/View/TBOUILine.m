//
//  TBOUILine.m
//  TBOcean
//
//  Created by go886 on 15/4/20.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOUILine.h"

@implementation TBOUILine
+(instancetype)defaultLine {
    TBOUILine* line = [[self alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 0.5)];
    line.backgroundColor = [UIColor grayColor];
    return line;
}
@end
