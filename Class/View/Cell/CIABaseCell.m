//
//  TBOBaseCell.m
//  TBOcean
//
//  Created by go886 on 15/4/15.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "CIABaseCell.h"
#import "TBOCellSeperator.h"

@implementation CIABaseCell
@synthesize model = _model;
@synthesize indexPath = _indexPath;
@synthesize cellStyle = _cellStyle;

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.contentView.backgroundColor = [UIColor whiteColor];
        self.clipsToBounds = YES;
        
        if (!self.cellSeperator) self.cellSeperator = [TBOCellSeperator defaultCellSeperator];
        [self addSubview:self.cellSeperator];
    }
    return self;
}
-(void)layoutSubviews {
    [super layoutSubviews];
    self.cellSeperator.bottom = self.bounds.size.height;
}

-(CGFloat)heightForCell {
    return [_model respondsToSelector:@selector(heightForCell)] ? [(id<ITBOCellHeight>)_model heightForCell] : 0;
}
@end
