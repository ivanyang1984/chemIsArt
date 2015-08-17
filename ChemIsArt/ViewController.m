//
//  ViewController.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/17.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "ViewController.h"
#import "CIATestQuestionViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    CIATestQuestionViewController *testVc = [[CIATestQuestionViewController alloc] init];
//    UINavigationBar *bar = [[UINavigationBar alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 56)];
//    self.navigationController
    self.title = @"Test";
    self.view.backgroundColor = [UIColor whiteColor];
//    [self.navigationController pushViewController:testVc animated:YES];
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(100, 100, 50, 25);
    [btn setTitle:@"test" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(testOpen) forControlEvents:UIControlEventTouchUpInside];
    [btn setBackgroundColor:[UIColor redColor]];
    [self.view addSubview:btn];
    
}

- (void)testOpen {
    [CIARouteService openWithURL:@"cia://test/questions?userId=1"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
