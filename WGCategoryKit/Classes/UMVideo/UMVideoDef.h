//
//  UMVideoDef.h
//  UMVideo
//
//  Created by Fred on 2020/2/17.
//  Copyright © 2020年 UMEye.com. All rights reserved.
//

#ifndef UMVideoDef_h
#define UMVideoDef_h
    enum{
        CZ_CODEC_ID_H264 = 0,
        CZ_CODEC_ID_MJPEG = 1,
        CZ_CODEC_ID_JPEG = 2,
        CZ_CODEC_ID_MPEG4 = 3,
        CZ_CODEC_ID_RTSP = 4,//不支持
        CZ_CODEC_ID_HEVC = 5,
        CZ_CODEC_ID_AAC = 7,//不支持
    };
    typedef int CZVIDEODECOD_CODEC_ID;

    #define MAX_NEG_CROP 1024

    typedef struct tag_yuvlookuptable
    {
        int RGB_Y[256];
        int R_V[256];
        int G_U[256];
        int G_V[256];
        int B_U[256];
    }yuvlookuptable;



    typedef struct tag_L264Decode
    {
        void    *sContext;
        void    *sFormatCtx;
        void    *sPicture;
        void    *sData;
        char    sFileName[512];
        int     iDecodeWidth;
        int     iDecodeHeight;
        int     iFlag;
        int     iIsInit;
        int     iIsIniting;
        int     iIsEnding;
        int     iVideoindex;
        int     iContextLen;
        int     iCodeId;
        yuvlookuptable yuvtable;
        unsigned char cropTbl[256 + 2 * MAX_NEG_CROP];
    }L264Decode,*PL264Decode;

    typedef struct tag_RTSPFrame
    {
        void *pContent;
        int nFrameLength;
        int nTimeStamp;
        int nParam1;
        int nParam2;
        
    }RTSPFrame,*PRTSPFrame;

    enum{
        CZVIDEODECOD_ERROR_OK = 1,
        CZVIDEODECOD_ERROR_FAIL = 0,
        CZVIDEODECOD_ERROR_INITFAIL = -1,
    };
    typedef int CZVIDEODECOD_ERROR;


    // Thread type
    typedef enum tagCZVIDEODECODE_THREADTYPE
    {
        CZVIDEODECODE_SINGLE_THREAD     = 0,
        CZVIDEODECODE_MULTI_THREAD
    } CZVIDEODECODE_THREADTYPE;
#endif /* UMVideoDef_h */
