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
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
/// @file hal_gpio.h                                                          //
/// Describes the GPIO driver API                                             //
//                                                                            //
//////////////////////////////////////////////////////////////////////////////// 

#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include "cs_types.h"

#include "chip_id.h"


/// @defgroup gpio HAL GPIO Driver
/// This document describes the characteristics of the GPIO module 
/// and how to use it via its Hardware Abstraction Layer API.
///
/// @par GPIO Operation
/// GPIOs are used to control external chips, or to get external events. They 
/// can be used as inputs or outputs. As input 8 of them can trigger an 
/// interruption.
///
/// @par Interruption Handler
/// For each one of the 8 interrupt capable GPIO, the user handler is set
/// through a call to the #hal_GpioIrqSetHandler function. When an interrupt
/// occurs on a GPIO, whether on a falling or rising edge, the registered
/// user function is called. No information about the kind of edge is available,
/// so these functions don't have a status.
///
/// @par Interruption Mask
/// For each one of the 8 interrupt capable GPIO, the mask is set through 
/// #hal_GpioIrqSetMask, using the #HAL_GPIO_IRQ_MASK_T structure to set on 
/// which edge the GPIO are sensitive.
///
/// @par HAL GPIO Driver is designed for ease of use and configurability for
/// edrv and svc, not for high speed toggling. If for some specific situation
/// (mostly experimental projects) a Fast GPIO interface is needed, this 
/// could be added to HAL.
///
/// @{
///   


// =============================================================================
// TYPES
// =============================================================================

  

// =============================================================================
// HAL_GPIO_TYPE_T
// -----------------------------------------------------------------------------
/// Used to give a type to a general purpose pin that can be either a GPIO pin
/// or a GPO pin.
// =============================================================================
typedef enum
{
    /// invalid IO type
    HAL_GPIO_TYPE_INVALID = 0x1000,

    /// no IO type
    HAL_GPIO_TYPE_NONE,

    /// GPIO type
    HAL_GPIO_TYPE_IO,

    /// GPO type
    HAL_GPIO_TYPE_O,

    /// TCO type
    HAL_GPIO_TYPE_TCO,

    HAL_GPIO_TYPE_QTY
} HAL_GPIO_TYPE_T;



// =============================================================================
// HAL_GPIO_GPIO_ID_T
// -----------------------------------------------------------------------------
/// This type is used to name all the GPIO.
/// Functions of the GPIO driver are called with a parameter of 
/// this type to specify which GPIO is concerned by a the function call.
// =============================================================================
//#if (CHIP_ASIC_ID != CHIP_ASIC_ID_5855)&& (CHIP_ASIC_ID != CHIP_ASIC_ID_5856)
typedef enum
{
    /// To be used in configuration when the field for this GPIO is not used
    HAL_GPIO_NONE = HAL_GPIO_TYPE_NONE << 16,
    // Only the first eight ones can trig interrupts
    /// Can cause an interrupt
    HAL_GPIO_0 = HAL_GPIO_TYPE_IO << 16,
    /// Can cause an interrupt
    HAL_GPIO_1,
    /// Can cause an interrupt
    HAL_GPIO_2,
    /// Can cause an interrupt
    HAL_GPIO_3,
    /// Can cause an interrupt
    HAL_GPIO_4,
    /// Can cause an interrupt
    HAL_GPIO_5,
    /// Can cause an interrupt
    HAL_GPIO_6,
    /// Can cause an interrupt
    HAL_GPIO_7,
    // Those following are not interruptible
    HAL_GPIO_8,
    HAL_GPIO_9,
    HAL_GPIO_10,
    HAL_GPIO_11,
    HAL_GPIO_12,
    HAL_GPIO_13,
    HAL_GPIO_14,
    HAL_GPIO_15,
    HAL_GPIO_16,
    HAL_GPIO_17,
    HAL_GPIO_18,
    HAL_GPIO_19,
    HAL_GPIO_20,
    HAL_GPIO_21,
    HAL_GPIO_22,
    HAL_GPIO_23,
    HAL_GPIO_24,
    HAL_GPIO_25,
    HAL_GPIO_26,
    HAL_GPIO_27,
    HAL_GPIO_28,
    HAL_GPIO_29,
    HAL_GPIO_30,
    HAL_GPIO_31,

    HAL_GPIO_0_0 = HAL_GPIO_0,
    HAL_GPIO_0_1,
    HAL_GPIO_0_2,
    HAL_GPIO_0_3,
    HAL_GPIO_0_4,
    HAL_GPIO_0_5,
    HAL_GPIO_0_6,
    HAL_GPIO_0_7,
    HAL_GPIO_1_0,
    HAL_GPIO_1_1,
    HAL_GPIO_1_2,
    HAL_GPIO_1_3,
    HAL_GPIO_1_4,
    HAL_GPIO_1_5,
    HAL_GPIO_1_6,
    HAL_GPIO_1_7,
    HAL_GPIO_2_0,
    HAL_GPIO_2_1,
    HAL_GPIO_2_2,
    HAL_GPIO_2_3,
    HAL_GPIO_2_4,
    HAL_GPIO_2_5,
    HAL_GPIO_2_6,
    HAL_GPIO_2_7,
    HAL_GPIO_3_0,
    HAL_GPIO_3_1,
    HAL_GPIO_3_2,
    HAL_GPIO_3_3,
    HAL_GPIO_3_4,
    HAL_GPIO_3_5,
    HAL_GPIO_3_6,
    HAL_GPIO_3_7,
    HAL_GPIO_4_0,
    HAL_GPIO_4_1,
    HAL_GPIO_4_2,
    HAL_GPIO_4_3,
    HAL_GPIO_4_4,
    HAL_GPIO_4_5,
    HAL_GPIO_4_6,
    HAL_GPIO_4_7,   
    HAL_GPIO_QTY = 40
}HAL_GPIO_GPIO_ID_T;

//#endif


// =============================================================================
// HAL_GPIO_TO_IRQ_T
// -----------------------------------------------------------------------------
/// Any Programmable Output IDentifier
/// Used to identify corresponding int num.
// =============================================================================
//typedef struct
//{
//    HAL_GPIO_TYPE_IO id;
//    U8  int_num;
//} HAL_GPIO_TO_IRQ_T;


// =============================================================================
// HAL_GPIO_ALTFUNC_CFG_ID_T
// -----------------------------------------------------------------------------
/// This type is used to name all the cfg of GPIO.
/// Type of Cfg of GPIO is always used in hal_GpioAltFuncConfig() when try to  
/// set altfuc of specified GPIO. The details are defined by hardware.
// =============================================================================
typedef enum
{
    HAL_GPIO_ALTFUNC_CFG_0 = 0,//000
    HAL_GPIO_ALTFUNC_CFG_1,      //001
    HAL_GPIO_ALTFUNC_CFG_2,      //010
    HAL_GPIO_ALTFUNC_CFG_3,      //011
    HAL_GPIO_ALTFUNC_CFG_4,      //100
    HAL_GPIO_ALTFUNC_CFG_5,      //101
    HAL_GPIO_ALTFUNC_CFG_6,      //110
    HAL_GPIO_ALTFUNC_CFG_7,      //111
    HAL_GPIO_ALTFUNC_CFG_8,      //1000
    HAL_GPIO_ALTFUNC_CFG_9,      //1001
    HAL_GPIO_ALTFUNC_CFG_10,    //1010
    HAL_GPIO_ALTFUNC_CFG_11,    //1011
    HAL_GPIO_ALTFUNC_CFG_12,    //1100
    HAL_GPIO_ALTFUNC_CFG_13,    //1101
    HAL_GPIO_ALTFUNC_CFG_QTY = 14    
}HAL_GPIO_ALTFUNC_CFG_ID_T;

// =============================================================================
// HAL_GPIO_UP_DOWN_ID_T
// -----------------------------------------------------------------------------
/// This type is used to define rising and falling of GPIO in 5855.
// =============================================================================
typedef enum
{
    HAL_GPIO_UP = 0,
    HAL_GPIO_DOWN,

    HAL_GPIO_UP_DOWN_QTY = 2,
}HAL_GPIO_UP_DOWN_ID_T;

#define TGT_HAL_GPIO_INPUT_DEFAULT_UP_DOWN HAL_GPIO_UP

// =============================================================================
// HAL_GPIO_GPO_ID_T
// -----------------------------------------------------------------------------
/// This type is used to name all the GPO.
/// GPO functions of the GPIO driver are called with a parameter of 
/// this type to specify which GPO is concerned by a the function call.
// =============================================================================
typedef enum
{
    /// To be used in configuration when the field for this GPO is not used
    HAL_GPO_NONE = HAL_GPIO_TYPE_NONE << 16,
    HAL_GPO_0 = HAL_GPIO_TYPE_O << 16,
    HAL_GPO_1,
    HAL_GPO_2,
    HAL_GPO_3,
    HAL_GPO_4,
    HAL_GPO_5,
    HAL_GPO_6,
    HAL_GPO_7,
    HAL_GPO_8,
    HAL_GPO_9,
    HAL_GPO_10,
    HAL_GPO_11,

    HAL_GPO_QTY = 12
} HAL_GPIO_GPO_ID_T;



// =============================================================================
// HAL_GPIO_TCO_ID_T
// -----------------------------------------------------------------------------
/// This type is used to name all the TCO.
/// TCO functions of the GPIO driver are called with a parameter of 
/// this type to specify which TCO is concerned by a the function call.
// =============================================================================
typedef enum
{
    /// To be used in configuration when the field for this TCO is not used
    HAL_TCO_NONE = HAL_GPIO_TYPE_NONE << 16,
    HAL_TCO_0 = HAL_GPIO_TYPE_TCO << 16,
    HAL_TCO_1,
    HAL_TCO_2,
    HAL_TCO_3,
    HAL_TCO_4,
    HAL_TCO_5,
    HAL_TCO_6,
    HAL_TCO_7,
    HAL_TCO_8,
    HAL_TCO_9,

    HAL_TCO_QTY = 10
} HAL_GPIO_TCO_ID_T;



// =============================================================================
// HAL_APO_ID_T
// -----------------------------------------------------------------------------
/// Any Programmable Output IDentifier
/// Used to identify any general purpose output pin which can be either a GPIO 
/// pin, a GPO pin or a TCO pin.
// =============================================================================
typedef union
{
    struct
    {
        // NOTE: THIS IS ENDIANNES DEPENDANT
        UINT16 id:16;
        /// Defines the kind of the pin: GPIO, GPO, TCO, none
        HAL_GPIO_TYPE_T type:16;
    };
    /// id field is either a GPIO ID ...
    HAL_GPIO_GPIO_ID_T gpioId;
    /// or a GPO ID
    HAL_GPIO_GPO_ID_T gpoId;
    /// or a TCO ID depending on the type.
    HAL_GPIO_TCO_ID_T tcoId;
} HAL_APO_ID_T;



// =============================================================================
// HAL_GPIO_IRQ_MASK_T
// -----------------------------------------------------------------------------
/// This structure is used to define on which occasion an interrupt 
/// will be triggered from an interruptible GPIO.
/// In that sense, it is the interrupt mask, but the configuration is
/// much more precise
// =============================================================================
typedef struct
{
    /// Defines whether an interruption will be triggered on a rising
    /// edge on the GPIO
    BOOL rising;

    /// Defines whether an interruption will be triggered on a falling
    /// edge on the GPIO
    BOOL falling;

    /// Defines if the GPIO's signal will be debounced before the interrupt
    /// is triggered
    BOOL debounce;

    /// Defines if the interruption is on level (\c TRUE), or on edge (\c FALSE)
    BOOL level;
} HAL_GPIO_IRQ_MASK_T;



// =============================================================================
// HAL_GPIO_IRQ_HANDLER_T
// -----------------------------------------------------------------------------
/// Type for the user function called when an interrupt is triggered on 
/// a GPIO.
// =============================================================================
typedef VOID (*HAL_GPIO_IRQ_HANDLER_T)(VOID);






// =============================================================================
// HAL_GPIO_DC_ON_INT_MODE_T
// -----------------------------------------------------------------------------
/// Type used to define the interruption mode of the DC_ON read.
// =============================================================================
typedef enum
{
    /// Send IRQ if last read DCON is '0' and now is '1'.
    HAL_GPIO_DC_ON_INT_L2H,
    /// Send IRQ if last read DCON is '1' and now is '0'.
    HAL_GPIO_DC_ON_INT_H2L,
    /// Send IRQ every time read is ready.
    HAL_GPIO_DC_ON_INT_RR,
    /// disable IRQ for DCON
    HAL_GPIO_DC_ON_INT_NO
} HAL_GPIO_DC_ON_INT_MODE_T;


// =============================================================================
// HAL_GPIO_DIRECTION_T
// -----------------------------------------------------------------------------
/// Direction of a GPIO
// =============================================================================
typedef enum
{
    HAL_GPIO_DIRECTION_INPUT,
    HAL_GPIO_DIRECTION_OUTPUT,
#if (CHIP_ASIC_ID == CHIP_ASIC_ID_5855)|| (CHIP_ASIC_ID == CHIP_ASIC_ID_5856)
    HAL_GPIO_DIRECTION_INOUT,
    HAL_GPIO_DIRECTION_UNDEFINED,
#endif

    HAL_GPIO_DIRECTION_QTY
} HAL_GPIO_DIRECTION_T;


//#if (CHIP_ASIC_ID == CHIP_ASIC_ID_5855)|| (CHIP_ASIC_ID == CHIP_ASIC_ID_5856)
typedef enum
{
    HAL_GPIO_VIO2P8_SEL,
    HAL_GPIO_VIO1P8_SEL,
    HAL_GPIO_VIO_SEL_QTY
}HAL_GPIO_VIO_SEL_T;
//#endif

// =============================================================================
// HAL_GPIO_CFG_T
// -----------------------------------------------------------------------------
/// This structure is used to define the initial state of a GPIO when it is 
/// opened by a call to #hal_GpioOpen.
// =============================================================================
typedef struct
{
    /// Direction of the GPIO
    HAL_GPIO_DIRECTION_T direction;

    /// Initial value (if this GPIO is an output)
    BOOL value;
//#if (CHIP_ASIC_ID == CHIP_ASIC_ID_5855) || (CHIP_ASIC_ID == CHIP_ASIC_ID_5856)
    HAL_GPIO_UP_DOWN_ID_T         updown;
//#endif

    //drive strength
    UINT8                                        drv;
	
    // enable interrupt or not 
    UINT8                                        enint;   
	
    // gpio interrupt num
    UINT8                                        gpio_intnum;  
	
    /// IRQ mask, only valid if applied to an interruptible GPIO
    HAL_GPIO_IRQ_MASK_T irqMask;

    /// IRQ handler, only valid if applied to an interruptible GPIO
    HAL_GPIO_IRQ_HANDLER_T irqHandler;
} HAL_GPIO_CFG_T;




// =============================================================================
// FUNCTIONS
// =============================================================================

//added for 5855 init
PUBLIC VOID hal_GpioInit(VOID);
// =============================================================================
// FUNCTIONS
// =============================================================================

// =============================================================================
// hal_GpioOpen
// -----------------------------------------------------------------------------
/// Opens the a GPIO and sets its initial configuration. The GPIO's state can 
/// then be changed by the others functions of this API.
/// It also sets the corresponding pin in GPIO mode.
///
/// @param gpio Identifier of the GPIO to open
/// @param cfg Initial configuration of this GPIO.
// =============================================================================
PUBLIC VOID hal_GpioOpen(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_CFG_T* cfg);



// =============================================================================
// hal_GpioClose
// -----------------------------------------------------------------------------
/// Closes a GPIO driver. The GPIO is returned to its reset state
/// @param gpio GPIO to close.
// =============================================================================
PUBLIC VOID hal_GpioClose(HAL_GPIO_GPIO_ID_T gpio);



// =============================================================================
// hal_GpioSetOut
// -----------------------------------------------------------------------------
/// This function sets one GPIO to output and leaves the others'directions
/// unchanged.
// =============================================================================
PUBLIC VOID hal_GpioSetOut(HAL_GPIO_GPIO_ID_T gpio);



// =============================================================================
// hal_GpioSetIn
// -----------------------------------------------------------------------------
/// This function sets one GPIO to input and leaves the others'directions
/// unchanged.
// =============================================================================
PUBLIC VOID hal_GpioSetIn(HAL_GPIO_GPIO_ID_T gpio);



// =============================================================================
// hal_GpioGet
// -----------------------------------------------------------------------------
/// This function reads a GPIO, and returns its value. It 
/// returns the input value of GPIO configured as input and the output value 
/// for GPIO configured as output.
///
/// @return The input value for a GPIO configured as input and 
/// the output value for a GPIO configured as output.
// =============================================================================
PUBLIC UINT32 hal_GpioGet(HAL_GPIO_GPIO_ID_T gpio);



// =============================================================================
// hal_GpioSet
// -----------------------------------------------------------------------------
/// This function sets to '1' the value of the given GPIO, GPO or TCO and leaves
/// the others unchanged
/// @param apo A GPIO, a GPO or a TCO set to '1', others being unchanged.
// =============================================================================
PUBLIC VOID hal_GpioSet(HAL_APO_ID_T apo);



// =============================================================================
// hal_GpioClr
// -----------------------------------------------------------------------------
/// This function sets to '0' the value of the given GPIO, GPO or TCO and leaves
/// the others unchanged
/// @param apo A GPIO, a GPO or a TCO set to '0', others being unchanged.
// =============================================================================
PUBLIC VOID hal_GpioClr(HAL_APO_ID_T apo);



// =============================================================================
// hal_GpioResetIrq
// -----------------------------------------------------------------------------
/// Clears the gpio IRQ, 
/// This function should only be called to avoid unwanted IRQ. \n
/// For regular usage, IRQ clearing is done automatically by the driver. \n
/// Rise and fall cause are cleared simultaneously
/// 
/// @param gpio A GPIO whose interrupt cause is cleared.
// ==========================================================================
PUBLIC VOID hal_GpioResetIrq(HAL_GPIO_GPIO_ID_T gpio);



// =============================================================================
// hal_GpioIrqSetHandler
// -----------------------------------------------------------------------------
/// Sets the user IRQ handler called when an interruption is triggerd on a 
/// given GPIO.
///
/// @param gpio The GPIO whose interrupt will trig the handler
/// @param handler The user function called on an interruption on this GPIO.
// =============================================================================
PUBLIC VOID hal_GpioIrqSetHandler(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_IRQ_HANDLER_T handler);


// =============================================================================
// hal_GpioIrqDisable
// -----------------------------------------------------------------------------
/// Sets the user IRQ handler called when an interruption is triggerd on a
/// given GPIO.
///
/// @param gpio is the gpio which disable 
// =============================================================================
PUBLIC VOID hal_GpioIrqDisable(uint8 int_num);




// =============================================================================
// hal_GpioIrqSetMask
// -----------------------------------------------------------------------------
/// Set the condition under which an interrupt is triggered on a GPIO
/// @param gpio The GPIO
/// @param cfg Pointer to the configuration defining the condition 
/// under which the interrupts are triggered, ie the interrupt mask.
// =============================================================================
PUBLIC VOID hal_GpioIrqSetMask(HAL_GPIO_GPIO_ID_T gpio, CONST HAL_GPIO_IRQ_MASK_T* cfg);






// =============================================================================
// hal_GpioIrqConfig
// -----------------------------------------------------------------------------
/// Set the condition under which an interrupt is triggered on a GPIO
/// @param gpio The GPIO
/// @param cfg Pointer to the configuration defining the condition 
/// under which the interrupts are triggered, ie the interrupt mask.
// =============================================================================
PUBLIC VOID hal_GpioIrqConfig(HAL_GPIO_GPIO_ID_T gpio, CONST HAL_GPIO_IRQ_MASK_T config,uint8 id);




// =============================================================================
// hal_GpioGetCfg
// -----------------------------------------------------------------------------
/// Return the configuration of a GPIO.
/// @param gpio Identifier of the GPIO.
/// @param cfg Current configuration of this GPIO.
// =============================================================================
PUBLIC VOID hal_GpioGetCfg(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_CFG_T* cfg);



// =============================================================================
// hal_GpioGetIntStatus
// -----------------------------------------------------------------------------
/// Return the interrupt status of a GPIO.
/// @param gpio Identifier of the GPIO.
/// @return The interrupt status of this GPIO.
// =============================================================================
PUBLIC BOOL hal_GpioGetIntStatus(HAL_GPIO_GPIO_ID_T gpio);

//#if (CHIP_ASIC_ID == CHIP_ASIC_ID_5855)|| (CHIP_ASIC_ID == CHIP_ASIC_ID_5856||CHIP_ASIC_ID == CHIP_ASIC_ID_5856E)
// =============================================================================
// hal_GpioSetIdleLevel
// -----------------------------------------------------------------------------
/// This function sets rising and falling of specified gpio in 5855.
/// @param gpio Identifier of the GPIO.
/// @param upDown Value of raising/falling
/// @return void
// =============================================================================
PUBLIC VOID hal_GpioSetIdleLevel(HAL_GPIO_GPIO_ID_T gpio, 
                                        HAL_GPIO_UP_DOWN_ID_T upDown);


// =============================================================================
// hal_GpioAltFuncConfig
// -----------------------------------------------------------------------------
/// This function sets specified gpio as alt func in 5855.
/// @param gpio Identifier of the GPIO.
/// @return void
// =============================================================================
PUBLIC VOID hal_GpioAltFuncConfig(HAL_GPIO_GPIO_ID_T gpio, 
                                        HAL_GPIO_ALTFUNC_CFG_ID_T cfg,
                                        UINT8 drv_strength,
                                        HAL_GPIO_UP_DOWN_ID_T updown);
                                        

                                   
PUBLIC VOID hal_GpioSetPinMux(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_ALTFUNC_CFG_ID_T cfg);
PUBLIC VOID hal_GpioVioSel(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_VIO_SEL_T sel);
PUBLIC VOID hal_GpioUpOrDn(HAL_GPIO_GPIO_ID_T gpio, HAL_GPIO_UP_DOWN_ID_T updown);
PUBLIC VOID hal_GpioPd(HAL_GPIO_GPIO_ID_T gpio, uint8 ispd);
//#endif

#if 0
// =============================================================================
// hal_GpioDcOnOpen
// =============================================================================
/// Configure the DC-ON command
/// @param outTime Time for which GPIO0 is set to output mode, after a start 
/// read DCON command is issued.
/// @param waitTime Time for which GPIO0 should wait before reading DC_ON,
/// after a start read DCON command is issued (Note: \p waitTime must be 
/// strictly greater than \p outTime).
/// @param intMode Interruption mode of GPIO0 in mode DC_ON detection.
// =============================================================================
PUBLIC VOID hal_GpioDcOnOpen(UINT32 outTime, UINT32 waitTime,
                            HAL_GPIO_DC_ON_INT_MODE_T intMode);


// =============================================================================
// hal_GpioDcOnClose
// =============================================================================
/// Disable the DC-ON command: set back GPIO0 as regular GPIO
// =============================================================================
PUBLIC VOID hal_GpioDcOnClose(VOID);


// =============================================================================
// hal_GpioChgSetMode
// -----------------------------------------------------------------------------
/// Enable or disable the charger according to \p on.
/// when enabled, #hal_GpioChgDown can be called to pulse down the charger.
/// @param on charger state
// =============================================================================
PUBLIC VOID hal_GpioChgSetMode(BOOL on);


// =============================================================================
// hal_GpioChgDown
// -----------------------------------------------------------------------------
/// Sends the down signal to the charger to avoid a time-out. The user will 
/// have to call that function at least every 5 seconds.
// =============================================================================
PUBLIC VOID hal_GpioChgDown(VOID);


// =============================================================================
// hal_GpioChgGet
// -----------------------------------------------------------------------------
/// This function reads the charger dedicated GPIO, and returns its value.
///
/// @return The input value of the charger dedicated GPIO.
// =============================================================================
PUBLIC UINT32 hal_GpioChgGet(VOID);


// =============================================================================
// hal_GpioChgIrqSetHandler
// -----------------------------------------------------------------------------
/// Sets the user IRQ handler called when an interruption is triggerd on the 
/// charger dedicated GPIO.
///
/// @param gpio The GPIO whose interrupt will trig the handler
/// @param handler The user function called on an interruption on the charger
/// dedicated GPIO.
// =============================================================================
PUBLIC VOID hal_GpioChgIrqSetHandler(HAL_GPIO_IRQ_HANDLER_T handler);


#endif



///  @} <- End of the gpio group 


#endif // _HAL_GPIO_H_



