//
//  TBOStandardModelLoader.h
//  TBOcean
//
//  Created by go886 on 15/4/24.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIStyleSheetLib/UIStyleSheetLib.h>

@protocol ITBOModelLoader <NSObject>
-(void)loadForModel:(BaseViewModel*)model;
-(BOOL)hasMore;
@end



@interface TBOStandardModelLoader : NSObject<ITBOModelLoader>

+(instancetype)initWithApiMethod:(NSString *)method
                      parameters:(NSDictionary *)param
                    forJSONModel:(Class)cls;
-(instancetype)initWithApiMethod:(NSString *)method
                      parameters:(NSDictionary *)param
                    forJSONModel:(Class)cls;

-(void)setParam:(NSString*)param forKey:(NSString*)key;
@end

extern TBOStandardModelLoader* TBOMakeStandardModelLoader(NSString* method, NSDictionary* param, Class cls);



