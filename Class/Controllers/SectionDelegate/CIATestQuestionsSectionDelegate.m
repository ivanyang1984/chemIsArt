//
//  CIATestQuestionsSectionDelegate.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIATestQuestionsSectionDelegate.h"
#import "CIAQuestionCell.h"

@implementation CIATestQuestionsSectionDelegate

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
//    BaseViewModel* m = [self sectionModel:makeIndexPath(section, 0)];
//    if (m.isEmpty && (MS_FINISHED == m.state || MS_FAILED == m.state)) {
//        return 1;
//    }
    return [self.model itemCount:section];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
//    id model  = [self.model data:indexPath];
    return 90;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    BOOL isNew;
    id model = [self.model data:indexPath];
    Class cls = [CIAQuestionCell class];
    CIABaseCell *cell = (CIAQuestionCell *)[tableView cellForClass:cls isNew:&isNew];
    cell.indexPath = indexPath;
    cell.model = model;
    return cell;
}

@end
