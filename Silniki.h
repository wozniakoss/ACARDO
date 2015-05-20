a/*
 * Silniki.h
 *
 * Created: 2015-05-05 12:26:10
 *  Author: JA
 */ 


//#ifndef SILNIKI_H_
//#define SILNIKI_H_
/*

#define PSILNIK_1 PD7 //Silnik prawy, sterownik 1
#define PSILNIK_2 PD6 //Silnik prawy, sterownik 2
#define LSILNIK_1 PD5 //Silnik lewy, sterownik 1
#define LSILNIK_2 PD4 //Silnik lewy, sterownik 2

#define PORT_SILNIK PORTD
#define PIN_SILNIK PIND
#define DDR_SILNIK DDRD

/* Ustawianie/kasowanie pojedynczych pinow *//*
#define SET_PSILNIK_1 PORT_SILNIK|=(1<<PSILNIK_1)
#define SET_PSILNIK_2 PORT_SILNIK|=(1<<PSILNIK_2)
#define SET_LSILNIK_1 PORT_SILNIK|=(1<<LSILNIK_1)
#define SET_LSILNIK_2 PORT_SILNIK|=(1<<LSILNIK_2)
#define CLR_PSILNIK_1 PORT_SILNIK&=(!(1<<PSILNIK_1))
#define CLR_PSILNIK_2 PORT_SILNIK&=(!(1<<PSILNIK_2))
#define CLR_LSILNIK_1 PORT_SILNIK&=(!(1<<LSILNIK_1))
#define CLR_LSILNIK_2 PORT_SILNIK&=(!(1<<LSILNIK_2))


/*ustawiane tak, aby jechal do przodu (F), do tulu (B) :
Prawy silnik przod: SET_PSILNIK_2;
					CLR_PSILNIK_1
Prawy silnik tyl	SET_PSILNIK_1;
					CLR_PSILNIK_2
Lewy silnik przod:	SET_LSILNIK_2;
					CLR_LSILNIK_1
lewy silnik tyl		SET_LSILNIK_1;
					CLR_LSILNIK_2
*/

/*Hamowanie*/
/*
#define BREAK_PSILNIK PORT_SILNIK|=((1<<PSILNIK_1)|(1<<PSILNIK_2)) //masa
#define BREAK_LSILNIK PORT_SILNIK|=((1<<LSILNIK_1)|(1<<LSILNIK_2)) //masa
#define BRK__PSILNIK PORT_SILNIK&=(!((1<<PSILNIK_1)|(1<<PSILNIK_2))) //napiecie
#define BRK__LSILNIK PORT_SILNIK&=(!((1<<LSILNIK_1)|(1<<LSILNIK_2))) //napiecie

#define MAX_TIMER 255
#define MAX_WYPELNIENIE 255
#define ZEROWE_WYPELNIENIE 127 // Czy nie bedzie to za mala rodzielczosc

void inicjuj_silniki();
*/
//#endif /* SILNIKI_H_ */