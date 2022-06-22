//
//  HKSDeviceAlertItem.h
//  IPHKPlayer
//
//  Created by George on 13-7-16.
//
//

#import <Foundation/Foundation.h>
#import "HKSDeviceNotifyOrActioItem.h"
@interface HKSDeviceAlarmItem : NSObject


@property(nonatomic, copy) NSString         *sAlarmType;//报警类型表，以逗号分隔，值参考HKS_NPC_D_MON_ALARM_TYPE_*定义
@property(nonatomic, copy) NSString         *sDevId;
@property(nonatomic, strong) NSMutableArray *tAlarmTypes;//报警类型表，以逗号分隔，值参考HKS_NPC_D_MON_ALARM_TYPE_*定义
@property(nonatomic, strong) NSMutableArray *notifyArray;//NSMutableArray[HKSDeviceNotifyOrActioItem]通知表
@property(nonatomic, strong) NSMutableArray *actionArray;//NSMutableArray[HKSDeviceNotifyOrActioItem]联动表
@property(nonatomic, assign) BOOL           bArmState;//布防状态，0：暂停状态，1：开启状态
@property(nonatomic, assign) BOOL           bNotifyState;//通知状态，0：暂停状态，1：开启状态
@property(nonatomic, assign) BOOL           bActionState;//联动状态，0：暂停状态，1：开启状态
@property(nonatomic, assign) int            iNotifyNum;//通知数
@property(nonatomic, assign) int            iActionNum;//联动数
@property(nonatomic, copy) NSString         *sVerifyCode;//校验码
@end
