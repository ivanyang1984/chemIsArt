//
//  SelectProxyViewModel.h
//  xiami
//
//  Created by go886 on 14-7-15.
//
//

#import <Foundation/Foundation.h>
#import "BaseProxyViewModel.h"
@interface SelectProxyViewModel : BaseProxyViewModel
@property(nonatomic,assign) NSInteger selectedIndex;
@property(nonatomic,copy) NSArray* models;
@property(nonatomic,assign)BOOL enabledAllModelChanged;
@property(nonatomic,assign)BOOL enabledAllRefresh;


+(instancetype)initWithViewModels:(NSArray*)models;
-(instancetype)initWithViewModels:(NSArray*)models;
@end
