//
//  BaseListViewModel.h
//  xiami
//
//  Created by go886 on 14-7-15.
//
//

#import <Foundation/Foundation.h>
#import "BaseViewModel.h"

@interface BaseListViewModel : BaseViewModel
+(instancetype)initWithData:(NSArray *)array;
-(instancetype)initWithData:(NSArray *)array;

-(NSArray*)innerItems;        //内部数据 copy
-(void)reset:(NSArray*)data; //替换数据;

-(void)addItems:(NSArray*)items;
-(void)removeItems:(NSArray*)items;
-(void)moveItem:(NSArray*)items toIndex:(NSInteger)idx;
-(BOOL)replaceItem:(id)item withItem:(id)newItem;

-(void)onloadFinished:(NSArray*)data nextpage:(NSInteger)nextpage;
@end
