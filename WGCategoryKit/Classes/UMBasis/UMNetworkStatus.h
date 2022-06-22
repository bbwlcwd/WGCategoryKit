//
//  UMNetworkStatus.h
//  UMBasis
//
//  Created by fred on 2020/3/9.
//  Copyright © 2020 UMEYE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, UMNetworkStatusType) {
    UMNetworkStatusUnknown          = -1,
    UMNetworkStatusNotReachable     = 0,
    UMNetworkStatusReachableViaWWAN = 1,
    UMNetworkStatusReachableViaWiFi = 2,
};
@interface UMNetworkStatus : NSObject

/// 当前连接的网络类型:wifi/wwan..
+ (UMNetworkStatusType)currentNetworkStatus;

/// 启动网络类型检测
/// @param completionHandler 通知
+ (void)startNetworkMonitor:(void (^)(UMNetworkStatusType state))completionHandler;

/// 检测是否可以连接外网
/// @param completionHandler 通知
+ (void)checkNetCanUse:(void (^)(BOOL canUse))completionHandler;

/// 是否为IPV6网络
+ (int)isIPV6Net:(NSString *)host clean:(BOOL)isClean change:(BOOL *)isChange;
/// ipv6头部
+ (char *)ipv6Head;

/// 网络检测模式
/// @param mode 1:正常模式，0：局域网网络
+ (void)setNetworkMode:(int)mode;
@end
