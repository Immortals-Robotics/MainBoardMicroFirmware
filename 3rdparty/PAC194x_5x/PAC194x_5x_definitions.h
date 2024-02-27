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

#ifndef PAC194X5X_TYPES_H
#define PAC194X5X_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/**
    Section: Included Files
*/
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
  

#include "PAC194x_5x_i2c.h"         // I2C driver support
#include "PAC194x_5x_mutex.h"       // mutex support
    
//PAC194x5x maximum transmission and reception data byte-count
#define PAC194X5X_I2C_TX_MAXSIZE    4 
#define PAC194X5X_I2C_RX_MAXSIZE    7
    
#define PAC194X5X_MAX_CH_COUNT      4

#define ENERGY_UNIT_CONVERSION  (float)1/3600  //convert from 1Ws to 1Wh    
    
/*
 * PAC194x5x register address
 */

#define PAC194X5X_REFRESH_CMD_ADDR            0x00
#define PAC194X5X_CTRL_ADDR                   0x01
#define PAC194X5X_ACC_COUNT_ADDR              0x02
#define PAC194X5X_VACC1_ADDR                  0x03
#define PAC194X5X_VACC2_ADDR                  0x04
#define PAC194X5X_VACC3_ADDR                  0x05
#define PAC194X5X_VACC4_ADDR                  0x06
#define PAC194X5X_VBUS1_ADDR                  0x07
#define PAC194X5X_VBUS2_ADDR                  0x08
#define PAC194X5X_VBUS3_ADDR                  0x09
#define PAC194X5X_VBUS4_ADDR                  0x0A
#define PAC194X5X_VSENSE1_ADDR                0x0B
#define PAC194X5X_VSENSE2_ADDR                0x0C
#define PAC194X5X_VSENSE3_ADDR                0x0D
#define PAC194X5X_VSENSE4_ADDR                0x0E
#define PAC194X5X_VBUS1_AVG_ADDR              0x0F
#define PAC194X5X_VBUS2_AVG_ADDR              0x10
#define PAC194X5X_VBUS3_AVG_ADDR              0x11
#define PAC194X5X_VBUS4_AVG_ADDR              0x12
#define PAC194X5X_VSENSE1_AVG_ADDR            0x13
#define PAC194X5X_VSENSE2_AVG_ADDR            0x14
#define PAC194X5X_VSENSE3_AVG_ADDR            0x15
#define PAC194X5X_VSENSE4_AVG_ADDR            0x16
#define PAC194X5X_VPOWER1_ADDR                0x17
#define PAC194X5X_VPOWER2_ADDR                0x18
#define PAC194X5X_VPOWER3_ADDR                0x19
#define PAC194X5X_VPOWER4_ADDR                0x1A
#define PAC194X5X_SMBUS_SETTINGS_ADDR         0x1C
#define PAC194X5X_NEG_PWR_FSR_ADDR            0x1D
#define PAC194X5X_REFRESH_G_CMD_ADDR          0x1E
#define PAC194X5X_REFRESH_V_CMD_ADDR          0x1F
#define PAC194X5X_SLOW_ADDR                   0x20
#define PAC194X5X_CTRL_ACT_ADDR               0x21
#define PAC194X5X_NEG_PWR_FSR_ACT_ADDR        0x22
#define PAC194X5X_CTRL_LAT_ADDR               0x23
#define PAC194X5X_NEG_PWR_FSR_LAT_ADDR        0x24
#define PAC194X5X_ACCUM_CONFIG_ADDR           0x25
#define PAC194X5X_ALERT_STATUS_ADDR           0x26
#define PAC194X5X_SLOW_ALERT1_ADDR            0x27
#define PAC194X5X_GPIO_ALERT2_ADDR            0x28
#define PAC194X5X_ACC_FULLNESS_LIMITS_ADDR    0x29
#define PAC194X5X_OC_LIMIT1_ADDR              0x30
#define PAC194X5X_OC_LIMIT2_ADDR              0x31
#define PAC194X5X_OC_LIMIT3_ADDR              0x32
#define PAC194X5X_OC_LIMIT4_ADDR              0x33
#define PAC194X5X_UC_LIMIT1_ADDR              0x34
#define PAC194X5X_UC_LIMIT2_ADDR              0x35
#define PAC194X5X_UC_LIMIT3_ADDR              0x36
#define PAC194X5X_UC_LIMIT4_ADDR              0x37
#define PAC194X5X_OP_LIMIT1_ADDR              0x38
#define PAC194X5X_OP_LIMIT2_ADDR              0x39
#define PAC194X5X_OP_LIMIT3_ADDR              0x3A
#define PAC194X5X_OP_LIMIT4_ADDR              0x3B
#define PAC194X5X_OV_LIMIT1_ADDR              0x3C
#define PAC194X5X_OV_LIMIT2_ADDR              0x3D
#define PAC194X5X_OV_LIMIT3_ADDR              0x3E
#define PAC194X5X_OV_LIMIT4_ADDR              0x3F
#define PAC194X5X_UV_LIMIT1_ADDR              0x40
#define PAC194X5X_UV_LIMIT2_ADDR              0x41
#define PAC194X5X_UV_LIMIT3_ADDR              0x42
#define PAC194X5X_UV_LIMIT4_ADDR              0x43
#define PAC194X5X_OC_LIMIT_N_ADDR             0x44
#define PAC194X5X_UC_LIMIT_N_ADDR             0x45
#define PAC194X5X_OP_LIMIT_N_ADDR             0x46
#define PAC194X5X_OV_LIMIT_N_ADDR             0x47
#define PAC194X5X_UV_LIMIT_N_ADDR             0x48    
#define PAC194X5X_ALERT_ENABLE_ADDR           0x49
#define PAC194X5X_ACCUM_CONFIG_ACT_ADDR       0x4A
#define PAC194X5X_ACCUM_CONFIG_LAT_ADDR       0x4B

#define PAC194X5X_PRODUCT_ID_ADDR             0xFD
#define PAC194X5X_MANUFACTURER_ID_ADDR        0xFE
#define PAC194X5X_REVISION_ID_ADDR            0xFF
    
/*
 * DEVICE REGISTER SIZES (bytes)
 */
#define PAC194X5X_ACC_COUNT_SZ       4
#define PAC194X5X_VACCN_SZ           7
#define PAC194X5X_VPOWERN_SZ         4
#define PAC194X5X_OPLIMIT_SZ         3
#define PAC194X5X_OTHERLIMIT_SZ      2
#define PAC194X5X_IDREG_SZ           1
#define PAC194X5X_CTRL_SZ            2
#define PAC194X5X_VBUS_VSENSE_SZ     2
#define PAC194X5X_SMBUS_SZ           1
#define PAC194X5X_NEGPWRFSR_SZ       2
#define PAC194X5X_SLOW_SZ            1
#define PAC194X5X_ACCUMCONFIG_SZ     1
#define PAC194X5X_ALERT_SZ           3
#define PAC194X5X_OTHERLIMIT_N_SZ    1

#define SMBUS_BYTECNT   1   //the extra byte for SMBUS block read protocol    

/*
 * DEVICE REGISTER WIDTH (bits)
 */
#define PAC194X5X_VPOWERN_WIDTH      30
#define PAC194X5X_VBUSN_WIDTH        16
#define PAC194X5X_VSENSEN_WIDTH      16
#define PAC194X5X_VLIMIT_WIDTH       16
#define PAC194X5X_PLIMIT_WIDTH       24

/* 
 * PAC194x5x library interface
 */

typedef enum _PAC194X5X_procState{
    Uninitialized = 0,
    Idle = 1,
    Sync = 2,
    GetDeviceIDReq              = 10,
    RefreshReq                  = 20,
    RefreshGReq                 = 21,
    RefreshVReq                 = 22,
    GetCtrlRegisterReq          = 30,
    SetCtrlRegisterReq          = 31,
    GetSMBusRegisterReq         = 32,
    SetSMBusRegisterReq         = 33,
    GetNegPWRFSRRegisterReq     = 34,
    SetNegPWRFSRRegisterReq     = 35,
    GetSlowRegisterReq          = 36,
    SetSlowRegisterReq          = 37,
    GetAccumConfigRegisterReq   = 38,
    SetAccumConfigRegisterReq   = 39,
    GetAccCountReq              = 40,
    GetVACCnRegisterReq         = 50,
    GetVACCnValueReq            = 51,
    GetEnergyReq                = 52,
    GetTimedEnergyReq           = 53,
    GetCoulombReq               = 54,
    GetTimedCoulombReq          = 55,
    GetAlertStatusRegisterReq   = 60,
    GetAlertEnableRegisterReq   = 61,
    SetAlertEnableRegisterReq   = 62,
    GetSlowAlert1RegisterReq    = 63,
    SetSlowAlert1RegisterReq    = 64,
    GetGpioAlert2RegisterReq    = 65,
    SetGpioAlert2RegisterReq    = 66,
    GetAccFullnessRegisterReq   = 67,
    SetAccFullnessRegisterReq   = 68,
    GetVBUSnRegisterReq         = 70,
    GetVBUSnValueReq            = 71,
    GetVSENSEnRegisterReq       = 72,
    GetVSENSEnValueReq          = 73,
    GetISENSEnValueReq          = 74,
    GetVBUSnAVGRegisterReq      = 80,
    GetVBUSnAVGValueReq         = 81,
    GetVSENSEnAVGRegisterReq    = 82,
    GetVSENSEnAVGValueReq       = 83,
    GetISENSEnAVGValueReq       = 84,
    GetVPOWERnRegisterReq       = 90,
    GetVPOWERnValueReq          = 91,
    GetOClimitRegisterReq       = 100,
    GetOClimitValueReq          = 101,
    SetOClimitRegisterReq       = 102,
    SetOClimitValueReq          = 103,
    GetUClimitRegisterReq       = 104,
    GetUClimitValueReq          = 105,
    SetUClimitRegisterReq       = 106,
    SetUClimitValueReq          = 107,
    GetOPlimitRegisterReq       = 108,
    GetOPlimitValueReq          = 109,
    SetOPlimitRegisterReq       = 110,
    SetOPlimitValueReq          = 111,
    GetOVlimitRegisterReq       = 112,
    GetOVlimitValueReq          = 113,
    SetOVlimitRegisterReq       = 114,
    SetOVlimitValueReq          = 115,
    GetUVlimitRegisterReq       = 116,
    GetUVlimitValueReq          = 117,
    SetUVlimitRegisterReq       = 118,
    SetUVlimitValueReq          = 119,
    GetLimitNsamplesRegisterReq = 120,
    SetLimitNsamplesRegisterReq = 121,
} PAC194X5X_procState;

typedef struct _PAC194X5X_DEVICE_INIT{
    uint16_t i2cAddress;                    //i2c client address of the PAC194x5x device
    bool syncMode;                          //if TRUE, the library function calls will be blocking calls
    PAC194X5X_I2C_HANDLE i2cHandle;
    uint32_t rsense[PAC194X5X_MAX_CH_COUNT];  //array of sense resistor values, expressed in micro-Ohm units, one value for each channel.
    float VrailToVbusRatio[PAC194X5X_MAX_CH_COUNT];
} PAC194X5X_DEVICE_INIT;

typedef enum {
    PAC194X5X_EVENT_NO_EVENT          = 0,
    PAC194X5X_EVENT_REQUEST_COMPLETE  = 1,
    PAC194X5X_EVENT_TRANSFER_ERROR    = 2,
    PAC194X5X_EVENT_UNKNOWN_ERROR     = 3,    // unidentified i2c communication error encountered
    PAC194X5X_EVENT_REQUEST_ERROR     = 4,
    PAC194X5X_EVENT_REQUEST_PENDING   = 5,
    PAC194X5X_EVENT_TIMEOUT           = 6
}PAC194X5X_EVENT, *PAC194X5X_PEVENT;

/**
    @Summary
        Pointer to user call-back function.
    @Description
        This is the prototype for the user "callback function" that the library can execute 
        upon receiving one of the events of PAC194X5X_EVENT type.
    @Preconditions
        None
    @Param
        event - Occurred event during library request processing.
    @Param
        context - Pointer to a variable of user defined datatype that the called-back
                    function receives back as parameter.
    @Returns
        None.
*/
typedef void ( *PAC194X5X_EVENT_HANDLER )( PAC194X5X_EVENT event, uintptr_t context );

typedef struct _PAC194X5X_deviceID {
    uint8_t product;        // PRODUCT_ID register value
    uint8_t manufacturer;   // MANUFACTURER_ID register value
    uint8_t revision;       // REVISION_ID register value
 } PAC194X5X_deviceID, *PAC194X5X_PdeviceID;

typedef struct _PAC194X5X_CTRL_REGISTER{  
  // register MSB
    unsigned char SAMPLE_MODE : 4;
    unsigned char GPIO_ALERT2 : 2;
    unsigned char SLOW_ALERT1 : 2;
  // register LSB
    unsigned char CH1_OFF     : 1;
    unsigned char CH2_OFF     : 1;
    unsigned char CH3_OFF     : 1;
    unsigned char CH4_OFF     : 1;
} PAC194X5X_CTRL_REGISTER, *PAC194X5X_PCTRL_REGISTER;
#define PAC194X5X_CTRL_SAMPLE_MODE_BITPOS    4      //field position in the register MSB
#define PAC194X5X_CTRL_GPIO_ALERT2_BITPOS    2      //field position in the register MSB
#define PAC194X5X_CTRL_SLOW_ALERT1_BITPOS    0      //field position in the register MSB
#define PAC194X5X_CTRL_CH1_OFF_BITPOS        7      //field position in the register LSB
#define PAC194X5X_CTRL_CH2_OFF_BITPOS        6      //field position in the register LSB
#define PAC194X5X_CTRL_CH3_OFF_BITPOS        5      //field position in the register LSB
#define PAC194X5X_CTRL_CH4_OFF_BITPOS        4      //field position in the register LSB
#define PAC194X5X_CTRL_SAMPLE_MODE_BITMASK   0x0F
#define PAC194X5X_CTRL_GPIO_ALERT_BITMASK    0x03
#define PAC194X5X_CTRL_CHN_OFF_BITMASK       0x01

typedef struct _PAC194X5X_SMBUS_SETTINGS_REGISTER {
    unsigned char GPIO_DATA2  : 1;
    unsigned char GPIO_DATA1  : 1;
    unsigned char ANY_ALERT   : 1;
    unsigned char POR         : 1;
    unsigned char TIMEOUT     : 1;
    unsigned char BYTE_COUNT  : 1;
    unsigned char NO_SKIP     : 1;
    unsigned char I2C_HISPEED : 1;
} PAC194X5X_SMBUS_SETTINGS_REGISTER, *PAC194X5X_PSMBUS_SETTINGS_REGISTER;
#define PAC194X5X_SMBUS_GPIODATA2_BITPOS    7
#define PAC194X5X_SMBUS_GPIODATA1_BITPOS    6
#define PAC194X5X_SMBUS_ANYALERT_BITPOS     5
#define PAC194X5X_SMBUS_POR_BITPOS          4
#define PAC194X5X_SMBUS_TIMEOUT_BITPOS      3
#define PAC194X5X_SMBUS_BYTECOUNT_BITPOS    2
#define PAC194X5X_SMBUS_NOSKIP_BITPOS       1
#define PAC194X5X_SMBUS_I2CSPEED_BITPOS     0
#define PAC194X5X_SMBUS_BITMASK   0x01

typedef struct _PAC194X5X_NEG_PWR_FSR_REGISTER {
  // register MSB
    unsigned char CFG_VS1 : 2;
    unsigned char CFG_VS2 : 2;
    unsigned char CFG_VS3 : 2;
    unsigned char CFG_VS4 : 2;
  // register LSB
    unsigned char CFG_VB1 : 2;
    unsigned char CFG_VB2 : 2;    
    unsigned char CFG_VB3 : 2;
    unsigned char CFG_VB4 : 2;    
} PAC194X5X_NEG_PWR_FSR_REGISTER, *PAC194X5X_PNEG_PWR_FSR_REGISTER;
#define PAC194X5X_NEGPWRFSR_VS1_BITPOS    6      //field position in the register MSB
#define PAC194X5X_NEGPWRFSR_VS2_BITPOS    4      //field position in the register MSB
#define PAC194X5X_NEGPWRFSR_VS3_BITPOS    2      //field position in the register MSB
#define PAC194X5X_NEGPWRFSR_VS4_BITPOS    0      //field position in the register MSB
#define PAC194X5X_NEGPWRFSR_VB1_BITPOS    6      //field position in the register LSB
#define PAC194X5X_NEGPWRFSR_VB2_BITPOS    4      //field position in the register LSB
#define PAC194X5X_NEGPWRFSR_VB3_BITPOS    2      //field position in the register LSB
#define PAC194X5X_NEGPWRFSR_VB4_BITPOS    0      //field position in the register LSB
#define PAC194X5X_NEGPWRFSR_BITMASK       0x03
#define PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR 0b00
#define PAC194X5X_NEGPWRFSR_MODE_BIPOLAR  0b01
#define PAC194X5X_NEGPWRFSR_MODE_HALFFSR  0b10
#define PAC194X5X_NEGPWRFSR_MODE_RESERVED 0b11

typedef struct _PAC194X5X_SLOW_REGISTER {
    unsigned char Slow          : 1;
    unsigned char SlowLowHigh   : 1;
    unsigned char SlowHighLow   : 1;
    unsigned char RefreshRise   : 1;
    unsigned char RefreshVRise  : 1;
    unsigned char RefreshFall   : 1;
    unsigned char RefreshVFall  : 1;
} PAC194X5X_SLOW_REGISTER, *PAC194X5X_PSLOW_REGISTER;
#define PAC194X5X_SLOW_SLOW_BITPOS      7
#define PAC194X5X_SLOW_LH_BITPOS        6
#define PAC194X5X_SLOW_HL_BITPOS        5
#define PAC194X5X_SLOW_RRISE_BITPOS     4
#define PAC194X5X_SLOW_RVRISE_BITPOS    3
#define PAC194X5X_SLOW_RFALL_BITPOS     2
#define PAC194X5X_SLOW_RVFALL_BITPOS    1
#define PAC194X5X_SLOW_BITMASK          0x01

typedef struct _PAC194X5X_ACCUM_CONFIG_REGISTER {
    unsigned char ACC1_CONFIG : 2;
    unsigned char ACC2_CONFIG : 2;
    unsigned char ACC3_CONFIG : 2;
    unsigned char ACC4_CONFIG : 2;
} PAC194X5X_ACCUM_CONFIG_REGISTER, *PAC194X5X_PACCUM_CONFIG_REGISTER;
#define PAC194X5X_ACCCFG_ACC1_BITPOS    6
#define PAC194X5X_ACCCFG_ACC2_BITPOS    4
#define PAC194X5X_ACCCFG_ACC3_BITPOS    2
#define PAC194X5X_ACCCFG_ACC4_BITPOS    0
#define PAC194X5X_ACCCFG_BITMASK        0x03
#define PAC194X5X_ACCCFG_MODE_VPOWER    0b00
#define PAC194X5X_ACCCFG_MODE_VSENSE    0b01
#define PAC194X5X_ACCCFG_MODE_VBUS      0b10
#define PAC194X5X_ACCCFG_MODE_RESERVED  0b11

typedef struct _PAC194X5X_ALERT_STATUS_REGISTER {
// register MSB
    unsigned char CH1_OC    : 1;
    unsigned char CH2_OC    : 1;
    unsigned char CH3_OC    : 1;
    unsigned char CH4_OC    : 1;
    unsigned char CH1_UC    : 1;
    unsigned char CH2_UC    : 1;
    unsigned char CH3_UC    : 1;
    unsigned char CH4_UC    : 1;
// register MiddleByte
    unsigned char CH1_OV    : 1;
    unsigned char CH2_OV    : 1;
    unsigned char CH3_OV    : 1;
    unsigned char CH4_OV    : 1;
    unsigned char CH1_UV    : 1;
    unsigned char CH2_UV    : 1;
    unsigned char CH3_UV    : 1;
    unsigned char CH4_UV    : 1;
// register LSB
    unsigned char CH1_OP    : 1;
    unsigned char CH2_OP    : 1;
    unsigned char CH3_OP    : 1;
    unsigned char CH4_OP    : 1;
    unsigned char ACC_OVF   : 1;
    unsigned char ACC_COUNT : 1;
    
} PAC194X5X_ALERT_STATUS_REGISTER, *PAC194X5X_PALERT_STATUS_REGISTER;
//field position in the register MSB
#define PAC194X5X_ALERT_CH1OC_BITPOS      7
#define PAC194X5X_ALERT_CH2OC_BITPOS      6
#define PAC194X5X_ALERT_CH3OC_BITPOS      5
#define PAC194X5X_ALERT_CH4OC_BITPOS      4
#define PAC194X5X_ALERT_CH1UC_BITPOS      3
#define PAC194X5X_ALERT_CH2UC_BITPOS      2
#define PAC194X5X_ALERT_CH3UC_BITPOS      1
#define PAC194X5X_ALERT_CH4UC_BITPOS      0
//field position in the register MiddleByte
#define PAC194X5X_ALERT_CH1OV_BITPOS      7
#define PAC194X5X_ALERT_CH2OV_BITPOS      6
#define PAC194X5X_ALERT_CH3OV_BITPOS      5
#define PAC194X5X_ALERT_CH4OV_BITPOS      4
#define PAC194X5X_ALERT_CH1UV_BITPOS      3
#define PAC194X5X_ALERT_CH2UV_BITPOS      2
#define PAC194X5X_ALERT_CH3UV_BITPOS      1
#define PAC194X5X_ALERT_CH4UV_BITPOS      0
//field position in the register LSB
#define PAC194X5X_ALERT_CH1OP_BITPOS      7
#define PAC194X5X_ALERT_CH2OP_BITPOS      6
#define PAC194X5X_ALERT_CH3OP_BITPOS      5
#define PAC194X5X_ALERT_CH4OP_BITPOS      4
#define PAC194X5X_ALERT_ACCOVF_BITPOS     3
#define PAC194X5X_ALERT_ACCCNT_BITPOS     2
#define PAC194X5X_ALERT_CC_BITPOS         1
#define PAC194X5X_ALERT_BITMASK           0x01

typedef struct _PAC194X5X_ALERT_REGISTER {
// register MSB
    unsigned char CH1_OC    : 1;
    unsigned char CH2_OC    : 1;
    unsigned char CH3_OC    : 1;
    unsigned char CH4_OC    : 1;
    unsigned char CH1_UC    : 1;
    unsigned char CH2_UC    : 1;
    unsigned char CH3_UC    : 1;
    unsigned char CH4_UC    : 1;
// register MiddleByte
    unsigned char CH1_OV    : 1;
    unsigned char CH2_OV    : 1;
    unsigned char CH3_OV    : 1;
    unsigned char CH4_OV    : 1;
    unsigned char CH1_UV    : 1;
    unsigned char CH2_UV    : 1;
    unsigned char CH3_UV    : 1;
    unsigned char CH4_UV    : 1;
// register LSB
    unsigned char CH1_OP    : 1;
    unsigned char CH2_OP    : 1;
    unsigned char CH3_OP    : 1;
    unsigned char CH4_OP    : 1;
    unsigned char ACC_OVF   : 1;
    unsigned char ACC_COUNT : 1;
    unsigned char ALERT_CCx : 1;
} PAC194X5X_ALERT_REGISTER, *PAC194X5X_PALERT_REGISTER;


typedef struct _PAC194X5X_ACCUM_LIMITS_REGISTER {
// register MSB
    unsigned char ACC_CH1   : 2;    
    unsigned char ACC_CH2   : 2;
    unsigned char ACC_CH3   : 2;
    unsigned char ACC_CH4   : 2;
// register LSB
    unsigned char ACC_COUNT : 2;
} PAC194X5X_ACCUM_LIMITS_REGISTER, *PAC194X5X_PACCUM_LIMITS_REGISTER;
#define PAC194X5X_ACCLIMITS_CH1_BITPOS    6 //field position in the register MSB
#define PAC194X5X_ACCLIMITS_CH2_BITPOS    4 //field position in the register MSB
#define PAC194X5X_ACCLIMITS_CH3_BITPOS    2 //field position in the register MSB
#define PAC194X5X_ACCLIMITS_CH4_BITPOS    0 //field position in the register MSB
#define PAC194X5X_ACCLIMITS_COUNT_BITPOS  6 //field position in the register LSB
#define PAC194X5X_ACCLIMITS_BITMASK       0x03
#define PAC194X5X_ACCLIMITS_FULL    0b00
#define PAC194X5X_ACCLIMITS_15BY16  0b01
#define PAC194X5X_ACCLIMITS_7BY8    0b10
#define PAC194X5X_ACCLIMITS_3BY4    0b11

typedef struct _PAC194X5X_LIMIT_NSAMPLES_REGISTER {
    unsigned char Nsamples_CH1 : 2;
    unsigned char Nsamples_CH2 : 2;
    unsigned char Nsamples_CH3 : 2;
    unsigned char Nsamples_CH4 : 2;
} PAC194X5X_LIMIT_NSAMPLES_REGISTER, *PAC194X5X_PLIMIT_NSAMPLES_REGISTER;
#define PAC194X5X_LIMITNSAMP_CH1_BITPOS    6
#define PAC194X5X_LIMITNSAMP_CH2_BITPOS    4
#define PAC194X5X_LIMITNSAMP_CH3_BITPOS    2
#define PAC194X5X_LIMITNSAMP_CH4_BITPOS    0
#define PAC194X5X_LIMITNSAMP_BITMASK       0x03
#define PAC194X5X_LIMITNSAMP_01    0b00
#define PAC194X5X_LIMITNSAMP_04    0b01
#define PAC194X5X_LIMITNSAMP_08    0b10
#define PAC194X5X_LIMITNSAMP_16    0b11

/* !!! WARNING !!!
 * The device context structure is initialized by PAC194x5x_Device_Initialize() function call
 */ 

typedef struct _PAC194X5X_DEVICE_CONTEXT
{
    // mutexProcState mutex helps to avoid concurrent processingState changes 
    // from "Idle" to a request processing state or from a request processing state back to "Idle"/"Sync".
    // (e.g. avoid new device request until the current one is completed)
    PAC194X5X_MUTEX mutexProcState;

    volatile PAC194X5X_procState processingState;
    volatile PAC194X5X_EVENT deviceEventStatus;   //to be reset every time a new request is initiated 
    
    PAC194X5X_I2C_PARAMS i2cParams;
    PAC194X5X_I2C_TRANSFER_HANDLE transferHandle;
    PAC194X5X_I2C_TRANSFER_HANDLE transferHandle_ctrl;
    PAC194X5X_I2C_TRANSFER_HANDLE transferHandle_negPwr;
    PAC194X5X_I2C_TRANSFER_HANDLE transferHandle_accumConfig;
    PAC194X5X_I2C_TRANSFER_HANDLE transferHandle_accCount;

    PAC194X5X_EVENT_HANDLER userCallback;
    uintptr_t             userContext;
    bool syncMode;  // if TRUE, the library functions will be blocking functions
    
    uint8_t i2cTxBuffer[PAC194X5X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_ctrl[PAC194X5X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_negPwr[PAC194X5X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_accumConfig[PAC194X5X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_accCount[PAC194X5X_I2C_TX_MAXSIZE];
    uint8_t i2cRxBuffer[PAC194X5X_I2C_RX_MAXSIZE + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_ctrl[PAC194X5X_CTRL_SZ + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_negPwr[PAC194X5X_NEGPWRFSR_SZ + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_accumConfig[PAC194X5X_ACCUMCONFIG_SZ + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_accCount[PAC194X5X_ACC_COUNT_SZ + SMBUS_BYTECNT];

    //copy the requested data in the user buffer;     
    void *outData;
    uint8_t channelNo;
    uint32_t time;
    
    uint8_t HwChannels;
    uint8_t LowSide;
    uint16_t VbusFSR;
    uint16_t VsenseFSR;
    uint16_t VPowerFSR;
    
    // Voltage divider ratios (ratio = Vrail / Vbus) used to determine the rail voltage (Vrail)
    // from the measured Vbus with the PAC194x/5x-2 devices ("low-side" connected devices). 
    // The voltage divider ratios are ignored by the PAC194x/5x-1 "high-side" devices.  
    float VrailToVbusRatio[PAC194X5X_MAX_CH_COUNT];
        
    // Sense resistor values, expressed in micro-Ohm units.
    uint32_t rsense[PAC194X5X_MAX_CH_COUNT];
    
    // cached BYTE_COUNT flag from the CHANNEL DIS and SMBUS register,
    // kept in sync by PAC194x5x_SetChannelDisSMBus_reg() and PAC194x5x_GetChannelDisSMBus_reg()
    bool ENABLE_BYTE_COUNT_FLAG;

    //cached channel scale values
    //"sign" depends on negPwr configuration
    //the cache must be marked "Invalid" by any "Refresh/V/G" or by "PAC194x5x_SetNegPwr_reg()"
    float IsenseLSB[PAC194X5X_MAX_CH_COUNT];            //Isense LSB unit;
    float VPowerLSB[PAC194X5X_MAX_CH_COUNT];            //VPower LSB unit;
    uint16_t VbusScale[PAC194X5X_MAX_CH_COUNT];         //VbusScale;
    uint16_t VsenseScale[PAC194X5X_MAX_CH_COUNT];       //VsenseScale;
    uint16_t VPowerScale[PAC194X5X_MAX_CH_COUNT];       //VPowerScale;
    uint8_t  IsSignedPower[PAC194X5X_MAX_CH_COUNT];     //IsSignedPower;
    uint8_t  IsSignedVbus[PAC194X5X_MAX_CH_COUNT];      //Vbus is signed
    uint8_t  IsSignedVsense[PAC194X5X_MAX_CH_COUNT];    //Vsense is signed
    bool ScaleValues_cached[PAC194X5X_MAX_CH_COUNT];    //the computed scale values are valid or not

    //cached device registers   
    PAC194X5X_deviceID deviceID;                        //updated by the PAC194x5x_GetDeviceID() function call
    PAC194X5X_CTRL_REGISTER ctrl_LAT;                   //updated by the PAC194x5x_GetCtrl_reg() function call
    PAC194X5X_NEG_PWR_FSR_REGISTER negPwrFsr_LAT;       //updated by the PAC194x5x_GetNegPwrFsr_reg() function call
    PAC194X5X_ACCUM_CONFIG_REGISTER accumConfig_LAT;    //updated by the PAC194x5x_GetAccumConfig_reg() function call
    uint32_t accCount;
    
    //cached validity flags
    bool deviceID_cached;
    bool ctrl_LAT_cached;
    bool negPwr_LAT_cached;
    bool accumConfig_LAT_cached;
    bool accCount_cached;
    
    uint8_t *accMode;
    
    int16_t processError;
        
} PAC194X5X_DEVICE_CONTEXT, *PAC194X5X_PDEVICE_CONTEXT;

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	// _PAC194X_5X_TYPES_H

/**
  End of File
*/
