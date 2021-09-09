/*
 * Atmega2.c
 *
 * Created: 09-Sep-21 6:01:37 PM
 * Author : Mahmoud
 */ 

#include <avr/io.h>
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "Bit_Math.h"

int main(void)
{
	SPI_Slave_Init();
	char master_data;
	DIO_voidSetPinDirection(PORTC,2,OUTPUT);
	DIO_voidSetPinDirection(PORTC,3,OUTPUT);
	while (1)
	{
		master_data = SPI_TransRecieve(0);
		switch(master_data){
			case 'a':
			TOG_BIT(PORTC_REG,2); break;
			case 'b':
			TOG_BIT(PORTC_REG,3); break;
			default: break;
			
		}
		
	}
}


