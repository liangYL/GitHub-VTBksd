//
//  XCEvent.h
//  XCEvent
//
//  Created by wxc on 14-7-3.
//  Copyright (c) 2014年 wxc. All rights reserved.
//

#import <Foundation/Foundation.h>

//事件中心
#define XCSendEvent(type,parame,...) ([[XCEvent sharedEvent] sendEvent:self eventType:type parameters:parame, ##__VA_ARGS__])

#define XCAddObserver(tag,type,backSel) do { [[XCEvent sharedEvent] addObserver:self suorceTag:tag eventType:type sel:backSel]; } while(0)
#define XCAddObserverB(tag,type,blockB) do { [[XCEvent sharedEvent] addObserver:self suorceTag:tag eventType:type block:blockB]; } while(0)

#define XCRemoveObserverAll do { [[XCEvent sharedEvent] removeObserver:self]; } while(0)
#define XCRemoveObserver(tag,type) do { [[XCEvent sharedEvent] removeObserver:tag enentType:type]; } while(0)

//开发者通知中心
#define XCPostNotification(Nname,parame,...) do { [[XCEvent sharedEvent] sendNotification:Nname parameters:parame, ##__VA_ARGS__]; } while(0)
#define XCAddNotification(Nname,backSel) do { [[XCEvent sharedEvent] addNotification:self name:Nname sel:backSel]; } while(0)
#define XCAddNotificationB(Nname,blockB) do { [[XCEvent sharedEvent] addNotification:self name:Nname block:blockB]; } while(0)

#define XCRemoveNotificationAll do { [[XCEvent sharedEvent] removeNotificationObserver:self]; } while(0)
#define XCRemoveNotification(Nname) do { [[XCEvent sharedEvent] removeNotificationObserver:self name:Nname]; } while(0)

@interface XCEvent : NSObject

+ (XCEvent *)sharedEvent;
//发送回调
- (id)sendEvent:(id)objTag eventType:(int)eventType parameters:(id)parameters,...;
//监控回调
- (void)addObserver:(id)objTag suorceTag:(id)suorceTag eventType:(int)eventType sel:(SEL)sel;
//监控回调
- (void)addObserver:(id)objTag suorceTag:(id)suorceTag eventType:(int)eventType block:(id(^)(id data,va_list otherParam))block;


//取消监控
- (void)removeObserver:(id)objTag;
//取消某个监控
- (void)removeObserver:(id)suorceTag enentType:(int)eventType;


- (void)sendNotification:(NSString *)name parameters:(id)parameters,...;
- (void)addNotification:(id)objTag name:(NSString *)name sel:(SEL)sel;
- (void)addNotification:(id)objTag name:(NSString *)name block:(void(^)(id data,va_list otherParam))block;
//取消监控
- (void)removeNotificationObserver:(id)objTag;
//取消某个监控
- (void)removeNotificationObserver:(id)objTag name:(NSString *)name;
@end



@interface XCEventObj : NSObject
{
    id  _objTag;
    id  _sourceTag;
    int _eventType;
    NSString  *_callBackSel;
    id (^callBackBlock)(id data,va_list otherParam);
    
    int _type;
}
@property (nonatomic,assign) id objTag,sourceTag;
@property (nonatomic,assign) int eventType,type;
@property (nonatomic,copy) NSString *callBackSel;
@property (nonatomic,copy) id (^callBackBlock)(id data,va_list otherParam);
@end


@interface XCNotificationObj : NSObject
{
    id       _objTag;
    NSString *_name;
    NSString *_callBackSel;
    void (^callBackBlock)(id data,va_list otherParam);
    
    int _type;
}
@property (nonatomic,assign) id objTag;
@property (nonatomic,assign) int type;
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *callBackSel;
@property (nonatomic,copy) void (^callBackBlock)(id data,va_list otherParam);
@end