///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end

enum {
    /** @brief  准备播放  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_READY = 0,
    /** @brief  正在播放  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_PLAYING = 1,
    /** @brief  已停止  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_STOP = 2,
    /** @brief  连接失败  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_FAIL = 3,
    /** @brief  正在连接  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SERVER = 4,
    /** @brief  连接成功  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_CONNECT_SUCESS = 5,
    /** @brief  暂停  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_PAUSE = 6,
    /** @brief  正在停止中  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_STOPING = 7,
    /** @brief  登录失败,无权限  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_PERMISSION = 8,
    /** @brief  登录失败,离线  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_OFFLINE = 9,
    /** @brief  登录失败,超过最大连接数  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_MAXCONN = 10,
    /** @brief  资源不存在  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_RESOURCE_NOT_EXIST = 11,
    /** @brief  码流错误，当前请求的码流设备不支持  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_STEAM_NOT_EXIST = 12,
    /** @brief  向服务器请求建立连接超时  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_SERVER_CONNECT_FAIL = 13,
    /** @brief  登录失败,密码错误  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_PASSWORD = -1,
    /** @brief  登录失败,用户名错误  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_USER = -2,
    /** @brief  登录失败,用户名或密码错误  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_USER_PWD = -19,
    /** @brief  登录失败,超时  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_TIMEOUT = -3,
    /** @brief  登录失败  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_RELOGGIN = -4,
    /** @brief  登录失败  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_LOCKED = -5,
    /** @brief  登录失败，连接被设备端主动断开  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_BUSY = -6,
    /** @brief  登录失败  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_LOGIN_ERROR_UNKNOW = -7,
    /** @brief  播放失败或中断,网络错误  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_NETWORK = -9,
    /** @brief  播放失败或中断,无数据返回  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_NODATA = -10,
    /** @brief  播放失败或中断,异常情况  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_EXCEPTION = -11,
    /** @brief  文件播放结束  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_FILE_END = -15,
    /** @brief  下载中断  */
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_DEWNLOAD_BLOCKED = -18,
    /// 无视频
    HKS_NPC_D_MON_DEV_PLAY_STATUS_ERROR_NOVIDEO = -20,
};
/** @brief  客户端连接模式,自定义错误码6150-6179,对应的设备自定义错误码150-179 */
typedef int HKSDevicePlayStatus;


//状态码,已过时
#define Statue_Ready					0                       //Player Ready
#define Statue_PLAYING					1                       //Playing
#define Statue_STOP						2                       //Stopped
#define Statue_ConnectFail				3                       //Connect to server fail
#define Statue_ConnectingServer			4                       //Connect to server...
#define Statue_ConnectingSucess			5                       //Connect to server successfully
#define Statue_PAUSE					6                       //Paused
#define Statue_STOPING					7                       //stoping
#define Statue_LOGIN_ERROR_PASSWORD		-1                      //Invalid password
#define Statue_LOGIN_ERROR_USER			-2                      //Invalid user
#define Statue_LOGIN_ERROR_TIMEOUT		-3                      //Login fail
#define Statue_LOGIN_ERROR_RELOGGIN		-4                      //Login fail
#define Statue_LOGIN_ERROR_LOCKED		-5                      //Login fail
#define Statue_LOGIN_ERROR_BUSY			-6                      //Login fail
#define Statue_Unknow_ERROR				-7                      //Login fail
#define Statue_PROTOCAL_ERROR			-8                      //Login fail
#define Statue_NET_ERROR				-9                      //Network error!
#define Statue_NODATA_ERROR				-10                     //No response!
#define Statue_Exception_ERROR			-11						//异常情况                //不提示重连即可
#define Statue_NosupportDevice_ERROR	-12						//不支持的厂家             //Invalid device,please contact with developer!
#define Statue_Beyondmaxchannels_ERROR	-13						//超过最大通道数           //Beyond the max channel!
#define Statue_MAXUSER_ERROR			-14						//超过最大用户数           //Max User error!
#define Statue_RecordFileOver			-15						//录像结束
#define Statue_HavenoRight_ERROR		-16						//权限不够                //The user is limited of authority!
#define Statue_DeviceIsNotOnLine		-17						//采集点离线                //The user is limited of authority!
#define Statue_DownloadBlocked          -18 //下载中断
//PPT对讲状态码
#define Statue_Ready_PPT					0                       //Player Ready
#define Statue_PLAYING_PPT					1                       //Playing
#define Statue_STOP_PPT						2                       //Stopped
#define Statue_ConnectFail_PPT					3                       //Connect to server fail
#define Statue_ConnectingServer_PPT				4                       //Connect to server...
#define Statue_ConnectingSucess_PPT				5                       //Connect to server successfully
#define Statue_ERROR_BUSY_PPT					-1                       //主机忙一般表示对讲已经被占用

