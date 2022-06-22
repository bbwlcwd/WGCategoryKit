//
//  HKSDeviceAlarmRecodeItem.h
//  IPHKPlayer
//
//  Created by George on 13-9-6.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceAlarmRecordItem : NSObject
/// 报警记录ID
@property(nonatomic, copy) NSString *sAlarmRecordId;
/// 设备ID（即摄像机ID）
@property(nonatomic, copy) NSString *sDevId;
/// 设备上层的AlarmId数据
@property(nonatomic, copy) NSString *sDevAlarmId;
/// 设备显示名称
@property(nonatomic, copy) NSString *sDevShowName;
/// 报警类型，参见HKS_NPC_D_MON_ALARM_TYPE_*定义
@property(nonatomic, assign) int    iAlarmType;
/// 报警状态,0:停止(离线),1:开始(在线),2:设备故障,3:硬盘满
@property(nonatomic, assign) int    iAlarmState;
/// 报警时间
@property(nonatomic, copy) NSString     *sAlarmTime;
/// 报警信息
@property(nonatomic, copy) NSString     *sAlarmInfo;
/// 报警大图
@property(nonatomic, copy) NSString     *sAlarmBigImg;
/// 报警小图
@property(nonatomic, copy) NSString     *sAlarmSmallImg;
/// 图片文件关联ID
@property(nonatomic, copy) NSString     *link_img_id;
/// 视频文件关联ID
@property(nonatomic, copy) NSString     *link_video_id;


/// 是否已读，预留上层使用
@property(nonatomic, assign) BOOL       isRead;
/// 是否已经存在，预留上层使用
@property(nonatomic, assign) BOOL       isExist;

@end
