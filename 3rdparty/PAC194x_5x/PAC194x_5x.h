/*
  © 2022 Microchip Technology Inc. and its subsidiaries

  Subject to your compliance with these terms, you may use Microchip software
  and any derivatives exclusively with Microchip products. You're responsible
  for complying with 3rd party license terms applicable to your use of 3rd party
  software (including open source software) that may accompany Microchip software.
  SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
  APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
  MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP
  BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS,
  DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER
  CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
  FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S TOTAL LIABILITY
  ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT OF FEES, IF ANY,
  YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*/

#ifndef PAC194X5X_H
#define PAC194X5X_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

// PAC194x5x generic library version
#define PAC194X5X_LIBVER "1.0"

/**
    Section: Included Files
*/
#include <string.h>
#include "PAC194x_5x_definitions.h"
#include "PAC194x_5x_i2c.h"
#include "PAC194x_5x_mutex.h"

/*
 * PAC194x5x library error codes
 */    
#define PAC194X5X_SUCCESS                               0
#define PAC194X5X_BUSY                                  1
#define PAC194X5X_MUTEX_INVALID                         2
#define PAC194X5X_MUTEX_FAIL                            3
#define PAC194X5X_INVALID_PARAMETER                     4
#define PAC194X5X_I2C_INVALID_PARAM                     5
#define PAC194X5X_INVALID_DEVICE                        6
#define PAC194X5X_ALREADY_CACHED                        7
#define PAC194X5X_INVALID_SHUNT_VALUE                   8
#define PAC194X5X_INVALID_SAMPLE_MODE                   9
#define PAC194X5X_SINGLE_SHOT_MODE_CONFIGURED           10
#define PAC194X5X_VACC_POWER_MODE_NOT_CONFIGURED        11
#define PAC194X5X_VACC_VSENSE_MODE_NOT_CONFIGURED       12
#define PAC194X5X_INVALID_ACCUMULATION_MODE             13
#define PAC194X5X_NO_SHUNT                              14
#define PAC194X5X_REQUEST_FAIL                          100

/* 
 * PAC194x5x library interface
 */


/**
    @Summary
        Set the user call-back function.
    @Description
        This routine registers the user function that PAC194x5x library will call back 
        every time the library generates a processing event of the PAC194X5X_EVENT type.
        For instance, the user call-back function can be useful to flag the completion of the 
        library service request or the error occurrence. 
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        userCallback - The pointer to the call-back function. 
    @Param
        userContext - Pointer to a variable of user defined datatype that the called-back function will
                      receive as parameter.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetUserCallback(pPACdevice, appCallback, (uintptr_t)&user_data);
        </code>
*/
int16_t PAC194x5x_SetUserCallback(
    const PAC194X5X_PDEVICE_CONTEXT pdevice,
    const PAC194X5X_EVENT_HANDLER userCallback,
    const uintptr_t userContext
);


/**
    @Summary
        Library processing timeout function.
    @Description
        This routine can be called from user application or can be registered as a timer callback  
        function in order to drop the pending library request and reset the processing state to "Idle". 
    @Preconditions
        None
    @Param
        deviceContext - pointer to PAC194x5x device context data.
    @Returns
        Nothing.
    @Example
        <code>
            PAC194x5x_Timeout((uintptr_t)pPACdevice);
        </code>
*/
void PAC194x5x_Timeout(
    const uintptr_t deviceContext
);


/**
    @Summary
        Provides the latest library event.
    @Description
        Provides the latest library event as recorded in the device context.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        pevent - pointer to event variable.
     @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetEventStatus(pPACdevice, &event);
        </code>
*/
int16_t PAC194x5x_GetEventStatus(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PEVENT pevent);


/**
    @Summary
        Initializes the PAC194x5x instance.
    @Description
        This routine initializes the PAC194X5X_DEVICE_CONTEXT device context data and
        the PAC194x5x device to the default configuration,
        or to the configuration selected by the user in the MPLAB Harmony GUI.
        It also reads the device ID registers and caches their values in the device context data. 
        NOTE: 1ms delay must be allowed between the PAC194x5x_Device_Initialize() function call and
        the following function calls. 
    @Preconditions
        The user must assure that I2C Driver initialization has been performed.
        All deviceInit parameters must contain valid values. 
    @Param
        pdevice - Reference to the memory storage of PAC194x5x device context data.
    @Param
        deviceInit - Structure that contains the i2c Address, sync mode, i2c handle, rsense.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_Device_Initialize(pPACdevice, deviceInit);
        </code>
*/
int16_t PAC194x5x_Device_Initialize(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_DEVICE_INIT deviceInit);


/**
    @Summary
        Tests if the PAC194x5x instance was initialized.
    @Description
        Tests if the PAC194x5x instance was initialized.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Returns
        True if the PAC194x5x instance was initialized and false if it was not initialized.
        False if pdevice is NULL.
    @Example
        <code>
            errorCode = PAC194x5x_Device_IsInitialized(pPACdevice);
        </code>
*/
bool PAC194x5x_Device_IsInitialized(PAC194X5X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Gets the identification values for the PAC194x5x.
    @Description
        This method gets the content of the ID registers: 
        PRODUCT_ID, MANUFACTURER_ID and REVISION_ID.
        The function caches the ID values in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        pdeviceID - content of the ID registers
    @Return
        The error code. 
            - If the function returns PAC194X5X_ALREADY_CACHED, the device ID data
              is already available and copied in the pdeviceID parameter.
            - If the function returns PAC194X5X_SUCCESS, the data request has been 
              successfully initiated in async mode or successfully completed in 
              sync mode.
    @Example
        <code>
            errorCode = PAC194x5x_GetDeviceID(pPACdevice);
        <code>
*/
int16_t PAC194x5x_GetDeviceID(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PdeviceID pdeviceID);


/**
    @Summary
        Executes a device 'REFRESH' command.
    @Description
        This method executes the device 'REFRESH' command. 
        The accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the device readable registers,  
        the accumulators are reset and the configuration changes are applied. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_Refresh(pPACdevice);
        <code>
*/
int16_t PAC194x5x_Refresh(PAC194X5X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Executes a 'REFRESH_G' command.
    @Description
        This method executes the device 'REFRESH_G' command, using i2c 
        General Call command. In this case, for all PAC194x5x devices connected at the
        same i2c bus, the accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the devices readable registers,  
        the accumulators are reset and the configuration changes are applied. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_RefreshG(pPACdevice);
        <code>
*/
int16_t PAC194x5x_RefreshG(PAC194X5X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Executes a device 'REFRESH_V' command.
    @Description
        This method executes the device 'REFRESH_V' command. 
        The accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the device readable registers,  
        and the configuration changes are applied but the accumulators are not reset. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Returns
        The error code. For execution success, the method returns PAC194x5x_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_RefreshV(pPACdevice);
        <code>
*/
int16_t PAC194x5x_RefreshV(PAC194X5X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Gets the CTRL register value.
    @Description
        This method gets the currently set, the currently active or the latched active control register value,
        depending on the reg_select mode.
        If CTRL_LAT is selected, the function caches the register value in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        reg_select - 1- CTRL, 2- CTRL_ACT, 3- CTRL_LAT
    @Param
        pCtrl_reg - The control register value:
                        Bits 7-6:   Sample Rate
                        Bit 5:      Sleep Mode
                        Bit 4:      Single Shot Mode
                        Bit 3:      Alert Pin
                        Bit 2:      Alert CC
                        Bit 1:      Overflow Alert
                        Bit 0:      Overflow
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetCtrl_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetCtrl_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PCTRL_REGISTER pCtrl_reg);


/**
    @Summary
        Sets the CTRL register value.
    @Description
        This method sets the current control register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        Ctrl_reg - the control register value to be set (8 bit value):
                        Bits 7-6:   Sample Rate
                        Bit 5:      Sleep Mode
                        Bit 4:      Single Shot Mode
                        Bit 3:      Alert Pin
                        Bit 2:      Alert CC
                        Bit 1:      Overflow Alert
                        Bit 0:      Overflow
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetCtrl_reg(pPACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetCtrl_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_CTRL_REGISTER Ctrl_reg);


/**
    @Summary
        Gets the current accumulator count.
    @Description
        This method provides the count of power product samples that have been summed
        in the accumulator. 
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        pregister_val - The accumulator count register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetAccumulatorCount(pPACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetAccumulatorCount(PAC194X5X_PDEVICE_CONTEXT pdevice, uint32_t* pregister_val);


/**
    @Summary
        Gets the current register accumulated Vpower.
    @Description
        This method gets the register value of the accumulator sum of Vpower samples.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the user variable that receives the accumulator register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVACCn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVACCn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint64_t* pregister_val);


/**
    @Summary
        Computes the accumulated Vpower, Vsense or Vbus.
    @Description
        This method provides tthe calculated real value of the accumulated sum of Vpower, Vsense or Vbus samples,
        depending on Accum Config register settings.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the Vpower, Vsense or Vbus real accumulated value of the selected channel.
    @Param
        pmode - Vpower, Vsense or Vbus mode configured in Accum Config register:
                - Power accumulator - mode 0 - milli-Watt
                - Coulomb count     - mode 1 - milli-Amp*sec
                - Vbus accumulator  - mode 2 - milli-Volt
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVACCn(pPACdevice, 1, &value, &mode);
        <code>
*/
int16_t PAC194x5x_GetVACCn(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint8_t* pmode);


/**
    @Summary
        Gets the accumulated energy value.
    @Description
        This method computes the energy value for the power product
        samples accumulated in the VACCn register.
        The value unit is milli-Watt-hour.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The energy value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
        
    @Example
        <code>
            errorCode = PAC194x5x_GetEnergy_mWh(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetEnergy_mWh(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the accumulated energy value, considering the user measured time interval of power accumulation.
    @Description
        This method gets the calculated energy value that corresponds to the accumulated power
        in the measured time interval lapsed between the accumulator reset and the last refresh command.
        The value unit is milli-Watt-hour.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The energy value for selected channel.
    @Param 
        time - the accumulation time to provide the energy measurement
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetTimedEnergy_mWh(pPACdevice, 1, &value, time);
        <code>
*/
int16_t PAC194x5x_GetTimedEnergy_mWh(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time);


/**
    @Summary
        Gets the current Coulomb count value.
    @Description
        This method gets the calculated Coulomb count value that corresponds 
        with the accumulated Vsense.
        The value unit is milli-Amp*sec.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The Coulomb count value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
        If Single Shot or Single Shot 8x is configured, the function returns PAC194X5X_SINGLE_SHOT_MODE_CONFIGURED error.
        If the accumulator is not configured in VSENSE mode, the function returns PAC194X5X_VACC_VSENSE_MODE_NOT_CONFIGURED error.
    @Example
        <code>
            errorCode = PAC194x5x_GetCoulomb_mAs(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetCoulomb_mAs(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Coulomb count value, considering the user measured time interval of power accumulation.
    @Description
        This method gets the calculated Coulomb count value that corresponds to the accumulated Vsense
        in the measured time interval lapsed between the accumulator reset and the last refresh command.
        The value unit is milli-Amp*sec.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The Coulomb count value for selected channel.
    @Param 
        time - the accumulation time to provide the Coulomb count
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
        If the accumulator is not configured in VSENSE mode, the function returns PAC194X5X_VACC_VSENSE_MODE_NOT_CONFIGURED error.
    @Example
        <code>
            errorCode = PAC194x5x_GetTimedCoulomb_mAs(PACdevice, 1, &value, time);
        <code>
*/
int16_t PAC194x5x_GetTimedCoulomb_mAs(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time);


/**
    @Summary
        Gets the current Vbus register value.
    @Description
        This method provides the register value of the latched bus voltage sample.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the bus voltage register value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVBUSn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVBUSn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vbus value.
    @Description
        This method computes the value of the latched bus voltage sample, expressed in milli-Volts.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the bus voltage calculated value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVBUSn_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetVBUSn_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vsense register value.
    @Description
        This method gets the most recent register value of the sense voltage samples.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of current sense voltage for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVSENSEn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVSENSEn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vsense value.
    @Description
        This method gets the most recent calculated real value of the sense voltage samples.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of current sense voltage for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVSENSEn_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetVSENSEn_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Isense value.
    @Description
        This method computes the value of the current flowing through the 
        sense resistor, expressed in mA.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of sense current for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetISENSEn_mA(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetISENSEn_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vbus average register value.
    @Description
        This method gets the most recent register value of a rolling average of 
        the 8 most recent bus voltage measurements
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the bus voltage average register value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVBUSn_AVG_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVBUSn_AVG_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vbus average value.
    @Description
        This method gets the most recent calculated real value of a rolling average of 
        the 8 most recent bus voltage measurements.
        The unit value is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the bus voltage calculated average value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVBUSn_AVG_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetVBUSn_AVG_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vsense average register value.
    @Description
        This method gets the most recent register value of a rolling average of 
        the 8 most recent sense voltage measurements.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of current sense voltage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVSENSEn_AVG_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVSENSEn_AVG_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vsense average value.
    @Description
        This method gets the most recent calculated real value of a rolling average of 
        the 8 most recent sense voltage measurements.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of current sense voltage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVSENSEn_AVG_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetVSENSEn_AVG_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Returns the current average Isense value.
    @Description
        This method returns the most recent calculated amperage value considering the rolling average of 
        the 8 most recent sense voltage measurements.
        The value unit is milli-Amp.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of sense amperage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetISENSEn_AVG_mA(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetISENSEn_AVG_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Returns the current Vpower register value.
    @Description
        This method returns the register value of the proportional power for each channel.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of power for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVPOWERn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetVPOWERn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val);


/**
    @Summary
        Returns the current real Vpower value.
    @Description
        This method provides the power value sample latched in VPOWER register, expressed in mW.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of power for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVPOWERn_mW(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetVPOWERn_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the SMBus Settings register value.
    @Description
        This method gets the currently set SMBus Settings register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pSMBus_reg - The SMBus Settings register value:
                        Bit 7:         GPIO_DATA2
                        Bit 6:         GPIO_DATA1
                        Bit 5:         ANY_ALERT
                        Bit 4:         POR
                        Bit 3:         TIMEOUT
                        Bit 2:         BYTE_COUNT
                        Bit 1:         NO SKIP
                        Bit 0:         I2C_HISPEED
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetSMBusSettings_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetSMBusSettings_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PSMBUS_SETTINGS_REGISTER pSMBus_reg);


/**
    @Summary
        Sets the SMBus Settings register value.
    @Description
        This method sets the current SMBus Settings register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        SMBus_reg - The SMBus Settings register value to be set:
                        Bit 7:         GPIO_DATA2
                        Bit 6:         GPIO_DATA1
                        Bit 5:         ANY_ALERT
                        Bit 4:         POR
                        Bit 3:         TIMEOUT
                        Bit 2:         BYTE_COUNT
                        Bit 1:         NO SKIP
                        Bit 0:         I2C_HISPEED
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetSMBusSettings_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetSMBusSettings_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_SMBUS_SETTINGS_REGISTER SMBus_reg);


/**
    @Summary
        Gets the NEG_PWR_FSR register value.
    @Description
        This method gets the currently set, the currently active or the latched active NEG_PWR_FSR register value,
        depending on the reg_select mode.
        If NEG_PWR_FSR_LAT is selected, the function caches the register value in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        reg_select - 1- NEG_PWR_FSR, 2- NEG_PWR_FSR_ACT, 3- NEG_PWR_FSR_LAT
    @Param
        pNegPwrFsr_reg - The NEG_PWR_FSR register value:
                        Bits 15-14:       CFG_VS1
                        Bits 13-12:       CFG_VS2
                        Bits 11-10:       CFG_VS3
                        Bits 9-8:         CFG_VS4
                        Bits 7-6:         CFG_VB1
                        Bits 5-4:         CFG_VB2
                        Bits 3-2:         CFG_VB3
                        Bits 1-0:         CFG_VB4
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetNegPwrFsr_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetNegPwrFsr_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PNEG_PWR_FSR_REGISTER pNegPwrFsr_reg);


/**
    @Summary
        Sets the NEG_PWR_FSR register value.
    @Description
        This method sets the current NEG_PWR_FSR register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        NegPwrFsr_reg - the NEG_PWR_FSR register value to be set (16 bit value):
                        Bits 15-14:       CFG_VS1
                        Bits 13-12:       CFG_VS2
                        Bits 11-10:       CFG_VS3
                        Bits 9-8:         CFG_VS4
                        Bits 7-6:         CFG_VB1
                        Bits 5-4:         CFG_VB2
                        Bits 3-2:         CFG_VB3
                        Bits 1-0:         CFG_VB4
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetNegPwrFsr_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetNegPwrFsr_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_NEG_PWR_FSR_REGISTER NegPwrFsr_reg);


/**
    @Summary
        Gets the SLOW register value.
    @Description
        This method gets the currently set SLOW register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pSlow_reg - The SLOW register value:
                        Bit 7:         Slow
                        Bit 6:         SlowLowHigh
                        Bit 5:         SlowHighLow
                        Bit 4:         RefreshRise
                        Bit 3:         RefreshVRise
                        Bit 2:         RefreshFall
                        Bit 1:         RefreshVFall
                        Bit 0:         Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetSlow_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetSlow_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PSLOW_REGISTER pSlow_reg);


/**
    @Summary
        Sets the SLOW Settings register value.
    @Description
        This method sets the current SLOW register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        Slow_reg - The SLOW register value to be set:
                        Bit 7:         Slow
                        Bit 6:         SlowLowHigh
                        Bit 5:         SlowHighLow
                        Bit 4:         RefreshRise
                        Bit 3:         RefreshVRise
                        Bit 2:         RefreshFall
                        Bit 1:         RefreshVFall
                        Bit 0:         Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetSlow_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetSlow_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_SLOW_REGISTER Slow_reg);


/**
    @Summary
        Gets the Accum Config register value.
    @Description
        This method gets the currently set, the currently active or the latched active Accum Config register value,
        depending on the reg_select mode.
        If Accum_Config_LAT is selected, the function caches the register value in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        reg_select - 1- Accum Config, 2- Accum Config ACT, 3- Accum Config LAT
    @Param
        pAccumConfig_reg - The Accum Config register value:
                        Bits 7-6:         ACC1_CONFIG
                        Bits 5-4:         ACC2_CONFIG
                        Bits 3-2:         ACC3_CONFIG
                        Bits 1-0:         ACC4_CONFIG
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetAccumConfig_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetAccumConfig_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PACCUM_CONFIG_REGISTER pAccumConfig_reg);


/**
    @Summary
        Sets the Accum Config register value.
    @Description
        This method sets the current Accum Config register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        AccumConfig_reg - the Accum Config register value to be set (8 bit value):
                        Bits 7-6:         ACC1_CONFIG
                        Bits 5-4:         ACC2_CONFIG
                        Bits 3-2:         ACC3_CONFIG
                        Bits 1-0:         ACC4_CONFIG
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetAccumConfig_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetAccumConfig_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ACCUM_CONFIG_REGISTER AccumConfig_reg);


/**
    @Summary
        Gets the ALERT STATUS register value.
    @Description
        This method gets the currently set ALERT STATUS register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pAlertStatus_reg - The ALERT STATUS register value:
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bits 1-0:       Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetAlertStatus_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetAlertStatus_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_STATUS_REGISTER pAlertStatus_reg);


/**
    @Summary
        Gets the ALERT ENABLE register value.
    @Description
        This method gets the currently set ALERT ENABLE register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pAlertEnable_reg - The ALERT ENABLE register value:
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetAlertEnable_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetAlertEnable_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pAlertEnable_reg);


/**
    @Summary
        Sets the ALERT ENABLE register value.
    @Description
        This method sets the current ALERT ENABLE register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        AlertEnable_reg - the ALERT ENABLE register value to be set (24 bit value):
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetAlertEnable_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetAlertEnable_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg);


/**
    @Summary
        Gets the SLOW_ALERT1 register value.
    @Description
        This method gets the currently set SLOW_ALERT1 register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pSlowAlert1_reg - The SLOW_ALERT1 register value:
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC1
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetSlowAlert1_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetSlowAlert1_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pSlowAlert1_reg);


/**
    @Summary
        Sets the SLOW_ALERT1 register value.
    @Description
        This method sets the current SLOW_ALERT1 register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        SlowAlert1_reg - the SLOW_ALERT1 register value to be set (24 bit value):
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC1
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetSlowAlert1_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetSlowAlert1_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg);


/**
    @Summary
        Gets the GPIO_ALERT2 register value.
    @Description
        This method gets the currently set GPIO_ALERT2 register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pGpioAlert2_reg - The GPIO_ALERT2 register value:
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC2
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetGpioAlert2_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetGpioAlert2_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pGpioAlert2_reg);


/**
    @Summary
        Sets the GPIO_ALERT2 register value.
    @Description
        This method sets the current GPIO_ALERT2 register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        GpioAlert2_reg - the GPIO_ALERT2 register value to be set (24 bit value):
                        Bit 23:         CH1_OC
                        Bit 22:         CH2_OC
                        Bit 21:         CH3_OC
                        Bit 20:         CH4_OC
                        Bit 19:         CH1_UC
                        Bit 18:         CH2_UC
                        Bit 17:         CH3_UC
                        Bit 16:         CH4_UC
                        Bit 15:         CH1_OV
                        Bit 14:         CH2_OV
                        Bit 13:         CH3_OV
                        Bit 12:         CH4_OV
                        Bit 11:         CH1_UV
                        Bit 10:         CH2_UV
                        Bit 9:          CH3_UV
                        Bit 8:          CH4_UV   
                        Bit 7:          CH1_OP
                        Bit 6:          CH2_OP
                        Bit 5:          CH3_OP
                        Bit 4:          CH4_OP
                        Bit 3:          ACC_OVF
                        Bit 2:          ACC_COUNT
                        Bit 1:          ALERT_CC2
                        Bit 0:          Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetGpioAlert2_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetGpioAlert2_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg);


/**
    @Summary
        Gets the ACC Fullness limits register value.
    @Description
        This method gets the currently set ACC Fullness limits register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        pAccFullnessLimits_reg - The ACC Fullness limits register value:
                        Bits 15-14:       ACC_CH1
                        Bits 13-12:       ACC_CH2
                        Bits 11-10:       ACC_CH3
                        Bits 9-8:         ACC_CH4
                        Bits 7-6:         ACC_COUNT
                        Bits 5-0:         Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetAccFullness_reg(PACdevice, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetAccFullness_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PACCUM_LIMITS_REGISTER pAccFullnessLimits_reg);


/**
    @Summary
        Sets the ACC Fullness limits register value.
    @Description
        This method sets the current ACC Fullness limits register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        AccFullnessLimits_reg - the ACC Fullness limits register value to be set (16 bit value):
                        Bits 15-14:       ACC_CH1
                        Bits 13-12:       ACC_CH2
                        Bits 11-10:       ACC_CH3
                        Bits 9-8:         ACC_CH4
                        Bits 7-6:         ACC_COUNT
                        Bits 5-0:         Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetAccFullness_reg(PACdevice, reg_value);
        <code>
*/
int16_t PAC194x5x_SetAccFullness_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ACCUM_LIMITS_REGISTER AccFullnessLimits_reg);


/**
    @Summary
        Gets the OC limit register value.
    @Description
        This method gets the currently set Over Current limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - The OC limit register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOClimit_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetOClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Sets the OC limit register value.
    @Description
        This method sets the current Over Current limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        register_val - the OC limit register value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOClimit_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetOClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val);


/**
    @Summary
        Gets the real OC limit value.
    @Description
        This method gets the currently set Over Current limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The OC limit real value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOClimit_real(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetOClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Sets the real OC limit value.
    @Description
        This method sets the current Over Current limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        value - the OC limit real value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOClimit_real(PACdevice, 1, value);
        <code>
*/
int16_t PAC194x5x_SetOClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value);


/**
    @Summary
        Gets the UC limit register value.
    @Description
        This method gets the currently set Under Current limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - The UC limit register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetUClimit_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetUClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Sets the UC limit register value.
    @Description
        This method sets the current Under Current limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        register_val - the UC limit register value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetUClimit_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetUClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val);


/**
    @Summary
        Gets the real UC limit value.
    @Description
        This method gets the currently set Under Current limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The UC limit real value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetUClimit_real(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetUClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Sets the real UC limit value.
    @Description
        This method sets the current Under Current limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        value - the UC limit real value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetUClimit_real(PACdevice, 1, value);
        <code>
*/
int16_t PAC194x5x_SetUClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value);


/**
    @Summary
        Gets the OP limit register value.
    @Description
        This method gets the currently set Over Power limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - The OP limit register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOPlimit_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetOPlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val);


/**
    @Summary
        Sets the OP limit register value.
    @Description
        This method sets the current Over Power limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        register_val - the OP limit register value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOPlimit_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetOPlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t register_val);


/**
    @Summary
        Gets the real OP limit value.
    @Description
        This method gets the currently set Over Power limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The OP limit real value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOPlimit_real(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetOPlimit_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Sets the real OP limit value.
    @Description
        This method sets the current Over Power limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        value - the OP limit real value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOPlimit_real(PACdevice, 1, value);
        <code>
*/
int16_t PAC194x5x_SetOPlimit_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value);


/**
    @Summary
        Gets the OV limit register value.
    @Description
        This method gets the currently set Over Voltage limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - The OV limit register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOVlimit_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetOVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Sets the OV limit register value.
    @Description
        This method sets the current Over Voltage limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        register_val - the OV limit register value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOVlimit_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetOVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val);


/**
    @Summary
        Gets the real OV limit value.
    @Description
        This method gets the currently set Over Voltage limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The OV limit real value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetOVlimit_real(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetOVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Sets the real OV limit value.
    @Description
        This method sets the current Over Voltage limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        value - the OV limit real value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetOVlimit_real(PACdevice, 1, value);
        <code>
*/
int16_t PAC194x5x_SetOVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value);


/**
    @Summary
        Gets the UV limit register value.
    @Description
        This method gets the currently set Under Voltage limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - The UV limit register value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetUVlimit_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetUVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Sets the UV limit register value.
    @Description
        This method sets the current Under Voltage limit register value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        register_val - the UV limit register value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetUVlimit_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetUVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val);


/**
    @Summary
        Gets the real UV limit value.
    @Description
        This method gets the currently set Under Voltage limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The UV limit real value.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetUVlimit_real(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_GetUVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Sets the real UV limit value.
    @Description
        This method sets the current Under Voltage limit calculated real value.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        value - the UV limit real value to be set.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetUVlimit_real(PACdevice, 1, value);
        <code>
*/
int16_t PAC194x5x_SetUVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value);


/**
    @Summary
        Gets the OC, UC, OP, OV or UV limit Nsamples register value.
    @Description
        This method gets the OC, UC, OP, OV or UV limit Nsamples register value, depending on the reg_select mode.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        reg_select - 1- OC limit Nsamples, 2- UC limit Nsamples, 3- OP limit Nsamples, 4- OV limit Nsamples, 5- UV limit Nsamples
    @Param
        pLimitNsamples_reg - The OC, UC, OP, OV or UV limit Nsamples register value:
                        Bits 7-6:         Nsamples_CH1
                        Bits 5-4:         Nsamples_CH2
                        Bits 3-2:         Nsamples_CH3
                        Bits 1-0:         Nsamples_CH4
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetLimitNsamples_reg(PACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC194x5x_GetLimitNsamples(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PLIMIT_NSAMPLES_REGISTER pLimitNsamples_reg);


/**
    @Summary
        Sets the OC, UC, OP, OV or UV limit Nsamples register value.
    @Description
        This method sets the current OC, UC, OP, OV or UV limit Nsamples register value depending on the reg_select mode.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        reg_select - 1- OC limit Nsamples, 2- UC limit Nsamples, 3- OP limit Nsamples, 4- OV limit Nsamples, 5- UV limit Nsamples
    @Param
        LimitNsamples_reg - the OC, UC, OP, OV or UV limit Nsamples register value to be set (8 bit value):
                        Bits 7-6:         Nsamples_CH1
                        Bits 5-4:         Nsamples_CH2
                        Bits 3-2:         Nsamples_CH3
                        Bits 1-0:         Nsamples_CH4
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_SetLimitNsamples_reg(PACdevice, 1, reg_value);
        <code>
*/
int16_t PAC194x5x_SetLimitNsamples(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_LIMIT_NSAMPLES_REGISTER LimitNsamples_reg);


/**
    @Summary
        Gets the current VBUS LSB unit value.
    @Description
        This method gets the calculated VBUS LSB unit value, also valid for
        the VACCn accumulator configured in Vbus accumulation mode.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The VBUS LSB unit value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVBUS_LSBunit(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_VBUS_LSBunit(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current VSENSE LSB unit value.
    @Description
        This method gets the calculated VSENSE LSB unit value, also valid for
        the VACCn accumulator configured in VSENSE accumulation mode.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The VSENSE LSB unit value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVSENSE_LSBunit(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_VSENSE_LSBunit(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current VPOWER LSB unit value.
    @Description
        This method gets the calculated VPOWER LSB unit value, also valid for
        the VACCn accumulator configured in power accumulation mode.
        The value unit is milli-Watt.
    @Preconditions
        None
    @Param
        pdevice - PAC194x/5x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The VPOWER LSB unit value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC194X5X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC194x5x_GetVPOWER_LSBunit(PACdevice, 1, &value);
        <code>
*/
int16_t PAC194x5x_VPOWER_LSBunit(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Tests if the PAC194x5x instance is busy.
    @Description
        Tests if the PAC194x5x instance is busy.
    @Preconditions
        None
    @Param
        pdevice - PAC194x5x device context data.
    @Returns
        True if the PAC194x5x instance is busy and false if it not busy.
        True if pdevice is NULL.
    @Example
        <code>
            errorCode = PAC194x5x_Device_IsBusy(pPACdevice);
        </code>
*/
bool PAC194x5x_Device_IsBusy(PAC194X5X_PDEVICE_CONTEXT pdevice);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	// _PAC194X_5X_H

/**
  End of File
*/
