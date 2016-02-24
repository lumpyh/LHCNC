#include "toolPath.hh"

toolPath::toolPath()
{
	this->path = new vector<point<int>*>();
}

toolPath::~toolPath()
{
	while( !this->path->empty())
	{
		delete this->path->back();
		this->path->pop_back();
	}
	delete this->path;
}

void toolPath::setPoint( int x, int y, int z)
{
	this->path->push_back( new point<int>( x, y, z));	
}

point<int>* toolPath::back()
{
	return this->path->back();
}

void toolPath::push_back( point<int>* p)
{
	this->path->push_back( p);
}

int toolPath::size()
{
	return path->size();
}

point<int>* toolPath::at( int i)
{
	return path->at( i);
}

bool toolPath::empty()
{
	return this->path->empty();
}
