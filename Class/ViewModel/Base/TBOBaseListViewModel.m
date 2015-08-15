 //
//  TBOBaseListViewModel.m
//  TBOcean
//
//  Created by go886 on 15/4/10.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOBaseListViewModel.h"
#import "CIABaseResponseModel.h"
#import "TBOBaseRequest.h"


@implementation TBOBaseListViewModel
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
-(BOOL)hasMore {
    return _loader ? [_loader hasMore] : [super hasMore];
}

-(void)onload {
    _loader ? [_loader loadForModel:self] : [super onload];
}

-(void)onloaderCompleted:(CIAResponse*)response succeeded:(BOOL)succeeded {
    if (succeeded) {
        NSAssert([response.responseJSONModel conformsToProtocol:@protocol(ITBOListModel)], @"protocol error");
        if ([response.responseJSONModel conformsToProtocol:@protocol(ITBOListModel)]) {
            id<ITBOListModel> model = (id<ITBOListModel>)response.responseJSONModel;
            [self onloadFinished:[model items] nextpage:([model page] + 1)];
            return;
        }
    }
    [self setLoadFinished:succeeded];
}
@end

