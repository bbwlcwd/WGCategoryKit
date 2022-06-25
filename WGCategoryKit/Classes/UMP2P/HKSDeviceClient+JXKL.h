///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//  嘉欣凯利
///#end

#import "HKSDeviceClient.h"

enum {
    /** @brief  停止  */
    HKS_NPC_D_DPS_CUSTOM_NI_MODEL_STOP = 0,
    /** @brief  自动模式  */
    HKS_NPC_D_DPS_CUSTOM_NI_MODEL_AUTO = 2,
    /** @brief  回充模式  */
    HKS_NPC_D_DPS_CUSTOM_NI_MODEL_CHARGE_STATION = 4,
    
};
/** @brief  扫地机工作模式定义  */
typedef int HKS_NPC_D_DPS_CUSTOM_NI_MODEL;

enum {
    /** @brief  上  */
    HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION_UP = 1,
    /** @brief  下  */
    HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION_DOWN = 2,
    /** @brief  左  */
    HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION_LEFT = 3,
    /** @brief  右  */
    HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION_RIGHT = 4,
    /** @brief  停止  */
    HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION_STOP = 5,
};
/** @brief  扫地机控制方向命定定义  */
typedef int HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION;

///#begin zh-cn
/**
 *  @class      HKSDeviceClient (JXKL)
 *  @brief      嘉兴凯力相关定制接口
 */
///#end
///#begin en
///#end
@interface HKSDeviceClient (JXKL)


///#begin zh-cn
/**
 *  @brief      获取扫地机的电量比例
 *  @param[out] iPower[int *] 电量比例，20-80
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToPower:(int *)iPower;

///#begin zh-cn
/**
 *  @brief      获取扫地机的电源开关状态
 *  @param[out] iOffOn[int *] 电源开关状态，0：关，1：开
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToPowerOffOn:(int *)iOffOn;

///#begin zh-cn
/**
 *  @brief      设置扫地机的电源开关状态
 *  @param[in] iOffOn[int] 电源开关状态，0：关，1：开
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToPowerSetOffOn:(int)iOffOn;

///#begin zh-cn
/**
 *  @brief      设置扫地机的LED灯开关状态，无获取状态接口，只有设置接口，所以每次连接观看设备后，先发送一个设置关闭命定。
 *  @param[in] iOffOn[int] 开关状态，0：关，1：开
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToLEDLigthSetOffOn:(int)iOffOn;

///#begin zh-cn
/**
 *  @brief      获取扫地机的工作模式
 *  @param[out] iMode[HKS_NPC_D_DPS_CUSTOM_NI_MODEL *] 工作模式，请参考HKS_NPC_D_DPS_CUSTOM_NI_MODEL
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToWorkMode:(HKS_NPC_D_DPS_CUSTOM_NI_MODEL *)iMode;

///#begin zh-cn
/**
 *  @brief      设置扫地机的工作模式
 *  @param[in]  iMode[HKS_NPC_D_DPS_CUSTOM_NI_MODEL] 工作模式，请参考HKS_NPC_D_DPS_CUSTOM_NI_MODEL
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToWorkSetMode:(HKS_NPC_D_DPS_CUSTOM_NI_MODEL)iMode;

///#begin zh-cn
/**
 *  @brief      控制扫地机前进方向
 *  @param[in]  iDirection[HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION] 方向，请参考HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToDirection:(HKS_NPC_D_DPS_CUSTOM_NI_DIRECTION)iDirection;

///#begin zh-cn
/**
 *  @brief      获取扫地机清洁计划
 *  @param[out]  tWeeks[NSMutableArray->HKSDeviceCleanItem] 清洁计划
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToClean:(NSMutableArray *)tWeeks;

///#begin zh-cn
/**
 *  @brief      设置扫地机清洁计划
 *  @param[in]  tWeeks[NSMutableArray->HKSDeviceCleanItem] 清洁计划
 *  @return     [int] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (int)cameraCallCustomFuncToSetClean:(NSMutableArray *)tWeeks;

///#begin zh-cn
/**
 *  @brief      设置扫地机时间
 *  @param[in]  sDate[NSDate] 时间
 *  @return     [HKS_NPC_D_MPI_MON_ERROR] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (HKS_NPC_D_MPI_MON_ERROR)cameraCallCustomFuncToSetTime:(NSDate *)sDate;

///#begin zh-cn
/**
 *  @brief          获取/设置监控模式
 *  @param[out|in]  iStatus[int *] 0 关闭，1开启，2为查询状态
 *  @return         [HKS_NPC_D_MPI_MON_ERROR] 错误码
 *  @since v2.4.1.5
 */
///#end
///#begin en
///#end
- (HKS_NPC_D_MPI_MON_ERROR)cameraCallCustomFuncToMonitorStatus:(int *)iStatus;


- (HKS_NPC_D_MPI_MON_ERROR)cameraCallCustomFuncToWIFIPassword:(NSMutableString *)inout_sPassword;


- (HKS_NPC_D_MPI_MON_ERROR)cameraCallCustomFuncToSetWIFIPassword:(NSString *)in_sPassword;


@end
