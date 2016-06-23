#ifndef CNCNETCONNECT_HH
#define CNCNETCONNECT_HH

#include "TCPSocket/ObjectSendingSocket.hh"
#include "TCPSocket/NetConnect.hh"
#include "TCPSocket/MashinePosition.hh"
#include <string>

using namespace std;

class CNCNetConnect: public NetConnect<ObjectSendingSocket>
{
	public:
		CNCNetConnect( ObjectSendingSocket*);


	private:
		void processCommand( string);
		MashinePosition pos;
	
	

};

#endif
