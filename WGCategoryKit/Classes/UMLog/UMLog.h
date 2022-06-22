//
//  UMLog.h
//  UMLog
//
//  Created by fred on 2020/2/19.
//

#ifndef UMLog_h
#define UMLog_h
    #import "UMLogMacros.h"
    #import "UMLogClient.h"

    #define ULogError(aTag, frmt, ...) \
    [UMLogClient log : UMLogLevelError \
    function : __PRETTY_FUNCTION__  \
        line : __LINE__ \
         tag : aTag  \
      format : (frmt), ## __VA_ARGS__]

    #define ULogWarning(aTag, frmt, ...)  \
    [UMLogClient log : UMLogLevelWarning \
    function : __PRETTY_FUNCTION__  \
        line : __LINE__ \
         tag : aTag  \
      format : (frmt), ## __VA_ARGS__]

    #define ULogInfo(aTag, frmt, ...) \
    [UMLogClient log : UMLogLevelInfo \
    function : __PRETTY_FUNCTION__  \
        line : __LINE__ \
         tag : aTag  \
      format : (frmt), ## __VA_ARGS__]

    #define ULogDebug(aTag, frmt, ...)    \
    [UMLogClient log : UMLogLevelDebug \
    function : __PRETTY_FUNCTION__  \
        line : __LINE__ \
         tag : aTag  \
      format : (frmt), ## __VA_ARGS__]

    #define ULogVerbose(aTag, frmt, ...)  \
    [UMLogClient log : UMLogLevelVerbose \
    function : __PRETTY_FUNCTION__  \
        line : __LINE__ \
         tag : aTag  \
      format : (frmt), ## __VA_ARGS__]

    #define ULogE(aTag, frmt, ...) ULogError(aTag, frmt, ##__VA_ARGS__)
    #define ULogW(aTag, frmt, ...) ULogWarning(aTag, frmt, ##__VA_ARGS__)
    #define ULogI(aTag, frmt, ...) ULogInfo(aTag, frmt, ##__VA_ARGS__)
    #define ULog(aTag, frmt, ...) ULogInfo(aTag, frmt, ##__VA_ARGS__)
    #define ULogD(aTag, frmt, ...) ULogDebug(aTag, frmt, ##__VA_ARGS__)

#endif /* UMLog_h */
