#pragma config(Sensor, S1,     HTIRS2,              sensorI2CCustom)
#include "hitechnic-irseeker-v2.h"

void soundIfDirectionIs5();


task main(){
	
}
void soundIfTowardsBeacon(){
	if ( HTIRS2readACDir(HTIRS2) = 5 )
    PlaySound(soundDownwardTones);
}
