#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector<int>* v = new vector<int>();
	for( int i = 0; i < 10000 ; i++)
	{
		v->push_back( i);
		cout << sizeof( *v) << endl;
	}

	return 0;
}
