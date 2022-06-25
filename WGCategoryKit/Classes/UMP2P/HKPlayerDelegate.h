
/**
 *  @class      HKPlayerDelegate<NSObject>
 *  @brief      播放内核相关回调接口
 */
@protocol HKPlayerDelegate<NSObject>
@optional
/// 播放状态发生改变
- (void)playerFeedback:(id)player status:(int)status;
/// 连接中
- (void)playerFeedbackConnect:(id)player;
/// 播放成功
- (void)playerFeedbackPlaying:(id)player;
/// 播放出错
- (void)playerFeedbackError:(id)player error:(NSError *)error;

/// 对讲连接中
- (void)playerTalkConnect:(id)player;
/// 对讲成功
- (void)playerTalkSuccess:(id)player;
/// 对讲结束
- (void)playerTalkStop:(id)player;
/// 对讲出错
- (void)playerTalkError:(id)player error:(NSError *)error;


/**
 *  @brief      远程回放回调接口
 *
 *  @param[in]  player[HKSDeviceCliet]  播放内核
 *  @param[in]  status[int]             当前文件的总时间
 *  @param[in]  pts[long]               当前播放位置的时间
 */
- (void)playerFeedback:(id)player status:(int)status pts:(long)pts UMP2PDeprecated("请使用playerFeedback:status:currentTime:totalTime:接口，该接口已过时");


/**
 *  @brief      远程、本地回放回调接口
 *
 *  @param[in]  player[HKSDeviceCliet]  播放内核
 *  @param[in]  status[int]             状态,0：非结束帧，1：最后一帧，2：停止流标志（因播放完或错误导致停止）。（实时预览和录像回放有效，如果是实时预览，值为2表示请求显示层关闭解码器，重新打开解码器）
 *  @param[in]  currentTime[long]       当前播放位置的时间
 *  @param[in]  totalTime[long]         当前文件的总时间
 */
- (void)playerFeedback:(id)player status:(int)status currentTime:(long)aCurrentTime totalTime:(long)aTotalTime;

- (void)playerFeedback:(id)player status:(int)status pos:(long)aPos timestamp:(long)aTimestamp totalTime:(long)aTotalTime;

/**
 *  @brief      下载文件回调接口，注意：两个接口只需要实现一个
 *  @param[in]  player[HKSDeviceCliet]  播放内核
 *  @param[in]  status[int]             下载状态
 *  @param[in]  iPercent[int]           下载百分比(0-100)
 *  @param[in]  aImage[UIImage]         下载文件类型为图片的时候，把下载好的图片数据转成成UIImage以后，返回给上层
 */
- (void)playerFeedback:(id)player status:(int)status downSize:(int)size percent:(int)iPercent;

- (void)playerFeedback:(id)player status:(int)status downSize:(int)size percent:(int)iPercent image:(UIImage *)aImage;

/**
 *  @brief      本地录像回调
 *  @param[in]  player[HKSDeviceCliet]  播放内核
 *  @param[in]  aFileName[NSString]     文件名称
 *  @param[in]  aStatus[int]            状态：1:找到第一个I帧，开始进行录像,2:编码格式发生了改变，导致重新录像,3:超过设置的最大时间,4:录像时间少于最少的录制时长
 */
- (void)playerFeedback:(id)player fileName:(NSString *)aFileName status:(int)aStatus;

@end
