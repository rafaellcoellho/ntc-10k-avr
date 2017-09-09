#define F_CPU 16000000

#include <math.h>

#include "AD.h"
#include "ntc_10k.h"

long int get_resistence_ntc(double vin)
{
	//Res of NTC (Ohm) = ((VCC + R1)/Vin) - R1
	return ( (VCC * R1) / vin) - 10000;
}

double steinhart_hart(unsigned int resistence)
{
	double temperature;

	/*
	Temperature (K) = 1 / (a + (b*ln(Rntc) + c.ln(Rntc)*ln(Rntc)*ln(Rntc)))

	a = 0.0011303
	b = 0.0002339
	c = 0.00000008863
	*/
	temperature = log(resistence);
	temperature = 1 / (0.0011303 + (0.0002339 * temperature) + (0.00000008863 * temperature * temperature * temperature));
	
	//Convert in Celsius
	temperature = temperature - 273.15;

	return temperature;
}

double get_temperature(void)
{
	double vin = voltage(CHANNEL);
	long res_ntc;
	
	res_ntc = get_resistence_ntc(vin);

	return steinhart_hart(res_ntc);	
}
