///#begin en
//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//
///#end


@interface HKSDeviceConnItem : NSObject<NSCoding>

/** @brief  umid，只有在iConnMode为云穿透模式时候才有值 */
@property(nonatomic, copy) NSString *sDeviceId;
/** @brief  设备厂家id,具体请参考HKS_NPC_D_MON_VENDOR_ID_* */
@property(nonatomic, assign) int    iVendorId;
/** @brief  设备IP地址，只有在iConnMode为直连模式时候才有值 */
@property(nonatomic, copy) NSString *sAddress;
/** @brief  设备端口，只有在iConnMode为直连模式时候才有值 */
@property(nonatomic, assign) int    iPort;
/** @brief  设备用户名 */
@property(nonatomic, copy) NSString *sUserId;
/** @brief  设备密码 */
@property(nonatomic, copy) NSString *sUserPwd;
/** @brief  设备通道 */
@property(nonatomic, assign) int    iChannel;
/** @brief  设备码流 */
@property(nonatomic, assign) int    iStream;
/** @brief  设备mac地址 */
@property(nonatomic, copy) NSString *sAdapterMac;
/** @brief  码流是否改变 */
@property(nonatomic, assign) BOOL   bIfStream;

@end
