
#import "HKSDeviceClient.h"

/**
 * @brief          定制接口功能类
 */
@interface HKSDeviceClient (CallCustom)

/// 定制功能json接口
/// @param aCusFuncId 定制功能ID
/// @param aSendBuffer 发送的数据
/// @param encoding 编码
- (NSString *)callCustomFuncAtJson:(int)aCusFuncId sendBuffer:(NSString *)aSendBuffer encoding:(NSStringEncoding)encoding;


/// 定制功能json接口
/// @param msgId 定制功能消息ID
/// @param param 数据
/// @param autoStop 是否发送完自动断开连接
/// @param completionHandler 数据回调
- (void)customFuncJson:(int)msgId
                 param:(NSDictionary *)param
              autoStop:(BOOL)autoStop
               handler:(void (^)(id data, int errorCode))completionHandler;

/// 定制功能接口
/// @param aCusFuncId 定制功能ID
/// @param aCusBodyBuf 定制包体缓冲区
/// @param aCusBoyLen 定制包体长度
/// @param aRespBodyBuf 应答包体缓冲区，由该函数分配内存，需调用callCustomFuncReleaseBuf释放
/// @param aRespBodyLen 应答包体长度
- (int)callCustomFunc:(int)aCusFuncId
           bodyBuffer:(unsigned char *)aCusBodyBuf
              bodyLen:(int)aCusBoyLen
          respBodyBuf:(unsigned char **)aRespBodyBuf
          respBodyLen:(int *)aRespBodyLen;


/**
 *  @brief  定制功能资源释放
 *  @param  aDataBuf    定制包体缓冲区
 */
- (void)callCustomFuncReleaseBuf:(unsigned char *)aDataBuf;
@end
