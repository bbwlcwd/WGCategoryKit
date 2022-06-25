//
//  UMHLSDef.h
//  UMHLS
//
//  Created by fred on 2020/9/28.
//

#ifndef UMHLSDef_h
#define UMHLSDef_h

#define kUMHLSVer @"1.3.2"

typedef NS_ENUM(NSInteger, UMHLSClientStatus) {
    /// 初始
    UMHLSClientStatusUnknown = 0,
    /// 连接中
    UMHLSClientStatusConnecting,
    /// 缓存完成，准备播放
    UMHLSClientStatusReadyToPlay,
    /// 失败
    UMHLSClientStatusFailed,
    /// 缓冲中
    UMHLSClientStatusBuffering,
    /// 播放中
    UMHLSClientStatusPlaying,
    /// 暂停
    UMHLSClientStatusPause,
    /// 停止
    UMHLSClientStatusStoping,
    UMHLSClientStatusStop,
    /// 结束
    UMHLSClientStatusEnd,
};

typedef NS_ENUM(NSInteger, UMHLSVideoGravity) {
    /// 等比例填充，直到一个维度到达区域边界
    UMHLSVideoGravityResizeAspect = 0,
    /// 等比例填充，直到填充满整个视图区域，其中一个维度的部分区域会被裁剪
    UMHLSVideoGravityResizeAspectFill,
    /// 非均匀模式。两个维度完全填充至整个视图区域
    UMHLSVideoGravityResize,
};

#endif /* UMHLSDef_h */
