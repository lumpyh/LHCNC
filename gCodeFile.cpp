#include "gCodeFile.hh"
#include <fstream>
#include <iostream>
#include <string>

gCodeFile::gCodeFile( const string& fileName):
	fileName(fileName)
{		
	commands = new vector<gCommand*>();
}

gCodeFile::~gCodeFile()
{
	gCommand* com;
	while( !commands->empty())
	{
		com = commands->back();
		commands->pop_back();
		delete com;
	}
	delete commands;
}

int gCodeFile::readFile()
{
	ifstream* is = new ifstream( this->fileName);
	char c;
	int counter = 0;
	unsigned int N;
	char lastChar = 0;
	string number = "";
	bool inParan = false;
	
	while( is->get(c))
	{ 	
		if( c == '(') inParan = true;
		else if( c == ')') inParan = false;
		if( c == 32 || c == 10 || inParan)	continue; 
		else if( c > 64 && c < 91) 
		{
			if( lastChar != 0) this->evalLast( lastChar, N, number); 
			number = "";	
			lastChar = c;
		}
		else if( c > 47 && c < 58 || c == '.')
		{
			number += c;
		} 
		
	}
	return counter;
}

int gCodeFile::evalLast( const char c, unsigned int& N, const string number)
{
	cout << c << endl;
	cout << number << endl;
	switch( c)
	{
		case 'N': 
			N = stoi( number);  
			break;
		case 'G': 
			this->commands->push_back( new gCommand( stoi( number), N));
			break;
		case 'X': 
			this->commands->back()->setX( stod(number));
			break;
		case 'Y': 
			this->commands->back()->setY( stod(number));
			break;
		case 'Z': 
			this->commands->back()->setZ( stod(number));
			break;
		default:
				cout << "Command " << c << " not known!" << endl;

		return 1;
	}
}

void gCodeFile::printCommands()
{
	for( int i = 0; i < this->commands->size(); i++)
	{
		cout << commands->at(i)->toString() << endl;
	}
}


