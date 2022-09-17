/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.c
 *       Module:  Port
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - Port Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Port.h"


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : ConfigPtr                     
* Parameters (out): None                                                      
* Return value    : None 
* Description  		:  Port Initialization Function
*******************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr){
	
	volatile uint32 * Port_Ptr = 0x00000000;
	
	int i;
	for(i=0; i < NO_OF_CHANNLES; i++){
		
		uint8 Port = ConfigPtr ->Pins[i].port_num;
		Port_PinType Pin = ConfigPtr ->Pins[i].pin_num;
		Port_PinDirectionType Direction = ConfigPtr ->Pins[i].direction;
		Port_PinModeType Mode = ConfigPtr ->Pins[i].Mode;
		Port_PinInternalAttachType res = ConfigPtr ->Pins[i].resistor;
		uint8 Value = ConfigPtr ->Pins[i].initial_value; 
	
		switch(Port ){
			case PORTA_PORT: Port_Ptr = &GPIO_PORTA_DATA_REG;
			case PORTB_PORT: Port_Ptr = &GPIO_PORTB_DATA_REG;
			case PORTC_PORT: Port_Ptr = &GPIO_PORTC_DATA_REG;
			case PORTD_PORT: Port_Ptr = &GPIO_PORTD_DATA_REG;
			case PORTE_PORT: Port_Ptr = &GPIO_PORTE_DATA_REG;
			case PORTF_PORT: Port_Ptr = &GPIO_PORTF_DATA_REG;
			
		}
		
		SYSCTL_REGCGC2_REG |= (1<<(ConfigPtr->Pins[i].port_num));
		volatile unsigned long delay = 0;
		delay = SYSCTL_REGCGC2_REG;
		
		if( ((Port == PORTF_PORT) && (Pin == PIN0)) || ((Port == PORTD_PORT) && (Pin == PIN7)) ){
			
			if(Port == PORTF_PORT){
				
				GPIO_PORTF_LOCK_REG  = UNLOCK_GPIOCR;
				GPIO_PORTF_CR_REG    |= (1<<0);
				
			}
			else if(Port == PORTD_PORT){
				
				GPIO_PORTD_LOCK_REG  = UNLOCK_GPIOCR;
				GPIO_PORTD_CR_REG    |= (1<<7);
				
			}
				
			
		}
		
		else if( (Port == PORTC_PORT) && (Pin >= PIN3))
		{
			continue;
		}
		
		if(Direction == PORT_PIN_IN){
			
			switch(Port){
				
				case PORTA_PORT: {
					
					CLEAR_BIT(GPIO_PORTA_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTA_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTA_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTA_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTA_PUR_REG, Pin);
						
					}
					
				}
				case PORTB_PORT: {
					
					CLEAR_BIT(GPIO_PORTB_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTB_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTB_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTB_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTB_PUR_REG, Pin);
						
					}
					
				}
				case PORTC_PORT: {
					
					CLEAR_BIT(GPIO_PORTC_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTC_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTC_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTC_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTC_PUR_REG, Pin);
						
					}
					
				}
				case PORTD_PORT: {
					
					CLEAR_BIT(GPIO_PORTD_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTD_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTD_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTD_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTD_PUR_REG, Pin);
						
					}
					
				}
				case PORTE_PORT: {
					
					CLEAR_BIT(GPIO_PORTE_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTE_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTE_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTE_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTE_PUR_REG, Pin);
						
					}
					
				}
				case PORTF_PORT: {
					
					CLEAR_BIT(GPIO_PORTF_DIR_REG,Pin);
					
					if(res == PULL_DOWN){
						
						SET_BIT(GPIO_PORTF_PDR_REG, Pin);
						
					}
					else if(res == PULL_UP){
						
						SET_BIT(GPIO_PORTF_PUR_REG, Pin);
						
					}
					else{
						
						CLEAR_BIT(GPIO_PORTF_PDR_REG, Pin);
						CLEAR_BIT(GPIO_PORTF_PUR_REG, Pin);
						
					}
					
				}
				
				
			}
			
		}
		
		else if(Direction == PORT_PIN_OUT){
			
			switch(Port){
				
				case PORTA_PORT: {
					
					SET_BIT(GPIO_PORTA_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTA_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTA_DATA_REG, Pin);
						
					}
					
					
				}
				
				case PORTB_PORT: {
					
					SET_BIT(GPIO_PORTB_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTB_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTB_DATA_REG, Pin);
						
					}
					
					
				}
				
				case PORTC_PORT: {
					
					SET_BIT(GPIO_PORTC_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTC_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTC_DATA_REG, Pin);
						
					}
					
					
				}
				
				case PORTD_PORT: {
					
					SET_BIT(GPIO_PORTD_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTD_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTD_DATA_REG, Pin);
						
					}
					
					
				}
				
				case PORTE_PORT: {
					
					SET_BIT(GPIO_PORTE_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTE_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTE_DATA_REG, Pin);
						
					}
					
					
				}
				
				case PORTF_PORT: {
					
					SET_BIT(GPIO_PORTF_DIR_REG,Pin);
					
					if(Value == STD_HIGH){
						
						SET_BIT(GPIO_PORTF_DATA_REG, Pin);
						
					}
					else {
						
						CLEAR_BIT(GPIO_PORTF_DATA_REG, Pin);
						
					}
					
					
				}
				
				
			}
		
		}
		
		if(Mode == DIO){

			
			switch(Port){
				
				case PORTA_PORT:{
					
					CLEAR_BIT(GPIO_PORTA_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTA_AFSEL_REG, Pin);
					GPIO_PORTA_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTA_DEN_REG, Pin);
			
				}
				
				case PORTB_PORT:{
					
					CLEAR_BIT(GPIO_PORTB_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTB_AFSEL_REG, Pin);
					GPIO_PORTB_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTB_DEN_REG, Pin);
			
				}
				
				case PORTC_PORT:{
					
					CLEAR_BIT(GPIO_PORTC_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTC_AFSEL_REG, Pin);
					GPIO_PORTC_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTC_DEN_REG, Pin);
			
				}
				
				case PORTD_PORT:{
					
					CLEAR_BIT(GPIO_PORTD_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTD_AFSEL_REG, Pin);
					GPIO_PORTD_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTD_DEN_REG, Pin);
			
				}
				
				case PORTE_PORT:{
					
					CLEAR_BIT(GPIO_PORTE_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTE_AFSEL_REG, Pin);
					GPIO_PORTE_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTE_DEN_REG, Pin);
			
				}
				
				case PORTF_PORT:{
					
					CLEAR_BIT(GPIO_PORTF_AMSEL_REG, Pin);
					CLEAR_BIT(GPIO_PORTF_AFSEL_REG, Pin);
					GPIO_PORTF_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTF_DEN_REG, Pin);
			
				}
				
				
			}
		}
		
		else if(Mode == ADC){
			
			switch(Port){
				
				case PORTA_PORT:{
					
					CLEAR_BIT(GPIO_PORTA_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTA_AFSEL_REG, Pin);
					GPIO_PORTA_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTA_AMSEL_REG, Pin);
			
				}
				
				case PORTB_PORT:{
					
					CLEAR_BIT(GPIO_PORTB_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTB_AFSEL_REG, Pin);
					GPIO_PORTB_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTB_AMSEL_REG, Pin);
			
				}
				
				case PORTC_PORT:{
					
					CLEAR_BIT(GPIO_PORTC_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTC_AFSEL_REG, Pin);
					GPIO_PORTC_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTC_AMSEL_REG, Pin);
			
				}
				
				case PORTD_PORT:{
					
					CLEAR_BIT(GPIO_PORTD_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTD_AFSEL_REG, Pin);
					GPIO_PORTD_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTD_AMSEL_REG, Pin);
			
				}
				
				case PORTE_PORT:{
					
					CLEAR_BIT(GPIO_PORTE_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTE_AFSEL_REG, Pin);
					GPIO_PORTE_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTE_AMSEL_REG, Pin);
			
				}
				
				case PORTF_PORT:{
					
					CLEAR_BIT(GPIO_PORTF_DEN_REG, Pin);
					CLEAR_BIT(GPIO_PORTF_AFSEL_REG, Pin);
					GPIO_PORTF_PCTL_REG &= ~(0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTF_AMSEL_REG, Pin);
			
				}
				
				
			}
			
		}
		
		else{
			
			switch(Port){
				
				case PORTA_PORT:{
					
					CLEAR_BIT(GPIO_PORTA_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTA_AFSEL_REG, Pin);
					GPIO_PORTA_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTA_DEN_REG, Pin);
			
				}
				
				case PORTB_PORT:{
					
					CLEAR_BIT(GPIO_PORTB_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTB_AFSEL_REG, Pin);
					GPIO_PORTB_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTB_DEN_REG, Pin);
			
				}
				
				case PORTC_PORT:{
					
					CLEAR_BIT(GPIO_PORTC_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTC_AFSEL_REG, Pin);
					GPIO_PORTC_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTC_DEN_REG, Pin);
			
				}
				
				case PORTD_PORT:{
					
					CLEAR_BIT(GPIO_PORTD_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTD_AFSEL_REG, Pin);
					GPIO_PORTD_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTD_DEN_REG, Pin);
			
				}
				
				case PORTE_PORT:{
					
					CLEAR_BIT(GPIO_PORTE_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTE_AFSEL_REG, Pin);
					GPIO_PORTE_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTE_DEN_REG, Pin);
			
				}
				
				case PORTF_PORT:{
					
					CLEAR_BIT(GPIO_PORTF_AMSEL_REG, Pin);
					SET_BIT(GPIO_PORTF_AFSEL_REG, Pin);
					GPIO_PORTF_PCTL_REG |= (0x0000000F << (Pin * 4));
					SET_BIT(GPIO_PORTF_DEN_REG, Pin);
			
				}
				
				
			}
			
		}
		

		
	}
	
	
	
}



/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
