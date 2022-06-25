///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

enum {
    /** @brief  成功  */
    HKS_NPC_D_MPI_MON_ERROR_SUC                         = 0,
    /** @brief  注册数据为空  */
    HKS_NPC_D_MPI_MON_ERROR_REGISTER_FAIL               = 9999,
    /** @brief  操作失败  */
    HKS_NPC_D_MPI_MON_ERROR_FAIL                        = 9998,
    /** @brief  读取数据失败  */
    HKS_NPC_D_MPI_MON_ERROR_FILE_READ_FAIL              = 9997,
    /** @brief  保存数据失败  */
    HKS_NPC_D_MPI_MON_ERROR_FILE_SAVE_FAIL              = 9996,
    /** @brief  本地模式模式下不支持该功能  */
    HKS_NPC_D_MPI_MON_ERROR_LOCAL_FAIL                  = 9995,
    /** @brief  远程录像搜索失败  */
    HKS_NPC_D_MPI_MON_ERROR_REC_SEARCH_FAIL             = 9994,
    /** @brief  客户端定制标识错误,请联系业务人员  */
    HKS_NPC_D_MPI_MON_ERROR_CLIENT_FLAG                 = 9993,
    /** @brief  门锁密码错误  */
    HKS_NPC_D_MPI_MON_ERROR_DOOR_PWD                    = 9992,
    /** @brief  系统错误  */
    HKS_NPC_D_MPI_MON_ERROR_SYS_ERROR                 = 1,
    /** @brief  连接失败  */
    HKS_NPC_D_MPI_MON_ERROR_CONNECT_FAIL              = 2,
    /** @brief  访问数据库失败,网络不稳定  */
    HKS_NPC_D_MPI_MON_ERROR_DBACCESS_FAIL             = 3,
    /** @brief  分配资源失败,可能是网络不稳定  */
    HKS_NPC_D_MPI_MON_ERROR_ALLOC_RES_FAIL            = 4,
    /** @brief  内部操作失败，如内存操作失败  */
    HKS_NPC_D_MPI_MON_ERROR_INNER_OP_FAIL             = 5,
    /** @brief  执行命令调用失败,可能是网络不稳定  */
    HKS_NPC_D_MPI_MON_ERROR_EXEC_ORDER_CALL_FAIL      = 6,
    /** @brief  执行命令结果失败,可能是网络不稳定  */
    HKS_NPC_D_MPI_MON_ERROR_EXEC_ORDER_RET_FAIL       = 7,
    /** @brief  文件不存在  */
    HKS_NPC_D_MPI_MON_ERROR_FILE_NONENTITY            = 8,
    /** @brief  未知，其它原因失败  */
    HKS_NPC_D_MPI_MON_ERROR_OTHER_FAIL                = 9,
    /** @brief  网络错误  */
    HKS_NPC_D_MPI_MON_ERROR_NET_ERROR                 = 10,
    /** @brief  服务器请求客户端重定向  */
    HKS_NPC_D_MPI_MON_ERROR_REDIRECT                  = 11,
    /** @brief  传入参数格式错误,如UMID没有12位  */
    HKS_NPC_D_MPI_MON_ERROR_PARAM_ERROR               = 12,
    /** @brief  错误的功能ID消息，当前服务器不支持该功能  */
    HKS_NPC_D_MPI_MON_ERROR_ERROR_FUNCID              = 13,
    /** @brief  该消息ID已过时，即已作废，当前服务器不支持该功能  */
    HKS_NPC_D_MPI_MON_ERROR_MSG_PAST_TIME             = 14,
    /** @brief  系统未授权  */
    HKS_NPC_D_MPI_MON_ERROR_SYS_NO_GRANT              = 15,
    /** @brief  网络错误，解析域名失败  */
    HKS_NPC_D_MPI_MON_ERROR_DNS_FAIL                  = 16,
    /** @brief  用户名格式错误  */
    HKS_NPC_D_MPI_MON_ERROR_USERNAME_FORMAT_ERROR     = 17,
    /** @brief  等待应答消息超时  */
    HKS_NPC_D_MPI_MON_ERROR_RESP_TIMEOUT              = 18,
    /** @brief  协议错误  */
    HKS_NPC_D_MPI_MON_ERROR_PROTOCOL_ERROR            = 19,
    /** @brief  用户ID或用户名错误  */
    HKS_NPC_D_MPI_MON_ERROR_USERID_ERROR              = 101,
    /** @brief  用户密码错误  */
    HKS_NPC_D_MPI_MON_ERROR_USERPWD_ERROR             = 102,
    /** @brief  用户名或密码错误  */
    HKS_NPC_D_MPI_MON_ERROR_USER_PWD_ERROR            = 103,
    /** @brief  正在连接  */
    HKS_NPC_D_MPI_MON_ERROR_CONNECTING                = 104,
    /** @brief  已连接  */
    HKS_NPC_D_MPI_MON_ERROR_CONNECTED                 = 105,
    /** @brief  播放失败  */
    HKS_NPC_D_MPI_MON_ERROR_PLAY_FAIL                 = 106,
    /** @brief  未连接摄像机  */
    HKS_NPC_D_MPI_MON_ERROR_NO_CONNECT_CAMERA         = 107,
    /** @brief  正在播放  */
    HKS_NPC_D_MPI_MON_ERROR_PLAYING                   = 108,
    /** @brief  未播放  */
    HKS_NPC_D_MPI_MON_ERROR_NO_PLAY                   = 109,
    /** @brief  不支持的厂家  */
    HKS_NPC_D_MPI_MON_ERROR_NONSUP_VENDOR             = 110,
    /** @brief  权限不够  */
    HKS_NPC_D_MPI_MON_ERROR_REJECT_ACCESS             = 111,
    /** @brief  摄像机离线  */
    HKS_NPC_D_MPI_MON_ERROR_CAMERA_OFFLINE            = 112,
    /** @brief  帐号已登录  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_LOGINED           = 113,
    /** @brief  用户帐号已过有效期  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_HAVE_EXPIRED      = 114,
    /** @brief  用户帐号未激活  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_NO_ACTIVE         = 115,
    /** @brief  用户帐号已欠费停机  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_DEBT_STOP         = 116,
    /** @brief  用户已注册  */
    HKS_NPC_D_MPI_MON_ERROR_USER_EXIST                = 117,
    /** @brief  该用户名不允许注册（不在许可表中）  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_NOPERM      = 118,
    /** @brief  不允许注册（在黑名单中）  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_ATBLACK     = 119,
    /** @brief  验证码已过期  */
    HKS_NPC_D_MPI_MON_ERROR_SECCODE_HAVE_EXPIRED      = 120,
    /** @brief  验证码错误  */
    HKS_NPC_D_MPI_MON_ERROR_SECCODE_ERROR             = 121,
    /** @brief  帐号已存在  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST             = 122,
    /** @brief  无空闲流媒体服务器  */
    HKS_NPC_D_MPI_MON_ERROR_NO_IDLE_STREAMSERVER      = 123,
    /** @brief  用户未登录  */
    HKS_NPC_D_MPI_MON_ERROR_USER_NO_LOGIN             = 124,
    /** @brief  帐号长度错误  */
    HKS_NPC_D_MPI_MON_ERROR_ACCOUNT_LEN_ERROR         = 125,
    /** @brief  接收授权的用户ID不存在  */
    HKS_NPC_D_MPI_MON_ERROR_EMP_ACC_USERID_NOT_EXIST  = 126,
    /** @brief  当前的IP地址禁止登录  */
    HKS_NPC_D_MPI_MON_ERROR_IPADDR_BAN_LOGIN          = 127,
    /** @brief  该手机不允许登录该帐号  */
    HKS_NPC_D_MPI_MON_ERROR_CLIENTID_NOT_ALLOW_LOGIN  = 128,
    /** @brief  该时间段不允许访问该摄像机  */
    HKS_NPC_D_MPI_MON_ERROR_TIMESECT_NOT_ALLOW_CAMERA = 129,
    /** @brief  文件不存在  */
    HKS_NPC_D_MPI_MON_ERROR_VOD_FILE_NOT_EXIST        = 130,
    /** @brief  拒绝登录  */
    HKS_NPC_D_MPI_MON_ERROR_REJECT_LOGIN              = 131,
    /** @brief  设备组ID不存在  */
    HKS_NPC_D_MPI_MON_ERROR_DEVGROUPID_NOT_EXIST      = 132,
    /** @brief  设备组认证：密码错误  */
    HKS_NPC_D_MPI_MON_ERROR_DEVGROUP_PWD_ERROR        = 133,
    /** @brief  资源已被占用  */
    HKS_NPC_D_MPI_MON_ERROR_RESOURCE_USED             = 134,
    /** @brief  资源已未被打开  */
    HKS_NPC_D_MPI_MON_ERROR_RESOURCE_NOT_OPEN         = 135,
    /** @brief  操作成功，但需要重启设备才生效  */
    HKS_NPC_D_MPI_MON_ERROR_SUCCESS_AND_RESTART       = 136,
    /** @brief  设备组下的结点不能操作  */
    HKS_NPC_D_MPI_MON_ERROR_OPNO_DEVGROUP             = 137,
    /** @brief  无空闲资源可使用  */
    HKS_NPC_D_MPI_MON_ERROR_RESOURCE_NO_IDLE          = 138,
    /** @brief  资源不存在 */
    HKS_NPC_D_MPI_MON_ERROR_RESOURCE_NOT_EXIST        = 139,
    /** @brief  打开资源失败  */
    HKS_NPC_D_MPI_MON_ERROR_RESOURCE_OPEN_FAIL        = 140,
    /** @brief  不支持该操作  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_SUPPORT_OP = 141,
    /** @brief  禁止修改  */
    HKS_NPC_D_MPI_MON_ERROR_BAN_MODIFY = 142,
    /** @brief  打开媒体流失败（打开实时预览失败）  */
    HKS_NPC_D_MPI_MON_ERROR_OPEN_STREAM_FAIL = 143,
    /** @brief  不支持该子码流  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_SUPPORT_SUBSTREAM = 144,
    /** @brief  不支持云台控制  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_SUPPORT_PTZ = 145,
    /** @brief  不支持强制I帧  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_SUPPORT_FORCE_I_FRAME = 146,
    /** @brief  不支持语音对讲  */
    HKS_NPC_D_MPI_MON_ERROR_NOT_SUPPORT_TALK = 147,
    /** @brief  文件操作失败  */
    HKS_NPC_D_MPI_MON_ERROR_FILE_OP_FAIL = 148,
    /** @brief  ID错误  */
    HKS_NPC_D_MPI_MON_ERROR_ID_ERROR = 149,
    /** @brief  通道号错误  */
    HKS_NPC_D_MPI_MON_ERROR_CHANNEL_NO_ERROR = 150,
    /** @brief  子码流号错误  */
    HKS_NPC_D_MPI_MON_ERROR_SUB_STREAM_NO_ERROR = 151,
    /** @brief  启动对讲失败  */
    HKS_NPC_D_MPI_MON_ERROR_START_TALK_FAIL = 152,
    /** @brief  设备端主动关闭连接  */
    HKS_NPC_D_MPI_MON_ERROR_NET_PEER_CLOSE = 153,
};
/** @brief  接口返回错误码定义  */
typedef int HKS_NPC_D_MPI_MON_ERROR;


enum {
    /** @brief  用户名错误  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_USER_ERROR                 = 1,
    /** @brief  密码错误  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_PWD_ERROR                  = 2,
    /** @brief  用户名或密码错误  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_USER_OR_PWD_ERROR          = 3,
    /** @brief  用户帐号未激活  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_ACCOUNT_NO_ACTIVE          = 4,
    /** @brief  用户帐号已过有效期  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_HAVE_EXPIRED               = 5,
    /** @brief  客户端ID不允许登录  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_CLIENTID_NOT_ALLOW_LOGIN   = 6,
    /** @brief  拒绝登录（IP地址不允许登录）  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_REJECT_LOGIN               = 7,
    /** @brief  其它原因  */
    HKS_NPC_D_MPI_MON_RELOGIN_CAUSE_OTHER                      = 99,
};
/** @brief  通知重新登录错误的原因定义  */
typedef int NPC_D_MPI_MON_RELOGIN_CAUSE;

enum {
    /** @brief  初始状态  */
    HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE_INIT             = 0,
    /** @brief  等待重连标识  */
    HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE_WAIT_RECONN_FLAG = 1,
    /** @brief  正在连接状态  */
    HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE_CONNECTING       = 2,
    /** @brief  正在登录状态  */
    HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE_LOGINING         = 3,
    /** @brief  登录成功状态  */
    HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE_LOGIN_OK         = 4,
};
/** @brief  服务器登录状态  */
typedef int HKS_NPC_D_MPI_MON_CLIENT_CHECK_SRV_CONN_STATE;

enum {
    /** @brief  不支持  */
    NPC_D_DPS_JSON_FUNCID_RESULT_STATUS_NOSUPPORT = -1,
    /** @brief  失败  */
    NPC_D_DPS_JSON_FUNCID_RESULT_STATUS_FAIL = 0,
    /** @brief  成功  */
    NPC_D_DPS_JSON_FUNCID_RESULT_STATUS_SUCCESS = 1,
    /** @brief  密码错误  */
    NPC_D_DPS_JSON_FUNCID_RESULT_STATUS_PWD_FAIL = 2,
};
/** @brief  设备配置参数返回状态码  */
typedef int NPC_D_DPS_JSON_FUNCID_RESULT_STATUS;
