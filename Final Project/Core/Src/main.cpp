
#include "string.h"
#include "FreeRTOS.h"
#include "task.h"
#include "list.h"
#include "queue.h"
#include "timers.h"
#include "control.h" // control motor to go forward,backward, right pr left
#include "uart.h" // enable uart to communicate with Laptop/smart-phone using  HC-05
#include "oled.h"
#include "semphr.h"

//Queue Handler
xQueueHandle xQueue;
SemaphoreHandle_t  semaphore;
//Tasks Handlers (just in case!!)
 TaskHandle_t xHandle_Green;
 TaskHandle_t xHandle_RED;
 TaskHandle_t xHandle_BLUE;
 TaskHandle_t xHandle_BUZZ;
 TaskHandle_t xHandle_Forward;
 TaskHandle_t xHandle_Backward;
 TaskHandle_t xHandle_Right;
 TaskHandle_t xHandle_Left;
 TaskHandle_t xHandle_Break;
///<declerations Begin>
 UART* bl_test = new(UART1INS) UART(UART1INS);
	/// <Activate Motor>
	Moto_Config m1_c = {{GPIOA, 5,MODE::Gen}, {GPIOB, 1,MODE::Gen}, {GPIOA, 6,MODE::Gen}}; // activating motor 1 driver as Pin A5 is ins1, B1 is ins2, A6 is Enable (50MHZ output)
	Moto_Config m2_c = {{GPIOA, 4,MODE::Gen}, {GPIOA, 0,MODE::Gen}, {GPIOB, 0,MODE::Gen}};// activating motor 2 driver as Pin A4 is ins1, A0 is ins2, B0 is Enable (50MHZ output)
	Motor M1(&m1_c); /// OBJ Motor has the name M1 and the address of m1_c
	Motor M2(&m2_c); /// OBJ Motor has the name M2 and the address of m2_c
	/// <ACTIVATE Control>
	Control motion(&M1,&M2); // controlling both motors with motion go forward, backward,right or left
	//LED and Buzzer
	OP LED_B(GPIOA,1,MODE::Gen); // PIN A1 is a 50MHZ Output (Blue LED)
	OP LED_G(GPIOA,2,MODE::Gen); // PIN A2 is a 50MHZ Output (Green LED)
	OP LED_R(GPIOA,3,MODE::Gen); // PIN A3 is a 50MHZ Output (Red LED)
	OP BUZZ(GPIOB,9,MODE::Gen);// PIN B9 is a 50MHZ output (Buzzer)
///<declerations ENDS>
///<UART Task Begins>
void uartTimerCallback(void *pv)
{
	bl_test->INIT(1);
    // Queue sender
	while(1)
	{
    char control = bl_test->Read();
    xQueueSendToBack(xQueue, &control, portMAX_DELAY);
   // bl_test->Send(control);
	vTaskDelay(100/portTICK_RATE_MS);
	}
}
void uart_READ(void *pv)
{

	char reading=0;
while(1)
{
	xQueueReceive(xQueue, &reading, portMAX_DELAY);
	if(reading =='w')
	{
		LED_G.ON();
		LED_B.OFF();
		LED_R.OFF();
		BUZZ.OFF();
		motion.Forward();
	//	vTaskDelay(200/portTICK_RATE_MS);
	}
	else if(reading =='s')
	{
		//BUZZ.ON();
		LED_R.ON();
		LED_B.OFF();
		LED_G.OFF();
		motion.Backward();
		//vTaskDelay(200/portTICK_RATE_MS);

	}
	else if (reading=='d')
	{
		LED_B.ON();
		LED_R.OFF();
		LED_G.OFF();
		BUZZ.OFF();
		motion.Right();

		//	vTaskDelay(200/portTICK_RATE_MS);

	}
	else if(reading =='a')
	{
		LED_B.ON();
		LED_G.OFF();
		LED_R.OFF();
		BUZZ.OFF();
		motion.Left();

		//	vTaskDelay(200/portTICK_RATE_MS);

	}
	else if(reading =='p')
	{
		LED_R.ON();
		LED_B.ON();
		LED_G.ON();
		BUZZ.OFF();
		motion.BREAK();
//vTaskDelay(200/portTICK_RATE_MS);
	}
	else
	{
		LED_B.ON();
		LED_R.ON();
		LED_G.OFF();
		BUZZ.OFF();
		motion.BREAK();

	}
}
}
///< UART Tasks ENDS	>

int main()
{
///<configurations BEGINS>
config port;
port.ENPA();//enable RCC for port A
port.ENPB();//enable RCC for port B
///<Configurations ENDS>
///<Activating OLED BEGINS>
/*
I2C i2c(I2C1, GPIOB); // Create an I2C object
Oled oled(i2c); // Create an Oled object
 * oled.init(); // Initialize the OLED screen
oled.sendString("Hello World", 0,3, 1, 1, 0);
   oled.setDisplayOptions(1, 1, 0); // Set display options (fontSize, fontColor, orientation)
   oled.display("Hello, World!"); // Send a string to the OLED screen at (0, 0) coordinates
*/
///<Activating OLED ENDS>
///<Activating RTOS BEGINS>
xQueue =xQueueCreate(10, sizeof(char));
semaphore = xSemaphoreCreateMutex();
if(xQueue != NULL)
{
	xTaskCreate(uartTimerCallback,"uart_com",400,NULL,3,NULL); //Receiving Data from (HC-05//TTL) and send it to Queue
	xTaskCreate(uart_READ,"uart_rec",400,NULL,3,NULL); // Fetching Data From Queue and Execute
	vTaskStartScheduler();
}
///<Activating RTOS ENDS>
while(1)
{
	//not needed infinte loop
}
return 0;
}


