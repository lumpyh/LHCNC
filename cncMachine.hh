#ifndef CNCMACHINE_HH
#define CNCMACHINE_HH

#include "cncState.hh"
#include "gCodeFile.hh"
#include <string>

class cncMachine
{
	public:
		cncMachine();
		void setFile( string);

	private: 
		cncState state;
		gCodeFile* gCode;
}


#endif
