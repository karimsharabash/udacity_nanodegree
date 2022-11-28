/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Led.c
 *        \brief  Led control Drover
 *
 *      \details  The Driver Configure the connected Leds.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "Led.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

typedef struct{
	DIO_PortType port;
	DIO_PinType  pin;
}LED_LedPinType;

	static LED_LedPinType sLedsList[LEDS_COUNT]= {{.port = PORTF, .pin = PIN1}, 
																								{.port = PORTF, .pin = PIN2},
																								{.port = PORTF, .pin = PIN3}};
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
* \Syntax          : void LED_TurnOn(LED_LedIdType ledId);                                  
* \Description     : Turn on the led                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_TurnOn(LED_LedIdType ledId)
{
	DIO_WriteChannel(sLedsList[ledId].port, sLedsList[ledId].pin, HIGH); 
}

/******************************************************************************
* \Syntax          : void LED_TurnOff(LED_LedIdType ledId);                                
* \Description     : Turn off the led                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_TurnOff(LED_LedIdType ledId)
{
	DIO_WriteChannel(sLedsList[ledId].port, sLedsList[ledId].pin, LOW); 
}

 /******************************************************************************
* \Syntax          : void LED_Toggle(LED_LedIdType ledId);                                
* \Description     : Turn off the led                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LED_Toggle(LED_LedIdType ledId)
{
	DIO_FlipChannel(sLedsList[ledId].port, sLedsList[ledId].pin);
}


/**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
