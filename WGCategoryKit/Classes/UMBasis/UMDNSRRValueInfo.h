//
//  UMDNSRRValueInfo.h
//  UMBasis
//
//  Created by fred on 2019/7/31.
//  Copyright © 2019 UMEYE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMDNSRRValueInfo : NSObject<NSCopying>
@property (nonatomic, copy) NSString *user_id;

@property (nonatomic, copy) NSString *auth_ip;
@property (nonatomic, assign) int auth_port;

@property (nonatomic, copy) NSString *ust_ip;
@property (nonatomic, assign) int ust_port;

@property (nonatomic, copy) NSString *ssl_domain;
@property (nonatomic, assign) int http_port;
@property (nonatomic, assign) int ssl_port;

@property (nonatomic, copy) NSString *umh_ip;
@property (nonatomic, copy) NSString *umh_domain;
@property (nonatomic, assign) int umh_port;

@property (nonatomic, copy) NSString *cloud_ip;
@property (nonatomic, assign) int cloud_port;

@property (nonatomic, copy) NSString *pay_ip;
@property (nonatomic, assign) int pay_port;

@property (nonatomic, copy) NSString *client_ip;

@property (nonatomic, copy) NSString *open_ip;
@property (nonatomic, assign) int open_port;

@property (nonatomic, assign) NSTimeInterval timestamp;
+ (instancetype)setup:(NSDictionary *)params;
@end

NS_ASSUME_NONNULL_END
