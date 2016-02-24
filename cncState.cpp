#include "cncState.hh"

cncState::cncState():
	absolute( true),
	inMill( true),
	stepsPerMill( 50),
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
	return this->inMill;
}

const point<int>& cncState::getStepPos()
{
	return this->stepPos;
}

const point<double>& cncState::getPos()
{
	return this->pos;
}

void cncState::setAbsolute( bool b)
{
	this->absolute = b;
}

void cncState::setInMill( bool b)
{
	this->inMill = b;
}

void cncState::setStepPos( int x, int y, int z)
{
	this->stepPos.setX( x);
	this->stepPos.setY( y);
	this->stepPos.setZ( z);
}

void cncState::setPos( double x, double y, double z)
{
	this->pos.setX( x);
	this->pos.setY( y);
	this->pos.setZ( z);
}

int cncState::getStepsPerMill()
{
	return this->stepsPerMill;
}




