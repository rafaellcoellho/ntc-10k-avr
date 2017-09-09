/*
	@file						AD.h
	@autor					Rafael Coelho <rafaellcoellho@gmail.com>
	@brief					Header with functions for AD interaction.
	@details                

	Resolution: 10bits
 			   Voltage = VOLTAGE_REFERENCE / [(2^Nbits)-1]
 			   Voltage = 5 / [(2^10)-1]
 			   Voltage = 5 / 1023
 			   Voltage = 4,887mV
 	Time of conversion: 13 - 260uS 
 	Number of channels: 8
 	Vin: 0 - Vcc
*/



#ifndef AD_H_
	#define AD_H_
	
	void init_adc(void);
	unsigned int adc_read(unsigned char channel);	
	double voltage(unsigned char channel);

#endif /* AD_H_ */