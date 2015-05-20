/*
 * Motors.c
 *
 * Created: 2015-04-22 23:39:17
 *  Author: JA
 */ 

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include "Motors.h"

#define PRZOD 1
#define TYL 0

volatile uint8_t pwm1=0, pwm2=0;

void inicjuj_silniki()
{
	// dla bezpieczenstwa
	CLR_A1;
	CLR_A2;
	CLR_B1;
	CLR_B2;
	
	//zegary
	
	TCCR0A|=(1<<WGM01);
	OCR0A=10;
	TIMSK0|=(1<<OCIE0A);
	TCCR0B|=((1<<CS01)); //preskaler 1
	//TIMSK0|=(1<<TOIE0); //przerwanie od przepelnienia
	
	DDR_SILNIKI|=((1<<A1)|(1<<A2)|(1<<B1)|(1<<B2)); // silnii
}

void ustaw_pwm_1(uint8_t zadana)
{
	if(zadana>=127)
	{
		pwm1=zadana-127;
		CLR_B1;
	}
	else 
	{
		pwm1=zadana;
		SET_B1;
	}
}
void ustaw_pwm_2(uint8_t zadana)
{
		if(zadana>=127)
		{
			pwm2=zadana-127;
			CLR_B2;
		}
		else
		{
			pwm2=zadana;
			SET_B2;
		}
}

ISR(TIMER0_COMPA_vect)
{
	static uint8_t licznik=0;
	
		if(pwm1>licznik) SET_A1;
		else CLR_A1;
		if(pwm2>licznik) SET_A2;
		else CLR_A2;

		++licznik;
		if(licznik>127) licznik=0;

}		
