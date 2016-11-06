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
		int setI( double I);
		int setJ( double J);
		int setN( unsigned int n);
		unsigned int getN();
		unsigned int getG();
		double getX();	
		double getY();	
		double getZ();	
		double getI();
		double getJ();
		string toString();

	private:
		unsigned int G, N;
		double X, Y, Z;
		double I,J;

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
