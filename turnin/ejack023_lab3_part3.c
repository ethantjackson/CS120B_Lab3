/*	Author: ejack023
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char aVal;
	unsigned char fuelLvl;
	unsigned char tmpC;
    /* Insert your solution below */
    while (1) {
	tmpC = 0x00;
	aVal = PINA;
	fuelLvl = aVal & 0x0F;
	if (fuelLvl <= 0) tmpC = 0x00;
	else if (fuelLvl <= 2) tmpC = 0x20;
	else if (fuelLvl <=4) tmpC = 0x30;
	else if (fuelLvl <=6) tmpC = 0x38;
	else if (fuelLvl <=9) tmpC = 0x3C;
	else if (fuelLvl <=12) tmpC = 0x3E;
	else tmpC = 0x3F;
	if (fuelLvl <=4) tmpC = tmpC | 0x40;
	if (aVal & 0x10 && aVal & 0x20 && !(aVal & 0x40)) tmpC = tmpC | 0x80;
	PORTC = tmpC;
    }
    return 1;
}
