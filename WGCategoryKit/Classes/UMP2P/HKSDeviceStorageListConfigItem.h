//
//  HKSDeviceStorageListConfigItem.h
//  IPHKPlayer
//
//  Created by UMEYE on 14/12/9.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceStorageListConfigItem : NSObject
@property(nonatomic, assign) unsigned int iStorageNum;//存储块数
@property(nonatomic, strong) NSMutableArray *tStorages;//分区列表[HKSDeviceStorageItem]
@end
