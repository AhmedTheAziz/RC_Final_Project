 *Project Name: 
	RC Car.
*Header Files:
	1- config.h : 
		Enable Clock for Ports and AFIOs 
	2-utils.h: 
		Set constexpr for Bits,Pins and Regesters per each other 
	3- op.h: 
		Activate GPIO's/AFIO's as O/P's
--	4- ip.h: (tick) //getstats must be within while (1) first.
		Activate GPIO's/AFIO's as I/P's 
	5- motor.h : 
		Control each Motor Indivdually
	6- control.h: 
		Control the Motion of the Car Kit 
	7- uart.h: 
		Setting uart Communication with MCU from Mobile or Laptop.
	8- timer3.h:
		Activating TIM3 as PWM mode 1.
--	9- oled: 
		A trial to add data to the OLED using I2C.
	10- nutshell.h: 
		Connect all headers in one headerto be included in main.c/main.cpp
	11- rtos:  (uartos.h)
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
	
N.B:
-- not Finished/Applied Header.