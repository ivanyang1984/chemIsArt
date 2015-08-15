//
//  Serializationhelp.h
//  XUtility
//
//  Created by go886 on 14/12/4.
//  Copyright (c) 2014年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface Serializationhelper : NSObject
+(instancetype)instance;

-(NSString*)fullFileName:(NSString*)filename;

-(void)writeJSONObject:(id)obj filename:(NSString*)filename;

-(NSData*)dataForkey:(NSString*)filename;
-(NSString*)stringForkey:(NSString*)filename;
-(UIImage*)imageForkey:(NSString*)filename;

-(id)jsonObjForkey:(NSString*)filename;
-(NSArray*)arrayForJson:(NSString*)filename;
-(NSDictionary*)objForJson:(NSString*)filename;

-(NSDictionary*)xmlobjForkey:(NSString*)filename;
@end
