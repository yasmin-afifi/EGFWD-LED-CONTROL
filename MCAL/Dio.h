/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  Header file for TM4C123GH6PM Microcontroller - Dio Driver    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "common_macros.h"
#include "std_types.h"




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Dio_LevelType;


typedef uint8 Dio_PortLevelType;

typedef enum
{
    PORTA = 0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}Dio_PortType;

typedef enum
{
    PA0 = 0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
    PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
    PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
    PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
    PE0, PE1, PE2, PE3, PE4, PE5,
    PF0 = 40, PF1, PF2, PF3, PF4
}Dio_ChannelType;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* DIO read Port API Function*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* DIO write Port API Function*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* DIO read Channel API Function*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* DIO write Channel API Function*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Dio Flip Channel API Function */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
