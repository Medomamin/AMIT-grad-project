#include "UART.h"
#include "DIO_interface.h"

void UART_Init(void){
	
	u8 UBRR_Val = 0;
	// Tx pin set to output
	DIO_voidSetPinDirection(PORTD,1,OUTPUT);
	// Rx pin set to input
	DIO_voidSetPinDirection(PORTD,0,INPUT);
	// Set Baud Rate
	UBRR_Val=((160000)/(16*96))-1;
	UBRRL = UBRR_Val;
	//enable Tx
	SET_BIT(UCSRB,4);
	//enable Rx
	SET_BIT(UCSRB,3);
	//
	UCSRC |= 0x86;
	
}

void UART_Tx(u8 data){
	UDR = data;
	while (GET_BIT(UCSRA,5)==0)
	{
	}
}


void UART_TxString(u8* str){
	u8 i = 0;
	
	while (str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}


u8 UART_Rx(void){
	u8 data = 0;
	while (GET_BIT(UCSRA,7)==0)
	{
	}
	data = UDR;
	return data;
}

