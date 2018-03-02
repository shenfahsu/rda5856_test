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
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file                                                                     //
/// That file Implements the functions to register the module.
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "cs_types.h"
#include "chip_id.h"

#include "hal_map.h"
#include "halp_sys.h"
#include "halp_lps.h"
#include "halp_speech.h"
#include "halp_gdb_stub.h"

#include "hal_map_engine.h"



// =============================================================================
//  MACROS
// =============================================================================

// HAL_VERSION_NUMBER is defined in hal_map.xmd/h
#define HAL_VERSION_STRING "HAL for " STRINGIFY_VALUE(HAL_ASIC_CAPD) \
                           " in " STRINGIFY_VALUE(HAL_RELEASE_MODE)
#include "halp_version.h"



// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================

extern UINT32 g_halLpsForceNoSleep;
extern HAL_GDB_SWITCH_CTX_T g_halGdbSwitchCtx;
#ifdef HAL_GDB_CONFIG
extern UINT32 g_halGdbEnabled;
#endif
extern UINT32 g_halEventMask;
extern HAL_ISPI_DEBUG_T g_halIspiDebug;

// =============================================================================
// g_halMapVersion
// -----------------------------------------------------------------------------
/// Contains the version of the module.
/// The macro used is generated by the make process.
// =============================================================================
PROTECTED HAL_MAP_VERSION_T g_halMapVersion = HAL_VERSION_STRUCT;



// =============================================================================
// g_halMapAccess
// -----------------------------------------------------------------------------
/// Contains the addresses of the structures of the module that will be
/// accessible from a remote PC (e.g. through CoolWatcher).
// =============================================================================
PROTECTED HAL_MAP_ACCESS_T g_halMapAccess =
{
    .sys = 
    {
        .halSysSystemFreq = (UINT32*)(UINT32)&g_halSysSystemFreq,
        .halSysLpsLock = &g_halSysLpsLock,
        .halSysFreqScalRegistry = (HAL_SYS_FREQ_REGISTRY_T*)g_halSysFreqScalRegistry
    },
    .lpsCtx = (HAL_LPS_CONTEXT_2_T*)&g_halLpsCtx,
    .lpsForceNoSleepPtr = &g_halLpsForceNoSleep,
    .halSpeechFifo = NULL,//&g_halSpeechFifo,
    .profileControl = {
        .config = 0,
    },
    .keypadPulseHandler = NULL,
#ifdef CHIP_CPU_IS_MIPS
    .gdbSwitchCtxPtr = &g_halGdbSwitchCtx,
#endif
#ifdef HAL_GDB_CONFIG
    .gdbEnabledPtr = &g_halGdbEnabled,
#else
    .gdbEnabledPtr = NULL,
#endif
    .eventMask = &g_halEventMask,
    .ispiDebug = &g_halIspiDebug,
};



// =============================================================================
//  FUNCTIONS
// =============================================================================


// =============================================================================
// hal_RegisterYourself
// -----------------------------------------------------------------------------
/// This function registers the module itself to HAL so that the version and
/// the map accessor are filled. Then, the CSW get version function and the
/// CoolWatcher get version command will work.
// =============================================================================
PUBLIC VOID hal_RegisterYourself(VOID)
{
    hal_MapEngineRegisterModule(HAL_MAP_ID_HAL, &g_halMapVersion, &g_halMapAccess);
}
