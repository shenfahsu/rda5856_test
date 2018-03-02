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
/// @file                                                                     //
/// That file Implements the functions to register the module.
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "cs_types.h"
#include "chip_id.h"

#include "hal_mem_map.h"
#include "hal_map_engine.h"

#include "sx_map.h"



// =============================================================================
//  MACROS
// =============================================================================

#define SX_VERSION_STRING "Hello, I'm SX!"
#include "sxp_version.h"



// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================

// To avoid linkage issue while compiling platform_test programs,
// we put the definition here instead of in sap_main.c
UINT32 HAL_UNCACHED_BSS g_sxsDebugIdleHookEnable = 0;
UINT32 HAL_UNCACHED_BSS  g_sxExternalTraceEnable= 0;
UINT16 HAL_UNCACHED_BSS g_sxTraceLelvel[32] = {0};

// =============================================================================
// g_sxMapVersion
// -----------------------------------------------------------------------------
/// Contains the version of the module.
/// The macro used is generated by the make process.
// =============================================================================
PROTECTED HAL_MAP_VERSION_T g_sxMapVersion = SX_VERSION_STRUCT;



// =============================================================================
// g_sxMapAccess
// -----------------------------------------------------------------------------
/// Contains the addresses of the structures of the module that will be
/// accessible from a remote PC (e.g. through CoolWatcher).
// =============================================================================
PROTECTED SX_MAP_ACCESS_T g_sxMapAccess =
{
    // Put your initialization here.
    .sxExternalTraceEnablePtr = (UINT32*)&g_sxExternalTraceEnable,
    .sxsDebugIdleHookEnablePtr = (UINT32*)&g_sxsDebugIdleHookEnable,
    .sxTraceLevelPtr = g_sxTraceLelvel,
};



// =============================================================================
//  FUNCTIONS
// =============================================================================


// =============================================================================
// sx_RegisterYourself
// -----------------------------------------------------------------------------
/// This function registers the module itself to HAL so that the version and
/// the map accessor are filled. Then, the CSW get version function and the
/// CoolWatcher get version command will work.
// =============================================================================
PUBLIC VOID sx_RegisterYourself(VOID)
{
    hal_MapEngineRegisterModule(HAL_MAP_ID_SX, &g_sxMapVersion, &g_sxMapAccess);
}

