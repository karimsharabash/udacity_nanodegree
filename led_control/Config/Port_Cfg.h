/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Dio.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORTX_PINX_DIO			(0x0) /* Use this pin as DIO no Special function for it*/
#define PORTA_PIN0_SF_UART0 (0x1) /* special function for PinA0 is to work as UART0 RX */
#define PORTA_PIN1_SF_UART0 (0x1) /* special function for PinA1 is to work as UART0 TX */
#define USED_PINS_COUNT  	 	(4)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum{
	INPUT = 0,
	OUTPUT
}PORT_CFG_Dirtype;

typedef enum{
	PULL_UP = 0,
	PULL_DOWN,
	OPEN_DRAIN,
	NO_INTERNAL_ATTACH,
}PORT_CFG_InternalAttachType;

typedef enum{
	TWO_MILI = 0,
	FOUR_MILI,
	EIGHT_MILI,
	DEFAULT,
}PORT_CFG_OutCurrentType;

typedef uint32 PORT_CFG_ModeType;

typedef enum{
	EDGE,
	LEVEL,
}PORT_CFG_IntTrigType;

typedef enum{
	FALLING,
	RISING,
}PORT_CFG_IntEdgeTrigType;

typedef struct{
	DIO_PortType								port;
	DIO_PinType									pin;
	DIO_LevelType								level;
	PORT_CFG_ModeType 					mode;
	PORT_CFG_Dirtype  					direction;
	PORT_CFG_InternalAttachType internalAttach;
	PORT_CFG_OutCurrentType			outCurrent;
	bool												enableInt;
	PORT_CFG_IntTrigType				intTrig;
	PORT_CFG_IntEdgeTrigType		intEdgeTrig;
}PORT_CFG_ConfigType;



extern PORT_CFG_ConfigType PORT_CFG_Ports[];

#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
