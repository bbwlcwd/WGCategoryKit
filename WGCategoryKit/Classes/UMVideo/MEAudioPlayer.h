//
//  MEAudioRecorder.h
//  UMVideo
//
//  Created by Fred on 12-11-24.
//
//

#import <Foundation/Foundation.h>
#import "MEAudioDef.h"

@interface MEAudioPlayer : NSObject {
	void *							_impl;
	BOOL							_shouldStop;

}
@property(nonatomic, assign) int audioSampleRate;
-(void)setDelegate:(id)aDelegate;
-(void)setDataSource:(id)aDataSource;
-(BOOL)isRunning;
-(void)play;
-(void)stop;
-(void)setMute:(BOOL)flag;
-(BOOL)isMute;
-(void)pause;
-(void)resume;

@end
