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
//
////////////////////////////////////////////////////////////////////////////////
//
/// @file hal_overlay.h
///
/// This file describes the overlaying mechanism used to share fast memory
/// between several codes requiring high performance memory access, but not
/// at the same time.
/// 
//
////////////////////////////////////////////////////////////////////////////////


#ifndef _HAL_OVERLAY_H_
#define _HAL_OVERLAY_H_


#include "cs_types.h"

//
// MMI TimerID
// 
#define COS_MMI_TIMER_ID_BASE  0x100
#define COS_MMI_TIMER_ID_END_  0x3FF


#endif  //_HAL_OVERLAY_H_



