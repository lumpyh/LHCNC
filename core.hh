#ifndef CORE_hh
#define CORE_hh

#include "cncMachine.hh"
#include "PiDriver.hh"

class core
{
	public:
		unsigned int getUInp();
		void prosInp( unsigned int);
		void setGCodeFile();
		void printPath();
			

	private:
		void goDir();
		cncMachine cM;
		PiDriver driv;
};

#endif
