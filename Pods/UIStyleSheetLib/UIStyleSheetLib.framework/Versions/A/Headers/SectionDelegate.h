//
//  TableViewDelegator.h
//  xiami
//
//  Created by go886 on 14-7-27.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol SectionDelegate<UITableViewDelegate, UITableViewDataSource>
@end


@interface UITableView (sectiondelegate)
@property(nonatomic,strong) id<SectionDelegate> sectionDelegate;
@end

@interface BaseSectionDelegate : NSObject<SectionDelegate>
-(instancetype)initWithTableView:(UITableView*)tableView;
@property(nonatomic,weak,readonly) UITableView* tableView;

-(void)update;
@end


@interface BaseProxySectionDelegate : NSProxy<SectionDelegate>
-(instancetype)initWithTarget:(id)target proxy:(id)proxy;
@property(nonatomic,weak,readonly) id target;
@property(nonatomic,strong) id proxy;
@end


@interface BaseSelectSectionDelegate : BaseProxySectionDelegate
-(instancetype)initWithTarget:(id)target delegates:(NSArray *)delegates;
@property(nonatomic,assign) NSInteger selectedIndex;
@property(nonatomic,copy,readonly) NSArray* delegates;
@end



@class BaseViewModel;
@class BaseMergeViewModel;
typedef void (^SectionDelegateCreateBlock)(NSUInteger section, BaseSectionDelegate* delegate);

@interface BaseMergeSectionDelegate : BaseSectionDelegate
@property(nonatomic,strong,readonly)BaseMergeViewModel* model;
@property(nonatomic,copy)SectionDelegateCreateBlock block;
@property(nonatomic,assign)BOOL  showHeaderWhenEmpty;

+(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(void)registerCls:(Class)cls forSection:(NSInteger)section;
-(void)unregisterForSection:(NSInteger)section;

-(void)registerCls:(Class)cls forModel:(Class)modelCls;
-(void)unregisterForModel:(Class)modelCls;
-(void)unregisterAll;
@end



@interface BaseMixSectionDelegate : BaseSectionDelegate
@property(nonatomic,strong,readonly)BaseViewModel* model;

+(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(void)registerCls:(Class)cls forModel:(Class)modelCls;
-(void)unregisterForModel:(Class)modelCls;
-(void)unregisterAll;
@end

////////////////////////

@interface XBaseSectionDelegate : BaseSectionDelegate
@property(nonatomic,strong,readonly)BaseViewModel* model;
@property(nonatomic,assign)BOOL enabledUpdate;

+(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(instancetype)initWithTableView:(UITableView*)tableView model:(BaseViewModel*)model;
-(BOOL)isLastCell:(NSIndexPath*)index;
-(BaseViewModel*)sectionModel:(NSIndexPath*)index;
-(void)viewModelStateChanged;
-(void)viewModelDataChanged;
@end







