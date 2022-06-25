//
//  UMUSTSDK.h
//  UMUSTSDK
//
//  Created by fred on 2020/1/16.
//  Copyright © 2020 UMEye.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UMUSTSDK : NSObject

/// 启动SDK
+ (void)startSDK:(NSString *)ip port:(int)port;

/// 停止SDK
+ (void)stopSDK;

/// 重置SDK
/// @param ip UST服务器IP
/// @param port UST服务器Port
+ (void)resetSDK:(NSString *)ip port:(int)port;
+ (void)resetSDK;

/// 配置联网模式
/// @param localMode 是否为局域网模式
+ (void)setLocalMode:(BOOL)localMode;

/// 设置强制转发
/// @param enable   是否开启强制转发
/// @param sysId    体系标识
+ (void)setTransConn:(BOOL)enable
               sysId:(NSString *)sysId;

/// 设置包头标识模式
/// @param mode 1:固定，2：随机
+ (void)setPacketFlagMode:(int)mode;

/// 设置加密类型
/// @param type 0:不加密，2：加密
+ (void)setDataEncrypt:(int)type;

/// 连接状态,0：未连接，1：正在连接，2：已连接
+ (int)connState;

/// 配置设备定制标识
/// @param devCustomFlag 定制标识参数
/// @param devCustomNum 定制标识数量
+ (void)setDevCustomFlag:(NSString *)devCustomFlag
            devCustomNum:(int)devCustomNum;

/// 配置参数
/// @param sDeviceVendorFlag 摄像头设备厂家，参考：HKS_NPC_D_MON_DEV_VENDOR_*
/// @param devCustomFlag 设备标识
/// @param devCustomNum 设备标识数
+ (void)setCustomVendorFlag:(NSString *)devVendorFlag
              devCustomFlag:(NSString *)devCustomFlag
               devCustomNum:(int)devCustomNum;

/// 设备鉴权加密方式
/// @param type 0:通过协议自动处理，10：强制MD5加密
+ (void)setDeviceEncrypt:(int)type;


/// 是否开启本地UDP
+ (void)setLocalUdp:(BOOL)aLocalUdp;

/// 开启日志
/// @param log 是否启动
+ (void)setLog:(BOOL)log;

/// 版本号
+ (NSString *)version;

/// 服务器地址
+ (NSString *)host;

/// 配置转发ID
+ (void)setPrivateTransId:(int)enterId;

+ (void)setConnStateTask:(void (^)(int state))completionHandler;

+ (void)setSearchSrvList:(NSMutableArray  *)srvLists;
@end

