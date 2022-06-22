//
//  UMLogMacros.h
//  UMLog
//
//  Created by Fred on 2018/5/21.
//

#ifndef UMLogMacros_h
#define UMLogMacros_h
#import <Foundation/Foundation.h>
#define UMLogLevelAll   UMLogFlagVerbose
typedef NS_OPTIONS(NSUInteger, UMLogLevel){
    UMLogLevelError      = (1 << 0),
    UMLogLevelWarning    = (1 << 1),
    UMLogLevelInfo       = (1 << 2),
    UMLogLevelDebug      = (1 << 3),
    UMLogLevelVerbose    = (1 << 4)
};

#endif /* UMLogMacros_h */
