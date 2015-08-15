//
//  SkinMgr.h
//  test_CSS
//
//  Created by go886 on 14-9-21.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UISkinMgr : NSObject
@property(nonatomic,assign)BOOL enabledLogger;
@property(nonatomic,assign)BOOL enabledAutoUpdate;
@property(nonatomic,strong)NSString* skinName;
@property(nonatomic,strong,readonly)NSString* skinDir;
@property(nonatomic,assign)float uiscale;

+(instancetype)instance;
-(void)reload;
@end

