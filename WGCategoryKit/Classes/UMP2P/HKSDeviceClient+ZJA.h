//
//  HKSDeviceClient+ZJA.h
//  UMCloud
//
//  Created by UMEYE on 2016/11/17.
//  众家安
//

#import "HKSDeviceClient.h"
@class UMDoorInfoItem;

@interface HKSDeviceClient (ZJA)


/**
 *  @brief      获取众家安门铃信息
 *
 *  @param[out] aOutItem[UMDoorInfoItem]    获取到的门铃信息
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)doorInfo:(UMDoorInfoItem *)aOutItem;

/**
 *  @brief      修改众家安门铃信息
 *
 *  @param[out] aOutItem[UMDoorInfoItem]    门铃信息
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)modifyDoorInfo:(UMDoorInfoItem *)aOutItem;

/**
 *  @brief      众家安门铃开锁
 *
 *  @param[out] aLockPassword[NSString]    锁密码
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (HKS_NPC_D_MPI_MON_ERROR)doorUnlock:(NSString *)aLockPassword;

/**
 *  @brief      获取电量
 *
 *  @param[out] aPower[int]     电量
 *
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态
 *
 *  @since  v2.7.4.2
 */
- (HKS_NPC_D_MPI_MON_ERROR)doorPower:(int *)aPower;
@end
