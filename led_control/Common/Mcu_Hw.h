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

typedef union
{
	struct 
	{
    uint32 PMC0	  :4; /* Port Mux Control 0, This field controls the configuration for GPIO pin 0. */
		uint32 PMC1   :4; /* Port Mux Control 1, This field controls the configuration for GPIO pin 1. */
		uint32 PMC2   :4; /* Port Mux Control 2, This field controls the configuration for GPIO pin 2. */
		uint32 PMC3   :4; /* Port Mux Control 3, This field controls the configuration for GPIO pin 3. */
		uint32 PMC4   :4; /* Port Mux Control 4, This field controls the configuration for GPIO pin 4. */
		uint32 PMC5   :4; /* Port Mux Control 5, This field controls the configuration for GPIO pin 5. */
		uint32 PMC6   :4; /* Port Mux Control 6, This field controls the configuration for GPIO pin 6. */
		uint32 PMC7   :4;	/* Port Mux Control 7, This field controls the configuration for GPIO pin 7. */	
	} FIELDS;
    uint32 REG;
}GPIOPCTL_Tag___;

typedef union
{
	struct 
	{
    uint32 PMC	 :4; /* Port Mux Control 0, This field controls the configuration for GPIO pin 0. */
	} PINS[8];
    uint32 REG;
}GPIOPCTL_Tag;

typedef union
{
	struct 
	{
    uint32 SYSENABLE :1;
		uint32 INTEN	   :1;
		uint32 CLK_SRC   :1;
		uint32 RESERVED  :13;
		uint32 COUNT		 :1;
	} FIELDS;
    uint32 REG;
}STCTRL_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDR		             0xE000E000
#define SYSTEM_CONTROL_REG_BASE_ADDR					 0x400FE000
/* Interrupt Control registers */
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDR+0xD04))
#define NVIC_INTERRUPTS_0_31_ENBALE						 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x100))
#define NVIC_INTERRUPTS_32_63_ENBALE				 	 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x104))
#define NVIC_INTERRUPTS_64_95_ENBALE					 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x108))
#define NVIC_INTERRUPTS_96_127_ENBALE					 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x10C))
#define NVIC_INTERRUPTS_128_138_ENBALE				 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDR+0x110))
#define NVIC_PRI_BASE_ADDR										 (CORTEXM4_PERI_BASE_ADDR + 0x400)

/* GPIO Ports registers (AHB access) */
#define RCGCGPIO															 *((volatile uint32*)(SYSTEM_CONTROL_REG_BASE_ADDR + 0x608))
#define GPIO_PORTA_BASE_ADDR  								 (0x40004000)
#define GPIO_PORTB_BASE_ADDR  								 (0x40005000)
#define GPIO_PORTC_BASE_ADDR  								 (0x40006000)
#define GPIO_PORTD_BASE_ADDR  								 (0x40007000)
#define GPIO_PORTE_BASE_ADDR  								 (0x40024000)
#define GPIO_PORTF_BASE_ADDR  								 (0x40025000)
#define GPIODATA_OFFSET												 (0x000)
#define GPIODIR_OFFSET												 (0x400)
#define GPIOIS_OFFSET												   (0x404)
#define GPIOIBE_OFFSET												 (0x408)
#define GPIOIEV_OFFSET												 (0x40C)
#define GPIOIM_OFFSET												   (0x410)
#define GPIORIS_OFFSET												 (0x414)
#define GPIOMIS_OFFSET												 (0x418)
#define GPIOICR_OFFSET												 (0x41C)
#define GPIOAFSEL_OFFSET											 (0x420)
#define GPIODR2R_OFFSET												 (0x500)
#define GPIODR4R_OFFSET												 (0x504)
#define GPIODR8R_OFFSET												 (0x508)
#define GPIOODR_OFFSET												 (0x50C)
#define GPIOPUR_OFFSET												 (0x510)
#define GPIOPDR_OFFSET												 (0x514)
#define GPIOSLR_OFFSET												 (0x518)
#define GPIODEN_OFFSET												 (0x51C)
#define GPIOLOCK_OFFSET												 (0x520)
#define GPIOCR_OFFSET												   (0x524)
#define GPIOAMSEL_OFFSET											 (0x528)
#define GPIOPCTL_OFFSET												 (0x52C)
#define GPIOADCCTL_OFFSET											 (0x530)
#define GPIODMACTL_OFFSET											 (0x534)

#define GPIOPCTL_PIN_MASK											 (0xf) /* Each pin controlled by 4 bits*/

/* Systick registers */
#define STCTRL																((volatile STCTRL_Tag*) (CORTEXM4_PERI_BASE_ADDR + 0x010))
#define STRELOAD                              *((volatile uint32*) (CORTEXM4_PERI_BASE_ADDR + 0x14))
#define STCURRENT															*((volatile uint32*) (CORTEXM4_PERI_BASE_ADDR + 0x18))
	
#define STRELOAD_MASK													(0xFFFFFFUL)
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
