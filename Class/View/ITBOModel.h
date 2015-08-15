//
//  ITBOModel.h
//  TBOcean
//
//  Created by go886 on 15/4/22.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ITBOModel <NSObject>
@property(nonatomic,strong)id model;
@end

@protocol ITBOCell <ITBOModel>
@property(nonatomic,strong)NSIndexPath* indexPath;
@end

@protocol ITBOCellHeight <NSObject>
-(CGFloat)heightForCell;
@end

///*曝光埋点*/
//@protocol ITBOBucket <NSObject>
//@property(nonatomic,strong)NSString* bucket;  //算法标识
//@end