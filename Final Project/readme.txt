 *Project Name: 
	DC Motor Electric Car.
*Header Files:
	1- config.h : (tick)
		Enable Clock for Ports and AFIOs 
	2-utils.h: (tick)
		Set constexpr for Bits,Pins and Regesters per each other 
	3- op.h: (tick)
		Activate GPIO's/AFIO's as O/P's
	4- ip.h: (tick) //getstats must be within while (1) first.
		Activate GPIO's/AFIO's as I/P's 
	5- motor.h : (tick)
		Control each Motor Indivdually
	6- control.h: (tick)
		Control the Motion of the Car Kit 
**	7- uart.h: --
		Setting uart Communication with MCU from Mobile or Laptop.
**	8- oled: --
		A trial to add data to the OLED using I2C.
----9- l8nbuzz.h: (tick) (Useless)
		A trial to control the LEDS and Buzzer connected to the MCU.
	10- nutshell.h: (tick)
		Connect all headers in one headerto be included in main.c/main.cpp
**	11- rtos: -- (uartos.h)
		Using FreeRTOS to time schedule every I/P & O/P and make them appear as they work simultaneously. 
*Source Files:
	1- main.c:
		Should include all Headers mentioned and by using FreeRTOS use every move and I/P O/P signal as one task 
	then determine each task's pirority (all the same except emergency Stop Button will be higher in pirority).
	
*Tasks:
	1- Make Headers files.
	2- Test Every File indvidually.
	3- Make main.c.
	4- Test. 