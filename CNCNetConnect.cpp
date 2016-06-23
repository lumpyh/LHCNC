#include "CNCNetConnect.hh"

CNCNetConnect::CNCNetConnect( ObjectSendingSocket* s):
	NetConnect<ObjectSendingSocket>(s),
	pos(0,1,2,3)
{
}

void CNCNetConnect::processCommand( string command)
{
	if( command == "getCurPos")
	{
			sock->sendObject( &(this->pos));
	}
	cout << command << endl;
}
