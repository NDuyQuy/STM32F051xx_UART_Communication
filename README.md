# STM32F051xx_UART_Communication
# Description
	Using STM32F051 comunication with computer by UART and control LED Blue on board . 
	The command structure use is *(command)# with '*' is the start condition and '#' is the end condition; (command) is the 
	command line which i use 'led on' and 'led off' to control the led.
	
	The software I use to send message from computer to stm32f051xx microchip is hercules_3-2-8 by HWGroup. The link 
	for software dowload https://www.hw-group.com/software/hercules-setup-utility .
# pin connection

## STM32F051 DISCOVERY KIT                              CH34OT MODULE USB 
	PIN 3,3V 												PIN 3,3V
	PIN GND 												PIN GND 
	PORT A PIN 9(UART TX)									PIN RXD
	PORT A PIN 10(UART RX)									PIN TXD	
## LED CONFIG 
	PORT A PIN 8(OUTPUT) //Because on the board already a blue led connect with the pc8 so i dont need to connect external led.