//
//  HKSDeviceAlarmMailItem.h
//  UMCloud
//
//  Created by UMEYE on 16/4/25.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceAlarmMailItem : NSObject

@property(nonatomic, assign) BOOL bEnable;

@property(nonatomic, copy) NSString *sEMailServerName;
@property(nonatomic, copy) NSString *sUserName;
@property(nonatomic, copy) NSString *sUserPwd;

@property(nonatomic, assign) BOOL bAanonymity;

@property(nonatomic, assign) int iPort;

@property(nonatomic, copy) NSString *sReceiverEMails;

@property(nonatomic, copy) NSString *sSendEMail;
@property(nonatomic, copy) NSString *sTitle;


@property(nonatomic, assign) BOOL bEnableSSL;

@end
