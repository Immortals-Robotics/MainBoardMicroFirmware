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

#ifndef PAC194X5X_MUTEX_H
#define PAC194X5X_MUTEX_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Target platform adaptation data types and services
 */    

typedef uint8_t PAC194X5X_MUTEX;

/* MUTEX support functions */

static inline bool PAC194x5x_MUTEX_Create(PAC194X5X_MUTEX *pmutex){
        return true;
}

static inline bool PAC194x5x_MUTEX_Lock(PAC194X5X_MUTEX *pmutex){
        return true;
}

static inline void PAC194x5x_MUTEX_Unlock(PAC194X5X_MUTEX *pmutex){
}

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	// _PAC194X_5X_MUTEX_H

/**
  End of File
*/
