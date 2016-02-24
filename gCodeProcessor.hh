#ifndef GCODEPROCESSOR_HH
#define GCODEPROCESSOR_HH

#include "cncState.hh"
#include "gCommand.hh"
#include "toolPath.hh"
#include <vector>

using namespace std;

class gCodeProcessor
{
	public:
		gCodeProcessor( cncState&);
		~gCodeProcessor();
		void processCommand( gCommand*);
		void createLinearPath( gCommand*);
		int size();
		toolPath* at( int i);
		vector<toolPath*>* getPathes();
		
	private:
		vector<toolPath*>* pathes;
		cncState& mState;
	
	
};

#endif
