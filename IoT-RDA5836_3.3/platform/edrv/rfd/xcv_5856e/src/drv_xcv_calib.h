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
/*************************************************************************/
/*                                                                       */
/* FILE NAME                                                             */
/*      xcv_calib.h                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      This file contains the calibration default values and accessors. */
/*                                                                       */
/*************************************************************************/

#ifndef XCV_CALIB_H
#define XCV_CALIB_H

//#include "calib_m.h"
//#include "rf_names.h"
#include "gsm.h"



// Calibration parameter accessors
// ------------------------------------------------------------------------
#define XCV_PARAM(n)                (g_xcvCalibPtr->xcv->param[(n)])
#define HST_XCV_PARAM(n)            (g_xcvCalibPtr->hstXcv->param[(n)])
#define XCV_TIME(n)                 (g_xcvCalibPtr->xcv->times[(n)])

// Default Calibration Times
// ------------------------------------------------------------------------
#define DEFAULT_CALIB_PDN_TX_UP          -103  // pdn to strob 120us, pdn to gmskon 110us
#define DEFAULT_CALIB_PDN_TX_DN           23

#ifdef XCV_DC_CANCEL_OFF
#define DEFAULT_CALIB_PDN_RX_UP         -108
#else // !XCV_DC_CANCEL_OFF
// DC cancel requires XCV to be opened at least 156us before real signal arrives
#define DEFAULT_CALIB_PDN_RX_UP         -172 // -156
#endif // !XCV_DC_CANCEL_OFF


// Modify DEFAULT_CALIB_PDN_RX_DN to fix "2nd FrameStart without FrameEnd" issue.
// Sometimes RF_IF cannot receive enough symbols, which causes BB_IFC2 misses an
// IFC2 IRQ at BCPU side, and then COM_REGS misses an EQU IRQ at XCPU side.

// Note that it might lead to an error if the value exceeds 4 Qb (or 1 symbol).
// RF_IF and BB_IFC2 will be re-programmed in IFC2 IRQ handler (just at the time
// when the actually needed number of symbols are received). If some extra symbols
// at the end of this window are received after the reprogramming, they will be saved
// as the starting symbols of next window.
#define DEFAULT_CALIB_PDN_RX_DN            51   // 6
#define DEFAULT_CALIB_SPI_CMD           -190
#define DEFAULT_CALIB_GMSK_ON             -8   // -4
#define DEFAULT_CALIB_GMSK_OFF             6
#define DEFAULT_CALIB_STROBE_UP           10
#ifdef PA_VRAMP_220PF
#define DEFAULT_CALIB_STROBE_DN            8   //8
#else // !PA_VRAMP_220PF
#define DEFAULT_CALIB_STROBE_DN            8
#endif // !PA_VRAMP_220PF

#define DEFAULT_CALIB_TIMES             {DEFAULT_CALIB_PDN_TX_UP, \
                                         DEFAULT_CALIB_PDN_TX_DN, \
                                         DEFAULT_CALIB_PDN_RX_UP, \
                                         DEFAULT_CALIB_PDN_RX_DN, \
                                         DEFAULT_CALIB_SPI_CMD, \
                                         DEFAULT_CALIB_GMSK_ON, \
                                         DEFAULT_CALIB_GMSK_OFF, \
                                         DEFAULT_CALIB_STROBE_UP, \
                                         DEFAULT_CALIB_STROBE_DN}





// Calibration Times Accessor index      
#define PDN_TX_UP          0
#define PDN_TX_DN          1
#define PDN_RX_UP          2
#define PDN_RX_DN          3
#define SPI_CMD            4
#define TX_GMSK_ON         5
#define TX_GMSK_OFF        6
#define TX_STROBE_ON       7
#define TX_STROBE_OFF      8

// Default Calibration Parameters
// ------------------------------------------------------------------------
#define RFD_DEFAULT_CALIB_ILOSS_ARFCN_850    {128, 158, 188, 218, 251,  0}
#define RFD_DEFAULT_CALIB_ILOSS_ARFCN_GSM    {35,  65,  116,  999, 1010, 0}
#define RFD_DEFAULT_CALIB_ILOSS_ARFCN_DCS    {545, 575, 627, 677, 702, 722, 800, 860, 0}
#define RFD_DEFAULT_CALIB_ILOSS_ARFCN_PCS    {512, 558, 604, 650, 696, 743, 788, 810, 0}

// Default calibration parameters.
#define DEFAULT_CALIB_CDAC        0xa
#define DEFAULT_CALIB_ILOSS       0x33333, 0x33333, 0x44444444, 0x55555555 /* GSM850 GSM900 DCS PCS */
#define DEFAULT_CALIB_AFC_GAIN    3500, 4000, 8000, 8500 /* 850 GSM DCS PCS */
#define DEFAULT_CALIB_AFC_GAIN2   3500, 4000, 8000, 8500 /* 850 GSM DCS PCS */
#define DEFAULT_CALIB_AFC_FREQ    0, 0, 0, 0 /* 850 GSM DCS PCS */
#define DEFAULT_CALIB_CDAC_FREQ   0x0

#define DEFAULT_CALIB_PARAM    {DEFAULT_CALIB_CDAC, \
                                DEFAULT_CALIB_ILOSS, \
                                DEFAULT_CALIB_AFC_GAIN, \
                                DEFAULT_CALIB_AFC_GAIN2, \
                                DEFAULT_CALIB_AFC_FREQ, \
                                DEFAULT_CALIB_CDAC_FREQ}

// Calibration Parameters Accessor index
#define XTAL              (0)
#define ILOSS(band)       (1 + (band))
#define AFC_GAIN(band)    (1 + (band) + 1*GSM_BAND_QTY)
#define AFC_GAIN2(band)   (1 + (band) + 2*GSM_BAND_QTY)
#define AFC_FREQ(band)    (1 + (band) + 3*GSM_BAND_QTY)
#define CDAC_FREQ         (1 + 4*GSM_BAND_QTY)

// Default calibration PAL custom parameters.
// ------------------------------------------------------------------------
#define DEFAULT_CALIB_RX_TX_FREQ_OFFSET     {0, 0, 0, 0}   /* 850 GSM DCS PCS */
#define DEFAULT_CALIB_RX_TX_TIME_OFFSET        (-24)   // -64
#define DEFAULT_CALIB_RX_IQ_TIME_OFFSET        (0)
#define DEFAULT_CALIB_TX_IQ_TIME_OFFSET        (-12)
#define DEFAULT_CALIB_DCO_CAL_TIME          (-100)

#define DEFAULT_CALIB_XCV_SPARE             {0, 0, 0, 0, 0, 0, 0}

#define DEFAULT_CALIB_PALCUST              {DEFAULT_CALIB_XCV_8809P,     \
                                            DEFAULT_CALIB_RX_TX_FREQ_OFFSET,\
                                            DEFAULT_CALIB_RX_TX_TIME_OFFSET,\
                                            DEFAULT_CALIB_RX_IQ_TIME_OFFSET,\
                                            DEFAULT_CALIB_TX_IQ_TIME_OFFSET,\
                                            DEFAULT_CALIB_DCO_CAL_TIME,\
                                            DEFAULT_CALIB_XCV_SPARE}



#endif // XCV_CALIB_H

