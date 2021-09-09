#ifndef UART_H_
#define UART_H_

#include "Bit_Math.h"
#include "STD_Types.h"
#include "UART_Private.h"

void UART_Init(void);

void UART_Tx(u8 data);

void UART_TxString(u8* str);

u8 UART_Rx(void);



#endif