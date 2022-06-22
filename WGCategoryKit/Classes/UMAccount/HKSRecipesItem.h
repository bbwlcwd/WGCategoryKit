//
//  HKSRecipesItem.h
//  UMCloud
//
//  Created by UMEYE on 15/3/9.
//
//

#import <Foundation/Foundation.h>

///#begin zh-cn
/**
 *  @class      HKSRecipesItem
 *  @brief      菜谱对象
 */
///#end
///#begin en
///#end
@interface HKSRecipesItem : NSObject

@property(nonatomic, copy) NSString   *sId;
/** @brief  星期几，0：星期日，1：星期一，2：星期二。。。  */
@property(nonatomic, assign) int       week;

/** @brief  就餐时间段，如：1:早餐，2:午餐，3:晚餐等  */
@property(nonatomic, assign) int        recipesType;

/** @brief  就餐时间段，新接口无效  */
@property(nonatomic, copy) NSString   *recipesTypeName;

/** @brief  菜谱名称  */
@property(nonatomic, copy) NSString   *recipesMenuName;

/** @brief  菜谱简介，旧接口无效  */
@property(nonatomic, copy) NSString   *content;

/** @brief  菜谱大图片URL  */
@property(nonatomic, copy) NSString   *bigPicUrl;

/** @brief  菜谱小图片URL  */
@property(nonatomic, copy) NSString   *smallPicUrl;

/** @brief  菜谱介绍URL，新接口无效  */
@property(nonatomic, copy) NSString   *menuIntrUrl;

@end
