#ifndef CORE_hh
#define CORE_hh

#include "cncMachine.hh"
#ifdef RPI
	#include "PiDriver.hh"
#else
	#include "FakeDriver.hh"
#endif

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
#ifdef RPI
		PiDriver driv;
#else
		FakeDriver driv;
#endif
};

#endif
