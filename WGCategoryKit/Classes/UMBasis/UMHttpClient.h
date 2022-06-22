//
//  UMHttpClient.h
//  UMBasis
//
//  Created by fred on 2019/7/30.
//  Copyright © 2019 UMEYE.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UMHttpClient : NSObject
/// 是否接受无效的证书,缺省YES
@property (nonatomic, assign) BOOL allowInvalidCertificates;
/// 是否匹配域名,缺省NO
@property (nonatomic, assign) BOOL validatesDomainName;

@property (nonatomic, assign) BOOL asyncEnable;
/// 创建一个client
+ (UMHttpClient *)setup:(NSString *)host
                    ssl:(BOOL)ssl
                    crt:(NSString *)crt;

+ (NSMutableArray *)ipListAtHost:(NSString *)host;

/// Post请求
- (void)postDataWithURL:(NSString *)url
             parameters:(NSDictionary *)parameter
                success:(void (^)(id data))success
                failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
