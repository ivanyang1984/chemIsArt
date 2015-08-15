//
//  Tipshelper.h
//  XUtility
//
//  Created by go886 on 15/1/8.
//  Copyright (c) 2015年 go886. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    Tip_Init = 0,
    Tip_Msg,
    Tip_OK,
    Tip_Info,
    Tip_Warn,
    Tip_Error,
}TipStyle;

@interface XTipContent : NSObject
@property(nonatomic,assign)BOOL threadSafe;
@property(nonatomic,strong)NSString* title;
@property(nonatomic,strong)NSString* msg;
@property(nonatomic,strong)NSString* cancel;
@property(nonatomic,strong)NSString* confirm;
@property(nonatomic,assign)TipStyle style;
@property(nonatomic,strong)id userdata;
@property(nonatomic,assign)int tag;
@end

typedef void (^TipFinished)(NSInteger btnIdx, XTipContent* ctx);
typedef void (^TipHandler)(XTipContent* ctx, TipFinished block);


@interface Tipshelper : NSObject
+(void)setTipHandler:(TipHandler)handler;

+(void)show:(XTipContent*)ctx;
+(void)show:(XTipContent*)ctx finished:(TipFinished)block;
+(void)show:(NSString*)msg style:(TipStyle)style;
+(void)show:(NSString*)msg title:(NSString*)title style:(TipStyle)style;


+(void)showMsg:(NSString*)msg;
+(void)showMsg:(NSString*)msg title:(NSString*)title;
+(void)showMsg:(NSString*)msg title:(NSString*)title cancel:(NSString*)cancel;
+(void)showMsg:(NSString *)msg title:(NSString *)title cancel:(NSString *)cancel confirm:(NSString*)confirm;
+(void)showMsg:(NSString *)msg title:(NSString *)title cancel:(NSString *)cancel confirm:(NSString*)confirm finisehd:(TipFinished)block;

+(void)showTipWithFormat:(NSString*)fmt, ...;
+(void)showTip:(NSString*)msg;
+(void)showTip:(NSString*)msg title:(NSString*)title;

+(void)warningTipWithFormat:(NSString*)fmt, ...;
+(void)warningTip:(NSString*)msg;
+(void)warningTip:(NSString*)msg title:(NSString*)title;

+(void)errorTipWithFormat:(NSString*)fmt, ...;
+(void)errorTip:(NSString*)msg;
+(void)errorTip:(NSString*)msg title:(NSString*)title;

+(void)finishedTipWithFormat:(NSString*)fmt, ...;
+(void)finishedTip:(NSString*)msg;
+(void)finishedTip:(NSString *)msg title:(NSString*)titile;
@end
