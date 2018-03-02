/* 
 * Copyright (c) 2006-2016 RDA Microelectronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef _DEBUG_HOST_ASM_H_
#define _DEBUG_HOST_ASM_H_

//THIS FILE HAS BEEN GENERATED WITH COOLWATCHER. PLEASE EDIT WITH CARE !

#ifndef CT_ASM
#error "You are trying to use in a normal C code the assembly H description of 'debug_host'."
#endif



//==============================================================================
// debug_host
//------------------------------------------------------------------------------
/// 
//==============================================================================
#define REG_DEBUG_HOST_BASE         0x01A3F000

#define REG_DEBUG_HOST_BASE_HI      BASE_HI(REG_DEBUG_HOST_BASE)
#define REG_DEBUG_HOST_BASE_LO      BASE_LO(REG_DEBUG_HOST_BASE)

#define REG_DEBUG_HOST_CMD          REG_DEBUG_HOST_BASE_LO + 0x00000000
#define REG_DEBUG_HOST_DATA         REG_DEBUG_HOST_BASE_LO + 0x00000004
#define REG_DEBUG_HOST_EVENT        REG_DEBUG_HOST_BASE_LO + 0x00000008
#define REG_DEBUG_HOST_MODE         REG_DEBUG_HOST_BASE_LO + 0x0000000C
#define REG_DEBUG_HOST_H2P_STATUS   REG_DEBUG_HOST_BASE_LO + 0x00000010
#define REG_DEBUG_HOST_P2H_STATUS   REG_DEBUG_HOST_BASE_LO + 0x00000014
#define REG_DEBUG_HOST_IRQ          REG_DEBUG_HOST_BASE_LO + 0x00000018

//cmd
#define DEBUG_HOST_ADDR(n)          (((n)&0x1FFFFFFF)<<0)
#define DEBUG_HOST_SIZE(n)          (((n)&3)<<29)
#define DEBUG_HOST_WRITE_H          (1<<31)

//data
#define DEBUG_HOST_DATA(n)          (((n)&0xFFFFFFFF)<<0)

//event
#define DEBUG_HOST_EVENT0_SEMA      (1<<0)
#define DEBUG_HOST_EVENT31_1(n)     (((n)&0x7FFFFFFF)<<1)

//mode
#define DEBUG_HOST_FORCE_ON         (1<<0)
#define DEBUG_HOST_CLK_HOST_ON      (1<<1)

//h2p_status
#define DEBUG_HOST_H2P_STATUS(n)    (((n)&0xFF)<<0)
#define DEBUG_HOST_H2P_STATUS_MASK  (0xFF<<0)
#define DEBUG_HOST_H2P_STATUS_SHIFT (0)
#define DEBUG_HOST_H2P_STATUS_RST   (1<<16)

//p2h_status
#define DEBUG_HOST_P2H_STATUS(n)    (((n)&0xFF)<<0)

//irq
#define DEBUG_HOST_XCPU_IRQ         (1<<0)
#define DEBUG_HOST_BCPU_IRQ         (1<<1)




#endif
