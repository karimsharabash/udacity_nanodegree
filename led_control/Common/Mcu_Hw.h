/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef union
{
	struct 
	{
    uint32 VECACT   :8; /* Interrupt Active Vector Number */
    uint32          :3; 
    uint32 RETBASE  :1; /* Return to Base */
    uint32 VECPEND  :7; /* Interrupt Pending Vector Number */
    uint32          :2;
    uint32 ISRPEND  :1; /* Interrupt Pending */
    uint32 ISRPRE   :1; /* Debug Interrupt Handling */
    uint32          :1;
    uint32 PENDSTCLR:1; /* SysTick Clear Pending */
    uint32 PENDSTSET:1; /* SysTick Set Pending */
    uint32 UNPENDSV :1; /* PendSV Clear Pending */
    uint32 PENDSV   :1; /* PendSV Set Pending */
    uint32          :2;
    uint32 NMISET   :1; /* NMI Set Pending */
	} FIELDS;
    uint32 REG;
}INTCTRL_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDR		             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDR+0xD04))
#define NVIC_INTERRUPTS_0_31_ENBALE						 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x100))
#define NVIC_INTERRUPTS_32_63_ENBALE				 	 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x104))
#define NVIC_INTERRUPTS_64_95_ENBALE					 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x108))
#define NVIC_INTERRUPTS_96_127_ENBALE					 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x10C))
#define NVIC_INTERRUPTS_128_138_ENBALE				 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x110))
#define NVIC_PRI_BASE_ADDR										 (CORTEXM4_PERI_BASE_ADDR + 0x400)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(REG,BIT) (REG |= (0x1 << BIT))
#define CLEAR_BIT(REG,BIT) (REG &= ~(0x1 << BIT))
 
#define NVIC_PRIX_REG(IRQN) (((IRQN / 4) * 4) + NVIC_PRI_BASE_ADDR) /* each 4 interrupts share a register */
#define NVIC_PRIX_POS(IRQN) (5 + (8 * (IRQN % 4)))	/* pri 4n at position 5-7, pri 4n+1 at position 13-15, pri 4n+2 at position 21-23 and pri 4n+3 at position 29-31 */


#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
