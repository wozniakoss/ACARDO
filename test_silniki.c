/*
 * test_silniki.c
 *
 * Created: 2015-05-13 14:54:44
 *  Author: JA
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Motors.h"
#include "Serwo.h"

#define FOSC 18432000UL
#define BAUD 115200UL

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}

int main(void)
{
inicjuj_silniki();
inicjuj_serwo();
/*Set baud rate */
UBRR0H = (unsigned char)((FOSC/16/BAUD-1)>>8);
UBRR0L = (unsigned char)(FOSC/16/BAUD-1);
//Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (3<<UCSZ00)/*|(1<<USBS0)*/;
sei();
uint8_t tmp1, tmp2, tmp3;
ustaw_pwm_1(127);//dajemy neutralne pozycje na pwm'y
ustaw_pwm_2(127);//tak zeby nam acardo nie odjechal przed po³¹czeniem

ustaw_serwo(255); //sekwencja startowa
_delay_ms(250);   // tylko po to zeby wiedzieæ ze
ustaw_serwo(0);   // wszystko jest ok
_delay_ms(250);
ustaw_serwo(127);
_delay_ms(250);
//debugowanie xD
//ustaw_pwm_1(127);
//_delay_ms(500);
//ustaw_pwm_1(0);
//_delay_ms(500);
//ustaw_pwm_1(255);
//_delay_ms(500);
//ustaw_pwm_1(200);
//_delay_ms(500);
//ustaw_pwm_1(127);
//_delay_ms(500);

while(1)
{
tmp1=USART_Receive();
tmp2=USART_Receive();
tmp3=USART_Receive();
tmp2=255-tmp2;
ustaw_pwm_1(tmp3);
ustaw_pwm_2(tmp3);
ustaw_serwo(tmp2);

}
}

/*ISR(TIMER0_COMPA_vect)
{
		static uint8_t licznik=0;
		
		if(pwm1>licznik) SET_A1;
		else CLR_A1;
		if(pwm2>licznik) SET_A2;
		else CLR_A2;
		++licznik;
		if(licznik>127) licznik=0;
}*/
