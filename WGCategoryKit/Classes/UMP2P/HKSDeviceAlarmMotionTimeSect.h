//
//  HKSDeviceAlarmMotionTimeSect.h
//  IPHKPlayer
//
//  Created by HSKJ on 14-5-9.
//
//

#import <Foundation/Foundation.h>


@interface HKSDeviceAlarmMotionTimeSect : NSObject

@property(nonatomic, assign) unsigned int bOpenGeneral;//是否开启常规录像（定时录像）
@property(nonatomic, assign) unsigned int bOpenCheckAlarm;//是否开启检测报警录像（移动报警、视频遮挡、视频丢失等）
@property(nonatomic, assign) unsigned int bOpenInputAlarm;//是否开启输入报警录像（指探头，如红外等）
@property(nonatomic, assign) int            bIfEnable;//是否启用
@property(nonatomic, assign) Date_Time      tBeginTime;//开始时间
@property(nonatomic, assign) Date_Time      tEndTime;//结束时间
@property(nonatomic, assign) int            week;//当前星期日
@property(nonatomic, strong) NSMutableArray *weeks;
@end
