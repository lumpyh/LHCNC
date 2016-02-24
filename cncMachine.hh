#ifndef CNCMACHINE_HH
#define CNCMACHINE_HH

#include "cncState.hh"
#include "gCodeFile.hh"
#include "gCodeProcessor.hh"

#include <string>

class cncMachine
{
	public:
		cncMachine();
		void setFile( string);
		void createPath();
		vector<toolPath*>* getPathes();

	private: 
		cncState state;
		gCodeFile* gCode;
		gCodeProcessor* gcp;
};


#endif
