//
//  TBOBaseSectionDelegate.m
//  TBOcean
//
//  Created by go886 on 15/4/10.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "CIABaseSectionDelegate.h"
#import <objc/message.h>

@implementation CIABaseSectionDelegate

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
//    id model = [self.model data:indexPath];
//    if (!model) {
//        
//    }else {
//        //NSAssert(false, @"model error");
//    }
}


-(Class)cellClassForModel:(id)model {
    NSAssert(FALSE, @"cellClassForModel no imp");
    return nil;
}

-(UITableViewCell<ITBOCell,ITBOCellHeight> *)tableView:(UITableView *)tableView
                                 cellForRowAtIndexPath:(NSIndexPath *)indexPath
                                       estimatedHeight:(BOOL)estimatedHeight
                                                 isNew:(BOOL*)isNew {
    id model = [self.model data:indexPath];
    Class cls = [self cellClassForModel:model];
    NSAssert([cls conformsToProtocol:@protocol(ITBOCell)], @"ITBOCell error");
    NSAssert([cls conformsToProtocol:@protocol(ITBOCellHeight)], @"ITBOCellHeight error");
    
    UITableViewCell<ITBOCell,ITBOCellHeight>* cell = nil;
    NSMutableDictionary* heightCache = objc_getAssociatedObject(tableView, _cmd);
    if (!heightCache) {
        heightCache = [NSMutableDictionary dictionary];
        objc_setAssociatedObject(tableView, _cmd, heightCache, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    
    BOOL _isNew = FALSE;
    cell = [heightCache objectForKey:NSStringFromClass(cls)];
    if (!cell) {
        cell = [tableView cellForClass:cls isNew:&_isNew];
        if (estimatedHeight) [heightCache setObject:cell forKey:NSStringFromClass(cls)];
    }else {
        if (!estimatedHeight) {
            [heightCache removeObjectForKey:NSStringFromClass(cls)];
        }
    }
    
    if (isNew) *isNew = _isNew;
    
    NSAssert(cls == cell.class, @"class error");
    [self configCell:cell indexPath:indexPath model:model estimatedHeight:estimatedHeight isNew:_isNew];
    return cell;
}

-(void)configCell:(UITableViewCell<ITBOCell,ITBOCellHeight> *)cell
        indexPath:(NSIndexPath*)indexPath
            model:(id)model
  estimatedHeight:(BOOL)estimatedHeight
            isNew:(BOOL)isNew {
    cell.indexPath = indexPath;
    cell.model = model;
    
}

- (NSString *)getBucket:(NSIndexPath *)indexPath {
    NSString *bucket = @"";
    id sectionModel = [self sectionModel:indexPath];
    while ([sectionModel isKindOfClass:[BaseProxyViewModel class]]) {
        sectionModel = [sectionModel srcViewModel];
    }
    return bucket;
}

-(UITableViewCell<ITBOCell,ITBOCellHeight> *)tableView:(UITableView *)tableView
                                 cellForRowAtIndexPath:(NSIndexPath *)indexPath
                                                 isNew:(BOOL*)isNew {
    return
    [self tableView:tableView cellForRowAtIndexPath:indexPath estimatedHeight:FALSE isNew:isNew];
}


-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    id model = [self.model data:indexPath];
    NSNumber* number = objc_getAssociatedObject(model, (__bridge const void*)tableView);
    if (number) return [number floatValue];
    
    if (model) {
        UITableViewCell<ITBOCell,ITBOCellHeight>* cell = [self tableView:tableView cellForRowAtIndexPath:indexPath estimatedHeight:YES isNew:nil];
        CGFloat height = ceilf([cell heightForCell]);
        if (model) objc_setAssociatedObject(model, (__bridge const void*)tableView, @(height), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        return height;
    }
    return 198; //empty cell
}
-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [self tableView:tableView cellForRowAtIndexPath:indexPath isNew:nil];
}
@end
