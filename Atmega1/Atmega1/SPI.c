#include "SPI.h"

void SPI_Master_Init(void){
	// MISO
	DIO_voidSetPinDirection(PORTB,6,INPUT);
	// MOSI
	DIO_voidSetPinDirection(PORTB,5,OUTPUT);
	// CLK
	DIO_voidSetPinDirection(PORTB,7,OUTPUT);
	// SS
	DIO_voidSetPinDirection(PORTB,4,OUTPUT);
	
	SPCR |= 0x53;
	
	DIO_voidSetPinValue(PORTB,4,HIGH);
}
void SPI_Slave_Init(void){
	// MISO
	DIO_voidSetPinDirection(PORTB,6,OUTPUT);
	// MOSI
	DIO_voidSetPinDirection(PORTB,5,INPUT);
	// CLK
	DIO_voidSetPinDirection(PORTB,7,INPUT);
	// SS
	DIO_voidSetPinDirection(PORTB,4,INPUT);
	
	SPCR |= 0x40;
}

void SPI_Master_InitTrans(void){
	DIO_voidSetPinValue(PORTB,4,LOW);
}

void SPI_Master_TermTrans(void){
	DIO_voidSetPinValue(PORTB,4,HIGH);
}


u8 SPI_TransRecieve(u8 data){
	u8 rec_data = 0;
	SPDR = data;
	while (GET_BIT(SPSR,7)==0)
	{
	}
	rec_data = SPDR;
	return rec_data;
}
