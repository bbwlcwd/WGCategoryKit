//
//  UMDNSClient.h
//  UMBasis
//
//  Created by fred on 2019/7/30.
//  Copyright © 2019 UMEYE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UMDNSRRValueInfo.h"

@interface UMDNSClient : NSObject

#pragma mark -
/// 所有服务模块的IP、Port记录值
+ (void)rrValue:(NSString *)userId
        handler:(void (^)(UMDNSRRValueInfo *data, NSError *error))completionHandler;

+ (void)rrValue:(NSString *)userId
             ip:(NSString *)ip
        handler:(void (^)(UMDNSRRValueInfo *data, NSError *error))completionHandler;

+ (void)rrValue:(NSString *)userId
             ip:(NSString *)ip
           mode:(int)mode
        handler:(void (^)(UMDNSRRValueInfo *data, NSError *error))completionHandler;

+ (NSObject *)rrValue:(NSString *)userId
                   ip:(NSString *)ip;

/// 清除缓存
+ (void)cleanRRValueCache:(NSString *)userId;

#pragma mark - 临时接口，请勿使用
/*
 param:
 @{
    @"app_id" : @"2000000",
    @"app_key" : @"com.umeye.app" ,
    @"client_id" : @"DFDFDFDFD" ,
    @"client_type" : @(2),
    @"no_login_mode" : @(0),
    @"user_id" : @""
 }
 */
/// 查询服务器信息
/// @param url 服务器地址
/// @param param 参数
/// @param completionHandler 回调
+ (void)rrValue:(NSString *)url
          param:(NSDictionary *)param
        handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;
@end

