//
//  HKSWIFIAPItem.h
//  IPHKPlayer
//
//  Created by HSKJ on 14-4-15.
//
//

#import <Foundation/Foundation.h>

@interface HKSWIFIAPItem : NSObject

@property(nonatomic, copy) NSString *sSSID;//SSID（必填）
@property(nonatomic, copy) NSString *sAuthType;//安全类型（可选）
@property(nonatomic, copy) NSString *sEncrypType;//加密类型（可选）
@property(nonatomic, assign) int iChannel;//信道号（可选）
@property(nonatomic, assign) int iRSSI;////信号强度（可选），值范围为0~100，0为信号最低，100为信号最强
@end
