#ifndef PIDRIVER_HH
#define PIDRIVER_HH


class PiDriver
{
	public:
		PiDriver();
		void progress( short, short, short);
		
	private:
		unsigned short xPin;
		unsigned short xDir;
		unsigned short yPin;
		unsigned short yDir;
		unsigned short zPin;
		unsigned short zDir;
		bool xPos;
		bool yPos;
		bool zPos;

};



#endif
