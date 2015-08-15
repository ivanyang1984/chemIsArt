//
//  IXLayout.h
//  XLayout
//
//  Created by go886 on 15/5/22.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol IXLayout <NSObject>
-(void)layout:(UIView*)view;
@end