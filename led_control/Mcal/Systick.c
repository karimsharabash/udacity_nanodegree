/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  Systick timer driver
 *
 *      \details  The Driver Configure All the needed Systick registers.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Systick.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static SYSTICK_HandlerCb sSystickCb;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Systick_Init(void) 
{
	/* Enable the interrupt */
	STCTRL->FIELDS.INTEN = ENABLE;
	STCTRL->FIELDS.CLK_SRC = ENABLE;
}

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
void Systick_Disable(void) 
{
	/* Disable the Systick */
	STCTRL->FIELDS.SYSENABLE = DISABLE;
}

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
void Systick_Reload(uint32 value)  
{
	STCTRL->FIELDS.SYSENABLE = DISABLE;
	
	/* Reload  the interrupt */
	STRELOAD = value;
	
	/* Enable the systick */
	STCTRL->FIELDS.SYSENABLE = ENABLE;
}

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
uint32 Systick_GetValue(void) 
{
	/* Return the value of the Systick timer */
	return STCURRENT;
}

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
void Systick_RegisterHandlerCb(SYSTICK_HandlerCb systickCb)
{
	sSystickCb = systickCb;
}

/******************************************************************************
* \Syntax          : void SysTick_Handler(void)                                   
* \Description     : Systick ISR                              
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler(void)
{
	sSystickCb();
}


/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
