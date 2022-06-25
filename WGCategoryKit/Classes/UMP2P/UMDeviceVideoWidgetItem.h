//
//  UMDeviceVideoWidgetItem.h
//  UMCloud
//
//  Created by UMEYE on 16/5/27.
//
//


@interface UMDeviceVideoWidgetTitleItem : NSObject

//名称
@property(nonatomic, copy) NSString *sName;
//序列号
@property(nonatomic, copy) NSString *sSerialNo;
@end

@interface UMDeviceVideoWidgetAttributeItem : NSObject
//背景颜色
@property(nonatomic, copy) NSString *sBackColor;
//是否显示
@property(nonatomic, assign) BOOL bIfEncodeBlend;
@property(nonatomic, copy) NSString *sFrontColor;
@property(nonatomic, assign) BOOL bIfPreviewBlend;
@property(nonatomic, strong) NSMutableArray *tRelativePos;
@end

@interface UMDeviceVideoWidget : NSObject

//通道标题
@property(nonatomic, strong) UMDeviceVideoWidgetTitleItem * tChannelTitle;
//通道标题属性
@property(nonatomic, strong) UMDeviceVideoWidgetAttributeItem *tChannelTitleAttribute;
@property(nonatomic, strong) NSMutableArray *tCovers;
@property(nonatomic, assign) int iCoverNum;
//通道时间属性
@property(nonatomic, assign) UMDeviceVideoWidgetAttributeItem *tTimeTitleAttribute;
@end

@interface UMDeviceVideoWidgetItem : NSObject

//通道数
@property(nonatomic, assign) int iChNum;
//通道数据集合
@property(nonatomic, strong) NSMutableArray * tVideoWidget;
@end
