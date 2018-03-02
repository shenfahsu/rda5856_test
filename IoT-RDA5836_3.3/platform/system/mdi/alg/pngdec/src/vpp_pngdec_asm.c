/* 
* Copyright (c) 2006-2016 RDA Microelectronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/*************************************************************************/
/*                                                                       */
/* FILE NAME                                                             */
/*      vpp_pngdec_asm.c                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*     This contains the VoC assembly code for the multimedia encoder    */
/*                                                                       */
/*************************************************************************/
///
///   @file vpp_PngDec_asm.c
///   This contains the VoC assembly code for Multimedia.
///

#include "cs_types.h"
#include "vppp_pngdec_asm_map.h"


#define RAM_X_BEGIN_ADDR               0x0000
#define RAM_Y_BEGIN_ADDR               0x4000

#define TO32(lo,hi)                    ((lo & 0xffff) | ((hi &0xffff) << 16))



// ******************************
//            COMMON
// ******************************

CONST INT32 g_vppPngDecCommonCode[] = {
#include "vpp_pngdec_asm_common.tab"
};

CONST INT32 g_vppPngDecCommonCodeSize = sizeof(g_vppPngDecCommonCode);


// ******************************
//            CONST
// ******************************

CONST INT32 g_vppPngDecConst[] =
{
#include "vpp_pngdec_const.tab"
};


// ******************************
//            CONST
// ******************************

CONST INT32 g_vppPngDecLenfixDistFix[] =
{
#include "vpp_pngdec_lenfix_distfix.tab"
};


