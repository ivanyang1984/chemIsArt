//
//  TBBLBaseRequest.h
//  TBBala
//
//  Created by go886 on 15/3/14.
//  Copyright (c) 2015年 taobao. All rights reserved.
//


#import "RTAPIBaseManager.h"
#import "AIFURLResponse.h"
#import "NSDictionary+TBJSONModel.h"

@interface AIFURLResponse(CIA)
@property (nonatomic, strong) TBJSONModel *responseJSONModel;
@end

typedef AIFURLResponse  CIAResponse;
typedef void (^CIAResponseCompletedBlock)(CIAResponse *response, BOOL succeed);

@interface TBOBaseRequest : RTAPIBaseManager <RTAPIManager, RTAPIManagerApiCallBackDelegate, RTAPIManagerValidator, RTAPIManagerParamSourceDelegate, RTAPIManagerInterceptor>

+ (instancetype)initWithMethod:(NSString *)method andParam:(NSMutableDictionary *)param;

-(void)asynRequestForModel:(Class)modelClass complete:(CIAResponseCompletedBlock)block;
@end