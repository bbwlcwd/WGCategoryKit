

#import "HKSDeviceClient.h"


/**
 *  @brief      设备视频数据相关控制接口
 */
@interface HKSDeviceClient (ControlMedia)


/**
 *  @brief       控制媒体流（暂停或继续），暂停后，服务器将不再发送媒体数据给客户端
 *
 *  @param[in]   ctrlOrder[int]控制命令，0：暂停，1：继续
 *  @param[in]   mediaType[int]媒体类型，0：视频，1：音频
 *  @return      [int]返回0表示成功，其它为失败
 *  @since       v1.0.0.0
 */
- (int)controlMediaStream:(int)ctrlOrder mediaType:(int)mediaType;


/**
 *  @brief       快进慢放控制
 *
 *  @param[in]   in_iCtrlCode[int]  操作类型：0=恢复正常速度，1为快放，-1为慢放
 *  @param[in]   in_iCtrlParam[int] 倍数，0：正常，1：2倍数，2：4倍数，3：8倍数，4：16倍数，5：32倍数
 *  @return      [int]返回0表示成功，其它为失败
 *  @since       v1.0.0.0
 */
- (int)controlPlaybackSpeed:(int)in_iCtrlCode
                      param:(int)in_iCtrlParam;

/// 控制播放
/// @param in_iCtrlCode 控制码，请参考HKS_NPC_D_MON_PLAY_CTRL_*
/// @param in_iData 控制参数，根据控制码确定值含义
- (int)controlRecord:(int)in_iCtrlCode
                data:(int)in_iData;

/**
 *  @brief       请求只发I帧或恢复发送全帧，恢复发送全帧后，会从I帧开始发送，该函数不具有强制I帧功能
 *
 *  @param[in]   in_iCtrlCode[int] 控制码，0：只发I帧，1：恢复发送全帧
 *  @return      [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since       v1.0.0.0
 */
- (int)controlCameraOnlyIFrame:(int)in_iCtrlCode;

/**
 *  @brief       强制I帧功能
 *
 *  @return      [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since       v2.7.1.8
 */
- (int)controlCameraRequForceIFrame;

/**
 *  @brief       切换通道\码流
 *
 *  @param[in]   in_iSwitchChNo[int] 切换后的通道号,如果只切换码流，通道号填写当前通道号
 *  @param[in]   in_iSwitchStreamNo[int] 切换后的码流号，0：主码流，1：子码流，-1表示码流号不变
 *  @return[int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 **/
- (int)controlCameraSwitchChNoStreamNo:(int)in_iSwitchChNo
                                stream:(int)in_iSwitchStreamNo;


/**
 *  @brief       查询当前通道号和码流号
 *
 *  @param[out]  out_pCurChNo[int] 输出当前通道号,从0开始
 *  @param[out]  out_pCurStreamNo[int] 输出当前码流号，0：主码流，1：子码流
 *  @return[int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 **/
- (int)getCameraChannelStreamNo:(int *)out_pCurChNo
                         stream:(int *)out_pCurStreamNo;


@end
