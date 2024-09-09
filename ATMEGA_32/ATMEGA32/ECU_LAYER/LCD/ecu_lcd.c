/*
 * ecu_lcd.c
 *
 * Created: 8/31/2024 4:00:23 AM
 *  Author: Mohamed Tarek
 */ 
#include "ecu_lcd.h"


static Std_ReturnType enable_signal_8bits(const lcd_8bits_t *lcd);
static Std_ReturnType enable_signal_4bits(const lcd_4bits_t *lcd);
static Std_ReturnType lcd_8bits_set_cursor(const lcd_8bits_t *lcd,uint8 Rows,uint8 coloumns);
static Std_ReturnType lcd_4bits_set_cursor(const lcd_4bits_t *lcd,uint8 Rows,uint8 coloumns);

static Std_ReturnType send_4bits(const lcd_4bits_t *lcd,uint8 data);

Std_ReturnType lcd_8bit_initialize(const lcd_8bits_t *lcd){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_pin_initialize(&(lcd->rs));
		ret = gpio_pin_initialize(&(lcd->enable));
		for(counter = 0;counter < 8;counter++){
			ret = gpio_pin_initialize(&(lcd->data_pins[counter]));
		}
		_delay_ms(20);
		lcd_8bit_send_command(lcd,LCD_8BIT_2_LINES);
		_delay_ms(5);
		lcd_8bit_send_command(lcd,LCD_8BIT_2_LINES);
		_delay_us(150);
		lcd_8bit_send_command(lcd,LCD_8BIT_2_LINES);
		lcd_8bit_send_command(lcd,CLEAR_LCD);
		lcd_8bit_send_command(lcd,RETURN_HOME);
		lcd_8bit_send_command(lcd,LCD_INCREAMENT_SHIFT_OFF);
		lcd_8bit_send_command(lcd,LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF);
		lcd_8bit_send_command(lcd,LCD_8BIT_2_LINES);
	}
	return ret;
}
Std_ReturnType lcd_8bit_send_command(const lcd_8bits_t *lcd,uint8 command){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->rs),GPIO_LOW);
		for(counter = 0;counter < 8;counter++){
			ret = gpio_pin_write_logic(&(lcd->data_pins[counter]),(command >> counter) & (uint8)0x01);
		}
		
		enable_signal_8bits(lcd);
	}
	return ret;
}
Std_ReturnType lcd_8bit_send_char(const lcd_8bits_t *lcd,uint8 _char){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->rs),GPIO_HIGH);
		for(counter = 0;counter < 8;counter++){
			ret = gpio_pin_write_logic(&(lcd->data_pins[counter]),(_char >> counter) & (uint8)0x01);
		}
		
		enable_signal_8bits(lcd);
	}
	return ret;
}
Std_ReturnType lcd_8bit_send_char_pos(const lcd_8bits_t *lcd,uint8 Row,uint8 coloumns,uint8 _char){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		lcd_8bits_set_cursor(lcd,Row,coloumns);
		lcd_8bit_send_char(lcd,_char);
	}
	return ret;
}
Std_ReturnType lcd_8bit_send_string(const lcd_8bits_t *lcd,uint8 *str){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		while(*str){
			ret = lcd_8bit_send_char(&(lcd->data_pins[counter]),*str++);
		}
		
	}
	return ret;
}
Std_ReturnType lcd_8bit_send_string_pos(const lcd_8bits_t *lcd,uint8 Row,uint8 coloumns,uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		
		ret = lcd_8bits_set_cursor(lcd,Row,coloumns);
		ret = lcd_8bit_send_string(lcd,str);
		
	}
	return ret;
}
Std_ReturnType lcd_8bit_custom_character(const lcd_8bits_t *lcd,uint8 Row,uint8 coloumns,uint8 chr[],uint8 mempos){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		
		ret = lcd_8bit_send_command(lcd,(_LCD_CGRAM_START + (mempos*8)));
		for(counter = 0;counter <= 7;counter++){
			ret = lcd_8bit_send_char(lcd,chr[counter]);
		}
		ret = lcd_8bit_send_char_pos(lcd,Row,coloumns,mempos);
		
	}
	return ret;
}


Std_ReturnType lcd_4bit_initialize(const lcd_4bits_t *lcd){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_pin_initialize(&(lcd->rs));
		ret = gpio_pin_initialize(&(lcd->enable));
		
			ret = gpio_pin_initialize(&(lcd->data_pins[0]));
			ret = gpio_pin_initialize(&(lcd->data_pins[1]));
			ret = gpio_pin_initialize(&(lcd->data_pins[2]));
			ret = gpio_pin_initialize(&(lcd->data_pins[3]));
		
		_delay_ms(20);
		lcd_4bit_send_command(lcd,LCD_8BIT_2_LINES);
		_delay_ms(5);
		lcd_4bit_send_command(lcd,LCD_8BIT_2_LINES);
		_delay_us(150);
		lcd_4bit_send_command(lcd,LCD_8BIT_2_LINES);
		lcd_4bit_send_command(lcd,CLEAR_LCD);
		lcd_4bit_send_command(lcd,RETURN_HOME);
		lcd_4bit_send_command(lcd,LCD_INCREAMENT_SHIFT_OFF);
		lcd_4bit_send_command(lcd,LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF);
		lcd_4bit_send_command(lcd,LCD_4BIT_2_LINES);
		lcd_4bit_send_command(lcd,0x80);
	}
	return ret;
}
Std_ReturnType lcd_4bit_send_command(const lcd_4bits_t *lcd,uint8 command){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->rs),GPIO_LOW);
		send_4bits(lcd,(command >> 4));
		enable_signal_4bits(lcd);
		send_4bits(lcd,command);
		enable_signal_4bits(lcd);
	}
	return ret;
}
Std_ReturnType lcd_4bit_send_char(const lcd_4bits_t *lcd,uint8 _char){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->rs),GPIO_HIGH);
		send_4bits(lcd,_char >> 4);
		enable_signal_4bits(lcd);
		send_4bits(lcd,_char);
		enable_signal_4bits(lcd);
	}
	return ret;
}
Std_ReturnType lcd_4bit_send_char_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 _char){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		ret = lcd_4bits_set_cursor(lcd,Row,coloumn);
		
		ret = lcd_4bit_send_char(lcd,_char);
	}
	return ret;
}
Std_ReturnType lcd_4bit_send_string(const lcd_4bits_t *lcd,uint8 *str){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		while(*str){
			ret = lcd_4bit_send_char(lcd,*str++);
		}
		
	}
	return ret;
}
Std_ReturnType lcd_4bit_send_string_pos(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumn,uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		ret = lcd_4bits_set_cursor(lcd,Row,coloumn);
		ret = lcd_4bit_send_string(lcd,str);
	}
	return ret;
}
Std_ReturnType lcd_4bit_custom_character(const lcd_4bits_t *lcd,uint8 Row,uint8 coloumns,uint8 chr[],uint8 mempos){
	Std_ReturnType ret = E_OK;
	uint8 counter = 0;
	if(NULL == lcd){
		ret = E_NOT_OK;
	}
	else{
		
		ret = lcd_4bit_send_command(lcd,(_LCD_CGRAM_START + (mempos*8)));
		for(counter = 0;counter <= 7;counter++){
			ret = lcd_4bit_send_char(lcd,chr[counter]);
		}
		ret = lcd_4bit_send_char_pos(lcd,Row,coloumns,mempos);
		
	}
	return ret;
}



Std_ReturnType convert_uint8_to_string(uint8 value,const uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == str){
		ret = E_NOT_OK;
	}
	else{
		memset((char *)str, '\0', 4);
		sprintf((uint8 *)str, "%u", (uint8)value);
	}
	return ret;
}
Std_ReturnType convert_uint16_to_string(uint16 value,uint8 *str){
	Std_ReturnType ret = E_OK;
	
	memset(str, '\0',6);
	sprintf(str, "%i", value);

	return ret;
}
Std_ReturnType convert_uint32_to_string(uint32 value,uint8 *str){
	
	Std_ReturnType ret = E_OK;
	memset(str,'\0',11);
	sprintf(str, "%i", value);

	return ret;
}
static Std_ReturnType gpio_pin_enable_8bit(const lcd_8bits_t *lcd){
	Std_ReturnType ret = E_OK;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->enable),GPIO_HIGH);
		_delay_us(5);
		gpio_pin_write_logic(&(lcd->enable),GPIO_LOW);
	}
	return ret;
}

static Std_ReturnType enable_signal_8bits(const lcd_8bits_t *lcd){
	Std_ReturnType ret = E_OK;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->enable),GPIO_HIGH);
		_delay_us(5);
		gpio_pin_write_logic(&(lcd->enable),GPIO_LOW);
	}
	return ret;
}


static Std_ReturnType enable_signal_4bits(const lcd_4bits_t *lcd){
	Std_ReturnType ret = E_OK;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->enable),GPIO_HIGH);
		_delay_us(5);
		gpio_pin_write_logic(&(lcd->enable),GPIO_LOW);
	}
	return ret;
}


static Std_ReturnType send_4bits(const lcd_4bits_t *lcd,uint8 data){
	Std_ReturnType ret = E_OK;
	if(lcd == NULL){
		ret = E_NOT_OK;
	}
	else{
		gpio_pin_write_logic(&(lcd->data_pins[0]),(data & 0x01));
		gpio_pin_write_logic(&(lcd->data_pins[1]),((data >> 1) & 0x01));
		gpio_pin_write_logic(&(lcd->data_pins[2]),((data >> 2) & 0x01));
		gpio_pin_write_logic(&(lcd->data_pins[3]),((data >> 3) & 0x01));
	}
	return ret;
}

static Std_ReturnType lcd_8bits_set_cursor(const lcd_8bits_t *lcd,uint8 Rows,uint8 coloumns){
	Std_ReturnType ret = E_OK;
	coloumns--;
	
	switch(Rows){
		case ROW1 : lcd_8bit_send_command(lcd,(0x80 + coloumns)); break;
		case ROW2 : lcd_8bit_send_command(lcd,(0xc0 + coloumns)); break;
		case ROW3 : lcd_8bit_send_command(lcd,(0x94 + coloumns)); break;
		case ROW4 : lcd_8bit_send_command(lcd,(0xd4 + coloumns)); break;
		default:
		break;
		
	}
	return ret;
}
static Std_ReturnType lcd_4bits_set_cursor(const lcd_4bits_t *lcd,uint8 Rows,uint8 coloumns){
	Std_ReturnType ret = E_OK;
	coloumns--;
	
	switch(Rows){
		case ROW1 : lcd_4bit_send_command(lcd,(0x80 + coloumns)); break;
		case ROW2 : lcd_4bit_send_command(lcd,(0xc0 + coloumns)); break;
		case ROW3 : lcd_4bit_send_command(lcd,(0x94 + coloumns)); break;
		case ROW4 : lcd_4bit_send_command(lcd,(0xd4 + coloumns)); break;
		default:
		break;
		
	}
	return ret;
	
}