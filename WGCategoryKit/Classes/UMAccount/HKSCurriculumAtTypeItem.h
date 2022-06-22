//
//  HKSCurriculumAtTypeItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/20.
//
//

#import <Foundation/Foundation.h>

@interface HKSCurriculumAtTypeItem : NSObject

/** @brief  课程表的类型名称  */
@property(nonatomic, strong) NSString *sCurriculumTypeName;

/** @brief  课程时间段，例如：1:上午，2:下午  */
@property(nonatomic, assign) int   time;

/** @brief  某一天某一个类型的所有课程<HKSCurriculumItem>  */
@property(nonatomic, strong) NSMutableArray *tAllCurriculums;

@end
