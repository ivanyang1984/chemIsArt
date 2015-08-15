//
//  BaseTableViewController.m
//  BaseViewModel
//
//  Created by go886 on 14-10-13.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import "XBaseTableViewController.h"
#import "BaseTableView.h"
#import "BaseViewModel.h"

@interface XBaseTableViewController ()
@end

@implementation XBaseTableViewController {
    UITableViewStyle _tableStyle;
}
- (instancetype)initWithStyle:(UITableViewStyle)style {
    self = [super init];
    if (self) {
        _tableStyle = style;
    }
    
    return self;
}

-(void)dealloc {
    _tableView.delegate = nil;
    _tableView.dataSource = nil;
    _tableView.sectionDelegate = nil;
    _tableView = nil;
}

-(void)setTableView:(UITableView *)tableView {
    if (_tableView != tableView) {
        [_tableView removeFromSuperview];
        _tableView = tableView;
        [self.view addSubview:tableView];
    }
}

-(void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UITableView* table = [[UITableView alloc] initWithFrame:self.view.bounds style:_tableStyle];
    table.frame = self.view.bounds;
    table.delegate = self;
    table.dataSource = self;
    table.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    table.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.tableView = table;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
-(void)viewModelDataChanged {
//    UITableView* tableview = self.tableView;
//    if (tableview) {
//        [tableview reloadData];
//        [tableview reloadRowsAtIndexPaths:[tableview indexPathsForVisibleRows] withRowAnimation:UITableViewRowAnimationAutomatic];
//        
////        [UIView transitionWithView:tableview
////                          duration:.3f
////                           options:UIViewAnimationOptionTransitionCrossDissolve
////                        animations:^{
////                            
////                        } completion:^(BOOL finished) {
////                            
////                        }];
//    }
}

#pragma UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return [self.viewModel sectionCount];
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.viewModel itemCount:section];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    return [tableView cellForClass:[tableView class]];
}

@end
