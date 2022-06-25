//
//  UMP2PFaceListIndexModel.h
//  HKSUMEyeCloudLIb
//
//  Created by fred on 2019/8/19.
//  Copyright © 2019 Fred. All rights reserved.
//  人脸索引模型

#import <Foundation/Foundation.h>

@interface UMP2PFaceListIndexModel : NSObject
/// 索引（库索引、系统ID）
@property(nonatomic, assign)  int iLibIndex;
@property(nonatomic, assign)  int iFileIndex;
@property(nonatomic, assign)  long iFileSize;
@property(nonatomic, assign)  int iChecksum;
/// 名单模式
@property(nonatomic, assign)  int iMode;
/// 是否启用
@property(nonatomic, assign)  int bEnable;

/// 人员名称
@property(nonatomic, copy)  NSString *sName;
/// 文件名
@property(nonatomic, copy)  NSString *sFileName;
/// 人员编号（Number、UserId）
@property(nonatomic, copy)  NSString *sUserId;
@property(nonatomic, copy)  NSString *sFaceID;

@property(nonatomic, strong)  UIImage *img;

@end
