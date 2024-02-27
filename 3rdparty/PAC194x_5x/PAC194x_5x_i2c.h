/*
  � 2022 Microchip Technology Inc. and its subsidiaries

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

#ifndef PAC194X5X_I2C_H
#define PAC194X5X_I2C_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/**
    Section: Included Files
*/
//#include <string.h>

///////////////////////////////////////////////////////////////////////////////
/*
 * Target platform adaptation data types and services
 */    
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define PAC194X5X_CLIENT_ADDRESS 0x10 // this is the default addres for PIM click

typedef uint8_t PAC194X5X_I2C_TRANSFER_HANDLE;    // uintptr_t
typedef i2c_inst_t*              PAC194X5X_I2C_HANDLE;             // uintptr_t
    
#define PAC194X5X_I2C_HANDLE_INVALID          NULL
#define PAC194X5X_I2C_TRANSFER_HANDLE_INVALID (~0)

typedef enum
{
    /* Transfer request is pending */
    PAC194X5X_I2C_TRANSFER_EVENT_PENDING = 0,

    /* All data from or to the buffer was transferred successfully. */
    PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE = 1,

    /* Transfer Handle given is expired. It means transfer
    is completed but with or without error is not known. */
    PAC194X5X_I2C_TRANSFER_EVENT_HANDLE_EXPIRED = 2,

    /* There was an error while processing the buffer transfer request. */
    PAC194X5X_I2C_TRANSFER_EVENT_ERROR = 3
} PAC194X5X_I2C_TRANSFER_EVENT;

typedef void ( PAC194X5X_I2C_TRANSFER_EVENT_HANDLER )( PAC194X5X_I2C_TRANSFER_EVENT event, PAC194X5X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context );
typedef void ( *PAC194X5X_P_I2C_TRANSFER_EVENT_HANDLER )( PAC194X5X_I2C_TRANSFER_EVENT event, PAC194X5X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context );

typedef struct _PAC194X5X_I2C_PARAMS{
    PAC194X5X_I2C_HANDLE i2cHandle;
    uint16_t i2cAddress;
    PAC194X5X_P_I2C_TRANSFER_EVENT_HANDLER pI2CEventHandler;
    uintptr_t pi2cEventHandlerContext;
}PAC194X5X_I2C_PARAMS, *PAC194X5X_PI2C_PARAMS;

/*
 * Target platform adaptation functions 
 */

static inline PAC194X5X_I2C_TRANSFER_HANDLE get_next_handle(){
    static PAC194X5X_I2C_TRANSFER_HANDLE handle = 0;
    handle = (handle + 1) % PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    return handle;
}

static inline PAC194X5X_I2C_TRANSFER_EVENT PAC194x5x_I2C_TransferStatusGet(
    const PAC194X5X_I2C_TRANSFER_HANDLE transferHandle
){
    return PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE;
};

static inline void PAC194x5x_I2C_WriteReadTransferAdd (
    const PAC194X5X_I2C_PARAMS i2cParams,
    void* const writeBuffer,
    const size_t writeSize,
    void* const readBuffer,
    const size_t readSize,
    PAC194X5X_I2C_TRANSFER_HANDLE* const transferHandle
){
    *transferHandle = get_next_handle();

    const int written_count = i2c_write_blocking(i2cParams.i2cHandle, i2cParams.i2cAddress, (uint8_t*)writeBuffer, writeSize, true);
    const int read_count = i2c_read_blocking(i2cParams.i2cHandle, i2cParams.i2cAddress, (uint8_t*)readBuffer, readSize, false);
    
    sleep_ms(1);

    PAC194X5X_I2C_TRANSFER_EVENT event;
    if (written_count == PICO_ERROR_GENERIC || read_count == PICO_ERROR_GENERIC){
        event = PAC194X5X_I2C_TRANSFER_EVENT_ERROR;
    }else{
        event = PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE;
    }

    (i2cParams.pI2CEventHandler)(PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE, *transferHandle, i2cParams.pi2cEventHandlerContext);
};

static inline void PAC194x5x_I2C_WriteTransferAdd(
    const PAC194X5X_I2C_PARAMS i2cParams,
    void* const buffer,
    const size_t size,
    PAC194X5X_I2C_TRANSFER_HANDLE* const transferHandle
){
    *transferHandle = get_next_handle();

    const int written_count = i2c_write_blocking(i2cParams.i2cHandle, i2cParams.i2cAddress, (uint8_t*)buffer, size, false);
    
    sleep_ms(1);

    PAC194X5X_I2C_TRANSFER_EVENT event;
    if (written_count == PICO_ERROR_GENERIC){
        event = PAC194X5X_I2C_TRANSFER_EVENT_ERROR;
    } else{
        event = PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE;
    }

    (i2cParams.pI2CEventHandler)(event, *transferHandle, i2cParams.pi2cEventHandlerContext);
}

static inline void PAC194x5x_I2C_TransferEventHandlerSet(
    const PAC194X5X_PI2C_PARAMS pi2cParams,
    const PAC194X5X_P_I2C_TRANSFER_EVENT_HANDLER eventHandler,
    const uintptr_t context
){
    pi2cParams->pI2CEventHandler = eventHandler;
    pi2cParams->pi2cEventHandlerContext = context;
    return;
}

static inline PAC194X5X_I2C_HANDLE PAC194x5_I2C_Open(
){
    return i2c0;
}

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	// _PAC194X_5X_I2C_H

/**
  End of File
*/
