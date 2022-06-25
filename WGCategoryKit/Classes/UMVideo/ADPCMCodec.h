//  ADPCMCodec.h
//  UMVideo
//
//  Created by Fred on 2020/2/17.
//  Copyright © 2020年 UMEye.com. All rights reserved.
//

#ifndef _ADPCMCODEC_H
#define _ADPCMCODEC_H

typedef unsigned long  DWORD;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
struct adpcm_state 
{
    short	valprev;	/* Previous output value */
    char	index;		/* Index into stepsize table */
};


//#ifndef __STDC__
//#define signed
//#endif

/* Intel ADPCM step variation table */
static int indexTableADPCM[16] =
{
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8,
};

static unsigned int stepsizeTableADPCM[89] = 
{
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

int GZCZDecoderFrame(unsigned char *soundInput, short *soundOutput, DWORD dwSamples,struct adpcm_state *decoder_state );
int EncoderFrame(short* soundInput, unsigned char *soundOutput, DWORD  dwSamples,struct adpcm_state *encoder_state);
	
#endif // ifndefin  _ADPCMCODEC_H
