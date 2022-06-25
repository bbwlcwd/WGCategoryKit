//
//  XBAudioUnitRecorder.h
//  XBVoiceTool
//
//  Created by xxb on 2018/6/28.
//  Copyright © 2018年 xxb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Header_audio.h"

@class XBAudioUnitRecorder;

typedef void (^XBAudioUnitRecorderOnputBlock)(NSMutableData *data);
typedef void (^XBAudioUnitRecorderOnputBlockFull)(XBAudioUnitRecorder *player,
                                                AudioUnitRenderActionFlags *ioActionFlags,
                                                const AudioTimeStamp *inTimeStamp,
                                                UInt32 inBusNumber,
                                                UInt32 inNumberFrames,
                                                AudioBufferList *ioData);

@interface XBAudioUnitRecorder : NSObject
@property (nonatomic,readonly,assign) BOOL isRecording;
@property (nonatomic, assign) int type;

@property (nonatomic,copy) XBAudioUnitRecorderOnputBlock bl_output;

@property (nonatomic,copy) XBAudioUnitRecorderOnputBlockFull bl_outputFull;

- (instancetype)initWithRate:(int)rate bit:(XBAudioBit)bit channel:(XBAudioChannel)channel type:(int)type;
- (void)start;
- (void)stop;
- (AudioStreamBasicDescription)getOutputFormat;
@end
