//
//  UMAuthenticationDelegate.h
//  UMBasis
//
//  Created by fred on 2019/4/28.
//

@protocol UMAuthenticationDelegate<NSObject>


- (void)asyncSendRequest:(int)apiId parameters:(NSDictionary *)parameter handler:(void (^)(NSDictionary *data, NSError *error))completionHandler;

@end
