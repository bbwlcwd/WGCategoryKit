//
//  HKSDeviceNotifyOrActioItem.h
//  IPHKPlayer
//
//  Created by George on 13-7-16.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceNotifyOrActioItem : NSObject
@property(nonatomic, assign) int    type;//通知类型，参考HKS_NPC_D_MON_ALARM_NOTIFY_TYPE_*定义 or 联动类型，参考HKS_NPC_D_MON_ALARM_ACTION_TYPE_*定义

@property(nonatomic,copy) NSString  *typeParam;//通知参数，根据通知类型确定通知参数内容，如手机推送为TOKEN，短信为手机号码，EMAIL为EMAIL地址

@end
