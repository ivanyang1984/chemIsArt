//
//  XLayoutSampleFactory.h
//  MyLayout
//
//  Created by go886 on 14-6-1.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>
@interface XLayoutSampleFactory : NSObject
+(id)createControl;
+(id)createControl:(NSString *)title;

+(UIColor*)randomLightingColor;
+(UIColor*)randomLightingColor:(CGFloat)alpha;
@end
