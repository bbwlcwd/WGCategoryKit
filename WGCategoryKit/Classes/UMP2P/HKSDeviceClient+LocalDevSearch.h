//
//  HKSDeviceClient+Tools.h
//  Created by Fred on 10-8-18.
//  Copyright 2010 UMEYE. All rights reserved.
//
//

#import "HKSDeviceClient.h"
@class HKSDeviceSearchItem;
@class HKSDeviceSearchAdapterItem;


/**
 *  @brief      局域网设备搜索
 */
@interface HKSDeviceClient (LocalDevSearch)


/**
 *  @brief      开始搜索设备
 *  255.255.255.255
 */
+ (void)startSearchDevice;

/**
 *  @brief      开始搜索设备
 *  根据动态获取的广播地址
 */
+ (void)startSearchDeviceByDynamicBroadcastAddress;

/**
 *  @brief          获取搜索到的设备数据,因为是通过局域网发送广播的形式,进行搜索,所以该接口需要调用多次,才会有数据
 *  @param[out]     deviceSearchArray[NSMutableArray->HKSDeviceSearchItem]输出变量,需要外部分配好空间,内部将会把获取到的数据填充进去
 *  @return[int]    返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
+ (int)getSearchDevTable:(NSMutableArray *)deviceSearchArray;


/**
 *  @brief      释放搜索内存,搜索完成以后必须调用该接口
 */
+ (void)stopSearchDevice;


/**
 *  @brief      修改本地设备密码
 *  @param[in]  item[TreeListItem]:修改的设备对象
 *  @param[in]  oldPwd[NSString]:原密码
 *  @param[in]  newPwd[NSString]:新密码
 *
 *  @return[int]    返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
+ (int)modifyDevPassword:(TreeListItem *)item oldPwd:(NSString *)oldPwd newPwd:(NSString *)newPwd;


/**
 *  @brief      修改本地设备网络参数
 *  @param[in]  deviceSearchItem[HKSDeviceSearchItem]:设备的设备对象,使用的字段:
    sDevId[NSString]:设备ID
    dwVendorId[int]:厂商ID
    sOldIpaddr[NSString]:原IP地址
 
 *  @param[in]  deviceSearchAdapterItem[HKSDeviceSearchAdapterItem]:新的网络参数对象
 *  @param[in]  oldPwd[NSString]:原密码
 *  @param[in]  newPwd[NSString]:新密码
 *  @param[in]  bDhcpEnable[BOOL]:dhcp
 *
 *  @return[int]    返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
+ (int)modifyDevIpaddr:(HKSDeviceSearchItem *)deviceSearchItem oldIpaddr:(NSString *)sOldIpaddr newAdapterItem:(HKSDeviceSearchAdapterItem *)deviceSearchAdapterItem;


/**
 *  @brief      修改本地设备网络参数
 *  @param[in]  deviceSearchItem[HKSDeviceSearchItem]:设备对象,使用的字段:
    sDevId[NSString]:设备ID
    dwVendorId[int]:厂商ID
    sDevName[NSString]:修改后的新名称
 
 *  @param[in]  deviceSearchAdapterItem[HKSDeviceSearchAdapterItem]:网卡对象,使用的字段:
    sAdapterMac[NSString]:网卡MAC地址，格式为XX-XX-
 *
 *  @return[int]    返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
+ (int)modifyDevName:(HKSDeviceSearchItem *)deviceSearchItem newAdapterItem:(HKSDeviceSearchAdapterItem *)deviceSearchAdapterItem;


/**
 *  @brief      启动/关闭 DHCP
 *  @param[in]  deviceSearchItem[HKSDeviceSearchItem]:设备对象,使用的字段:
    sDevId[NSString]:设备ID
    dwVendorId[int]:厂商ID
    bIfEnableDhcp[BOOL]:是否启动DHCP
 
 *  @param[in]  deviceSearchAdapterItem[HKSDeviceSearchAdapterItem]:网卡对象,使用的字段:
    sAdapterMac[NSString]:网卡MAC地址，格式为XX-XX-
    sAdapterName[NSString]://网卡名称
 *
 *  @return[int]    返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
+ (int)modifyDevDevDhcp:(HKSDeviceSearchItem *)deviceSearchItem newAdapterItem:(HKSDeviceSearchAdapterItem *)deviceSearchAdapterItem;
@end
