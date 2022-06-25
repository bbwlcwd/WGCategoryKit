///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

#import <mach/mach_time.h>
#import "HKPlayerDelegate.h"

@class UMNoise;
@class TreeListItem;
@class NetworkSpeed;
@class MP4Maker;
//@class MEAudioPlayer;
//@class XBAudioUnitPlayer;
//@class XBAudioUnitRecorder;
//@class MEAudioRecorder;
@class HKSRecFile;
@class UMMP4Helper;
#ifdef QVMediaProcessing
@class QVAudioEnginerManager;
#endif
typedef void (^RawDataCallback)(int iMsgId, char *in_pDataBuf, int in_iDataLen);

typedef void (^RawDataCallExback)(int iMsgId, void *target, char *in_pDataBuf, id data, int in_iDataLen);

typedef void (^UMDevClientTask)(id request, NSString *msgId, int iError, id aParam);

typedef struct
{
    /// 媒体数据
    unsigned char *mediaData;
    /// 媒体长度
    unsigned int mediaDataLen;
    /// 时间戳
    unsigned int timestamp;
    /// 媒体类型，0：视频，1：音频
    int mediaType;
    /// 编码，10:H264,13:h265,20:AAC,30:PCM
    int codecId;
    /// 帧类型，1:I帧，2:P帧
    int frameType;
    /// 帧率
    int frameRate;
    /// 音频采样率
    int audioSampleRate;
    /// 音频码率
    int audioBitRate;
} UMRawMediaData;

/**
 *  @brief      设备相关功能类，设备所有相关功能都由此类进行提供(Camera function interface class, all camera functions performed by such offers)
    
    @code
    @endcode
 */
@interface HKSDeviceClient : NSObject{
    
    /*! @brief  连接类型，HKS_NPC_D_MON_CLIENT_MODE_*  */
    void            *_videoDecoder;
    long            _audioDecoder;
    long            _audioEncode;

    BOOL            _isPlayerPause;
    BOOL            _isNoCanPlaying;
    BOOL            _pause;
    BOOL            _isIFrame;
    BOOL            _isIFrameRecode;
    void            *_pCamera;
    void            *_parser;
    NSThread        *_decodeThread;
    NetworkSpeed    *_networkSpeed;
    MP4Maker        *_mp4Maker;
    UMMP4Helper     *_umMP4Helper;
    int             _nDynamicFPS;
    int             _videoWidth;
	int             _videoHeight;
    int             _smoothFrameRate;
    int             _playFrameRate;
    int             _nDecodeIndex;
    int             _nAllFrameRate;
    int             _iRealplayOriFrameRate;
    BOOL            _bIfCallCustomFunc;
    MEAudioPlayer   *_auPlayer;
    MEAudioRecorder *_auRecorder;

    XBAudioUnitPlayer *_auUnitPlayer;
    XBAudioUnitRecorder *_auUnitRecorder;

    
    HKSRecFile      *_recFile;
    int             _networkTraffic;
    
    UIImage         *_downImage;
    
    NSCondition         *_connLock;
    NSCondition         *_recLock;
    NSCondition         *_customLock;
    BOOL                _isDowningFile;
    BOOL                _isPlaying;
    
    int                 _iAudioCodecId;
    int                 _clearFrameNumber;
    BOOL                _isSearching;
    NSTimeInterval      _frameStartTime;
    
    int                 _iVideoCodecId;
    
    int                 _iControlSpeed;
    BOOL                _bIfPtzing;
    
    int                 _iMaxConnProgress;
    NSTimer             *_connProgressTimer;
    
    BOOL                _recordPause;
    
    float               _soundGainMltiple;
    
    UMNoise             *_umNoise;
}
#ifdef QVMediaProcessing
@property(nonatomic, strong) QVAudioEnginerManager       *audioManager;
#endif

#pragma mark - 回调
//设备端主动上报透明通道数据回调
@property(nonatomic, copy) RawDataCallback      hCallback;
@property(nonatomic, copy) RawDataCallExback    hCallbackEx;
@property(nonatomic, weak) id<HKPlayerDelegate>   delegate;

#pragma mark - 设备连接信息
@property(nonatomic, copy) NSString             *deviceID;
@property(nonatomic, copy) NSString             *deviceUMID;
@property(nonatomic, copy) NSString             *deviceAddress;
@property(nonatomic, copy) NSString             *deviceUserID;
@property(nonatomic, copy) NSString             *devicePassword;
@property(nonatomic, assign) int                udTag;
@property(nonatomic, assign) int                deviceChannel;
@property(nonatomic, assign) int                devicePort;
@property(nonatomic, assign) int                deviceStream;

/// 是否开启降噪，默认关闭
@property(nonatomic, assign) BOOL                isNoise;
/*! @brief  设备协议ID，缺省：HKS_NPC_D_MON_VENDOR_ID_UMSP */
@property(nonatomic, assign) int    deviceVendor;
@property(nonatomic, assign) int    deviceConnMode;
/// 参考HKS_NPC_D_MON_CLIENT_MODE
@property(nonatomic, assign) int    connType;
@property(nonatomic, strong) TreeListItem       *currentItem;

#pragma mark - 显示视图相关
/// 播放画面视图(playing view)
@property(nonatomic, strong) UIView                 *view;

#if TARGET_OS_IPHONE
/*! @brief  视频显示试图的背景颜色，不支持透明(video displays the view background color, being transparent is not supported) */
@property(nonatomic, strong) UIColor            *displayViewColor;
#endif

/*! @brief  视频显示视图是否隐藏,缺省:NO(whether to hide the video view, default: NO) */
@property(nonatomic, assign) BOOL               hiddenDisplayView;

#pragma mark - 本地录像
@property(nonatomic, copy) NSString             *recordPath;
@property(nonatomic, assign) unsigned long long recordMemory;
/*! @brief  是否调用了本地录像接口，但是底层不一定正在开始录制了，需要通过localRECStatus属性来判断,缺省:NO(whether to open the video, default: NO)  */
@property(nonatomic, assign) BOOL               recordEnabled;

/*! @brief  本地录像是否开启(whether to start recoding the video) */
@property(nonatomic, assign) BOOL               recording;

/// 本地录像状态,缺省:0,0:停止录像,1:启动录像中,2:正在转码,3:暂停中,4:正在录像
@property(nonatomic, assign) int                localRECStatus;
/*! @brief  本地录像录制的最大时长（单位:秒）,缺省:0，无限制(max. local video recording time(unit: second), default: 0, unlimited)  */
@property(nonatomic, assign) int                localRECMaxTime;
/*! @brief  本地录像录制的最小时长（单位:秒）,缺省:2 (min. local video recording time(unit: second), default: 0, unlimited)  */
@property(nonatomic, assign) int                localRECMinTime;

@property(nonatomic, assign) int                localRECType;

/*! @brief  本地录像的每个文件的最大时长，最大限制的时间，将会换一个新的文件录制（单位:秒）,缺省:0，无限制(max. local video time of each file, max. limited time, will record in a new file(unit: second), default: 0, unlimited) */
@property(nonatomic, assign) int                localRECMaxFileTime;

#pragma mark - 播放配置
/// timeout,30000(ms)
@property(nonatomic, assign) int    iConnTimeout;
/*! @brief  是否开启音频,缺省:NO(whether to open the audio, default: NO) */
@property(nonatomic, assign) BOOL               audioEnabled;
/// 对讲开启以后，是否发送对讲数据，缺省:YES
@property(nonatomic, assign) BOOL               sendTalkEnabled;
/*! @brief  是否平铺播放视图,缺省:YES（whether to tile the views, default: YES）(whether to ) */
@property(nonatomic, assign) BOOL               fullScreenEnabled;
/*! @brief  是否使用平滑,缺省:NO（whether to use smooth, default: NO）*/
@property(nonatomic, assign) BOOL               smoothEnabled;
/// 按时间播放远程回放，缺省:NO(real-time remote play, default: NO)
@property(nonatomic, assign) BOOL               timePlayRECEnabled;
/*! @brief  是否开启解码I帧模式,缺省:NO(whether to open decoding I frame mode, default: NO)*/
@property(nonatomic, assign) BOOL               decodingIFrameEnabled;
/// 回音消除，默认NO
@property(nonatomic, assign) BOOL               audioEcho;
@property(nonatomic, assign) int sampleRate;
@property(nonatomic, assign) int bitRate;
@property(nonatomic, assign) int talkType;
/// 是否由SDK自动解码播放，缺少：YES
@property(nonatomic, assign) BOOL bAutoDecodPlay;
#pragma mark -
@property(nonatomic, assign) BOOL               isBackplay;

/*! @brief  远程录像是否开启 */
@property(nonatomic, assign) BOOL               remoteRecording;

/*! @brief  对讲状态,1:对讲开启，其他：对讲关闭(intercom status, 1: open intercom, others: close intercom) */
@property(nonatomic, assign) int                    talkState;

/*! @brief  实时播放的平均帧率，fps(the average fps of real-time play) */
@property(nonatomic, assign, readonly) int          videoFrameRate;

/*! @brief  是否播放的平均码流，kps (the average stream of whether to play, kps) */
@property(nonatomic, assign, readonly) float        videoNetworkSpeed;

/*! @brief  播放状态(playing status) */
@property(nonatomic, assign) HKSDevicePlayStatus    playerState;

/*! @brief  下载文件状态(status of downloading files) */
@property(nonatomic, assign) HKSDevicePlayStatus    downFileState;

#pragma mark -
/*! @brief  连接失败并且出现密码错误的时候是否自动修改加密方式进行重练，缺省:NO(when it occurs connection failed and password error, whether to automatically modify the way of encryption and reconnect, default: NO) */
@property(nonatomic, assign) BOOL                   connFailModifyEncryptionReconnection;

/*! @brief  解码类型ID，缺省:-1，根据设备传输类型解码,自动:-1,h264:0,mpeg4:1,mjpg:2,jpg:3,h265:4(decoding type ID, default:-1, decode according to the device transmitting type, automatically: -1,h264:0,mpeg4:1,mjpg:2,jpg:3,h265:4) */
@property(nonatomic, assign) int                    iVideoDecodeTypeId;
@property(nonatomic, assign) int                    iVideoFps;

//glkview
@property (nonatomic, assign) int   glMode;
/*  @brief  设置显示模式。1 - 半球A、2 - 半球B、3 - 单平面、4 - 圆柱、5 - 双平面、6 - 四视口   */
@property (nonatomic, assign) int   glShowType;
/*  @brief  巡航   */
@property (nonatomic, assign) BOOL  glCruise;
/*  @brief  偏移大小，20   */
@property (nonatomic, assign) int   glOffsetSize;
/*  @brief  广角，180   */
@property (nonatomic, assign) int   glWideAngle;
@property (nonatomic, assign) id    viewController;

@property (nonatomic, assign) BOOL  glAutoUpdate;

/*! @brief  演示固定序列号，默认:umipv6000000，如果播放数据的序列号等于该属性，则内部自动播放ipv6test.mp4文件 */
@property(nonatomic, copy) NSString *demoDeviceID;

//camview
@property (nonatomic, assign) int   smoothMaxFrameRate;
@property (nonatomic, assign) int   smoothType;

@property (nonatomic, assign) int   iConnProgress;

@property (nonatomic, assign) int   index;

/// 是否启动视频解码贴图，默认YES
@property(nonatomic, assign) BOOL   videoProcessEnable;

#pragma mark - 已过时
/*! @brief  是否在本地录像文件后面增加帧率,缺省:NO( whether to increase fps behind the local video files, default: NO)  */
@property(nonatomic, assign) BOOL               localRECFilePathFPS UMP2PDeprecated("已过时,无需再调用");

/*! @brief  是否在本地录像的时候写入音频,缺省:YES(whether to write in audio during local video recording, default: YES)  */
@property(nonatomic, assign) BOOL               localRECWirteAudeioEnabled UMP2PDeprecated("已过时,无需再调用");

/*! @brief  是否开启本地mp4平滑处理，缺省:NO(whether to open local mp4 smooth processing, default: NO) */
@property(nonatomic, assign) BOOL               localMP4SmoothEnabled UMP2PDeprecated("已过时,无需再调用");
@property(nonatomic, copy) NSString             *serverIP UMP2PDeprecated("已过时,无需再调用");
@property(nonatomic, assign) int                serverPort UMP2PDeprecated("已过时,无需再调用");

#pragma mark -
/** @brief  开始播放摄像头(start to play camera) */
- (void)start;

/** @brief  开始播放摄像头(start to play camera) */
- (void)start:(BOOL)bCleanView;

/**
 *  @brief  开始播放摄像头(start to play camera)
 
 @param  serverIP[NSString]         服务器地址(server IP)
 @param  serverPort[int]            服务器端口(server port)
 @param  deviceUMID[NSString]       序列号(UMID)
 @param  deviceUserID[NSString]     用户名(user ID)
 @param  devicePassword[NSString]   用户密码(password)
 @param  deviceChannel[int]         通道号(channel)
 @param  deviceStream[int]          码流，1：子码流，0：主码流(stream, 1: sub-stream, 0: main stream)
 @param  deviceVendor[int]          设备厂家(device verdor)
 */
- (void)startAtConnParam:(NSString *)serverIP
              serverPort:(int)serverPort
              deviceUMID:(NSString *)deviceUMID
            deviceUserID:(NSString *)deviceUserID
          devicePassword:(NSString *)devicePassword
           deviceChannel:(int)deviceChannel
            deviceStream:(int)deviceStream
            deviceVendor:(int)deviceVendor;

/**
 *  @brief      停止摄像头连接(stop playing camera)
 *
 *  @param[in]  block[BOOL]:阻塞线程控制，YES：阻塞，NO：不阻塞(blocking thread control, YES: blocked, NO, unblocked)
 */
- (void)stop:(BOOL)block;

/**
 *  @brief      停止摄像头连接(stop playing camera)
 *  @param[in]  block[BOOL]:阻塞线程控制，YES：阻塞，NO：不阻塞(blocking thread control, YES: blocked, NO, unblocked)
 *  @param[in]  theExit[BOOL]:是否真正退出，YES：等待状态非HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER的时候，执行停止命定，NO：如果状态为HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER，将不会执行停止命定(whether to exit actually, YES: when the waiting state isn’t HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER, it will perform stop imposed, NO: when the state is  HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER, it will not perform stop posed)
 */
- (void)stop:(BOOL)block exit:(BOOL)theExit;

/**
 *  @brief      停止摄像头连接(stop playing camera)
 *  @param[in]  block[BOOL]:阻塞线程控制，YES：阻塞，NO：不阻塞(blocking thread control, YES: blocked, NO, unblocked)
 *  @param[in]  theExit[BOOL]:是否真正退出，YES：等待状态非HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER的时候，执行停止命定，NO：如果状态为HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER，将不会执行停止命定(whether to exit actually, YES: when the waiting state isn’t HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER, it will perform stop imposed, NO: when the state is  HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER, it will not perform stop posed)
 *  @param[in]  aClearView[BOOL]:是否清除最后一帧图像(Whether to remove the last frame)
 */
- (void)stop:(BOOL)block exit:(BOOL)theExit clearView:(BOOL)aClearView;

/// 清除最后一帧图像，建议在停止状态下调用
- (void)clearView;

/**
 *  @brief  设置音频
 *  @param  enabled[BOOL]      是否开启音频
 *  @param  sync[BOOL]         是否同步状态到设备端
 */
- (void)setAudioEnabled:(BOOL)enabled syncDev:(BOOL)sync;

#pragma mark -
/// 获取原始媒体数据
/// @param type 数据类型，0：混合方式，1：视频，2：音频
- (UMRawMediaData *)rawMediaData:(int)type;

/// 释放媒体数据
/// @param mediaData 媒体数据
- (void)releaseRawMediaData:(UMRawMediaData *)mediaData;
#pragma mark -
/**
 *  @brief      重置音频模块(reset the audio module)
 */
- (void)resetAudio;

/*! @brief  获取当前视频的编码ID,需要在状态为播放中的时候，该接口才有效(Acquire the current video code, and the connection is valid only when the video is playing ) */
- (HKS_NPC_D_MON_CODEC_ID)videoCodecId;

/*! @brief  播放状态(playing status) */
- (HKSDevicePlayStatus)playerState;

/// 设备播放的连接类型,参考HKS_NPC_D_MON_DEV_CONN_TYPE
- (int)deviceConnNetworkMode;

/** @brief  当前播放使用网络流量(the network flow used by the video being played)  */
- (int)networkTraffic;

/** @brief  服务器句柄(server handle) */
- (void *)serverClient;

- (void)setMaxRecordTime:(int)aMaxRecordTime UMP2PDeprecated("该接口已过时,请使用localRECMaxTime，the connection has expired, please use localRECMaxTime");

- (void)updateGLView;

@end
