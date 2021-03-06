// 
// 
// 

#include "NO2.h"

#include "Arduino.h"
#include <math.h>


double Sensitivity = -40.0;
#define VOLTAGE_IN 3.3
double  TIA = 499.0;

double V0 = 3.3;

NO2::NO2(int input) {
	_input = input;
	pinMode(input, INPUT);
}

double NO2::getVoltage()
{
	reading = analogRead(_input);
	//Serial.print(reading);

	
	voltage = reading*(3.3 / 1023.0);


	return voltage;
}

double NO2::getNO2Reading()
{
	sensorCalibration = Sensitivity * TIA;
	
	double reading = (1.0 / sensorCalibration) * (getVoltage() - V0)*pow(10, 6);
	//Serial.printf("Reading: %0.5f\n", reading);
	//Serial.printf("%8.3f \n", sensorCalibration);
	return reading;
}


