//
//  XUtility.h
//  XUtility
//
//  Created by go886 on 14-10-14.
//  Copyright (c) 2014年 go886. All rights reserved.
//
#import <Foundation/Foundation.h>

BOOL isNull(id);
int toInt(id);
BOOL isEmptyString(id);
NSTimeInterval tNow();
float systemVersion();

extern NSString* str(NSString* fmt, ...);
extern NSURL* url(NSString* fmt, ...);

unsigned long long sizeForPath(NSString* path, BOOL isRecursion);
unsigned long long freeDiskSpace();

extern void enabledDroppedFrameCounter(BOOL enabled);

NSMutableDictionary* objToDictionary(NSObject* obj);
id dictionaryToObj(NSDictionary* dict, Class defaultclass);

extern id newToken(id obj);
extern id objForToken(id token);

id logger(NSString* format, ...);

#define WS(obj)  __weak __typeof(&*obj)w_##obj = obj;

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)



#ifndef DEF_SINGLETON
#define DEF_SINGLETON \
+ (instancetype)instance \
{ \
static dispatch_once_t once; \
static id __singleton__; \
dispatch_once( &once, ^{ __singleton__ =  [[[self class] alloc] init]; } ); \
return __singleton__; \
}
#endif


#ifdef DEBUG
#define sLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define sLogger(fmt, ...) logger((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define sLog(fmt, ...)    {}
#define sLogger(fmt, ...) {}
#endif


#define valuestr(s)             ([NSString stringWithUTF8String:#s])
#define onlyMainThread          (NSAssert([NSThread isMainThread], @"only mainthread"))
#define sleep(s)                ([NSThread sleepForTimeInterval:s])

#define RGBA(r,g,b,a)           [UIColor colorWithRed:((float)r)/255.f green:((float)g)/255.f blue:((float)b)/255.f alpha:a]
#define RGB(r,g,b)              RGBA(r,g,b,1.0f)
#define ColorWithHex(hexValue)  RGBA( ((hexValue & 0xFF000000) >> 24), ((hexValue & 0xFF0000) >> 16), ((hexValue & 0xFF00) >> 8), ((float)(hexValue & 0x00FF))/255.f )

#ifndef UIViewAutoresizingFlexibleSize
#define UIViewAutoresizingFlexibleSize (UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth)
#endif

#ifndef UIViewAutoresizingFlexibleMargin
#define UIViewAutoresizingFlexibleMargin (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin |UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin)
#endif

#ifndef UIViewAutoresizingLeftCenter
#define UIViewAutoresizingLeftCenter (UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin)
#endif

#ifndef UIViewAutoresizingRightCenter
#define UIViewAutoresizingRightCenter (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin)
#endif


#define isAfterIOS6     (systemVersion() >= 6.0f)
#define isAfterIOS7     (systemVersion() >= 7.0f)
#define isAfterIOS8     (systemVersion() >= 8.0f)
#define kScreenWidth    ([[UIScreen mainScreen]bounds].size.width)
#define kScreenHeight   ([[UIScreen mainScreen]bounds].size.height)
#define kScreen4Inch    ([[UIScreen mainScreen]bounds].size.height>480)
#define kScreen3P5Inch  ([[UIScreen mainScreen] currentMode].size.height <1136)


#define theDefaultCenter ([NSNotificationCenter defaultCenter])
#define theFileMgr       ([NSFileManager defaultManager])
#define theUserDefaults  ([NSUserDefaults standardUserDefaults])




#import "NSInvocation+utility.h"
#import "NSData+Base64.h"
#import "NSDate+utility.h"
#import "NSDictionary+KeyPath.h"
#import "NSDictionary+utility.h"
#import "NSNotificationCenter+utility.h"
#import "NSObject+observer.h"
#import "NSObject+event.h"
#import "NSString+MD5.h"
#import "NSString+UrlEncode.h"
#import "NSStringAdditions.h"
#import "NSThread+block.h"
#import "NSTimer+Blocks.h"
#import "Serializationhelper.h"
#import "UIAlertView+MKBlockAdditions.h"
#import "UIViewAdditons.h"

#import "Tipshelper.h"
#import "CacheCenter.h"
