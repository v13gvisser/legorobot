#include "drivers/hitechnic-angle.h"
#include "motors.h"
nxtDisplayTextLine(2, "RPM: %7d", HTANGreadRPM(HTANG)) //rotations/minute, lijkt me onnodig om /sec van te maken
task main(){
	
}
void RotationsPerSecond(){
TFileHandle myFileHandle;          // create a file handle variable 'myFileHandle'
TFileIOResult IOResult;            // create an IO result variable 'IOResult'
string myFileName = "myFile.txt";  // create and initialize a string variable 'myFileName'
 
OpenWrite(myFileHandle, IOResult, myFileName, myFileSize);  // open for write: "myFile.txt"

 motor[motorA] = 50;
 motor[motorB] = 50;
 nxtDisplayTextLine(2, "RPM: %7d", HTANGreadRPM(HTANG))
 long writeMe = HTANGreadRPM(HTANG);                       // create a long variable 'writeMe' and set it to 424246
WriteLong(myFileHandle, IOResult, writeMe);  // writes HTANGreadRPM(HTANG);  to the file handled by 'myFileHandle'
wait1Msec(5000);

 
 motor[motorA] = 60;
 motor[motorB] = 60;
 nxtDisplayTextLine(3, "RPM: %7d", HTANGreadRPM(HTANG))
 WriteLong(myFileHandle, IOResult, writeMe);
 wait1Msec(5000);
 
 motor[motorA] = 70;
 motor[motorB] = 70;
 WriteLong(myFileHandle, IOResult, writeMe);
 nxtDisplayTextLine(4, "RPM: %7d", HTANGreadRPM(HTANG))
 wait1Msec(5000);
 Close(myFileHandle, IOResult); 

}
