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

#include "calibp_calibration.h"

#include "calib_m.h"
#include "calib_map.h"



// =============================================================================
//  MACROS
// =============================================================================

#define CALIB_VERSION_STRING "Calibration Daemon v" \
                             STRINGIFY_VALUE(CALIB_MAJ_VERSION) "." \
                             STRINGIFY_VALUE(CALIB_MIN_VERSION)
#include "calibp_version.h"



// =============================================================================
//  GLOBAL VARIABLES
// =============================================================================


// =============================================================================
// g_calibMapVersion
// -----------------------------------------------------------------------------
/// Contains the version of the module.
/// The macro used is generated by the make process.
// =============================================================================
PROTECTED HAL_MAP_VERSION_T g_calibMapVersion = CALIB_VERSION_STRUCT;



// =============================================================================
//  FUNCTIONS
// =============================================================================


// =============================================================================
// calib_RegisterYourself
// -----------------------------------------------------------------------------
/// This function registers the module itself to HAL so that the version and
/// the map accessor are filled. Then, the CSW get version function and the
/// CoolWatcher get version command will work.
// =============================================================================
PUBLIC VOID calib_RegisterYourself(VOID)
{
    //  Init the pointer used by HST to say talk with the Platform's calibration code.
    //  This will allow HST to read the calib buffer. 
    hal_MapEngineRegisterModule(HAL_MAP_ID_CALIB, &g_calibMapVersion, &g_calibCalibration);
}
