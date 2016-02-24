#ifndef GCODEFILE_HH
#define GCODEFILE_HH 

#include <string>
#include <vector>
#include "gCommand.hh"

using namespace std;

class gCodeFile
{
	public:
		gCodeFile( const string& fileName);
		~gCodeFile();
		int readFile();
		void printCommands();
		vector<gCommand*>* getCommands();	
		
	private:
		string fileName;
		vector<gCommand*>* commands;
		bool absolute;
		int addNewCommand( unsigned int, unsigned int);
		int evalLast( const char, unsigned int&, const string);
};

#endif
