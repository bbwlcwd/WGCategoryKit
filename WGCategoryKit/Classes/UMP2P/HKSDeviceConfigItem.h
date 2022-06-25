//
//  HKSDeviceConfigItem
//  IPHKPlayer
//
//  Created by HSKJ on 14-5-9.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceConfigItem : NSObject

@property(nonatomic, assign) int  iChNo;                  //通道号
@property(nonatomic, assign) int  bIfEnable;              //是否开启,1:开启,0:失败
@property(nonatomic, assign) int  bIfPictureMirror;       //是否开启图像镜像
@property(nonatomic, assign) int  bFuncEnable_SensorType; //功能是否有效：传感器类型,1:传感器类型参数项有效,0:为无效（下同）
@property(nonatomic, assign) int  bFuncEnable_Level;      //功能是否有效：灵敏度，TRUE：灵敏度参数项有效，FALSE：为无效（下同）
@property(nonatomic, assign) int  bFuncEnable_Region;     //功能是否有效：检测区域块
@property(nonatomic, assign) int  bFuncEnable_Photo;      //功能是否有效：拍照
@property(nonatomic, assign) int  bFuncEnable_Record;     //功能是否有效：录像
@property(nonatomic, assign) int  bFuncEnable_AlarmOut;   //功能是否有效：报警输出
@property(nonatomic, assign) int  bFuncEnable_Beep;       //功能是否有效：报警蜂鸣
@property(nonatomic, assign) int  bFuncEnable_WeekSect;   //功能是否有效：检测时间段
@property(nonatomic, assign) int  iSensorType;            //传感器类型,0:常闭,1:常开
@property(nonatomic, assign) int  iLevel;                 //灵敏度，1-6
@property(nonatomic, strong) NSMutableArray *regions;     //检测区域块 NSNumber numberWithUnsignedLong
@property(nonatomic, assign) int  bPhotoEnable;           //拍照
@property(nonatomic, assign) int  bRecordEnable;          //录像
@property(nonatomic, assign) int        iRecordDelayedTime;     //录像延时时间(秒)
@property(nonatomic, assign) int  bAlarmOutEnable;        //报警输出使能
@property(nonatomic, assign) BOOL       bEmailEnable;           //报警邮件通知
@property(nonatomic, assign) int        iAlarmOutDelayedTime;   //报警输出延时时间(秒)
@property(nonatomic, assign) int  bBeepEnable;            //蜂鸣使能
@property(nonatomic, strong) NSMutableArray *weekTimes;         //检测时间段 NSMutableArray->HKSDeviceAlarmMotionTimeSect

@end
