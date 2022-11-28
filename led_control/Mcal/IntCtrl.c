/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

#define APINT_VECTKEY 0x05FA0000  
#define APINT_PRIGROUP_POS (0x8)
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


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
		uint32 idx;
		uint32 regAdd;
	  uint32 apintV;
	  /*Configure Grouping\SubGrouping System in APINT register in SCB*/
    apintV = APINT_VECTKEY | (INTCTRL_CFG_GROUPING_OPTION << APINT_PRIGROUP_POS);
	  APINT = apintV;
	  /*	Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    for (idx = 0; idx < INTCTRL_CFG_CONFIGURED_INTERRUPTS_COUNT; idx++)
		{
			if (IntCrl_Cfg_InterruptsInfo[idx].intNumber < 32)
			{
				SET_BIT(NVIC_INTERRUPTS_0_31_ENBALE, IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			} else if (IntCrl_Cfg_InterruptsInfo[idx].intNumber < 64)
			{
				SET_BIT(NVIC_INTERRUPTS_32_63_ENBALE, IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			}else if (IntCrl_Cfg_InterruptsInfo[idx].intNumber < 96)
			{
				SET_BIT(NVIC_INTERRUPTS_64_95_ENBALE, IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			}
			else if (IntCrl_Cfg_InterruptsInfo[idx].intNumber < 128)
			{
				SET_BIT(NVIC_INTERRUPTS_96_127_ENBALE, IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			}else if (IntCrl_Cfg_InterruptsInfo[idx].intNumber < 138)
			{
				SET_BIT(NVIC_INTERRUPTS_128_138_ENBALE, IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			} else
			{
				/* Report an error */
			}
			
			/* Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
			regAdd = NVIC_PRIX_REG(IntCrl_Cfg_InterruptsInfo[idx].intNumber);
			*(volatile uint32*) regAdd |= (IntCrl_Cfg_InterruptsInfo[idx].intPri.value << NVIC_PRIX_POS(IntCrl_Cfg_InterruptsInfo[idx].intNumber));
			
		}
	    
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
