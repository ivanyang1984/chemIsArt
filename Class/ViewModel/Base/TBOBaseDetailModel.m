//
//  TBOBaseDetailModel.m
//  TBOcean
//
//  Created by go886 on 15/4/24.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOBaseDetailModel.h"
#import "CIABaseResponseModel.h"
#import "TBOBaseRequest.h"

@implementation TBOBaseDetailModel
+(instancetype)initWithModelLoader:(id<ITBOModelLoader>)loader {
    return [[self alloc] initWithModelLoader:loader];
}
-(instancetype)initWithModelLoader:(id<ITBOModelLoader>)loader {
    self = [self init];
    if (self) {
        _loader = loader;
        onSelector(_loader, self, @selector(onloaderCompleted:succeeded:));
    }
    return self;
}

-(void)onload {
    _loader ? [_loader loadForModel:self] : [super onload];
}

-(void)onloaderCompleted:(CIAResponse*)response succeeded:(BOOL)succeeded {
    if (succeeded) {
        NSAssert([response.responseJSONModel conformsToProtocol:@protocol(ITBODetailModel)], @"protocol error");
        if ([response.responseJSONModel conformsToProtocol:@protocol(ITBODetailModel)]) {
            id<ITBODetailModel> model = (id<ITBODetailModel>)response.responseJSONModel;
            [self setData:[model detailInfo]];
        }
    }
    [self setLoadFinished:succeeded];
}
@end
