//
//  HKSCurriculumAtWeekItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/20.
//
//

#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *  @class      HKSCurriculumAtWeekItem.h
 *  @brief      课程表对象，根据星期和课程表的类型区分
 */
///#end
///#begin en
///#end
@interface HKSCurriculumAtWeekItem : NSObject

/** @brief  星期几，0：星期日，1：星期一，2：星期二。。。  */
@property(nonatomic, assign) int            iWeek;

/** @brief  某一天的所有课程<HKSCurriculumAtTypeItem>  */
@property(nonatomic, strong) NSMutableArray *tAllCurriculumsAtType;


@end
