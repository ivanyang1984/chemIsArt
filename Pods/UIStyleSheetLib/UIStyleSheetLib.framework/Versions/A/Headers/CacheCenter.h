//
//  CacheCenter.h
//  XUtility
//
//  Created by go886 on 15/4/25.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
//typedef enum _ICachePolicy {
//
//} ICachePolicy;



@protocol ICacheFormater <NSObject>
-(void)saveObject:(id)obj toPath:(NSString*)path forKey:(NSString*)key;
-(id)objectFromPath:(NSString*)path forKey:(NSString*)key;
-(void)removeFromPath:(NSString*)path forKey:(NSString*)key;
@end

@protocol ICache <NSObject>
-(NSUInteger)cacheSize;
-(NSString*)name;

-(void)saveObject:(id)obj forKey:(id)key;
-(void)saveObjectToDisk:(id)obj forKey:(id)key;
-(void)saveObjectToMemory:(id)obj forKey:(id)key;

-(id)memoryObjectForKey:(id)key;
-(void)objectForKey:(id)key inDisk:(void(^)(id obj))block;
-(id)objectForKey:(id)key;

-(void)removeForKey:(NSString*)key;
-(void)clear;

-(id<ICache>)getSubCache:(NSString*)name withFormater:(id<ICacheFormater>)formater;
@end


extern id<ICache> defaultCache();
