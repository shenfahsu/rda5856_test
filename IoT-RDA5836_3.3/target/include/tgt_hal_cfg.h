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
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file tgt_hal_cfg.h                                                       //
/// That file provides the TGT API related to HAL configuration.              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef _TGT_HAL_CFG_H
#define _TGT_HAL_CFG_H

#include "cs_types.h"
#include "hal_config.h"


// =============================================================================
// tgt_GetHalConfig
// -----------------------------------------------------------------------------
/// This function is used by HAL to get access to its configuration structure.
/// This is the only way HAL can get this information.
// =============================================================================
PUBLIC CONST HAL_CFG_CONFIG_T* tgt_GetHalConfig(VOID);


#endif // _TGT_HAL_CFG_H

