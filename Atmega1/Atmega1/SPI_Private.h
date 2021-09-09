#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
#include "STD_Types.h"


#define				SPCR			*((volatile u8 *)0x2D)
#define				SPSR			*((volatile u8 *)0x2E)
#define				SPDR			*((volatile u8 *)0x2F)

#endif