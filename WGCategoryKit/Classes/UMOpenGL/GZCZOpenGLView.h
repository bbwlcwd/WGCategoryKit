//
//  SurveillanceClient
//
//  Created by Jiexiong Zhou on 12-4-7.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    
    GZCZVideoFrameFormatRGB = 1,
    GZCZVideoFrameFormatYUV = 2,
} GZCZVideoFrameFormat;

@interface GZCZOpenGLView : UIView {
        void *_userData;
        BOOL _isFullScreen;
    
}
@property(nonatomic, assign) int glMode;
@property(nonatomic, strong) UIColor *displayBackgroundColor;
@property(nonatomic, assign) BOOL   hiddenView;
@property(nonatomic, assign) BOOL   isInitGLView;
@property(nonatomic, assign) UIApplicationState appState;

/*
 @brief  设置显示模式。1 - 半球A、2 - 半球B、3 - 单平面、4 - 圆柱、5 - 双平面、6 - 四视口
 */
@property(nonatomic, assign) int glShowType;
/*! @brief  播放界面的Controller */
@property(nonatomic, assign) id viewController;

@property(nonatomic, assign) bool autoRun;
@property(nonatomic, assign) bool isAutoUpdate;

@property (nonatomic, assign) int   offsetSize;//70
@property (nonatomic, assign) int   wideAngle;//180


- (BOOL)setupGLView;
- (void)updateGLView;

/**
 *  @brief      刷新openGL控件图像
 *
 *  @param[in]  video[void *]           视频yuv数据
 *  @param[in]  videoWidth[uint32_t]    宽
 *  @param[in]  videoHeight[uint32_t]   高
 *  @param[in]  orientation[int]        图像是否处理，0：不做任何处理，1：上下倒转（左右会调换），2：左右翻转，3：上下倒转（左右会调换）
 */
- (void)displayVideo:(void *)video 
          videoWidth:(uint32_t)videoWidth 
         videoHeight:(uint32_t)videoHeight 
         orientation:(int)orientation;


/**
 *  @brief      刷新openGL控件图像
 *
 *  @param[in]  y[unsigned char *]      视频y数据
 *  @param[in]  u[unsigned char *]      视频u数据
 *  @param[in]  v[unsigned char *]      视频v数据
 *  @param[in]  videoWidth[uint32_t]    宽
 *  @param[in]  videoHeight[uint32_t]   高
 *  @param[in]  orientation[int]        图像是否处理，0：不做任何处理，1：上下倒转（左右会调换），2：左右翻转，3：上下倒转（左右会调换）
 */
- (void)displayVideo:(unsigned char *)y
                   u:(unsigned char *)u
                   v:(unsigned char *)v
          videoWidth:(uint32_t)videoWidth
         videoHeight:(uint32_t)videoHeight
         orientation:(int)orientation;

- (void)displayVideo:(void *)video
                   y:(unsigned char *)y
                   u:(unsigned char *)u
                   v:(unsigned char *)v
          videoWidth:(uint32_t)videoWidth
         videoHeight:(uint32_t)videoHeight
         orientation:(int)orientation
         frameFormat:(GZCZVideoFrameFormat)frameFormat
             dataLen:(int)aDataLen;


- (void)clear;

- (BOOL)updateVideoRenderer;
- (BOOL)updateVideoRenderer:(GZCZVideoFrameFormat)theFrameFormat;

- (void)setFullScreen:(BOOL)isFull;


@end
