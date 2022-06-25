
#import "HKSDeviceClient.h"

typedef void (^UMDevDownloadTask)(int iError, int len, int percent, id aParam);
/**
 *  @brief      摄像机文件搜索、下载相关接口。通过HKSDeviceClient调用(camear file function interface class)
 */
@interface HKSDeviceClient (SearchFile)

/**
 *  @brief      搜索远程回放文件
 *
 *  @param[in]  startTime[Date_Time] 开始时间
 *  @param[in]  endTime[Date_Time]endTime 结束时间
 *  @param[in]  fileType[int] 搜索文件类型,参考HKS_NPC_D_MON_REC_FILE_TYPE_*定义
 *  @param[in]  fileList[NSMutableArray->HKSRecFile] 文件列表
 *  @return     [int]返回执行状态，请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since      v1.0.0.0
 */
- (int)searchRecFile:(Date_Time)startTime
				 end:(Date_Time)endTime
			fileType:(int)fileType
         outFileList:(NSMutableArray *)fileList;

- (int)searchRecFile:(Date_Time)startTime
                 end:(Date_Time)endTime
            fileType:(int)fileType
         outFileList:(NSMutableArray *)fileList
          stopDevice:(BOOL)isStop;


/**
 *  @brief      搜索远程回放文件，新增加功能，使用该接口之前先确保设备端是否支持
 *
 *  @param[in]  iChNo[int] 通道号，-1：表示所有通道
 *  @param[in]  iStream[int] 码流,0：主，1：子，-1：所有码流
 *  @param[in]  iCreateMode[int] HKS_NPC_D_MON_FILE_CREATE_MODE
 *  @param[in]  startTime[Date_Time] 开始时间
 *  @param[in]  tEvents[NSMutableArray->nsnumber HKS_NPC_D_MON_ALARM_TYPE_] 报警事件表（最大16个事件），参见HKS_NPC_D_MON_ALARM_TYPE_*定义，只有创建方式为HKS_NPC_D_MON_FILE_CREATE_MODE_ALARM时有效
 *  @param[in]  endTime[Date_Time]endTime 结束时间
 *  @param[in]  iFileType[HKS_NPC_D_MON_FILE_TYPE] 搜索文件类型,参考HKS_NPC_D_MON_FILE_TYPE_*定义
 *  @param[in]  tFiles[NSMutableArray->HKSRecFile] 文件列表
 *  @return     [int]返回执行状态，请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 *  @since      v2.4.8.19
 */
- (int)searchRecFile:(int)iChNo
              stream:(int)iStream
          createMode:(HKS_NPC_D_MON_FILE_CREATE_MODE)iCreateMode
              events:(NSMutableArray *)tEvents
           startTime:(Date_Time)startTime
                 end:(Date_Time)endTime
            fileType:(HKS_NPC_D_MON_FILE_TYPE)iFileType
         outFileList:(NSMutableArray *)tFiles;

- (int)searchRecFile:(int)iChNo
              stream:(int)iStream
          createMode:(HKS_NPC_D_MON_FILE_CREATE_MODE)iCreateMode
              events:(NSMutableArray *)tEvents
           startTime:(Date_Time)startTime
                 end:(Date_Time)endTime
            fileType:(HKS_NPC_D_MON_FILE_TYPE)iFileType
         outFileList:(NSMutableArray *)tFiles
          stopDevice:(BOOL)isStop;

- (void)searchRecFileRangeDay:(int)iStream
                    startTime:(Date_Time)startTime
                      endTime:(Date_Time)endTime
                      handler:(void (^)(id data, int errorCode))completionHandler;

/**
 *  @brief      开始文件下载，下载具体进度可以使用delegate回调playerFeedback:status:downSize:percent:接口查看
 *
 *  @param[in]  theRecFile[HKSRecFile] 下载的文件对象，通过searchRecFile可以获得
 *  @param[in]  in_iFileType[HKS_NPC_D_MON_REC_FILE_TYPE] 下载的类型HKS_NPC_D_MON_REC_FILE_TYPE_*
 *  @param[in]  in_sSaveFilePath[NSString] 下载以后保存的路径
 *  @since      v1.0.0.0
 */
- (void)startDownFileAtRecFile:(HKSRecFile *)theRecFile
                      fileType:(HKS_NPC_D_MON_REC_FILE_TYPE)in_iFileType
                          path:(NSString *)in_sSaveFilePath;

- (void)startDownFileAtRecFile:(HKSRecFile *)theRecFile
                      fileType:(HKS_NPC_D_MON_REC_FILE_TYPE)in_iFileType
                          path:(NSString *)in_sSaveFilePath
                          task:(UMDevDownloadTask)task;


/**
 *  @brief  停止文件下载
 *
 *  @since  v1.0.0.0
 */
- (void)stopDownFile;


/**
 *  @brief  获取图片下载数据,回调playerFeedback:status:downSize:percent:接口的percent值等于100的时候可以调用该接口。
 *
 *  @return [UIimage]图片数据
 *  @since  v1.0.0.0
 */
- (UIImage *)getDownloadImage;

- (int)searchRecFileRange:(int)iChNo
                   stream:(int)iStream
               createMode:(HKS_NPC_D_MON_FILE_CREATE_MODE)iCreateMode
                   events:(NSMutableArray *)tEvents
                startTime:(Date_Time)startTime
                      end:(Date_Time)endTime
              outFileList:(NSMutableArray *)tFiles
               stopDevice:(BOOL)isStop;

- (void)searchRecFileRange:(int)iStream
                createMode:(HKS_NPC_D_MON_FILE_CREATE_MODE)iCreateMode
                    events:(NSMutableArray *)tEvents
                 startTime:(Date_Time)startTime
                   endTime:(Date_Time)endTime
                   handler:(void (^)(id data, int errorCode))completionHandler;
@end
