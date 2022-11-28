/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  General Purpose Input Output pin driver
 *
 *      \details  The Driver Configure All the needed GPIO pins.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static PORT_HandlerCb sPortfHanlderCb;
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
* \Syntax          : void Port_Init(void)                                      
* \Description     : initialize GPIO Module by parsing the Configuration 
*                    into GPIO registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(void)
{
	uint32 idx;
	uint32 portBaseAddr;
	
	for (idx = 0; idx < USED_PINS_COUNT; idx++)
	{
		/* Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register */
		SET_BIT(RCGCGPIO, PORT_CFG_Ports[idx].port);

		portBaseAddr = (uint32)gPortsAddresses[PORT_CFG_Ports[idx].port];
	
		*((volatile uint32*) (portBaseAddr + GPIOLOCK_OFFSET)) = 0x4C4F434B;
		SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOCR_OFFSET)), PORT_CFG_Ports[idx].port);
	
		/* Set the direction of the GPIO port pins by programming the GPIODIR register. */
		
		if (PORT_CFG_Ports[idx].direction)
		{
			SET_BIT(*((volatile uint32*) (portBaseAddr + GPIODIR_OFFSET)), PORT_CFG_Ports[idx].pin);
			DIO_WriteChannel(PORT_CFG_Ports[idx].port, PORT_CFG_Ports[idx].pin, PORT_CFG_Ports[idx].level);
			
			/* Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R
				registers. */
				switch (PORT_CFG_Ports[idx].outCurrent)
				{
					case TWO_MILI:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIODR2R_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					case FOUR_MILI:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIODR4R_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					case EIGHT_MILI:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIODR8R_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					default:
					{
						/* Report an Error */
					}	
				}
		}
		else
		{
			CLEAR_BIT(*((volatile uint32*) (portBaseAddr + GPIODIR_OFFSET)), PORT_CFG_Ports[idx].pin);
			
			/* Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
				the GPIOPUR, GPIOPDR, GPIOODR register */
				switch (PORT_CFG_Ports[idx].internalAttach)
				{
					case PULL_UP:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOPUR_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					case PULL_DOWN:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOPDR_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					case OPEN_DRAIN:
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOODR_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					break;
					default:
					{
						/* Report an Error */
					}	
				}	
				
		}
		
	
		/* Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
			pin is chosen for a bit */
			if (PORT_CFG_Ports[idx].mode == PORTX_PINX_DIO)
			{
				CLEAR_BIT(*((volatile uint32*) (portBaseAddr + GPIOAFSEL_OFFSET)), PORT_CFG_Ports[idx].pin);
				

	
			/* To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. To
				enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the
				GPIOAMSEL register. */
		
			SET_BIT(*((volatile uint32*) (portBaseAddr + GPIODEN_OFFSET)), PORT_CFG_Ports[idx].pin);
			/* Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event,
				and mask of the interrupts for each port.*/
				if (PORT_CFG_Ports[idx].enableInt == TRUE)
				{
					if (PORT_CFG_Ports[idx].intTrig == EDGE)
					{
						CLEAR_BIT(*((volatile uint32*) (portBaseAddr + GPIOIS_OFFSET)), PORT_CFG_Ports[idx].pin);

						if (PORT_CFG_Ports[idx].intEdgeTrig == FALLING)						
						{
							CLEAR_BIT(*((volatile uint32*) (portBaseAddr + GPIOIEV_OFFSET)), PORT_CFG_Ports[idx].pin);
						}
						else
						{
							SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOIS_OFFSET)), PORT_CFG_Ports[idx].pin);
						}
					}
					else
					{
						SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOIS_OFFSET)), PORT_CFG_Ports[idx].pin);
					}
					
					SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOIM_OFFSET)), PORT_CFG_Ports[idx].pin);
				}
				
			}
			else /* Pin will work as a Special function not as DIO*/
			{
				SET_BIT(*((volatile uint32*) (portBaseAddr + GPIOAFSEL_OFFSET)), PORT_CFG_Ports[idx].pin);
				((volatile GPIOPCTL_Tag*) (portBaseAddr + GPIOPCTL_OFFSET))->PINS[PORT_CFG_Ports[idx].pin].PMC =  GPIOPCTL_PIN_MASK & PORT_CFG_Ports[idx].mode;
			}
		}
}

/******************************************************************************
* \Syntax          : void PORTF_RegisterHandlerCb(PORT_HandlerCb portHandlerCb)                                    
* \Description     : Register callback function to the PORTF handler                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void PORTF_RegisterHandlerCb(PORT_HandlerCb portHandlerCb) 
{
	sPortfHanlderCb = portHandlerCb;
}

/******************************************************************************
* \Syntax          : void GPIOF_Handler(void)                                   
* \Description     : GPIOF ISR                              
*                                                                             
* \Sync\Async      : Asynchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIOF_Handler(void)
{
	sPortfHanlderCb();
	
	/* Clear the interrupt */
	*((volatile uint32*) (GPIO_PORTF_BASE_ADDR + GPIOICR_OFFSET)) = 0xff;
}


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
