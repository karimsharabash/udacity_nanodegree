/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  main.c
 *        \brief  application main
 *
 *      \details  Application to control the on and off time of a led
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "Port.h"
#include "Systick.h"
#include "Led.h"
#include "Switch.h"
#include "Platform_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define SYS_CLOCK_FREQ  (16000000) /* Simulator fixed frequency*/
#define MAX_SYSTICK_VALUE (16777215)
#define SYS_CLOCK_FREQ_KHZ (16000UL)
#define MAX_TIME_MS (1100)

/**********************************************************************************************************************
 *  LOCAL VARIABLES 
 *********************************************************************************************************************/
static volatile bool sIsLedOn = FALSE;
static volatile uint32 sOnTime = 600;
static volatile uint32 sOffTime = 600;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void periodicEvent(void)
{
	LED_Toggle(LED_1);
	uint32 waitTime = 0;
	
	if (sIsLedOn == FALSE)
	{
		waitTime = sOnTime * SYS_CLOCK_FREQ_KHZ ;
		sIsLedOn = TRUE;
	}
	else
	{
		waitTime = sOffTime * SYS_CLOCK_FREQ_KHZ;
		sIsLedOn = FALSE;
	}

	Systick_Reload(waitTime - 1);
}

void SwitchsFunctionality(void)
{
		if (LOW == SWITCH_READ(SWITCH_1))
		{
				if ( (sOnTime + 100) <= MAX_TIME_MS)
				{
					sOnTime += 100;
				}					
				if (sOffTime > 0 )
				{
					sOffTime -= 100;
				}
		}
		
		if (LOW == SWITCH_READ(SWITCH_2))
		{
				if ( (sOffTime + 100) <= MAX_TIME_MS)
				{
					sOffTime += 100;
				}				
				if (sOnTime > 0 )
				{
					sOnTime -= 100;
				}
		}
}

int main(void)
{
	uint32 waitTime = 0;
	
	IntCrtl_Init();
	
	Port_Init();
	PORTF_RegisterHandlerCb(SwitchsFunctionality);
	
	Systick_Init();
	Systick_RegisterHandlerCb(periodicEvent);
	
	
	waitTime = sOffTime * SYS_CLOCK_FREQ_KHZ ;
	Systick_Reload(waitTime - 1);
	
	while(1);
	
	return 0;
}

/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/
