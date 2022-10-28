#ifndef  EXTINT0_PRIV_H 
#define  EXTINT0_PRIV_H

#define EXTINT0_SENSE_LOW       0
#define EXTINT0_SENSE_RISING    1
#define EXTINT0_SENSE_FALLING   2
#define EXTINT0_SENSE_IOC       3


#define GICR  *((volatile uint8 *) 0x5B)
#define MCUCR *((volatile uint8 *) 0x55)
#define GIFR  *((volatile uint8 *) 0x5A)
#endif