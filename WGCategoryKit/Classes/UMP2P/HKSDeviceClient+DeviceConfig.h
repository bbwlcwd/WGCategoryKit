

#import "HKSDeviceClient.h"
@class HKSDeviceCodecItem;
@class HKSDeviceInfoItem;
@class HKSDeviceImageItem;
@class HKSDeviceSearchAdapterItem;

/**
 *  @class      HKSDeviceClient (DeviceConfig)
 *  @brief      摄像机JSON参数配置接口，调用接口之前请先确认设备是否已经实现该功能模块。通过HKSDeviceClient调用(camear param function interface class)
 */
@interface HKSDeviceClient (DeviceConfig)


/**
 *  @brief  获取是否支持json方式进行设备配置
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)isDeviceConfigSupportJson;

/**
 *  @brief      根据通道号获取通道的编码数据
 *
 *  @param[in]  aChannel[int]通道号，从0开始到31  0xff为所有通道
 *  @param[out] aParamItem[HKSDeviceCodecItem]输入获取到的设备编码数据
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceConfigCodec:(int)aChannel
                                               outCodecItem:(HKSDeviceCodecItem *)aParamItem;


/**
 *  @brief      根据通道号设置通道的编码数据
 *
 *  @param[int] aParamItem[HKSDeviceCodecItem]需要修改的设备编码数据
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)setDeviceConfigCodec:(HKSDeviceCodecItem *)aParamItem;

/**
 *  @brief      获取设备信息
 *
 *  @param[int] aParamItem[HKSDeviceCodecItem]获取到的设备信息
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceConfigInfo:(HKSDeviceInfoItem *)aParamItem;

/**
 *  @brief      获取设备以太网信息
 *
 *  @param[int] aParamItem[HKSDeviceSearchAdapterItem]获取到的以太网信息
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.7.4.1
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceEthernetInfo:(HKSDeviceSearchAdapterItem *)aParamItem;

/**
 *  @brief      设置设备以太网信息
 *
 *  @param[int] aParamItem[HKSDeviceSearchAdapterItem]以太网信息
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.7.4.1
 */
- (HKS_NPC_D_MPI_MON_ERROR)setDeviceEthernetInfo:(HKSDeviceSearchAdapterItem *)aParamItem;

/**
 *  @brief      设备控制
 *
 *  @param[int] aFuncId[HKS_NPC_D_CHILD_JSON_MANAGE_FUNCID]控制功能ID
 *  @return [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceControl:(HKS_NPC_D_CHILD_JSON_MANAGE_FUNCID)aFuncId;



/**
 *  @brief      获取设备图像参数
 *
 *  @param[in]  aChannel[int]通道号，从0开始到31  0xff为所有通道
 *  @param[out] aParamItem[HKSDeviceImageItem]  输入获取到的设备图像数据
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceConfigImage:(int)aChannel
                                            outParamItem:(HKSDeviceImageItem *)aParamItem;

/**
 *  @brief      设备管理(重启设备、恢复初始化)
 *
 *  @param[in]  aCmd[int]命定，1：重启，2：初始化
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]接口执行状态
 *  @since  v2.3.6.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceManage:(int)aCmd;


/**
 *  @brief      控制远程录像
 *  @param      bEnable[BOOL]   启用
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceRemoteVideo:(BOOL)bEnable;

/**
 *  @brief      控制远程抓拍
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceRemotePhoto;

/// 零通道道
- (HKS_NPC_D_MPI_MON_ERROR)deviceZeroChannel:(NSMutableArray *)aParamItem;
- (HKS_NPC_D_MPI_MON_ERROR)setDeviceZeroChannel:(NSMutableArray *)aParamItem;

/// 获取报警输出信息
/// @param aParamItem 请求通道数组，从0开始，空:获取全部
- (void)deviceCfgAlarmOut:(NSMutableArray *)aParamItem
                  handler:(void (^)(id data, int errorCode))completionHandler;

/// 设置报警输出
/// @param channel 报警输出通道,从0开始,0xFFFF表示全通道
/// @param param 报警输出使能,0=关闭,1=自动,2=手动
- (void)setDeviceCfgAlarmOut:(int)channel
                       param:(int)param
                     handler:(void (^)(id data, int errorCode))completionHandler;


/// 通用设备获取配置接口
/// @param op 操作码
/// @param param 参数
/// @param completionHandler 回调
- (void)deviceConfigJson:(int)op
                   param:(NSMutableDictionary *)param
                autoStop:(BOOL)autoStop
                 handler:(void (^)(id data, int errorCode))completionHandler;


/// 通用设备获取设置接口
/// @param op 操作码
/// @param param 参数
/// @param completionHandler 回调
- (void)setDeviceConfigJson:(int)op
                      param:(NSMutableDictionary *)param
                   autoStop:(BOOL)autoStop
                    handler:(void (^)(id data, int errorCode))completionHandler;
@end
