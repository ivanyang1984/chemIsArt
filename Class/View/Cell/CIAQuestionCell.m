//
//  CIAQuestionCell.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIAQuestionCell.h"
#import "CIAQuestionModel.h"

@implementation CIAQuestionCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.label = [[UILabel alloc] init];
        self.label.textColor = [UIColor redColor];
        self.label.font = CIAFont(NO, 14);
        self.label.textAlignment = NSTextAlignmentCenter;
        self.label.numberOfLines = 1;
        [self.contentView addSubview:self.label];
        
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self.label sizeToFit];
}

- (void)setModel:(id)model {
    TBOCheckModel(CIAQuestionModel, model);
    self.label.text = ((CIAQuestionModel *)model).content;
}

@end
