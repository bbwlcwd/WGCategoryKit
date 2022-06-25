
#import "HKSDeviceClient.h"


/**
 *  @brief  串口功能类
 */
@interface HKSDeviceClient (SerialPorts)


/**
 *  @brief  串口接口-打开串口
 *
 *  @param[in]  aCommType[int]  串口类型，0：RS232串口，1：RS485串口
 *  @param[in]  aPort[int]      串口端口
 *  @param[in]  aBaudRate[int]  波特率，如4800，14400，28800，36600
 *  @param[in]  aDataBit[int]   数据位，如8位
 *  @param[in]  aStopBit[int]   停止位，如1
 *  @param[in]  aCheckBit[int]  奇偶校验位，如1
 */
- (HKS_NPC_D_MPI_MON_ERROR)serialPortsComOpen:(int)aCommType prot:(int)aPort baudRate:(int)aBaudRate dataBit:(int)aDataBit stopBit:(int)aStopBit checkBit:(int)aCheckBit;


/**
 *  @brief  串口接口-发送串口数据
 *
 *  @param[in]  aCommType[int]              串口类型，0：RS232串口，1：RS485串口
 *  @param[in]  aPort[int]                  串口端口
 *  @param[in]  sendDataBuf[unsigned char]  发送的串口数据
 *  @param[in]  aSendDataLen[int]           发送的串口长度
 */
- (HKS_NPC_D_MPI_MON_ERROR)serialPortsComSend:(int)aCommType prot:(int)aPort sendDataBuf:(unsigned char *)aBuffer sendDataBufLen:(int)aSendDataLen;

/**
 *  @brief  串口接口-关闭串口
 *
 *  @param[in]  aCommType[int]  串口类型，0：RS232串口，1：RS485串口
 *  @param[in]  aPort[int]      串口端口
 */
- (HKS_NPC_D_MPI_MON_ERROR)serialPortsComClose:(int)aCommType prot:(int)aPort;

@end
