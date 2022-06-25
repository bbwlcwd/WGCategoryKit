
typedef void (^portDataCallback)(void *in_pUserData, void *in_pPortData, unsigned char *in_pDataBuf, int in_iDataLen);

/**
 *  @brief      端口映射相关接口
 */
@interface DeviceNetPortClient : NSObject

/**
 *  @brief              查询最优服务器
 *
 *  @return[NSString]   ust服务器地址，返回nil的时候表示查询失败
 *  @since  v2.7.1.9
 */
+ (NSString *)ustServer:(NSString *)aHttpHost
                 serverProt:(int)aPort;

/**
 *  @brief          启动sdk
 *
 *  @param[in]      aHost[NSString]         服务器地址
 *  @param[in]      aPort[int]              服务器端口
 *  @param[in]      bIfQueryServer[BOOL]    是否需要查询最优服务器，如果在调用该接口之前已经调用ustServer:接口查询过最优服务器，就传入NO,否则传入YES
 *  @param[in]      aTimeout[int]           超时时间,秒
 *  @return[int]    1:失败，2:成功
 *  @since  v2.7.1.9
 */
+ (int)startSDK:(NSString *)aHost
     serverProt:(int)aPort
 bIfQueryServer:(BOOL)bIfQueryServer
        timeout:(int)aTimeout;

/**
 *  @brief          初始化端口映射
 *
 *  @return[int]    1:失败，2:成功
 *  @since  v1.0.0.0
 */
+ (int)initClientWithServerInfo:(NSString *)aUstAddress
                     serverProt:(int)aPort UMP2PDeprecated("该接口已过时");

/**
 *  @brief          版本号
 *
 *  @since  v1.0.0.0
 */
+ (NSString *)version;


/**
 *  @brief          服务器连接状态
 *
 *  @return[int]    0：未连接，1：正在连接，2：已连接，返回9表示错误
 *  @since  v1.0.0.0
 */
+ (int)clientStatus;


/**
 *  @brief          添加映射端口
 *
 *  @param[in]      sUMID[NSString]映射端口设备的umid
 *  @param[in|out]  sLocalProt[unsigned short ]本地映射端口号，如果值为0，则由系统分配端口号
 *  @return[int]    0：成功，其他：失败
 *  @since  v1.0.0.0
 */
+ (int)addPort:(NSString *)sUMID
  outLocalPort:(unsigned short *)sLocalProt;


/**
 *  @brief          根据设备通道添加映射端口
 *
 *  @param[in]      sUMID[NSString]映射端口设备的umid
 *  @param[in]      aChNo[int]映射的通道号
 *  @param[in|out]  sLocalProt[unsigned short ]本地映射端口号，如果值为0，则由系统分配端口号
 *  @return[int]    0：成功，其他：失败
 *  @since  v1.0.0.0
 */
+ (int)addPortByChNo:(NSString *)sUMID
             channel:(int)aChNo
        outLocalPort:(unsigned short *)sLocalProt;


/**
 *  @brief          删除映射端口
 *
 *  @param[in]      sLocalProt[unsigned short]本地映射端口号
 *  @return[int]    0：成功，其他：失败
 *  @since  v1.0.0.0
 */
+ (void)delPort:(unsigned short)sLocalProt;



/**
 *  @brief          清除设备状态查询列表
 *
 *  @since  v1.0.0.0
 */
+ (void)clearDeviceStatusList;



/**
 *  @brief          添加查询设备
 *
 *  @param[in]      sUMID[NSString]需要查询设备的umid
 *  @return[int]    YES：成功，NO：失败
 *  @since  v1.0.0.0
 */
+ (BOOL)addDeviceStatusAtUMID:(NSString *)sUMID;


/**
 *  @brief          请求查询设备状态列表
 *
 *  @return[int]    YES：成功，NO：失败
 *  @since  v1.0.0.0
 */
+ (BOOL)requQueryDeviceStatus;


/**
 *  @brief          根据umid获取设备在线状态
 *
 *  @return[int]    -1：获取失败，0：离线，1：在线
 *  @since  v1.0.0.0
 */
+ (int)deviceStatusAtUMID:(NSString *)aUMID;

/**
 *  @brief  释放端口映射相关内存
 *
 *  @since  v1.0.0.0
 */
+ (void)deallocClient;


/**
 *  @brief          根据umid连接设备
 *
 *  @param[in]      aUmid[char]         设备的umid
 *
 *  @return[int]    设备句柄
 *  @since  v2.7.2.1
 */
+ (void *)connectDevAtUMID:(NSString *)sUMID outIp:(char *)aIp outPort:(int *)aPort;

/**
 *  @brief          根据umid断开设备连接
 *
 *  @param[in]      hDevHandel[void *]         设备句柄
 *
 *  @since  v2.7.2.1
 */
+ (void)disconnetDevAtUMID:(void *)hDevHandel;

/**
 *  @brief          发送透传数据
 *
 *  @param[in]      hDevHandel[void *]         设备句柄
 *  @param[in]      in_pDataBuf[char]   发送的数据
 *  @param[in]      in_iDataBufLen[int] 发送的数据长度
 *  @param[in]      aTimeout[int]       超时时长(ms)
 *
 *  @return[BOOL]   发送是否成功
 *  @since  v2.7.2.1
 */
+ (BOOL)sendData:(void *)hDevHandle
        sendData:(char *)in_pDataBuf
     sendDataLen:(int)in_iDataBufLen
         timeout:(int)aTimeout;

+ (void)setCallback:(portDataCallback)in_pCallback;

/**
 *  @brief          获取透传数据
 *
 *  @param[in]      hDevHandel[void *]         设备句柄
 *  @param[out]     out_pDataBuf[char]      接收的数据
 *  @param[out]     out_iDataBufLen[int]    接收的数据长度
 *  @param[in]      aTimeout[int]       超时时长(ms)
 *
 *  @return[BOOL]   是否接收到数据
 *  @since  v2.7.2.1
 */
+ (BOOL)getData:(void *)hDevHandel
        dataBuf:(char *)out_pDataBuf
     dataBufLen:(int *)out_iDataBufLen
        timeout:(int)aTimeout;

+ (NSString *)printErrorLog;

@end
