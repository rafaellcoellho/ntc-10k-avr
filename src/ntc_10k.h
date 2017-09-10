/*
* ----------------------------------------------------------------------------
* "THE BEER-WARE LICENSE" (Revision 42):
* <rafaellcoellho@gmail.com> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think
* this stuff is worth it, you can buy me a beer in return 
* ----------------------------------------------------------------------------
*/

/*
	@file					ntc_10k.h
	@autor					Rafael Coelho <rafaellcoellho@gmail.com>
	@brief					Header with functions for ntc 10k.
	@details                
			Sensor:
				Type: NTC 10k +/- 1% 3950
				Measuring range:-20 a 105
				B-const: 3380K - / + 1%

			Circuit: 

			VCC
			 |
			 |
			| |
			| |	ntc 10k
			| |
			 |
			 |____AD
			 |
			 |
			| |
			| | R1
			| |
			 |
			 |
			GND
*/

#ifndef NTC_10K_H_
#define NTC_10k_H_

#define VCC							5
#define R1							(unsigned int)10000

#include <stdint.h>

#define CHANNEL 					0


void init_adc(void);
double get_temperature(void);

#endif /* MEASUREMENTS_H_ */
