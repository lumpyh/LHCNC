#ifndef GCOMMAND_HH
#define GCOMMAND_HH
#include <exception>
#include <string>

using namespace std;

class gCommand
{
	public:
		gCommand( unsigned int);
		gCommand( unsigned int, unsigned int);
		~gCommand();
		int setX( double x);
		int setY( double y);
		int setZ( double z);
		int setN( unsigned int n);
		unsigned int getN();
		double getX();	
		double getY();	
		double getZ();	
		string toString();

	private:
		unsigned int G, N;
		double X, Y, Z;

};

class gCodeValueException: public exception
{
	public:
		gCodeValueException( unsigned int);
		~gCodeValueException();
		virtual const char* what() const throw();
	private:
		int i;
};

#endif
