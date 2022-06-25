//
//  UMHLSProtocol.h
//  UMHLS
//
//  Created by fred on 2020/9/28.
//

#ifndef UMHLSProtocol_h
#define UMHLSProtocol_h

@protocol UMHLSClientDelegate<NSObject>

/// 当前播放位置
/// @param client 播放对象
/// @param currentTime 当前位置
/// @param totalTime 总时长
/// @param totalBuffer 缓存时长
- (void)umHLSTime:(id)client currentTime:(NSInteger)currentTime totalBuffer:(NSInteger)totalBuffer totalTime:(NSInteger)totalTime;


/// 播放状态
/// @param client 播放对象
/// @param status 播放状态
/// @param error 错误信息
- (void)umHLSStatus:(id)client status:(UMHLSClientStatus)status error:(NSError *)error;

@end

#endif /* UMHLSProtocol_h */
