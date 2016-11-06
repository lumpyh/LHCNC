
#ifndef FAKEDRIVER_HH
#define FAKEDRIVER_HH

#include "toolPath.hh"
#include <vector>

using namespace std;


class FakeDriver
{
	public:
		FakeDriver();
		void progress( short, short, short);
		void setPath( vector<toolPath*>*);
		void doTheJob();
		void goX( int );
		void goY( int );
		void goZ( int );
		
		
	private:
		vector<toolPath*>* tP;
		int currX;
		int currY;
		int currZ;
		unsigned short xPin;
		unsigned short xDir;
		unsigned short yPin;
		unsigned short yDir;
		unsigned short zPin;
		unsigned short zDir;
		bool xPos;
		bool yPos;
		bool zPos;

};



#endif
