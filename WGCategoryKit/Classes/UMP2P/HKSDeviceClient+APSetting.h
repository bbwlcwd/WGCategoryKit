//
//  HKSDeviceClient+APSetting.h
//  UMCloud
//
//  Created by UMEYE on 16/4/14.
//
//

#import "HKSDeviceClient.h"

enum{
    UM_DEVICE_AP_TYPE_HZYX = 1,
    UM_DEVICE_AP_TYPE_GZHY = 2,
    UM_DEVICE_AP_TYPE_MTK = 3,
    UM_DEVICE_AP_TYPE_TS = 4,
};
/** @brief  type  */
typedef int UM_DEVICE_AP_TYPE;
/**
 *  @brief      smart wifi 功能类
 */
@interface HKSDeviceClient (APSetting)
/**
 *  @brief      wifi配置工具
 *
 *  @param[in]  aSSID[NSString]wifi的ssid
 *  @param[in]  aPwd[NSString]wifi的密码
 *  @param[in]  aType[UM_DEVICE_AP_TYPE] 厂家类型
 */
+ (void)setDeviceSSID:(NSString *)aSSID password:(NSString *)aPwd type:(UM_DEVICE_AP_TYPE)aType;
+ (void)setDeviceSSID:(NSString *)aSSID password:(NSString *)aPwd type:(UM_DEVICE_AP_TYPE)aType encoding:(NSStringEncoding)encoding;
/**
 *  @brief      wifi配置工具状态
 *
 *  @return     [BOOL]当前状态，1:正在配置中，0：配置结束,2：配置失败
 */
+ (int)settingsStatus;


/**
 *  @brief      停止wifi配置工具
 */
+ (void)stopSetDeviceSSID;


+ (void)setStatusCallback:(SEL)aCallback delegate:(id)aDelegate;

@end
