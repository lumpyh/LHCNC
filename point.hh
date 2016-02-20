#ifndef POINT_HH
#define POINT_HH

template<class A>  class point{
	public:	
		point();
		point( A, A, A);
		void setX( A);
		void setY( A);
		void setZ( A);
		A getX();
		A getY();
		A getZ();
	
	private:
		A X;
		A Y;
		A Z;
};

#endif
