///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

///#begin zh-cn
/**
 *  @class      设备数据对象
 *  @brief      设备对象
 */
///#end
///#end
#import <UIKit/UIKit.h>
/** @brief  零通道 */
#define HKS_NPC_D_DPS_CHANNEL_VALUE_ZERO    10000

@interface TreeListItem : NSObject<NSCoding>

/////////////////////////////////////////////////////////
///////////////////////获取设备节点使用字段//////////////////
/** @brief  结点ID,值大于0 */
@property (nonatomic, copy) NSString            *sNodeId;
/** @brief  父级结点ID,如果为0，表示查询顶层结点 */
@property (nonatomic, copy) NSString            *sParentNodeId;
/** @brief  父结点类型,底层为赋值，预留给上层使用 */
@property (nonatomic, assign) int               dwParentNodeType;
/** @brief  设备名称 */
@property (nonatomic, copy) NSString            *sNodeName;
/** @brief  设备ID，登录模式情况下，可以直接使用设备id建立连接 */
@property (nonatomic, copy) NSString            *sDevId;
/** @brief  结点类型,参见HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_*定义 */
@property (nonatomic, assign) HKS_NPC_D_MPI_MON_DEV_NODE_TYPE   iNodeType;
/** @brief  连接类型,参考HKS_NPC_D_MON_DEV_CONN_MODE_*定义 */
@property (nonatomic, assign) HKS_NPC_D_MON_DEV_CONN_MODE       iConnMode;
@property (nonatomic, assign) HKS_NPC_D_MPI_MON_DEV_TYPE        iDevType;
/** @brief  结点归属类型，0：正常设备，1：设备组设备，2：授权设备 */
@property (nonatomic, assign) int               iIdType;
/** @brief  授权状态：0表示授权设备，1表示非授权设备 */
@property (nonatomic, assign) int               ucNodeKind;
/** @brief  设备在线状态，0：离线，1：在线 */
@property (nonatomic, assign) int               ucDevState;
/** @brief  umid，只有在iConnMode为云穿透模式时候才有值 */
@property(nonatomic, copy) NSString *sDeviceId;
/** @brief  设备厂家id,具体请参考HKS_NPC_D_MON_VENDOR_ID_* */
@property(nonatomic, assign) int    iVendorId;
/** @brief  设备IP地址，只有在iConnMode为直连模式时候才有值 */
@property(nonatomic, copy) NSString *sAddress;
/** @brief  设备端口，只有在iConnMode为直连模式时候才有值 */
@property(nonatomic, assign) int    iPort;
/** @brief  设备用户名 */
@property(nonatomic, copy) NSString *sUserId;
/** @brief  设备密码 */
@property(nonatomic, copy) NSString *sUserPwd;
/** @brief  设备通道,iNodeType为DVR的时候为设备通道数，从1开始.为CAMERA的时候为通道号，从0开始 */
@property(nonatomic, assign) int    iChannel;
/** @brief  设备码流 */
@property(nonatomic, assign) int    iStream;
/** @brief  自定义参数,63 */
@property(nonatomic, copy) NSString *sCustomParam;
///////////////////////获取设备节点使用字段//////////////////
/////////////////////////////////////////////////////////

/** @brief  设备mac地址 */
@property(nonatomic, copy) NSString *sAdapterMac;
/** @brief  分享名称 */
@property (nonatomic, copy) NSString            *sShareName;
/** @brief  图片链接 */
@property (nonatomic, copy) NSString            *sPicLink;
/** @brief  布放校验码 */
@property (nonatomic, copy) NSString            *sVerifyCode;

//////////////////////////////////////////////////////
//////////////////已过时///////////////////////////////
/** @brief  结点ID,值大于0,已过时 */
@property (nonatomic, assign) int               dwNodeId;
/** @brief  父级结点ID,如果为0，表示查询顶层结点,已过时 */
@property (nonatomic, assign) int               dwParentNodeId;
/** @brief  是否支持云台，已过时 */
@property (nonatomic, assign) int               ucIfPtz;
/** @brief  设备布放状态，已过时 */
@property (nonatomic, assign) BOOL              bIfSetAlarm;
/** @brief  推送消息类型，已过时 */
@property (nonatomic, assign) int               iMsgType;
/** @brief  提示消息ID，值大于0，为0表示没有提示消息，已过时 */
@property (nonatomic, assign) int               iPromptId;
/** @brief  消息内容，已过时 */
@property (nonatomic, copy) NSString            *msg;
/** @brief  是否支持经纬度，已过时 */
@property (nonatomic, assign) int               ucIfLongLat;
/** @brief  纬度，已过时 */
@property (nonatomic, copy) NSString            *latitude;
/** @brief  经度，已过时 */
@property (nonatomic, copy) NSString            *longtitude;
/** @brief  服务器地址，已过时 */
@property (nonatomic, copy) NSString            *serverAddress;
/** @brief  服务器端口，已过时 */
@property (nonatomic, assign) int               serverPort;
/** @brief  码流是否改变，已过时 */
@property(nonatomic, assign) BOOL   bIfStream;
//////////////////已过时///////////////////////////////
//////////////////////////////////////////////////////

/** @brief  预留上层使用 */
@property (nonatomic, assign) BOOL              bGroup;
/** @brief  节点级别，预留上层使用 */
@property (nonatomic, assign) int               iLevel;
/** @brief  设备缩略图片url，预留上层使用 */
@property (nonatomic, copy) NSString            *thumbnailsPath;
/** @brief  设备缩略图片，预留上层使用 */
@property (nonatomic, strong) UIImage           *thumbnailsImage;
/** @brief  是否显示该节点下面的设备，预留上层使用 */
@property (nonatomic, assign) BOOL              isOpen;
/** @brief  扩充参数，预留上层使用 */
@property (nonatomic, assign) BOOL              isSelect;
/** @brief  扩充参数，预留上层使用 */
@property (nonatomic, assign) int               iParam1;
/** @brief  扩充参数，预留上层使用 */
@property (nonatomic, assign) int               iParam2;
/** @brief  扩充参数，预留上层使用 */
@property (nonatomic, copy) NSString            *sParam1;
/** @brief  扩充参数，预留上层使用 */
@property (nonatomic, copy) NSString            *sParam2;
/** @brief  当前节点下一级子节点个数，预留上层使用 */
@property (nonatomic, assign) int               numofChild;
/** @brief  当前节点的全部子节点个数，预留上层使用 */
@property (nonatomic, assign) int               allChild;

@property (nonatomic, assign) int               share_type;
@property (nonatomic, copy) NSString            *sLinkId;
/// 分享源
@property (nonatomic, copy) NSString            *sShareSou;
/// 接收者
@property (nonatomic, copy) NSString            *sShareTo;
@property (nonatomic, copy) NSMutableArray      *tDevRights;
@property (nonatomic, assign) int   ucNodeOwnerType;

+ (instancetype)setup:(NSDictionary *)params;

/// 两个函数匹配使用
+ (TreeListItem *)nodeAtNodeDic:(NSMutableDictionary *)aNodeDic;
- (NSMutableDictionary *)nodeDic;

- (void)detailString;
@end
