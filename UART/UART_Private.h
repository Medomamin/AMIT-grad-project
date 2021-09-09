#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "STD_Types.h"

#define UBRRH (*((volatile u8*)0x40))
#define UBRRL (*((volatile u8*)0x29))
#define UCSRA (*((volatile u8*)0x2B))
#define UCSRB (*((volatile u8*)0x2A))
#define UCSRC (*((volatile u8*)0x40))
#define UDR (*((volatile u8*)0x2C))



#endif