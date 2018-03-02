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

/*
================================================================================
  File         sxr_tls.h
--------------------------------------------------------------------------------

  Scope      : Tools header file for system executif.

  History    :
--------------------------------------------------------------------------------
 May 06 2005 |  FCH  | Add table for FCS computation
 Aug 13 2003 |  ADA  | Creation
================================================================================
*/

#ifndef __SXR_TLS_H__
#define __SXR_TLS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sxs_type.h"

#define SXR_RND_NB_MAX_USR 4

#define SXR_RND_USR0 0
#define SXR_RND_USR1 1
#define SXR_RND_USR2 2
#define SXR_RND_USR3 3

#define sxr_Random(a) _sxr_Random(a, SXR_RND_USR3)

u16  _sxr_Random (u16 Max, u8 Usr);
void sxr_RandomInit (u8 *RandomTab);
void sxr_Sleep (u32 Period);
void sxr_ComputeFcs (u16 Len, u8 *Frm, u8 *Fcs);

#ifdef __SXR_TLS_VAR__
const u8 sxr_MsbToLsb [256] =
{
 0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0,
 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
 0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8,
 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
 0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4,
 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
 0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec,
 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
 0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2,
 0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
 0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea,
 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
 0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6,
 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
 0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,
 0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
 0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1,
 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
 0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9,
 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
 0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5,
 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
 0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed,
 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
 0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3,
 0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
 0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
 0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
 0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7,
 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
 0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef,
 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff
};
#else
extern const u8 sxr_MsbToLsb [256];
#endif



//=============================================================================
// Table to speed up the FCS calculation
// Gives the the FCS result for any byte
//=============================================================================
#ifdef __SXR_TLS_VAR__
const u32 sxr_FcsTab[ 256 ] =
{
   0x00000000,0x01BBA1B5,0x03CCE2DF,0x0277436A,0x0722640B,0x0699C5BE,0x04EE86D4,0x05552761,
   0x0E44C816,0x0FFF69A3,0x0D882AC9,0x0C338B7C,0x0966AC1D,0x08DD0DA8,0x0AAA4EC2,0x0B11EF77,
   0x1C89902C,0x1D323199,0x1F4572F3,0x1EFED346,0x1BABF427,0x1A105592,0x186716F8,0x19DCB74D,
   0x12CD583A,0x1376F98F,0x1101BAE5,0x10BA1B50,0x15EF3C31,0x14549D84,0x1623DEEE,0x17987F5B,
   0x39A881ED,0x38132058,0x3A646332,0x3BDFC287,0x3E8AE5E6,0x3F314453,0x3D460739,0x3CFDA68C,
   0x37EC49FB,0x3657E84E,0x3420AB24,0x359B0A91,0x30CE2DF0,0x31758C45,0x3302CF2F,0x32B96E9A,
   0x252111C1,0x249AB074,0x26EDF31E,0x275652AB,0x220375CA,0x23B8D47F,0x21CF9715,0x207436A0,
   0x2B65D9D7,0x2ADE7862,0x28A93B08,0x29129ABD,0x2C47BDDC,0x2DFC1C69,0x2F8B5F03,0x2E30FEB6,
   0x73EAA26F,0x725103DA,0x702640B0,0x719DE105,0x74C8C664,0x757367D1,0x770424BB,0x76BF850E,
   0x7DAE6A79,0x7C15CBCC,0x7E6288A6,0x7FD92913,0x7A8C0E72,0x7B37AFC7,0x7940ECAD,0x78FB4D18,
   0x6F633243,0x6ED893F6,0x6CAFD09C,0x6D147129,0x68415648,0x69FAF7FD,0x6B8DB497,0x6A361522,
   0x6127FA55,0x609C5BE0,0x62EB188A,0x6350B93F,0x66059E5E,0x67BE3FEB,0x65C97C81,0x6472DD34,
   0x4A422382,0x4BF98237,0x498EC15D,0x483560E8,0x4D604789,0x4CDBE63C,0x4EACA556,0x4F1704E3,
   0x4406EB94,0x45BD4A21,0x47CA094B,0x4671A8FE,0x43248F9F,0x429F2E2A,0x40E86D40,0x4153CCF5,
   0x56CBB3AE,0x5770121B,0x55075171,0x54BCF0C4,0x51E9D7A5,0x50527610,0x5225357A,0x539E94CF,
   0x588F7BB8,0x5934DA0D,0x5B439967,0x5AF838D2,0x5FAD1FB3,0x5E16BE06,0x5C61FD6C,0x5DDA5CD9,
   0xE76EE56B,0xE6D544DE,0xE4A207B4,0xE519A601,0xE04C8160,0xE1F720D5,0xE38063BF,0xE23BC20A,
   0xE92A2D7D,0xE8918CC8,0xEAE6CFA2,0xEB5D6E17,0xEE084976,0xEFB3E8C3,0xEDC4ABA9,0xEC7F0A1C,
   0xFBE77547,0xFA5CD4F2,0xF82B9798,0xF990362D,0xFCC5114C,0xFD7EB0F9,0xFF09F393,0xFEB25226,
   0xF5A3BD51,0xF4181CE4,0xF66F5F8E,0xF7D4FE3B,0xF281D95A,0xF33A78EF,0xF14D3B85,0xF0F69A30,
   0xDEC66486,0xDF7DC533,0xDD0A8659,0xDCB127EC,0xD9E4008D,0xD85FA138,0xDA28E252,0xDB9343E7,
   0xD082AC90,0xD1390D25,0xD34E4E4F,0xD2F5EFFA,0xD7A0C89B,0xD61B692E,0xD46C2A44,0xD5D78BF1,
   0xC24FF4AA,0xC3F4551F,0xC1831675,0xC038B7C0,0xC56D90A1,0xC4D63114,0xC6A1727E,0xC71AD3CB,
   0xCC0B3CBC,0xCDB09D09,0xCFC7DE63,0xCE7C7FD6,0xCB2958B7,0xCA92F902,0xC8E5BA68,0xC95E1BDD,
   0x94844704,0x953FE6B1,0x9748A5DB,0x96F3046E,0x93A6230F,0x921D82BA,0x906AC1D0,0x91D16065,
   0x9AC08F12,0x9B7B2EA7,0x990C6DCD,0x98B7CC78,0x9DE2EB19,0x9C594AAC,0x9E2E09C6,0x9F95A873,
   0x880DD728,0x89B6769D,0x8BC135F7,0x8A7A9442,0x8F2FB323,0x8E941296,0x8CE351FC,0x8D58F049,
   0x86491F3E,0x87F2BE8B,0x8585FDE1,0x843E5C54,0x816B7B35,0x80D0DA80,0x82A799EA,0x831C385F,
   0xAD2CC6E9,0xAC97675C,0xAEE02436,0xAF5B8583,0xAA0EA2E2,0xABB50357,0xA9C2403D,0xA879E188,
   0xA3680EFF,0xA2D3AF4A,0xA0A4EC20,0xA11F4D95,0xA44A6AF4,0xA5F1CB41,0xA786882B,0xA63D299E,
   0xB1A556C5,0xB01EF770,0xB269B41A,0xB3D215AF,0xB68732CE,0xB73C937B,0xB54BD011,0xB4F071A4,
   0xBFE19ED3,0xBE5A3F66,0xBC2D7C0C,0xBD96DDB9,0xB8C3FAD8,0xB9785B6D,0xBB0F1807,0xBAB4B9B2,
};
#else
extern const u32 sxr_FcsTab[ 256 ];
#endif



#ifdef __cplusplus
}
#endif

#endif
