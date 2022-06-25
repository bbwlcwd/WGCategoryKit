//
//  HKSDeviceStorageConfigItem.h
//  IPHKPlayer
//
//  Created by UMEYE on 14/12/9.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceStorageItem : NSObject

@property(nonatomic, assign) int iSerialNo;//序列号
@property(nonatomic, assign) unsigned long dwStorageSize;//存储容量（单位为M）
@property(nonatomic, assign) unsigned long dwRemainSize;//剩余空间（单位为M）
@end
