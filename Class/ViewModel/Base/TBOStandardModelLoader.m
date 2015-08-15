//
//  TBOStandardModelLoader.m
//  TBOcean
//
//  Created by go886 on 15/4/24.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOStandardModelLoader.h"
#import "TBOBaseRequest.h"
#import "CIABaseResponseModel.h"

@implementation TBOStandardModelLoader {
    NSString* _cursor;
    BOOL _hasMore;
    NSString* _method;
    NSMutableDictionary* _params;
    Class _responseCls;
}

+(id<ICache>)currentCache {
    return [defaultCache() getSubCache:str(@"%@", @"admin") withFormater:nil];
}

+(NSString*)keyForMethod:(NSString*)method query:(NSDictionary*)query {
    NSMutableString* urlstring = [NSMutableString stringWithFormat:@"%@|", method];
    for (NSString* k in query) {
        [urlstring appendFormat:@"%@=%@|", k, query[k]];
    }
    return [urlstring MD5Hash];
}

+(NSDictionary*)cacheFromMethod:(NSString*)method query:(NSDictionary*)query {
    id data = [[self currentCache] objectForKey:[self keyForMethod:method query:query]];
    if ([data isKindOfClass:[NSData class]]) {
        NSError *error = nil;
        id  obj = [NSJSONSerialization JSONObjectWithData:(NSData*)data
                                                  options:NSJSONReadingMutableContainers | NSJSONReadingMutableLeaves | NSJSONReadingAllowFragments
                                                    error:&error];
        
        if ([obj isKindOfClass:[NSDictionary class]]) {
            NSDictionary* model = [obj objectForKey:@"data"];
            if ([model isKindOfClass:NSDictionary.class]) {
                return model;
            }
        }
    }
    return nil;
}

+(void)saveCacheFromMethod:(NSString*)method query:(NSDictionary*)query data:(id)data {
    [[self currentCache] saveObjectToDisk:data forKey:[self keyForMethod:method query:query]];
}

+(instancetype)initWithApiMethod:(NSString *)method parameters:(NSDictionary *)param forJSONModel:(Class)cls {
    return [[self alloc] initWithApiMethod:method parameters:param forJSONModel:cls];
}
-(instancetype)initWithApiMethod:(NSString *)method parameters:(NSDictionary *)param forJSONModel:(Class)cls {
    self = [self init];
    if (self) {
        _method = method;
        _params = [NSMutableDictionary dictionaryWithDictionary:param];
        _responseCls = cls;
    }
    return self;
}

-(BOOL)hasMore {
    return _hasMore;
}
-(void)setParam:(NSString*)param forKey:(NSString*)key {
    [_params setObject:param forKey:key];
}
-(void)loadForModel:(BaseViewModel *)model {
    NSDictionary* params = _params;
    if (_cursor && !model.isRefreshing) {
        NSMutableDictionary* queryparams = [NSMutableDictionary dictionaryWithDictionary:_params];
        [queryparams setObject:_cursor forKey:@"cursor"];
        params = queryparams;
    }else if(model.page > 1 && !model.isRefreshing) {
        NSMutableDictionary* queryparams = [NSMutableDictionary dictionaryWithDictionary:_params];
        [queryparams setObject:@(model.page) forKey:@"page"];
        params = queryparams;
    }
    
    WS(self);
    TBOBaseRequest* r = [TBOBaseRequest initWithMethod:_method andParam:_params];
    [r asynRequestForModel:_responseCls complete:^(CIAResponse *response, BOOL succeeded) {
        if (succeeded && response.responseJSONModel) { //保存到cache中
            [TBOStandardModelLoader saveCacheFromMethod:_method query:params data:response.responseData];
        }
        if (!succeeded && !model.isRefreshing) { //从cache 加载
            NSDictionary* model = [TBOStandardModelLoader cacheFromMethod:_method query:params];
            if (model) {
                response.responseJSONModel = [[_responseCls alloc] initWithJSONDictionary:model error:nil];
                succeeded = YES;
            }
        }
        
        if ([response.responseJSONModel conformsToProtocol:@protocol(ITBOListModel)]) {
            id<ITBOListModel> listmodel = (id<ITBOListModel>)response.responseJSONModel;
            _cursor = [listmodel cursor];
            _hasMore = [listmodel hasMore]&&(listmodel.items.count);
        }
        sendToSelector(w_self, @selector(onloaderCompleted:succeeded:), response, succeeded);
    }];
}
@end

TBOStandardModelLoader* TBOMakeStandardModelLoader(NSString* method, NSDictionary* param, Class cls) {
    return [TBOStandardModelLoader initWithApiMethod:method parameters:param forJSONModel:cls];
}
