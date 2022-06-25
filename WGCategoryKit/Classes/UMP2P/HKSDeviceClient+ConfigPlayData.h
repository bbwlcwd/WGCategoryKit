///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

#import "HKSDeviceClient.h"
@class HKSRecFile;

/**
 *  @brief   初始化设备连接信息接口类
 */
@interface HKSDeviceClient (ConfigPlayData)

/// 设置设备连接数据
/// @param params 设备连接数据对象
- (void)setDeviceConnParam:(id)params;

/// 初始化接口,远程回放
/// @param theRecFile 远程回放数据对象
- (void)setRecFileConnParam:(HKSRecFile *)theRecFile;

/**
 * @brief   设置设备连接数据,通过umid方式播放
 *
 * @param[in]   serverIP[NSString] 服务器地址
 * @param[in]   serverPort[int] 服务器端口
 * @param[in]   deviceUMID[NSString] 设备UMID
 * @param[in]   deviceAddress[NSString] 设备直连地址
 * @param[in]   devicePort[int] 设备直连端口
 * @param[in]   deviceUserID[NSString] 设备用户
 * @param[in]   devicePassword[NSString] 设备密码
 * @param[in]   [int]deviceChannel 设备通道，从0开始
 * @param[in]   [int]deviceStream 播放码流，0：主码流，1：子码流
 * @param[in]   [int]deviceVendor 设备厂家，-1：底层智能识别，其他请参考HKS_NPC_D_MON_VENDOR_ID_*,暂时只支持穿透模式，ip直连需要自己填写。
 */
- (void)setDeviceConnParam:(NSString *)serverIP
                serverPort:(int)serverPort
                deviceUMID:(NSString *)deviceUMID
              deviceUserID:(NSString *)deviceUserID
            devicePassword:(NSString *)devicePassword
             deviceChannel:(int)deviceChannel
              deviceStream:(int)deviceStream
              deviceVendor:(int)deviceVendor UMP2PDeprecated("该接口已过时");

/**
 * @brief   设置设备连接数据,通过umid方式播放
 *
 * @param[in]   serverIP[NSString] 服务器地址
 * @param[in]   serverPort[int] 服务器端口
 * @param[in]   deviceUMID[NSString] 设备UMID
 * @param[in]   deviceAddress[NSString] 设备直连地址
 * @param[in]   devicePort[int] 设备直连端口
 * @param[in]   deviceUserID[NSString] 设备用户
 * @param[in]   devicePassword[NSString] 设备密码
 * @param[in]   [int]deviceChannel 设备通道，从0开始
 * @param[in]   [int]deviceStream 播放码流，0：主码流，1：子码流
 * @param[in]   [int]deviceConnType 连接类型:HKS_NPC_D_MON_DEV_CONN_MODE_*
 * @param[in]   [int]deviceVendor 设备厂家，-1：底层智能识别，其他请参考HKS_NPC_D_MON_VENDOR_ID_*,暂时只支持穿透模式，ip直连需要自己填写。
 */
- (void)setDeviceConnParam:(NSString *)serverIP
                serverPort:(int)serverPort
                deviceUMID:(NSString *)deviceUMID
             deviceAddress:(NSString *)deviceAddress
                devicePort:(int)devicePort
              deviceUserID:(NSString *)deviceUserID
            devicePassword:(NSString *)devicePassword
             deviceChannel:(int)deviceChannel
              deviceStream:(int)deviceStream
            deviceConnType:(int)deviceConnType
              deviceVendor:(int)deviceVendor UMP2PDeprecated("该接口已过时");

/**
 *  @brief  初始化接口,通过设备id方式播放
 *
 *  @param[in]   theDevice[TreeListItem]设备连接数据对象
 *  @param[in]   theConnType[int]设备连接类型,请参考HKS_NPC_D_MON_CLIENT_MODE_*
 */
- (void)setDeviceConnParam:(TreeListItem *)theDevice
                      type:(int)theConnType UMP2PDeprecated("该接口已过时");
@end
