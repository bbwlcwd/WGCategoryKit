//
//  UMConfigDef.h
//  UMSDK
//
//  Created by fred on 2019/11/7.
//  Copyright © 2019 UMEYE.COM. All rights reserved.
//

#ifndef UMConfigDef_h
#define UMConfigDef_h

typedef NS_ENUM(NSUInteger, UMServerType) {
    /// UM P2P 体系的用户服务
    UMServerP2P = 0,
    /// UM SCS 体系的用户服务
    UMServerSCS,
    /// UM CSM 体系的用户服务
    UMServerCSM,
};

#pragma mark - lang
enum {
    /** @brief  en  */
    UM_WEB_API_WS_LANG_TYPE_EN = 1,
    /** @brief  中文简体  */
    UM_WEB_API_WS_LANG_TYPE_ZH = 2,
    /** @brief  中文繁体  */
    UM_WEB_API_WS_LANG_TYPE_ZH_HK = 3,
    /** @brief  德文(German)  */
    UM_WEB_API_WS_LANG_TYPE_GERMAN = 4,
    /** @brief  法文(French)  */
    UM_WEB_API_WS_LANG_TYPE_FRENCH = 5,
    /** @brief  葡萄牙文(Portuguese)  */
    UM_WEB_API_WS_LANG_TYPE_PORTUGUESE = 6,
    /** @brief  俄文(Russian)  */
    UM_WEB_API_WS_LANG_TYPE_RUSSIAN = 7,
    /** @brief  意大利(Italian)  */
    UM_WEB_API_WS_LANG_TYPE_ITALIAN = 8,
    /** @brief  土耳其(Turkish)  */
    UM_WEB_API_WS_LANG_TYPE_TURKISH = 9,
    /** @brief  波兰(Polish)  */
    UM_WEB_API_WS_LANG_TYPE_POLISH = 10,
    /** @brief  阿拉伯(Arabic)  */
    UM_WEB_API_WS_LANG_TYPE_ARABIC = 11,
    /** @brief  Fr  */
    UM_WEB_API_WS_LANG_TYPE_Fr = 12,
    /** @brief  捷克语(Czech)  */
    UM_WEB_API_WS_LANG_TYPE_CZECH = 13,
    /** @brief  丹麦  */
    UM_WEB_API_WS_LANG_TYPE_Danish = 14,
    /** @brief  芬兰语  */
    UM_WEB_API_WS_LANG_TYPE_Finnish = 15,
    /** @brief  希腊语  */
    UM_WEB_API_WS_LANG_TYPE_Greek = 16,
    /** @brief  荷兰语  */
    UM_WEB_API_WS_LANG_TYPE_Nederlands = 17,
    /** @brief  挪威语  */
    UM_WEB_API_WS_LANG_TYPE_Norwegian = 18,
    /** @brief  西班牙  */
    UM_WEB_API_WS_LANG_TYPE_Spanish = 19,
    /** @brief  瑞典语  */
    UM_WEB_API_WS_LANG_TYPE_Swedish = 20,
    /** @brief  葡萄牙语-巴西  */
    UM_WEB_API_WS_LANG_TYPE_Brazil = 21,
    /** @brief  印度  */
    UM_WEB_API_WS_LANG_TYPE_Hindi = 22,
    /** @brief  日本  */
    UM_WEB_API_WS_LANG_TYPE_Japanese = 23,
    /** @brief  韩语  */
    UM_WEB_API_WS_LANG_TYPE_Korean = 24,
    /** @brief  泰语  */
    UM_WEB_API_WS_LANG_TYPE_Thai = 25,
    /** @brief  越南语  */
    UM_WEB_API_WS_LANG_TYPE_Vietnamese = 26,
    /** @brief  希伯来语  */
    UM_WEB_API_WS_LANG_TYPE_Hebrew = 27,
    /** @brief  罗马尼亚语  */
    UM_WEB_API_WS_LANG_TYPE_Romanian = 28,
    /** @brief  匈牙利语  */
    UM_WEB_API_WS_LANG_TYPE_Hungarian = 29,
    /** @brief  印度尼西亚语  */
    UM_WEB_API_WS_LANG_TYPE_Indonesian = 30,
    /** @brief  乌克兰语  */
    UM_WEB_API_WS_LANG_TYPE_Ukrainian = 31,
    /** @brief  马来语  */
    UM_WEB_API_WS_LANG_TYPE_Malay = 32,
    /** @brief  菲律宾语  */
    UM_WEB_API_WS_LANG_TYPE_Filipino = 33,
    /** @brief  立陶宛语  */
    UM_WEB_API_WS_LANG_TYPE_Lithuanian = 34,
    /** @brief  柬埔寨语  */
    UM_WEB_API_WS_LANG_TYPE_Cambodian = 35,
    /** @brief  孟加拉语  */
    UM_WEB_API_WS_LANG_TYPE_Bengali = 36,
    /** @brief  南非语  */
    UM_WEB_API_WS_LANG_TYPE_Afrikaans = 37,
    /** @brief  冰岛语  */
    UM_WEB_API_WS_LANG_TYPE_Icelandic = 38,
    /** @brief  白俄罗斯语  */
    UM_WEB_API_WS_LANG_TYPE_Belarusian = 39,
};
/** @brief  语言类型  */
typedef int UM_WEB_API_WS_LANG_TYPE;

#define UMCFG_DEPRECATED(_info) __attribute__((deprecated(_info)))

#endif /* UMConfigDef_h */
