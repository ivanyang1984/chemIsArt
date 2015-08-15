//
//  NSNotificationCenter+utility.h
//  TBBala
//
//  Created by go886 on 15/3/13.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNotificationCenter (utility)
- (void)addOnceObserverForName:(NSString *)name
                        object:(id)obj
                         queue:(NSOperationQueue *)queue
                    usingBlock:(void (^)(NSNotification *note))block;

- (void)addWeakObserverForName:(NSString *)name
                       weakObserver:(id)observer
                        object:(id)obj
                         queue:(NSOperationQueue *)queue
                    usingBlock:(void (^)(NSNotification *note, BOOL* stop))block;
@end
