/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYSTICK.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef void (*SYSTICK_HandlerCb) (void);
/**********************************************************************************************************************
 *  GLOBAL FUNCTION 
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Systick_Init(void)                                      
* \Description     : Init the Systick timer                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Init(void);

/******************************************************************************
* \Syntax          : void Systick_RegisterHandlerCb(SYSTICK_HandlerCb)                                    
* \Description     : Register callback function to the systick handler                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_RegisterHandlerCb(SYSTICK_HandlerCb systickCb);

/******************************************************************************
* \Syntax          : void Systick_Disable(void)                                      
* \Description     : Disable the Systick timer                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Disable(void);

/******************************************************************************
* \Syntax          : void Systick_Reload(uint32 value)                                      
* \Description     : Reload the Systick timer by the needed value and enable the Systick timer.                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Systick_Reload(uint32 value);

/******************************************************************************
* \Syntax          : uint32 Systick_GetValue(void)                                      
* \Description     : Get the current value of the Systick timer.                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
uint32 Systick_GetValue(void);
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
