#pragma config(Sensor, S1,     HTGYRO,              sensorAnalogInactive)
#include "hitechnic-gyro.h"
void offsetPlusCurrentValue(int X, int Y);
void soundIfTrue (int certainValue);

task main(){
	
}
//if gyro measures a certain value, brick makes sound
void soundIfTrue (int certainValue){
	if ( HTGYROreadRot(HTGYRO) >= certainValue )
    PlaySound(soundDownwardTones);
}

void offsetPlusCurrentValue(int maximumAllowedDeviation);{
	x = HTGYROreadRot(HTGYRO);
	for (;;){
		y = HTGYROreadRot(HTGYRO);
		if (y < x - maximumAllowedDeviation || y > x + maximumAllowedDeviation ){
			PlaySound(soundException);
			wait1ms(2000);
		}
	}
		
}
