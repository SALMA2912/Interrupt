/*
 * main.c
 *
 *  Created on: 2 Sep 2022
 *      Author: HP
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>

#include "DIO_int.h"


void ISRAppCode(void)
{
	DIO_enuWritePin(8 , 1);
	_delay_ms(1000);
	DIO_enuWritePin(8 , 0);
}

void main (void)
{
	DIO_voidInit();
	EXTINT0_voidInit();
	EXTINT0_voidSetCallBack(ISRAppCode);
	DIO_enuActivatePullUp(26 , 1);
	EXTINT0_voidEnable();
	GIE_voidEnable();
	while (1)
	{
		DIO_enuWritePin(0,1);
		_delay_ms(1000);
		DIO_enuWritePin(0,0);
		_delay_ms(1000);


	}
}


