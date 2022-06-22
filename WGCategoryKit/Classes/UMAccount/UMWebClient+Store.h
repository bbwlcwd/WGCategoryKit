/*!
 @class  UMWebClient (Store)
 @brief  用户系统类-连锁店
 @since  v2.4.10.0
 */

#import "UMWebClient.h"
#pragma mark -
enum{
    /** @brief  巡店计划  */
    UM_WEB_API_WS_STORE_EVENT_FROM_STOREPLAN = 1,
    /** @brief  防盗计划  */
    UM_WEB_API_WS_STORE_EVENT_FROM_PICKPROOFPLAN = 2,
    /** @brief  实时预览  */
    UM_WEB_API_WS_STORE_EVENT_FROM_LIVEPREVIEW = 3,
    /** @brief  录像回放  */
    UM_WEB_API_WS_STORE_EVENT_FROM_BACKPLAY = 4,
    /** @brief  现场巡店  */
    UM_WEB_API_WS_STORE_EVENT_FROM_PHONE = 5,
};
/** @brief  事件来源  */
typedef int UM_WEB_API_WS_STORE_EVENT_FROM_ID;

@interface UMWebClient (Store)

#pragma mark - 连锁店专用接口
/** @brief  用户动态    */
- (void)userDynamics;

#pragma mark -

/** @brief  获取用户下所有门店所在的区域列表    */
- (void)nodeCitiesList;

#pragma mark - 事件相关
/** @brief  类型事件列表  */
- (void)eventTypeList;
/** 
 *  @brief  事件列表
 *  @param[in]  aEventTypes[NSMutableArray] 事件类型数组
 *  @param[in]  aShopIds[NSMutableArray]    门店列表
 *  @param[in]  aStartTime[NSString]        开始时间
 *  @param[in]  aEndTime[NSString]          结束时间
 */
- (void)eventList:(NSMutableArray *)aEventTypes
          shopIds:(NSMutableArray *)aShopIds
        startTime:(NSString *)aStartTime
          endTime:(NSString *)aEndTime;

/**
 *  @brief  根据id查询事件
 *  @param[in]  aEventId[NSString]  事件id
 */
- (void)eventById:(NSString *)aEventId;

/*
 *  @brief  添加事件
 *  @param[in]
 {
 "dev_id":"",
 "img_url": "",
 "evt_from":"",
 "evt_type_id": "0",
 "priority": "1",
 "assign" : "1",
 "complete_time" : "2017‐10‐12 10:10:10",
 "carbon_copy": [
 {"user_id":"12", "user_name":"xxxx"}
 ],
 "desc": "" 
 }
 */
- (void)addEvent:(id)aParam;

/**
 *  @brief      删除事件
 *  @param[in]  aParam[NSString]    事件id
 */
- (void)delEvent:(id)aParam;

/**
 *  @brief      事件处理流程
 *  @param[in]  aParam[NSString]    事件id
 */
- (void)eventProcessingFlow:(id)aParam;

/**
 *  @brief      修改事件
 *  @param[in]  aParam[NSString]    事件id
 *  @param[in]  aStatus[int]        状态
 */
- (void)modifyEvent:(id)aEventId status:(int)aStatus;

/** 
 * @brief       查询要指派或抄送的人员
 * @param[in]   aShopID[NSString]   门店的id
 */
- (void)eventUserList:(NSString *)aShopID;

/**
 * @brief       提交事件的处理结果
 * @param[in]   
 {
 "evt_id":"xxxxxx",
 "handler_id":"xxx",
 "desc":"xxx",
 "result":"xxx",
 "attach":"xxx",
 "state":1
 }
 */
- (void)eventSubmit:(id)aParam;

#pragma mark - 巡店计划相关
/** @brief  巡店计划列    */
- (void)storePlanList;

/**
 *  @brief      查询巡店计划图片
 @param  aParam[in]
 {
 "plan_id":"xxx",    //""值的时候表示查询计划id
 "page_index":1,     //分页功能，指定从第几页开始，是可选的，默认不分页
 "page_size":10      //分页功能，每页返回的记录数，是可选的，默认不分页
 }
 */
- (void)storePlanListImage:(id)aParam;

/**
 *  @brief  添加巡店计划
 *  @param[in]
 { 
 "plan_name":"计划名称",
 "state":1,
 "shop_count":3,
 "devs":[
 {"shop_id":"门店ID","dev_id":"镜头ID"} ],
 "times":["巡店时间1","巡店时间2","巡店时间3"] 
 }
 */
- (void)addStorePlan:(id)aParam;

/**
 *  @brief      修改巡店计划
 *  @param[in]  aParam[NSString]    id
 *  @param[in]  aStatus[int]        状态
 */
- (void)modifyStorePlan:(id)aId state:(int)aState;

/**
 @brief  删除巡店计划
 
 @param  aParam[NSArray]    巡店计划id数组
 
 @since  2.7.4.4
 */
- (void)deleteStorePlan:(id)aParam;

/**
 @brief  删除巡店计划图片
 
 @param  aParam[NSArray]    图片id数组
 @param  sPlanId[NSString]  计划Id，删除该计划下所有图片，才需要传值
 
 @since  2.7.4.4
 */
- (void)deleteStorePlanImage:(id)aParam planId:(NSString *)sPlanId;

#pragma mark - 防盗计划相关
/** 
 *  @brief  防盗计划列表
 *  @param  sPlanId[NSString]   防盗计划id，“”：表示查询所有。
 *  @param  aPageIndex[int]     分页功能，指定从第几页开始，0:表示不分页
 *  @param  aPageSize[int]      分页功能，每页返回的记录数，0:表示不分页
 *  @param  bOnlySelf[int]      是否只查自己的防盗计划，
 */
- (void)pickproofPlanList:(NSString *)sPlanId
                pageIndex:(int)aPageIndex
                 pageSize:(int)aPageSize
                 onlySelf:(BOOL)bOnlySelf;

/**
 @brief  查询防盗计划的镜头报警图片列表
 @param  aParam[in]
 {
 "plan_id":"xxx",    //""值的时候表示查询计划id
 "page_index":1,     //分页功能，指定从第几页开始，是可选的，默认不分页
 "page_size":10      //分页功能，每页返回的记录数，是可选的，默认不分页
 }
 @since  2.7.4.4
 */
- (void)pickproofPlanImageList:(id)aParam;

/** 
 *  @brief  添加防盗计划
 *  @param[in]
 {
 "state":1, "plan_name":"防盗计划1", "devs":[{"shop_id":"门店ID","dev_id":"镜头ID"} ],
 "start_time":"防盗开始时间", "end_time":"防盗结束时间", "receivers":[{"user_id":"12", "user_name":"xxxx"}]
 }
 */
- (void)addPickproofPlan:(id)aParam;

/**
 *  @brief      修改防盗计划
 *  @param[in]  aParam[Dic]
 { 
    "plan_id":"计划ID", "state":1, "devs":[{"shop_id":"门店ID","dev_id":"镜头ID"}],"start_time":"防盗开始时间","end_time":"防盗结束时间"
 }
 */
- (void)modifyPickproofPlan:(id)aParam;

/**
 @brief  删除防盗计划
 
 @param  aParam[NSArray]    id数组
 
 @since  2.7.4.4
 */
- (void)deletePickproofPlan:(id)aParam;

/**
 @brief  删除防盗计划图片
 
 @param  aParam[NSArray]    图片id数组
 @param  sPlanId[NSString]  计划id，删除该计划下所有图片的时候才需要传值
 
 @since  2.7.4.4
 */
- (void)deletePickproofPlanImage:(id)aParam planId:(NSString *)sPlanId;

#pragma mark - 消息记录
/**
 @brief  查询消息列表
 
 @param  aParam[in]
 {
 "typs":["消息类型1","消息类型2","消息类型3"], 
 "page_index":1,
 "page_size":10
 }
 @since  2.7.4.4
 */
- (void)logList:(id)aParam;

/**
 @brief  删除消息列表
 
 @param  aParam[NSArray]    消息id数组
 
 @since  2.7.4.10
 */
- (void)delLog:(id)aParam;

/**
 @brief  阅读消息列表
 
 @param  aParam[NSArray]    消息id数组
 
 @since  2.7.4.10
 */
- (void)readLog:(id)aParam;

#pragma mark - 收藏
/**
 @brief  门店收藏列表
 
 @since  2.7.4.10
 */
- (void)storeFavorites;

/**
 @brief  添加门店收藏
 @param  aParam[NSArray]    门店id数组
 @since  2.7.4.10
 */
- (void)addStoreFavorites:(id)aParam;

/**
 @brief  删除门店收藏
 @param  aParam[NSArray]    门店id数组
 @since  2.7.4.10
 */
- (void)deleteStoreFavorites:(id)aParam;

#pragma mark - 抓拍图片
/**
 @brief  上传客户端抓拍图片
 *  @param[in]
 {
 "dev_id":3,        //镜头节点的link_id
 "dev_name":""      //镜头节点名称
 "shop_id":1,       //门店节点的link_id
 "shop_name":"",    //门店名称
 "small_img":"xxx", //大图url
 "big_img": "xxx"   //小图url
 }
 @since  2.7.6.5
 */
- (void)addSnappedImage:(id)aParam;
/**
 @brief  删除客户端抓拍图片
 *  @param[in]
 {
 "img_ids":["xx", "xx", "xx", "xx"],    //需要删除的图片id列表
 "dev_id":21                            //镜头节点的link_id，当需要删除设备下所有的图片的时候才需要传
 }
 @since  2.7.6.5
 */
- (void)delSnappedImage:(id)aParam;
/**
 @brief  查询客户端抓拍图片
 *  @param[in]
 {
 "dev_id":[1,3],            //镜头节点的link_id数组
 "start_time":"xxxx‐xx‐xx", //开始时间，可选
 "end_time":"xxxx‐xx‐xx",   //结束时间，可选
 "page_index":1             //分页功能，从第几页开始，可选
 "page_size":10             //分页功能，每页返回的最大记录数，可选
 }
 @since  2.7.6.5
 */
- (void)snappedImageList:(id)aParam;

#pragma makr -巡检评分
/**
 *  @brief  查询巡检项列表
 *  @param  iStoreId[int]   门店id
 *  @param  iType[int]      巡店类型，0：远程巡店，1：现场巡店
 *  @since  2.7.6.5
 */
- (void)inspectItemList:(int)iStoreId type:(int)iType;
/**
 @brief  提交巡检评分
 *  @param[in]
 {
 "store_id":1001,       //门店id
 "type":0,              //巡检类型,0:远程巡店,1:现场巡店
 "score":95,            //总评分
 "details":{
     "pass":[1,3],      //检查通过数组
     "flunk":[2],       //检查不通过数组
     "rectify":[5,6]    //需整改数组
 }
 @since  2.7.6.5
 */
- (void)addScores:(id)aParam;

#pragma mark -
//获取客流统计URL
- (NSString *)passengerVolumeURL;

- (NSString *)html5URL:(NSString *)aFilePath;

- (NSString *)html5URLEventManage;
- (NSString *)html5URLSafetyManage;
- (NSString *)html5URLTimeCruise;
@end
