#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*		Ip / op	*/
void DIO_voidSetPinDirection(u8 PORTID , u8 PINID , u8 Direction)
{
	if (Direction == OUTPUT)
	{
		switch(PORTID)
		{
			case PORTA : SET_BIT(DDRA_REG,PINID);	break;
			case PORTB : SET_BIT(DDRB_REG,PINID);	break;
			case PORTC : SET_BIT(DDRC_REG,PINID);	break;
			case PORTD : SET_BIT(DDRD_REG,PINID);	break;
		}
	}
	else if(Direction == INPUT)
	{
				switch(PORTID)
				{
					case PORTA : CLR_BIT(DDRA_REG,PINID);	break;
					case PORTB : CLR_BIT(DDRB_REG,PINID);	break;
					case PORTC : CLR_BIT(DDRC_REG,PINID);	break;
					case PORTD : CLR_BIT(DDRD_REG,PINID);	break;
				}
	}
}
/*		OUT = High or Low		*/
void DIO_voidSetPinValue(u8 PORTID , u8 PINID , u8 Value)
{
	if (Value == HIGH)
	{
			switch(PORTID)
			{
				case PORTA : SET_BIT(PORTA_REG,PINID);	break;
				case PORTB : SET_BIT(PORTB_REG,PINID);	break;
				case PORTC : SET_BIT(PORTC_REG,PINID);	break;
				case PORTD : SET_BIT(PORTD_REG,PINID);	break;
			}
	}else if (Value == LOW)
	{
			switch(PORTID)
			{
				case PORTA : CLR_BIT(PORTA_REG,PINID);	break;
				case PORTB : CLR_BIT(PORTB_REG,PINID);	break;
				case PORTC : CLR_BIT(PORTC_REG,PINID);	break;
				case PORTD : CLR_BIT(PORTD_REG,PINID);	break;
			}
	}
}
/*		Input = High or Low		*/
u8 DIO_u8GetPinValue(u8 PORTID , u8 PINID)
{
	u8 Local_u8Data = 0xFF;
	switch(PORTID)
	{
		case PORTA : Local_u8Data = GET_BIT(PINA_REG,PINID);	break;
		case PORTB : Local_u8Data = GET_BIT(PINB_REG,PINID);	break;
		case PORTC : Local_u8Data = GET_BIT(PINC_REG,PINID);	break;
		case PORTD : Local_u8Data = GET_BIT(PIND_REG,PINID);	break;
	}
	return Local_u8Data;
}
void DIO_voidSetPortDirection(u8 PORTID, u8 Direction){
	switch(PORTID)
	{
		case PORTA : DDRA_REG = Direction;	break;
		case PORTB : DDRB_REG = Direction;	break;
		case PORTC : DDRC_REG = Direction;	break;
		case PORTD : DDRD_REG = Direction;	break;
	}
}

void DIO_voidSetPortValue(u8 PORTID, u8 Value){
	switch(PORTID)
	{
		case PORTA : PORTA_REG = Value;	break;
		case PORTB : PORTB_REG = Value;	break;
		case PORTC : PORTC_REG = Value;	break;
		case PORTD : PORTD_REG = Value;	break;
	}
}