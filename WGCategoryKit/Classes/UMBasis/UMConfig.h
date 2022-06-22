//
//  UMConfig.h
//  UMBasis
//
//  Created by fred on 2019/5/14.
//  Copyright © 2019 UMEYE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UMConfigDef.h"

@interface UMConfig : NSObject
/// 服务器连接信息,缺省值:v0p2p.umeye.com
@property (nonatomic, copy) NSString *host;
/// 服务器连接信息,缺省值:8888/8443
@property (nonatomic, assign) int port;
/// 备用服务器ip,域名解析失败的情况下使用
@property (nonatomic, copy) NSString *backupIp;
/// 是否启动账号模块，缺省:YES
@property (nonatomic, assign) BOOL accountEnable;
/// APP唯一识别码(客户端定制标识)
@property (nonatomic, copy) NSString *appId;
/// 语言类型,自动只识别中/英,需要支持其他语言需根据服务器支持语言列表手动进行设置
@property (nonatomic, assign) UM_WEB_API_WS_LANG_TYPE langId;
/// 是否开启SSL，缺省:NO
@property (nonatomic, assign) BOOL sslEnable;
/// ssl crt证书名称,缺省值:umssl
@property (nonatomic, copy) NSString *crtFileName;
/// 是否开启推送,作用于未使用UM账号模式,缺省:NO
@property (nonatomic, assign) BOOL pushEnable;
/// 是否启动Log,缺省:NO
@property (nonatomic, assign) BOOL logEnable;
@property (nonatomic, assign) BOOL logDevEnable;
/// 最优服务器模块启用状态
@property (nonatomic, assign) BOOL umhBestEnable;
@property (nonatomic, assign) BOOL ustBestEnable;
///  异步请求，默认:NO
@property (nonatomic, assign) BOOL asyncEnable;
/// 自动局域网模式，默认：YES
@property (nonatomic, assign) BOOL autoLocal;
/// UM体系的用户服务类型，缺省:UMServerP2P
@property (nonatomic, assign) UMServerType type;
/// 协议类型,0:HTTP POST
@property (nonatomic, assign) int protocol;
/// 版本号
@property (nonatomic, assign) int apiVer;
/// 手机唯一识别码，支持自动生成
@property (nonatomic, copy) NSString *clientId;
/// 客户端类型
@property (nonatomic, assign, readonly) int clientType;
/// 请求头,http/https,
@property (nonatomic, copy, readonly) NSString *httpHead;
/// http服务请求地址，SDK内部根据服务器连接信息拼接得到
@property (nonatomic, copy, readonly) NSString *httpURL;
/// APP包名
@property (nonatomic, copy, readonly) NSString *bundleIdentifier;
/// 无账号系统推送模式
@property (nonatomic, assign, readonly) BOOL noAccountPushMode;
@property (nonatomic, assign) int timeoutInterval;
/// SDK启动状态,0:未初始化,1:初始化中,2:初始化完成
@property (nonatomic, assign) int sdkState;
/// 最优服务地址缓存时间，默认60s,最大为12*3600，最少为60
@property (nonatomic, assign) int addrCacheTime;
/// 云存储平台类型，0：不支持云存储，2：阿里云OSS，3：AWS,缺省:0
@property (nonatomic, assign) int oss_type;
/// app版本号
@property (nonatomic, copy, readonly) NSString *appVer;


/// 获取配置句柄
+ (UMConfig *)builder;

/// 启动SDK
+ (void)startSDK:(NSString *)appid;

/// 版本号
+ (NSString *)version;
@end
