

#import "HKSDeviceClient.h"

/** @brief  设备对讲功能类 */
@interface HKSDeviceClient (Talkback)

/// 开启对讲
/// @param chNo 通道号,从0开始，-1：对当前连接通道发起对讲,前端对讲：20000+，广播对讲：30000+
/// @param type 音频类型,请参考HKS_NPC_D_AUDIO_*定义
- (int)startTalk:(int)chNo
            type:(int)type;

- (int)startPPTTalk;

- (int)startPPTTalkWithType:(int)type UMP2PDeprecated("该接口已过时,startTalk");

- (int)startPPTTalkWithType:(int)type
              audioRecorder:(BOOL)audioRecorder
           soundGainMltiple:(float)aSoundGainMltiple;
/**
 @brief  开启对讲
 
 @param  audioRecorder[BOOL]    是否启动SDK自带录音和发送功能，如果需要做回音消除请传递NO，调用sendTalkAudioData发送数据
 @return [int]返回执行状态，请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)startPPTTalk:(BOOL)audioRecorder;


/**
    @brief  关闭对讲
    @return [int]返回执行状态，请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)stopPPTTalk;

/**
 @brief  发送对讲数据,PCM类型
 */
- (void)sendTalkAudioData:(unsigned char *)data len:(int)len;

@end
