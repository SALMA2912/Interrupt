#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT0_int.h"
#include "EXTINT0_cfg.h"
#include "EXTINT0_priv.h"

pf x = EXTINT0_voidInit;  //law mashwersh 3ala 7aga hayb2a by default ynafz elinitialization function

void EXTINT0_voidInit(void)
{
	
	
	#if EXTINT0_SENSE_MODE == EXTINT0_SENSE_RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);
	#elif EXTINT0_SENSE_MODE == EXTINT0_SENSE_IOC
	SET_BIT(MCUCR , 0);
	CLR_BIT(MCUCR , 1);
	#elif EXTINT0_SENSE_MODE == EXTINT0_SENSE_LOW
	CLR_BIT(MCUCR , 0);
	CLR_BIT(MCUCR , 1);
	#else
	CLR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);	
	#endif
	/* clear event flag */
	SET_BIT(GIFR , 6);
	/*Disable interrupt*/
	CLR_BIT(GICR , 6) ;

}

void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR , 6) ;
}

void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR , 6) ;
}

void EXTINT0_voidSetCallBack(pf y)
{
	x = y ;
}

void __vector_1 (void) __attribute__((signal ,used));
void __vector_1 (void)
{
	x();
}






