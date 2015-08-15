//
//  TBOBaseSectionDelegate.h
//  TBOcean
//
//  Created by go886 on 15/4/10.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

@interface CIABaseSectionDelegate : XBaseSectionDelegate

-(Class)cellClassForModel:(id)model;
-(UITableViewCell<ITBOCell,ITBOCellHeight> *)tableView:(UITableView *)tableView
                                 cellForRowAtIndexPath:(NSIndexPath *)indexPath
                                       estimatedHeight:(BOOL)estimatedHeight
                                                 isNew:(BOOL*)isNew;
-(UITableViewCell<ITBOCell,ITBOCellHeight> *)tableView:(UITableView *)tableView
                                 cellForRowAtIndexPath:(NSIndexPath *)indexPath
                                                 isNew:(BOOL*)isNew;

-(void)configCell:(UITableViewCell<ITBOCell,ITBOCellHeight> *)cell
        indexPath:(NSIndexPath*)indexPath
            model:(id)model
  estimatedHeight:(BOOL)estimatedHeight
            isNew:(BOOL)isNew;
@end
