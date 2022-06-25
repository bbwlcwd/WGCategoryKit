//
//  HKSDeviceClient+JuLong.h
//  UMCloud
//
//  Created by UMEYE on 16/6/18.
//
//

#import "HKSDeviceClient.h"
#import "UMP2PFaceListIndexModel.h"
typedef enum _PNPC_S_FACE_CMP_ATTRIBUTE_EMOTION
{
    ATTRIBUTE_EMOTION_SMILE        = 0x5,      //微笑
    ATTRIBUTE_EMOTION_ANGRY        = 0xf,      //表情 生气
    ATTRIBUTE_EMOTION_CLAM         = 0x10,     //表情 平静
    ATTRIBUTE_EMOTION_HAPPY        = 0x12,     //表情 高兴
    ATTRIBUTE_EMOTION_SAD          = 0x13,     //表情 悲伤
    ATTRIBUTE_EMOTION_SURPRISED    = 0x17,     //表情 惊讶
}NPC_S_FACE_CMP_ATTRIBUTE_EMOTION,*PNPC_S_FACE_CMP_ATTRIBUTE_EMOTION;

typedef enum _PNPC_S_FACE_CMP_ERROR
{
    /// 添加失败
    WB_FAILE = -1,
    /// 提取特征值失败
    WB_COLLECT_ERROR = -2,
    /// 图片名称或编号重复
    WB_FILEINDEX_ERROR = -3,
    /// 名单库已满，无法添加
    WB_LIB_FULL = -4,
    /// 添加超时
    WB_ADD_TIME_OUT = -5,
    /// 参数错误
    WB_PARA_ERROR = -6,
    /// 图片过大，添加失败（上限960*960）
    WB_FILE_BIG = -7,
    /// 设备存储空间不足
    WB_SPACE_ERROR = -8,
    /// 文件打开失败
    WB_FILE_OPEN_ERROR = -9,
    /// 未检测到人脸库
    WB_NO_DBFILE = -10,
    /// 图片读取失败
    WB_FILE_ERROR = -11,
    /// 数据库文件损坏
    WB_DBFILE_BAD = -12,
    /// 图片质量差，无法添加
    WB_PIC_QUALITY_ERROR = -13,
    /// 图片宽高不能为奇数
    WB_FILE_WHSIZE_ERROR = -14,
    /// 检测人脸失败（无人脸或多张人脸）
    WB_FILE_FACE_ERROR = -15,
    /// 图片格式错误（支持JPG）
    WB_PIC_FORMAT_ERROR = -16
}NPC_S_FACE_CMP_ERROR,*PNPC_S_FACE_CMP_ERROR;

@class HKSDeviceImageItem;

//功能ID定义
//比对数据
#define HKS_NPC_D_UMSP_CUSTOM_FUNCID_CMP_DATA       0x00010005
//上传实时抓拍图片
#define HKS_NPC_D_UMSP_CUSTOM_FUNCID_CAP_JPG        0x00010006
//比对数据
#define HKS_NPC_D_UMSP_CUSTOM_FUNCID_V1_CMP_DATA    0x10010005
//上传实时抓拍图片
#define HKS_NPC_D_UMSP_CUSTOM_FUNCID_V1_CAP_JPG     0x10010006

//图片类型
/// 名单类型：全部名单
#define HKS_NPC_D_FACE_MODE_TYPE_ALL        0
/// 名单类型：黑名单
#define HKS_NPC_D_FACE_MODE_TYPE_BLACK      1
/// 名单类型：白名单
#define HKS_NPC_D_FACE_MODE_TYPE_WHITE      2
/// 名单类型：VIP名单
#define HKS_NPC_D_FACE_MODE_TYPE_VIP        3
/// 名单类型：陌生人
#define HKS_NPC_D_FACE_MODE_TYPE_Visitor    0x100
/// 名单类型：其他名单
#define HKS_NPC_D_FACE_MODE_TYPE_OTHER      0xFF

#define kUMParamFaceChannel         @"iChannel"
#define kUMParamFaceStartTime       @"sStartTime"
#define kUMParamFaceEndTime         @"sEndTime"

/// 名单模式
#define kUMParamFaceMode            @"iMode"
/// 年龄
#define kUMParamFaceAge             @"iAge"
/// 表情
#define kUMParamFaceEmotion         @"iEmotion"
/// 温度
#define kUMParamFaceTemperature     @"iTemperature"
/// 是否带眼镜
#define kUMParamFaceGlasses         @"iGlasses"
/// 性别，1：男，2：女
#define kUMParamFaceGender          @"iGender"
/// 是否带面具\口罩
#define kUMParamFaceMask            @"iMask"
/// 客流统计
#define kUMParamFaceGuest           @"iGuest"
/// 相识度
#define kUMParamFaceSimilarity      @"iSimilarity"
/// 名称
#define kUMParamFaceName            @"sName"
/// 编号
#define kUMParamFaceNumber          @"sNumbber"
/// 名称_编号，已过期
#define kUMParamFaceNpicname        @"sNpicname"
/// 抓拍时间
#define kUMParamFaceSnapTime        @"iSnapTime"
/// 首次到店时间
#define kUMParamFaceFirstTime       @"iFirstTime"
/// 最近到店时间
#define kUMParamFaceUpdateTime      @"iUpdateTime"

/// 查询还是翻页,1:查询2:翻页
#define kUMParamFaceQueryType       @"iQueryOrPaged"
/// 页码,从第1页开始，0的话表示只返回数量，不返回信息
#define kUMParamFacePage            @"iPage"
/// 数据排练,1:正序 0:反序
#define kUMParamFaceOrder           @"iOrder"
/// 每页数量
#define kUMParamFacePageCount       @"iPageCount"
/// 系统ID
#define kUMParamFaceSyslistid       @"iSyslistid"
/// 用户ID
#define kUMParamFaceUserId          @"sUserId"
/// 人脸ID
#define kUMParamFaceFaceId          @"sFaceID"
/// 实时抓拍图片[UIImage]
#define kUMParamFaceImg             @"sImg"
/// 背景图
#define kUMParamFaceBackImg         @"sBackImg"
/// 底库图
#define kUMParamFaceLibImg          @"sLibImg"
/// 人行图
#define kUMParamFaceBodyImg         @"sBodyImg"
/// 控制类型,1
#define kUMParamFaceCtrlType        @"iCtrlType"

@interface HKSDeviceClient (JuLong)

/**
 黑白名单：查询图片索引列表
 
 @param aBWMode[int]                黑白名单类型：参考HKS_NPC_D_FACE_MODE_TYPE_*
 @param completionHandler[NSMutableArray->NSMutableDictionary]  返回图片索引列表数据
 @since  v2.4.11.15
 */
- (void)bwIndexList:(int)aMode
           handler:(void (^)(id data, int errorCode))completionHandler;


/**
 *  @brief      根据图片索引查询图片
 *
 *  @param[out] aData[NSMutableDictionary]  图片索引数据
 *
 *  @return [HKS_NPC_D_MPI_MON_ERROR]       接口执行状态
 *
 *  @since  v2.4.11.15
 */
- (void)faceImageAtIndex:(UMP2PFaceListIndexModel *)param
                 handler:(void (^)(id data, int errorCode))completionHandler;

- (void)faceImageAtIndex:(int)mode
                libIndex:(int)libIndex
               fileIndex:(int)fileIndex
                fileName:(NSString *)fileName
                 handler:(void (^)(id data, int errorCode))completionHandler;

- (void)faceImageAtIndex:(int)mode
                libIndex:(int)libIndex
                  userId:(NSString *)userId
               fileIndex:(int)fileIndex
                fileName:(NSString *)fileName
                 handler:(void (^)(id data, int errorCode))completionHandler;
/**
 添加人脸名单
 
 @param mode    名单模式
 @param name    人员姓名
 @param userId  人员编号
 @param image   人员图片
 
 @return [HKS_NPC_D_MPI_MON_ERROR]   接口执行状态，0：成功，<0：使用注释上面对应说明，>0:使用HKS_NPC_D_MPI_MON_ERROR对应说明
 @since  v2.4.11.15
 */
- (void)faceAddUserListAtImage:(int)mode
                          name:(NSString *)name
                        userId:(NSString *)userId
                           img:(UIImage *)image
                       handler:(void (^)(id data, int errorCode))completionHandler;

/**
 删除名单
 
 @param aBWMode             黑白名单类型：参考HKS_NPC_D_FACE_MODE_TYPE_*
 @param libIndex            库索引、系统ID
 @param fileIndex           文件索引
 @param fileName            文件名称
 @param completionHandler   回调
 @since  v2.4.11.15
 */
- (void)faceDeleteUserListAtIndex:(int)mode
                         libIndex:(int)libIndex
                           userId:(NSString *)userId
                        fileIndex:(int)fileIndex
                         fileName:(NSString *)fileName
                          handler:(void (^)(id data, int errorCode))completionHandler;

/**
 获取推送配置
 
 @param completionHandler 数据回调
 @since  v2.4.11.15
 */
- (void)bwPushInfo:(void (^)(id data, int errorCode))completionHandler;

/**
 设置推送配置
 
 @param aData[NSMutableDictionary]      推送配置数据
 {
     "PushEnable":   0,//推送总开关
     "BPushEnable":  0,//黑名单消息推送
     "WPushEnable":  0,//白名单消息推送
     "NWPushEnable": 0//非白名单消息推送
 }
 @since  v2.4.11.15
 */
- (void)setBWPushInfo:(id)aData
             handler:(void (^)(id data, int errorCode))completionHandler;

/*
 {
     "FaceSize":80,
     "SnapMode":2,
     "TrackFrameNum":3,
     "SnapNum":1,
     "IntervalTime": 1,
     "IntervalFrame":2,
     "IntervalSnapNum":3,
     "GateIntervalFrame":10,
     "Similarity":80,
     "CompareMode":1,
     "CompareCount":3
 }
 FaceSize：人脸最小识别像素（30-300）
 SnapMode：抓拍模式（0-5） 0=离开后抓拍（距离优先），1=快速抓拍，2=间隔抓拍（以秒为单位），3=间隔抓拍（以帧为单位），4=单人模式,5=离开后抓拍（质量优先）
 SnapNum：最大抓拍次数（1-3），对应 离开后抓拍（距离优先）和 离开后抓拍（质量优先）
 TrackFrameNum：快速抓拍帧数（10-1500），对应快速抓拍
 IntervalTime：间隔时间（1-30s），对应间隔抓拍（以秒为单位）
 IntervalFrame：间隔帧数（10-1500），对应间隔抓拍（以帧为单位）
 IntervalSnapNum：抓拍次数(0-20),0=持续抓拍，1-20是对应抓拍次数，对应 应间隔抓拍（以帧为单位）和 间隔抓拍（以秒为单位）
 GateIntervalFrame：间隔帧数（10-1500），对应单人模式
 Similarity：比对相似度（0-100）
 CompareMode：识别模式：0=次数识别，1=一直识别
 CompareCount：识别次数（1-10），对应次数识别模式
 */
/**
 获取人脸参数配置
 
 @param completionHandler 数据回调
 @since v2.4.11.15
 */
- (void)faceParamInfo:(void (^)(id data, int errorCode))completionHandler;

/**
 设置人脸参数配置
 
 @param  param[NSMutableDictionary]  人脸配置数据
 @param completionHandler 数据回调
 @since v2.4.11.15
 */
- (void)faceSetParamInfo:(id)param
                 handler:(void (^)(id data, int errorCode))completionHandler;

///考勤：考勤时间查询
- (void)faceCheckinTime:(UMDevClientTask)task param:(id)aParam;
///考勤：考勤时间设置
- (void)faceCheckinSetTime:(UMDevClientTask)task param:(id)aParam;
///考勤：考勤记录查询
- (void)faceAttendanceLog:(NSString *)name
                   number:(NSString *)number
                startTime:(NSString *)startTime
                  endTime:(NSString *)endTime
             queryOrPaged:(int)queryOrPaged
                pageIndex:(int)pageIndex
                pageCount:(int)pageCount
  querySomedayOrStatistic:(int)querySomedayOrStatistic
                  handler:(void (^)(id data, int errorCode))completionHandler;

/// 对比历史记录查询
- (void)faceRecord:(NSString *)name
            number:(NSString *)number
         startTime:(NSString *)startTime
           endTime:(NSString *)endTime
              mode:(int)mode
      queryOrPaged:(int)queryOrPaged
         pageIndex:(int)pageIndex
         pageCount:(int)pageCount
             order:(int)order
           handler:(void (^)(id data, int errorCode))completionHandler;

- (void)faceRecord:(NSString *)name
            number:(NSString *)number
         startTime:(NSString *)startTime
           endTime:(NSString *)endTime
              mode:(int)mode
      queryOrPaged:(int)queryOrPaged
         pageIndex:(int)pageIndex
         pageCount:(int)pageCount
           handler:(void (^)(id data, int errorCode))completionHandler;


// 上传实时抓拍图片char转dic
- (NSMutableDictionary *)faceCapInfo:(char *)bodyBuf bodyLen:(int)bodyLen;
- (NSMutableDictionary *)faceCmpInfo:(char *)bodyBuf bodyLen:(int)bodyLen;
- (NSMutableDictionary *)faceCmpInfoV1:(char *)bodyBuf bodyLen:(int)bodyLen;
@end
