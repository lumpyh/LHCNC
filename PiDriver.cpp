#include "PiDriver.hh"
#include <wiringPi.h>
#include <unistd.h>


PiDriver::PiDriver():
	tP{NULL},
	currX{0},
	currY{0},
	currZ{0},
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

	usleep( 1000);
	
	if( x != 0)
		digitalWrite( xPin, 0);
	if( y != 0)
		digitalWrite( yPin, 0);
	if( z != 0)
		digitalWrite( zPin, 0);
	usleep( 1000);
}

void PiDriver::setPath( vector<toolPath*>* p)
{
	this->tP = p;
	this->currX = p->at(0)->at(0)->getX();
	this->currY = p->at(0)->at(0)->getY();
	this->currZ = p->at(0)->at(0)->getZ();
}


void PiDriver::doTheJob()
{
	int x = 0;
	int y = 0;
	int z = 0;
	toolPath* p;
	for( int i = 0; i < this->tP->size(); i++)
	{
		p = this->tP->at(i);
		for( int j = 0; j < p->size(); j++)
		{
			x = p->at(j)->getX();		
			y = p->at(j)->getY();		
			z = p->at(j)->getZ();		
			this->progress( x - currX, y - currY, z - currZ);
			currX = x;
			currY = y;
     			currZ = z;
		}	
	}
}

void PiDriver::goX( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( dir, 0, 0);
	}
}

void PiDriver::goY( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( 0, dir, 0);
	}
}

void PiDriver::goZ( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( 0, 0, dir);
	}
}




