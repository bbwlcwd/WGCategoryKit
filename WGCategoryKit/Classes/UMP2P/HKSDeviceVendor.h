//
//  HKSDeviceVendor.h
//  IPHKPlayer
//
//  Created by George on 13-7-15.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceVendor : NSObject
@property(nonatomic) int                iVendorId;      //厂家ID
@property(nonatomic, strong) NSString   *sVendorName;   //厂家名称

@end
