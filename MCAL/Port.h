/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  Header file for TM4C123GH6PM Microcontroller - Port Driver    
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "common_macros.h"
#include "std_types.h"
#include "Port_Cfg.h"




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PIN0            (Port_PinType)0 
#define PIN1            (Port_PinType)1 
#define PIN2            (Port_PinType)2
#define PIN3            (Port_PinType)3 
#define PIN4            (Port_PinType)4 
#define PIN5            (Port_PinType)5 
#define PIN6            (Port_PinType)6 
#define PIN7            (Port_PinType)7

#define PORTA_PORT 					0
#define PORTB_PORT 					1
#define PORTC_PORT 					2
#define PORTD_PORT 					3
#define PORTE_PORT 					4
#define PORTF_PORT 					5


#define ADC  (Port_PinModeType)0x00
#define ALT1 (Port_PinModeType)0x01
#define ALT2 (Port_PinModeType)0x02
#define ALT3 (Port_PinModeType)0x03
#define ALT4 (Port_PinModeType)0x04
#define ALT5 (Port_PinModeType)0x05
#define ALT6 (Port_PinModeType)0x06
#define ALT7 (Port_PinModeType)0x07
#define ALT8 (Port_PinModeType)0x08
#define ALT9 (Port_PinModeType)0x09
#define DIO  (Port_PinModeType)0x0A


/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile unsigned long *)0x4000452C))


/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile unsigned long *)0x4000552C))


/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile unsigned long *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile unsigned long *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile unsigned long *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile unsigned long *)0x4000652C))


/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile unsigned long *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile unsigned long *)0x4000752C))


/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile unsigned long *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile unsigned long *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile unsigned long *)0x4002452C))


/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile unsigned long *)0x4002552C))


#define SYSCTL_REGCGC2_REG        (*((volatile unsigned long *)0x400FE108))

#define UNLOCK_GPIOCR                   0x4C4F434B


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/




typedef uint8 Port_PinType;

typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;
 
typedef uint8 Port_PinModeType ;

typedef enum
{
    PULL_UP = 0,PULL_DOWN, OPENDRIN
}Port_PinInternalAttachType;

typedef uint8 Port_PinOutputCurrentType;

typedef struct 
{
    uint8 port_num; 
    Port_PinType pin_num; 
    Port_PinDirectionType direction;
    Port_PinModeType Mode;
    Port_PinInternalAttachType resistor;
    uint8 initial_value;
}Port_Config;


typedef struct
{
Port_Config Pins[NO_OF_CHANNLES];
}Port_ConfigType;


extern const Port_ConfigType Port_Configuration;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Port Init Function*/
void Port_Init(const Port_ConfigType* ConfigPtr);


#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
