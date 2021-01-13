#include "stm32f4xx.h"
void configureLED(void);
void msDelay(uint32_t msTime);
int main(void)
{
	//Configure LED
	configureLED();
	//Define Delay function
	msDelay(1000);
	while(1)
	{
		if(GPIOA->IDR&1)
		{
			GPIOD->ODR ^= (0x1UL<<10);
			while(GPIOA->IDR&1);
		}
	}
}
void configureLED(void)
{
	RCC->AHB1ENR |=(0x9UL<<0);
	GPIOD->MODER &= ~(0x3UL<<10*2); //making PD10 as output
	GPIOD->MODER |= (0x1UL<<10*2);
	//GPIOA->PUPDR &= ~(0x3UL<<0); 
	//GPIOA->PUPDR |= (0x1UL<<0);
	GPIOA->MODER &= ~(0xFFUL<<0); //making PA0 as input
	GPIOA->MODER |= (0x00UL<<0);
	GPIOA->PUPDR &= ~(0x3UL<<0); 
	GPIOA->PUPDR |= (0x00UL<<0);
}
void msDelay(uint32_t msTime)
{
	/* For loop takes 4 clock cycles to get executed. Clock frequency of stm32f407 by default is 16MHz
	So, 16MHz/4=4MHz. If we want 1000ms delay, 4MHz/1000=4000, so we have to multiply by 4000 to get a delay of 1s
	*/
	for(uint32_t i=0;i<msTime*4000;i++)
	{
		__NOP();
	}
	
}
