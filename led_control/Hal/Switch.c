/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Switch.c
 *        \brief  Switch control Drover
 *
 *      \details  The Driver Configure the connected Switchs.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "Switch.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

typedef struct{
	DIO_PortType port;
	DIO_PinType  pin;
}SWITCH_SwitchPinType;

	static SWITCH_SwitchPinType sSwitchsList[SWITCHS_COUNT]= {{.port = PORTF, .pin = PIN4}, 
																														{.port = PORTF, .pin = PIN0}};
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
* \Syntax          : SWITCH_LvlType SWITCH_READ(SWITCH_SwitchIdType SwitchId);                                 
* \Description     : Read the value of the switch                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
SWITCH_LvlType SWITCH_READ(SWITCH_SwitchIdType switchId)
{
	SWITCH_LvlType level =  DIO_ReadChannel(sSwitchsList[switchId].port, sSwitchsList[switchId].pin);
	return level;
}


/**********************************************************************************************************************
 *  END OF FILE: Switch.c
 *********************************************************************************************************************/