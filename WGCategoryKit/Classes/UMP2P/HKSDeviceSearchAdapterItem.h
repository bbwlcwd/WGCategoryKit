//
//  HKSDeviceSearchAdapterItem.h
//  IPHKPlayer
//
//  Created by George on 13-8-9.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceSearchAdapterItem : NSObject

@property(nonatomic, assign) BOOL bDhcpEnable;
@property(nonatomic, copy) NSString *sAdapterName;//网卡名称
@property(nonatomic, copy) NSString *sAdapterMac;//网卡MAC地址，格式为XX-XX-
@property(nonatomic, copy) NSString *sIpaddr;//IP地址
@property(nonatomic, copy) NSString *sNetmask;//子网掩码
@property(nonatomic, copy) NSString *sGateway;//网关地址
@property(nonatomic, assign) int iIpConnMode;
@end
