///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end


///#begin zh-cn
/**
 *  @class      HKSDeviceCleanItem
 *  @brief      摄像机清除计划对象
 */
///#end
///#begin en
///#end
@interface HKSDeviceCleanItem : NSObject

/** @brief  星期，0：星期日，1：星期一。。。  */
@property (nonatomic, assign) int iWeek;

/** @brief  开始时间  */
@property (nonatomic, assign) char cStartHour;
@property (nonatomic, assign) char cStartMinute;

/** @brief  结束时间  */
@property (nonatomic, assign) char cEndHour;
@property (nonatomic, assign) char cEndMinute;
@end
