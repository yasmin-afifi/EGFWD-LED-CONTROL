/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  IntCtrl
 *
 *  Description:  Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver    
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "common_macros.h"
#include "std_types.h"
#include "IntCtrl_Cfg.h"




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define Enable_Exceptions()    		__asm("CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   		__asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        		__asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       		__asm("CPSID F") 

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   		__asm("WFI")



#define NVIC_PRI0_REG             (*((volatile unsigned long *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile unsigned long *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile unsigned long *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile unsigned long *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile unsigned long *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile unsigned long *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile unsigned long *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile unsigned long *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile unsigned long *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile unsigned long *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile unsigned long *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile unsigned long *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile unsigned long *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile unsigned long *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile unsigned long *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile unsigned long *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile unsigned long *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile unsigned long *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile unsigned long *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile unsigned long *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile unsigned long *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile unsigned long *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile unsigned long *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile unsigned long *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile unsigned long *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile unsigned long *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile unsigned long *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile unsigned long *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile unsigned long *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile unsigned long *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile unsigned long *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))

/*****************************************************************************
SCB Registers
*****************************************************************************/
#define NVIC_SYSTEM_PRI1_REG      (*((volatile unsigned long *)0xE000ED18))
#define NVIC_SYSTEM_PRI2_REG      (*((volatile unsigned long *)0xE000ED1C))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile unsigned long *)0xE000ED20))
#define NVIC_SYSTEM_SYSHNDCTRL    (*((volatile unsigned long *)0xE000ED24))
#define NVIC_SYSTEM_INTCTRL       (*((volatile unsigned long *)0xE000ED04))
#define NVIC_SYSTEM_CFGCTRL       (*((volatile unsigned long *)0xE000ED14))


#define APINT                     (*((volatile uint32 *)0xE000ED0C))


#define VECTKEY                    0x05FA

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
		MEM_MANAG_FAULT=-7,
    BUS_FAULT,
    USAGE_FAULT,
    SVC,
    DEBUG,
    PENDSV,
    SYSTICK,
    
	
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM_FAULT,
    PWM_GEN_0,
    PWM_GEN_1,
    PWM_GEN_2,
    QUAD_ENCODER,
    ADC_SEQ_0,
    ADC_SEQ_1,
    ADC_SEQ_2,
    ADC_SEQ_3,
    WATCHDOG,
    TIMER0_A,
    TIMER0_B,
    TIMER1_A,
    TIMER1_B,
    TIMER2_A,
    TIMER2_B,
    COMP0,
    COMP1,
    COMP2,
    SYSTEM_CONTROL,
    FLASH_CONTROL,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    UART2,
    SSI1,
    TIMER_3A,
    TIMER_3B,
    I2C1,
    QUAD_ENCODER1,
    CAN0,
    CAN1,
    CAN2,
    ETHERNET,
    HIBERNATE,
    USB0,
    PWM_GEN_3,
    UDMA_SOFT_TFR,
    UDMA_ERROR,
	
	
}IntCtrl_InterruptType;	

typedef enum
{
	NVIC_PRI_GR8_SUBGR1 = 0x4,
	NVIC_PRI_GR4_SUBGR2,
	NVIC_PRI_GR2_SUBGR4,
	NVIC_PRI_GR1_SUBGR8
	
	
}IntCtrl_Gr_Sub;


typedef enum 
{
DIS,
ENA,
NONE
}IntCtrl_En_Dis;


typedef  uint8 IntCtrl_IntGroup;
typedef  uint8 IntCtrl_IntSubGroup;

typedef struct 
{
    IntCtrl_InterruptType intType;
    IntCtrl_En_Dis ED;
    IntCtrl_IntGroup intGroup;
    IntCtrl_IntSubGroup intSubGroup; 
}IntCtrl_Cfg;



extern const IntCtrl_Cfg IntCtrl_Configuration[NO_OF_INT];

extern const uint8 IntCtrl_Gr_SubGr_cfg;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Interrupt Initialization Function*/
void IntCtrl_init(void);


#endif  /* INTCTRL_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
