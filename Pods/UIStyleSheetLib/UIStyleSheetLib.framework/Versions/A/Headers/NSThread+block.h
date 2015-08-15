//
//  NSThread+block.h
//  xiami
//
//  Created by teym on 14-7-8.
//
//

#import <Foundation/Foundation.h>

@interface NSThread (block)
-(void) runBlock:(void(^)()) block;
@end
