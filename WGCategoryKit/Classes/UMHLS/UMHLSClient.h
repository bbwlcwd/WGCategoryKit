//
//  UMHLSClient.h
//  UMHLS-播放相关
//
//  Version 1.0.0
//  Created by Fred on 2020/2/17.
//  Copyright © 2020年 UMEye.com. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UMHLSDef.h"
#import "UMHLSProtocol.h"

@interface UMHLSClient : NSObject

/// 0：暂停，1：正常速度，注意：播放中设置才有效
@property (nonatomic, assign) float rate;
/// 当前位置
@property (nonatomic, assign) NSInteger currentTime;
/// 总时长
@property (nonatomic, assign) NSInteger totalTime;
/// 已缓存总时长
@property (nonatomic, assign) NSInteger totalBuffer;
/// 状态
@property (nonatomic, assign) UMHLSClientStatus status;
/// 日志状态
@property (nonatomic, assign) BOOL logEnable;
/// 回调
@property (nonatomic, weak) id<UMHLSClientDelegate> delegate;
/// 视频拉伸方式
@property (nonatomic, assign) UMHLSVideoGravity videoGravity;

+ (NSString *)version;

/// 初始化播放器
/// @param url 播放地址
- (instancetype)initWithURL:(NSURL *)url;

/// 视频视图
- (UIView *)view;

/// 切换URL
/// @param url 播放地址
- (void)replaceCurrentURLWithPlayerURL:(NSURL *)url;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 停止
- (void)stop;

/// 抓拍
- (UIImage *)snapshotImage;

/// seek
/// @param time 时间位置,秒
- (void)seekToTime:(NSInteger)time;

/// seek
/// @param time 时间位置,秒
/// @param completionHandler 结果通知
- (void)seekToTime:(NSInteger)time completionHandler:(void (^)(BOOL finished))completionHandler;


@end


