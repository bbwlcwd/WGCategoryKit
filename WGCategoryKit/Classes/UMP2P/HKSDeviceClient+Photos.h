
#import "HKSDeviceClient.h"

/**
 *  @brief  抓拍图片、录制mp4视频功能类
 */
@interface HKSDeviceClient (Photos)


/**
 *  @brief  开始本地MP4录制
 *  @param[in]  path[NSString] 文件保存位置
 *
 *  @since v1.0.0.0
 */
- (void)startRecordToPath:(NSString *)path;


/**
 *  @brief  结束本地MP4录制
 *
 *  @param[in]  block[BOOL]:阻塞线程控制，YES：阻塞，NO：不阻塞
 *  @since v1.0.0.0
 */
- (NSString *)stopLocalMP4REC:(BOOL)block;
- (NSString *)stopRecordToPath;

- (void)pauseRecord:(BOOL)isPause;


/**
 *  @brief  本地抓拍
 *
 *  @param[in]  path[NSString]      文件保存位置
 *  @param[in]  bIfSavePhoto[BOOL]  保存一份到手机系统相册
 *  @since v1.0.0.0
 */
- (void)savePhotosToPath:(NSString *)path;
- (void)savePhotosToPath:(NSString *)path bIfSavePhoto:(BOOL)bIfSavePhoto;
@end
