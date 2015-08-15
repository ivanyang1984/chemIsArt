//
//  NSDictionary+utility.h
//  XUtility
//
//  Created by go886 on 15/4/22.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (utility)
-(instancetype)replaceForKeysMap:(NSDictionary*)keysMap;

-(id)objectForAnyKey:(NSArray*)keys;
-(id)objectForAnyKey:(NSArray*)keys notFoundMarker:(id)marker;

-(NSString*)toQueryURLString;
@end