#include "Systic.h"


/*Need to set the value for systick to interrupt every 1 second assuming that system frequency is 16Mhz*/
/* 16Mhz :  16M Clock -> 1 sec => Each clock Takes 1/16M = 62.5 ns */
/*So we need to put 15999999 in load Registe */
/*Maximum value for load registe is ((2^24) -1) which can hold the value*/
void Systick_Init(uint32_t value)
{
	SysTick->CTRL = 0;  //Disable Systick during setup
	SysTick->LOAD = value-1;  //load the needed value
	SysTick->VAL = 0; //write to the current register to clear the counter
										
	NVIC_SetPriority(SysTick_IRQn,1); //set priority of the Systick timer to 1

	SysTick->CTRL |=7;    //enable systick , enable interrupt when counter reach 0 and use system clock
	
	__enable_irq();  //enable interrupt globally
	
}




