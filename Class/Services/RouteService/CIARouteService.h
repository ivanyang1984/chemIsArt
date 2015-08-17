//
//  CIARouteService.h
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/17.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CIARouteService : NSObject

+(instancetype)instance;

//! 初始化导航配置
+ (void)setUpRoutersConfig;

//! 根据URL 打开页面
+ (void)openWithURL:(NSString *)url;

@end
