#include "cncMachine.hh"

cncMachine::cncMachine():
	state(),
	gCode( NULL)
{
}

void cncMachine::setgCodeFile( string filename)
{
	gCode = new gCodeFile( filename);
	gCode->readFile();
}


