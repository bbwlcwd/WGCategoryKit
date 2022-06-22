//
//  HKSRecipesAtTypeItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/20.
//
//

#import <Foundation/Foundation.h>

@interface HKSRecipesAtTypeItem : NSObject

/** @brief  就餐时间段，如：早餐，午餐等  */
@property(nonatomic, strong) NSString   *sRecipesTypeName;

/** @brief  就餐时间段，如：1:早餐，2:午餐，3:晚餐等  */
@property(nonatomic, assign) int        recipesType;

/** @brief  某一天某一个时间段的所有菜谱<HKSRecipesItem>  */
@property(nonatomic, strong) NSMutableArray *tAllRecipes;

@end
