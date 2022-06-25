///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//  广州丽凌
///#end

#import "HKSDeviceClient.h"

//功能ID定义
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_QUERY_MP3_FILE_LIST				0x0101			//查询MP3文件列表
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_DELETE_MP3_FILE					0x0102			//删除MP3文件
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_START_PLAY_MP3_FILE				0x0103			//开始播放MP3文件
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_PLAY_MP3_FILE				0x0104			//停止播放MP3文件
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_CTRL_VOLUME						0x0105			//控制音量
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_START_UPLOAD_MP3_FILE			0x0106			//开始上传文件
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_UPLOAD_MP3_FILE				0x0107			//停止上传文件
#define HKS_NPC_D_DPS_CUSTOM_NI_FUNCID_UPLOAD_FILE_DATA					0x0108			//上传文件数据

///#begin zh-cn
/**
 *  @class      HKSDeviceClient (GZLL)
 *  @brief      广州LL相关定制接口
 */
///#end
///#begin en
///#end
@interface HKSDeviceClient (GZLL)

/** @brief  获取mp3列表  */
- (int)cameraCallCustomFunc:(int)type
                   fileName:(NSString *)sFileName
                   outArray:(NSMutableArray *)array;

/** @brief  mp3相关操作  */
- (int)cameraCallCustomFunc:(int)type
                   fileName:(NSString *)sFileName
                  soundSize:(int)iSoundSize
                   outArray:(NSMutableArray *)array;

- (int)cameraCallCustomFuncStopOrStopUploadMP3:(int)type
                                      fileName:(NSString *)theFileName
                                      fileSize:(unsigned long)theFileSize
                                    inUploadId:(unsigned long)inUploadId
                                   outUploadId:(unsigned long *)outUploadId;

- (int)cameraCallCustomFuncUploadMP3:(unsigned long)in_ulUploadId
                            fileSize:(unsigned long)in_iDataLen
                            fileData:(unsigned char *)in_ucFileData;
@end
