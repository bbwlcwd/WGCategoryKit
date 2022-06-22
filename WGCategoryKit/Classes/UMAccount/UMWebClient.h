/*!
 @class  UMWebDef
 @brief  用户系统类
 @since  v2.4.10.0
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UMWebDef.h"
@class TreeListItem;
@class UMWebProtocol;

/**
    @brief  The UMWebClient protocol
 */
@protocol UMWebClientDelegate<NSObject>

/**
    @brief  UMWebClient Callback
    
    @param  tager       UMWebClient
    @param  aStatus     状态码(Wrong ID)
    @param  aMsgId      功能ID(Protocol head - message ID)
    @param  aParam      返回数据(Returned data)
 */
- (void)umWebClient:(id)tager status:(UM_WEB_API_ERROR_ID)aStatus msgId:(UM_WEB_API_WS_HEAD_I_ID)aMsgId param:(id)aParam;
@end

/**
 @brief  UMWebClient Task
 
 @param  iMsgId      功能ID(Protocol head - message ID)
 @param  iError      状态码(Wrong ID)
 @param  aParam      返回数据(Returned data)
 */
typedef void (^UMWebClientDataTask)(int iMsgId, int iError, id aParam);

/**
 @brief  用户系统类（User System Class）
 
 @since  v2.4.10.1
 */
@interface UMWebClient : NSObject{
    
    UM_WEB_API_WS_HEAD_I_ID     _iMsgId;
    
    NSString                    *_sSession;
    
    
    UMWebProtocol               *_protocol;
    
    BOOL                        _npcStatusEnable;
    
    int                         _encryptMode;
    
    BOOL                        _delegateEnable;
}

/** @brief  服务器地址(server address)   */
@property(nonatomic, copy) NSString     *sHost;

/** @brief  服务器端口(server port)   */
@property(nonatomic, assign) int        iPort;

@property(nonatomic, copy) NSString     *sLoginHost;

/** @brief  备用服务器IP，解析域名失败的时候使用(server address)   */
@property(nonatomic, copy) NSString     *sBackupIp;

@property(nonatomic, copy) NSString     *sClientId;
/** @brief  connecting type, 1: login type, 0: no local account type, default: 1    */
@property(nonatomic, assign) UM_WEB_API_CONN_TYPE   iConnType;

/** @brief  user id   */
@property(nonatomic, copy) NSString     *sUserId;

/** @brief  user password   */
@property(nonatomic, copy) NSString     *sUserPwd;

/** @brief  app version   */
@property(nonatomic, copy) NSString     *sClientVer;

/** @brief  推送id，用于消息推送，请在调用设置用户推送和设备布放之前设置(app push token)   */
@property(nonatomic, copy) NSString     *sClientToken;

/** @brief  是否开启免登录推送(nologin push),NO   */
@property(nonatomic, assign) BOOL       noLoginPushEnable;

/** @brief  DEBUG log   */
@property(nonatomic, assign) BOOL       logEnable;

@property(nonatomic, strong) NSMutableArray             *tDevices;
@property(nonatomic, copy) NSString                     *sIp;
/** @brief  ssl,NO    */
@property(nonatomic, assign) BOOL                       sslEnable;

@property(nonatomic, assign) BOOL                       checkServerStatusEnable;
/// 后台超时时长，默认：30
@property(nonatomic, assign) int                        checkServerTimeout;

/** @brief  是否要指定连接服务器,默认:NO    */
@property(nonatomic, assign) BOOL                       bIfSpecifyConnSrv;

@property(nonatomic, assign) BOOL                       apiBlockEnEnable;

/** @brief  sdk初始化状态    */
@property(nonatomic, assign) UM_WEB_API_STATE_ID        sdkState;

/**
 *  @brief      响应数据回调方式设置，两选一。dataTask优先（callback delegate）
 *  @dataTask   通过UMWebClientDataTask返回[主线程]
 *  @delegate   通过UMWebClientDelegate返回[子线程]
 */
@property(nonatomic, copy)   UMWebClientDataTask        dataTask;
@property(nonatomic, weak) id                         delegate;

@property(nonatomic, assign) BOOL   isLogin;

/// 自动更新设备通道状态，缺省:YES
@property(nonatomic, assign) BOOL   autoUpdateDevChannelStateEnable;

#pragma mark - 已过时
@property(nonatomic, copy) NSString     *sUstHost UMAccountDeprecated("已过时");
@property(nonatomic, assign) int        iUstPort UMAccountDeprecated("已过时");
@property(nonatomic, copy) NSString     *sAuthHost UMAccountDeprecated("已过时,请使用sLoginHost");
@property(nonatomic, assign) int        iAuthPort UMAccountDeprecated("已过时");
/** @brief  conn server,YES    */
@property(nonatomic, assign) BOOL                       connSvrEnable UMAccountDeprecated("已过时");

#pragma mark -

/// 启动SDK,基础模块自动调用
+ (void)startSDK:(NSString *)host port:(int)port;

/// 获取登录session
- (NSString *)sSession;

/**
 *  @brief  获取当前协议类型的句柄（Get handle of current protocol type），已过期，请使用setup进行初始化，再使用shareClient进行获取
 *  @param  aWebAPIType    协议类型（protocol type）
 *  @return [UMWebClient]                   协议句柄（protocol handle）
 *
 *  @since  v2.4.10.0
 */
+ (UMWebClient *)shareClient:(UM_WEB_API_TYPE)aWebAPIType UMAccountDeprecated("该接口已过时");

/**
 @brief  获取当前协议类型的句柄（Get handle of current protocol type）返回上次类型句柄
 
 @return [UMWebClient]                   协议句柄（protocol handle）
 
 @since  v2.4.10.0
 */
+ (UMWebClient *)shareClient;

/**
 *  @brief  清除APP临时文件
 *
 *  @since  v2.4.11.15
 */
+ (void)cleanTempPathFile;

/**
 *  @brief  SDK版本号
 *
 *  @since  v2.4.11.15
 */
+ (NSString *)version;

/// 开启日志
/// @param log 是否启动
+ (void)setLog:(BOOL)log;
#pragma mark - start stop sdk
/**
 @brief  启动SDK（start sdk）
 
 @param  aHost          server ip,v0.api.umeye.com
 @param  aPort          server port,8888
 @param  aCustomFlag    app custom flag
 
 @since  v2.4.11.15
 */
- (void)startSDK:(NSString *)aHost
            port:(int)aPort
      customFlag:(NSString *)aCustomFlag UMAccountDeprecated("该接口已过时,请使用[UMConfig startSDK]");

- (void)startSDK:(NSString *)aHost
            port:(int)aPort
      customFlag:(NSString *)aCustomFlag
           token:(NSString *)aToken UMAccountDeprecated("该接口已过时");

/**
 @brief  停止SDK（stop sdk）
 
 @since  v2.4.12.1
 */
- (void)stopSDK;

#pragma mark -

/**
 *  @brief  清除本地保存的配置文件数据，下次连接的时候将会重新获取(remove local configuration files which will be re-acquired in the next connection)
 *
 *  @since  v2.4.10.0
 */
- (void)cleanLocalCofigInfo;

/**
 *  @brief  获取服务器列表(get server list)
 *
 *  @since  v2.4.10.0
 */
- (void)authUstServerList;

#pragma mark - user
/// 登录
/// @param aUserId 账号
/// @param aPassword 密码
/// @param areaCode 区号（手机号码登录的时候才需要填写，否则填0）
- (void)login:(NSString *)aUserId
     password:(NSString *)aPassword
     areaCode:(int)areaCode;

/// 登录
/// @param aUserId      账号
/// @param aPassword    密码
/// @param areaCode     区号（手机号码登录的时候才需要填写，否则填0）
/// @param apiVer       API版本号
- (void)login:(NSString *)aUserId
     password:(NSString *)aPassword
     areaCode:(int)areaCode
       apiVer:(NSString *)apiVer;


/// 登录
/// @param aUserId      账号
/// @param aPassword    密码
/// @param areaCode     区号（手机号码登录的时候才需要填写，否则填0）
/// @param verType     3：短信验证码，4：邮箱验证码（验证码登录的时候才需要填写，否则填0）
/// @param verCode  动态验证码 （验证码登录的时候才需要填写，否则填@""）
/// @param apiVer       API版本号
- (void)login:(NSString *)aUserId
     password:(NSString *)aPassword
     areaCode:(int)areaCode
      verType:(int)verType
      verCode:(NSString *)verCode
       apiVer:(NSString *)apiVer;

/// 第三方登录
/// @param userId 用户ID
/// @param openId 第三方平台APP ID
/// @param openUser 第三方平台用户唯一码
/// @param openName 第三方平台用户昵称
/// @param openType 第三方平台类型,1:微信
/// @param completionHandler 回调
- (void)login:(NSString *)userId
       openId:(NSString *)openId
     openUser:(NSString *)openUser
     openName:(NSString *)openName
     openType:(int)openType
      handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

/**
 *  @brief  登录认证服务器(sign in the authentication server)
 *
 *  @param  aUserId     用户ID，必填(user ID，required)
 *  @param  aPassword   用户密码，必填(user password, required)
 *  @since  v2.4.10.0
 */
- (void)loginServerAtUserId:(NSString *)aUserId
                   password:(NSString *)aPassword;

/**
 *  @brief  注销服务器(logout the server)
 *  @param  bIfDisablePush  是否关闭推送(to close the push or not)
 *
 *  @since  v2.4.10.0
 */
- (void)logoutServer:(BOOL)bIfDisablePush;

/**
 *  @brief  user info,email\name\phone\img
 *  @param  aUserId userId
 *  @since  v2.4.12.1
 */
- (void)userInfo:(NSString *)aUserId;

/// 刷新session
- (void)refreshSessionID;

/// 删除账号
- (void)deleteUser;
/**
 *  @brief  修改用户信息
 *  @param  aEmail      邮箱
 *  @param  aName       用户昵称
 *  @param  aPhone      手机号码
 *  @param  aImg        头像url
 *  @param  aTelephone  联系电话
 *  @param  aAddress    地址
 *  @param  aSex        性别，0：未知，1：男，2：女
 *  @param  aOnlineDuration 在线时长，分钟
 *
 *  @since  v2.4.12.1
 */
- (void)modifyUserInfo:(NSString *)aEmail
                  name:(NSString *)aName
                 phone:(NSString *)aPhone
                   img:(NSString *)aImg
             telephone:(NSString *)aTelephone
               address:(NSString *)aAddress
                   sex:(int)aSex
        onlineDuration:(int)aOnlineDuration;

- (void)modifyUserInfo:(NSString *)aEmail
                  name:(NSString *)aName
                 phone:(NSString *)aPhone
                   img:(NSString *)aImg UMAccountDeprecated("该接口已过时");


- (void)modifyUserInfo:(id)aParam;


/// 注册账号
/// @param aUserId 用户名（邮箱or手机or账号）
/// @param aPassword 密码
/// @param aUserName 昵称
/// @param verType 验证码类型，0：无校验，1：发送激活邮箱，2：发送注册成功邮件，3:需要手机验证码验证; 4:需要邮箱验证码验证
/// @param verCode 验证码，验证类型为3、4的时候才需要填写
/// @param areaCode 手机区号（userId为手机号码的时候才需要填写，否则为0）
- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
              userName:(NSString *)aUserName
               verType:(int)verType
               verCode:(NSString *)verCode
              areaCode:(int)areaCode;
/**
 *  @brief  注册账号(register an account)
 *  @param  aUserId     用户ID[24]，必填(user ID [24]，required)
 *  @param  aPassword   用户密码[20]，必填(user password[20]，required)
 *  @param  aEMail      邮箱[32]，必填email[32]，required
 *  @param  aUserName   姓名[32]，必填(name[32]，required)
 *  @param  aPhone      手机号码[32]，必填(phone[32]，required)
 *  @param  aCardId     身份证[24]，必填(card ID[24]，required)
 *  @param  aMailType    邮件类型，0：注册成功不需要发邮件通知，1：发送激活邮箱，2：发送注册成功邮件，3:需要手机验证码验证; 4:需要邮箱验证码验证
*  @param  aCode        验证码
 *
 *  @since  v2.4.10.0
 */
- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
                 email:(NSString *)aEMail
              userName:(NSString *)aUserName
                 phone:(NSString *)aPhone
                cardId:(NSString *)aCardId
                   sex:(int)aSex
             telephone:(NSString *)aTelephone
               address:(NSString *)aAddress
                 birth:(NSString *)aBirthTime
              mailType:(int)aMailType
                  code:(NSString *)aCode;

- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
                 email:(NSString *)aEMail
              userName:(NSString *)aUserName
                 phone:(NSString *)aPhone
                cardId:(NSString *)aCardId;

- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
                 email:(NSString *)aEMail
              userName:(NSString *)aUserName
                 phone:(NSString *)aPhone
                cardId:(NSString *)aCardId
                  mailType:(int)aMailType;

- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
                 email:(NSString *)aEMail
              userName:(NSString *)aUserName
                 phone:(NSString *)aPhone
                cardId:(NSString *)aCardId
                   sex:(int)aSex
             telephone:(NSString *)aTelephone
               address:(NSString *)aAddress
                 birth:(NSString *)aBirthTime
              mailType:(int)aMailType;

- (void)registeredUser:(NSString *)aUserId
              password:(NSString *)aPassword
                 email:(NSString *)aEMail
              userName:(NSString *)aUserName
                 phone:(NSString *)aPhone
                cardId:(NSString *)aCardId
                   sex:(int)aSex
             telephone:(NSString *)aTelephone
               address:(NSString *)aAddress
                 birth:(NSString *)aBirthTime
              mailType:(int)aMailType
                  code:(NSString *)aCode
              areaCode:(int)areaCode;

/// 修改用户密码(modify user password)
/// @param aUserId 用户ID，可选，非登录状态必填
/// @param aOldPassword 旧密码，可选，跟验证码二选一
/// @param aNewPassword 新密码
/// @param aVerCode 验证码
/// @param verType 验证类型，0：原密码校验，1：短信验证码校验，2：邮箱验证码校验
/// @param areaCode 手机区号（userId为手机号码的时候才需要填写，否则为0）
- (void)modifyUserPassword:(NSString *)aUserId
               oldPassword:(NSString *)aOldPassword
               newPassword:(NSString *)aNewPassword
                   verCode:(NSString *)aVerCode
                   verType:(int)verType
                  areaCode:(int)areaCode;

- (void)modifyUserPassword:(NSString *)aUserId
               oldPassword:(NSString *)aOldPassword
               newPassword:(NSString *)aNewPassword
                   verCode:(NSString *)aVerCode
                   verType:(int)verType;

- (void)modifyUserPassword:(NSString *)aUserId
               oldPassword:(NSString *)aOldPassword
               newPassword:(NSString *)aNewPassword;

/**
 *  @brief  找回密码，发送修改密码邮件到用户的注册邮箱(reset user password)
 *
 *  @param  aUserId     user ID
 *
 *  @since  v2.4.10.0
 */
- (void)resetUserPassword:(NSString *)aUserId;


/**
 *  @brief  重置密码，直接把密码恢复成123456,调用该接口的手机必须使用该用户成功登录过。
 *
 *  @param  aUserId     用户名
 *
 *  @since  v2.4.11.12
 */
- (void)restoreFactoryUserPassword:(NSString *)aUserId;

#pragma mark - node
/// 获取节点列表，包含设备状态
- (void)nodeList;

- (UM_WEB_API_ERROR_ID)nodeList:(NSMutableArray *)aDevices UMAccountDeprecated("已过时");
- (UM_WEB_API_ERROR_ID)nodeList:(NSMutableArray *)aDevices cache:(BOOL)bCache UMAccountDeprecated("已过时");

/**
 *  @brief  添加节点(add node)
 *
 *  @param  aNode       节点信息(node information)
 *  @param  aSubNames   下级通道节点名称，可选，nil
 *  @param  aOnlyUMID   UMID是否唯一，表示一个UMID只允许一个用户添加
 *
 *  @since  v2.4.10.0
 */
- (void)addNodeInfo:(TreeListItem *)aNode
           subNames:(NSMutableArray *)aSubNames
           onlyUMID:(int)aOnlyUMID;
- (void)addNodeInfo:(TreeListItem *)aNode
           subNames:(NSMutableArray *)aSubNames
           onlyUMID:(int)aOnlyUMID
         limitAPPId:(int)aLimitAPPId;
- (void)addNodeInfo:(TreeListItem *)aNode;


/**
 *  @brief  修改节点(modify node)
 *
 *  @param  aNode[TreeListItem]         节点信息(node information)
 *  @param  isUpdateChannelName[BOOL]   修改DVR节点的时候，是否同步修改下级通道的名称，默认YES
 *
 *  @since  v2.4.10.0
 */
- (void)modifyNodeInfo:(TreeListItem *)aNode;
- (void)modifyNodeInfo:(TreeListItem *)aNode isUpdateChannelName:(BOOL)isUpdateChannelName;

/**
 *  @brief  修改设备通道数(modify dvr channels)
 *
 *  @param  aNode[TreeListItem]     节点信息(node information)
 *  @param  aChannels[int]          通道数(Channels)
 *
 *  @since  v2.4.12.9
 */
- (void)modifyNodeChannels:(TreeListItem *)aNode
                  channels:(int)aChannels;


/**
 *  @brief  通过umid查询节点在线状态,请勿频繁查询(check the node on-line status)
 *
 *  @param  aNodes[id<TreeListItem,NSMutableArray>] 节点信息(node information)
 *
 *  @since  v2.4.10.0
 */
- (void)nodeStatus:(id)aNodes;


/**
 *  @brief  通过sDevId查询节点在线状态,请勿频繁查询，客户定制接口，正常用户请使用nodeStatus接口查询设备状态
 *
 *  @param  aNodes[id<TreeListItem,NSMutableArray>] 节点信息
 *
 *  @since  v2.4.11.12
 */
- (void)nodeStatusAtDevId:(id)aNodes;

/**
 *  @brief  删除节点(delete node)
 *
 *  @param  aNodes[NSMutableArray or TreeListItem] 节点信息(node information)
 *
 *  @since  v2.4.10.0
 */
- (void)deleteNodeInfo:(id)aNodes;

#pragma mark - push alarm
/**
 *  @brief  查询报警记录，建议使用分页功能，因为在数据量大的情况下，查询所有数据会比较慢(It’s recommended to use the paging function for querying alarm records because it will be slow when all records are queried in the case of big amount of data.)
 
 *  @param  aPageIndex[int]                     分页功能，可选，指定从第几页开始，起始值：1，0为不分页(paging function, optional, specify which page to start from, starting value: 1, no paging for 0)
 
 *  @param  aPageSize[int]                      分页功能，可选，每页返回的记录数，0为不限制(paging function, optional, the record numbers returned of each page，no limit for 0)
 
 *  @param  aDevId[NSString]                    设备ID，可选(device ID[sDevId]，required)
 
 *  @param  aAlarmEvents[NSArray]               报警事件，可选,HKS_NPC_D_MON_ALARM_TYPE(alarm events，required,HKS_NPC_D_MON_ALARM_TYPE)
 
 *  @param  aStatTime[NSString]                 开始时间，可选，格式：xxxx-xx-xx xx:xx:xx(start time，optional，format：xxxx-xx-xx xx:xx:xx)
 
 *  @param  aEndTime[NSString]                  结束时间，可选，格式：xxxx-xx-xx xx:xx:xx(end time，optional，format：xxxx-xx-xx xx:xx:xx)
 *  @param  is_grater[int]                      是否查询大于指定alarm_id的数据，可选：-1，传1的时候查询到的是最新的数据
 *  @param  aAlarmId[int]                       指定报警ID，可选：-1
 
 *  @since  v2.4.10.0
 */
- (void)alarmLogs:(int)aPageIndex
             size:(int)aPageSize
            devId:(NSString *)aDevId
      alarmEvents:(NSArray *)aAlarmEvents
        startTime:(NSString *)aStartTime
          endTime:(NSString *)aEndTime
        is_grater:(int)is_grater
          alarmId:(int)aAlarmId;

/**
 *  @brief  删除报警记录(query alarm records)
 *
 *  @param  aAlarmId[id->NSString or NSArray<NSString>] 报警ID,可选(alarm ID, optional)
 *  @param  aDevId[NSString]                    设备ID，可选(sDevId，optional)
 *  @param  aAlarmEvents[NSArray]               报警事件，可选,HKS_NPC_D_MON_ALARM_TYPE(alarm events，optional,HKS_NPC_D_MON_ALARM_TYPE)
 *  @param  aStatTime[NSString]                 开始时间，可选(start time，optional)
 *  @param  aEndTime[NSString]                  结束时间，可选(end time，optional)
 *
 *  @since  v2.4.10.0
 */
- (void)deleteAlarmLogs:(id)aAlarmId
                  devId:(NSString *)aDevId
            alarmEvents:(NSArray *)aAlarmEvents
              startTime:(NSString *)aStartTime
                endTime:(NSString *)aEndTime;


/**
 *  @brief  查询设备布防、通知信息，不支持免登录布放(query device protection and notice，)
 *
 *  @param  aDevId[NSString]    sDevId
 *
 *  @since  v2.4.10.0
 *  @deprecated 已过时
 */
- (void)deviceAlarmInfo:(NSString *)aDevId UMAccountDeprecated("该接口已过时,请使用deviceAlarmInfoAtItem");

/**
 *  @brief  查询设备布防、通知信息,支持免登录布放(query device protection and notice)
 *
 *  @param  aDevItem[TreeListItem]  device(sDevId,sDeviceId,iChannel,sNodeName)
 *  @return [HKSDeviceAlarmItem]通过回调接口传递参数
 *  @since  v2.4.12.1
 */
- (void)deviceAlarmInfoAtItem:(id)aDevItems;


/**
 *  @brief  修改设备布防/撤防/取消通知(modify device protection/ removal/ cancel notification)
 *
 *  @param  aDevId[id]                  设备ID或者设备ID列表，支持NSString和Array类型(device ID or device ID list, support NSString or Array type)
 
 *  @param  aOpcode[int]                操作ID，1：布防/布防通知，2：撤防，3：取消布防通知，4：对所有设备进行撤防，必填(operation ID，1：protection/protection notice，2：removal，3：remove protection notice, required，4：removal all device)
 
 *  @param  alarmEvents[NSMutableArray] 报警事件，必填,HKS_NPC_D_MON_ALARM_TYPE(alarm events, required,HKS_NPC_D_MON_ALARM_TYPE)
 
 *  @param  aNotifyType[int]            消息类型，1表示手机推送、2表示短信通知、3表示EMAIL，暂时只支持手机推送的方式(notification type: 1.mobile push; 2. short message; 3. Email. At present it only supports mobile push.)
 
 *  @param  aNotifyParam[NSString]      消息参数，根据不同的通知类型指定相应的值，比如消息类型是手机推送的时候，消息参数为手机的token值(message parameters, specifying the corresponding values according to different notification types. For example, when it is mobile push, the message parameter is the value token of the mobile.)
 
 *  @param  aDisableNotify[int]         disable notify,1:disable,0:enable
 
 *  @since  v2.4.10.0
 *  @deprecated 已过时
 */
- (void)modifyDeviceAlarmInfo:(id)aDevIds
                       opcode:(int)aOpcode
                  alarmEvents:(NSMutableArray *)aAlarmEvents
                   notifyType:(int)aNotifyType
                  notifyParam:(NSString *)aNotifyParam
                disableNotify:(int)aDisableNotify UMAccountDeprecated("该接口已过时");

- (void)modifyDeviceAlarmInfoAtItem:(id)aDevItems
                             opcode:(int)aOpcode
                        alarmEvents:(NSMutableArray *)aAlarmEvents
                         notifyType:(int)aNotifyType
                        notifyParam:(NSString *)aNotifyParam
                      disableNotify:(int)aDisableNotify UMAccountDeprecated("该接口已过时");

/**
 *  @brief  修改设备布防/撤防/取消通知,支持免登录模式(modify device protection/ removal/ cancel notification)
 *
 *  @param  aDevItems    设备对象(device item)
 *  @param  aOpcode 操作ID，1：布防/布防通知，2：撤防，3：取消布防通知，必填(operation ID，1：protection/protection notice，2：removal，3：remove protection notice, required)
 *  @param  aAlarmEvents 报警事件，必填,HKS_NPC_D_MON_ALARM_TYPE(alarm events, required,HKS_NPC_D_MON_ALARM_TYPE)
 *  @param  aDisableNotify  disable notify,1:disable,0:enable
 
 *  @since  v2.4.12.1
 */
- (void)modifyDeviceAlarmInfoAtItem:(id)aDevItems
                             opcode:(int)aOpcode
                        alarmEvents:(NSMutableArray *)aAlarmEvents
                      disableNotify:(int)aDisableNotify;

/**
    @brief  查询用户推送信息(query user push information)

    @return  aParam[id->NSDictionary]   回调返回的类型为NSDictionary(callback return type is NSDictionary)
    @since  v2.4.10.0
 */
- (void)userPushInfo;

/**
    @brief  修改用户推送信息，支持未登录之前调用(modify user push information)
 
    @param  aIfEnable[BOOL]              是否开启该账号的推送(open the push of this account or not)
 
    @param  aIfDisableOtherUsers[BOOL]   是否禁止当前手机本APP的其他账号推送(inhibit the push of other accounts of this mobile appor not)
 
    @param  aUnReadCount[BOOL]           把推送的未读记录数设置为指定的值(set the number of unread records as a specified value)
    @param  aUserId[NSString]            用户id，未登录情况下，才需要填写。(user id)
 
    @since  v2.4.10.0
 */
- (void)modifyUserPushInfo:(BOOL)aIfEnable
         disableOtherUsers:(BOOL)aIfDisableOtherUsers
               unReadCount:(int)aUnReadCount
                    userId:(NSString *)aUserId;

- (void)modifyUserPushInfo:(BOOL)aIfEnable
         disableOtherUsers:(BOOL)aIfDisableOtherUsers
               unReadCount:(int)aUnReadCount
                    userId:(NSString *)aUserId
              platformFlag:(NSString *)platformFlag;

#pragma mark - 请求验证码

/// 请求发送短信消息
/// @param phone 手机号码
/// @param areaCode 手机区号
/// @param type 消息类型：1：找回密码，2：注册，3：激活通知，3：运维
- (void)sendSmsMessage:(NSString *)phone
              areaCode:(int)areaCode
               msgType:(int)type;

/// 请求发送邮寄消息
/// @param email 邮箱号码
/// @param type 消息类型：1：邮箱注册用户验证码、2：邮箱修改密码验证码
- (void)sendEmailMessage:(NSString *)email
                 msgType:(int)type;

/// 请求推送短信
/// @param aPhone 手机号码
/// @param aAreaCode 手机号码归属国际区号
/// @param aType 用途：1：找回密码，2：注册，3：激活通知，3：运维
- (void)pushPhoneSMS:(NSString *)aPhone
            areaCode:(NSString *)aAreaCode
                type:(int)aType;
/// 请求推送邮件
/// @param email 邮箱地址
/// @param type 邮箱验证码类型，1：邮箱注册用户验证码、2：邮箱修改密码验证码
- (void)pushEmailMsg:(NSString *)email
                type:(int)type;


/// 请求设备超级密码，通过APP扫描设备端二维码获取请求数据
/// @param mac mac，设备端提供
/// @param time time，设备端提供
/// @param phone 手机号码，设备端提供
/// @param area 手机号码区号，设备端提供
/// @param email 邮箱，设备端提供
/// @param noticeType 通知类型，设备提供
- (void)deviceSuperPassword:(NSString *)mac
                       time:(NSString *)time
                      phone:(NSString *)phone
                       area:(int)area
                      email:(NSString *)email
                 noticeType:(int)noticeType;
#pragma mark - cloud
- (void)cloudFileList:(NSMutableArray *)items createModel:(int)aCreateMode alarmType:(int)aAlarmType startTime:(NSString *)aStartTime endTime:(NSString *)aEndTime;

- (void)deleteCloudFileList:(NSMutableArray *)items;

/// 异步发送数据包
/// @param apiId 功能ID
/// @param parameters 参数
/// @param version 版本号
/// @param completionHandler 结果回调
- (void)asyncSendRequest:(int)apiId
              parameters:(NSDictionary *)parameters
                 version:(NSString *)version
                 handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

- (void)asyncSendRequest:(int)apiId
              parameters:(NSDictionary *)parameters
                 handler:(void (^)(NSDictionary *, NSError *))completionHandler;
#pragma mark - app info
/**
 *  @brief  查询客户端信息,比如版本信息(query the app information such as the version number)
 *
 *  @since  v2.4.10.0
 */
- (void)clientInfo;

#pragma mark - 广告
/**
 *  @brief  banner list
 *
 *  @since  v2.4.10.0
 */
- (void)bannerList;

#pragma mark - http图片上传
- (void)updateImageAtImage:(UIImage *)aImage
                             handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

#pragma mark - 分享节点
/**
*  @brief      获取分享节点列表
*  @param[in]  aParam      分享类型：0:项目列表，1:分享给我的列表，2:我分享给别人的列表
*  @since  v2.4.10.0
*/
- (void)sharkNode:(int)aParam;

/**
*  @brief      编辑分享节点列表
*  @param[in]  aOpcode     操作码：1:分享节点，2:删除我分享的节点
*  @param[in]  aType       分享类型：0:由系统分配，1:表示用户分享
*  @param[in]  aNodeIds    分享的节点数组
*  @param[in]  aUserId     分享的目标用户名
*  @param[in]  aRights     分享的权限组
*  @since  v2.4.10.0
*/
- (void)modifySharkNode:(int)aOpcode
                   type:(int)aType
                nodeIds:(NSMutableArray *)aNodeIds
                   user:(NSString *)aUserId
                 rights:(NSMutableArray *)aRights;


/// 查询设备的分享用户列表
/// @param item 设备对象
- (void)sharkUserList:(TreeListItem *)item;

/// 清除某设备ID的所有用户绑定信息
/// @param umid     设备ID
/// @param compId   公司ID
/// @param pk       产品ID
/// @param mac      设备MAC
/// @param rsaPubKey rsa公钥
- (void)deleteUMIDLinkUser:(NSString *)umid
                    compId:(NSString *)compId
                        pk:(NSString *)pk
                       mac:(NSString *)mac
                 rsaPubKey:(NSString *)rsaPubKey;

- (void)deleteUMIDLinkUser:(NSString *)umid
                    compId:(NSString *)compId
                        pk:(NSString *)pk
                       mac:(NSString *)mac
                 rsaPubKey:(NSString *)rsaPubKey
                    userId:(NSString *)userId;

- (void)testSendData:(id)aParam id:(int)aId key:(NSString *)aKey;

#pragma mark -
- (void)setUMIDMode:(int)aMode;
- (NSString *)localDevIdAtUMID:(NSString *)aNodeId umid:(NSString *)sDeviceId channel:(int)aChNo nodeType:(int)aNodeType;

#pragma mark - 已过时
/**
 *  @brief  设置网络状态，需要UI层要网络尽改变时调用该函数设置网络状态，如网络断开或网络连接时调用，该接口主要是加快底层重连速度。
 *
 *  @param[in]  state[int]  网络连接状态，0：断开状态，1：连接状态
 *  @since v2.4.11.15
 */
- (void)setClientNetState:(int)state UMAccountDeprecated("该接口已过时,由SDK内部自动处理，上层无需处理");

/// 重新连接
- (void)reconnectServer UMAccountDeprecated("该接口已过时");
@end
