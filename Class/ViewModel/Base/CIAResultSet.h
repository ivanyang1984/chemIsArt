//
//  CIAResultSet.h
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "TBJSONModel.h"
#import "CIAQuestionModel.h"

@interface CIAResultSet : TBJSONModel

@property (nonatomic, strong) NSMutableArray<CIAQuestionModel> *questions;

@end
