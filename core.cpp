#include "core.hh"
#include "gCodeFile.hh"
#include "gCommand.hh"
#include "cncState.hh"
#include "gCodeProcessor.hh"
#include "toolPath.hh"
#include "cncMachine.hh"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main( void)
{

	core a;
	unsigned int uinp = 0;
	while( uinp < 3)
	{
		uinp = a.getUInp();
		a.prosInp( uinp);	
	}
		
	return 0;
}


unsigned int core::getUInp()
{
	unsigned int a = 0;
	do
	{
		cout << "What to do?" << endl;
		cout << "1 -Input g-Code-File" << endl;
		cout << "2 -Print path" << endl;
		cout << "Input: ";
		cin >> a;
	}while( a == 0 || a > 2);
	
	
	return a;
}

void core::prosInp( unsigned int a)
{
	switch( a)
	{
		case 1: 
			this->setGCodeFile();
			break;
		case 2:
			this->printPath();
			break;
	}
	return;
}		

void core::setGCodeFile()
{
	string inp;
	cout << "File: ";
	cin >> inp;
	this->cM.setFile( inp);
	this->cM.createPath();
	return;
}

void core::printPath()
{
	vector<toolPath*>* path = this->cM.getPathes();
	for( int i = 0; i < path->size(); i++)
	{
		for( int j = 0; j < path->at(i)->size(); j++)
		{
			cout << path->at(i)->at(j)->getX();
			cout << "\t";
			cout << path->at(i)->at(j)->getY();
			cout << "\t";
			cout << path->at(i)->at(j)->getZ();
			cout << endl;
		}
	}
}
