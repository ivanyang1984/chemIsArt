//
//  NSDictionary+TBJSONModel.m
//  TBModelFactory
//
//  Created by Luke on 8/16/13.
//  Copyright (c) 2013 taobao. All rights reserved.
//

#import "NSDictionary+TBJSONModel.h"
#import "NSArray+TBJSONModel.h"

@implementation NSDictionary(TBJSONModel)

- (NSDictionary *)modelDictionaryWithClass:(Class)modelClass{
    NSMutableDictionary *modelDictionary = [NSMutableDictionary dictionary];
    for (NSString *key in self) {
        id object = [self objectForKey:key];
        if ([object isKindOfClass:[NSDictionary class]]) {
            [modelDictionary setObject:[[modelClass alloc] initWithJSONDictionary:object] forKey:key];
        }else if ([object isKindOfClass:[NSArray class]]){
            [modelDictionary setObject:[object modelArrayWithClass:modelClass] forKey:key];
        }else{
            [modelDictionary setObject:object forKey:key];
        }
    }
    return modelDictionary;
}

- (NSDictionary *)toJSONDictionary{
    NSMutableDictionary *jsonDictionary = [NSMutableDictionary dictionary];
    for (NSString *key in self) {
        id object = [self objectForKey:key];
        if ([object isKindOfClass:[TBJSONModel class]]) {
            [jsonDictionary setObject:[(TBJSONModel *)object toJSONDictionary] forKey:key];
        }else if ([object isKindOfClass:[NSArray class]]){
            [jsonDictionary setObject:[(NSArray *)object toJSONArray] forKey:key];
        }else{
            [jsonDictionary setObject:object forKey:key];
        }
    }
    return jsonDictionary;
}

@end
