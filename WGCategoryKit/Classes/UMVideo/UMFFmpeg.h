/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  UMFFmpeg.h 
 * Version       :  1.0
 * Author        :  Johnny
 * DateTime      :  2020-04-15
 * Description   :  音频解码接口定义
 *----------------------------------------------------------------------------*/

#ifndef __UMFFmpeg_H
#define __UMFFmpeg_H


//导出导入定义
#ifdef _WIN32
	#ifdef _MEDIA_CODE__EXPORTS
		#define MEDIA_CODE_API __declspec(dllexport)
	#else
		#ifdef _MEDIA_CODE__IMPORT
			#define MEDIA_CODE_API __declspec(dllexport)
		#else
			#define MEDIA_CODE_API
		#endif
	#endif
#else
	#define MEDIA_CODE_API
#endif

#ifndef IN
#define IN
#define OUT
#endif


//----------------------------------------------------------------------
//音频格式
#define		MEDIA_AUDIO_FORMAT_RAW								0
#define		MEDIA_AUDIO_FORMAT_AAC								1
#define		MEDIA_AUDIO_FORMAT_G711A							2
#define		MEDIA_AUDIO_FORMAT_G711U							3
#define		MEDIA_AUDIO_FORMAT_ADPCM							4
#define		MEDIA_AUDIO_FORMAT_MP3								5
#define		MEDIA_AUDIO_FORMAT_AMR								6

//视频格式
//视频编码格式
#define		MEDIA_VIDEO_FORMAT_DEFAULT							0				//未知
#define		MEDIA_VIDEO_FORMAT_264								1				//h264
#define 	MEDIA_VIDEO_FORMAT_MPEG4              				2       		 //MPEG4
#define 	MEDIA_VIDEO_FORMAT_MJPG              				3        		//MJPG
#define		MEDIA_VIDEO_FORMAT_265								4				//h265
//------------------------------------------------------------------------
typedef struct _NPC_AVC_SPS_AND_PPS_HEAD
{
	unsigned char	version;					//版本号
	unsigned char	AVCProfileIndication;		//AVC配置文件描述
	unsigned char	profile_compatibility;		//配置文件的兼容性
	unsigned char	AVCLevelIndication;			//AVC等级描述
	unsigned char	Sign;						//一般为0xff
}NPC_AVC_SPS_AND_PPS_HEAD, *PNPC_AVC_SPS_AND_PPS_HEAD;

//媒体信息
typedef struct _MEDIA_FRAME_INFO
{
	unsigned int    iMediaTime;     //媒体总时长(毫秒)
	unsigned int    bHaveVideo;     //是否有视频
	int             iVideoCodecId;  //视频编码格式：MEDIA_VIDEO_FORMAT_*
	int             iVideoWidth;    //视频宽度
	int             iVideoHeight;   //视频高度
	int             iVideoBitRate;  //视频码率
	int             iVideoFrameRate;    //视频帧率

	unsigned int    bHaveAudio;     //是否有音频
	int             iAudioCodecId;  //音频编码格式：MEDIA_AUDIO_FORMAT_*
	int             iAudioBitRate;  //音频码率
	int             iAudioSampleRate;   //音频采样率
	int             iAudioChNum;    //音频声道数

} MEDIA_FRAME_INFO, *PMEDIA_FRAME_INFO;

//错误码定义
typedef enum {
	MERR_SUCCESS		= 0,		//0: 成功
	MERR_PARAM,						//1: 参数错误：可能是参数不能为空，或者参数不在取值范围内
	MERR_ALLOC,						//2: 资源空间失败
	MERR_SIZE,						//3: 尺寸不足，可能是输出的内容超过缓冲区上限
	MERR_DECODE,					//4: 解码失败
	MERR_ENCODE,					//5: 编码失败
	MERR_SWR,						//6: 重采样失败
	MERR_OPEN,						//7: 资源加载失败，可能是参数错误，也可能是没有这个资源
	MERR_READ,						//8: 读取资源失败，可能是源文件损坏
	MERR_SEEK,						//9: 定位文件失败
	
	MERR_EOF			= 0xFFFF,	//0xFFFF: 结束标示，非错误，个别状态标示
}ENUM_ERROR;

#ifdef __cplusplus
extern "C"
{
#endif

//-----------------------------------------------------------------------------------
//

/// 初始化,返回ENUM_ERROR
/// @param iCpuNum CPU数量
MEDIA_CODE_API int	MediaInit(
	IN		int     iCpuNum
	);
////////////////////////////////////
/// 反初始化
MEDIA_CODE_API int MediaUnInit();

/// 创建音频解码模块,返回ENUM_ERROR
/// @param iAudioFormat 音频格式
/// @param iChannel 声道数
/// @param iSamplesRate 采样率
/// @param iBitRate 分辨率
/// @param iOutSamplesRate 重采样率,即输出采样率。
/// @param pADecodeHdl 音频解码句柄，用于后续处理，需保存
MEDIA_CODE_API int AudioDecodeCreate(
	IN		int     iAudioFormat,
	IN		int     iChannel,
	IN		int     iSamplesRate,
	IN		int     iBitRate,
	IN		int     iOutSamplesRate,
	OUT		long    *pADecodeHdl
	);

/// 销毁音频播放句柄,返回ENUM_ERROR
/// @param lADecodeHdl 音频解码句柄，AudioCodeCreate中返回
MEDIA_CODE_API int AudioDecodeRelease(
	IN		long    lADecodeHdl
	);

/// 输入音频数据解码,返回ENUM_ERROR
/// @param lADecodeHdl 音频解码句柄，AudioCodeCreate中返回
/// @param pInData 源数据缓冲区
/// @param iInDataLen 源数据长度
/// @param pOutData 输出数据缓冲区
/// @param iOutSize 输出数据缓冲区大小
/// @param pOutLen 输出数据长度
MEDIA_CODE_API int AudioDecodeInput(
	IN		long            lADecodeHdl,
	IN		unsigned char   *pInData,
	IN		int             iInDataLen,
	OUT		unsigned char   *pOutData,
	IN		int             iOutSize,
	OUT		int	            *pOutLen
	);

////////////////////////////////////
/// 创建音频编码模块,返回ENUM_ERROR
/// @param iPcmSampleRate 输入PCM的采样率
/// @param iPcmChannel 输入PCM的通道号
/// @param iPcmBitRate 输入PCM的位率
/// @param iOutFormat 输出音频格式
/// @param iOutChannel 输出声道数
/// @param iOutSamplesRate 输出采样率
/// @param pAEncodeHdl 音频编码句柄，用于后续处理，需保存
MEDIA_CODE_API int AudioEncodeCreate(
	IN		int     iPcmSampleRate,
	IN		int     iPcmChannel,
	IN		int     iPcmBitRate,
	IN		int     iOutFormat,
	IN		int     iOutChannel,
	IN		int     iOutSamplesRate,
	OUT		long    *pAEncodeHdl
	);

/// 销毁音频播放句柄,返回ENUM_ERROR
/// @param lAEncodeHdl 音频编码句柄，AudioEncodeCreate中返回
MEDIA_CODE_API int AudioEncodeRelease(
	IN		long    lAEncodeHdl
	);

/// 输入音频数据解码,返回ENUM_ERROR
/// @param lADecodeHdl 音频解码句柄，AudioCodeCreate中返回
/// @param pInData 源数据缓冲区
/// @param iInDataLen 源数据长度
/// @param pOutData 输出数据缓冲区
/// @param iOutSize 输出数据缓冲区大小
/// @param pOutLen 输出数据长度
MEDIA_CODE_API int AudioEncodeInput(
	IN		long            lADecodeHdl,
	IN		unsigned char   *pInData,
	IN		int             iInDataLen,
	OUT		unsigned char   *pOutData,
	IN		int             iOutSize,
	OUT		int	            *pOutLen
	);

////////////////////////////////////
/// 创建hls解析模块,返回ENUM_ERROR
/// @param pFilePath 文件路径：M3U8地址，本地路径或者HTTP地址
/// @param lHlsHdl Hls解析句柄，用于后续处理，需保存
/// @param pMediaInfo 媒体信息
MEDIA_CODE_API int HlsParseCreate(
	IN		unsigned char       *pFilePath,
	OUT		long                *lHlsHdl,
	OUT		PMEDIA_FRAME_INFO   pMediaInfo
	);

/// 销毁音频播放句柄,返回ENUM_ERROR
/// @param lHlsHdl Hls解析句柄，HlsParseCreate中返回
MEDIA_CODE_API int HlsParseRelease(
	IN		long    lHlsHdl
	);

/// 读取媒体流,返回ENUM_ERROR
/// @param lHlsHdl Hls解析句柄，HlsParseCreate中返回
/// @param iType 0:混合，1:视频，2:音频
/// @param pMediaType 媒体类型：1=视频，2=音频
/// @param pFrameType 视频帧类型：1=I帧，2=P帧
/// @param pTimestamp 时间戳：(毫秒)
/// @param ppMediaData 媒体流数据
/// @param pMediaDataLen 媒体流数据长度
MEDIA_CODE_API int HlsParseRead(
	IN		long    lHlsHdl,
	IN		int     iType,
	OUT		int	    *pMediaType,
	OUT		int     *pFrameType,
	OUT		unsigned int    *pTimestamp,
	OUT		unsigned char   **ppMediaData,
	OUT		int             *pMediaDataLen
	);

/// 释放数据
/// @param ppMediaData 媒体流数据
MEDIA_CODE_API int HlsFreeData(
	IN		unsigned char   **ppMediaData
	);

/// 跳转
/// @param lHlsHdl Hls解析句柄，HlsParseCreate中返回
/// @param iSeekTime 定位时间：相对时间，单位秒。
MEDIA_CODE_API int HlsParseSeek(
	IN		long    lHlsHdl,
	IN		int     iSeekTime
	);


#ifdef __cplusplus
}
#endif

#endif

