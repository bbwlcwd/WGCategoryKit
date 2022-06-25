//
//  MEAudioRecorder.h
//  UMVideo
//
//  Created by Fred on 12-11-24.
//
//
#import <Foundation/Foundation.h>
#import "MEAudioDef.h"

typedef void (^UMAudioRecordDataBlock)(unsigned char *data, int len);
@interface MEAudioRecorder : NSObject {
    void *							_impl;
	BOOL							_shouldStop;
}

@property (nonatomic,copy) UMAudioRecordDataBlock dataBlock;

-(void)setDelegate:(id)aDelegate;
-(void)setDataSource:(id)aDataSource;

-(BOOL)isRunning;
-(void)start:(int)format;
-(void)stop;

@end
