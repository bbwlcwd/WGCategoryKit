//
//  HKSDeviceImageItem.h
//  UMCloud
//
//  Created by UMEYE on 15/12/9.
//
//

#import <Foundation/Foundation.h>

@interface HKSDeviceImageItem : NSObject
/** @brief  通道，0开始,0xff所有通道  */
@property(nonatomic, assign) int iChNo;

/** @brief  是否自定义，0：恢复默认,1：设置自定义数据  */
@property(nonatomic, assign) int iCustom;

/** @brief  亮度；0~255  */
@property(nonatomic, assign) int iBrightness;

/** @brief  对比度；0~255  */
@property(nonatomic, assign) int iContrast;

/** @brief  色度；0~255  */
@property(nonatomic, assign) int iHue;

/** @brief  饱和度；0~255  */
@property(nonatomic, assign) int iSaturation;

/** @brief  清晰度，0-255  */
@property(nonatomic, assign) int iResolution;

@end
