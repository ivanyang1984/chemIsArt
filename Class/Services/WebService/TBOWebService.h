//
//  TBBLWebService.h
//  TBBala
//
//  Created by go886 on 15/3/14.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBOBaseRequest.h"
//#import "TBLoginSRServiceProtocol.h"

//#import "TBOAction.h"

@interface TBOWebService : NSObject
//@property(nonatomic,strong,readonly)id<TBLoginSRServiceProtocol> loginService;
//@property(nonatomic,strong,readonly)TBOFeedService* feedService;
//@property(nonatomic,strong,readonly)TBOTopicService* topicService;
//@property(nonatomic,strong,readonly)TBOCommentService* commentService;
+(instancetype)instance;

-(void)authenticateWithCompletion:(void (^)(BOOL succeed))block;
@end
