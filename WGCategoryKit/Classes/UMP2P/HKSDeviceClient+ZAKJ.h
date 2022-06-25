//
//  HKSDeviceClient+ZAKJ.h
//  UMCloud
//
//  Created by fred on 2017/6/23.
//  Copyright © 2017年 Fred. All rights reserved.

#import "HKSDeviceClient.h"
@class HKSDeviceImageItem;

@interface HKSDeviceClient (ZAKJ)

/**
 *  @brief      开门控制
 *
 *  @param[in] aIndex[int]          开门位置:1、2
 *  @param[in] iControl[int]        1:关门，2:开门
 *  @param[in] isPwd[BOOL]          是否需要密码
 *  @param[in] aPasswd[NSString]    密码
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)lockControlZAKJ:(int)aIndex
                                   control:(int)iControl
                                     isPwd:(BOOL)isPwd
                                    passwd:(NSString *)aPasswd;

/**
 *  @brief      获取图像颜色
 *
 *  @param[in] aItem[HKSDeviceImageItem]    图片颜色对象，需要填写正确的通道号
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)imageRGBZAKJ:(HKSDeviceImageItem *)aItem;

/**
 *  @brief      设置图像颜色
 *
 *  @param[in] aItem[HKSDeviceImageItem]    图片颜色对象
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)setImageRGBZAKJ:(HKSDeviceImageItem *)aItem;


/**
 *  @brief      是否需要更新
 *
 *  @param[in]  aVer[NSString]  版本号
 *  @param[out] isUpdate[int]   是否需要更新
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)queryIsUpdateZAKJ:(NSString *)aVer isUpdate:(int *)isUpdate;

/**
 *  @brief      请求升级
 *
 *  @param[in]  aVer[NSString]      版本号
 *  @param[in]  aFileSize[int]      文件大小
 *  @param[in]  aFileUrl[NSString]  文件URL,1.2.3.4:2011
 *  @param[in]  aUserId[NSString]   url用户名
 *  @param[in]  aUserPwd[NSString]  url密码
 *  @param[out] iUpgradeId[int]     升级ID
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)requUpdateZAKJ:(NSString *)aVer
                                 fileSize:(int)aFileSize
                                  fileUrl:(NSString *)aFileUrl
                                   userId:(NSString *)aUserId
                                  userPwd:(NSString *)aUserPwd
                                upgradeId:(int *)iUpgradeId;

/**
 *  @brief      查询更新进度
 *
 *  @param[in]  iUpgradeId[int] 升级ID
 *  @param[out] iPos[int]       进度
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)queryUpdatePosZAKJ:(int)iUpgradeId pos:(int *)iPos;

- (void)zakjTimeZone:(UMDevClientTask)task;
- (void)zakjSetTimeZone:(UMDevClientTask)task param:(id)param;

@end
