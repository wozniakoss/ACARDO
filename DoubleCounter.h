/*
 * DoubleCounter.h
 *
 * Created: 2015-04-09 00:09:06
 *  Author: JA
 */ 

/* Dajmy gesto tarcze, musi byc aktualnie*/
#ifndef DOUBLECOUNTER_H_
#define DOUBLECOUNTER_H_

#include <inttypes.h>

//#define F_CPU 1000000 //wykasowac po ogolnym zdefoniowaniu

#define SENSOR1 (1<<PD2)
#define SENSOR2 (1<<PD3)

#define SENSOR1_DDR DDRD
#define SENSOR2_DDR DDRD
#define SENSOR1_PIN PIND
#define SENSOR2_PIN PIND
#define SENSOR1_PORT PORTD
#define SENSOR2_PORT PORTD

#define MNOZNIK 1000
#define TIME_FOR_COUNT 1
#define OVF_FOR_COUNT 4
#define MAX_k_VALX1000 500
#define MIN_k_VALX1000 2

extern uint16_t k_factorX1000;

#endif /* DOUBLECOUNTER_H_ */