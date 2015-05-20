/*
 * Serwo.h
 *
 * Created: 2015-05-16 00:04:32
 *  Author: JA
 */ 


#ifndef SERWO_H_
#define SERWO_H_

#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#define DDR_SERWO DDRB
#define PORT_SERWO PORTB

#define SET_WIRE PORTB|=(1<<PB1);
#define CLR_WIRE PORTB&=~(1<<PB1);

void inicjuj_serwo();
void ustaw_serwo(uint8_t zadana);
#endif /* SERWO_H_ */
