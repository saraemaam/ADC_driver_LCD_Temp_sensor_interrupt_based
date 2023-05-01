/******************************************************************************
 * Module     : Temperature Sensor
 * File Name  : lm35_sensor.h
 * Description: header file for the LM35 Temperature Sensor driver
 * Author     : Sarah
 *
 *****************************************************************************/

#include"lm35_sensor.h"
#include"lcd.h"
#include"adc.h"
#include<avr/io.h>

int main(void)
{
	uint8 temp;

	SREG|=(1<<7); /* Enable Global Interrupts */

	LCD_init(); /* initialize LCD driver */

	ADC_init(); /* initialize ADC driver */

	LCD_displayString("Temp is =  C");

	while(1)
	{

		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(0,10);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}

}
