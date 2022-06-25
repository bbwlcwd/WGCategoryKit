//
//  HKSDeviceClient+Tools.h
//  Created by Fred on 10-8-18.
//  Copyright 2010 UMEYE. All rights reserved.
//
//

#import "HKSDeviceClient.h"

@interface HKSDeviceClient (PreConnection)

/**
 *  @brief      预连接，加快播放设备速度
 *  @param[in]  aDevices[NSMutableArray->TreeListItem]  设备列表
 *  @since v2.7.3.1
 */
+ (void)devicePreConnection:(NSMutableArray *)aDevices;

/**     @brief  开始预连接   */
+ (void)startPreConnClient;
/**     @brief  停止预连接   */
+ (void)stopPreConnClient;
@end
