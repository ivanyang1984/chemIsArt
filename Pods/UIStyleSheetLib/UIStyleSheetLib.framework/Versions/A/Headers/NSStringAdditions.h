//
//  NSStringAdditions.h
//  xiami
//
//  Created by Henry on 9/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (xiamiString)

+(NSString *)documentPath;
+(NSString *)cachePath;
//+(NSString *)formatCurDate;
//+(NSString *)formatCurDay;
+(NSString *)getAppVer;

- (NSURL *) toURL;
- (NSURL *) toSongURL;
//- (BOOL) isEmail;
- (BOOL) isEmpty;
//- (NSString *) escapeHTML;
- (NSString *) unescapeHTML;
//- (NSString *) stringByRemovingHTML;
-(NSString *)trim;

//-(BOOL) isOlderVersionThan:(NSString*)otherVersion;
//-(BOOL) isNewerVersionThan:(NSString*)otherVersion;
@end
