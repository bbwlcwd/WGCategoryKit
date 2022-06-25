//
//  HKSDeviceWIFIItem.h
//  IPHKPlayer
//
//  Created by HSKJ on 14-4-14.
//
//

#import <Foundation/Foundation.h>
#import "HKSWIFIAPItem.h"
@interface HKSDeviceWIFIItem : HKSWIFIAPItem
@property(nonatomic, strong) NSString       *sNetcardName;
@property(nonatomic, strong) NSString       *sMac;
@property(nonatomic, assign) int            bEnable;
@property(nonatomic, strong) NSString       *sWifiSSID;
@property(nonatomic, strong) NSString       *sWifiPwd;
@property(nonatomic, assign) int            bIfSetNetParam;
@property(nonatomic, assign) int            bDhcpEnable;
@property(nonatomic, strong) NSString       *sIpaddr;
@property(nonatomic, strong) NSString       *sNetmask;
@property(nonatomic, strong) NSString       *sGateway;


@property(nonatomic, assign) int bFieldEnable_AuthType;//字段使能：安全类型，TRUE表示sAuthType字段有效，否则无效，下同
@property(nonatomic, assign) int bFieldEnable_EncrypType;//字段使能：加密类型
@property(nonatomic, assign) int bFieldEnable_Channel;//字段使能：信道号
@property(nonatomic, assign) int bFieldEnable_RSSI;//字段使能：信号强度
@end
