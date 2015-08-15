//
//  TBBLBaseRequest.m
//  TBBala
//
//  Created by go886 on 15/3/14.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOBaseRequest.h"
#import <objc/message.h>

@implementation AIFURLResponse (CIA)
static char kCIAResponseJSONModel;
-(void)setResponseJSONModel:(TBJSONModel *)responseJSONModel {
    objc_setAssociatedObject(self,
                             &kCIAResponseJSONModel,
                             responseJSONModel,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);

}
-(TBJSONModel*)responseJSONModel {
    return objc_getAssociatedObject(self, &kCIAResponseJSONModel);
}
@end

@interface TBOBaseRequest(){}

@property(nonatomic,strong) CIAResponseCompletedBlock block;
@property(nonatomic,assign) Class modelClass;
@property(nonatomic,assign) NSTimeInterval requestTime;
@property (nonatomic, strong) NSString *method;
@property (nonatomic, strong) NSMutableDictionary *param;

@end

@implementation TBOBaseRequest

+ (instancetype)initWithMethod:(NSString *)method andParam:(NSMutableDictionary *)param {
    TBOBaseRequest *r = [[TBOBaseRequest alloc] init];
    r.method = method;
    r.param = param;
    return r;
}

- (NSString *)serviceType
{
    return @"normal";
}

- (NSString *)methodName
{
    return self.method;
}

- (RTAPIManagerRequestType)requestType
{
    return RTAPIManagerRequestTypeRestGet;
}

-(void)asynRequestForModel:(Class)modelClass complete:(CIAResponseCompletedBlock)block {
    
    self.modelClass = modelClass;
    self.block = block;
    self.requestTime = [[NSDate date] timeIntervalSince1970] * 1000;
    self.validator = self;
    self.interceptor = self;
    self.paramSource = self;
    [self loadData];
}

- (void)successedOnCallingAPI:(AIFURLResponse *)response {
    _requestTime = [[NSDate date] timeIntervalSince1970]*1000 - _requestTime;
    if (_block) {
        //TODO
        static dispatch_once_t once;
        static dispatch_queue_t ioQueue;
        dispatch_once( &once, ^{
            ioQueue = dispatch_queue_create("cia_net_io", DISPATCH_QUEUE_SERIAL);
        });
        
        dispatch_async(ioQueue, ^{
            id model = nil;
            NSDictionary* json = response.content;
            if (_modelClass && [_modelClass isSubclassOfClass:[TBJSONModel class]]&& json && json.count) {
                NSDictionary* data = [json objectForKey:@"data"];
                if ([data isKindOfClass:[NSDictionary class]] && data.count) {
                    model = [_modelClass modelWithJSONDictionary:data error:nil];
                    if (model) response.responseJSONModel = model;
                }
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                if (_block) _block(response, TRUE);
            });
        });
    }
}

- (void)failedOnCallingAPI:(AIFURLResponse *)response withErrorType:(RTAPIManagerErrorType)errorType {
    if (_block) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (_block) _block(response, FALSE);
        });
    }
}

#pragma mark -
#pragma RTAPIManagerApiCallBackDelegate implementation
- (void)managerCallAPIDidSuccess:(RTAPIBaseManager *)manager {
    
}

- (void)managerCallAPIDidFailed:(RTAPIBaseManager *)manager {
    
}

#pragma RTAPIManagerValidator implementation
- (BOOL)manager:(RTAPIBaseManager *)manager isCorrectWithCallBackData:(NSDictionary *)data {
    return YES;
}

- (BOOL)manager:(RTAPIBaseManager *)manager isCorrectWithParamsData:(NSDictionary *)data {
    return YES;
}


#pragma RTAPIManagerParamSourceDelegate implementation
- (NSDictionary *)paramsForApi:(RTAPIBaseManager *)manager {
    return self.param;
}


#pragma RTAPIManagerInterceptor implementation
- (void)manager:(RTAPIBaseManager *)manager beforePerformSuccessWithResponse:(AIFURLResponse *)response {
    
}

- (void)manager:(RTAPIBaseManager *)manager afterPerformSuccessWithResponse:(AIFURLResponse *)response {
    
}

- (void)manager:(RTAPIBaseManager *)manager beforePerformFailWithResponse:(AIFURLResponse *)response {
    
}

- (void)manager:(RTAPIBaseManager *)manager afterPerformFailWithResponse:(AIFURLResponse *)response {
    
}

- (BOOL)manager:(RTAPIBaseManager *)manager shouldCallAPIWithParams:(NSDictionary *)params {
    return NO;
}

- (void)manager:(RTAPIBaseManager *)manager afterCallingAPIWithParams:(NSDictionary *)params {
}
@end
