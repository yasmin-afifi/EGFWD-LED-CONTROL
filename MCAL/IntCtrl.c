/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.c
 *       Module:  IntCtrl
 *
 *  Description:  Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"


/******************************************************************************
*                                                                                                                
* Sync\Async      : Synchronous                                               
* Reentrancy      : Non Reentrant                                             
* Parameters (in) : None                     
* Parameters (out): None                                                      
* Return value    : None 
* Description  		:  Interrupt Initialization Function 
*******************************************************************************/
void IntCtrl_init(void){
	
	uint8 Priority;
	
	volatile uint32 * Ptr = 0x00000000;
	
	
	APINT = (VECTKEY << 16) | ( IntCtrl_Gr_SubGr_cfg << 8);

  int i;
	for(i = 0; i < NO_OF_INT; i++){
		
		IntCtrl_IntGroup Gr_Pri_Value = IntCtrl_Configuration[i].intGroup;
		
		IntCtrl_IntSubGroup SubGr_Pri_Value = IntCtrl_Configuration[i].intSubGroup;
		
		switch(IntCtrl_Gr_SubGr_cfg){
			
			case NVIC_PRI_GR8_SUBGR1:  Priority = Gr_Pri_Value;
			
			case NVIC_PRI_GR1_SUBGR8:  Priority = SubGr_Pri_Value;
			
			case NVIC_PRI_GR4_SUBGR2:  Priority = ((Gr_Pri_Value << 1) & 0x06) | (SubGr_Pri_Value & 0x01);
			
			case NVIC_PRI_GR2_SUBGR4:  Priority = ((Gr_Pri_Value << 2) & 0x04) | (SubGr_Pri_Value & 0x03);
			
			
		}
		
		if(IntCtrl_Configuration[i].intType <0){
        // adjust priority of system exception only and go to next iteration
            switch ((uint32)IntCtrl_Configuration[i].intType)
            {
            case MEM_MANAG_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (Priority << 5);
                break;
            case BUS_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (Priority << 13);
                break;
            case USAGE_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (Priority << 21);
                break;
            case SVC:
                NVIC_SYSTEM_PRI2_REG |= (Priority << 29);
                break;
            case DEBUG:
                NVIC_SYSTEM_PRI3_REG |= (Priority << 5);
                break;
            case PENDSV:
                NVIC_SYSTEM_PRI3_REG |= (Priority << 21);
                break;
            case SYSTICK:
                NVIC_SYSTEM_PRI3_REG |= (Priority << 29);
                break;
            }
            continue;
        }
		
		if(IntCtrl_Configuration[i].ED == ENA){
					
			Ptr = &NVIC_EN0_REG;
    }
    else{
      
			Ptr = &NVIC_DIS0_REG;
    }
       
		Ptr += ((uint32)(IntCtrl_Configuration[i].intType / 32)); 
	 
		(*Ptr)|= (1<<(IntCtrl_Configuration[i].intType % 32));
   
       
		if(IntCtrl_Configuration[i].ED == ENA){
        
			Ptr = &NVIC_PRI0_REG;
       
		}
        
		else{
            
			continue;
        
		}

        
		Ptr += ((uint32)(IntCtrl_Configuration[i].intType / 4));
        
		(*Ptr)|=(Priority << (((IntCtrl_Configuration[i].intType % 4)*8)+5));		
				
		
	}
	

	
}



/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
