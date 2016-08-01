#include "PiDriver.hh"
#include <wiringPi.h>
#include <unistd.h>


PiDriver::PiDriver():
	xPin{0},	
	xDir{1},
	yPin{2},	
	yDir{3},
	zPin{4},	
	zDir{5},
	xPos{true},
	yPos{true},
	zPos{true}
{
	wiringPiSetup();	
	pinMode( xPin, OUTPUT);
	pinMode( yPin, OUTPUT);
	pinMode( zPin, OUTPUT);
	pinMode( xDir, OUTPUT);
	pinMode( yDir, OUTPUT);
	pinMode( zDir, OUTPUT);
	digitalWrite( xPin, 0);
	digitalWrite( yPin, 0);
	digitalWrite( zPin, 0);
	digitalWrite( xDir, 1);
	digitalWrite( yDir, 1);
	digitalWrite( zDir, 1);
}
	
void PiDriver::progress( short x, short y, short z)
{
	if( ( x > 0 && !xPos) || ( x < 0 && xPos))
	{
		xPos = !xPos;
		digitalWrite( xDir, xPos ? 1 : 0);  
	}
	if( ( y > 0 && !yPos) || ( y < 0 && yPos))
	{
		yPos = !yPos;
		digitalWrite( yDir, yPos ? 1 : 0);  
	}
	if( ( z > 0 && !zPos) || ( z < 0 && zPos))
	{
		zPos = !zPos;
		digitalWrite( zDir, zPos ? 1 : 0);  
	}
	if( x != 0)
		digitalWrite( xPin, 1);
	if( y != 0)
		digitalWrite( yPin, 1);
	if( z != 0)
		digitalWrite( zPin, 1);

	usleep( 51000);
	
	if( x != 0)
		digitalWrite( xPin, 0);
	if( y != 0)
		digitalWrite( yPin, 0);
	if( z != 0)
		digitalWrite( zPin, 0);
	usleep( 51000);
}
