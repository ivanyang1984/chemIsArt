//
//  TBJSONModelError.m
//  TBJSONModel
//
//  Created by Luke on 12/1/13.
//  Copyright (c) 2013 taobao. All rights reserved.
//

#import "TBJSONModelError.h"

NSString * const TBJSONModelErrorDomain = @"TBJSONModelErrorDomain";

@implementation TBJSONModelError
+ (TBJSONModelError *)errorNilInput{
    return [TBJSONModelError errorWithDomain:TBJSONModelErrorDomain code:TBJSONModelErrorCodeNilInput userInfo:@{NSLocalizedDescriptionKey: @"用于创建TBJSONModel的参数为nil"}];
}

+ (TBJSONModelError *)errorDataInvalidWithDescription:(NSString *)description{
    return [TBJSONModelError errorWithDomain:TBJSONModelErrorDomain code:TBJSONModelErrorCodeDataInvalid userInfo:@{NSLocalizedDescriptionKey: description}];
}
@end
