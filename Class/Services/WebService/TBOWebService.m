//
//  TBBLWebService.m
//  TBBala
//
//  Created by go886 on 15/3/14.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBOWebService.h"
#import <UIStyleSheetLib/UIStyleSheetLib.h>
//#import <TBLoginSRServiceProtocol.h>
//#import "LoginAdapter.h"

@implementation TBOWebService {
   // id<TBLoginSRServiceProtocol> _loginService;
}
DEF_SINGLETON

-(instancetype)init {
    self = [super init];
    if (self) {
      //  _loginService =  [[TBMContainer sharedContainer] serviceForName:kLoginSRService];
//        _feedService =  [[TBOFeedService alloc]init];
//        _topicService = [TBOTopicService instance];
//        _commentService = [[TBOCommentService alloc] init];
     //   _loginService =  [[TBMContainer sharedContainer] serviceForName:kLoginSRService];
    }
    return self;
}
-(void)authenticateWithCompletion:(void (^)(BOOL succeed))block {
//    [[LoginAdapter sharedInstantce] loginWithLoginOption:LoginOptionAutoLoginAndManualLogin
//                                       completionHandler:^(BOOL isSuccessful, NSDictionary *loginResult) {
//                                           if (block) block(isSuccessful);
//                                       } cancelationHandler:^{
//                                           if (block) block(FALSE);
//                                       }];
}
@end
