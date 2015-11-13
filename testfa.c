#pragma config(Sensor, S1,     HTANG,               sensorI2CCustom)
#include "constanteSnelheid.h"
#include "rotSpeedTest.h"
#include "drivers/hitechnic-angle.h"
#include "motors.h"
#include "Versnelling_bepalen.h"
#include "constanteSnelheid.c"

task main()
{
char * sFileName = "testFile.dat";

TFileIOResult nIoResult;
TFileHandle hFileHandle;
while(true){
moveWithConstantSpeed(30, 60, 1);
Delete(sFileName, nIoResult);
int nParmToReadLong = 0;

short   nParmToWrite 			= currentRPM;
int nFileSize 					= 100;

OpenWrite(  hFileHandle, nIoResult, sFileName, nFileSize);
WriteShort(  hFileHandle, nIoResult, nParmToWrite);
Close(hFileHandle, nIoResult);

OpenRead(hFileHandle, nIoResult, "testFile.dat", nFileSize);
ReadShort(hFileHandle, nIoResult,  nParmToReadLong);
Close(hFileHandle, nIoResult);
//nxtDisplayTextLine(5,"val: %d", currentRPM);
nxtDisplayTextLine(6,"val: %d", nParmToReadLong);
wait1Msec(100);
}
}
