//
//  HKSDeviceClient+MP4.h
//  IPHKPlayer
//
//  Created by HSKJ on 14-6-5.
//
//

#import "HKSDeviceClient.h"

/**
 *  @brief  本地MP4文件播放控制类
 */
@interface HKSDeviceClient (MP4)

/**
 *  @brief  根据mp4文件录像获取当前文件帧率
 *
 *  @param[in]  theMp4FilePath[NSString] 文件路径
 */
- (int)getMp4FileInforFPS:(NSString *)theMp4FilePath;


/**
 *  @brief  设置播放帧率
 *
 *  @param[in]  fps[int] 帧率
 */
- (void)setControlSpeed:(int)fps;


/**
 *  @brief  暂停播放
 *
 */
- (void)pause;

/**
 *  @brief  恢复播放
 *
 */
- (void)resume;


/**
 *  @brief  跳转
 *
 *  @param[in]  date[Date_Time] 跳转时间
 */
- (void)seek:(Date_Time)date;
@end
