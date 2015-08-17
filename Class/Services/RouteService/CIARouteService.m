//
//  CIARouteService.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/17.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIARouteService.h"
#import "ViewController.h"
#import "CIATestQuestionViewController.h"

@implementation CIARouteService

DEF_SINGLETON

+ (void)setUpRoutersConfig {
    CIARouteService *routeService = [CIARouteService instance];
    NSDictionary *configs = [routeService localConfigWithName:@"routerConfig" ofType:@"plist"];
    [configs enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [MGJRouter registerURLPattern:key toHandler:^(NSDictionary *routerParameters) {
            Class cls = NSClassFromString(str(@"%@",obj));
            CIATestQuestionViewController *clsInstance = [[cls alloc] initNaviParams:routerParameters];
            [((UINavigationController *)[[UIApplication sharedApplication] keyWindow].rootViewController) pushViewController:clsInstance animated:YES];
        }];
    }];
}

+ (void)openWithURL:(NSString *)url {
    [MGJRouter openURL:url];
}

#pragma mark - own
- (NSDictionary *)localConfigWithName:(NSString *)fileName ofType:(NSString *)type {
    NSString *configPath      = [[NSBundle mainBundle] pathForResource:fileName ofType:type];
    NSDictionary  *localConfigDic = [NSDictionary dictionaryWithContentsOfFile:configPath];
    if (localConfigDic && [localConfigDic count] > 0) {
        return localConfigDic;
    }
    return nil;
}

@end
