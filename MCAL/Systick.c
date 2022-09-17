/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick.c
 *       Module:  Systick
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - Systick Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Systick.h"


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : None                    
* Parameters (out): None                                                      
* Return value    : None 
* Description  		: Systick Timer Enable Function
*******************************************************************************/

void Systick_Enable(void){
	
	
	SYSTICK_CURRENT_REG = 0;              
    
  SYSTICK_CTRL_REG   |= 0x07;

}
/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : milliSeconds                    
* Parameters (out): None                                                      
* Return value    : None 
* Description  		: Systick Reload Function
*******************************************************************************/


void Systick_Reload(uint32 time){
	
	SYSTICK_RELOAD_REG  = (16000*time)-1;
	
	
}
/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : None                    
* Parameters (out): None                                                      
* Return value    : None 
* Description  		: Systick Timer Disable Function
*******************************************************************************/


void Systick_Disable(void){
	
	SYSTICK_CURRENT_REG = 0;              
    
  SYSTICK_CTRL_REG = 0;
	
	SYSTICK_RELOAD_REG  = 0;
}



/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
