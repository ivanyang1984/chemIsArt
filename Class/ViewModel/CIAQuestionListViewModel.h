//
//  CIAQuestionListViewModel.h
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "TBOBaseListViewModel.h"
#import "CIAQuestionModel.h"

@interface CIAQuestionListViewModel : TBOBaseListViewModel

@property (nonatomic, strong) NSMutableArray<CIAQuestionModel> *questions;

+ (instancetype) initWithUserId;

@end
