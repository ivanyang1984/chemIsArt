//
//  CIAQuestionListViewModel.m
//  ChemIsArt
//
//  Created by roro_latrobe on 15/8/15.
//  Copyright (c) 2015年 roro_latrobe. All rights reserved.
//

#import "CIAQuestionListViewModel.h"
#import "CIAResultSet.h"

@implementation CIAQuestionListViewModel

+ (instancetype) initWithUserId {
    TBOStandardModelLoader* loader = TBOMakeStandardModelLoader(@"questions/1", nil, [CIAResultSet class]);
    return [self initWithModelLoader:loader];
}

-(id)data:(NSIndexPath* const)indexPath {
    return [self.questions objectAtIndex:indexPath.row];
}

-(void)onloaderCompleted:(CIAResponse*)response succeeded:(BOOL)succeeded {
    if (succeeded) {
        CIAResultSet* result = (CIAResultSet*)response.responseJSONModel;
        [self beginDataChanged];
        self.questions = result.questions;
        [self endDataChanged];
    }
    [self setLoadFinished:succeeded];
}

-(NSInteger)itemCount:(NSInteger)section {
    return [self.questions count];
}

@end
