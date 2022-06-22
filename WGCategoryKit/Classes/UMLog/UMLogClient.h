//
//  UMLogClient.h
//  UMLog
//
//  Created by Fred on 2018/5/15.
//
NS_ASSUME_NONNULL_BEGIN

@interface UMLogClient : NSObject

+ (NSString *)version;

+ (void)addTag:(NSString *)aTag;

+ (void)delTag:(NSString *)aTag;

+ (void)log:(NSUInteger)flag
   function:(const char *)function
       line:(NSUInteger)line
        tag:(id __nullable)aTag
     format:(NSString *_Nullable)format, ...;

+ (NSArray<NSString *> *)exportLog;
@end
NS_ASSUME_NONNULL_END
