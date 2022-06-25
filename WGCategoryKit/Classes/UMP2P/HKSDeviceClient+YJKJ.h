//
//  HKSDeviceClient+YJKJ.h
//  UMCloud
//
//  Created by UMEYE on 16/6/12.
//  易佳科技
//

#import "HKSDeviceClient.h"

//智能家居控制相关指定定义
#define HKS_NPC_D_MON_CMD_LIGHTING          0x52    //灯控
#define HKS_NPC_D_MON_CMD_APPLIANCES        0x55    //电器
#define HKS_NPC_D_MON_CMD_LOCK              0x8E    //门锁
#define HKS_NPC_D_MON_CMD_SCENES            0x20    //场景
#define HKS_NPC_D_MON_CMD_ALARM_SET         0x7D    //布防
#define HKS_NPC_D_MON_CMD_ALARM_CANCEL      0x7C    //撤防
#define HKS_NPC_D_MON_CMD_ALARM_OFFSOUND    0xE8    //关警笛

@interface HKSDeviceClient (YJKJ)

/**
 *  智能家居控制
 *
 *  @param comm      控制指定:HKS_NPC_D_MON_CMD_*
 *  @param status    控制开关:YES、NO
 *  @param index     控制索引:1、2、3、4
 *  @param controlID 家居控制ID:一个4位数字的字符串
 *
 *  @return 返回状态,请参考HKS_NPC_D_MPI_MON_ERROR_*定义
 */
- (int)comSendData:(int)comm status:(BOOL)status index:(int)index controlID:(NSString *)controlID;

@end
