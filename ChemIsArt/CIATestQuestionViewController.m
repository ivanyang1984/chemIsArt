//
//  ViewController.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/11.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIATestQuestionViewController.h"
#import "CIAResultSet.h"
#import "CIAQuestionListViewModel.h"
#import "CIATestQuestionsSectionDelegate.h"

@interface CIATestQuestionViewController ()


@end

@implementation CIATestQuestionViewController

- (instancetype)initNaviParams:(NSDictionary *)params 
{
    self = [super init];
    if (self) {
        CIAQuestionListViewModel *questionsViewModel = [CIAQuestionListViewModel initwithQueryParams:params];
        self.viewModel = questionsViewModel;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.sectionDelegate = [CIATestQuestionsSectionDelegate initWithTableView:self.tableView model:self.viewModel];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
