//
//  um_file_converter.h
//  UMVideo
//
//  Created by fred on 2021/11/10.
//

#ifndef um_file_converter_h
#define um_file_converter_h

#ifdef __cplusplus
extern "C"
{
#endif
/// 音视频文件合并MP4
/// @param pInVideoFile 视频数据文件路径
/// @param pInAudioFile 音频数据文件路径
/// @param pInMp4File MP4文件存放路径
/// @param iInVideoFormat 视频编码ID
int UMMP4Merge(const char *pInVideoFile, const char *pInAudioFile, const char *pInMp4File, int iInVideoFormat, int fps);

/// TS文件分解成音视频文件
/// @param pInTsFile TS文件路径
/// @param pOutAudioFile 分解后的音频文件
/// @param pOutVideoFile 分解后的视频文件
int UMTSAnalysis(const char *pInTsFile, const char *pOutAudioFile, const char *pOutVideoFile);

#ifdef __cplusplus
}
#endif
#endif /* um_file_converter_h */
