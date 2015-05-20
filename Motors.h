/*
 * Motors.h
 *
 * Created: 2015-05-15 18:54:05
 *  Author: JA
 */ 


#ifndef MOTORS_H_
#define MOTORS_H_

#define DDR_SILNIKI DDRD
#define PORT_SILNIKI PORTD

#define A1 PD7
#define B1 PD6
#define A2 PD5
#define B2 PD4 

#define SET_A1 PORT_SILNIKI|=(1<<A1)
#define SET_A2 PORT_SILNIKI|=(1<<A2)
#define SET_B1 PORT_SILNIKI|=(1<<B1)
#define SET_B2 PORT_SILNIKI|=(1<<B2)

#define CLR_A1 PORT_SILNIKI&=~(1<<A1)
#define CLR_A2 PORT_SILNIKI&=~(1<<A2)
#define CLR_B1 PORT_SILNIKI&=~(1<<B1)
#define CLR_B2 PORT_SILNIKI&=~(1<<B2)

void inicjuj_silniki();
void ustaw_pwm_1(uint8_t);
void ustaw_pwm_2(uint8_t);

extern volatile uint8_t pwm1;
extern volatile uint8_t pwm2;


#endif /* MOTORS_H_ */