//
//  CIAQuestionListViewModel.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIAQuestionListViewModel.h"
#import "CIAResultSet.h"

@implementation CIAQuestionListViewModel

+ (instancetype) initWithUserId {
    TBOStandardModelLoader* loader = TBOMakeStandardModelLoader(@"questions/1", nil, [CIAResultSet class]);
    return [self initWithModelLoader:loader];
}

@end
