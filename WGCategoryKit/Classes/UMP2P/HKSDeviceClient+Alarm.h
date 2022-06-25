
#import "HKSDeviceClient.h"

/**
 *  @brief      摄像机报警信息接口。通过HKSDeviceClient调用(camear alarm info function interface class)
 */
@interface HKSDeviceClient (Alarm)


/**
 *  @brief  实时预览摄像机的时候，开启接收摄像机的报警信息
 *
 *  @since v2.3.4.1
 */
- (BOOL)startCameraAlarmInfo;


/**
 *  @brief  实时预览摄像机的时候，停止接收摄像机的报警信息
 *
 *  @since v2.3.4.1
 */
- (void)stopCameraAlarmInfo;
@end
