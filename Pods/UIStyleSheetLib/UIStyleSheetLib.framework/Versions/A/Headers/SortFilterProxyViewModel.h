//
//  SortFilterProxyViewModel.h
//  xiami
//
//  Created by go886 on 14-7-15.
//
//

#import <Foundation/Foundation.h>
#import "BaseProxyViewModel.h"

typedef char  (^firstCharFun)(NSString* src);
typedef NSString* (^pinyinHelperFun)(NSString* src, NSMutableString* shortedpinyin);
typedef NSComparisonResult (^sorter)(id v1, id v2, NSString* key);
typedef NSUInteger (^filterfun)(id value, NSString* key);
typedef id (^groupsplit)(id value, NSString* key);

@interface SortFilterProxyViewModel : BaseProxyViewModel
+(void)installPinYinHelper:(firstCharFun)firstCharFun helper:(pinyinHelperFun)helper;

@property(nonatomic,assign) BOOL orderedDescending;
@property(nonatomic,copy) NSArray* sortedKeys;
@property(nonatomic,copy) sorter sorter;
@property(nonatomic,strong,readonly) NSArray* indexTitles;
@property(nonatomic,copy) NSString* keyForIndexTitles;

@property(nonatomic,assign) BOOL enableFilterIndexOrdered;
@property(nonatomic,assign) BOOL enableConverPinYinFilter;
@property(nonatomic,assign) BOOL enableRegExpFileter;
@property(nonatomic,copy) NSArray* filterKeys;
@property(nonatomic,copy) NSString* patterns;
@property(nonatomic,copy) filterfun filter;

@property(nonatomic,assign)BOOL enableGroupOrdered;
@property(nonatomic,assign)BOOL groupOrderedDescending;
@property(nonatomic,copy) NSArray* groupKeys;
@property(nonatomic,copy) NSString* groupPatterns;
@property(nonatomic,copy) groupsplit split;

@property(nonatomic,assign) BOOL lazyDataChanged;
@property(nonatomic,assign,readonly) BOOL hasDataChanged;
-(NSIndexPath*)maptoSource:(NSIndexPath*)index;
-(NSArray*)groups;
-(id)keyForSection:(NSInteger)section;
-(void)setKeyForSection:(NSInteger)section key:(id)key;

-(void)apply;
@end