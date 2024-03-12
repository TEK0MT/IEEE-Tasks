#include <stdint.h>
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO.h"
#include "lcd.h"

void clock_init()
{
	//Enable port A clock
	RCC_GPIOA_CLK_EN();
	//Enable port B clock
	RCC_GPIOB_CLK_EN();
}
void wait_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}//hint time :100 == 1 sec

int main(void)
{
	clock_init();
	lcd_init();
	while(1)
	{
		// implementation
		lcd_set_position(0,4);
        lcd_send_string("IEEE #1");
        wait_ms(200);
        lcd_clear();
		lcd_set_position(0,1);
		lcd_send_string("Mohamed Tarek");
		lcd_set_position(0,0);
		wait_ms(200);
        lcd_clear();
		lcd_send_string("Volunteer n IEEE");
        wait_ms(200);
        lcd_clear();
        lcd_set_position(0,1);
		lcd_send_string("Embedded Sys");
        wait_ms(200);
        lcd_clear();
	}

}
