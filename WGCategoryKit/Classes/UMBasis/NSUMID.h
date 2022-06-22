//
//  NSUMID.h
//  UMCloud
//
//  Created by fred on 2017/9/15.
//  Copyright © 2017年 Fred. All rights reserved.
//

enum {
    /** @brief  正常  */
    UMID_TYPE_ID_NONE = 1,
    /** @brief  科达  */
    UMID_TYPE_ID_KD = 2
};
/** @brief  umid格式  */
typedef int UMID_TYPE_ID;

@interface NSUMID : NSObject{
    UMID_TYPE_ID    _type;
}
+ (NSUMID *)share;

- (void)setType:(UMID_TYPE_ID)aType;
- (NSString *)umidAtId:(NSString *)aId;
@end
