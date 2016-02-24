#ifndef TOOLPATH_HH
#define TOOLPATH_HH

#include "point.hh"
#include <vector>

using namespace std;

class toolPath
{
	public:
		toolPath();
		~toolPath();
		void setPoint( int, int, int);
		point<int>* back();
		void push_back( point<int>*);
		int size();
		point<int>* at( int i);
		bool empty();
		

	private:
		int speed = 1;
		vector<point<int>*>* path;
	
};


#endif
