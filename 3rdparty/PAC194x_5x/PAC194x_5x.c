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

#include "PAC194x_5x.h"

int16_t PAC194x5x_GetDeviceIDProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetCtrl_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetAccumulatorCountProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVACCn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVACCnProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetEnergy_mWhProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetTimedEnergy_mWhProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetCoulomb_mAsProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetTimedCoulomb_mAsProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVBUSn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVBUSn_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVSENSEn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVSENSEn_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetISENSEn_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVBUSn_AVG_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVBUSn_AVG_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVSENSEn_AVG_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVSENSEn_AVG_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetISENSEn_AVG_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVPOWERn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetVPOWERn_mWProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetSMBusSettings_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_SetSMBusSettings_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetNegPwrFsr_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetSlow_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetAccumConfig_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetAlertStatus_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetAlert_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetAccFullness_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOClimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOClimit_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetUClimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetUClimit_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOPlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOPlimit_mWProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOVlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetOVlimit_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetUVlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetUVlimit_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_GetLimitNsamplesProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);


int16_t PAC194x5x_UpdateContext_ChannelPolarity(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_UpdateContext_ChannelPolarityProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);

int16_t PAC194x5x_UpdateContext_Ctrl(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_UpdateContext_CtrlProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);

int16_t PAC194x5x_UpdateContext_AccumConfig(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_UpdateContext_AccumConfigProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);

int16_t PAC194x5x_UpdateContext_AccumulatorCount(PAC194X5X_PDEVICE_CONTEXT pdevice);
int16_t PAC194x5x_UpdateContext_AccumulatorCountProcess(PAC194X5X_PDEVICE_CONTEXT pdevice);

void PAC194x5x_I2CEventHandler(PAC194X5X_I2C_TRANSFER_EVENT event, PAC194X5X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context);

///////////////////////////////////////////////////////////////////////////////

/*
 * Library functions, target platform independent 
 */

void PAC194x5x_Timeout(uintptr_t deviceContext){

    // lock the mutexProcState mutex
    if( PAC194x5x_MUTEX_Lock(&(((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC194x5x_I2CEventHandler or PAC194x5x_I2CEventHandlerError)
    if( (((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->processingState == Idle) || 
        (((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->processingState == Sync)  ){
        
        PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->mutexProcState));
        return;
    }
    
    // drop any remaining i2c transfers from the current lib request
    ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->transferHandle              = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->transferHandle_negPwr       = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->transferHandle_ctrl         = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->transferHandle_accumConfig  = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->transferHandle_accCount     = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    // advance the state machine to "Idle" or "Sync"
    if ( ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->syncMode == true){
        ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->processingState = Sync;
    }else
    {    
        ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->processingState = Idle;
    }
   
    // call the user call-back if there is one registered
    if(((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->userCallback != NULL){
        PAC194X5X_EVENT_HANDLER userCallback;
        PAC194X5X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->userCallback;
        ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->deviceEventStatus = PAC194X5X_EVENT_TIMEOUT;
        event = ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->deviceEventStatus;
        userContext = ((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->userContext;
        userCallback(event, userContext);
    }
    
    // unlock the mutexProcState mutex
    PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)deviceContext)->mutexProcState));
}


/* !!!  PAC194x5x_I2CEventHandlerError must not be called outside of PAC194x5x_I2CEventHandler() !!! */
void PAC194x5x_I2CEventHandlerError(uintptr_t context){

    // lock the mutexProcState mutex
    if( PAC194x5x_MUTEX_Lock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC194x5x_Timeout)
    if( (((PAC194X5X_PDEVICE_CONTEXT)context)->processingState == Idle) || 
        (((PAC194X5X_PDEVICE_CONTEXT)context)->processingState == Sync)  ){
        
        PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState));
        return;
    }
    
    // drop any remaining i2c transfers from the current lib request
    ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle                    = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr             = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl               = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig        = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accCount           = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    // advance the state machine to "Idle" 
    if ( ((PAC194X5X_PDEVICE_CONTEXT)context)->syncMode == true){
        ((PAC194X5X_PDEVICE_CONTEXT)context)->processingState = Sync;
    }else
    {    
        ((PAC194X5X_PDEVICE_CONTEXT)context)->processingState = Idle;
    }
   
    // call the user call-back if there is one registered
    if(((PAC194X5X_PDEVICE_CONTEXT)context)->userCallback != NULL){
        PAC194X5X_EVENT_HANDLER userCallback;
        PAC194X5X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC194X5X_PDEVICE_CONTEXT)context)->userCallback;
        event = ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus;
        userContext = ((PAC194X5X_PDEVICE_CONTEXT)context)->userContext;
        userCallback(event, userContext);
    }
    
    // unlock the mutexProcState mutex
    PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState));
}


void PAC194x5x_I2CEventHandler(PAC194X5X_I2C_TRANSFER_EVENT event, PAC194X5X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context)
{
    int16_t *retPtr;
    
    if(context == 0){ 
        return;
    }
    
    if( (((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accCount == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID) ) 
    {
        return; // ignore the remaining i2c transfers (if any) for the invalidated requests due to previous errors
    }
    
    retPtr = &((PAC194X5X_PDEVICE_CONTEXT)context)->processError;
    *retPtr = PAC194X5X_SUCCESS;
    
    // handles the I2C events:        
    switch(event)
    {
        case PAC194X5X_I2C_TRANSFER_EVENT_PENDING:
            return;
        
        case PAC194X5X_I2C_TRANSFER_EVENT_COMPLETE:
        /* I2C Transfer Complete. */
        ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_COMPLETE;
        
            switch((((PAC194X5X_PDEVICE_CONTEXT)context)->processingState))
            {
                case RefreshReq:
                case RefreshGReq:
                case RefreshVReq:
                    break;
                case GetDeviceIDReq:
                    PAC194x5x_GetDeviceIDProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetCtrlRegisterReq:
                    PAC194x5x_GetCtrl_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case SetCtrlRegisterReq:
                    break;
                case GetAccCountReq:
                    PAC194x5x_GetAccumulatorCountProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVACCnRegisterReq:
                    PAC194x5x_GetVACCn_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;                    
                case GetVACCnValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig){
                        *retPtr = PAC194x5x_UpdateContext_AccumConfigProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVACCnProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }
                    }
                    break;
                case GetEnergyReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC194x5x_UpdateContext_CtrlProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig){
                        *retPtr = PAC194x5x_UpdateContext_AccumConfigProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetEnergy_mWhProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetTimedEnergyReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC194x5x_UpdateContext_CtrlProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr) {
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig){
                        *retPtr = PAC194x5x_UpdateContext_AccumConfigProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accCount){
                        *retPtr = PAC194x5x_UpdateContext_AccumulatorCountProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetTimedEnergy_mWhProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetCoulombReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC194x5x_UpdateContext_CtrlProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig){
                        *retPtr = PAC194x5x_UpdateContext_AccumConfigProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetCoulomb_mAsProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetTimedCoulombReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC194x5x_UpdateContext_CtrlProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr) {
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accumConfig){
                        *retPtr = PAC194x5x_UpdateContext_AccumConfigProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_accCount){
                        *retPtr = PAC194x5x_UpdateContext_AccumulatorCountProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetTimedCoulomb_mAsProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVBUSnRegisterReq:
                    PAC194x5x_GetVBUSn_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVBUSnValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVBUSn_mVProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVSENSEnRegisterReq:
                    PAC194x5x_GetVSENSEn_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVSENSEnValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVSENSEn_mVProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetISENSEnValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetISENSEn_mAProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVBUSnAVGRegisterReq:
                    PAC194x5x_GetVBUSn_AVG_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVBUSnAVGValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVBUSn_AVG_mVProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVSENSEnAVGRegisterReq:
                    PAC194x5x_GetVSENSEn_AVG_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVSENSEnAVGValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVSENSEn_AVG_mVProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetISENSEnAVGValueReq:                    
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetISENSEn_AVG_mAProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVPOWERnRegisterReq:
                    PAC194x5x_GetVPOWERn_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case GetVPOWERnValueReq:
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        *retPtr = PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if(*retPtr == PAC194X5X_SUCCESS) {
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC194X5X_PDEVICE_CONTEXT)context)->transferHandle){
                        *retPtr = PAC194x5x_GetVPOWERn_mWProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                        if (*retPtr != PAC194X5X_SUCCESS){
                            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_REQUEST_ERROR;
                            PAC194x5x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetSMBusRegisterReq:
                    PAC194x5x_GetSMBusSettings_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case SetSMBusRegisterReq:
                    PAC194x5x_SetSMBusSettings_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetNegPWRFSRRegisterReq:
                    PAC194x5x_GetNegPwrFsr_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case SetNegPWRFSRRegisterReq:
                    break;
                case GetSlowRegisterReq:
                    PAC194x5x_GetSlow_regProcess((PAC194X5X_PDEVICE_CONTEXT)context);
                    break;
                case SetSlowRegisterReq:
                    break;
                case GetAccumConfigRegisterReq:
                    PAC194x5x_GetAccumConfig_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetAccumConfigRegisterReq:
                    break;
                case GetAlertStatusRegisterReq:
                    PAC194x5x_GetAlertStatus_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetAlertEnableRegisterReq:
                    PAC194x5x_GetAlert_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetAlertEnableRegisterReq:
                    break;
                case GetSlowAlert1RegisterReq:
                    PAC194x5x_GetAlert_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetSlowAlert1RegisterReq:
                    break;
                case GetGpioAlert2RegisterReq:
                    PAC194x5x_GetAlert_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetGpioAlert2RegisterReq:
                    break;
                case GetAccFullnessRegisterReq:
                    PAC194x5x_GetAccFullness_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetAccFullnessRegisterReq:
                    break;
                case GetOClimitRegisterReq:
                    PAC194x5x_GetOClimit_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetOClimitValueReq:
                    PAC194x5x_GetOClimit_mAProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetOClimitRegisterReq:
                    break;
                case SetOClimitValueReq:
                    break;
                case GetUClimitRegisterReq:
                    PAC194x5x_GetUClimit_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetUClimitValueReq:
                    PAC194x5x_GetUClimit_mAProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetUClimitRegisterReq:
                    break;
                case SetUClimitValueReq:
                    break;
                case GetOPlimitRegisterReq:
                    PAC194x5x_GetOPlimit_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetOPlimitValueReq:
                    PAC194x5x_GetOPlimit_mWProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetOPlimitRegisterReq:
                    break;
                case SetOPlimitValueReq:
                    break;
                case GetOVlimitRegisterReq:
                    PAC194x5x_GetOVlimit_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetOVlimitValueReq:
                    PAC194x5x_GetOVlimit_mVProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetOVlimitRegisterReq:
                    break;
                case SetOVlimitValueReq:
                    break;
                case GetUVlimitRegisterReq:
                    PAC194x5x_GetUVlimit_regProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case GetUVlimitValueReq:
                    PAC194x5x_GetUVlimit_mVProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetUVlimitRegisterReq:
                    break;
                case SetUVlimitValueReq:
                    break;
                case GetLimitNsamplesRegisterReq:
                    PAC194x5x_GetLimitNsamplesProcess((PAC194X5X_PDEVICE_CONTEXT) context);
                    break;
                case SetLimitNsamplesRegisterReq:
                    break;

                default:
                    //we are in either IDLE, SYNC or Uninitialized
                    return; // we should ignore this i2c transfer, nobody waits for it
            }
        break;
        
        case PAC194X5X_I2C_TRANSFER_EVENT_ERROR:
            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_TRANSFER_ERROR;
            PAC194x5x_I2CEventHandlerError(context);
            return;
        case PAC194X5X_I2C_TRANSFER_EVENT_HANDLE_EXPIRED:        
        // to be safe we should handle this as unknown error (like "DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID")
        // the error code comment is: "Transfer Handle given is expired. 
        // It means transfer is completed but with or without error is not known."
        default:
            // - DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID
            ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC194X5X_EVENT_UNKNOWN_ERROR;
            PAC194x5x_I2CEventHandlerError(context);
            return;
    }
    
    // Lock the mutexProcState mutex
    if( PAC194x5x_MUTEX_Lock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC194x5x_Timeout)
    if( (((PAC194X5X_PDEVICE_CONTEXT)context)->processingState == Idle) || 
        (((PAC194X5X_PDEVICE_CONTEXT)context)->processingState == Sync)  ){
        
        PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState));
        return;
    }    
    
    // advance the state machine to "Idle" or "Sync"
    if ( ((PAC194X5X_PDEVICE_CONTEXT)context)->syncMode == true){
        ((PAC194X5X_PDEVICE_CONTEXT)context)->processingState = Sync;
    }else
    {    
        ((PAC194X5X_PDEVICE_CONTEXT)context)->processingState = Idle;
    }
   
    // call the user call-back if there is one registered
    if(((PAC194X5X_PDEVICE_CONTEXT)context)->userCallback != NULL){
        PAC194X5X_EVENT_HANDLER userCallback;
        PAC194X5X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC194X5X_PDEVICE_CONTEXT)context)->userCallback;
        event = ((PAC194X5X_PDEVICE_CONTEXT)context)->deviceEventStatus;
        userContext = ((PAC194X5X_PDEVICE_CONTEXT)context)->userContext;
        userCallback(event, userContext);
    }
    
    // Unlock the Timeout mutex
    PAC194x5x_MUTEX_Unlock(&(((PAC194X5X_PDEVICE_CONTEXT)context)->mutexProcState));
    
}


bool PAC194x5x_Device_IsInitialized(PAC194X5X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL){ 
        return false;   // return "false" if pdevice is NULL
    }else{
        return (pdevice->processingState != Uninitialized);
    }
}


bool PAC194x5x_Device_IsBusy(PAC194X5X_PDEVICE_CONTEXT pdevice){
    bool deviceIsBusy = false;
    bool i2cIsBusy = false;
    
    if (pdevice == NULL) return true;   // return "true" is pdevice is NULL

    if ( PAC194X5X_I2C_TRANSFER_EVENT_PENDING == PAC194x5x_I2C_TransferStatusGet(pdevice->transferHandle) ||
     PAC194X5X_I2C_TRANSFER_EVENT_PENDING == PAC194x5x_I2C_TransferStatusGet(pdevice->transferHandle_ctrl) || 
     PAC194X5X_I2C_TRANSFER_EVENT_PENDING == PAC194x5x_I2C_TransferStatusGet(pdevice->transferHandle_negPwr) ||
     PAC194X5X_I2C_TRANSFER_EVENT_PENDING == PAC194x5x_I2C_TransferStatusGet(pdevice->transferHandle_accCount) ||
     PAC194X5X_I2C_TRANSFER_EVENT_PENDING == PAC194x5x_I2C_TransferStatusGet(pdevice->transferHandle_accumConfig)  )         
    {
        i2cIsBusy = true;
    }
    
    if( (i2cIsBusy == true) || (pdevice->processingState != Idle) )
    {
        deviceIsBusy = true; 
    }
    return deviceIsBusy;
}


int16_t PAC194x5x_Device_Initialize(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_DEVICE_INIT deviceInit) {
    int16_t errorCode = PAC194X5X_SUCCESS;
    int i;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    //step 1 - initialize the device context
    memset(pdevice, 0, sizeof(PAC194X5X_DEVICE_CONTEXT));

    // Create the processingState mutex
    if( PAC194x5x_MUTEX_Create(&(pdevice->mutexProcState)) == false )
    {
        return PAC194X5X_MUTEX_INVALID;
    }
    
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    pdevice->processingState = Uninitialized;
    pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
    
    //step2 - configure the I2C communication
    (pdevice->i2cParams).i2cAddress = deviceInit.i2cAddress;
    (pdevice->i2cParams).i2cHandle = deviceInit.i2cHandle;
    
    if ((pdevice->i2cParams).i2cHandle != PAC194X5X_I2C_HANDLE_INVALID)
    {
        /* Register I2C transfer complete Event Handler for this device */
        
        PAC194x5x_I2C_TransferEventHandlerSet(&(pdevice->i2cParams), PAC194x5x_I2CEventHandler, (uintptr_t)pdevice);
    }
    else
    {
        /* Handle error */
        errorCode = PAC194X5X_I2C_INVALID_PARAM;
        goto initialize_error;
    }

    //step3 - set the initial device configuration
    
    //NOTE: use synchronous communication for the device initial configuration.
    //reset the device configuration (similar to POR)
    pdevice->syncMode = true;
    pdevice->processingState = Idle; // set the state machine to Idle to allow function calls
    
    //unlock the processingState mutex
    PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
    
    pdevice->ENABLE_BYTE_COUNT_FLAG = false;
    //initialize the cached registers in the device context
    pdevice->deviceID_cached = false;
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    pdevice->accumConfig_LAT_cached = false;
    pdevice->accCount_cached = false;
    
    for (i=0; i<PAC194X5X_MAX_CH_COUNT; i++){
        pdevice->ScaleValues_cached[i] = false;
    }
    
    //make sure that the I2C protocol is set to default configuration: I2C version (not SMBUS)
    // Configure SMBUS_SETTINGS - 0x10
    PAC194X5X_SMBUS_SETTINGS_REGISTER SMBus;
    SMBus.GPIO_DATA2 = 0b0;
    SMBus.GPIO_DATA1 = 0b0;
    SMBus.ANY_ALERT = 0b0;
    SMBus.POR = 0b1;    //keep the flag value as is
    SMBus.TIMEOUT = 0b0;
    SMBus.BYTE_COUNT = 0b0;
    SMBus.NO_SKIP = 0b0;
    SMBus.I2C_HISPEED = 0b0;
    errorCode = PAC194x5x_SetSMBusSettings_reg(pdevice, SMBus);
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
    
    //initialize the VrailToVbusRatio vector
    for(i = 0; i < PAC194X5X_MAX_CH_COUNT; i++){
        pdevice->VrailToVbusRatio[i] = 1.0;
    }
    
    //read and store the device IDs in the device context
    errorCode = PAC194x5x_GetDeviceID(pdevice, &(pdevice->deviceID)); 
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
    
    //set the device specific properties in the device context
    pdevice->VsenseFSR = 100;           //milliVolts
    
    switch (pdevice->deviceID.product){
        //PAC194x family
        case 0b01101000:{               //0x68 - PAC1941
            pdevice->HwChannels  = 1;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            break;
        }
        case 0b01101001:{               //0x69 - PAC1942
            pdevice->HwChannels  = 2;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            break;
        }
        case 0b01101010:{               //0x6A - PAC1943
            pdevice->HwChannels  = 3;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            break;
        }
        case 0b01101011:{               //0x6B - PAC1944
            pdevice->HwChannels  = 4;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            break;
        }
        case 0b01101100:{               //0x6C - PAC1941-2
            pdevice->HwChannels  = 1;
            pdevice->LowSide     = 1;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            pdevice->VrailToVbusRatio[0] = deviceInit.VrailToVbusRatio[0];
            break;
        }
        case 0b01101101:{               //0x6D - PAC1942-2
            pdevice->HwChannels  = 2;
            pdevice->LowSide     = 1;
            pdevice->VbusFSR     = 9000;  //milliVolts
            pdevice->VPowerFSR   = 900;   //milli-Volt^2
            pdevice->VrailToVbusRatio[0] = deviceInit.VrailToVbusRatio[0];
            pdevice->VrailToVbusRatio[1] = deviceInit.VrailToVbusRatio[1];
            break;
        }
        
        //PAC195x family
        case 0b01111000:{               //0x78 - PAC1951
            pdevice->HwChannels  = 1;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            break;
        }
        case 0b01111001:{               //0x79 - PAC1952
            pdevice->HwChannels  = 2;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            break;
        }
        case 0b01111010:{               //0x7A - PAC1953
            pdevice->HwChannels  = 3;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            break;
        }
        case 0b01111011:{               //0x7B - PAC1954
            pdevice->HwChannels  = 4;
            pdevice->LowSide     = 0;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            break;
        }
        case 0b01111100:{               //0x7C - PAC1951-2
            pdevice->HwChannels  = 1;
            pdevice->LowSide     = 1;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            pdevice->VrailToVbusRatio[0] = deviceInit.VrailToVbusRatio[0];
            break;
        }
        case 0b01111101:{               //0x7D - PAC1952-2
            pdevice->HwChannels  = 2;
            pdevice->LowSide     = 1;
            pdevice->VbusFSR     = 32000; //milliVolts
            pdevice->VPowerFSR   = 3200;  //milli-Volt^2
            pdevice->VrailToVbusRatio[0] = deviceInit.VrailToVbusRatio[0];
            pdevice->VrailToVbusRatio[1] = deviceInit.VrailToVbusRatio[1];
            break;
        }
        default:
            errorCode = PAC194X5X_INVALID_DEVICE;
            return errorCode;
    }
    
    for(i = 0; i < PAC194X5X_MAX_CH_COUNT; i++){
        float PowerLSB;
        float IsenseLSB;
        
        pdevice->rsense[i] = deviceInit.rsense[i];        
        //IsenseLSB
        if(deviceInit.rsense[i] != 0){
            IsenseLSB = (float)(pdevice->VsenseFSR) * 1000000.0 / 65536.0;   // 1000000 due to rsense uOhm scale
            IsenseLSB /= (float)deviceInit.rsense[i];
        }else{
            IsenseLSB = 0.0;
        }
        pdevice->IsenseLSB[i] = (float)IsenseLSB;
        
        //PowerLSB
        if(deviceInit.rsense[i] != 0){
            PowerLSB = (float)(pdevice->VPowerFSR) * 1000000.0 / (float)0x10000000; // 1000000 due to rsense uOhm scale
            PowerLSB /= (float)deviceInit.rsense[i];

        }else{
            PowerLSB = 0.0;
        }
        pdevice->VPowerLSB[i] = PowerLSB;
    }
        
    // Configure CTRL - 0x0700
    PAC194X5X_CTRL_REGISTER Ctrl;
    Ctrl.SAMPLE_MODE = 0b0000;
    Ctrl.GPIO_ALERT2 = 0b01;
    Ctrl.SLOW_ALERT1 = 0b11;
    Ctrl.CH1_OFF     = 0b0;
    Ctrl.CH2_OFF     = 0b0;
    Ctrl.CH3_OFF     = 0b0;
    Ctrl.CH4_OFF     = 0b0;
    errorCode = PAC194x5x_SetCtrl_reg(pdevice, Ctrl);    
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
  
    // Configure NEG_PWR_FSR - 0x0000
    PAC194X5X_NEG_PWR_FSR_REGISTER NegPwr;
    NegPwr.CFG_VS1 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VS2 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VS3 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VS4 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VB1 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VB2 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VB3 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    NegPwr.CFG_VB4 = PAC194X5X_NEGPWRFSR_MODE_UNIPOLAR;
    errorCode = PAC194x5x_SetNegPwrFsr_reg(pdevice, NegPwr);    
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;   

    // Configure SLOW - 0x00
    PAC194X5X_SLOW_REGISTER Slow;
    Slow.RefreshRise  = 0b0;
    Slow.RefreshVRise = 0b0;
    Slow.RefreshFall  = 0b0;
    Slow.RefreshVFall = 0b0;
    errorCode = PAC194x5x_SetSlow_reg(pdevice, Slow);
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
    
    // Configure ACCUM_CONFIG - 0x00
    PAC194X5X_ACCUM_CONFIG_REGISTER AccCfg;
    AccCfg.ACC1_CONFIG = PAC194X5X_ACCCFG_MODE_VPOWER;
    AccCfg.ACC2_CONFIG = PAC194X5X_ACCCFG_MODE_VPOWER;
    AccCfg.ACC3_CONFIG = PAC194X5X_ACCCFG_MODE_VPOWER;
    AccCfg.ACC4_CONFIG = PAC194X5X_ACCCFG_MODE_VPOWER;
    errorCode = PAC194x5x_SetAccumConfig_reg(pdevice, AccCfg);
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
    
    // Configure ACC_Fullness_limits - 0x5540
    PAC194X5X_ACCUM_LIMITS_REGISTER AccLimits;
    AccLimits.ACC_CH1 = PAC194X5X_ACCLIMITS_15BY16;
    AccLimits.ACC_CH2 = PAC194X5X_ACCLIMITS_15BY16;
    AccLimits.ACC_CH3 = PAC194X5X_ACCLIMITS_15BY16;
    AccLimits.ACC_CH4 = PAC194X5X_ACCLIMITS_15BY16;
    AccLimits.ACC_COUNT = PAC194X5X_ACCLIMITS_15BY16;
    errorCode = PAC194x5x_SetAccFullness_reg(pdevice, AccLimits);
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
    
    // Configure ALERT_ENABLE - 0x000000
    PAC194X5X_ALERT_REGISTER AlertEnable;
    memset(&AlertEnable, 0, sizeof(PAC194X5X_ALERT_REGISTER));
    errorCode = PAC194x5x_SetAlertEnable_reg(pdevice, AlertEnable);
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error;
        
    errorCode = PAC194x5x_Refresh(pdevice);    // the REFRESH ensures that the configuration
                                               // changes are applied
    if(errorCode != PAC194X5X_SUCCESS) goto initialize_error; 

    pdevice->syncMode = deviceInit.syncMode;    // set the user sync mode selection

    //device initialization success. device ready to execute commands
    return errorCode;
    
initialize_error:
    pdevice->processingState = Uninitialized;
    pdevice->syncMode = deviceInit.syncMode;    // set the user sync mode selection
    PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));    
    return errorCode;
}


int16_t PAC194x5x_SetUserCallback(
    const PAC194X5X_PDEVICE_CONTEXT pdevice,
    const PAC194X5X_EVENT_HANDLER userCallback,
    const uintptr_t userContext
){
    if( (pdevice == NULL) || (userCallback == NULL) ){
        return PAC194X5X_INVALID_PARAMETER;
    }

    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }    
    
    if(pdevice->processingState == Idle){
        // set the callback
        pdevice->userCallback = userCallback;
        pdevice->userContext = userContext;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_SUCCESS;
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC194X5X_BUSY;
    }  
}

int16_t PAC194x5x_GetEventStatus(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PEVENT pevent){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    *pevent = pdevice->deviceEventStatus;
    return PAC194X5X_SUCCESS;
}

int16_t PAC194x5x_GetDeviceID(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PdeviceID pdeviceID){
    if ((pdevice == NULL) || (pdeviceID == NULL)) return PAC194X5X_INVALID_PARAMETER;
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetDeviceIDReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC194X5X_BUSY;
    }
    
    if(pdevice->deviceID_cached == true){
        *pdeviceID = pdevice->deviceID;
        pdevice->processingState = Idle;
        return PAC194X5X_ALREADY_CACHED;
    }
    
    pdevice->outData = (void*)pdeviceID;
    pdevice->i2cTxBuffer[0] = PAC194X5X_PRODUCT_ID_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = sizeof(PAC194X5X_deviceID);
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize += 3; //there is one byteCount reported before each ID register value
        PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle)); 

#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;    
}


int16_t PAC194x5x_GetDeviceIDProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    int idx = 0;

    pRawValue = pdevice->i2cRxBuffer;
    //Product ID
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.product = pRawValue[idx];
    ((PAC194X5X_PdeviceID)pdevice->outData)->product = pRawValue[idx++];
    
    //Manufacturer ID    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.manufacturer = pRawValue[idx];
    ((PAC194X5X_PdeviceID)pdevice->outData)->manufacturer = pRawValue[idx++];

    //Revision ID
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.revision = pRawValue[idx];
    ((PAC194X5X_PdeviceID)pdevice->outData)->revision = pRawValue[idx];
    
    pdevice->deviceID_cached = true;
    return PAC194X5X_SUCCESS;   
}


int16_t PAC194x5x_Refresh(PAC194X5X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    pdevice->accumConfig_LAT_cached = false;
    pdevice->accCount_cached = false;
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_REFRESH_CMD_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));    

#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_RefreshG(PAC194X5X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshGReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC194X5X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    pdevice->accumConfig_LAT_cached = false;
    pdevice->accCount_cached = false; 
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_REFRESH_G_CMD_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;   
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_RefreshV(PAC194X5X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshVReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    pdevice->accumConfig_LAT_cached = false;
    pdevice->accCount_cached = false;
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_REFRESH_V_CMD_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;   
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetCtrl_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PCTRL_REGISTER pCtrl_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    switch(reg_select){
        case 1:
            registerAddr = PAC194X5X_CTRL_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_CTRL_ACT_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_CTRL_LAT_ADDR;
            break;
        default:
            return PAC194X5X_INVALID_PARAMETER;      
    }    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetCtrlRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pCtrl_reg;
    pdevice->i2cTxBuffer_ctrl[0] = registerAddr;
    pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_CTRL_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_ctrl, 1, (void*) pdevice->i2cRxBuffer_ctrl, i2cRxSize, &(pdevice->transferHandle_ctrl));        

#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle_ctrl == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetCtrl_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_ctrl;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->SAMPLE_MODE = (pRawValue[0] >> PAC194X5X_CTRL_SAMPLE_MODE_BITPOS) & PAC194X5X_CTRL_SAMPLE_MODE_BITMASK;
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->GPIO_ALERT2 = (pRawValue[0] >> PAC194X5X_CTRL_GPIO_ALERT2_BITPOS) & PAC194X5X_CTRL_GPIO_ALERT_BITMASK;
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->SLOW_ALERT1 = (pRawValue[0] >> PAC194X5X_CTRL_SLOW_ALERT1_BITPOS) & PAC194X5X_CTRL_GPIO_ALERT_BITMASK;
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->CH1_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH1_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK;
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->CH2_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH2_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK;
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->CH3_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH3_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK; 
    ((PAC194X5X_PCTRL_REGISTER)pdevice->outData)->CH4_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH4_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK; 
    
    // cache the LAT register value in context 
    if(pdevice->i2cTxBuffer_ctrl[0] == PAC194X5X_CTRL_LAT_ADDR){
        PAC194x5x_UpdateContext_CtrlProcess(pdevice);
    }
    
    return PAC194X5X_SUCCESS;    
}


int16_t PAC194x5x_SetCtrl_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_CTRL_REGISTER Ctrl_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetCtrlRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_CTRL_ADDR;
    pdevice->i2cTxBuffer[1] = (Ctrl_reg.SAMPLE_MODE << PAC194X5X_CTRL_SAMPLE_MODE_BITPOS) |
                     (Ctrl_reg.GPIO_ALERT2 << PAC194X5X_CTRL_GPIO_ALERT2_BITPOS) |
                      Ctrl_reg.SLOW_ALERT1;
    pdevice->i2cTxBuffer[2] = (Ctrl_reg.CH1_OFF << PAC194X5X_CTRL_CH1_OFF_BITPOS) |
                     (Ctrl_reg.CH2_OFF << PAC194X5X_CTRL_CH2_OFF_BITPOS) |
                     (Ctrl_reg.CH3_OFF << PAC194X5X_CTRL_CH3_OFF_BITPOS) |
                     (Ctrl_reg.CH4_OFF << PAC194X5X_CTRL_CH4_OFF_BITPOS);
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*)pdevice->i2cTxBuffer, 1+PAC194X5X_CTRL_SZ, &(pdevice->transferHandle));
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAccumulatorCount(PAC194X5X_PDEVICE_CONTEXT pdevice, uint32_t* pregister_val){

    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAccCountReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;

    pdevice->i2cTxBuffer_accCount[0] = PAC194X5X_ACC_COUNT_ADDR;
    pdevice->transferHandle_accCount = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ACC_COUNT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_accCount, 1, (void*) pdevice->i2cRxBuffer_accCount, i2cRxSize, &(pdevice->transferHandle_accCount));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle_accCount == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAccumulatorCountProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
        
    pRawValue = pdevice->i2cRxBuffer_accCount;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];
    *((uint32_t*)pdevice->outData) = regVal;
    
    PAC194x5x_UpdateContext_AccumulatorCountProcess((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVACCn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint64_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVACCnRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)     
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVACCn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint64_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];

    *((uint64_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVACCn(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint8_t* pmode){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    }    
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVACCnValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
           
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    // Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }

    // Make sure that cached ACCUM_CONFIG_LAT value is valid
    errorCode = PAC194x5x_UpdateContext_AccumConfig((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->accMode = pmode;
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    #if defined(I2C_EVENT_CALLBACK_SUPPORTED) 
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif    
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;    
}


int16_t PAC194x5x_GetVACCnProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VAccReg;
    float VpowerAccReal, PowerUnit;
    float VsenseAccReal, VsenseLsb;
    float VbusAccReal, VbusLsb;
    uint8_t mode;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];
    
    VAccReg = regVal;

    switch(pdevice->channelNo){
        case 1:
            mode = pdevice->accumConfig_LAT.ACC1_CONFIG;
            break;
        case 2:
            mode = pdevice->accumConfig_LAT.ACC2_CONFIG;
            break;
        case 3:
            mode = pdevice->accumConfig_LAT.ACC3_CONFIG;
            break;
        case 4:
            mode = pdevice->accumConfig_LAT.ACC4_CONFIG;
            break;
        default:
            errorCode = PAC194X5X_INVALID_PARAMETER;
            return errorCode;      
    }
    
    *((uint8_t*)pdevice->accMode) = mode;
    
    switch(mode){
        case 0: //Power accumulator - mode 0 - milliWatt
            
            if(pdevice->IsSignedPower[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VpowerAccReal = (float)((int64_t)VAccReg);
            }else{
                VpowerAccReal = (float)(VAccReg);
            }

            PowerUnit = (float)pdevice->VPowerScale[(pdevice->channelNo)-1] * 1000000 / (pdevice->rsense)[(pdevice->channelNo)-1];
            PowerUnit = PowerUnit / 1073741824.0;   // milli-Watts/bit
            
            VpowerAccReal = VpowerAccReal * PowerUnit;

            if(pdevice->LowSide == 1) VpowerAccReal *= pdevice->VrailToVbusRatio[(pdevice->channelNo)-1];
            
            *((float*)pdevice->outData) = VpowerAccReal;
            
            break;
            
        case 1: //Vsense accumulator - mode 1 - milliVolt
            if(pdevice->IsSignedVsense[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VsenseAccReal = (float)((int64_t)VAccReg);
            }else{
                VsenseAccReal = (float)(VAccReg);
            }
            
            VsenseLsb = (pdevice->VsenseScale[(pdevice->channelNo)-1]) / 65536.0;
            VsenseAccReal = VsenseAccReal * VsenseLsb; //mV    
            
            *((float*)pdevice->outData) = VsenseAccReal;
            
            break;
            
        case 2: //Vbus accumulator  - mode 2 - milliVolt
            if(pdevice->IsSignedVbus[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VbusAccReal = (float)((int64_t)VAccReg);
            }else{
                VbusAccReal = (float)(VAccReg);
            }
            
            VbusLsb = (pdevice->VbusScale[(pdevice->channelNo)-1]) / 65536.0;
            VbusAccReal = VbusAccReal * VbusLsb; //mV
            
            if(pdevice->LowSide == 1) VbusAccReal *= pdevice->VrailToVbusRatio[(pdevice->channelNo)-1];
            
            *((float*)pdevice->outData) = VbusAccReal;
            
            break;

        default:
            errorCode = PAC194X5X_INVALID_ACCUMULATION_MODE;
            return errorCode;      
    }
    
    return errorCode;
}

//reports energy in mWh
int16_t PAC194x5x_GetEnergy_mWh(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    }    
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetEnergyReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
            
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    // Read Ctrl & NegPwr
    errorCode = PAC194x5x_UpdateContext_Ctrl((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        //discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    // Make sure that cached ACCUM_CONFIG_LAT value is valid
    errorCode = PAC194x5x_UpdateContext_AccumConfig((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;

    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer       
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }
           
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetEnergy_mWhProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    float energyVal;
    float EnergyUnit = ENERGY_UNIT_CONVERSION;
    uint8_t* pRawValue;
    uint64_t regVal;
    float VpowerAccReal, PowerUnit;
    uint64_t VAccReg;uint16_t sampleRate;
    uint8_t mode;
    uint8_t channelCount = 0;
    uint16_t errorCode = PAC194X5X_SUCCESS;
    
    if ( (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1000) || (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1001) ){
        errorCode = PAC194X5X_SINGLE_SHOT_MODE_CONFIGURED;
        return errorCode;
    } 
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];
    
    VAccReg = regVal;

    switch(pdevice->channelNo){
        case 1:
            mode = pdevice->accumConfig_LAT.ACC1_CONFIG;
            break;
        case 2:
            mode = pdevice->accumConfig_LAT.ACC2_CONFIG;
            break;
        case 3:
            mode = pdevice->accumConfig_LAT.ACC3_CONFIG;
            break;
        case 4:
            mode = pdevice->accumConfig_LAT.ACC4_CONFIG;
            break;
        default:
            errorCode = PAC194X5X_INVALID_PARAMETER;
            return errorCode;      
    }
    
    if (mode != 0){
        errorCode = PAC194X5X_VACC_POWER_MODE_NOT_CONFIGURED;
        return errorCode;
    }
    
    //Power accumulator - mode 0 - milliWatt
            
            if(pdevice->IsSignedPower[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VpowerAccReal = (float)((int64_t)VAccReg);
            }else{
                VpowerAccReal = (float)(VAccReg);
            }

            PowerUnit = (float)pdevice->VPowerScale[(pdevice->channelNo)-1] * 1000000 / (pdevice->rsense)[(pdevice->channelNo)-1];
            PowerUnit = PowerUnit / 1073741824.0;   // milli-Watts/bit
            
            VpowerAccReal = VpowerAccReal * PowerUnit;

            if(pdevice->LowSide == 1) VpowerAccReal *= pdevice->VrailToVbusRatio[(pdevice->channelNo)-1];
                                   
        
    if ( (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1010) || (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1011) ){
        switch(pdevice->HwChannels){
            case 4:
                if (pdevice->ctrl_LAT.CH4_OFF == 0) channelCount++;
            case 3:
                if (pdevice->ctrl_LAT.CH3_OFF == 0) channelCount++;
            case 2:
                if (pdevice->ctrl_LAT.CH2_OFF == 0) channelCount++;
            case 1:
                if (pdevice->ctrl_LAT.CH1_OFF == 0) channelCount++;
        }
    }
    
    switch(pdevice->ctrl_LAT.SAMPLE_MODE){
        case 0:
            sampleRate = 1024;
            break;
        case 1:
            sampleRate = 1024;
            break;
        case 2:
            sampleRate = 1024;
            break;
        case 3:
            sampleRate = 1024;
            break;
        case 4:
            sampleRate = 1024;
            break;
        case 5:
            sampleRate = 256;
            break;
        case 6:
            sampleRate = 64;
            break;
        case 7:
            sampleRate = 8;
            break;
        case 10:
            sampleRate = (1024 * 5) / (channelCount + 1);
        case 11:
            sampleRate = (1024 * 5) / channelCount;
        default:
            errorCode = PAC194X5X_INVALID_SAMPLE_MODE;
            return errorCode;      
    }
    
    energyVal = (VpowerAccReal / sampleRate) * EnergyUnit;
    
    *((float*)pdevice->outData) = energyVal;
    
    return errorCode;
}

//reports energy in mWh
int16_t PAC194x5x_GetTimedEnergy_mWh(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    } 
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;
            
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetTimedEnergyReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    // Read Ctrl & NegPwr
    errorCode = PAC194x5x_UpdateContext_Ctrl((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        //discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    // Make sure that cached ACCUM_CONFIG_LAT value is valid
    errorCode = PAC194x5x_UpdateContext_AccumConfig((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    // get the number of samples
    errorCode = PAC194x5x_UpdateContext_AccumulatorCount((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    pdevice->channelNo = channelNo;
    pdevice->time = time;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accCount = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }  
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetTimedEnergy_mWhProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode;
    float energyVal;
    float EnergyUnit = ENERGY_UNIT_CONVERSION; 
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VAccReg;
    float VpowerAccReal, PowerUnit;
    uint32_t sampleCount;
    uint8_t mode;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];
    
    VAccReg = regVal;
    
    switch(pdevice->channelNo){
        case 1:
            mode = pdevice->accumConfig_LAT.ACC1_CONFIG;
            break;
        case 2:
            mode = pdevice->accumConfig_LAT.ACC2_CONFIG;
            break;
        case 3:
            mode = pdevice->accumConfig_LAT.ACC3_CONFIG;
            break;
        case 4:
            mode = pdevice->accumConfig_LAT.ACC4_CONFIG;
            break;
        default:
            errorCode = PAC194X5X_INVALID_PARAMETER;
            return errorCode;      
    }
    
    switch(mode){
        case 0: //Power accumulator - mode 0 - milliWatt
            
            if(pdevice->IsSignedPower[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VpowerAccReal = (float)((int64_t)VAccReg);
            }else{
                VpowerAccReal = (float)(VAccReg);
            }

            PowerUnit = (float)pdevice->VPowerScale[(pdevice->channelNo)-1] * 1000000 / (pdevice->rsense)[(pdevice->channelNo)-1];
            PowerUnit = PowerUnit / 1073741824.0;   // milli-Watts/bit
            
            VpowerAccReal = VpowerAccReal * PowerUnit;

            if(pdevice->LowSide == 1) VpowerAccReal *= pdevice->VrailToVbusRatio[(pdevice->channelNo)-1];
            
            break;
            
        default:
            errorCode = PAC194X5X_VACC_POWER_MODE_NOT_CONFIGURED;
            return errorCode;      
    }
    
    sampleCount = pdevice->accCount;
    
    if(sampleCount > 1) VpowerAccReal /= (float)sampleCount;
        
    energyVal = VpowerAccReal * ((pdevice->time) / 1000.0) * EnergyUnit;    // milli-Watt*h
    
    *((float*)pdevice->outData) = energyVal;
    
    return PAC194X5X_SUCCESS;
}

//reports energy in mAs
int16_t PAC194x5x_GetCoulomb_mAs(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    }    
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetCoulombReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
            
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    // Read Ctrl & NegPwr
    errorCode = PAC194x5x_UpdateContext_Ctrl((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        // discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }

    // Make sure that cached ACCUM_CONFIG_LAT value is valid
    errorCode = PAC194x5x_UpdateContext_AccumConfig((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;

    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }
           
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetCoulomb_mAsProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    float coulombVal;
    uint8_t* pRawValue;
    uint64_t regVal;
    float VsenseAccReal, VsenseLsb;
    uint64_t VAccReg;
    uint16_t sampleRate;
    uint8_t mode;
    uint8_t channelCount = 0;
    uint16_t errorCode = PAC194X5X_SUCCESS;
    
    if ( (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1000) || (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1001) ){
        errorCode = PAC194X5X_SINGLE_SHOT_MODE_CONFIGURED;
        return errorCode;
    } 
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];
    
    VAccReg = regVal;

    switch(pdevice->channelNo){
        case 1:
            mode = pdevice->accumConfig_LAT.ACC1_CONFIG;
            break;
        case 2:
            mode = pdevice->accumConfig_LAT.ACC2_CONFIG;
            break;
        case 3:
            mode = pdevice->accumConfig_LAT.ACC3_CONFIG;
            break;
        case 4:
            mode = pdevice->accumConfig_LAT.ACC4_CONFIG;
            break;
        default:
            errorCode = PAC194X5X_INVALID_PARAMETER;
            return errorCode;      
    }
    
    if (mode != 1){
        errorCode = PAC194X5X_VACC_VSENSE_MODE_NOT_CONFIGURED;
        return errorCode;
    }
    
    //Vsense accumulator - mode 1 - milliVolt
            if(pdevice->IsSignedVsense[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VsenseAccReal = (float)((int64_t)VAccReg);
            }else{
                VsenseAccReal = (float)(VAccReg);
            }
            
            VsenseLsb = (pdevice->VsenseScale[(pdevice->channelNo)-1]) / 65536.0;
            VsenseAccReal = VsenseAccReal * VsenseLsb; //mV
                                   
        
    if ( (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1010) || (pdevice->ctrl_LAT.SAMPLE_MODE == 0b1011) ){
        switch(pdevice->HwChannels){
            case 4:
                if (pdevice->ctrl_LAT.CH4_OFF == 0) channelCount++;
            case 3:
                if (pdevice->ctrl_LAT.CH3_OFF == 0) channelCount++;
            case 2:
                if (pdevice->ctrl_LAT.CH2_OFF == 0) channelCount++;
            case 1:
                if (pdevice->ctrl_LAT.CH1_OFF == 0) channelCount++;
        }
    }
    
    switch(pdevice->ctrl_LAT.SAMPLE_MODE){
        case 0:
            sampleRate = 1024;
            break;
        case 1:
            sampleRate = 1024;
            break;
        case 2:
            sampleRate = 1024;
            break;
        case 3:
            sampleRate = 1024;
            break;
        case 4:
            sampleRate = 1024;
            break;
        case 5:
            sampleRate = 256;
            break;
        case 6:
            sampleRate = 64;
            break;
        case 7:
            sampleRate = 8;
            break;
        case 10:
            sampleRate = (1024 * 5) / (channelCount + 1);
        case 11:
            sampleRate = (1024 * 5) / channelCount;
        default:
            errorCode = PAC194X5X_INVALID_SAMPLE_MODE;
            return errorCode;      
    }
    
    coulombVal = 1000000.0 * VsenseAccReal / sampleRate / pdevice->rsense[pdevice->channelNo - 1];
    
    *((float*)pdevice->outData) = coulombVal;
    
    return errorCode;
}

//reports energy in mAs
int16_t PAC194x5x_GetTimedCoulomb_mAs(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    } 
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;
            
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetTimedCoulombReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VACC1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VACC2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VACC3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VACC4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    //Read Ctrl & NegPwr
    errorCode = PAC194x5x_UpdateContext_Ctrl((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        //discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }

    //Make sure that cached ACCUM_CONFIG_LAT value is valid
    errorCode = PAC194x5x_UpdateContext_AccumConfig((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    //get the number of samples
    errorCode = PAC194x5x_UpdateContext_AccumulatorCount((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    pdevice->channelNo = channelNo;
    pdevice->time = time;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_accCount = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif    
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }  
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetTimedCoulomb_mAsProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode;
    float coulombVal;
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VAccReg;
    float VsenseAccReal, VsenseLsb;
    uint32_t sampleCount;
    uint8_t mode;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    regVal = (regVal << 8) | (uint64_t)pRawValue[6];
    
    VAccReg = regVal;
    
    switch(pdevice->channelNo){
        case 1:
            mode = pdevice->accumConfig_LAT.ACC1_CONFIG;
            break;
        case 2:
            mode = pdevice->accumConfig_LAT.ACC2_CONFIG;
            break;
        case 3:
            mode = pdevice->accumConfig_LAT.ACC3_CONFIG;
            break;
        case 4:
            mode = pdevice->accumConfig_LAT.ACC4_CONFIG;
            break;
        default:
            errorCode = PAC194X5X_INVALID_PARAMETER;
            return errorCode;      
    }
    
    switch(mode){
        case 1: //Vsense accumulator - mode 1 - milliVolt
            if(pdevice->IsSignedVsense[(pdevice->channelNo)-1] == 1){
                if( (VAccReg & 0x80000000000000) == 0x80000000000000){
                    VAccReg = VAccReg | 0xFF80000000000000; //sign extension
                }
                VsenseAccReal = (float)((int64_t)VAccReg);
            }else{
                VsenseAccReal = (float)(VAccReg);
            }
            
            VsenseLsb = (pdevice->VsenseScale[(pdevice->channelNo)-1]) / 65536.0;
            VsenseAccReal = VsenseAccReal * VsenseLsb; //mV    
            
            *((float*)pdevice->outData) = VsenseAccReal;
            
            break;
            
        default:
            errorCode = PAC194X5X_VACC_VSENSE_MODE_NOT_CONFIGURED;
            return errorCode;      
    }
    
    sampleCount = pdevice->accCount;
    
    if(sampleCount > 1) VsenseAccReal /= (float)sampleCount; 
        
    coulombVal = VsenseAccReal * pdevice->time * 1000 / pdevice->rsense[pdevice->channelNo - 1];  // milli-Amp*s
    
    *((float*)pdevice->outData) = coulombVal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVBUSn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VBUS1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VBUS2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VBUS3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VBUS4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVBUSn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mV
int16_t PAC194x5x_GetVBUSn_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VBUS1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VBUS2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VBUS3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VBUS4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVBUSn_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VbusReg;
    float VbusReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VbusReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVbus[pdevice->channelNo-1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VbusReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VbusScale[pdevice->channelNo - 1];
        VbusReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VbusReg * (uint32_t)pdevice->VbusScale[pdevice->channelNo - 1];
        VbusReal = (float)tempProd;
    }
    
    VbusReal = VbusReal / 65536.0;    //mV
    if(pdevice->LowSide == 1) VbusReal *= pdevice->VrailToVbusRatio[pdevice->channelNo-1];    

    *((float*)pdevice->outData) = VbusReal;

        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
      
    pdevice->channelNo = channelNo;
    // Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseReg;
    float VsenseReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VsenseReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VsenseReg * (uint32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }
    
    VsenseReal = VsenseReal / 65536.0;    //mV

    *((float*)pdevice->outData) = VsenseReal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetISENSEn_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ) return PAC194X5X_INVALID_PARAMETER;

    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetISENSEnValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
   
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetISENSEn_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseReg;
    float VsenseReal;
    float IsenseReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VsenseReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VsenseReg * (uint32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }
    
    VsenseReal = VsenseReal / 65536.0;    //mV
    IsenseReal = ( VsenseReal * 1000000 ) / (pdevice->rsense[pdevice->channelNo - 1]);     //mA

    *((float*)pdevice->outData) = IsenseReal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVBUSn_AVG_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnAVGRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VBUS1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VBUS2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VBUS3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VBUS4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;  
}


int16_t PAC194x5x_GetVBUSn_AVG_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVBUSn_AVG_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnAVGValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VBUS1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VBUS2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VBUS3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VBUS4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
        
    pdevice->channelNo = channelNo;
    
    // Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;  
}


int16_t PAC194x5x_GetVBUSn_AVG_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VbusReg;
    float VbusReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VbusReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVbus[pdevice->channelNo - 1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VbusReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VbusScale[pdevice->channelNo - 1];
        VbusReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VbusReg * (uint32_t)pdevice->VbusScale[pdevice->channelNo - 1];
        VbusReal = (float)tempProd;
    }
    
    VbusReal = VbusReal / 65536.0;    //mV
    if(pdevice->LowSide == 1) VbusReal *= pdevice->VrailToVbusRatio[pdevice->channelNo - 1];

    *((float*)pdevice->outData) = VbusReal;
            
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_AVG_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnAVGRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_AVG_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVSENSEn_AVG_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnAVGValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    // Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        //discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID; 
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetVSENSEn_AVG_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseReg;
    float VsenseReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVsense[pdevice->channelNo - 1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VsenseReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VsenseReg * (uint32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }
    
    VsenseReal = VsenseReal / 65536.0;    //mV

    *((float*)pdevice->outData) = VsenseReal;
            
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetISENSEn_AVG_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
        
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ) return PAC194X5X_INVALID_PARAMETER;
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;     
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetISENSEnAVGValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID; 
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}

int16_t PAC194x5x_GetISENSEn_AVG_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseReg;
    float VsenseReal;
    float IsenseReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseReg = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if (pdevice->IsSignedVsense[pdevice->channelNo - 1] == 1){
        int16_t signedReg;
        int32_t tempProd;
        signedReg = (int16_t)VsenseReg;
        tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }else{
        uint32_t tempProd;
        tempProd = (uint32_t)VsenseReg * (uint32_t)pdevice->VsenseScale[pdevice->channelNo - 1];
        VsenseReal = (float)tempProd;
    }
    
    VsenseReal = VsenseReal / 65536.0;    //mV
    IsenseReal = (VsenseReal * 1000000 ) / pdevice->rsense[pdevice->channelNo - 1];     //mA

    *((float*)pdevice->outData) = IsenseReal;
            
    return PAC194X5X_SUCCESS;
}

int16_t PAC194x5x_GetVPOWERn_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVPOWERnRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VPOWER1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VPOWER2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VPOWER3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VPOWER4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_VPOWERN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVPOWERn_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];

    *((uint32_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

// pvalue reported as milli-Watt
int16_t PAC194x5x_GetVPOWERn_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC194X5X_SUCCESS;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC194X5X_INVALID_PARAMETER;
        return errorCode;       
    }  
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC194X5X_INVALID_SHUNT_VALUE;    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVPOWERnValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_VPOWER1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_VPOWER2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_VPOWER3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_VPOWER4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    // Read NegPwr
    errorCode = PAC194x5x_UpdateContext_ChannelPolarity((PAC194X5X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC194X5X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_VPOWERN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetVPOWERn_mWProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
    uint32_t VpowerReg;
    float VpowerReal, PowerUnit;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];
    
    VpowerReg = regVal;
    
    if(pdevice->IsSignedPower[pdevice->channelNo - 1] == 1){
        int32_t signedVpowerReg;
        signedVpowerReg = (int32_t)VpowerReg;
        signedVpowerReg >>= 2;  // 30 bit reg value
        VpowerReal = (float)signedVpowerReg;
    }else{
        VpowerReg >>= 2;    // 30 bit reg value
        VpowerReal = (float)VpowerReg;
    }

    PowerUnit = (float)pdevice->VPowerScale[pdevice->channelNo - 1] * 1000000 / pdevice->rsense[pdevice->channelNo - 1];
    PowerUnit = PowerUnit / 1073741824.0;   // milli-Watts/bit    
    VpowerReal = VpowerReal * PowerUnit;
    if(pdevice->LowSide == 1) VpowerReal *= pdevice->VrailToVbusRatio[pdevice->channelNo - 1];

    *((float*)pdevice->outData) = VpowerReal;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetSMBusSettings_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PSMBUS_SETTINGS_REGISTER pChDisSMBus_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetSMBusRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pChDisSMBus_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_SMBUS_SETTINGS_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_SMBUS_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetSMBusSettings_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->GPIO_DATA2  = (pRawValue[0] >> PAC194X5X_SMBUS_GPIODATA2_BITPOS) & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->GPIO_DATA1  = (pRawValue[0] >> PAC194X5X_SMBUS_GPIODATA1_BITPOS) & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->ANY_ALERT   = (pRawValue[0] >> PAC194X5X_SMBUS_ANYALERT_BITPOS)  & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->POR         = (pRawValue[0] >> PAC194X5X_SMBUS_POR_BITPOS)       & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->TIMEOUT     = (pRawValue[0] >> PAC194X5X_SMBUS_TIMEOUT_BITPOS)   & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->BYTE_COUNT  = (pRawValue[0] >> PAC194X5X_SMBUS_BYTECOUNT_BITPOS) & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->NO_SKIP     = (pRawValue[0] >> PAC194X5X_SMBUS_NOSKIP_BITPOS)    & PAC194X5X_SMBUS_BITMASK;
    ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)pdevice->outData)->I2C_HISPEED = (pRawValue[0] >> PAC194X5X_SMBUS_I2CSPEED_BITPOS)  & PAC194X5X_SMBUS_BITMASK;
    
    // cache the BYTE_COUNT flag into device context
    pdevice->ENABLE_BYTE_COUNT_FLAG = ( ((PAC194X5X_PSMBUS_SETTINGS_REGISTER)(pdevice->outData))->BYTE_COUNT == 1 ) ? true: false;    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_SetSMBusSettings_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_SMBUS_SETTINGS_REGISTER ChDisSMBus_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetSMBusRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_SMBUS_SETTINGS_ADDR;
    pdevice->i2cTxBuffer[1] =   (ChDisSMBus_reg.GPIO_DATA2 << PAC194X5X_SMBUS_GPIODATA2_BITPOS) |
                                (ChDisSMBus_reg.GPIO_DATA1 << PAC194X5X_SMBUS_GPIODATA2_BITPOS) |
                                (ChDisSMBus_reg.ANY_ALERT  << PAC194X5X_SMBUS_ANYALERT_BITPOS)  |
                                (ChDisSMBus_reg.POR        << PAC194X5X_SMBUS_POR_BITPOS)       |
                                (ChDisSMBus_reg.TIMEOUT    << PAC194X5X_SMBUS_TIMEOUT_BITPOS)   |
                                (ChDisSMBus_reg.BYTE_COUNT << PAC194X5X_SMBUS_BYTECOUNT_BITPOS) |
                                (ChDisSMBus_reg.NO_SKIP    << PAC194X5X_SMBUS_NOSKIP_BITPOS)    |
                                 ChDisSMBus_reg.I2C_HISPEED;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID; 
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_SMBUS_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetSMBusSettings_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){    
    // cache the BYTE_COUNT flag into device context
    pdevice->ENABLE_BYTE_COUNT_FLAG = ( ((pdevice->i2cTxBuffer[1] >> PAC194X5X_SMBUS_BYTECOUNT_BITPOS) & PAC194X5X_SMBUS_BITMASK) == 1 ) ? true: false;
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetNegPwrFsr_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PNEG_PWR_FSR_REGISTER pNegPwr_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    switch(reg_select){
        case 1:
            registerAddr = PAC194X5X_NEG_PWR_FSR_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_NEG_PWR_FSR_ACT_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_NEG_PWR_FSR_LAT_ADDR;
            break;
        default:
            return PAC194X5X_INVALID_PARAMETER;      
    }    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetNegPWRFSRRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pNegPwr_reg;
    pdevice->i2cTxBuffer_negPwr[0] = registerAddr;
    pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_NEGPWRFSR_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_negPwr, 1, (void*) pdevice->i2cRxBuffer_negPwr, i2cRxSize, &(pdevice->transferHandle_negPwr));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle_negPwr == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;  
}


int16_t PAC194x5x_GetNegPwrFsr_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_negPwr;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VS1 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS1_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VS2 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS2_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VS3 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS3_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VS4 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS4_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;    
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VB1 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB1_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VB2 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB2_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VB3 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB3_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    ((PAC194X5X_PNEG_PWR_FSR_REGISTER)pdevice->outData)->CFG_VB4 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB4_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    
    if(pdevice->i2cTxBuffer_negPwr[0] == PAC194X5X_NEG_PWR_FSR_LAT_ADDR){ 
        PAC194x5x_UpdateContext_ChannelPolarityProcess((PAC194X5X_PDEVICE_CONTEXT)pdevice);  
    }
    
    return PAC194X5X_SUCCESS;   
}


int16_t PAC194x5x_SetNegPwrFsr_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_NEG_PWR_FSR_REGISTER NegPwr_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetNegPWRFSRRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_NEG_PWR_FSR_ADDR; 
    pdevice->i2cTxBuffer[1] =   (NegPwr_reg.CFG_VS1 << PAC194X5X_NEGPWRFSR_VS1_BITPOS) |
                                (NegPwr_reg.CFG_VS2 << PAC194X5X_NEGPWRFSR_VS2_BITPOS) |
                                (NegPwr_reg.CFG_VS3 << PAC194X5X_NEGPWRFSR_VS3_BITPOS) |
                                (NegPwr_reg.CFG_VS4 << PAC194X5X_NEGPWRFSR_VS4_BITPOS) ;
    pdevice->i2cTxBuffer[2] =   (NegPwr_reg.CFG_VB1 << PAC194X5X_NEGPWRFSR_VB1_BITPOS) |
                                (NegPwr_reg.CFG_VB2 << PAC194X5X_NEGPWRFSR_VB2_BITPOS) |
                                (NegPwr_reg.CFG_VB3 << PAC194X5X_NEGPWRFSR_VB3_BITPOS) |
                                (NegPwr_reg.CFG_VB4 << PAC194X5X_NEGPWRFSR_VB4_BITPOS) ;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_NEGPWRFSR_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;  
}


int16_t PAC194x5x_GetSlow_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PSLOW_REGISTER pSlow_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetSlowRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pSlow_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_SLOW_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_SLOW_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetSlow_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->Slow         = (pRawValue[0] >> PAC194X5X_SLOW_SLOW_BITPOS)   & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->SlowLowHigh  = (pRawValue[0] >> PAC194X5X_SLOW_LH_BITPOS)     & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->SlowHighLow  = (pRawValue[0] >> PAC194X5X_SLOW_HL_BITPOS)     & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->RefreshRise  = (pRawValue[0] >> PAC194X5X_SLOW_RRISE_BITPOS)  & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->RefreshVRise = (pRawValue[0] >> PAC194X5X_SLOW_RVRISE_BITPOS) & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->RefreshFall  = (pRawValue[0] >> PAC194X5X_SLOW_RFALL_BITPOS)  & PAC194X5X_SLOW_BITMASK;
    ((PAC194X5X_PSLOW_REGISTER)pdevice->outData)->RefreshVFall = (pRawValue[0] >> PAC194X5X_SLOW_RVFALL_BITPOS) & PAC194X5X_SLOW_BITMASK;
    
    return PAC194X5X_SUCCESS;     
}


int16_t PAC194x5x_SetSlow_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_SLOW_REGISTER Slow_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetSlowRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_SLOW_ADDR;
    pdevice->i2cTxBuffer[1] =   (Slow_reg.Slow << PAC194X5X_SLOW_SLOW_BITPOS) |
                                (Slow_reg.SlowLowHigh << PAC194X5X_SLOW_LH_BITPOS) |
                                (Slow_reg.SlowHighLow << PAC194X5X_SLOW_HL_BITPOS) |
                                (Slow_reg.RefreshRise << PAC194X5X_SLOW_RRISE_BITPOS) |
                                (Slow_reg.RefreshVRise << PAC194X5X_SLOW_RVRISE_BITPOS) |
                                (Slow_reg.RefreshFall << PAC194X5X_SLOW_RFALL_BITPOS) |
                                (Slow_reg.RefreshVFall << PAC194X5X_SLOW_RVFALL_BITPOS);
            
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_SLOW_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetAccumConfig_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PACCUM_CONFIG_REGISTER pAccumConfig_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    switch(reg_select){
        case 1:
            registerAddr = PAC194X5X_ACCUM_CONFIG_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_ACCUM_CONFIG_ACT_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_ACCUM_CONFIG_LAT_ADDR;
            break;
        default:
            return PAC194X5X_INVALID_PARAMETER;      
    }    
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAccumConfigRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pAccumConfig_reg;
    pdevice->i2cTxBuffer_accumConfig[0] = registerAddr;
    pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ACCUMCONFIG_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_accumConfig, 1, (void*) pdevice->i2cRxBuffer_accumConfig, i2cRxSize, &(pdevice->transferHandle_accumConfig));        
 #if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle_accumConfig == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
 #endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAccumConfig_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_accumConfig;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    ((PAC194X5X_PACCUM_CONFIG_REGISTER)pdevice->outData)->ACC1_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC1_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    ((PAC194X5X_PACCUM_CONFIG_REGISTER)pdevice->outData)->ACC2_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC2_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    ((PAC194X5X_PACCUM_CONFIG_REGISTER)pdevice->outData)->ACC3_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC3_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    ((PAC194X5X_PACCUM_CONFIG_REGISTER)pdevice->outData)->ACC4_CONFIG =  pRawValue[0] & PAC194X5X_ACCCFG_BITMASK;
    // cache the LAT register value in context 
    if(pdevice->i2cTxBuffer_accumConfig[0] == PAC194X5X_ACCUM_CONFIG_LAT_ADDR){    
        PAC194x5x_UpdateContext_AccumConfigProcess(pdevice);
    }
    
    return PAC194X5X_SUCCESS;    
}


int16_t PAC194x5x_SetAccumConfig_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ACCUM_CONFIG_REGISTER AccumConfig_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetAccumConfigRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_ACCUM_CONFIG_ADDR;
    pdevice->i2cTxBuffer[1] =  (AccumConfig_reg.ACC1_CONFIG << PAC194X5X_ACCCFG_ACC1_BITPOS) |
                               (AccumConfig_reg.ACC2_CONFIG << PAC194X5X_ACCCFG_ACC2_BITPOS) |
                               (AccumConfig_reg.ACC3_CONFIG << PAC194X5X_ACCCFG_ACC3_BITPOS) |
                                AccumConfig_reg.ACC4_CONFIG;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_ACCUMCONFIG_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)    
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAlertStatus_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_STATUS_REGISTER pAlertStatus_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAlertStatusRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pAlertStatus_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_ALERT_STATUS_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ALERT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAlertStatus_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH1_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH1OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH2_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH2OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH3_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH3OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH4_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH4OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH1_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH1UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH2_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH2UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH3_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH3UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH4_UC =  pRawValue[0] & PAC194X5X_ALERT_BITMASK;
    
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH1_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH1OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH2_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH2OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH3_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH3OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH4_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH4OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH1_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH1UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH2_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH2UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH3_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH3UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH4_UV =  pRawValue[1] & PAC194X5X_ALERT_BITMASK;
    
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH1_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH1OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH2_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH2OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH3_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH3OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->CH4_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH4OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->ACC_OVF = (pRawValue[2] >> PAC194X5X_ALERT_ACCOVF_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_STATUS_REGISTER)pdevice->outData)->ACC_COUNT = (pRawValue[2] >> PAC194X5X_ALERT_ACCCNT_BITPOS) & PAC194X5X_ALERT_BITMASK;
    
    return PAC194X5X_SUCCESS;     
}


int16_t PAC194x5x_GetAlertEnable_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pAlertEnable_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAlertEnableRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pAlertEnable_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_ALERT_ENABLE_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ALERT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAlert_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH1_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH1OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH2_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH2OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH3_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH3OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH4_OC = (pRawValue[0] >> PAC194X5X_ALERT_CH4OC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH1_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH1UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH2_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH2UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH3_UC = (pRawValue[0] >> PAC194X5X_ALERT_CH3UC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH4_UC =  pRawValue[0] & PAC194X5X_ALERT_BITMASK;
    
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH1_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH1OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH2_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH2OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH3_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH3OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH4_OV = (pRawValue[1] >> PAC194X5X_ALERT_CH4OV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH1_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH1UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH2_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH2UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH3_UV = (pRawValue[1] >> PAC194X5X_ALERT_CH3UV_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH4_UV =  pRawValue[1] & PAC194X5X_ALERT_BITMASK;
    
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH1_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH1OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH2_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH2OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH3_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH3OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->CH4_OP = (pRawValue[2] >> PAC194X5X_ALERT_CH4OP_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->ACC_OVF = (pRawValue[2] >> PAC194X5X_ALERT_ACCOVF_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->ACC_COUNT = (pRawValue[2] >> PAC194X5X_ALERT_ACCCNT_BITPOS) & PAC194X5X_ALERT_BITMASK;
    ((PAC194X5X_PALERT_REGISTER)pdevice->outData)->ALERT_CCx = (pRawValue[2] >> PAC194X5X_ALERT_CC_BITPOS) & PAC194X5X_ALERT_BITMASK;
    
    return PAC194X5X_SUCCESS;     
}


int16_t PAC194x5x_SetAlertEnable_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetAlertEnableRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_ALERT_ENABLE_ADDR; 
    pdevice->i2cTxBuffer[1] =   (AlertEnable_reg.CH1_OC << PAC194X5X_ALERT_CH1OC_BITPOS) |
                                (AlertEnable_reg.CH2_OC << PAC194X5X_ALERT_CH2OC_BITPOS) |
                                (AlertEnable_reg.CH3_OC << PAC194X5X_ALERT_CH3OC_BITPOS) |
                                (AlertEnable_reg.CH4_OC << PAC194X5X_ALERT_CH4OC_BITPOS) |
                                (AlertEnable_reg.CH1_UC << PAC194X5X_ALERT_CH1UC_BITPOS) |
                                (AlertEnable_reg.CH2_UC << PAC194X5X_ALERT_CH2UC_BITPOS) |
                                (AlertEnable_reg.CH3_UC << PAC194X5X_ALERT_CH3UC_BITPOS) |
                                (AlertEnable_reg.CH4_UC << PAC194X5X_ALERT_CH4UC_BITPOS); 
    
    pdevice->i2cTxBuffer[2] =   (AlertEnable_reg.CH1_OV << PAC194X5X_ALERT_CH1OV_BITPOS) |
                                (AlertEnable_reg.CH2_OV << PAC194X5X_ALERT_CH2OV_BITPOS) |
                                (AlertEnable_reg.CH3_OV << PAC194X5X_ALERT_CH3OV_BITPOS) |
                                (AlertEnable_reg.CH4_OV << PAC194X5X_ALERT_CH4OV_BITPOS) |
                                (AlertEnable_reg.CH1_UV << PAC194X5X_ALERT_CH1UV_BITPOS) |
                                (AlertEnable_reg.CH2_UV << PAC194X5X_ALERT_CH2UV_BITPOS) |
                                (AlertEnable_reg.CH3_UV << PAC194X5X_ALERT_CH3UV_BITPOS) |
                                (AlertEnable_reg.CH4_UV << PAC194X5X_ALERT_CH4UV_BITPOS); 

    pdevice->i2cTxBuffer[3] =   (AlertEnable_reg.CH1_OP << PAC194X5X_ALERT_CH1OP_BITPOS) |
                                (AlertEnable_reg.CH2_OP << PAC194X5X_ALERT_CH2OP_BITPOS) |
                                (AlertEnable_reg.CH3_OP << PAC194X5X_ALERT_CH3OP_BITPOS) |
                                (AlertEnable_reg.CH4_OP << PAC194X5X_ALERT_CH4OP_BITPOS) |
                                (AlertEnable_reg.ACC_OVF << PAC194X5X_ALERT_ACCOVF_BITPOS) |
                                (AlertEnable_reg.ACC_COUNT << PAC194X5X_ALERT_ACCCNT_BITPOS) |
                                (AlertEnable_reg.ALERT_CCx << PAC194X5X_ALERT_CC_BITPOS);
            
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_ALERT_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetSlowAlert1_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pSlowAlert1_reg){    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetSlowAlert1RegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pSlowAlert1_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_SLOW_ALERT1_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ALERT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetSlowAlert1_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetSlowAlert1RegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_SLOW_ALERT1_ADDR;   
    pdevice->i2cTxBuffer[1] =   (AlertEnable_reg.CH1_OC << PAC194X5X_ALERT_CH1OC_BITPOS) |
                                (AlertEnable_reg.CH2_OC << PAC194X5X_ALERT_CH2OC_BITPOS) |
                                (AlertEnable_reg.CH3_OC << PAC194X5X_ALERT_CH3OC_BITPOS) |
                                (AlertEnable_reg.CH4_OC << PAC194X5X_ALERT_CH4OC_BITPOS) |
                                (AlertEnable_reg.CH1_UC << PAC194X5X_ALERT_CH1UC_BITPOS) |
                                (AlertEnable_reg.CH2_UC << PAC194X5X_ALERT_CH2UC_BITPOS) |
                                (AlertEnable_reg.CH3_UC << PAC194X5X_ALERT_CH3UC_BITPOS) |
                                (AlertEnable_reg.CH4_UC << PAC194X5X_ALERT_CH4UC_BITPOS); 
    
    pdevice->i2cTxBuffer[2] =   (AlertEnable_reg.CH1_OV << PAC194X5X_ALERT_CH1OV_BITPOS) |
                                (AlertEnable_reg.CH2_OV << PAC194X5X_ALERT_CH2OV_BITPOS) |
                                (AlertEnable_reg.CH3_OV << PAC194X5X_ALERT_CH3OV_BITPOS) |
                                (AlertEnable_reg.CH4_OV << PAC194X5X_ALERT_CH4OV_BITPOS) |
                                (AlertEnable_reg.CH1_UV << PAC194X5X_ALERT_CH1UV_BITPOS) |
                                (AlertEnable_reg.CH2_UV << PAC194X5X_ALERT_CH2UV_BITPOS) |
                                (AlertEnable_reg.CH3_UV << PAC194X5X_ALERT_CH3UV_BITPOS) |
                                (AlertEnable_reg.CH4_UV << PAC194X5X_ALERT_CH4UV_BITPOS); 

    pdevice->i2cTxBuffer[3] =   (AlertEnable_reg.CH1_OP << PAC194X5X_ALERT_CH1OP_BITPOS) |
                                (AlertEnable_reg.CH2_OP << PAC194X5X_ALERT_CH2OP_BITPOS) |
                                (AlertEnable_reg.CH3_OP << PAC194X5X_ALERT_CH3OP_BITPOS) |
                                (AlertEnable_reg.CH4_OP << PAC194X5X_ALERT_CH4OP_BITPOS) |
                                (AlertEnable_reg.ACC_OVF << PAC194X5X_ALERT_ACCOVF_BITPOS) |
                                (AlertEnable_reg.ACC_COUNT << PAC194X5X_ALERT_ACCCNT_BITPOS) |
                                (AlertEnable_reg.ALERT_CCx << PAC194X5X_ALERT_CC_BITPOS);
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_ALERT_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetGpioAlert2_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PALERT_REGISTER pGpioAlert2_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetGpioAlert2RegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pGpioAlert2_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_GPIO_ALERT2_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_ALERT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetGpioAlert2_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ALERT_REGISTER AlertEnable_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetGpioAlert2RegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_GPIO_ALERT2_ADDR;
    pdevice->i2cTxBuffer[1] =   (AlertEnable_reg.CH1_OC << PAC194X5X_ALERT_CH1OC_BITPOS) |
                                (AlertEnable_reg.CH2_OC << PAC194X5X_ALERT_CH2OC_BITPOS) |
                                (AlertEnable_reg.CH3_OC << PAC194X5X_ALERT_CH3OC_BITPOS) |
                                (AlertEnable_reg.CH4_OC << PAC194X5X_ALERT_CH4OC_BITPOS) |
                                (AlertEnable_reg.CH1_UC << PAC194X5X_ALERT_CH1UC_BITPOS) |
                                (AlertEnable_reg.CH2_UC << PAC194X5X_ALERT_CH2UC_BITPOS) |
                                (AlertEnable_reg.CH3_UC << PAC194X5X_ALERT_CH3UC_BITPOS) |
                                (AlertEnable_reg.CH4_UC << PAC194X5X_ALERT_CH4UC_BITPOS); 
    
    pdevice->i2cTxBuffer[2] =   (AlertEnable_reg.CH1_OV << PAC194X5X_ALERT_CH1OV_BITPOS) |
                                (AlertEnable_reg.CH2_OV << PAC194X5X_ALERT_CH2OV_BITPOS) |
                                (AlertEnable_reg.CH3_OV << PAC194X5X_ALERT_CH3OV_BITPOS) |
                                (AlertEnable_reg.CH4_OV << PAC194X5X_ALERT_CH4OV_BITPOS) |
                                (AlertEnable_reg.CH1_UV << PAC194X5X_ALERT_CH1UV_BITPOS) |
                                (AlertEnable_reg.CH2_UV << PAC194X5X_ALERT_CH2UV_BITPOS) |
                                (AlertEnable_reg.CH3_UV << PAC194X5X_ALERT_CH3UV_BITPOS) |
                                (AlertEnable_reg.CH4_UV << PAC194X5X_ALERT_CH4UV_BITPOS); 

    pdevice->i2cTxBuffer[3] =   (AlertEnable_reg.CH1_OP << PAC194X5X_ALERT_CH1OP_BITPOS) |
                                (AlertEnable_reg.CH2_OP << PAC194X5X_ALERT_CH2OP_BITPOS) |
                                (AlertEnable_reg.CH3_OP << PAC194X5X_ALERT_CH3OP_BITPOS) |
                                (AlertEnable_reg.CH4_OP << PAC194X5X_ALERT_CH4OP_BITPOS) |
                                (AlertEnable_reg.ACC_OVF << PAC194X5X_ALERT_ACCOVF_BITPOS) |
                                (AlertEnable_reg.ACC_COUNT << PAC194X5X_ALERT_ACCCNT_BITPOS) |
                                (AlertEnable_reg.ALERT_CCx << PAC194X5X_ALERT_CC_BITPOS);    
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_ALERT_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetAccFullness_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_PACCUM_LIMITS_REGISTER pAccFullnessLimits_reg){
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAccFullnessRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pAccFullnessLimits_reg;
    pdevice->i2cTxBuffer[0] = PAC194X5X_ACC_FULLNESS_LIMITS_ADDR;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetAccFullness_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    ((PAC194X5X_PACCUM_LIMITS_REGISTER)pdevice->outData)->ACC_CH1 = (pRawValue[0] >> PAC194X5X_ACCLIMITS_CH1_BITPOS) & PAC194X5X_ACCLIMITS_BITMASK;
    ((PAC194X5X_PACCUM_LIMITS_REGISTER)pdevice->outData)->ACC_CH2 = (pRawValue[0] >> PAC194X5X_ACCLIMITS_CH2_BITPOS) & PAC194X5X_ACCLIMITS_BITMASK;
    ((PAC194X5X_PACCUM_LIMITS_REGISTER)pdevice->outData)->ACC_CH3 = (pRawValue[0] >> PAC194X5X_ACCLIMITS_CH3_BITPOS) & PAC194X5X_ACCLIMITS_BITMASK;
    ((PAC194X5X_PACCUM_LIMITS_REGISTER)pdevice->outData)->ACC_CH4 = (pRawValue[0] >> PAC194X5X_ACCLIMITS_CH4_BITPOS) & PAC194X5X_ACCLIMITS_BITMASK;
    
    ((PAC194X5X_PACCUM_LIMITS_REGISTER)pdevice->outData)->ACC_COUNT = (pRawValue[1] >> PAC194X5X_ACCLIMITS_COUNT_BITPOS) & PAC194X5X_ACCLIMITS_BITMASK;
    
    return PAC194X5X_SUCCESS;     
}


int16_t PAC194x5x_SetAccFullness_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, PAC194X5X_ACCUM_LIMITS_REGISTER AccFullnessLimits_reg){
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetAccFullnessRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->i2cTxBuffer[0] = PAC194X5X_ACC_FULLNESS_LIMITS_ADDR;  
    pdevice->i2cTxBuffer[1] =   (AccFullnessLimits_reg.ACC_CH1 << PAC194X5X_ACCLIMITS_CH1_BITPOS) |
                                (AccFullnessLimits_reg.ACC_CH2 << PAC194X5X_ACCLIMITS_CH2_BITPOS) |
                                (AccFullnessLimits_reg.ACC_CH3 << PAC194X5X_ACCLIMITS_CH3_BITPOS) |
                                 AccFullnessLimits_reg.ACC_CH4;
            
    pdevice->i2cTxBuffer[2] =   AccFullnessLimits_reg.ACC_COUNT << PAC194X5X_ACCLIMITS_COUNT_BITPOS;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_OTHERLIMIT_SZ, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS; 
}


int16_t PAC194x5x_GetOClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOClimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOClimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mA
int16_t PAC194x5x_GetOClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOClimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
            
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOClimit_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t limitRegister;
    int16_t signedReg;
    int32_t tempProd;
    float limitReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    limitRegister = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    signedReg = (int16_t)limitRegister; // limit register is always signed
    tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseFSR;
    limitReal = (float)tempProd * 1000000.0;
    limitReal /= pdevice->rsense[pdevice->channelNo - 1];     //mA
    limitReal = limitReal / 32768.0;

    *((float*)pdevice->outData) = limitReal;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOClimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->i2cTxBuffer[1] = (register_val >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = register_val & 0xff;
            
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value){
    uint8_t registerAddr;
    uint16_t limitRegister;
    float maxLimit;
    float flimit;
    int16_t ilimit;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOClimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //compute the device maximum supported current limit = VsenseFSR / Rsense
    maxLimit = (float)pdevice->VsenseFSR * 1000000;
    maxLimit /= (float)pdevice->rsense[channelNo-1];

    if(value >= maxLimit){
        //if the requested limit value is above the device +FSR,
        //set the limit register to the max positive value
        limitRegister = 0x7fff; //32767
    }else if(value < (-maxLimit)){
        //if the requested limit value is below the device -FSR,
        //set the limit register to the min negative value        
        limitRegister = 0x8000; //-32768
    }else{
        //compute the limit register = value * 2^15 * Rsense / VsenseFSR  
        flimit = value * 32768.0 / maxLimit;
        ilimit = (int16_t)flimit;
        limitRegister = (uint16_t)ilimit;
    }

    pdevice->i2cTxBuffer[0] = registerAddr; 
    pdevice->i2cTxBuffer[1] = (limitRegister >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = limitRegister & 0xff;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetUClimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUClimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mA
int16_t PAC194x5x_GetUClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetUClimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
            
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUClimit_mAProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t limitRegister;
    int16_t signedReg;
    int32_t tempProd;
    float limitReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    limitRegister = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    signedReg = (int16_t)limitRegister; // limit register is always signed
    tempProd = (int32_t)signedReg * (int32_t)pdevice->VsenseFSR;
    limitReal = (float)tempProd * 1000000.0;
    limitReal /= pdevice->rsense[pdevice->channelNo - 1];     //mA
    limitReal = limitReal / 32768.0;

    *((float*)pdevice->outData) = limitReal;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetUClimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetUClimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    pdevice->i2cTxBuffer[0] = registerAddr; 
    pdevice->i2cTxBuffer[1] = (register_val >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = register_val & 0xff;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetUClimit_mA(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value){
    uint8_t registerAddr;
    uint16_t limitRegister;
    float maxLimit;
    float flimit;
    int16_t ilimit;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetUClimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UC_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UC_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UC_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //compute the device maximum supported current limit = VsenseFSR / Rsense
    maxLimit = (float)pdevice->VsenseFSR * 1000000;
    maxLimit /= (float)pdevice->rsense[channelNo-1];

    if(value >= maxLimit){
        //if the requested limit value is above the device +FSR,
        //set the limit register to the max positive value
        limitRegister = 0x7fff; //32767
    }else if(value < (-maxLimit)){
        //if the requested limit value is below the device -FSR,
        //set the limit register to the min negative value        
        limitRegister = 0x8000; //-32768
    }else{
        //compute the limit register = value * 2^15 * Rsense / VsenseFSR  
        flimit = value * 32768.0 / maxLimit;
        ilimit = (int16_t)flimit;
        limitRegister = (uint16_t)ilimit;
    }

    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->i2cTxBuffer[1] = (limitRegister >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = limitRegister & 0xff;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOPlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOPlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OP_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OP_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OP_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_OPLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOPlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    
    *((uint32_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mW
int16_t PAC194x5x_GetOPlimit_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOPlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OP_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OP_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OP_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
            
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OPLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOPlimit_mWProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t limitRegister;
    int32_t signedReg;
    float PowerUnit;
    float limitReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    limitRegister = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    limitRegister = (limitRegister << 8) | (uint32_t)pRawValue[2];
    
    //sign extend the 24-bit OP limit register
    if ((limitRegister >> 23) & 0x1) {
        limitRegister = limitRegister | ~0xFFFFFFLL;    //sign extension
    }    
    signedReg = (int32_t)limitRegister; // limit register is always signed

    PowerUnit = (float)pdevice->VPowerFSR * 1000000 / (pdevice->rsense[pdevice->channelNo - 1]);
    PowerUnit /= 8388608.0;   // milli-Watts/bit  

    limitReal = (float)signedReg * PowerUnit;
    if(pdevice->LowSide == 1) limitReal *= pdevice->VrailToVbusRatio[pdevice->channelNo - 1];
    
    *((float*)pdevice->outData) = limitReal;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOPlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t register_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOPlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OP_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OP_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OP_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;

    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->i2cTxBuffer[1] = (register_val >> 16) & 0xff; 
    pdevice->i2cTxBuffer[2] = (register_val >> 8) & 0xff;
    pdevice->i2cTxBuffer[3] = register_val & 0xff;    
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 4, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOPlimit_mW(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value){
    uint8_t registerAddr;
    uint32_t limitRegister;
    float maxLimit;
    float flimit;
    int32_t ilimit;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOPlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OP_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OP_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OP_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //compute the device maximum supported power limit = VPowerFSR * VrailToVbusRatio / Rsense
    maxLimit = (float)pdevice->VPowerFSR * 1000000;
    if(pdevice->LowSide == 1) maxLimit *= pdevice->VrailToVbusRatio[channelNo-1];
    maxLimit /= (float)pdevice->rsense[channelNo-1];

    if(value >= maxLimit){
        //if the requested limit value is above the device +FSR,
        //set the limit register to the max positive value
        limitRegister = 0x7fffff; //8388607
    }else if(value < (-maxLimit)){
        //if the requested limit value is below the device -FSR,
        //set the limit register to the min negative value        
        limitRegister = 0x800000; //-8388608
    }else{
        //compute the limit register = value * 2^23 * Rsense / (VsenseFSR * VrailToVbusRatio)  
        flimit = value * 8388608.0 / maxLimit;
        ilimit = (int32_t)flimit;
        limitRegister = (uint32_t)ilimit;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->i2cTxBuffer[1] = (limitRegister >> 16) & 0xff;
    pdevice->i2cTxBuffer[2] = (limitRegister >> 8) & 0xff;
    pdevice->i2cTxBuffer[3] = limitRegister & 0xff;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 4, &(pdevice->transferHandle));    
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOVlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOVlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mV
int16_t PAC194x5x_GetOVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetOVlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
            
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetOVlimit_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t limitRegister;
    int16_t signedReg;
    int32_t tempProd;
    float limitReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    limitRegister = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    signedReg = (int16_t)limitRegister; // limit register is always signed
    tempProd = (int32_t)signedReg * (int32_t)pdevice->VbusFSR;
    limitReal = (float)tempProd / 32768.0;    //mV
    if(pdevice->LowSide == 1) limitReal *= pdevice->VrailToVbusRatio[pdevice->channelNo - 1]; 

    *((float*)pdevice->outData) = limitReal;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOVlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    pdevice->i2cTxBuffer[0] = registerAddr; 
    pdevice->i2cTxBuffer[1] = (register_val >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = register_val & 0xff;
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetOVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value){
    uint8_t registerAddr;
    uint16_t limitRegister;
    float maxLimit;
    float flimit;
    int16_t ilimit;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetOVlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_OV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_OV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //compute the maximum supported voltage limit = VbusFSR * VrailToVbusRatio
    maxLimit = (float)pdevice->VbusFSR;
    if(pdevice->LowSide == 1) maxLimit *= pdevice->VrailToVbusRatio[channelNo-1];

    if(value >= maxLimit){
        //if the requested limit value is above the device +FSR,
        //set the limit register to the max positive value
        limitRegister = 0x7fff; //32767
    }else if(value < (-maxLimit)){
        //if the requested limit value is below the device -FSR,
        //set the limit register to the min negative value        
        limitRegister = 0x8000; //-32768
    }else{
        //compute the limit register = value * 2^15 / (VbusFSR * VrailToVbusRatio)   
        flimit = value * 32768.0 / maxLimit;
        ilimit = (int16_t)flimit;
        limitRegister = (uint16_t)ilimit;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr; 
    pdevice->i2cTxBuffer[1] = (limitRegister >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = limitRegister & 0xff;    
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetUVlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUVlimit_regProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC194X5X_SUCCESS;
}

//pvalue reported as mV
int16_t PAC194x5x_GetUVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetUVlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
            
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetUVlimit_mVProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t limitRegister;
    int16_t signedReg;
    int32_t tempProd;
    float limitReal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    limitRegister = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    signedReg = (int16_t)limitRegister; // limit register is always signed
    tempProd = (int32_t)signedReg * (int32_t)pdevice->VbusFSR;
    limitReal = (float)tempProd / 32768.0;    //mV
    if(pdevice->LowSide == 1) limitReal *= pdevice->VrailToVbusRatio[pdevice->channelNo - 1]; 

    *((float*)pdevice->outData) = limitReal;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetUVlimit_reg(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t register_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetUVlimitRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->i2cTxBuffer[1] = (register_val >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = register_val & 0xff;    
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetUVlimit_mV(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float value){
    uint8_t registerAddr;
    uint16_t limitRegister;
    float maxLimit;
    float flimit;
    int16_t ilimit;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetUVlimitValueReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC194X5X_UV_LIMIT1_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UV_LIMIT2_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_UV_LIMIT3_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_UV_LIMIT4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC194X5X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //compute the maximum supported voltage limit = VbusFSR * VrailToVbusRatio
    maxLimit = (float)pdevice->VbusFSR;
    if(pdevice->LowSide == 1) maxLimit *= pdevice->VrailToVbusRatio[channelNo-1];

    if(value >= maxLimit){
        //if the requested limit value is above the device +FSR,
        //set the limit register to the max positive value
        limitRegister = 0x7fff; //32767
    }else if(value < (-maxLimit)){
        //if the requested limit value is below the device -FSR,
        //set the limit register to the min negative value        
        limitRegister = 0x8000; //-32768
    }else{
        //compute the limit register = value * 2^15 / (VbusFSR * VrailToVbusRatio)   
        flimit = value * 32768.0 / maxLimit;
        ilimit = (int16_t)flimit;
        limitRegister = (uint16_t)ilimit;
    }

    pdevice->i2cTxBuffer[0] = registerAddr;  
    pdevice->i2cTxBuffer[1] = (limitRegister >> 8) & 0xff;
    pdevice->i2cTxBuffer[2] = limitRegister & 0xff;    
    
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 3, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetLimitNsamples(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_PLIMIT_NSAMPLES_REGISTER pLimitNsamples_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    switch(reg_select){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT_N_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT_N_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT_N_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT_N_ADDR;
            break;
        case 5:
            registerAddr = PAC194X5X_UV_LIMIT_N_ADDR;
            break;
        default:
            return PAC194X5X_INVALID_PARAMETER;      
    }    
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetLimitNsamplesRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    pdevice->outData = (void*)pLimitNsamples_reg;
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC194X5X_OTHERLIMIT_N_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED) 
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
    
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_GetLimitNsamplesProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    ((PAC194X5X_PLIMIT_NSAMPLES_REGISTER)pdevice->outData)->Nsamples_CH1 = (pRawValue[0] >> PAC194X5X_LIMITNSAMP_CH1_BITPOS) & PAC194X5X_LIMITNSAMP_BITMASK;
    ((PAC194X5X_PLIMIT_NSAMPLES_REGISTER)pdevice->outData)->Nsamples_CH2 = (pRawValue[0] >> PAC194X5X_LIMITNSAMP_CH2_BITPOS) & PAC194X5X_LIMITNSAMP_BITMASK;
    ((PAC194X5X_PLIMIT_NSAMPLES_REGISTER)pdevice->outData)->Nsamples_CH3 = (pRawValue[0] >> PAC194X5X_LIMITNSAMP_CH3_BITPOS) & PAC194X5X_LIMITNSAMP_BITMASK;
    ((PAC194X5X_PLIMIT_NSAMPLES_REGISTER)pdevice->outData)->Nsamples_CH4 = (pRawValue[0] >> PAC194X5X_LIMITNSAMP_CH4_BITPOS) & PAC194X5X_LIMITNSAMP_BITMASK;
        
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_SetLimitNsamples(PAC194X5X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC194X5X_LIMIT_NSAMPLES_REGISTER LimitNsamples_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC194X5X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC194x5x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC194X5X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetLimitNsamplesRegisterReq;
        pdevice->deviceEventStatus = PAC194X5X_EVENT_NO_EVENT;
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC194x5x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC194X5X_BUSY;
    }
    
    switch(reg_select){
        case 1:
            registerAddr = PAC194X5X_OC_LIMIT_N_ADDR;
            break;
        case 2:
            registerAddr = PAC194X5X_UC_LIMIT_N_ADDR;
            break;
        case 3:
            registerAddr = PAC194X5X_OP_LIMIT_N_ADDR;
            break;
        case 4:
            registerAddr = PAC194X5X_OV_LIMIT_N_ADDR;
            break;
        case 5:
            registerAddr = PAC194X5X_UV_LIMIT_N_ADDR;
            break;
        default:
            return PAC194X5X_INVALID_PARAMETER;      
    }  
        
    pdevice->i2cTxBuffer[0] = registerAddr; 
    pdevice->i2cTxBuffer[1] =   (LimitNsamples_reg.Nsamples_CH1 << PAC194X5X_LIMITNSAMP_CH1_BITPOS) |
                                (LimitNsamples_reg.Nsamples_CH2 << PAC194X5X_LIMITNSAMP_CH2_BITPOS) |
                                (LimitNsamples_reg.Nsamples_CH3 << PAC194X5X_LIMITNSAMP_CH3_BITPOS) |
                                 LimitNsamples_reg.Nsamples_CH4;
    pdevice->transferHandle = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC194x5x_I2C_WriteTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer, 1+PAC194X5X_OTHERLIMIT_N_SZ, &(pdevice->transferHandle));
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    if(pdevice->transferHandle == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC194X5X_I2C_INVALID_PARAM;
    }
#endif
       
    // wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC194X5X_EVENT_REQUEST_COMPLETE ){
            return PAC194X5X_REQUEST_FAIL;
        }
    }    
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_UpdateContext_ChannelPolarity(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t registerAddr;
    uint16_t errorCode = PAC194X5X_SUCCESS;

    // Check if the cached negPwrFsr_LAT is valid
    if(pdevice->negPwr_LAT_cached == false){
        registerAddr = PAC194X5X_NEG_PWR_FSR_LAT_ADDR;
                
        pdevice->i2cTxBuffer_negPwr[0] = registerAddr;
        pdevice->transferHandle_negPwr = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        
        unsigned int i2cRxSize = PAC194X5X_NEGPWRFSR_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
        PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_negPwr, 1, (void*) pdevice->i2cRxBuffer_negPwr, i2cRxSize, &(pdevice->transferHandle_negPwr));            
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
        if(pdevice->transferHandle_negPwr == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            return PAC194X5X_I2C_INVALID_PARAM;
        }
#endif    
    }
    else
    {
        errorCode = PAC194X5X_ALREADY_CACHED;
    }
    
   return errorCode; 
}


int16_t PAC194x5x_UpdateContext_ChannelPolarityProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint8_t isSignedPower = 0;
    uint8_t isSignedVbus = 0;
    uint8_t isSignedVsense = 0;
    uint8_t cfgVSense = 0;
    uint8_t cfgVBus = 0;
    uint16_t VpowerFSR;
    uint16_t VbusFSR;
    uint16_t VsenseFSR;    
    uint16_t errorCode = PAC194X5X_SUCCESS;
    int channelNo;
    
    pRawValue = pdevice->i2cRxBuffer_negPwr;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    (pdevice->negPwrFsr_LAT).CFG_VS1 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS1_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VS2 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS2_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VS3 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS3_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VS4 = (pRawValue[0] >> PAC194X5X_NEGPWRFSR_VS4_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;    
    (pdevice->negPwrFsr_LAT).CFG_VB1 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB1_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VB2 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB2_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VB3 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB3_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;
    (pdevice->negPwrFsr_LAT).CFG_VB4 = (pRawValue[1] >> PAC194X5X_NEGPWRFSR_VB4_BITPOS) & PAC194X5X_NEGPWRFSR_BITMASK;    
    
    pdevice->negPwr_LAT_cached = true;
    
    // Update the cached channel polarity info
    //
    // Check the cached NEG_PWR register.
    // - If either VSense or VBus is bipolar, the chanel is bipolar
    // - If either VSense or VBus is FSR/2, the channel is "FSR/2 mode" and bipolar
    //
    for(channelNo = 1; channelNo <= pdevice->HwChannels; channelNo++){
        switch (channelNo){
            case 1:{
                cfgVSense = pdevice->negPwrFsr_LAT.CFG_VS1;     // NegPwrFsr.CFG_VS1;
                cfgVBus = pdevice->negPwrFsr_LAT.CFG_VB1;       // NegPwrFsr.CFG_VB1;
                break;
            }

            case 2:{
                cfgVSense = pdevice->negPwrFsr_LAT.CFG_VS2;     // NegPwrFsr.CFG_VS2;
                cfgVBus = pdevice->negPwrFsr_LAT.CFG_VB2;       //  NegPwrFsr.CFG_VB2;
                break;
            }

            case 3:{
                cfgVSense = pdevice->negPwrFsr_LAT.CFG_VS3;     // NegPwrFsr.CFG_VS3;
                cfgVBus = pdevice->negPwrFsr_LAT.CFG_VB3;       // NegPwrFsr.CFG_VB3;
                break;
            }

            case 4:{
                cfgVSense = pdevice->negPwrFsr_LAT.CFG_VS4;     // NegPwrFsr.CFG_VS4;
                cfgVBus = pdevice->negPwrFsr_LAT.CFG_VB4;       // NegPwrFsr.CFG_VB4;
                break;
            }

            default:{
                errorCode = PAC194X5X_INVALID_PARAMETER;
                return errorCode;   
            }
        }
        
        // init power factor FSR
        VpowerFSR = pdevice->VPowerFSR;
        // init voltage FSR
        VbusFSR = pdevice->VbusFSR;
        VsenseFSR = pdevice->VsenseFSR;
        
        isSignedPower = 0;
        isSignedVbus = 0;
        isSignedVsense = 0; 
        
        if (cfgVSense == 0x1) {
            VsenseFSR *= 2; // LSB value is double for bipolar channels

        }

        if (cfgVBus == 0x1) {
            VbusFSR *= 2; // LSB value is double for bipolar channels
        }

        if ((cfgVSense | cfgVBus) == 0x1) {
            VpowerFSR *= 2; // LSB value is double for "bipolar mode" channels
                            // either Vbus or Vsense are bipolar and no one is FSR/2
        }

        if ( cfgVSense  != 0x0) {
            isSignedPower  = 1;     // either Vbus or Vsense are bipolar or FSR/2
            isSignedVsense = 1;     // Vsense is bipolar
        }

        if ( cfgVBus != 0x0) {
            isSignedPower = 1;      // either Vbus or Vsense are bipolar or FSR/2
            isSignedVbus  = 1;      // Vbus is bipolar
        }    

        (pdevice->VbusScale[channelNo - 1]) = VbusFSR;
        (pdevice->VsenseScale[channelNo - 1]) = VsenseFSR;
        (pdevice->VPowerScale[channelNo - 1]) = VpowerFSR;
        (pdevice->IsSignedPower[channelNo - 1]) = isSignedPower;
        (pdevice->IsSignedVsense[channelNo - 1]) = isSignedVsense;
        (pdevice->IsSignedVbus[channelNo - 1]) = isSignedVbus;

        // ScaleValues_cached[channelNo-1] is now valid
        // set the "cached" flag to true
        pdevice->ScaleValues_cached[channelNo-1] = true;
    }
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_UpdateContext_Ctrl(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode = PAC194X5X_SUCCESS;
    uint8_t registerAddr;
         
    //check if cached CTRL_LAT is valid
    //if NOT valid, update the cache
    if(pdevice->ctrl_LAT_cached == false){
        registerAddr = PAC194X5X_CTRL_LAT_ADDR;
        pdevice->i2cTxBuffer_ctrl[0] = registerAddr;
        pdevice->transferHandle_ctrl = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        
        unsigned int i2cRxSize = PAC194X5X_CTRL_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
        PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_ctrl, 1, (void*) pdevice->i2cRxBuffer_ctrl, i2cRxSize, &(pdevice->transferHandle_ctrl));            
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
        if(pdevice->transferHandle_ctrl == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            return PAC194X5X_I2C_INVALID_PARAM;
        }
#endif      
    }
    else
    {
        errorCode = PAC194X5X_ALREADY_CACHED;
    }
    
    return errorCode;
}

int16_t PAC194x5x_UpdateContext_CtrlProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_ctrl;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    (pdevice->ctrl_LAT).SAMPLE_MODE = (pRawValue[0] >> PAC194X5X_CTRL_SAMPLE_MODE_BITPOS) & PAC194X5X_CTRL_SAMPLE_MODE_BITMASK;
    (pdevice->ctrl_LAT).GPIO_ALERT2 = (pRawValue[0] >> PAC194X5X_CTRL_GPIO_ALERT2_BITPOS) & PAC194X5X_CTRL_GPIO_ALERT_BITMASK;
    (pdevice->ctrl_LAT).SLOW_ALERT1 = (pRawValue[0] >> PAC194X5X_CTRL_SLOW_ALERT1_BITPOS) & PAC194X5X_CTRL_GPIO_ALERT_BITMASK;
    (pdevice->ctrl_LAT).CH1_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH1_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK;
    (pdevice->ctrl_LAT).CH2_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH2_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK;
    (pdevice->ctrl_LAT).CH3_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH3_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK; 
    (pdevice->ctrl_LAT).CH4_OFF = (pRawValue[1] >> PAC194X5X_CTRL_CH4_OFF_BITPOS) & PAC194X5X_CTRL_CHN_OFF_BITMASK; 
       
    pdevice->ctrl_LAT_cached = true;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_UpdateContext_AccumConfig(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode = PAC194X5X_SUCCESS;
    uint8_t registerAddr;
         
    //check if cached accumConfig_LAT is valid
    //if NOT valid, update the cache
    if(pdevice->accumConfig_LAT_cached == false){
        registerAddr = PAC194X5X_ACCUM_CONFIG_LAT_ADDR;
        pdevice->i2cTxBuffer_accumConfig[0] = registerAddr;
        pdevice->transferHandle_accumConfig = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        
        unsigned int i2cRxSize = PAC194X5X_ACCUMCONFIG_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
        PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_accumConfig, 1, (void*) pdevice->i2cRxBuffer_accumConfig, i2cRxSize, &(pdevice->transferHandle_accumConfig));            
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
        if(pdevice->transferHandle_accumConfig == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            return PAC194X5X_I2C_INVALID_PARAM;
        }
#endif       
    }
    else
    {
        errorCode = PAC194X5X_ALREADY_CACHED;
    }
    
    return errorCode;
}


int16_t PAC194x5x_UpdateContext_AccumConfigProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_accumConfig;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    (pdevice->accumConfig_LAT).ACC1_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC1_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    (pdevice->accumConfig_LAT).ACC2_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC2_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    (pdevice->accumConfig_LAT).ACC3_CONFIG = (pRawValue[0] >> PAC194X5X_ACCCFG_ACC3_BITPOS) & PAC194X5X_ACCCFG_BITMASK;
    (pdevice->accumConfig_LAT).ACC4_CONFIG =  pRawValue[0] & PAC194X5X_ACCCFG_BITMASK;
    
    pdevice->accumConfig_LAT_cached = true;
    
    return PAC194X5X_SUCCESS;
}


int16_t PAC194x5x_UpdateContext_AccumulatorCount(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode;
    //check if cached ACC_COUNT is valid
    //if NOT valid, update the cache
    if(pdevice->accCount_cached == false){
        pdevice->i2cTxBuffer_accCount[0] = PAC194X5X_ACC_COUNT_ADDR;
        pdevice->transferHandle_accCount = PAC194X5X_I2C_TRANSFER_HANDLE_INVALID;
        unsigned int i2cRxSize = PAC194X5X_ACC_COUNT_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
        PAC194x5x_I2C_WriteReadTransferAdd(pdevice->i2cParams, (void*) pdevice->i2cTxBuffer_accCount, 1, (void*) pdevice->i2cRxBuffer_accCount, i2cRxSize, &(pdevice->transferHandle_accCount));        
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
        if(pdevice->transferHandle_accCount == PAC194X5X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            pdevice->processingState = Idle;
            return PAC194X5X_I2C_INVALID_PARAM;
        }
#endif        
    }
    else
    {
        errorCode = PAC194X5X_ALREADY_CACHED;
    }    
    return errorCode;
}


int16_t PAC194x5x_UpdateContext_AccumulatorCountProcess(PAC194X5X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
        
    pRawValue = pdevice->i2cRxBuffer_accCount;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];
    pdevice->accCount = regVal;
    
    pdevice->accCount_cached = true;
    
    return PAC194X5X_SUCCESS;
}