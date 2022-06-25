//
//  MEAudioDef.h
//  UMVideo
//
//  Created by fred on 2020/9/28.
//  Copyright © 2020 Fred. All rights reserved.
//

#ifndef MEAudioDef_h
#define MEAudioDef_h

    typedef struct
    {
        unsigned char* pContent;
        unsigned long nLength;
        unsigned int nFrameLength;
        unsigned int nEncodeType;
        unsigned long nTimeStamp;
        unsigned int iFrameFlag;
    } MEAUDIOData_FRAME;

    #define     MEAUDIO_TYPE_PCM        10
    #define     MEAUDIO_TYPE_G711a      11
    #define     MEAUDIO_TYPE_AMRNB        12
    #define     MEAUDIO_TYPE_AMRWB        13
    #define     MEAUDIO_TYPE_AAC        14
    #define     MEAUDIO_TYPE_ADPCM        15
    #define     MEAUDIO_TYPE_QIHANADPCM    16
    #define     MEAUDIO_TYPE_G711u        17
    #define     MEAUDIO_TYPE_G726        18

#endif /* MEAudioDef_h */
