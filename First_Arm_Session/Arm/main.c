#include "stm32f10x.h"
void delay_ms(int n);
int main(){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//00010
	GPIOA->CRL = 0x33333333;
	GPIOA->CRH = 0x33333333;
	while(1){
		GPIOA->ODR = 0x01;
	delay_ms(1000);
				GPIOA->ODR = 0x00;
delay_ms(1000);
	}
}

void delay_ms(int n){
	int i = 0 , j = 0;
	for(j = 0;j < n ;j++){
		for(i = 0;i < 681;i++);
		}
	}

	
	