//
//  UMHLSDownloadClient.h
//  UMHLS-下载相关
//
//  Created by fred on 2020/2/22.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, UMHLSClientDownloadStatus) {
    /// 初始
    UMHLSClientDownloadStatusReady = 0,
    /// 下载中
    UMHLSClientDownloadStatusDownloading,
    /// 下载完成，合并中
    UMHLSClientDownloadStatusCombine,
    /// 下载结束
    UMHLSClientDownloadStatusEnd,
    /// 下载停止
    UMHLSClientDownloadStatusStop,
    /// 下载失败
    UMHLSClientDownloadStatusFailed,
};

NS_ASSUME_NONNULL_BEGIN
@protocol UMHLSDownloadClientDelegate<NSObject>

/// 下载状态
/// @param client 下载对象
/// @param status 下载状态
/// @param progress 下载进度
/// @param filePath 保存的文件路径
- (void)umHLSDownloadStatus:(id)client
                     status:(UMHLSClientDownloadStatus)status
                   progress:(float)progress
                   filePath:(NSString *)filePath;
@end

@interface UMHLSDownloadClient : NSObject
/// 下载状态
@property (nonatomic, assign) UMHLSClientDownloadStatus status;
/// 下载进度
@property (nonatomic, assign) float progress;
/// 日志状态
@property (nonatomic, assign) BOOL logEnable;
/// 回调
@property (nonatomic, weak) id<UMHLSDownloadClientDelegate> delegate;
/// 初始化
/// @param url 下载地址
- (instancetype)initWithURL:(NSURL *)url;

/// 开始下载
/// @param aFilePath 下载的文件存放路径.如:/343/434/aa.mp4
- (void)startDownload:(NSString *)aFilePath;

/// 停止下载
- (void)stopDownload;
@end

NS_ASSUME_NONNULL_END
