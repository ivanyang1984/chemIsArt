//
//  NSObject+observer.h
//  TBBala
//
//  Created by go886 on 15/3/16.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void (^ObserverBlock)(id obj, NSDictionary* change, void* context);

@interface NSObject (observer)
-(void)addObserver:(NSObject *)observer
        forKeyPath:(NSString *)keyPath
           options:(NSKeyValueObservingOptions)options
           context:(void *)context
             block:(ObserverBlock)block;

-(void)addObserver:(NSObject *)observer
        forKeyPath:(NSString *)keyPath
           options:(NSKeyValueObservingOptions)options
           context:(void *)context
          selector:(SEL)sel;

-(void)delObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(void *)context;
@end
