/*
 * Serwo.c
 *
 * Created: 2015-05-16 00:05:20
 *  Author: JA
 */ 
#include "Serwo.h"
#include <avr/io.h>
//46079
void inicjuj_serwo()
{
	DDRB|=(1<<PB1);
TCCR1A|=((1<<WGM11));
TCCR1B|=((1<<WGM13)|(1<<WGM12));
TCCR1A|=(1<<COM1A1);
TCCR1B|=(1<<CS11);
ICR1=46079;
OCR1A=3500; // pozycja �rodkowa serwa ~1,5ms
}

void ustaw_serwo(uint8_t zadana)
{
	uint32_t temp;

	temp=zadana*600UL;  // domy�lna promocja do int
						// UL - unsigned long
						// Musimy wymusi� taki typ danych aby kompilaor
						// zaniecha� promocji do int
	// http://atnel.pl/domyslna-promocja-do-typu-int.html  <- �r�d�o
	temp=temp/51;
	temp=temp+2000;
	OCR1A=(uint16_t)temp;	// ca�e wyra�nie obliczamy wg. wzoru:  temp=2000+((zadana*3000)/255);
	// 600 i 51 wzi�o si� ze skr�cenia 3000 i 255
	 // tutaj te� na wszelki wypadek jawne rzutowanie to uint16_t
}
