#include "gCommand.hh"
#include <string>
#include <iostream>
	



gCommand::gCommand( unsigned int g)
{
	if( g > 3 ) throw gCodeValueException( g);
	this->G = g; 
}

gCommand::gCommand( unsigned int g, unsigned int n)
{
	if( g > 3 ) throw gCodeValueException( g);
	this->G = g; 
	this->N = n;
}

gCommand::~gCommand()
{
}

int gCommand::setX( double x)
{
	this->X = x;
	return 1;
}

int gCommand::setY( double x)
{
	this->Y = x;
	return 1;
}

int gCommand::setZ( double x)
{
	this->Z = x;
	return 1;
}

int gCommand::setI( double x)
{
	this->I = x;
	return 1;
}

int gCommand::setJ( double x)
{
	this->J = x;
	return 1;
}

int gCommand::setN( unsigned int x)
{
	this->N = x;
	return 1;
}

unsigned int gCommand::getN()
{
	return this->N;
}

unsigned int gCommand::getG()
{
	return this->G;
}

double gCommand::getX()
{
	return this->X;
}

double gCommand::getY()
{
	return this->Y;
}


double gCommand::getZ()
{
	return this->Z;
}

double gCommand::getI()
{
	return this->I;
}

double gCommand::getJ()
{
	return this->J;
}

string gCommand::toString()
{
	string str = "G: " + to_string(this->G);
	str += " X: " + to_string(this->X); 
	str += " Y: " + to_string(this->Y); 
	str += " Z: " + to_string(this->Z); 
	str += " N: " + to_string(this->N); 
	str += " I: " + to_string(this->I);
	str += " J: " + to_string(this->J);
	return str;
}

gCodeValueException::gCodeValueException( unsigned int i):
	exception(),
	i(i)
{
}

gCodeValueException::~gCodeValueException()
{
}

const char* gCodeValueException::what() const throw()
{
	string str = " is not a valied G-Code command (atleast for us (in the moment)).";
	str = to_string( i) + str; 
	cout << str << endl;
	return str.c_str();
}



