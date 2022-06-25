

#import "HKSDeviceClient.h"
@class HKSDeviceConfigItem;
@class HKSDeviceTimeItem;
@class HKSDeviceWIFIItem;
@class HKSDeviceSearchAdapterItem;
@class HKSDeviceRecordConfigItem;
@class HKSDeviceTimeConfigItem;
@class HKSDeviceStorageListConfigItem;
@class HKSDeviceInfoItem;
@class HKSDeviceCodecItem;
@class HKSDeviceAlarmMailItem;
@class UMDeviceVideoWidgetItem;

enum {
    /** @brief  设备名称  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_NAME = 1,
    /** @brief  设备有线IP地址  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_IP = 2,
    /** @brief  设备WIFI信息  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_WIFI = 3,
    /** @brief  获取WIFI的AP列表  */
    HKS_NPC_D_PVM_CFG_FUNCID_GET_WIFIAP_LIST = 4,
    /** @brief  编码配置  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_CODEC = 5,
    /** @brief  移动侦测报警参数  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_MOTION_DETECT = 6,
    /** @brief  探头输入报警参数  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_PROBE = 7,
    /// 人行侦测
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_AI = 12,
    /** @brief  设备系统时间  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_SYS_TIME = 20,
    /** @brief  设备信息  */
    HKS_NPC_D_PVM_CFG_FUNCID_DEV_INFO = 21,
};
/** @brief  配置功能ID定义  */
typedef int HKS_NPC_D_PVM_CFG_FUNCID;

enum {
    /** @brief  1080P  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_1080P = 1,
    /** @brief  720P  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_720P = 2,
    /** @brief  D1  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_D1 = 3,
    /** @brief  HD1  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_HD1 = 4,
    /** @brief  BCIF  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_BCIF = 5,
    /** @brief  CIF  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_CIF = 6,
    /** @brief  QCIF  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_QCIF = 7,
    /** @brief  VGA  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_VGA = 8,
    /** @brief  QVGA  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_QVGA = 9,
    /** @brief  SVCD  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_SVCD = 10,
    /** @brief  QQVGA  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_QQVGA = 11,
    /** @brief  SXVGA  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_SXVGA = 12,
    /** @brief  UXGA  */
    HKS_NPC_D_MON_VEDIO_RESOLUTION_UXGA = 13,
};
/** @brief  分辨率  */
typedef int HKS_NPC_D_MON_VEDIO_RESOLUTION;

/**
 *  @brief  设备配置功能类
 */
@interface HKSDeviceClient (Config)

/**
 *  @brief  摄像机WIFI获取
 *
 * @param[HKSDeviceWIFIItem]theWifiItem 上层负责初始化，底层只会把获取到的wifi信息赋值给HKSDeviceWIFIItem对应的属性
 *
 * @return[int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceWifiInfo:(HKSDeviceWIFIItem *)theWifiItem;

/**
 *  @brief  摄像机WIFI AP列表获取
 *
 * @param   [NSMutableArray->HKSWIFIAPItem]theDeviceWIFIList 上层负责初始化，
 底层只会把获取到的wifi AP列表信息赋值给theDeviceWIFIList
 *
 * @return  [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceWifiAPList:(NSMutableArray *)theDeviceWIFIList;

/**
 *  @brief  摄像机WIFI设置
 *
 *  @param  [HKSDeviceWIFIItem]theItem WIFI对象
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceWifiInfo:(HKSDeviceWIFIItem *)theItem;

/**
 *  @brief  获取设备的有线网络数据
 *
 *  @param  [HKSDeviceSearchAdapterItem]outItem 输出获取到的有线网络数据，需要上层初始化
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceIpInfo:(HKSDeviceSearchAdapterItem *)outItem;

/**
 *  @brief  设置设备的有线网络数据
 *
 *  @param  [HKSDeviceSearchAdapterItem]outItem 设置的有线网络数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceIpInfo:(HKSDeviceSearchAdapterItem *)inItem;

/**
 *  @brief  摄像机报警参数获取
 *
 *  @param   [HKSDeviceConfigItem]outAlarmMotionDetect 上层负责初始化，
 底层只会把获取到的wifi信息赋值给HKSDeviceConfigItem对应的属性
 *  @param  [int]theConfigId 报警类型：参见HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_*定义
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceAlarmInfo:(HKSDeviceConfigItem *)outAlarmMotionDetect configId:(int)theConfigId;


/**
 *  @brief  摄像机报警参数获取
 *
 *  @param  [HKSDeviceConfigItem]outAlarmMotionDetect 上层负责初始化，
 底层只会把获取到的wifi信息赋值给HKSDeviceConfigItem对应的属性
 *  @param  [int]theConfigId 报警类型：参见HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_*定义
 *  @param  [BOOL]isVerificationDeviceStatus 是否验证设备连接状态，如果验证，并且当前状态不是连接成功状态，将会进行连接设备操作
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceAlarmInfo:(HKSDeviceConfigItem *)outAlarmMotionDetect configId:(int)theConfigId isVerificationDeviceStatus:(BOOL)isVerifacation;

/**
 *  @brief  摄像机报警参数设置
 *
 *  @param  [HKSDeviceConfigItem]theItem 报警数据对象
 *  @param  [int]theConfigId报警类型 参见HKS_NPC_D_PVM_CFG_FUNCID_DEV_ALARM_*定义
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceAlarmInfo:(HKSDeviceConfigItem *)theItem  configId:(int)theConfigId;

/**
 *  @brief  摄像机参数获取，该接口暂时只有获取图象翻转状态
 *
 *  @param  [HKSDeviceConfigItem]theItem 由外层初始化，赋值属性：iChNo[通道号]、bIfEnable[是否开启]
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceParamInfo:(HKSDeviceConfigItem *)theItem;

/**
 *  @brief  摄像机参数设置，该接口暂时只有设置图象翻转状态
 *
 *  @param  [HKSDeviceConfigItem]theItem 使用属性：iChNo[通道号]、bIfEnable[是否开启]
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceParamInfo:(HKSDeviceConfigItem *)theItem;

/**
 *  @brief  获取录像计划配置(非常规接口，客户定制)
 *
 *  @param  [HKSDeviceRecordConfigItem]outItem 由外层初始化,获取录像配置参数
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceRecordInfo:(HKSDeviceRecordConfigItem *)outItem;

/**
 *  @brief  设置录像计划配置(非常规接口，客户定制)
 *
 *  @param  [HKSDeviceRecordConfigItem]inItem 设置的录像配置参数数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceRecordInfo:(HKSDeviceRecordConfigItem *)inItem;

/**
 *  @brief  获取设备时间
 *
 *  @param  [HKSDeviceTimeConfigItem]outItem 由外层初始化,获取设备时间
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceTimeInfo:(HKSDeviceTimeConfigItem *)outItem;

/**
 *  @brief  设置设备时间
 *
 *  @param  [HKSDeviceTimeConfigItem]inItem 设置的设备时间数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)setDeviceTimeInfo:(HKSDeviceTimeConfigItem *)inItem;

/**
 *  @brief  获取设备存储
 *
 *  @param  [HKSDeviceTimeConfigItem]outItem 由外层初始化,获取设备存储数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceStorageListInfo:(HKSDeviceStorageListConfigItem *)outItem;

/**
 *  @brief  获取设备报警邮件信息
 *
 *  @param  [HKSDeviceAlarmMailItem]outItem 由外层初始化,获取设备报警邮件信息
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceAlertEMailInfo:(HKSDeviceAlarmMailItem *)outItem;

/**
 *  @brief  设置设备报警邮件信息
 *
 *  @param  [HKSDeviceAlarmMailItem]pDeviceInfo 设置设备报警邮件信息数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (HKS_NPC_D_MPI_MON_ERROR)setDeviceAlertEMailInfo:(HKSDeviceAlarmMailItem *)pDeviceInfo;

/**
 *  @brief  格式化设备存储
 *
 *  @param  [HKSDeviceStorageListConfigItem]inItem 格式化设备存储数据
 *
 *  @return [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)deviceStorageFormat:(HKSDeviceStorageListConfigItem *)inItem;


/**
 *  @brief      修改设备密码，调用该接口之前，必须调用setDeviceConnParam接口设置设备数据
 *
 *  @param[in]  in_sPassword[NSString] 新密码
 *  @return     [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.3.4.1
 */
- (int)setDeviceNewPassword:(NSString *)in_sPassword;

/**
 *  @brief      获取设备信息
 *
 *  @param[out]  outItem[HKSDeviceInfoItem] 设备信息
 *  @return     [int]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.4.1.1
 */
- (int)deviceInfo:(HKSDeviceInfoItem *)outItem;

- (int)deviceSystemInfo:(HKSDeviceInfoItem *)outItem;

/**
 *  @brief      获取设备编码
 *
 *  @param[out] out_pCodecInfo[HKSDeviceCodecItem] 设备编码信息
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.4.1.5
 */
- (HKS_NPC_D_MPI_MON_ERROR)deviceCodecInfo:(HKSDeviceCodecItem *)out_pCodecInfo UMP2PDeprecated("该接口已过时");



/**
 *  @brief      设置设备编码
 *
 *  @param[in]  pCodecInfo[HKSDeviceCodecItem] 设备编码信息
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.4.1.5
 */
- (HKS_NPC_D_MPI_MON_ERROR)setDeviceCodecInfo:(HKSDeviceCodecItem *)pCodecInfo UMP2PDeprecated("该接口已过时");


/**
 *  @brief      获取设备通道的名称、是否显示通道名称、是否显示时间信息
 *
 *  @param[in]  aItem[UMDeviceVideoWidgetItem] 所有通道的通道信息数据
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.4.1.5
 */
- (int)deviceVideoWidgetInfo:(UMDeviceVideoWidgetItem *)aItem;



/**
 *  @brief      设置设备通道的名称、是否显示通道名称、是否显示时间信息
 *
 *  @param[in]  aItem[UMDeviceVideoWidgetItem] 所有通道的通道信息数据
 *  @return     [HKS_NPC_D_MPI_MON_ERROR]调用接口是否成功，参见HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since v2.4.1.5
 */
- (int)setDeviceVideoWidgetInfo:(UMDeviceVideoWidgetItem *)aItem;

//请求摄像机远程抓拍图片，并上传到云服务
- (NSString *)deviceTimerSnapshot:(int)aChNo;
@end
