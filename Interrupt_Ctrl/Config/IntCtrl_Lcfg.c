/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define INTCTRL_CFG_INTERRUPTS_COUNT 139
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
INTCTRL_CFG_INTCFG IntCrl_Cfg_InterruptsInfo[INTCTRL_CFG_CONFIGURED_INTERRUPTS_COUNT] =
{
	{.intNumber = 0, .intPri.fields.subGroup = 1, .intPri.fields.group = 1}, /* GPIO_PORTA */
	{.intNumber = 1, .intPri.fields.subGroup = 0, .intPri.fields.group = 2}, /* GPIO_PORTB */
	{.intNumber = 2, .intPri.fields.subGroup = 0, .intPri.fields.group = 3}, /* GPIO_PORTC */
	{.intNumber = 3, .intPri.fields.subGroup = 1, .intPri.fields.group = 0}, /* GPIO_PORTD */
	{.intNumber = 4, .intPri.fields.subGroup = 0, .intPri.fields.group = 2}, /* GPIO_PORTE */
	{.intNumber = 5, .intPri.fields.subGroup = 1, .intPri.fields.group = 1}, /* UART0 */
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
