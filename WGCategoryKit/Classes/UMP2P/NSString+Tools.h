///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end


@interface NSString (Tools)

- (NSString *)aes256Md5Encrypt:(NSString *)aKey;
- (NSString *)aes256Md5Decrypt:(NSString *)aKey;

- (NSString *)aes256Base64Encrypt:(NSString *)key options:(int)iOptions;
- (NSString *)aes256Base64Decrypt:(NSString *)key;

//aes256加密、解密
- (NSString *)aes256Encrypt:(NSString *)key options:(int)iOptions;
- (NSString *)aes256Decrypt:(NSString *)key;

//md5 32位加密
- (NSString *)md532Encrypt;

//获取域名下所有IP
- (NSMutableArray *)ipList;

//获取域名下随机一个IP
- (NSString *)ip;

- (NSString *)iPhoneType;

+ (BOOL)isNull:(NSString *)str;
@end
