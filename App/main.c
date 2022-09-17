#include "Port.h"
#include "Systick.h"
#include "Dio.h"
#include "IntCtrl.h"

static volatile uint32 tick;

void SysTick_Handler(void)
{
    tick++;
}



int main()
{
	uint32 OnDuration  =3000;
	uint32 OffDuration =1000;
	uint8 Flag = 1;
	
	Port_Init(&Port_Configuration);
	
	IntCtrl_init();
	
	Systick_Disable();
	
	Systick_Reload(1000);
	
	Dio_WriteChannel(PF1,STD_HIGH);
	
	Systick_Enable();
	
	while(1){
		
		if(tick ==(OnDuration/1000) && Flag ==1){
			Dio_FlipChannel(PF1);
			
			tick = 0;
			
			Flag = 0;
		}
		
		else if(tick == (OffDuration/1000) && Flag==0){
			Dio_FlipChannel(PF1);
			
			tick = 0;
			
			Flag = 1;
			
		}
		
		
		
		
		
		
	}
	
	
	
	
  return 0;
}
