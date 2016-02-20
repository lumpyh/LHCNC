#include "gCodeFile.hh"
#include "gCommand.hh"
#include "point.hh"
#include <iostream>

using namespace std;

int main( void)
{
	gCodeFile g("test.gcode");
	g.readFile();

	point<int> a( 0, 1, 4);
	cout << a.getY() << endl;
	
}

