/*!
    @class  UMWebDef
    @brief  用户系统类相关宏定义
    @since  v2.4.10.0
 */

#pragma mark - 协议头

#define UMH_API_PATH_WS                 @"umeye_ws_api"
#define UMH_API_PATH_HTTP               @"umeye_api"
#define UM_WEB_API_IMAGE                @"upload_img"
/// 协议头
#define UMH_API_HEAD                    @"h"
/// 版本，必填
#define UM_WEB_API_WS_HEAD_V            @"v"
/// 协议数据内容
#define UM_WEB_API_WS_BODY              @"b"
/// 请求头信息
#define UMH_API_REQ                     @"r"
#define UMH_API_REQ_V                   @"api_ver"

/// 版本号
#define UM_WEB_API_WS_HEAD_V_1          1
#define UM_WEB_API_WS_HEAD_V_2          2
#define UM_WEB_API_WS_HEAD_V_3          3
#define UM_WEB_API_WS_HEAD_V_4          4

/// 消息ID，必填
#define UM_WEB_API_WS_HEAD_I            @"i"

#define UM_WEB_API_WS_HEAD_M            @"m"

/// 会话(session)ID
#define UM_WEB_API_WS_HEAD_S            @"s"
/// 服务端处理消息时出现错误后返回给客户端的错误代码,主要沿用HTTP的状态码定义，可选
#define UM_WEB_API_WS_HEAD_E            @"e"

#define UM_WEB_API_NOT_LOGOUT           @"kUMWEBNotificationLogout"

#define UM_WEB_API_NOT_CLIENT_VERINFO   @"kUMWEBNotificationClientVerInfo"

/// 登录过期通知
#define kUMLoginExpiredNotification     @"kUMLoginExpiredNotification"
/// 登录成功通知
#define kUMLoginSucNotification     @"kUMLoginSucNotification"

#pragma mark - api type
enum{
    /// http
    UM_WEB_API_TYPE_HTTP_P2P = 0,
    UM_WEB_API_TYPE_HTTP_SCS = 1,
    /// Chain store
    UM_WEB_API_TYPE_HTTP_STORE = 2,
    /// Chain store
    UM_WEB_API_TYPE_WS_STORE = 4,
    UM_WEB_API_TYPE_WS = 0,
};
/// type
typedef int UM_WEB_API_TYPE;

#pragma mark - conn type
enum{
    /// local
    UM_WEB_API_CONN_TYPE_LOCAL = 0,
    /// login
    UM_WEB_API_CONN_TYPE_LOGIN = 1,
};
/// conn type
typedef int UM_WEB_API_CONN_TYPE;

#pragma mark - error id
enum{
    /// connection failed
    UM_WEB_API_ERROR_ID_CONN = 0,
    /// 协议头解析错误[protocol head parsing error]
    UM_WEB_API_ERROR_ID_HEAD = 1,
    /// 消息ID解析错误[message ID parsing error]
    UM_WEB_API_ERROR_ID_MSGID = 2,
    /// 协议主体解析错误[protocol bouncer parsing error]
    UM_WEB_API_ERROR_ID_BODY = 3,
    ///  成功[successful]
    UM_WEB_API_ERROR_ID_SUC = 200,
    /// 无效的请求，缺少参数，比如必填参数没有填写数据[invalid request, lacking parameters, such as not filling in requested parameters]
    UM_WEB_API_ERROR_ID_BAD_REQUEST = 400,
    /// 该用户在其他地方登录，当前登录失效
    UM_WEB_API_ERROR_ID_HTTP_UNAUTHORIZED = 401,
    /// 数据非法，请求被拒绝，比如：登录密码恢复出厂设置的时候，请求的用户没有在该手机登录过，就会提示该错误码[request rejected, for example, after the password is reset to factory setting, if the user did not sign in on the phone before, the error code pops out]
    UM_WEB_API_ERROR_ID_FORBIDDEN = 403,
    /// 请求没找到。不支持该功能的请求[request not found. the request for this function unsupported]
    UM_WEB_API_ERROR_ID_NOT_FOUND = 404,
    /// 非法请求。未登录，请登录[illegal request. unlogged in, pls login]
    UM_WEB_API_ERROR_ID_NOT_ALLOWED = 405,
    /// 请求不被接受。参数错误，比如：用户名或密码不正确[request unaccepted. parameter error, such as wrong user name or password]
    UM_WEB_API_ERROR_ID_NOT_ACCEPTABLE = 406,
    /// 请求发送冲突，数据中数据库已经存在，比如用户已注册，设备id已添加[request conflict, for example, the registered user name already exists]
    UM_WEB_API_ERROR_ID_CONFLICT = 409,
    /// 请求用户太多[too many requesting users]
    UM_WEB_API_ERROR_ID_TOO_MANY_REQUESTS = 429,
    /// 请求被拒绝。登录失效，请重新登录[request rejected. Login failed. Pls login again.]
    UM_WEB_API_ERROR_ID_ILLEGAL = 451,
    /// 服务器错误，常见错误：1、数据库操作错误，查询不到符合条件的数据，2、请求外部资源失败
    UM_WEB_API_ERROR_ID_DB = 500,
    /// 账号未激活
    UM_WEB_API_ERROR_ID_USER_NOT_ACTIVE = 508,
    /// 账号停用
    UM_WEB_API_ERROR_ID_USER_NOT_ENABLE = 509,
    /// 超过最大限制
    UM_WEB_API_ERROR_ID_MAX_LIMIT = 510,
    /// 邮箱地址错误
    UM_WEB_API_ERROR_EMALL = 511,
    /// 密码错误
    UM_WEB_API_ERROR_PASSWORD = 512,
    /// 无权限
    UM_WEB_API_ERROR_NO_PERMISSION = 513,
    /// 验证码错误
    UM_WEB_API_ERROR_CODE = 514,
    /// 加密错误
    UM_WEB_API_ERROR_ENCRYPT = 522,
    /// 解密错误
    UM_WEB_API_ERROR_DECRYPT = 523,
    /// 非法操作
    UM_WEB_API_ERROR_ILLEGAL_OP = 528,
    /// 请求超出有效时间失效
    UM_WEB_API_ERROR_OVERDUE_OP = 529,
    /// 用户名不存在
    UM_WEB_API_ERROR_ID_USER = 899999,
    /// 获取认证服务器错误，比如：用户名不存在，网络不好
    UM_WEB_API_ERROR_ID_GETQUTH = 899998,
    /// 分享设备失败，不能分享给自己
    UM_WEB_API_ERROR_ID_SHARK_USER = 899997,
    
};
/// 错误ID[wrong ID]
typedef int UM_WEB_API_ERROR_ID;

#pragma mark - msg id
enum{
    /** @brief  unknown  */
    UM_WEB_API_WS_HEAD_I_NONE = 999999,
#pragma mark p2p msg id
    /** @brief  获取最优的认证、ust服务器地址(Get the best authorization、ust server address)  */
    UM_WEB_API_WS_HEAD_I_AUTHUST = 100,
    /** @brief  获取认证、ust服务器地址列表(Get authorization、ust server address list)  */
    UM_WEB_API_WS_HEAD_I_AUTHUSTLIST = 101,
    /// 根据参数查找数据所在地址
    UM_WEB_API_WS_HEAD_I_PARAM_IP = 103,
    /// 清除某设备ID的所有用户绑定信息
    UM_WEB_API_WS_HEAD_I_UMID_LINKUSER = 164,
    /** @brief  user registration  */
    UM_WEB_API_WS_HEAD_I_USER_REGISTER = 201,
    /** @brief  user login  */
    UM_WEB_API_WS_HEAD_I_USER_LOGIN = 202,
    /** @brief  user logout  */
    UM_WEB_API_WS_HEAD_I_USER_LOGOUT = 203,
    /** @brief  third-party login  */
    UM_WEB_API_WS_HEAD_I_USER_LOGIN_OTHER = 204,
    /** @brief  user permission  */
    UM_WEB_API_WS_HEAD_I_USER_RIGHTS = 206,
    /** @brief  user info:email\name\phone  */
    UM_WEB_API_WS_HEAD_I_USER_INFO_QUERY = 208,
    /** @brief  modify user info:email\name\phone  */
    UM_WEB_API_WS_HEAD_I_USER_INFO_MODIFY = 209,
    /** @brief  change password  */
    UM_WEB_API_WS_HEAD_I_USER_MODIFYPWD = 210,
    /** @brief  reset password to the email  */
    UM_WEB_API_WS_HEAD_I_USER_RESETPWD = 211,
    /** @brief  重置密码为123456(reset password to be 123456)  */
    UM_WEB_API_WS_HEAD_I_USER_RESTOREFACTORYPWD = 212,
    /// 请求短信
    UM_WEB_API_WS_HEAD_I_PUSH_SMS = 213,
    /// 验证短信
    UM_WEB_API_WS_HEAD_I_CHECK_SMS = 214,
    /// 刷新Session
    UM_WEB_API_WS_HEAD_I_LOGIN_SESSION = 215,
    /// 删除账号
    UM_WEB_API_WS_HEAD_I_USER_DEL = 216,
    /// 推送邮件
    UM_WEB_API_WS_HEAD_I_PUSH_EMAIL = 217,
    /// 查询目录/设备/摄像机节点,回调参数:NSMutableArray<TreeListItem *>
    UM_WEB_API_WS_HEAD_I_DEVICE_QUERY = 231,
    /** @brief  add node  */
    UM_WEB_API_WS_HEAD_I_DEVICE_ADD = 232,
    /** @brief  delete node  */
    UM_WEB_API_WS_HEAD_I_DEVICE_DEL = 233,
    /** @brief  modify node  */
    UM_WEB_API_WS_HEAD_I_DEVICE_MODIFY = 234,
    /// 通过序列号查询设备状态(query device status via serial number)
    UM_WEB_API_WS_HEAD_I_DEVICE_STATUS = 235,
    /// 通过sDevId查询设备状态(query device status via sDevId)
    UM_WEB_API_WS_HEAD_I_DEVICE_STATUS_DEVID = 237,
    /** @brief  设备通道数修改(modify dvr channels)  */
    UM_WEB_API_WS_HEAD_I_DEVICE_CH_MODIFY = 238,
    /** @brief  查询设备节点分享  */
    UM_WEB_API_WS_HEAD_I_DEVICE_SHARE_QUERY = 239,
    /** @brief  添加、删除分享设备节点  */
    UM_WEB_API_WS_HEAD_I_DEVICE_SHARE_MODIFY = 240,
    /// 查询设备的分享用户列表
    UM_WEB_API_WS_HEAD_I_DEVICE_SHARE_USERS = 230,
    /** @brief  查询情景  */
    UM_WEB_API_WS_HEAD_I_SCENARIO_QUERY = 241,
    /** @brief  添加情景  */
    UM_WEB_API_WS_HEAD_I_SCENARIO_ADD = 242,
    /** @brief  删除情景  */
    UM_WEB_API_WS_HEAD_I_SCENARIO_DEL = 243,
    /** @brief  修改情景  */
    UM_WEB_API_WS_HEAD_I_SCENARIO_MODIFY = 244,
    /** @brief  查询场景  */
    UM_WEB_API_WS_HEAD_I_SCENE_QUERY = 245,
    /** @brief  添加场景  */
    UM_WEB_API_WS_HEAD_I_SCENE_ADD = 246,
    /** @brief  删除场景  */
    UM_WEB_API_WS_HEAD_I_SCENE_DEL = 247,
    /** @brief  修改场景  */
    UM_WEB_API_WS_HEAD_I_SCENE_MODIFY = 248,
    /** @brief  意见反馈  */
    UM_WEB_API_WS_HEAD_I_FEEDBACK = 302,
    /** @brief  query alarm logs  */
    UM_WEB_API_WS_HEAD_I_ALARM_LOG_QUERY = 261,
    /** @brief  delete alarm log  */
    UM_WEB_API_WS_HEAD_I_ALARM_DEL = 262,
    /** @brief  query alarm information  */
    UM_WEB_API_WS_HEAD_I_ALARM_INFO_QUERY = 271,
    /// @brief  修改设备布防/撤防/取消通知(modify device protealarmction/ removal/ notice cancellation)
    UM_WEB_API_WS_HEAD_I_ALARM_SET = 272,
    /** @brief  query user push information  */
    UM_WEB_API_WS_HEAD_I_USER_PUSH_QUERY = 278,
    /** @brief  set up user push information  */
    UM_WEB_API_WS_HEAD_I_USER_PUSH_SET = 279,
    /** @brief  云存储文件查询  */
    UM_WEB_API_WS_HEAD_I_CLOUD_QUERY = 280,
    /// 删除云存储信息
    UM_WEB_API_WS_HEAD_I_CLOUD_DEL = 281,
    /// @brief  查询客户端最新版本信息(query the latest version of app)
    UM_WEB_API_WS_HEAD_I_CLIENT_NEWVERSION = 301,
    /// 广告栏列表
    UM_WEB_API_WS_HEAD_I_BANNERS = 312,
    /// 请求设备超级密码
    UM_WEB_API_WS_HEAD_I_PWD_SUPER = 2302,
#pragma mark kindergarten msg id
    /** @brief  幼儿园公告   */
    UM_WEB_API_WS_HEAD_I_KINDERGARTEN_BULLETIN = 401,
    /** @brief  幼儿园学生信息   */
    UM_WEB_API_WS_HEAD_I_KINDERGARTEN_PUPILINFO = 402,
    /** @brief  幼儿园食谱   */
    UM_WEB_API_WS_HEAD_I_KINDERGARTEN_RECIPES = 403,
    /** @brief  幼儿园课程表   */
    UM_WEB_API_WS_HEAD_I_KINDERGARTEN_TIMETABLES = 404,
    
#pragma mark store msg id
    /** @brief  获取最优的认证、ust服务器地址  */
    /** @brief  Get the best authorization、ust server address  */
    UM_WEB_API_WS_STORE_HEAD_I_AUTHUST = 41001,
    /** @brief  广告栏列表  */
    /** @brief  banner list  */
    UM_WEB_API_WS_STORE_HEAD_I_BANNERS = 41002,
    /** @brief  user login  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_LOGIN = 41003,
    /** @brief  user logout  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_LOGOUT = 41039,
    /** @brief  reset password to the email  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_RESETPWD = 41004,
    /** @brief  change password  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_MODIFYPWD = 41040,
    /** @brief  重置密码为123456  */
    /** @brief  reset password to be 123456  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_RESTOREFACTORYPWD = 999999997,
    /** @brief  查询全部目录/设备/摄像机节点  */
    /** @brief  query node list  */
    UM_WEB_API_WS_STORE_HEAD_I_DEVICE_QUERY = 41034,
    /** @brief  获取用户下所有门店所在的区域集合  */
    UM_WEB_API_WS_STORE_HEAD_I_CITIES_QUERY = 41046,
    /** @brief  通过序列号查询设备状态  */
    /** @brief  query device status via serial number  */
    UM_WEB_API_WS_STORE_HEAD_I_DEVICE_STATUS = 999999996,
    /** @brief  user registration  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_REGISTER = 999999995,
    /** @brief  user dynamics  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_DYNAMICS_QUERY = 41005,
    /** @brief  查询节点门店，已过时  */
    UM_WEB_API_WS_STORE_HEAD_I_STORE_QUERY = 41007,
    /** @brief  查询事件类型  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_TYPE_QUERY = 41009,
    /** @brief  添加事件  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_ADD = 41010,
    /** @brief  根据id查询事件  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_ID_QUERY = 41011,
    /** @brief  查询事件列表  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_QUERY = 41014,
    /** @brief  修改事件  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_MODIFY = 41012,
    /** @brief  删除事件  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_DEL = 41013,
    /** @brief  事件的处理流程  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_PROCESSING_FLOW = 41037,
    /** @brief  提交事件的处理结果  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_SUBMIT = 41038,
    /** @brief  查询要指派或抄送的人员  */
    UM_WEB_API_WS_STORE_HEAD_I_EVENT_USER = 41035,
    /** @brief  添加巡店计划  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_ADD = 41015,
    /** @brief  查询巡店计划  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_QUERY = 41016,
    /** @brief  查询巡店计划图片  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_IMAGE_QUERY = 41017,
    /** @brief  修改巡店计划  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_MODIFY = 41018,
    /** @brief  删除巡店计划  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_DEL = 41019,
    /** @brief  删除巡店计划抓拍图片  */
    UM_WEB_API_WS_STORE_HEAD_I_STOREPLAN_IMAGE_DEL = 41020,
    /** @brief  添加防盗计划  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_ADD = 41021,
    /** @brief  查询防盗计划  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_QUERY = 41022,
    /** @brief  查询防盗计划的镜头报警图片列表  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_IMAGE_QUERY = 41023,
    /** @brief  修改防盗计划  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_MODIFY = 41024,
    /** @brief  删除防盗计划  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_DEL = 41025,
    /** @brief  删除防盗计划图片  */
    UM_WEB_API_WS_STORE_HEAD_I_PICKPROOFPLAN_IMAGE_DEL = 41026,
    /** @brief  添加门店收藏  */
    UM_WEB_API_WS_STORE_HEAD_FAV_ADD = 41027,
    /** @brief  查询门店收藏  */
    UM_WEB_API_WS_STORE_HEAD_FAV_QUERY = 41028,
    /** @brief  取消门店收藏  */
    UM_WEB_API_WS_STORE_HEAD_FAV_DEL = 41032,
    /** @brief  查询消息记录  */
    UM_WEB_API_WS_STORE_HEAD_I_LOG = 41030,
    /** @brief  删除消息记录  */
    UM_WEB_API_WS_STORE_HEAD_I_LOG_DEL = 41031,
    /** @brief  阅读消息记录  */
    UM_WEB_API_WS_STORE_HEAD_I_LOG_READ = 41033,
    /** @brief  设置用户推送  */
    UM_WEB_API_WS_STORE_HEAD_I_USER_SET_PUSH = 41036,
    /** @brief  用户自定义头像  */
    UM_WEB_API_WS_STORE_HEAD_I_USERINFO_MODIFY = 41041,
    /** @brief  客户端版本信息  */
    UM_WEB_API_WS_STORE_HEAD_I_VER_INFO = 41042,
    /** @brief  上传客户端预览抓拍图片  */
    UM_WEB_API_WS_STORE_HEAD_I_IMAGE_ADD = 41043,
    /** @brief  查询客户端预览抓拍图片  */
    UM_WEB_API_WS_STORE_HEAD_I_IMAGE_QUERY = 41044,
    /** @brief  删除客户端预览抓拍图片  */
    UM_WEB_API_WS_STORE_HEAD_I_IMAGE_DEL = 41045,
    /** @brief  查询巡检项  */
    UM_WEB_API_WS_STORE_HEAD_I_INSPECT_QUERY = 41048,
    /** @brief  提交巡检评分  */
    UM_WEB_API_WS_STORE_HEAD_I_INSPECT_SCORE_SUBMIT = 41049,
};
/** @brief 协议头-消息ID(protocol head - message ID)  */
typedef int UM_WEB_API_WS_HEAD_I_ID;


#pragma mark -
enum{
    /** @brief  所有厂家  */
    UM_WEB_API_WS_VENDOR_ID_ALL = 0,
    /** @brief  UMSP  */
    UM_WEB_API_WS_VENDOR_ID_UMSP = 1009,
    /** @brief  杭州大华（通用参数解析）  */
    UM_WEB_API_WS_VENDOR_ID_HZDH = 2020,
    /** @brief  深圳汉邦（通用参数解析）  */
    UM_WEB_API_WS_VENDOR_ID_SZHB = 2050,
    /** @brief  杭州雄迈（通用参数解析）  */
    UM_WEB_API_WS_VENDOR_ID_HZXM = 2060,
};
/** @brief  设备协议ID  */
typedef int UM_WEB_API_WS_VENDOR_ID;

#pragma mark -
enum{
    /** @brief  sdk未初始化  */
    UM_WEB_API_STATE_ID_INIT = 0,
    /** @brief  sdk初始化中  */
    UM_WEB_API_STATE_ID_CONNING = 1,
    /** @brief  sdk ust 模块启动中  */
    UM_WEB_API_STATE_ID_UST_CONNING = 2,
    /** @brief  sdk启动完成  */
    UM_WEB_API_STATE_ID_CONN_OK = 3,
    /** @brief  sdk连接失败  */
    UM_WEB_API_STATE_ID_CONN_FAL = 4,
    UM_WEB_API_STATE_ID_STOP = 5,
};
/** @brief  sdk运行状态id  */
typedef int UM_WEB_API_STATE_ID;

/*! @brief  type  */
enum{
    UM_WEB_API_ENCRYPT_MODE_N = 1,
    UM_WEB_API_ENCRYPT_MODE_R = 2,
};
typedef int UM_WEB_API_ENCRYPT_MODE;

#define UMAccountDeprecated(_info) __attribute__((deprecated(_info)))
