//
//  BaseViewModel.h
//  xiami
//
//  Created by go886 on 14-6-19.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum{
    MS_INIT = 0,
    MS_LOADING,
    MS_FINISHED,
    MS_FAILED
}MODESTATE;

extern NSString* const kStateKey;
extern NSString* const kDataKey;
@protocol ViewModelDelegate <NSObject>
@property(nonatomic,assign) MODESTATE state;
@property(nonatomic,strong) NSError* error;
@property(nonatomic,assign) NSUInteger minLoadPageNum;
@property(nonatomic,assign) NSUInteger reserveItemNum;
@property(nonatomic,assign) BOOL disabledDataChenged;
-(BOOL)hasMore;
-(BOOL)needLoad;
-(BOOL)isLoading;
-(BOOL)isRefreshing;
-(BOOL)isEmpty;
-(NSInteger)size;
-(NSInteger)page;
-(void)load;
-(void)refresh;
-(void)cancelLoad;
-(void)reload;
-(void)reset;
-(void)beginDataChanged;
-(void)endDataChanged;
-(void)emitDataChanged;

-(void)each:(void(^)(NSIndexPath* index, BOOL* stop))block;
-(void)echoForKey:(NSString*)key;

-(void)preloadForView:(UIView*)v;

-(NSInteger)sectionCount;
-(NSInteger)itemCount:(NSInteger)section;
-(id)data:(NSIndexPath* const)indexPath;
-(id)data:(NSIndexPath* const)indexPath key:(NSString*)key;
-(void)setData:(NSIndexPath* const)indexPath key:(NSString*)key value:(id)value;
-(void)insert:(NSIndexPath* const)indexPath data:(NSArray*)data;
-(void)remove:(NSIndexPath* const)indexPath count:(NSInteger)count;
-(void)remove:(NSArray *)indexPathArray;

-(void)bind:(id)obj indexPath:(NSIndexPath*)indexPath keys:(NSArray*)keys;
-(void)bind:(id)obj indexPath:(NSIndexPath*)indexPath keys:(NSArray*)keys keysMap:(NSDictionary*)keysmap;
@end


@interface BaseViewModel : NSObject<ViewModelDelegate>
-(void)setLoadFinished:(BOOL)succeed;
-(void)setLoadFinished:(BOOL)succeed nextPage:(NSInteger)nextPage;
-(void)onload;
-(void)oncanelLoad;
-(void)onclear;
-(void)ondataChanged;
@end


extern NSIndexPath * makeIndexPath(NSUInteger section,NSUInteger row);
