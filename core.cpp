#include "gCodeFile.hh"
#include "gCommand.hh"
#include "cncState.hh"
#include "gCodeProcessor.hh"
#include "toolPath.hh"
#include "cncMachine.hh"
#include <iostream>
#include <vector>

using namespace std;

int main( void)
{

	
	cncMachine* cM = new cncMachine();
	cM->setFile( "test.gcode");
	cM->createPath();
	
	vector<toolPath*>* pathes = cM->getPathes();
	toolPath* path = 0;

	for( int j = 0; j < pathes->size(); j++)
	{
	path = pathes->at(j);
	for( int i = 0; i < path->size(); i++)
	{
		cout << path->at(i)->getX();
		cout << "\t";
		cout << path->at(i)->getY();
		cout << "\t";
		cout << path->at(i)->getZ();
		cout << endl;
	}	
	}
	
	
	
		
	return 0;
}

