#include "PiDriver.hh"
#include <iostream>

using namespace std;

int main()
{
	PiDriver driver;
	unsigned int cnt = 0;
	short dir = 1;
	while(true)
	{
		driver.progress( dir, 0, 0);
		if( cnt > 100) dir = -1;
		else if( cnt < 1) dir = 1;
		cnt += dir;
		cout << cnt << endl;
	}
	return 0;
}
