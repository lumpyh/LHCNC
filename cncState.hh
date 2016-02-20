#ifndef CNCSTATE_HH
#define CNCSTATE_HH
#include "point.hh"


class cncState{

	public:
		cncState();
		bool isAbsolute();
		bool isInMill();	
		int getStepsPerMill();
		const point<int>& getStepPos();
		const point<double>& getPos();
		void setAbsolute( bool);
		void setInMill( bool);
		void setStepPos( int, int, int);
		void setPos( double, double, double);

	private:
		bool absolute;
		bool inMill;
		int stepsPerMill;
		point<int> stepPos;
		point<double> pos;
};
