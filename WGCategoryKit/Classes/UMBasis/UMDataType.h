///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

enum {
    /** @brief  登录服务器获取列表模式  */
    HKS_NPC_D_MON_CLIENT_MODE_SERCER = 0,
    /** @brief  本地免登录  */
    HKS_NPC_D_MON_CLIENT_MODE_LOCAL = 1,
    /** @brief  本地UMID或者直连方式  */
    HKS_NPC_D_MON_CLIENT_MODE_LOCALUMID = 2,
    /** @brief  本地设备id方式  */
    HKS_NPC_D_MON_CLIENT_MODE_LOCALDEVID = 3,
    /** @brief  本地MP4播放  */
    HKS_NPC_D_MON_CLIENT_MODE_MP4 = 5,
};
/** @brief  客户端连接模式  */
typedef int HKS_NPC_D_MON_CLIENT_MODE;

enum {
    /** @brief  直连模式  */
    HKS_NPC_D_MON_DEV_CONN_MODE_DIRECT = 0,
    /** @brief  流媒体服务器模式  */
    HKS_NPC_D_MON_DEV_CONN_MODE_STREAM = 1,
    /** @brief  P2P云模式  */
    HKS_NPC_D_MON_DEV_CONN_MODE_CLOUD_P2P = 2,
    /** @brief  云流媒体模式  */
    HKS_NPC_D_MON_DEV_CONN_MODE_CLOUD_STREAM = 3,
    /** @brief  未知  */
    HKS_NPC_D_MON_DEV_CONN_MODE_NONE = 4,
};
/** @brief  设备连接模式  */
typedef int HKS_NPC_D_MON_DEV_CONN_MODE;

enum {
    HKS_NPC_D_MON_DEV_CONN_TYPE_NON = 0,
    /** @brief  P2P云模式  */
    HKS_NPC_D_MON_DEV_CONN_TYPE_CLOUD_P2P = 1,
    /** @brief  中转连接  */
    HKS_NPC_D_MON_DEV_CONN_TYPE_TRANS = 2,
    /** @brief  直连模式  */
    HKS_NPC_D_MON_DEV_CONN_TYPE_DIRECT = 3,
    /** @brief  流媒体服务器模式  */
    HKS_NPC_D_MON_DEV_CONN_TYPE_STREAM = 4,
};
/** @brief  设备连接模式  */
typedef int HKS_NPC_D_MON_DEV_CONN_TYPE;

enum {
    /** @brief  根据设备返回的加密类型自动处理，非常非常老的设备sdk版本不支持  */
    HKS_NPC_D_MON_CLIENT_FLAG_AUTO = 0,
    /** @brief  MD5加密  */
    HKS_NPC_D_MON_CLIENT_FLAG_MD5 = 10,
};
/** @brief  设备标识  */
typedef int HKS_NPC_D_MON_CLIENT_FLAG;

enum{
    /** @brief  所有厂家  */
    HKS_NPC_D_MON_VENDOR_ID_ALL = 0,
    /** @brief  华科流媒体协议（bit）  */
    HKS_NPC_D_MON_VENDOR_ID_NSPB = 1001,
    /** @brief  华科流媒体协议（XML）  */
    HKS_NPC_D_MON_VENDOR_ID_NSPX = 1002,
    /** @brief  华科流媒体协议（JSON）  */
    HKS_NPC_D_MON_VENDOR_ID_NSPJ = 1003,
    /** @brief  华科流媒体协议（OWSP）  */
    HKS_NPC_D_MON_VENDOR_ID_OWSP = 1004,
    /** @brief  原华科流媒体服务器协议（HKSP）  */
    HKS_NPC_D_MON_VENDOR_ID_HKSP = 1005,
    /** @brief  文件摄像机协议（FCAM）  */
    HKS_NPC_D_MON_VENDOR_ID_FCAM = 1006,
    /** @brief  华科监控通讯协议（HMCP）  */
    HKS_NPC_D_MON_VENDOR_ID_HMCP = 1007,
    /** @brief  华科设备上连协议（HDTP）NTS  */
    HKS_NPC_D_MON_VENDOR_ID_HDTP = 1008,
    /** @brief  UMSP  */
    HKS_NPC_D_MON_VENDOR_ID_UMSP = 1009,
    /** @brief  EPMY  */
    HKS_NPC_D_MON_VENDOR_ID_EPMY = 1010,
    /** @brief  RTSP  */
    HKS_NPC_D_MON_VENDOR_ID_RTSP = 1010,
    /** @brief  HTTP  */
    HKS_NPC_D_MON_VENDOR_ID_HTTP = 1011,
    /** @brief  SIP  */
    HKS_NPC_D_MON_VENDOR_ID_SIP = 1012,
    /** @brief  RTMP  */
    HKS_NPC_D_MON_VENDOR_ID_RTMP = 1013,
    /** @brief  杭州海康（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_HZHK = 2010,
    /** @brief  杭州海康推模式  */
    HKS_NPC_D_MON_VENDOR_ID_HKPU = 2011,
    /** @brief  杭州大华（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_HZDH = 2020,
    /** @brief  深圳锐明（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SZRM = 2030,
    /** @brief  深圳黄河（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SZHH = 2040,
    /** @brief  深圳汉邦（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SZHB = 2050,
    /** @brief  杭州雄迈（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_HZXM = 2060,
    /** @brief  中山立堡（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_ZSLB = 2070,
    /** @brief  成都索贝（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_CDSB = 2080,
    /** @brief  上海皓维（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SHHW = 2090,
    /** @brief  金三立（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_JSLP = 2100,
    /** @brief  上海通立  */
    HKS_NPC_D_MON_VENDOR_ID_SHTL = 2110,
    /** @brief  深圳郎驰（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SZLC = 2120,
    /** @brief  网视通（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_WST = 2130,
    /** @brief  广州奇幻（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_GZQH = 2140,
    /** @brief  安联锐视（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_ALRS = 2150,
    /** @brief  广州佳可（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_GZJK = 2160,
    /** @brief  深圳旗翰（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_SZQH = 2170,
    /** @brief  瀚晖威视（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_HHWS = 2180,
    /** @brief  杭州智诺（通用参数解析）  */
    HKS_NPC_D_MON_VENDOR_ID_HZZN = 2190,
};
/** @brief  设备协议ID  */
typedef int HKS_NPC_D_MON_VENDOR_ID;


enum{
    /** @brief  所有  */
    HKS_NPC_D_MON_ALARM_TYPE_ALL = 0,
    /** @brief  设备故障报警  */
    HKS_NPC_D_MON_ALARM_TYPE_DEV_FAULT = 1,
    /** @brief  移动侦测报警  */
    HKS_NPC_D_MON_ALARM_TYPE_MOTION = 2,
    /** @brief  视频遮挡报警  */
    HKS_NPC_D_MON_ALARM_TYPE_VIDEO_BLIND = 3,
    /** @brief  视频丢失报警  */
    HKS_NPC_D_MON_ALARM_TYPE_VIDEO_LOSS = 4,
    /** @brief  探头报警（外部输入报警）  */
    HKS_NPC_D_MON_ALARM_TYPE_PROBE = 5,
    /** @brief  人体感应报警  */
    HKS_NPC_D_MON_ALARM_TYPE_PIR = 6,
    /** @brief  门铃报警  */
    HKS_NPC_D_MON_ALARM_TYPE_DOORBELL = 7,
    /** @brief  硬盘错误  */
    HKS_NPC_D_MON_ALARM_TYPE_HDD_ERROR = 8,
    /** @brief  硬盘满  */
    HKS_NPC_D_MON_ALARM_TYPE_HDD_FULL = 9,
    /** @brief  越线侦测报警  */
    HKS_NPC_D_MON_ALARM_TYPE_SMART_IPC_CROSS_LINE = 10,
    /** @brief  区域入侵报警  */
    HKS_NPC_D_MON_ALARM_TYPE_SMART_IPC_AREA_INTRUSION = 11,
    /** @brief  区域进入报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_AREA_IN = 12,
    /** @brief  区域离开报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_AREA_OUT = 13,
    /** @brief  物品遗留报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_OBJECT_FORGET = 14,
    /** @brief  物品拾取报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_OBJECT_PICKUP = 15,
    /** @brief  快速移动  */
    HKS_NPC_D_MON_ALARM_TYPE_MOTION_FAST = 16,
    /** @brief  人脸识别  */
    HKS_NPC_D_MON_ALARM_TYPE_FACE_RECOGNITION = 17,
    /** @brief  敲门报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_KNOCK = 18,
    /** @brief  徘徊侦测报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_WANDER_DETECT = 19,
    /** @brief  停车侦测报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_AREA_PARK = 20,
    /** @brief  人员聚集报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SMART_IPC_AREA_CROWD = 21,
    /** @brief  黑名单报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_FACE_BLACK = 22,
    /** @brief  白名单报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_FACE_WHITE = 23,
    /** @brief  人员聚集报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_FACE_NON_WHITE = 24,
    /** @brief  目标计数报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_TARGET_CONNT = 25,
    /** @brief  温度报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_TEMPERATURE = 26,
    /** @brief  声音报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_SOUND = 27,
    /** @brief  VIP报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_FACE_VIP = 28,
    /** @brief  陌生人报警  */
    HKS_NPC_D_MON_CSD_ALARM_EVENT_STRANGER_MODE = 29,
    /// 人员提醒
    HKS_NPC_D_MON_CSD_ALARM_EVENT_PERSON_ALERT = 30,
    /// 车辆提醒
    HKS_NPC_D_MON_CSD_ALARM_EVENT_VEHICLE_ALERT = 31,
    /// 访客呼叫
    HKS_NPC_D_MON_CSD_ALARM_EVENT_VISITOR_CALL = 32,
    /// 人行侦测
    HKS_NPC_D_MON_CSD_ALARM_EVENT_AI = 33
};
/** @brief  报警类型定义  */
typedef int HKS_NPC_D_MON_ALARM_TYPE;


enum {
    /** @brief  目录名  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_DIR = 0,
    /** @brief  DVR  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_DVR = 1,
    /** @brief  镜头或者通道  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_CAMERA = 2,
    /** @brief  已过时  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_IPC = 3,
    /** @brief  智能家居  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_SMART = 4,
    /** @brief  智能家居单品  */
    HKS_NPC_D_MPI_MON_DEV_NODE_TYPE_SMART_CH = 5,
};
/** @brief  设备目录结点类型  */
typedef int HKS_NPC_D_MPI_MON_DEV_NODE_TYPE;

enum {
    /** @brief  DVR  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_DVR = 0,
    /** @brief  镜头或者通道  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_DVR_CH = 1,
    /** @brief  开关  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_SWITCH = 2,
    /** @brief  开关通道  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_SWITCH_CH = 3,
    /** @brief  鱼眼  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_FISHEYE = 4,
    /** @brief  鱼眼通道  */
    HKS_NPC_D_MPI_MON_DEV_TYPE_FISHEYE_CH = 5,
};
/** @brief  设备目录结点类型  */
typedef int HKS_NPC_D_MPI_MON_DEV_TYPE;

#define HKS_NPC_D_MON_VENDOR_TITLE_SDK  @"sdk"//SDK定制标识,请主动联系具体人员分配唯一的客户端标识,避免发生其他问题.

//对讲类型
#define		HKS_NPC_D_AUDIO_PCM	    	10
#define		HKS_NPC_D_AUDIO_G711a		11
#define		HKS_NPC_D_AUDIO_AMRNB		12
#define		HKS_NPC_D_AUDIO_AMRWB		13
#define		HKS_NPC_D_AUDIO_AAC         14
#define		HKS_NPC_D_AUDIO_ADPCM		15
#define		HKS_NPC_D_AUDIO_QIHANADPCM	16


//客户端类型定义
#define HKS_NPC_D_MON_CLIENT_TYPE_PC								1				//PC客户端
#define HKS_NPC_D_MON_CLIENT_TYPE_IPHONE							2				//IPHONE
#define HKS_NPC_D_MON_CLIENT_TYPE_ANDRIOD_PHONE						3				//ANDRIOD手机
#define HKS_NPC_D_MON_CLIENT_TYPE_IPAD								4				//IPAD
#define HKS_NPC_D_MON_CLIENT_TYPE_ANDRIOD_PANEL						5				//ANDRIOD平板
#define HKS_NPC_D_MON_CLIENT_TYPE_WEB_OCX							6				//WEB控件
#define HKS_NPC_D_MON_CLIENT_TYPE_VIALARM_PC						30				//小区报警监听PC客户端

//客户端连接状态
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_NO_INIT     -1          //客户端未初始化
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_NO_CONNECT	0			//未连接服务器
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECTING	1			//正在连接服务器
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECT_OK	2			//已连接服务器但未登录
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_LOGIN_OK	3			//已登录状态并连接正常
#define HKS_NPC_D_MPI_MON_CLIENT_CONN_STATE_DISCONNECT	4			//连接断开状态


//客户端断开连接原因
#define HKS_NPC_D_MPI_MON_CLIENT_DISCAUSE_PEER_CLOSE				1			//对端关闭连接
#define HKS_NPC_D_MPI_MON_CLIENT_DISCAUSE_LOGIN_FAIL				2			//登录失败而断开连接
#define HKS_NPC_D_MPI_MON_CLIENT_DISCAUSE_RECV_ERR_PACK				3			//接收到错误数据包而本端主动关闭连接
#define HKS_NPC_D_MPI_MON_CLIENT_DISCAUSE_RESP_TIMEOUT				4			//等待应答消息超时而本端主动关闭连接
#define HKS_NPC_D_MPI_MON_CLIENT_DISCAUSE_HEART_TIMEOUT				5			//等待心跳应答消息超时而本端主动关闭连接


#define HKS_NPC_D_MPI_MON_LOGIN_TYPE_PUBLICT                        1           //通用
#define HKS_NPC_D_MPI_MON_LOGIN_TYPE_PUBLICTEST                     2           //中性版本类型 “publictest”


//推送消息类型
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_CONFIG							1			//配置参数
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_ORDER							2			//服务器推送命令
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_PROMPT							3			//服务器推送提示消息
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_DEVN_UPDATE_NODE				4			//服务器推送设备变更：更新结点（添加、修改）
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_DEVN_DEL_NODE					5			//服务器推送设备变更：删除结点（设备或目录
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_UPDATE_GPOP						6			//服务器推送全局权限变更
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_DEV_ALARM						7			//服务器推送设备报警消息
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_DEVN_UPDATE_NODE_ADD			100			//服务器推送全局权限变更:添加节点
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_DEVN_UPDATE_NODE_UPDATE			101			//服务器推送全局权限变更:修改节点
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_REQU_REFRESH_DEVLIST			9			//请求上层刷新设备列表
#define HKS_NPC_D_MPI_MON_PUSH_TYPE_RE_LOGIN_NOTIFY					10			//密码被其它用户修改

//用户权限定义
#define HKS_NPC_D_MPI_MON_USER_POP_ADD_CAMERA						1			//添加摄像机或目录（仅限于全局权限）
#define HKS_NPC_D_MPI_MON_USER_POP_DEL_CAMERA						2			//删除摄像机或目录（仅限于全局权限）
#define HKS_NPC_D_MPI_MON_USER_POP_CH_CAMERA_CONN_PARAM				3			//修改摄像机连接参数（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_CH_CAMERA_NAME					4			//修改摄像机名称（全局/设备权限）

#define HKS_NPC_D_MPI_MON_USER_POP_TRY_DISABLE						60			//试用禁用（设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_REALPLAY							61			//实时预览（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_MANUAL_RECORD					62			//手动录像（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_PTZ								63			//云台控制（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_BACKPLAY							64			//回放录像（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_RECV_ALARM						65			//接收报警（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_DEV_EMP							66			//设备授权（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_ARMING							67			//布防撤防（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_VOC_TALK							68			//语音对讲（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_LOCAL_RECORD                     69			//本地录像（全局/设备权限）
#define HKS_NPC_D_MPI_MON_USER_POP_LOCAL_PHOTO                      70			//本地拍照（全局/设备权限）


//语言种类定义
#define HKS_NPC_D_MON_LANGUAGE_EN                                   @"English"          //英语
#define HKS_NPC_D_MON_LANGUAGE_ZH_HANS                              @"SimpChinese"      //简体
#define HKS_NPC_D_MON_LANGUAGE_ZH_HANT                              @"TradChinese"      //繁体

//演示点语言定义
#define HKS_NPC_D_MON_LAND_KIND_SIMPCHINESE							0				//简体中文
#define HKS_NPC_D_MON_LAND_KIND_ENGLISH								1				//英文

//连接模式，0：P2P直连，1：流媒体分发，2：云。
//注意：已过时，请使用HKS_NPC_D_MON_DEV_CONN_MODE
#define HKS_NPC_D_MON_CONN_MODE_P2P                                 0
#define HKS_NPC_D_MON_CONN_MODE_STREAM								1
#define HKS_NPC_D_MON_CONN_MODE_CLOUD								2

//修改设备密码状态
#define HKS_NPC_D_MON_USERPWD_START_MODIFY      0
#define HKS_NPC_D_MON_USERPWD_END_MODIFY        1


//报警通知类型定义
#define HKS_NPC_D_MON_ALARM_NOTIFY_TYPE_PHONE_PUSH					1				//手机推送消息
#define HKS_NPC_D_MON_ALARM_NOTIFY_TYPE_SMS							2				//短信
#define HKS_NPC_D_MON_ALARM_NOTIFY_TYPE_EMAIL						3				//EMAIL

//报警联动类型定义
#define HKS_NPC_D_MON_ALARM_ACTION_TYPE_PHOTO						1				//拍照
#define HKS_NPC_D_MON_ALARM_ACTION_TYPE_VIDEO						2				//录像
#define HKS_NPC_D_MON_ALARM_ACTION_TYPE_PTZ							3				//PTZ联动


//录像回放或点播控制码定义
#define HKS_NPC_D_MON_PLAY_CTRL_PAUSE								1				//暂停（无参数）
#define HKS_NPC_D_MON_PLAY_CTRL_RESUME								2				//继续（无参数）
#define HKS_NPC_D_MON_PLAY_CTRL_SET_FRAME_RATE						3				//设置帧率（参数为帧率）
#define HKS_NPC_D_MON_PLAY_CTRL_SET_PLAY_POS						4				//设置播放位置（参数为位置（秒））
#define HKS_NPC_D_MON_PLAY_CTRL_SET_FAST_FORWARD					5				//快进（无参数），保持原帧率，丢掉部分帧
#define HKS_NPC_D_MON_PLAY_CTRL_SET_SLOW_FORWARD					6				//慢进（无参数）
#define HKS_NPC_D_MON_PLAY_CTRL_SET_FAST_BACKWARD					7				//快退（无参数），保持原帧率，丢掉部分帧
#define HKS_NPC_D_MON_PLAY_CTRL_SET_SLOW_BACKWARD					8				//慢退（无参数）
#define HKS_NPC_D_MON_PLAY_CTRL_SET_FRAME_FORWARD					9				//单帧进（无参数）
#define HKS_NPC_D_MON_PLAY_CTRL_SET_FRAME_BACKWARD					10				//单帧退（无参数）

#define HKS_NPC_D_MON_PLAY_CTRL_ONLY_IFRAME							11				//请求只回放I帧数据（参数为丢弃I帧数，0：不丢I帧，1：丢弃1个I帧（即间隔1个I帧传输），2：丢弃2个I帧，如此类推）
#define HKS_NPC_D_MON_PLAY_CTRL_RECOVER_ALLFRAME					12				//请求恢复回放全帧数据（无参数）


//设备厂家标识
#define HKS_NPC_D_MON_DEV_VENDOR_TITLE_Def                          @"def"                              //默认
#define HKS_NPC_D_MON_DEV_VENDOR_TITLE_QianMing                     @"qianming"                         //乾明
#define HKS_NPC_D_MON_DEV_VENDOR_TITLE_TDKS                         @"tdks"                             //TDKS
#define HKS_NPC_D_MON_DEV_VENDOR_TITLE_HZTS                         @"hzts"                             //HZTS

//功能配置ID定义
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAIN_STREAM             @"open_main_stream"                 //打开主码流
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_P2P_CONNMODE            @"open_p2p_connmode"                //打开直连地址
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_DEVICE_ADDDVR           @"open_adddvr_devicemanage"         //支持添加设备
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_DEVICE_MODIFY_IP        @"open_modify_ip_devicesearch"      //设备搜索是否支持修改设备ip
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_DEVICE_MODIFY_Password  @"open_modify_pwd_devicesearch"     //设备搜索是否支持修改设备密码
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_DEVICE_POP_ADDDEV       @"open_pop_adddvr_devicemanage"     //打开添加设备权限,默认:NO
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_ALARM_SMS               @"open_sms_alarm"                   //打开短息通知
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_ALARM_PUSH              @"open_push_alarm"                  //打开推送通知
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_ALARM_DEFAULTPUSH       @"open_defaultpush_alarm"           //是否开启默认推送功能，即在报警管理中布防时就默认开启推送。0：禁用，1：启用。

#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_DEVICE_SEARCH           @"open_search_device"               //打开设备搜索
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_DEVICEMANAGE   @"open_devicemanage_mainmenu"       //打开设备管理
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_BACKPLAY       @"open_backplay_mainmenu"           //打开远程回放
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_ALARM          @"open_alarm_mainmenu"              //打开报警管理
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_MODIFYPASSWORD @"open_modifypassword_mainmenu"     //打开修改密码
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_LOCALCONFIG    @"open_localconfig_mainmenu"        //打开本地配置
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_HELP           @"open_help_mainmenu"               //打开帮助
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_MAINMENU_MP3            @"open_mp3_mainmenu"                //打开MP3,默认:NO
#define HKS_NPC_D_MON_VENDOR_TITLE_KEY_OPEN_LIVEPRE_ALARMPTZ        @"open_alarmptz_livepre"            //打开设备开启布防支持云台控制

#define IOS_VERSION_DEPRECATED(_info) __attribute__((deprecated(_info)))

