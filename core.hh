#ifndef CORE_hh
#define CORE_hh

#include "cncMachine.hh"

class core
{
	public:
		unsigned int getUInp();
		void prosInp( unsigned int);
		void setGCodeFile();
		void printPath();
			

	private:
		cncMachine cM;
};

#endif
