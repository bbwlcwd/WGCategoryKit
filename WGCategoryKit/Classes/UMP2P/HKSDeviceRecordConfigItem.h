//
//  HKSDeviceRecordConfigItem.h
//  IPHKPlayer
//
//  Created by UMEYE on 14/12/8.
//
//  Record config
//

#import <Foundation/Foundation.h>

@interface HKSDeviceRecordConfigItem : NSObject

@property(nonatomic, assign) int iChNo;//通道号（查询请求消息中只有通道号有效，其它参数无效）
@property(nonatomic, assign) int iRecState;//录像状态，0：关闭，1：始终录像，2：配置录像
@property(nonatomic, assign) int iRecStream;//录像码流
@property(nonatomic, assign) int iPreRecord;//预录时长（秒）
@property(nonatomic, assign) unsigned int bOpenAudio;//是否开启音频录像

@property(nonatomic, assign) unsigned int bOpenGeneral;//是否开启常规录像（定时录像）
@property(nonatomic, assign) unsigned int bOpenCheckAlarm;//是否开启检测报警录像（移动报警、视频遮挡、视频丢失等）
@property(nonatomic, assign) unsigned int bOpenInputAlarm;//是否开启输入报警录像（指探头，如红外等）
@property(nonatomic, strong) NSMutableArray *tWeekSect;//时间段

@end
