#ifndef SPI_H_
#define SPI_H_

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "STD_Types.h"
#include "Bit_Math.h"
#include "SPI_Private.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);
void SPI_Master_TermTrans(void);

u8 SPI_TransRecieve(u8 data);



#endif