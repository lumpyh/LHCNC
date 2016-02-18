#include "gCodeFile.hh"
#include "gCommand.hh"

int main( void)
{
	gCodeFile g("test.gcode");
	g.readFile();

	g.printCommands();
}
