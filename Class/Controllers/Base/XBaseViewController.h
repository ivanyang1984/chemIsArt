//
//  BaseViewController.h
//  xiami
//
//  Created by go886 on 14-6-19.
//
//

#import <UIKit/UIKit.h>
@class BaseViewModel;
@interface XBaseViewController : UIViewController
@property(nonatomic,strong) BaseViewModel* viewModel;
@property(nonatomic,assign,readonly)NSUInteger viewDidLoadNum;
@property(nonatomic,assign,readonly)BOOL isFirstViewDidLoad;

-(void)viewModelStateChanged;
-(void)viewModelDataChanged;
@end
