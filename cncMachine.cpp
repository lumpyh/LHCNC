#include "cncMachine.hh"

#include <vector>
#include <iostream>
#include "gCommand.hh"


using namespace std;

cncMachine::cncMachine():
	state(),
	gCode( NULL),
	gcp( new gCodeProcessor( state))
{
}

void cncMachine::setFile( string filename)
{
	gCode = new gCodeFile( filename);
	gCode->readFile();
}

void cncMachine::createPath()
{
	vector<gCommand*>*  coms= this->gCode->getCommands();
	
	for( unsigned int i = 0; i < coms->size(); i++)
	{
		//cout << coms->at(i)->toString() << endl;
		gcp->processCommand( coms->at(i));
	}
}

vector<toolPath*>* cncMachine::getPathes()
{
	return gcp->getPathes();
}
	


