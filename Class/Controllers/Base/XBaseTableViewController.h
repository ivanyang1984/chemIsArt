//
//  BaseTableViewController.h
//  BaseViewModel
//
//  Created by go886 on 14-10-13.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XBaseViewController.h"
@interface XBaseTableViewController : XBaseViewController<UITableViewDelegate,UITableViewDataSource>
- (instancetype)initWithStyle:(UITableViewStyle)style;

@property(nonatomic,weak)IBOutlet UITableView *tableView;
@end
