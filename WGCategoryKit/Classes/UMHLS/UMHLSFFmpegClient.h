//
//  UMHLSFFmpegClient.h
//  UMHLS
//
//  Created by fred on 2020/9/27.
//

#import <Foundation/Foundation.h>
#import "UMHLSDef.h"
#import "UMHLSProtocol.h"

@interface UMHLSFFmpegClient : NSObject
/// 回调
@property (nonatomic, weak) id<UMHLSClientDelegate> delegate;

/// 当前位置
@property (nonatomic, assign) NSInteger currentTime;
/// 总时长
@property (nonatomic, assign) NSInteger totalTime;
/// 已缓存总时长
@property (nonatomic, assign) NSInteger totalBuffer;
/// 状态
@property (nonatomic, assign) UMHLSClientStatus status;

@property (nonatomic, assign) UMHLSVideoGravity videoGravity;

/// 日志状态
@property (nonatomic, assign) BOOL logEnable;

@property (nonatomic, assign) BOOL audioEnable;

+ (NSString *)version;
/// 初始化播放器
/// @param url 播放地址
- (instancetype)initWithURL:(NSURL *)url;

/// 切换URL
/// @param url 播放地址
- (void)replaceCurrentURLWithPlayerURL:(NSURL *)url;

/// 视频视图
- (UIView *)view;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 停止
- (void)stop;

/// 抓拍
- (UIImage *)snapshotImage;

/// 抓拍
/// @param fileName 保存文件名称，如:a.png，可选：为nil则由SDK自动分配
- (NSString *)snapshotImage:(NSString *)fileName;

/// seek
/// @param time 时间位置,秒
- (void)seekToTime:(NSInteger)time;

/// seek
/// @param time 时间位置,秒
/// @param completionHandler 结果通知
- (void)seekToTime:(NSInteger)time completionHandler:(void (^)(BOOL finished))completionHandler;
@end
