//
//  CIAQuestionModel.h
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "TBJSONModel.h"

@protocol CIAQuestionModel <NSObject>

@end
@interface CIAQuestionModel : TBJSONModel

@property (nonatomic, strong) NSString *questionId;

@property (nonatomic, strong) NSString *authorId;

@property (nonatomic, strong) NSString *questionTitle;

@property (nonatomic, strong) NSString *content;

@property (nonatomic, strong) NSString *state;

@property (nonatomic, strong) NSString *categoryId;

@property (nonatomic, assign) NSInteger numOfExposures;

@property (nonatomic, assign) NSInteger numOfComments;

@property (nonatomic, assign) NSInteger numOfAnswers;

@end
