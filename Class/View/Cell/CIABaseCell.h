//
//  TBOBaseCell.h
//  TBOcean
//
//  Created by go886 on 15/4/15.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ITBOModel.h"

typedef NS_ENUM(NSInteger, TBOCellStyle) {
    TBOCellStyleDefault = 0,    //! 默认 不显示更多
    TBOCellStyleMore,           //! 圈子等页面显示更多
    TBOCellStyleHome,           //! 首页显示圈子条 更多操作不显示
    TBOCellStyleHomeMore,       //! 首页显示更多
};

@protocol ITBOCellStyle <NSObject>
@property(nonatomic,assign) TBOCellStyle cellStyle;
@end

@interface CIABaseCell : UITableViewCell<ITBOCell, ITBOCellStyle, ITBOCellHeight>
@property(nonatomic,strong)UIView* cellSeperator;
@end


#define TBOCheckModel(modelclass, model) \
{\
        NSAssert([model isKindOfClass:[modelclass class]], @"model error"); \
        if (![model isKindOfClass:[modelclass class]]) {\
            return; \
        }\
        [super setModel:model];\
}