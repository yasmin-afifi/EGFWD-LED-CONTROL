/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Lcfg.c
 *       Module:  Port
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - Port Driver Config    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Port.h"


const Port_ConfigType Port_Configuration = {
	
	PortConf_PORTF_PORT_NUM, PortConf_PF0, PORT_PIN_OUT, DIO, PULL_DOWN, STD_HIGH,
	PortConf_PORTF_PORT_NUM, PortConf_PF1, PORT_PIN_OUT, DIO, PULL_DOWN, STD_HIGH,
	
	
	
};






/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
