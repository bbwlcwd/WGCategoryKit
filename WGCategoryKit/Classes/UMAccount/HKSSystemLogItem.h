//
//  HKSDeviceSystemEvent.h
//  IPHKPlayer
//
//  Created by HSKJ on 14-5-19.
//
//

#import <Foundation/Foundation.h>

@interface HKSSystemLogItem : NSObject

@property(nonatomic, copy) NSString *sMsgId;
@property(nonatomic, copy) NSString *sMsgTime;
@property(nonatomic, copy) NSString *sMsgTitle;
@property(nonatomic, copy) NSString *sMsgContent;
@property(nonatomic, assign) BOOL   isRead;
@end
