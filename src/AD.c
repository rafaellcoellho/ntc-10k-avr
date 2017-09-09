#define F_CPU 16000000

#include <avr/io.h>
#include "AD.h"


void init_adc(void)
{
	ADMUX |= (1<<REFS0);
	

	//Prescaler of 128. 16Mhz/128 = 125kHz
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

unsigned int adc_read(unsigned char channel)
{
	ADMUX = ADMUX & 0xF0;
	ADMUX |= (channel & 0x0F);
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC) );
	
	return ADC;
}

double voltage(unsigned char channel)
{
	//R = 5 / (2^10 - 1) = 0.0048875855327468 
	return adc_read(channel) * 0.004887;
}

