/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

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

typedef enum{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PinType;

typedef enum{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
}DIO_PortType;

typedef enum{
	LOW = 0,
	HIGH
}DIO_LevelType;
 
typedef uint8 DIO_PortLvlType;

extern uint32 gPortsAddresses[];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION 
 *********************************************************************************************************************/

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
DIO_LevelType DIO_ReadChannel(DIO_PortType port, DIO_PinType pin);

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
void DIO_WriteChannel(DIO_PortType port, DIO_PinType pin, DIO_LevelType level);

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
DIO_LevelType DIO_FlipChannel(DIO_PortType port, DIO_PinType pin);  


#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
