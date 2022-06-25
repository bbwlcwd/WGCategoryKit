//
//  HKSRecFile.h
//  IPHKPlayer
//
//  Created by HSKJ on 12-5-29.
//  Copyright 2012 UMEYE. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HKSRecFile : NSObject

@property(nonatomic, copy) NSString         *fileName;
@property(nonatomic, assign) int            fileSize;
@property(nonatomic, assign) int            fileType;
@property(nonatomic, assign) Date_Time      startTime;
@property(nonatomic, assign) Date_Time      endTime;
@property(nonatomic, assign) int            recTimeLen;
@property(nonatomic, assign) long           param1;
@property(nonatomic, assign) int            param2;
@property(nonatomic, assign) int            iChNo;
@property(nonatomic, assign) int            iStream;
/// 文件模式，HKS_NPC_D_MON_FILE_CREATE_MODE_*
@property(nonatomic, assign) int            iCreateMode;
/// 报警事件类型，HKS_NPC_D_MON_CSD_ALARM_EVENT_*
@property(nonatomic, assign) int            iAlarmEvent;

@property(nonatomic, assign) int            bVideoFlag;
@property(nonatomic, assign) int            bAudioFlag;
@property(nonatomic, assign) int            iVideoCodecId;
@property(nonatomic, assign) int            iVideoFrameRate;
@property(nonatomic, assign) int            iVideoBitRate;
@property(nonatomic, assign) short          usVideoWidth;
@property(nonatomic, assign) short          usVideoHeight;

@property(nonatomic, assign) int            iAudioCodecId;
@property(nonatomic, assign) int            iAudioBitRate;
@property(nonatomic, assign) int            iAudioSampleRate;
@property(nonatomic, assign) int            iAudioChNum;
@property(nonatomic, assign) int            iPictureFormat;
@property(nonatomic, copy) NSString         *devId;

@end
