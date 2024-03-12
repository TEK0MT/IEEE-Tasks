.PHONY: all clear
cc := arm-none-eabi-
cf := -mcpu=cortex-m3 -std=gnu11 -mthumb
obj:= lcd.o main.o startup.o Stm32_F103C6_GPIO.o
all : Mohamed_Tarek.elf
%.o:%.c
	$(cc)gcc -c $(cf) $< -o $@
Mohamed_Tarek.elf:$(obj)
	$(cc)ld -T linkerscript.ld $(obj) -o $@
Progamm:
	openocd -f board/st_nucleo_f4.cfg
clear:
	rm -f *.o *.elf