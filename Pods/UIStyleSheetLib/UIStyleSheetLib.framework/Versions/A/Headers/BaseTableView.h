//
//  BaseTableView.h
//  xiami
//
//  Created by go886 on 14-7-11.
//
//

#import <UIKit/UIKit.h>
@interface UITableView (viewmodel)
-(id)cellForClass:(Class)cls;
-(id)cellForClass:(Class)cls isNew:(BOOL*)isNew;
-(id)cellForClass:(Class)cls style:(UITableViewCellStyle)style;
-(id)cellForClass:(Class)cls style:(UITableViewCellStyle)style isNew:(BOOL*)isNew;
-(id)cellForClass:(Class)cls style:(UITableViewCellStyle)style kIdentifier:(NSString*)identifier;
-(id)cellForClass:(Class)cls style:(UITableViewCellStyle)style kIdentifier:(NSString*)identifier isNew:(BOOL*)isNew;
-(id)cellForNibNamed:(NSString*)name kIdentifier:(NSString*)identifier;
@end


@class BaseViewModel;
@interface BaseTableView : UITableView
@property(nonatomic,strong)BaseViewModel* viewModel;
-(void)viewModelStateChanged;
-(void)viewModelDataChanged;
@end


