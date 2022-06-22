//
//  UMConfig+Utils.h
//  UMBasis
//
//  Created by fred on 2020/3/9.
//  Copyright © 2020 UMEYE.COM. All rights reserved.
//
#import "UMConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface UMConfig (Network)
/// 是否为局域网模式
@property (nonatomic, assign) BOOL localMode;
/// 是否为IPV6网络
@property (nonatomic, assign, getter=isIPV6) int ipv6;
/// 网络状态,0:无网络，1：网络正常
@property (nonatomic, assign) int networkCanUse;
@end

NS_ASSUME_NONNULL_END
