//  g711_cq.h
//  UMVideo
//
//  Created by Fred on 2020/2/17.
//  Copyright © 2020年 UMEye.com. All rights reserved.
//

#ifndef G711_CQ_H
#define G711_CQ_H
//#ifdef __cplusplus
//
//	extern "C"
//
//	{
//
//#endif

unsigned char	linear2ulaw(signed short l);

unsigned char linear2alaw(signed short l);

signed short		ulaw2linear(unsigned char u);

signed short		alaw2linear(unsigned char a);

unsigned char	ulaw2alaw(unsigned char u);

unsigned char	alaw2ulaw(unsigned char a);
//#ifdef __cplusplus
//
//	}
//
//#endif
#endif

