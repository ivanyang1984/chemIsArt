//
//  TBOBaseResponseModel.h
//  TBOcean
//
//  Created by go886 on 15/4/16.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "TBJSONModel.h"
@protocol ITBOListModel <NSObject>
-(NSArray*)items;
-(NSString*)cursor;
-(NSInteger)page;
-(BOOL)hasMore;
@end


@protocol ITBODetailModel <NSObject>
-(id)detailInfo;
@end

@interface CIABaseResponseModel : TBJSONModel<ITBOListModel>
@property(nonatomic,strong)NSString* cursor;
@property(nonatomic,assign)BOOL hasMore;
@property(nonatomic,assign)NSInteger page; //当前页数
@end
