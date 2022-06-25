//
//  L264.h
//  UMVideo
//
//  Created by Fred on 2020/2/17.
//  Copyright © 2020年 UMEye.com. All rights reserved.
//

#ifndef L264_H
#define L264_H
    
#include "UMVideoDef.h"

#ifdef __cplusplus__
extern "C" {
#endif
    
    char *CZVIDEODECOD_VERSION();
    //初始化
    int CZVIDEODECODE_Create(PL264Decode phDecoder,CZVIDEODECOD_CODEC_ID eCodecId,CZVIDEODECODE_THREADTYPE eThreadType);

    /// 解码
    /// @param phDecoder 句柄
    /// @param pInStream 需要解码的数据
    /// @param iInStreamLen 解码数据长度
    /// @param eCodeId 数据类型
    /// @param eThreadType 解码线程类型
    /// @return 解码结果：1：成功，其他失败
    CZVIDEODECOD_ERROR CZVIDEODECODE_DecodeFrame(PL264Decode phDecoder,unsigned char *pInStream,int iInStreamLen,CZVIDEODECOD_CODEC_ID eCodeId,CZVIDEODECODE_THREADTYPE eThreadType);
    
    //获取解码成功以后的yuv数据
    int CZVIDEODECOD_GetBuffer(PL264Decode PL264,unsigned char *aBuffer);
    int CZVIDEODECOD_GetBufferWH(PL264Decode PL264,unsigned char *aBuffer, int aWidth, int aHeight);

    /// 解码结束，释放资源
    /// @param phDecoder 句柄
    CZVIDEODECOD_ERROR CZVIDEODECODE_Delete(PL264Decode phDecoder);
    
    //调换R与G位置
    int CZVIDEODECOD_RGBRTOG(PL264Decode PL264,unsigned char *aBuffer);
    //宽度
    int GetPictureWidth(PL264Decode PL264);
    //高度
    int GetPictureHeight(PL264Decode PL264);
    
    /// 视频转码接口
    /// @param PL264 H264句柄
    /// @param bmp 转码成功的输出数据
    int YUV2RGB444(PL264Decode PL264,unsigned char *bmp);
    int YUV2RGB555(PL264Decode PL264,unsigned char *bmp);
    int YUV2RGB565(PL264Decode PL264,unsigned char *bmp);
    int YUV2RGB888(PL264Decode PL264,unsigned char *bmp);
    int YUV2BGR888(PL264Decode PL264,unsigned char *bmp);
    int YUV2RGB32 (PL264Decode PL264,unsigned char *bmp);
    int YUV2BGR32 (PL264Decode PL264,unsigned char *bmp);
    int YUV420TOYUVV422 (PL264Decode PL264,unsigned char *bmp);
    int YUV2RGB24(PL264Decode PL264,unsigned char *bmp);
    
#ifdef __cplusplus__
}
#endif

#endif
