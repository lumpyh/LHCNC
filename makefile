cc = g++
cflags =-c -Wall -std=c++11
lflags = -lpthread -lwiringPi

depend = core.o cncMachine.o cncState.o gCodeFile.o gCodeProcessor.o gCommand.o toolPath.o point.o PiDriver.o


all: LHCNC 

LHCNC: $(depend)
	$(cc) $(lflags) $(depend) -o LHCNC

core.o: core.cpp
	$(cc) $(cflags) core.cpp

cncMachine.o: cncMachine.cpp
	$(cc) $(cflags) cncMachine.cpp

cncState.o: cncState.cpp
	$(cc) $(cflags) cncState.cpp

gCodeFile.o: gCodeFile.cpp
	$(cc) $(cflags) gCodeFile.cpp

gCodeProcessor.o: gCodeProcessor.cpp
	$(cc) $(cflags) gCodeProcessor.cpp

gCommand.o: gCommand.cpp
	$(cc) $(cflags) gCommand.cpp

toolPath.o: toolPath.cpp
	$(cc) $(cflags) toolPath.cpp

point.o: point.cpp
	$(cc) $(cflags) point.cpp

PiDriver.o: PiDriver.cpp
	$(cc) $(cflags) PiDriver.cpp

clean:
	rm *.o
	rm LHCNC
