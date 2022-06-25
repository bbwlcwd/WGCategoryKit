//
//  UMDoorInfoItem.h
//  UMCloud
//
//  Created by UMEYE on 2016/11/17.
//
//

@interface UMDoorInfoItem : NSObject

//设备密码
@property(nonatomic, copy)  NSString *sDevPwd;
//门铃密码
@property(nonatomic, copy)  NSString *sLockPwd;
//门铃序列号
@property(nonatomic, copy)  NSString *sDevSerial;
//设备类型
@property(nonatomic, copy)  NSString *sDevType;
@property(nonatomic, assign)  int   iChannelNum;
//省电模式，1:正常模块，2:深度省电模式，3:夜间省电模式
@property(nonatomic, assign)  int   iPowerMode;
//PIR状态
@property(nonatomic, assign)  int   iPirState;
//PIR时间
@property(nonatomic, copy)  NSString    *iPirTime;
@property(nonatomic, assign)  int       iTamperState;
//门铃声音
@property(nonatomic, assign)  int       iDoorAudio;

@end
