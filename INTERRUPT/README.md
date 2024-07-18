#INTERRUPT
##What is interrupt
when some interrupt happens like puhing button the Cpu stops excuting the code and start doing isr (interrupt service routine)



#ISR
- The code that being excuted when interrupt happens



#What happens when interrupt happens
- The Cpu finishes the current instruction after that the data stored in stack and Cpu stop excuting the main code
and the status of the CPU is stored in (PSW/PSR) registers and the PC (programm counter) refer to the vector ,then the isr being excuted
when the interrupt finishes all the data restored from stack and psw

#There are two types of interrupt :
1- ASYNCHRONOUS : caused by Hardware interrupt 
2- SYNCHRONOUS : caused by software interrupt


We can say there is 1 - Maskable interrupts : interrupts we can control (ENABLE-DISABLE) EXP:- TIMERS-ADC
2- Non-maskable interrupts : we can't enable or disable it EXP:- Reset


- Some MCU has priority like (PIC18 and above) but older versions doesn't have priority

- Some MCU has many levels of priority nad some has HIGH & LOW only

- when high level intterupt happens it get over low level interrupts

- we have INTx and RBx interrupt 
- INtx : when the pin get 5V the interrupt happens 
- RBx : when the pin has voltage change (either 5v or 0) the interrupt happens

#Steps we follow when coding interrupt
1- Disable interrupt
2- initialize pin
3- intialize priority
4- Assign Isr that will happen
5- Interrupt Enable

- when doing these steps we use bits we can find them in the data sheet
![alt text](image-2.png)

- We shuld see the data sheet to make the interrupt right for every MCU