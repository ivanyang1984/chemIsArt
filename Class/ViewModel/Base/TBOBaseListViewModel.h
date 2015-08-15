//
//  TBOBaseListViewModel.h
//  TBOcean
//
//  Created by go886 on 15/4/10.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIStyleSheetLib/UIStyleSheetLib.h>
#import "TBOStandardModelLoader.h"
#import "TBOBaseRequest.h"
@interface TBOBaseListViewModel : BaseListViewModel
@property(nonatomic,strong,readonly)id<ITBOModelLoader> loader;
+(instancetype)initWithModelLoader:(id<ITBOModelLoader>)loader;
-(instancetype)initWithModelLoader:(id<ITBOModelLoader>)loader;

-(void)onloaderCompleted:(CIAResponse*)response succeeded:(BOOL)succeeded;
@end
