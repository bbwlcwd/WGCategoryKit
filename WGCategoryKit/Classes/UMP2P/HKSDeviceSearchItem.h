//
//  HKSDeviceSearchItem.h
//  IPHKPlayer
//
//  Created by George on 13-8-9.
//
//



@interface HKSDeviceSearchItem : NSObject

@property(nonatomic, assign) unsigned int       dwVendorId;//厂商ID
@property(nonatomic, copy) NSString             *sDevModel;//厂商设备型号
@property(nonatomic, copy) NSString             *sUMDevModel;//UM设备型号
@property(nonatomic, copy) NSString             *sDevName;//设备名称
@property(nonatomic, copy) NSString             *sDevId;//设备ID
@property(nonatomic, copy) NSString             *sDevUserName;//设备用户名
@property(nonatomic, copy) NSString             *sDevAddress;//设备地址
@property(nonatomic, assign) int                iDevPort;//设备端口
@property(nonatomic, assign) BOOL               bIfSetPwd;//是否设置了密码
@property(nonatomic, copy) NSString             *sCloudServerAddr;//云服务地址
@property(nonatomic, copy) NSString             *sCustomFlag;//客户端定制表识

@property(nonatomic, assign) unsigned short     usCloudServerPort;//云服务端口号
@property(nonatomic, assign) unsigned short     usChNum;//通道数
@property(nonatomic, assign) int                iDevIdType;//设备ID类型，
@property(nonatomic, assign) BOOL               bIfAllowSetIpaddr;//是否可以设置IP地址
@property(nonatomic, assign) BOOL               bIfEnableDhcp;//是否启用DHCP
@property(nonatomic, assign) int                iAdapterNum;//网卡数
@property(nonatomic, strong) NSMutableArray     *tAdapterTable;//网卡表

@property(nonatomic, assign) BOOL               bIfConnState;//是否有连接状态
@property(nonatomic, assign) UM_NPC_D_MPI_MON_DEV_SRV_CONN_STATE    iSrvConnState;//服务器连接状态，参见NPC_D_MPI_MON_DEV_SRV_CONN_STATE_*定义
@property(nonatomic, assign) NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE   iSrvConnResult;//服务器连接结果，参见NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_*定义
@end
