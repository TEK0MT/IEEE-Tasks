/*
 * CLCD.c
 *
 * Created: 8/31/2024 3:50:35 AM
 * Author : Mohamed Tarek
 */ 

#include <avr/io.h>
#include "ECU_LAYER\Seven_Segment\ecu_seven_segment.h"
#include "ECU_LAYER\BUTTON\ecu_button.h"
#include "ECU_LAYER/LCD/ecu_lcd.h"
lcd_4bits_t lcd ={.rs.port = PORTD_INDEX,.rs.pin=Pin0,.rs.direction=GPIO_DIRECTION_OUTPUT,.rs.logic=GPIO_LOW,
					.enable.port=PORTD_INDEX,.enable.pin=Pin1,.enable.direction=GPIO_DIRECTION_OUTPUT,.enable.logic=GPIO_LOW,
					.data_pins[0].port=PORTD_INDEX,.data_pins[0].pin=Pin2,.data_pins[0].direction=GPIO_DIRECTION_OUTPUT,.data_pins[0].logic=GPIO_LOW,
					.data_pins[1].port=PORTD_INDEX,.data_pins[1].pin=Pin3,.data_pins[1].direction=GPIO_DIRECTION_OUTPUT,.data_pins[1].logic=GPIO_LOW,
					.data_pins[2].port=PORTD_INDEX,.data_pins[2].pin=Pin4,.data_pins[2].direction=GPIO_DIRECTION_OUTPUT,.data_pins[2].logic=GPIO_LOW,
					.data_pins[3].port=PORTD_INDEX,.data_pins[3].pin=Pin5,.data_pins[3].direction=GPIO_DIRECTION_OUTPUT,.data_pins[3].logic=GPIO_LOW};
button_t btn_right = {.pin.pin=Pin6,.pin.port=PORTD_INDEX,.pin.direction=GPIO_DIRECTION_INPUT,.pin.logic=GPIO_LOW,.type=ACTIVE_HIGH};
button_t btn_left = {.pin.pin=Pin7,.pin.port=PORTD_INDEX,.pin.direction=GPIO_DIRECTION_INPUT,.pin.logic=GPIO_LOW,.type=ACTIVE_HIGH};
	
uint8 questions = 0;
uint8 right_val = 0;
uint8 left_val = 0;
int main(void)
{
	lcd_4bit_initialize(&lcd);
	Button_Init(&btn_right);
	Button_Init(&btn_left);
    /* Replace with your application code */
    while (1) 
    {
		if(questions == 0){
			lcd_4bit_send_string_pos(&lcd,1,5,"The Forest");
			lcd_4bit_send_string_pos(&lcd,2,1,"Welcome toThe Forest");
			questions++;
			_delay_ms(4000);
    }
	else if(questions == 1){
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"Imagine you're in a ");
		lcd_4bit_send_string_pos(&lcd,2,1,"mysterious, magical");
		lcd_4bit_send_string_pos(&lcd,3,1,"land....");
		_delay_ms(4000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"option 1 is left btn");
		lcd_4bit_send_string_pos(&lcd,2,1,"option 2is right btn");
		_delay_ms(2000);
		questions++;
	}
	else if(questions == 2){
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"As u enter the land,");
		lcd_4bit_send_string_pos(&lcd,2,1,"u see a forest ahead");
		_delay_ms(4000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		questions++;
		
	}
	else if(questions == 3){
		
		lcd_4bit_send_string_pos(&lcd,1,1,"How dothe trees look?");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-Theyre in pattern");
		lcd_4bit_send_string_pos(&lcd,3,1,"2-Theyre in random");
		
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val!= 0 || right_val !=0){
			questions++;
			lcd_4bit_send_command(&lcd,CLEAR_LCD);
			_delay_ms(400);}
	}
	else if(questions == 4){
		left_val =0;
		right_val =0;
		
		lcd_4bit_send_string_pos(&lcd,1,1,"Is it day or night?");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-day");
		lcd_4bit_send_string_pos(&lcd,3,1,"2-night");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val!= 0 || right_val !=0){
		questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
	}
	else if(questions == 5){
		left_val =0;
		right_val =0;
		
		lcd_4bit_send_string_pos(&lcd,1,1,"u walk deep into");
		lcd_4bit_send_string_pos(&lcd,2,1,"the forest,and u");
		lcd_4bit_send_string_pos(&lcd,3,1,"found a key");
		_delay_ms(6000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		questions++;
		
	}
	else if(questions == 6){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"What does it look");
		lcd_4bit_send_string_pos(&lcd,2,1,"like");
		lcd_4bit_send_string_pos(&lcd,3,1,"1-Old & rusty");
		lcd_4bit_send_string_pos(&lcd,4,1,"2-Modern & new");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
		questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 7){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"What will u do?");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-Leave the key");
		lcd_4bit_send_string_pos(&lcd,3,1,"2-Pick up the key");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 8){
		left_val =0;
		right_val =0;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"As you continue walking,");
		lcd_4bit_send_string_pos(&lcd,2,1,"you see a path leading to");
		lcd_4bit_send_string_pos(&lcd,3,1,"leading to");
		lcd_4bit_send_string_pos(&lcd,4,1,"a mysterious door");
		_delay_ms(3000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		questions++;
		
	}
	else if(questions == 9){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"Z(the) door is...");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-Grand & decorated");
		lcd_4bit_send_string_pos(&lcd,3,1,"2-Simple & worn out");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 10){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"u hear a scream from");
		lcd_4bit_send_string_pos(&lcd,2,1,"behind z door,do u");
		lcd_4bit_send_string_pos(&lcd,3,1,"1-Open z door");
		lcd_4bit_send_string_pos(&lcd,4,1,"2-Turn back and walk away");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 11){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"Zdoor open-to reveal");
		lcd_4bit_send_string_pos(&lcd,2,1,"abox.Whats inside?");
		lcd_4bit_send_string_pos(&lcd,3,1,"1An ancient artifact");
		lcd_4bit_send_string_pos(&lcd,4,1,"2-sparkling jewels");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 12){
		left_val =0;
		right_val =0;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"u suddenly feel");
		lcd_4bit_send_string_pos(&lcd,2,1,"a cold breeze ");
		lcd_4bit_send_string_pos(&lcd,3,1,"& hear footsteps");
		lcd_4bit_send_string_pos(&lcd,4,1,"behind u");
		_delay_ms(3000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		questions++;
		
	}
	else if(questions == 13){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"do u ..");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-Turn to see who");
		lcd_4bit_send_string_pos(&lcd,3,1,"2-Ignore &keep");
		lcd_4bit_send_string_pos(&lcd,4,1,"walking");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		_delay_ms(400);}
		
	}
	else if(questions == 14){
		left_val =0;
		right_val =0;
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		lcd_4bit_send_string_pos(&lcd,1,1,"shadowy figure");/**/
		lcd_4bit_send_string_pos(&lcd,2,1,"appears in the ");
		lcd_4bit_send_string_pos(&lcd,2,1,"distance");
		lcd_4bit_send_string_pos(&lcd,4,1,"watching you silently");
		
		_delay_ms(3000);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);
		questions++;
		
	}
	else if(questions == 15){
		left_val =0;
		right_val =0;
		lcd_4bit_send_string_pos(&lcd,1,1,"do u ..");
		lcd_4bit_send_string_pos(&lcd,2,1,"1-Approach it");/**/
		lcd_4bit_send_string_pos(&lcd,3,1,"in cautiously");
		lcd_4bit_send_string_pos(&lcd,4,1,"2-RUN");
		Button_Read_Value(&btn_right,&right_val);
		Button_Read_Value(&btn_left,&left_val);
		if(left_val != 0 || right_val != 0){
			questions++;
		
		_delay_ms(400);
		lcd_4bit_send_command(&lcd,CLEAR_LCD);}}
		
		else if(questions == 16){
			left_val =0;
			right_val =0;
			lcd_4bit_send_command(&lcd,CLEAR_LCD);
			lcd_4bit_send_string_pos(&lcd,1,3,"Loading......");
			_delay_ms(2000);
			lcd_4bit_send_string_pos(&lcd,2,5,"SHUT UP ");
			lcd_4bit_send_string_pos(&lcd,3,5,"I SAID LODAING");
			lcd_4bit_send_string_pos(&lcd,4,5,"JUST WAIT");			
			_delay_ms(3000);
			lcd_4bit_send_command(&lcd,CLEAR_LCD);
			questions++;
			
			
		}
		else if(questions == 17){
			left_val =0;
			right_val =0;
			lcd_4bit_send_string_pos(&lcd,1,1,"...Congratulation...");
			lcd_4bit_send_string_pos(&lcd,2,4,"U are autistic");
			lcd_4bit_send_string_pos(&lcd,3,1,"1-Try again");
			lcd_4bit_send_string_pos(&lcd,4,1,"2-STFU");
			Button_Read_Value(&btn_right,&right_val);
			Button_Read_Value(&btn_left,&left_val);
			if(left_val != 0){
				lcd_4bit_send_command(&lcd,CLEAR_LCD);
				lcd_4bit_send_string_pos(&lcd,2,7,"U KIDDING ME");
				lcd_4bit_send_string_pos(&lcd,3,10,"NO");
				_delay_ms(2000);
				lcd_4bit_send_command(&lcd,CLEAR_LCD);
			}
			else if(right_val != 0){
				lcd_4bit_send_command(&lcd,CLEAR_LCD);
				lcd_4bit_send_string_pos(&lcd,2,10,"NO");
				lcd_4bit_send_string_pos(&lcd,3,5,"U STFU");
				lcd_4bit_send_string_pos(&lcd,4,1,"Or Iam gonna kill u");
				_delay_ms(2000);
				lcd_4bit_send_command(&lcd,CLEAR_LCD);
			}
			
		}
		
	else{}
}

	}
	