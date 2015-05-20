/*
 * DoubleCounter.c
 *
 * Created: 2015-04-09 00:05:57
 *  Author: Aleksander Kasprzak
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "DoubleCounter.h"


uint16_t k_factorX1000=1; //do przeliczenia i przemyslenia ile bitow potrzeba - moze byc problem z przypisywaniem osobnych bajtow
uint8_t counter1=0; //upewnic sie czy wystarczy 8 bitow, znika problem z podzialem przypisania na osobne bajty
uint8_t counter2=0; //upewnic sie czy wystarczy 8 bitow, znika problem z podzialem przypisania na osobne bajty
uint8_t OVF_counter=0;
//uint8_t fail_counter=0; //zliczanie podejrzanych wartosci, po przekroczeniu progu wylaczenie systemu

void init_counters()
{
	SENSOR1_DDR&=(~(SENSOR1)); //niekonieczne
	SENSOR2_DDR&=(~(SENSOR2));
	SENSOR1_PORT|=SENSOR1; //stan wysoki
	SENSOR2_PORT|=SENSOR2;

	EICRA|=((1<<ISC00)|(1<<ISC10));	//przerwanie od zmiany stanu logicznego Nie matwimy sie bledem wynikajacym z pzycji poczatkowej! - przewaga nad zboczami
	EIMSK|=((1<<INT0)||(1<<INT1)); // mal zmiana dla Atmegi 328P
	
	TCCR0B|=((1<<CS02)||(1<<CS00)); //preskaler 1024
	TIMSK0|=(1<<TOIE0); //przerwanie od przepelnienia
}
/*
ISR(TIMER0_OVF_vect) //atrybutem wlaczyc przerwania
{
	if(OVF_counter==OVF_FOR_COUNT) //koniec pomiaru, atrybutem wylaczyc przerwania
	{
		/* W pierwszej wersji unikamy mniejszej kontroli w szczegolnosci przy malych predkosciach, mozna sprawdzic w praktyce jaka roznica jest*/
		/*int8_t tmp=counter2-counter1;
		if(tmp==0||tmp==1||tmp==-1) {k_factorX1000=1; /*fail_counter=0;*///} //mie musi tego byc koniecznie, ale dla bezpieczenstawa lepiej by bylo
		//else if(counter2==0) {k_factorX1000=MAX_k_VALX1000;	/*fail_counter++;*/}
		//else if(counter1==0) {k_factorX1000=MIN_k_VALX1000;	/*fail_counter++;*/}
		//else {k_factorX1000=(counter1*MNOZNIK)/counter2; /*fail_counter=0;*/}
		/*
		if(counter2==0)
		{
			if(counter1==1||counter1==0) k_factorX1000=1;
			else {k_factorX1000=MAX_k_VALX1000;	/*fail_counter++;}	
		}
		else if(counter1==0) 
		{
			if(counter2==1) k_factorX1000=1;
			else {k_factorX1000=MIN_k_VALX1000;	/*fail_counter++;}
		}
		else {k_factorX1000=(counter1*MNOZNIK)/counter2; /*fail_counter=0;}
		*/
	//}
//	else OVF_counter++; //mozna napidac w assemblerze
//}

ISR(INT0_vect) // wllaczyc atrybutem przerwania
{
	counter1++; //pozniej poprawie do ASSEMBLERA
}

ISR(INT1_vect) //wlaczyc atrybotem przerwania
{
	counter2++; //pozniej poprawie do ASSEMBLERA
}

ISR(BADISR_vect) {;}
