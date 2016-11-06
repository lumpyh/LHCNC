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
	while( uinp < 5)
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
		cout << "3 -go Direction" << endl;
		cout << "4 -go Path" << endl;
		cout << "5 -exit"	<< endl;
		cout << "Input: ";
		cin >> a;
	}while( a == 0 || a > 5);
	
	
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
		case 3: 
			this->goDir();
			break;
		case 4:
			this->driv.setPath( this->cM.getPathes());
			this->driv.doTheJob();
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
	for( unsigned int i = 0; i < path->size(); i++)
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

void core::goDir()
{
	int dir = 0;
	int steps = 0;
	cout << "Which direction? (1,2,3): ";
	cin >> dir; 
	cout << endl;
	cout << "How many steps?: ";
	cin >> steps;
	cout << endl; 
	switch( dir)
	{
		case 1:
			this->driv.goX( steps);
			break;
		case 2:
			this->driv.goY( steps);
			break;
		case 3:
			this->driv.goZ( steps);
			break;
	}
}
