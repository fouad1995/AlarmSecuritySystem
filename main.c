#include "Systic.h"


/*To restrict access of this structure to this file and SYSTICK_HANDLER */
/*No other file can access this Time Structure*/
static struct Time{

	uint8_t seconds;
	uint8_t minitues;
	uint16_t Hours;
}Clock={0,0,0};


int main()
{
	SYSCTL->RCGCGPIO |= 0x20; //enable portf 
	GPIOF->DIR |= 0x02;
	GPIOF->DEN |= 0x02;
	GPIOF->AFSEL &=~ 0x02;
	Systick_Init(16000000);
	
	while(1)
	{
	
		//GPIOF->DATA |= 0x02;
	
	
	}
	
	return 0;
}



void SysTick_Handler()
{

	GPIOF->DATA ^= 0x02;
	if(Clock.seconds == 59){
		Clock.seconds=0;
		Clock.minitues++;
	}
	if(Clock.minitues == 59){
		Clock.seconds=0;
		Clock.Hours++;
	}
	if(Clock.Hours == 12){
		Clock.seconds=0;
		Clock.minitues=0;
		Clock.Hours=1;
	}
	Clock.seconds ++;
	
}



