//
//  BaseViewModelConfig.h
//  BaseViewModelLib
//
//  Created by go886 on 15/1/17.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaseViewModelConfig : NSObject
@property(nonatomic,assign)NSInteger initPageIndex;
@property(nonatomic,assign)NSUInteger minLoadPageNum;
@property(nonatomic,assign)NSUInteger reserveItemNum;
@property(nonatomic,assign)BOOL disabledDataChenged;

+(instancetype)instance;
@end
