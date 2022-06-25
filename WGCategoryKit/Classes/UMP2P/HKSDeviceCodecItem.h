///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

//码流控制模式
enum{
    HKS_NPC_D_MON_CSD_BITRATECTRL_CBR = 1,				//固定码流
    HKS_NPC_D_MON_CSD_BITRATECTRL_VBR = 2,				//可变码流
    HKS_NPC_D_MON_CSD_BITRATECTRL_MBR = 3,				//混和码流
};
/** @brief  视频分辨率  */
typedef int HKS_NPC_D_MON_CSD_BITRATECTRL;
///#begin zh-cn
/**
 *  @class      HKSDeviceAudioFormat
 *  @brief      摄像机音频编码格式对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceAudioFormat : NSObject
/** @brief  是否开启音频  */
@property(nonatomic, assign) BOOL enabled;

/** @brief  音频编码ID，参见HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_*定义  */
@property(nonatomic, assign) HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO iCodecId;
/** @brief  比特率（kbps）  */
@property(nonatomic, assign) int iBitRate;
/** @brief  采样率  */
@property(nonatomic, assign) int iSampleRate;
/** @brief  最大音量,无效  */
@property(nonatomic, assign) int iMaxVolume;
@end

///#begin zh-cn
/**
 *  @class      HKSDeviceAudioFormat
 *  @brief      摄像机视频编码格式对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceVideoFormat : NSObject

/** @brief  是否开启视频，无效  */
@property(nonatomic, assign) BOOL enabled;

/** @brief  视频编码ID，参见HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO_*定义  */
@property(nonatomic, assign) HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO   iCodecId;

/** @brief  分辨率，参见HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_*定义  */
@property(nonatomic, assign) HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION iResolution;

/** @brief  支持的分辨率数组，参见HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_*定义  */
@property(nonatomic, strong) NSMutableArray *tSupportResolution;

/** @brief  码流控制模式，参见HKS_NPC_D_MON_CSD_BITRATECTRL_*定义  */
@property(nonatomic, assign) HKS_NPC_D_MON_CSD_BITRATECTRL      iBitRateControl;

/** @brief  视频码流（kbps）  */
@property(nonatomic, assign) int iBitRate;

/** @brief  视频帧率，取值范围根据iMinFrameRate、iMaxFrameRate决定  */
@property(nonatomic, assign) int iFrameRate;

/** @brief  视频帧率，取值范围-5~30,只读  */
@property(nonatomic, assign) int iMaxFrameRate;

/** @brief  I帧间隔  */
@property(nonatomic, assign) int iGOP;

/** @brief  图像质量，只有在可变码流下才起作用，取值1-6（很差 较差 一般 好 很好 最好），值越大，图像质量越好  */
@property(nonatomic, assign) int iQuality;

@end

///#begin zh-cn
/**
 *  @class      HKSDeviceAudioFormat
 *  @brief      摄像机编码码流对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceStreamCodecItem : NSObject



/** @brief  视频编码  */
@property(nonatomic, strong) HKSDeviceVideoFormat   *pVideoFormat;
/** @brief  音频编码  */
@property(nonatomic, strong) HKSDeviceAudioFormat   *pAudioFormat;

@end

///#begin zh-cn
/**
 *  @class      HKSDeviceAudioFormat
 *  @brief      摄像机编码对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceCodecItem : NSObject

/** @brief  通道，0开始,0xff所有通道  */
@property(nonatomic, assign) int  iChNo;
/** @brief  最大通道数  */
@property(nonatomic, assign) int  iMaxChNo;

/** @brief  码流编码<HKSDeviceStreamCodecItem>，0：主码流，1：子码流，  */
@property(nonatomic, strong) NSMutableArray *tStreamCodecItems;


- (HKSDeviceStreamCodecItem *)tStreamCodecItemsAtIndex:(int)aIndex;
@end

