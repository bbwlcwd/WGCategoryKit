///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

#import "HKSDeviceClient.h"

enum {
    /** @brief  停止运动，停止前一个启动命令  */
    HKS_NPC_D_MON_PTZ_CMD_STOP = 0,
    /** @brief  接通灯光电源，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_LIGHT_PWRON = 2,
    /** @brief  接通雨刷开关，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_WIPER_PWRON = 3,
    /** @brief  接通风扇开关，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_FAN_PWRON = 4,
    /** @brief  接通加热器开关，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_HEATER_PWRON = 5,
    /** @brief  接通辅助设备开关1，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_AUX_PWRON1 = 6,
    /** @brief  接通辅助设备开关2，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_AUX_PWRON2 = 7,
    
    /** @brief  设置预置点，in_dwPtzData为预置点的序号（1至255）  */
    HKS_NPC_D_MON_PTZ_CMD_SET_PRESET = 8,
    /** @brief  清除预置点，in_dwPtzData为预置点的序号（1至255）  */
    HKS_NPC_D_MON_PTZ_CMD_CLE_PRESET = 9,
    
    /** @brief  焦距以速度SS变大（倍率变大），in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_ZOOM_IN = 11,
    /** @brief  焦距以速度SS变小（倍率变小），in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_ZOOM_OUT = 12,
    /** @brief  焦点以速度SS前调，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_FOCUS_NEAR = 13,
    /** @brief  焦点以速度SS后调，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_FOCUS_FAR = 14,
    /** @brief  光圈以速度SS扩大，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_IRIS_OPEN = 15,
    /** @brief  光圈以速度SS缩小，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_IRIS_CLOSE = 16,

    /** @brief  云台以SS的速度上仰，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_TILT_UP = 21,
    /** @brief  云台以SS的速度下俯，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_TILT_DOWN = 22,
    /** @brief  云台以SS的速度左转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_PAN_LEFT = 23,
    /** @brief  云台以SS的速度右转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_PAN_RIGHT = 24,
    /** @brief  云台以SS的速度上仰和左转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_UP_LEFT = 25,
    /** @brief  云台以SS的速度上仰和右转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_UP_RIGHT = 26,
    /** @brief  云台以SS的速度下俯和左转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_DOWN_LEFT = 27,
    /** @brief  云台以SS的速度下俯和右转，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_DOWN_RIGHT = 28,
    /** @brief  云台以SS的速度左右自动扫描，in_dwPtzData为速度（1至10），in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_PAN_AUTO = 29,
    
    /** @brief  将预置点加入巡航序列，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为巡航点号（1至32），in_dwPtzExtParam2为预置点号（1至255）  */
    HKS_NPC_D_MON_PTZ_CMD_FILL_PRE_SEQ = 30,
    /** @brief  设置巡航点停顿时间，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为巡航点号（1至32），in_dwPtzExtParam2为停顿时间（1至255秒）  */
    HKS_NPC_D_MON_PTZ_CMD_SET_SEQ_DWELL = 31,
    /** @brief  设置巡航速度，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为巡航点号（1至32），in_dwPtzExtParam2为停顿时间（1至10）  */
    HKS_NPC_D_MON_PTZ_CMD_SET_SEQ_SPEED = 32,
    /** @brief  将预置点从巡航序列中删除，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为巡航点号（1至32），in_dwPtzExtParam2为预置点号（1至255）  */
    HKS_NPC_D_MON_PTZ_CMD_CLE_PRE_SEQ = 33,
    /** @brief  开始记录轨迹，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_STA_MEM_CRUISE = 34,
    /** @brief  停止记录轨迹，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_STO_MEM_CRUISE = 35,
    /** @brief  开始轨迹，无参数，无参数  */
    HKS_NPC_D_MON_PTZ_CMD_RUN_CRUISE = 36,
    /** @brief  开始巡航，in_dwPtzData为巡航路径号  */
    HKS_NPC_D_MON_PTZ_CMD_RUN_SEQ = 37,
    /** @brief  停止巡航，in_dwPtzData为巡航路径号  */
    HKS_NPC_D_MON_PTZ_CMD_STOP_SEQ = 38,
    /** @brief  快球转到预置点，in_dwPtzData为预置点号  */
    HKS_NPC_D_MON_PTZ_CMD_GOTO_PRESET = 39,
    /** @brief  清除巡航，in_dwPtzData为巡航路径号  */
    HKS_NPC_D_MON_PTZ_CMD_CLEAR_TOUR = 40,
    /** @brief  UTC 探测是否支持  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_DETECT = 101,
    /** @brief  UTC 设置  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_SET = 102,
    /** @brief  UTC 上  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_UP = 103,
    /** @brief  UTC 下  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_DOWN = 104,
    /** @brief  UTC 左  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_LEFT = 105,
    /** @brief  UTC 右  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_RIGHT = 106,
    /** @brief  UTC 聚焦  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_FOCUS_NEER = 107,
    /** @brief  UTC 聚焦  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_FOCUS_FAR = 108,
    /** @brief  UTC ZOOM  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_ZOOM_WIDE = 109,
    /** @brief  UTC ZOOM  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_ZOOM_TELE = 110,
    /** @brief  UTC 停止  */
    HKS_NPC_D_MON_CSD_PTZ_CMD_UTC_STOP = 111,
    
};
/** @brief  摄像头云台控制命定定义  */
typedef int HKSDevicePtzCmd;

/**
 *  @brief      摄像机云台控制接口。通过HKSDeviceClient调用(camear ptz function interface class)
 */
@interface HKSDeviceClient (PTZ)


/**
 *  @brief  当摄像头状态为HKS_NPC_D_MON_DEV_PLAY_STATUS_PLAYING播放中的时候，就可以调用该接口进行摄像头的云台控制
 *
 *  @param[in]  ptzData[int] 控制参数，根据云台控制命定，填写相对于的数据
 *  @param[in]  thePtzCmd[HKSDevicePtzCmd] 云台控制命定，请参考HKSDevicePtzCmd
 *  @since v1.0.0.0
 */
- (int)ptzControlWithCmd:(HKSDevicePtzCmd)ptzCmd
                     data:(int)ptzData;


/**
 *  @brief  当摄像头状态为HKS_NPC_D_MON_DEV_PLAY_STATUS_PLAYING播放中的时候，就可以调用该接口进行摄像头的云台控制
 *
 *  @param[in]  thePtzCmd[HKSDevicePtzCmd] 云台控制命定，请参考HKSDevicePtzCmd
 *  @param[in]  ptzData[int] 控制参数，根据云台控制命定，填写相对于的数据
 *  @param[in]  in_dwPtzExtParam1[int] 控制参数一，根据云台控制命定，填写相对于的数据
 *  @param[in]  in_dwPtzExtParam2[int] 控制参数二，根据云台控制命定，填写相对于的数据
 *  @since v2.3.4.1
 */
- (int)ptzControlWithCmd:(int)ptzCmd
                     data:(int)ptzData
                   param1:(int)in_dwPtzExtParam1
                   param2:(int)in_dwPtzExtParam2;
@end
