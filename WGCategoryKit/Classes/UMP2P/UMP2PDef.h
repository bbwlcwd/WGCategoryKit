//
//  UMP2PDef.h
//  HKSUMEyeCloudLIb
//
//  Created by fred on 2020/6/7.
//  Copyright © 2020 Fred. All rights reserved.
//

#ifndef UMP2PDef_h
#define UMP2PDef_h

    typedef struct
    {
        short year;
        short month;
        unsigned char day;
        unsigned char hour;
        unsigned char minute;
        unsigned char second;
        unsigned int minsecond;
    } Date_Time;


    enum{
        /** @brief  所有录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_ALL = 0x00FF,
        /// 所有报警
        HKS_NPC_D_MON_REC_FILE_TYPE_ALL_ALARM = 0x00FE,
        /** @brief  常规录像（定时录像）    */
        HKS_NPC_D_MON_REC_FILE_TYPE_GENERAL = 0x0001,
        /** @brief  报警录像（移动报警录像）    */
        HKS_NPC_D_MON_REC_FILE_TYPE_ALARM = 0x0002,
        /** @brief  手动录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_MALUAL = 0x0004,
        /** @brief  输入（探头）报警录像，巡航    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PROBE = 0x0008,
        /** @brief  人体感应报警录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIR = 0x0010,
        /** @brief  门铃报警录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_DOORBELL = 0x0020,
        /** @brief  越线侦测报警录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_SMART_IPC_CROSS_LINE = 0x0040,
        /** @brief  区域入侵报警录像    */
        HKS_NPC_D_MON_REC_FILE_TYPE_SMART_IPC_AREA_INTRUSION = 0x0080,
        /** @brief  3GP    */
        HKS_NPC_D_MON_REC_FILE_TYPE_3GP = 0x1111,
        /** @brief  所有图片文件    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_ALL = 0xFF00,
        /// 所有报警
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_ALL_ALARM = 0xFE00,
        /** @brief  常规图片（定时）    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_GENERAL = 0x0100,
        /** @brief  报警图片（移动报警）    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_ALARM = 0x0200,
        /** @brief  手动图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_MALUAL = 0x0400,
        /** @brief  输入（探头）报警图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_PROBE = 0x0800,
        /** @brief  人体感应报警图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_PIR = 0x1000,
        /** @brief  门铃报警图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_DOORBELL = 0x2000,
        /** @brief  越线侦测报警图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_CROSS_LINE = 0x4000,
        /** @brief  区域入侵报警图片    */
        HKS_NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_AREA_INTRUSION = 0x8000
    };
    /** @brief  录像文件类型    */
    typedef int HKS_NPC_D_MON_REC_FILE_TYPE;


    enum{
        /** @brief  所有方式    */
        HKS_NPC_D_MON_FILE_CREATE_MODE_ALL = 0,
        /** @brief  报警方式    */
        HKS_NPC_D_MON_FILE_CREATE_MODE_ALARM = 1,
        /** @brief  手动方式    */
        HKS_NPC_D_MON_FILE_CREATE_MODE_MANUAL = 2,
        /** @brief  定时方式    */
        HKS_NPC_D_MON_FILE_CREATE_MODE_TIMER = 3,
    };
    /** @brief  文件创建方式定义    */
    typedef int HKS_NPC_D_MON_FILE_CREATE_MODE;

    enum{

        /** @brief  所有文件类型    */
        HKS_NPC_D_MON_FILE_TYPE_ALL = 0,
        /** @brief  录像文件    */
        HKS_NPC_D_MON_FILE_TYPE_RECORD = 1,
        /** @brief  拍照文件    */
        HKS_NPC_D_MON_FILE_TYPE_PICTRUE = 2,
    };
    /** @brief  文件类型定义    */
    typedef int HKS_NPC_D_MON_FILE_TYPE;

    enum{
        HKS_NPC_D_MON_CODEC_ID_VEDIO_H264 = 10,                //H264
        HKS_NPC_D_MON_CODEC_ID_VEDIO_MPEG4 = 11,            //MPEG4
        HKS_NPC_D_MON_CODEC_ID_VEDIO_MJPG = 12,                //MJPG
        HKS_NPC_D_MON_CODEC_ID_VEDIO_H265 = 13,                //H265
        
        HKS_NPC_D_MON_CODEC_ID_AUDIO_AAC = 20,                //AAC
        HKS_NPC_D_MON_CODEC_ID_AUDIO_PCMA = 21,                //PCMA（G711A）
        HKS_NPC_D_MON_CODEC_ID_AUDIO_PCMU = 22,                //PCMU（G711U）
        HKS_NPC_D_MON_CODEC_ID_AUDIO_ADPCM = 23,            //ADPCM
        HKS_NPC_D_MON_CODEC_ID_AUDIO_G726 = 24,                //G726
        HKS_NPC_D_MON_CODEC_ID_AUDIO_AMRNB = 25,                //AMRNB
        HKS_NPC_D_MON_CODEC_ID_AUDIO_ADPCM_DJ = 26,                //ADPCM_DJ
        
        HKS_NPC_D_MON_CODEC_ID_AUDIO_16BITPCM = 30,                //16线性PCM
    };
    /** @brief  编码ID定义    */
    typedef int HKS_NPC_D_MON_CODEC_ID;

    enum{
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE_NON_CONNECT = 0,            //未连接
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECTING = 1,            //正在连接
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_OK = 2,            //已连接
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_FAIL = 3,            //连接失败
    };
    //设备连接服务器状态定义
    typedef int UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE;

    enum{
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_SUCCESS = 0,            //成功
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_DNS_FAIL = 1,            //域名解析失败（可能为设备未接入公网，或者域名错误）
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_CONN_SRV_FAIL = 2,            //连接服务器失败（可能为服务器未运行，或者防火墙阻止了通讯）
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_LOGIN_AUTH_FAIL = 3,            //登录认证失败（可能是UMID未授权，或认证码错误）
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_UMID_REGISTERED = 4,            //UMID已经注册（UMID被其它设备注册到服务器）
        UM_NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_OTHER_FAIL = 99,            //其它失败
    };
    //设备连接服务器的失败码定义
    typedef int NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE;

    enum{
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_AAC = 1,                //AAC
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_PCMA = 2,                //PCMA（G711A）
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_PCMU = 3,                //PCMU（G711U）
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_ADPCM = 4,                //ADPCM
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_G726 = 5,                //G726
        HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO_AMRNB = 6,                //AMRNB
    };
    /** @brief  通道配置的音频编码类型  */
    typedef int HKS_NPC_D_MON_CSD_CODEC_ID_AUDIO;

    enum{
        /** @brief  重启  */
        HKS_NPC_D_CHILD_JSON_MANAGE_FUNCID_RESTART = 1,
        /** @brief  恢复出厂设置  */
        HKS_NPC_D_CHILD_JSON_MANAGE_FUNCID_RESET = 2,
    };
    /** @brief  设备管理子功能ID定义  */
    typedef int HKS_NPC_D_CHILD_JSON_MANAGE_FUNCID;


    enum {
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_1080P = 1,                //1080P
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_720P = 2,                //720P
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_D1 = 3,                //D1
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_HD1 = 4,                //HD1
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_BCIF = 5,                //BCIF
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_CIF = 6,                //CIF
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_QCIF = 7,                //QCIF
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_VGA = 8,                //VGA
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_QVGA = 9,                //QVGA
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_SVCD = 10,                //SVCD
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_QQVGA = 11,                //QQVGA
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_SXVGA = 12,                //SXVGA
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_UXGA = 13,                //UXGA
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_960H = 14,                //960H
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_960P = 15,                //960P
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_3M = 16,                //3M:2304 * 1296
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_4M = 17,                //4M:2592 * 1520
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_5M = 18,                //5M:2592 * 1944
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_UHD4K = 19,                //UHD4K:3840 * 2160
        HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION_12M = 20,                //12M:4000 * 3000
    };
    /** @brief  视频分辨率  */
    typedef int HKS_NPC_D_MON_CSD_VEDIO_RESOLUTION;



    enum{
        HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO_H264 = 1,                //H264
        HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO_MPEG4 = 2,                //MPEG4
        HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO_MJPG = 3,                //MJPG
        HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO_H265 = 4,                //H265
    };
    /** @brief  通道配置的视频编码类型  */
    typedef int HKS_NPC_D_MON_CSD_CODEC_ID_VEDIO;


    #define UMP2PDeprecated(_info) __attribute__((deprecated(_info)))

#endif /* UMP2PDef_h */
