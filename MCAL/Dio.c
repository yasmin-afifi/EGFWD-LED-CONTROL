/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.c
 *       Module:  Dio
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - Dio Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Dio.h"


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Reentrant                                             
* Parameters (in) : ChannelId                     
* Parameters (out): None                                                      
* Return value    : Dio_LevelType 
* Description  		:  DIO read Port API Function 
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	
	volatile uint32 * Port_Ptr = 0x00000000;
	Dio_LevelType output = STD_LOW;
	uint8 Port = ChannelId / 8;
	uint8 Pin = ChannelId % 8;
	
	switch(Port){
		case PORTA: Port_Ptr = &GPIO_PORTA_DATA_REG;
		case PORTB: Port_Ptr = &GPIO_PORTB_DATA_REG;
		case PORTC: Port_Ptr = &GPIO_PORTC_DATA_REG;
		case PORTD: Port_Ptr = &GPIO_PORTD_DATA_REG;
		case PORTE: Port_Ptr = &GPIO_PORTE_DATA_REG;
		case PORTF: Port_Ptr = &GPIO_PORTF_DATA_REG;
			
	}
	
	if(BIT_IS_SET(*Port_Ptr,Pin)){
		
		output = STD_HIGH;
	}
	else
	{
		output = STD_LOW;
	}
	
	return output;
	
	
}


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Reentrant                                             
* Parameters (in) : ChannelId , Level                     
* Parameters (out): None                                                      
* Return value    : None 
* Description			:  DIO write Port API Function 
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level){
	
	volatile uint32 * Port_Ptr = 0x00000000;
	
	uint8 Port = ChannelId / 8;
	uint8 Pin = ChannelId % 8;
	
	switch(Port){
		case PORTA: Port_Ptr = &GPIO_PORTA_DATA_REG;
		case PORTB: Port_Ptr = &GPIO_PORTB_DATA_REG;
		case PORTC: Port_Ptr = &GPIO_PORTC_DATA_REG;
		case PORTD: Port_Ptr = &GPIO_PORTD_DATA_REG;
		case PORTE: Port_Ptr = &GPIO_PORTE_DATA_REG;
		case PORTF: Port_Ptr = &GPIO_PORTF_DATA_REG;
		
	}
	
	if(Level == STD_LOW){
		
		CLEAR_BIT(*Port_Ptr,Pin);
		
	}
	else{
		
		SET_BIT(*Port_Ptr,Pin);
	}
	
	
	
}


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Reentrant                                             
* Parameters (in) : PortId                     
* Parameters (out): None                                                      
* Return value    : Dio_PortLevelType 
* Description			:  DIO read Channel API Function  
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	
	
	Dio_PortLevelType output = 0;
	
	switch(PortId){
		case PORTA: output = GPIO_PORTA_DATA_REG;
		case PORTB: output = GPIO_PORTB_DATA_REG;
		case PORTC: output = GPIO_PORTC_DATA_REG;
		case PORTD: output = GPIO_PORTD_DATA_REG;
		case PORTE: output = GPIO_PORTE_DATA_REG;
		case PORTF: output = GPIO_PORTF_DATA_REG;
		
	}
	
	return output;
	
	
	
}

/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Reentrant                                             
* Parameters (in) : PortId , Level                    
* Parameters (out): None                                                      
* Return value    : None  
* Description			:  DIO write Channel API Function 
*******************************************************************************/

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level){
	
	
	switch(PortId){
		case PORTA: GPIO_PORTA_DATA_REG = Level;
		case PORTB: GPIO_PORTB_DATA_REG = Level;
		case PORTC: GPIO_PORTC_DATA_REG = Level;
		case PORTD: GPIO_PORTD_DATA_REG = Level;
		case PORTE: GPIO_PORTE_DATA_REG = Level;
		case PORTF: GPIO_PORTF_DATA_REG = Level;
		
	} 
	
}

/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Reentrant                                             
* Parameters (in) : ChannelId                     
* Parameters (out): None                                                      
* Return value    : Dio_LevelType  
* Description			:  Dio Flip Channel API Function                                           
*******************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
	
	volatile uint32 * Port_Ptr = 0x00000000;
	Dio_LevelType output = STD_LOW;
	uint8 Port = ChannelId / 8;
	uint8 Pin = ChannelId % 8;
	
	switch(Port){
		case PORTA: Port_Ptr = &GPIO_PORTA_DATA_REG;
		case PORTB: Port_Ptr = &GPIO_PORTB_DATA_REG;
		case PORTC: Port_Ptr = &GPIO_PORTC_DATA_REG;
		case PORTD: Port_Ptr = &GPIO_PORTD_DATA_REG;
		case PORTE: Port_Ptr = &GPIO_PORTE_DATA_REG;
		case PORTF: Port_Ptr = &GPIO_PORTF_DATA_REG;
		
	}
	
	if(BIT_IS_SET(*Port_Ptr,Pin)){
		
		CLEAR_BIT(*Port_Ptr,Pin);
		output = STD_LOW;
	}
	else
	{
		SET_BIT(*Port_Ptr,Pin);
		output = STD_HIGH;
	}
	
	return output;
	
	
}


/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
