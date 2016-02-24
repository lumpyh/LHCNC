#include "gCodeProcessor.hh"
#include <cmath>
#include <iostream>

using namespace std;

gCodeProcessor::gCodeProcessor( cncState& mS):
	mState( mS)
{
	pathes = new vector<toolPath*>();	
}


gCodeProcessor::~gCodeProcessor()
{
	while( !this->pathes->empty())
	{
		delete this->pathes->back();
		this->pathes->pop_back();
	}
	delete this->pathes;
}

void gCodeProcessor::processCommand( gCommand* command)
{
	int G = command->getG();

	switch( G)
	{
		case 0:
			this->createLinearPath( command);
			break;
		case 1:
			this->createLinearPath( command);
			break;
		default:
			cout << "Command G" << G << " not known!" << endl;
			break;
	}
}


void gCodeProcessor::createLinearPath( gCommand* command)
{
	toolPath* cPath = new toolPath();
	int xs, ys, zs;
	int xz, yz, zz;
	int vx, vy, vz;
	char c = '0';
	int f = 1;
	int xi, yi, zi;
	if( pathes->empty())
	{
		xs = 0;
		ys = 0;
		zs = 0;
	}
	else{
		xs = pathes->back()->back()->getX();
		ys = pathes->back()->back()->getY();
		zs = pathes->back()->back()->getZ();
	}

	xz = int( command->getX() * this->mState.getStepsPerMill());
	yz = int( command->getY() * this->mState.getStepsPerMill());
	zz = int( command->getZ() * this->mState.getStepsPerMill());

	vx = xz-xs;
	vy = yz-ys;
	vz = zz-zs;
	
	int iz;

	if( abs(vx) > abs(vy) && abs(vx) > abs(vz))
	{
		c = 'x';
		iz = vx;
	}
	else if( abs(vy) > abs(vz))
	{
		c = 'y';
		iz = vy;
	}
	else	
	{ 
		c = 'z';
		iz = vz;
	}
	
	if( iz < 0 ) f = -1;


//	cout << "iz = " << iz << endl;
	
	

	for( int i = 0;  i <= f * iz; i++)
	{
		if( iz == 0) break;
		switch(c)
		{
			case 'x':
				xi = f * i + xs;
				yi = int(float(vy)/float(vx) * f * i + ys);
				zi = int(float(vz)/float(vx) * f * i + zs);
				break;
			case 'y':
				yi = f * i + ys;
				xi = int(float(vx)/float(vy) * f * i + xs);
				zi = int(float(vz)/float(vy) * f * i + zs);
				break;
			case 'z':
				zi = f * i + zs;
				yi = int(float(vy)/float(vz) * f * i + ys);
				xi = int(float(vx)/float(vz) * f * i + xs);
				break;
		}	
//		cout << xi << "\t" << yi << "\t" << zi << endl;
		cPath->push_back( new point<int>( xi, yi, zi));
	} 	
	if( !cPath->empty()) pathes->push_back( cPath);
}

int gCodeProcessor::size()
{
	return this->pathes->size();
}

toolPath* gCodeProcessor::at( int i)
{
	return this->pathes->at(i);
}

vector<toolPath*>* gCodeProcessor::getPathes()
{
	return this->pathes;
}
