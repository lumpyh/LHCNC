#include "cncState.hh"

cncState::cncState():
	absolute( true),
	inMill( true),
	stepsPerMill( 1000),
	stepPos( 0, 0, 0),
	pos( 0, 0, 0)
{
}

bool cncState::isAbsolute()
{
	return this->absolute;
}

bool cncState::isInMill()
{
	return this->inMill();
}

const point<int>& cncState::getStepPos()
{
	return this->stepPos;
}

const point<double>& cncState::getPos()
{
	return this->pos;
}

void cncStatesetAbsolute( bool b)
{
	this->absolute = b;
}

void cncState::setInMill( bool b)
{
	this->inMill = b;
}

void cncState::setStepPos( int x, int y, int z)
{
	this->setStepPos.setX( x);
	this->setStepPos.setY( y);
	this->setStepPos.setZ( z);
}

void cncState::setPos( double x, double y, double z)
{
	this->setPos.setX( x);
	this->setPos.setY( y);
	this->setPos.setZ( z);
}






