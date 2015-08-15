//
//  TBOCellSeperator.m
//  TBOcean
//
//  Created by go886 on 15/4/20.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOCellSeperator.h"
#import "TBOUILine.h"

@implementation TBOCellSeperator
+(instancetype)defaultCellSeperator {
    TBOCellSeperator* sep = [[self alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, px([self defaultHeight]))];
    if (sep) {
        sep.backgroundColor = RGB(238, 238, 238);
        TBOUILine* line = [TBOUILine defaultLine];
        line.backgroundColor =   ColorWithHex(0xd9d9d9FF);
        line.layer.shadowColor = ColorWithHex(0xe7e7e7FF).CGColor;
        line.layer.shadowOffset = CGSizeMake(0,0);
        
        [sep addSubview:line];
        
        [sep.sizePolicy setFixedHeight:sep.height];
        [sep.sizePolicy setWidthExpand:YES];
    }
    
    return sep;
}
+(CGFloat)defaultHeight {
    return 9;
}
@end
