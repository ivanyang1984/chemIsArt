//
//  NSObject+event.h
//  TBBala
//
//  Created by go886 on 15/3/17.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @brief      异步发送消息到sel
 @param      que  消息发送的队列, default is [NSOperationQueue mainQueue]
             sender  指定消息的发送源, 可为 nil
             sel   消息处理的selector
             ...   可变参数, 注意参数需与selecotr 匹配
 
 @example:
     onSelector(nil, self, @Selector(onLogin:));
     postToSelector(nil, nil, @Selector(onLogin:), userinfo);
 */
extern void postToSelector(id sender, dispatch_queue_t que, SEL sel, ...);
extern void postToSelectorN(id sender, int limit, dispatch_queue_t que, SEL sel, ...);


/**
 @brief     同步发送消息到sel, 参考 postToSelector
 */
extern void sendToSelector(id sender, SEL sel, ...);
extern void sendToSelectorN(id sender, int limit, SEL sel, ...);

/**
 @brief      接收消息处理(接收来自 postToSelector、 sendToSelector 的消息)
 @param      sender 指定接收指定发送者发出的消息, 可为nil
             receiver 指定按收消息处理的对象, 不可为空
             sel 消息处理的selector 需要与发出的消息中的sel 匹配
             @return    返回 token, 可用来 removeEvent(, token) 中使用
 
 @example:
    onSelector(sender, self, @Selector(onLogin:))
 */
extern id   onSelector(id sender, id receiver, SEL sel);
extern id   onSelectorEx(id sender, SEL sel, id receiver, SEL receiveSel);
extern id   onSelectorWithBlock(id sender, SEL sel, id block);

extern void offSelector(id sender, SEL sel, id receiver, SEL receiveSel);



//----------------------------------------------------------------
/**
 @brief      异步发送事件
 @param      sender  指定事件的发送源, 可为 nil
             que  消息发送的队列, default is [NSOperationQueue mainQueue]
             type 事件的类型
             param 事件的参数
 
 @example:
     onEvent(nil, EV_LOGIN, ^(struct eventContext* const ev){});
     postEvent(nil, nil, EV_LOGIN, @"name");
 */
extern void postEvent(id sender, dispatch_queue_t que, int type, id param);

/**
 @brief     同步发送事件, 参考: postEvent
 */
extern void sendEvent(id sender, int type, id param);


/**
 @brief      接收处理指定的事件(接收来自 postEvent、 sendEvent 发出的事件)
 @param      sender  指定接收来自sender 发出的事件, 可为 nil
             type    事件类型
             handler 事件的处理函数, 不能为空
 @return     返回 token, 在 removeEvent(, token) 中使用
 */
//extern id   onEvent(id sender, int type, eventHandler handler);


/**
 @brief      接收指定的事件, 交由 sel 处理
 @param      sender  指定接收来自sender 发出的事件, 可为 nil
             type    事件类型
             receiver 事件按收的对象
             sel 事件的处理函数, 注意: 函数原型为以下两种：
             - selName:(id)name;  带一个参数
             - selName;     不带参数
 @return     返回 token, 在 removeEvent(, token) 中使用
 
 @example:
     onEventSelector(nil, EV_LOGIN, self, @selector(onLogin:))
     onEventSelector(nil, EV_LOGIN, self, @selector(onLogined));
     sendEvent(nil, EV_LOGIN, userinfo);
 */
extern id   onEventSelector(id sender, int type, id receiver, SEL sel);

extern void offEventSelector(id sender, int type, id receiver, SEL sel);

/**
 @brief     移除指定sender 下的指定 token 的事件
 @param     sender 事件的发送源, 可为 nil
            token 不能为空, 通过 onSelector、onEventSelector、onEventSelectorParam 等返回
 */
extern void removeEvent(id token);


/**
 @brief     清空 receiver 下所有的事件
 */
extern void removeAllEvent(id receiver);