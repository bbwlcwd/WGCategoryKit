//
//  Copyright (c) 2018 UMCloud. All rights reserved.
//

#import "UMP2PDef.h"
#import "HKSDevicePlayStatus.h"
#import "HKSDeviceConnStatus.h"
#import <UMBasis/UMBasis.h>
#import <UMVideo/UMVideo.h>

#import "HKPlayerDelegate.h"

#import "HKSDeviceInfoItem.h"
#import "HKSDeviceTimeConfigItem.h"
#import "HKSDeviceSearchAdapterItem.h"
#import "HKSDeviceSearchItem.h"
#import "HKSDeviceWIFIItem.h"
#import "HKSWIFIAPItem.h"
#import "HKSDeviceVendor.h"
#import "HKSDeviceConfigItem.h"
#import "HKSDeviceAlarmMotionTimeSect.h"
#import "HKSDeviceStorageListConfigItem.h"
#import "HKSDeviceRecordConfigItem.h"
#import "HKSDeviceStorageItem.h"

#import "HKSDeviceCodecItem.h"
#import "HKSRecFile.h"
#import "HKSDeviceImageItem.h"
#import "HKSDeviceAlarmMailItem.h"

#import "UMDoorInfoItem.h"
#import "UMP2PFaceListIndexModel.h"

#import "UMDeviceVideoWidgetItem.h"
#import "HKSMP3Item.h"

#import "HKSDeviceClient.h"
#import "HKSDeviceClient+Config.h"
#import "HKSDeviceClient+ConfigPlayData.h"
#import "HKSDeviceClient+PTZ.h"
#import "HKSDeviceClient+MP4.h"
#import "HKSDeviceClient+ControlMedia.h"
#import "HKSDeviceClient+Talkback.h"
#import "HKSDeviceClient+Photos.h"
#import "HKSDeviceClient+SearchFile.h"
#import "HKSDeviceClient+GZLL.h"
#import "HKSDeviceClient+YJKJ.h"
#import "HKSDeviceClient+ZJA.h"
#import "HKSDeviceClient+ZAKJ.h"
#import "HKSDeviceClient+JuLong.h"
#import "HKSDeviceClient+CallCustom.h"
#import "HKSDeviceClient+DeviceConfig.h"
#import "HKSDeviceClient+SerialPorts.h"
#import "HKSDeviceClient+APSetting.h"
#import "HKSDeviceClient+LocalDevSearch.h"
#import "HKSDeviceClient+PreConnection.h"

//#import "HKSServerClient.h"
//#import "HKSServerClient+User.h"
//#import "HKSServerClient+Device.h"
//#import "HKSServerClient+LocalDeviceSearch.h"
//#import "HKSServerClient+CustomConfig.h"
//#import "HKSServerClient+Alarm.h"
//#import "HKSServerClient+ReqUpdate.h"
//#import "HKSServerClient+Demo.h"

#import "DeviceNetPortClient.h"

#import "UMUSTSDK.h"
