//
//  HKMPClinet.h
//  libUMEyeCloud
//
//  Created by fred on 2018/12/6.
//  Copyright © 2018年 Fred. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HKMPClinet : NSObject



@property(nonatomic, assign) int    state;

/*! @brief  播放画面视图(playing view) */
@property(nonatomic, strong) UIView     *view;
@property(nonatomic, strong) UIColor    *viewColor;

- (void)start:(NSString *)fileURL;
- (void)stop;
@end

NS_ASSUME_NONNULL_END
