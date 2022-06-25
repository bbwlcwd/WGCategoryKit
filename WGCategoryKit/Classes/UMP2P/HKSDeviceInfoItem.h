//
//  HKSDeviceInfoItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/12.
//
//

#import <Foundation/Foundation.h>



///#begin zh-cn
/**
 *  @class      HKSDeviceInfoItem
 *  @brief      设备信息对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceInfoItem : NSObject

/** @brief  通道数  */
@property(nonatomic, assign) int        iChannel;

/** @brief  P2P序列号，  */
@property(nonatomic, strong) NSString   *cloudSerial;

/** @brief  类型；如:DVR；IPC；NVR等  */
@property(nonatomic, strong) NSString   *devType;

/** @brief  型号，厂家自定义  */
@property(nonatomic, strong) NSString   *devModel;

/** @brief  P2P主程序版本号，可从NTS的配置文件中获取  */
@property(nonatomic, strong) NSString   *cloudVersion;

/** @brief  设备的系统固件版本号，由厂家自定义  */
@property(nonatomic, strong) NSString   *devVersion;


/** @brief  当前版本的发布时间  */
@property(nonatomic, strong) NSString   *sBuildTime;

/** @brief  云连接状态，0：未连接；1：正在连接；2：已连接；3：连接失败；4：域名解析失败；5：连接服务器失败；6：非法ID；7.重复ID，当前ID有设备在使用  */
@property(nonatomic, assign) int        cloudStatus;

@property(nonatomic, assign) int        cloudDevVerNo;

@property(nonatomic, assign) int        iRunTime;//分

@end
