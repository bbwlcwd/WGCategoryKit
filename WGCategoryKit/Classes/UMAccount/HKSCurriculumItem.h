//
//  HKSCurriculumItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/12.
//
//

#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *  @class      HKSCurriculumItem
 *  @brief      课程表对象
 */
///#end
///#begin en
///#end
@interface HKSCurriculumItem : NSObject

/** @brief  星期几，0：星期日，1：星期一，2：星期二。。。  */
@property(nonatomic, assign) int        week;

/** @brief  课程时间段，如：上午，下午等  */
@property(nonatomic, copy) NSString   *curriculumTypeName;

/** @brief  课程时间段，例如：1:上午，2:下午  */
@property(nonatomic, assign) int   time;

/** @brief  课程名称  */
@property(nonatomic, copy) NSString   *curriculumName;

/** @brief  课程内容  */
@property(nonatomic, copy) NSString   *curriculumContent;

/** @brief  大图片url  */
@property(nonatomic, copy) NSString   *bigImg;

/** @brief  小图片url  */
@property(nonatomic, copy) NSString   *smallImg;

/** @brief  老师  */
@property(nonatomic, copy) NSString   *teacher;

/** @brief  老师电话  */
@property(nonatomic, copy) NSString   *teacherPhone;
@end
