/*!
 @class  UMWebClient (Smart)
 @brief  用户系统类-智能家居
 @since  v2.4.10.0
 */

#import "UMWebClient.h"

@interface UMWebClient (Smart)
#pragma mark - 情景模块
/**
 *  @brief      查询情景
 *  @server     3.0.0
 */
- (void)scenarioList;
/*
 *  @brief      添加情景
 *  @param[in]  aParam
 {
 "name": "xx",
 "img": "http://www.xxx.com/xxx.jpg",
 "scene_items": [
 {
 "scene_id": "1",
 "dev_items": [
 {
 "node_id": "323232",
 "node_states":
   [
    {
      "state":1,
      "channel":0
    },
    {
      "state":1,
      "channel":1
    }
   ]
 }
 ]
 }
 ]
 }
 *  @server     3.0.0
 */
- (void)addScenario:(id)aParam;
/*
 *  @brief      修改情景
 *  @param[in]  aParam
 {
 "id": "1",
 "name": "xx",
 "img": "http://www.xxx.com/xxx.jpg",
 "scene_items": [
 {
 "scene_id": "1",
 "dev_items":
 [
   {
   "node_id": "323232",
   "node_states":
   [
     {
      "state":1,
      "channel":0
     },
     {
       "state":1,
       "channel":1
     }
   ]
   }
 ]
 }
 ]
 }
 *  @server     3.0.0
 */
- (void)modifyScenario:(id)aParam;

/**
 *  @brief      删除情景
 *  @param[in]  aParam[NSMutableArray]  删除的情景id列表
 *  @server     3.0.0
 */
- (void)delScenario:(id)aParam;
#pragma mark - 场景模块

/**
 *  @brief      查询场景
 */
- (void)sceneList;
/**
 *  @brief      添加场景
 *  @param[in]  aParam
 {
 "name":"xx",
 "img":"http://www.xxx.com/xxx.jpg",
 "link_ids":["132323","323232"]
 *  @server     3.0.0
 }
 */
- (void)addScene:(id)aParam;
/**
 *  @brief      修改场景
 *  @param[in]  aParam
 {
 "id":"1"
 "name":"xx",
 "img":"http://www.xxx.com/xxx.jpg",
 "link_ids":["132323","323232"]
 }
 *  @server     3.0.0
 */
- (void)modifyScene:(id)aParam;
/**
 *  @brief      删除场景
 *  @param[in]  aParam[NSMutableArray]  删除的场景id列表
 *  @server     3.0.0
 */
- (void)delScene:(id)aParam;

#pragma mark - 意见反馈

/**
 *  @brief      意见反馈
 *  @param[in]  aParam
 {
 "contact":"xx",
 "content":"xx"
 }
 *  @server     3.0.0
 */
- (void)feedback:(id)aParam;

@end
