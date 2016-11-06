
#include "FakeDriver.hh"
#include <unistd.h>


FakeDriver::FakeDriver():
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
}
	
void FakeDriver::progress( short x, short y, short z)
{
	usleep( 1000);
}

void FakeDriver::setPath( vector<toolPath*>* p)
{
	this->tP = p;
	this->currX = p->at(0)->at(0)->getX();
	this->currY = p->at(0)->at(0)->getY();
	this->currZ = p->at(0)->at(0)->getZ();
}


void FakeDriver::doTheJob()
{
	int x = 0;
	int y = 0;
	int z = 0;
	toolPath* p;
	for( unsigned int i = 0; i < this->tP->size(); i++)
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

void FakeDriver::goX( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( dir, 0, 0);
	}
}

void FakeDriver::goY( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( 0, dir, 0);
	}
}

void FakeDriver::goZ( int i)
{
	int dir = 1;
	if( i < 0) dir = -1;
	for( int j = 0; j != i; j += dir)
	{
		this->progress( 0, 0, dir);
	}
}



