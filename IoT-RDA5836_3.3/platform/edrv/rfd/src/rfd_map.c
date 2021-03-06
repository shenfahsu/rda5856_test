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

#include "hal_map_engine.h"

#include "rf_names.h"
#include "rfd_xcv.h"
#include "rfd_pa.h"
#include "rfd_sw.h"
#include "rfd_map.h"



// =============================================================================
//  MACROS
// =============================================================================

#define RFD_VERSION_STRING "RFD for transceiver " STRINGIFY_VALUE(RFD_XCV_MODEL) \
    ", for PA " STRINGIFY_VALUE(RFD_PA_MODEL) \
    " and for switch " STRINGIFY_VALUE(RFD_SW_MODEL)
//#include "rfdp_version.h"



// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================


// =============================================================================
// g_rfdMapVersion
// -----------------------------------------------------------------------------
/// Contains the version of the module.
/// The macro used is generated by the make process.
// =============================================================================
//PROTECTED HAL_MAP_VERSION_T g_rfdMapVersion = RFD_VERSION_STRUCT;
PROTECTED HAL_MAP_VERSION_T g_rfdMapVersion = {0};


// =============================================================================
// g_rfdMapAccess
// -----------------------------------------------------------------------------
/// Contains the addresses of the structures of the module that will be
/// accessible from a remote PC (e.g. through CoolWatcher).
// =============================================================================
PROTECTED RFD_MAP_ACCESS_T g_rfdMapAccess =
{
    // Put your initialization here.
};



// =============================================================================
//  FUNCTIONS
// =============================================================================


// =============================================================================
// rfd_RegisterYourself
// -----------------------------------------------------------------------------
/// This function registers the module itself to HAL so that the version and
/// the map accessor are filled. Then, the CSW get version function and the
/// CoolWatcher get version command will work.
// =============================================================================
PUBLIC VOID rfd_RegisterYourself(VOID)
{
#ifdef SERVICE_CALIB_SUPPORT
    // Put transceiver name (ID) in the field "number" of the version.
    g_rfdMapVersion.number = rfd_XcvCalibGetDefault()->palcust.name;
#endif

    hal_MapEngineRegisterModule(HAL_MAP_ID_RFD, &g_rfdMapVersion, &g_rfdMapAccess);
}

