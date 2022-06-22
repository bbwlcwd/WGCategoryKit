//
//  UMMallClient.h
//  UMAccount
//
//  Created by fred on 2020/7/21.
//

#import <Foundation/Foundation.h>

@interface UMMallClient : NSObject
/// 初始化账号服务，基础模块自动调用
+ (void)startSDK:(NSString *)host port:(int)port;

/// 商城H5基础地址
+ (NSString *)mallHost;

/// 商城首页地址
+ (NSString *)mallMainHost;
    
/// 商城订单列表地址
+ (NSString *)mallOrderHost;
@end

