/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digitial Input output driver
 *
 *      \details  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


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
uint32 gPortsAddresses[] = {GPIO_PORTA_BASE_ADDR, GPIO_PORTB_BASE_ADDR, GPIO_PORTC_BASE_ADDR,
													  GPIO_PORTD_BASE_ADDR, GPIO_PORTE_BASE_ADDR, GPIO_PORTF_BASE_ADDR};

/******************************************************************************
* \Syntax          : DIO_LevelType DIO_ReadChannel(DIO_PortType port, DIO_PinType pin)                                      
* \Description     : Read GPIO pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_PortType port, DIO_PinType pin)  
{
	return (DIO_LevelType)((*((volatile uint32*) (gPortsAddresses[port] + GPIODATA_OFFSET + (0x3FC) )) & (1<<pin)) == (1<<pin));
}

/******************************************************************************
* \Syntax          : void DIO_WriteChannel(DIO_PortType port, DIO_PinType pin, DIO_LevelType level)                                     
* \Description     : write on GPIO pin                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void DIO_WriteChannel(DIO_PortType port, DIO_PinType pin, DIO_LevelType level)  
{
	if (level)
	{
		*((volatile uint32*) (gPortsAddresses[port] + GPIODATA_OFFSET + (0x3FC))) |= (1 << pin);
	}
	else
	{
		*((volatile uint32*) (gPortsAddresses[port] + GPIODATA_OFFSET + (0x3FC))) &= ~(1 << pin);
	}
	
}

/******************************************************************************
* \Syntax          : DIO_LevelType DIO_FlipChannel(DIO_PortType port, DIO_PinType pin)                                      
* \Description     : Flip GPIO pin value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

DIO_LevelType DIO_FlipChannel(DIO_PortType port, DIO_PinType pin)  
{
	/* Xoring with ones while we are masking the unwanted bits will flip the pin  without affecting the other pins*/
	return *((volatile uint32*) (gPortsAddresses[port] + GPIODATA_OFFSET + 0x3FC)) ^= (1<<pin); 
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
