//
//  HKSRecipesAtWeekItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/20.
//
//

#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *  @class      HKSRecipesAtWeekItem
 *  @brief      菜谱对象,根据星期和就餐时间段区分
 */
///#end
///#begin en
///#end
@interface HKSRecipesAtWeekItem : NSObject

/** @brief  星期几，0：星期日，1：星期一，2：星期二。。。  */
@property(nonatomic, assign) int        iWeek;

/** @brief  某一天某一个时间段的所有菜谱<HKSRecipesAtTypeItem>  */
@property(nonatomic, strong) NSMutableArray *tAllRecipesAtType;



@end
