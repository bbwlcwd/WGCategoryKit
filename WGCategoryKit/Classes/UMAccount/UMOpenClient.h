//
//  UMOpenClient.h
//  UM
//
//  Created by fred on 2019/7/30.
//  Copyright © 2019 Fred. All rights reserved.
//  UMGOpen API模块

#import <Foundation/Foundation.h>

@interface UMOpenClient : NSObject

#pragma mark -
/// 初始化账号服务，基础模块自动调用
+ (void)startSDK:(NSString *)host port:(int)port;
///  获取app鉴权数据
+ (NSDictionary *)getAppAuthData;

/// 通用接口
/// @param path 路径
/// @param ver 版本
/// @param linkId 关联ID,如用户ID
/// @param parameters 请求数据
/// @param completionHandler 回调
+ (void)asyncSendRequest:(NSString *)path
                     ver:(NSString *)ver
                  linkId:(NSString *)linkId
              parameters:(NSDictionary *)parameters
                 handler:(void (^)(id data, NSError *error))completionHandler;


+ (void)asyncSendRequest:(NSString *)path
                     ver:(NSString *)ver
                  linkId:(NSString *)linkId
              parameters:(NSDictionary *)parameters
             respHandler:(void (^)(id resp, NSError *error))completionHandler;

/// 通用接口
/// @param path 路径
/// @param ver 版本
/// @param parameters 请求数据
/// @param completionHandler 回调
+ (void)asyncSendRequest:(NSString *)path
                     ver:(NSString *)ver
              parameters:(NSDictionary *)parameters
                 handler:(void (^)(id data, NSError *error))completionHandler;

/// 根据文件ID查询文件详情
+ (void)fileAtFileId:(NSString *)userId
              fileId:(NSString *)fileId
             handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

/// 根据文件ID列表查下文件列表详情
+ (void)fileListAtFileId:(NSString *)userId
                 fileIds:(NSMutableArray *)fileIds
                 handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

@end
