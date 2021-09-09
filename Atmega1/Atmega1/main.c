/*
 * Atmega1.c
 *
 * Created: 09-Sep-21 5:56:35 PM
 * Author : Mahmoud
 */ 

#include <avr/io.h>
#include "UART.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include <util/delay.h>

#define F_CPU 16000000
int main(void)
{
	u8 bluetooth_data = 0;
	UART_Init();
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	while (1)
	{
		bluetooth_data = UART_Rx();
		if (bluetooth_data)
		{
			if (bluetooth_data == 'a')
			{
				SPI_TransRecieve('a');
				bluetooth_data = 0;
			}
			if (bluetooth_data == 'b')
			{
				SPI_TransRecieve('b');
				bluetooth_data = 0;
			}
		}
	}
}


